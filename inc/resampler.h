/*
 * resampler.h
 *
 *  Created on: Dec 23, 2013
 *      Author: bsg
 */

#ifndef RESAMPLER_H_
#define RESAMPLER_H_

#include <stdlib.h>
#include <math.h>
#include <vector>
#include <deque>
#include <complex>
#include "quantized_cache.h"

//convert data from real to complex by zeroing the imaginary part
void toCx(std::deque<float>& oldData, std::deque<std::complex<float> >& newData);

//copy up to n elments from old data to new data
template<typename T>
void copy_n_elements(std::deque<T>& oldData, std::deque<T>& newData, size_t n)
{
	size_t cpyNum = std::min(n,oldData.size());
	newData.resize(cpyNum);
	typename std::deque<T>::iterator o =oldData.begin();
	for (typename std::deque<T>::iterator i =newData.begin(); i!=newData.end(); i++)
	{
		*i=*o;
		o++;
	}
}

//This is a class to compute the Lanczos Kernel for computing resampling fitler coefficients
template<typename OutType, typename InType>
class LanczosKernel
{
public:
	//Create the kernal - there are typically 2a input points used to compute one resampled output
	//So the bigger a, the more history, delay, computation, etc.
	LanczosKernel(size_t a);
	OutType getValue(InType& x);
	size_t _a;
};

template<typename OutType, typename InType>
LanczosKernel<OutType, InType>::LanczosKernel(size_t a) :
 _a(a)
 {}

template<typename OutType, typename InType>
OutType LanczosKernel<OutType, InType>::getValue(InType& x)
 {
	if (x==0)
		return 1.0;
	float piX = M_PI*x;
	float denominator=std::pow(piX,2);
	float numerator = _a*sin(piX)*sin(piX/_a);
	return numerator/denominator;
}

//This is an arbitrary rate resampler for non-integer value decimation/interpolation
//all computations are done int the time domain with a time varient filter whose coefficients are calculated
//by the LanczosKernel.  This is slowe then a frequency domain approach but can be useful for
//cases where exact rate resampling is required
class ArbitraryRateResamplerClass
{
public:
	//do not pass in a startTime and the filter will default appropriately
	//don't pass in realHistory or complexHistory if there is none
	//the rest of the parameters are required
	ArbitraryRateResamplerClass(float inputRate,
			                    float outputRate,
			                    size_t a,
			                    size_t quantizationPts,
			                    std::vector<float>& real_out,
			                    std::vector<std::complex<float> >& complex_out,
			                    float* startTime=NULL,
			                    std::deque<float>* realHistory=NULL,
			                    std::deque<std::complex<float> >* cmplxHistory=NULL);
	//pass in new real input data.  return the delay associated with the first output sample
	float newData(std::vector<float>& real_in);
	//pass in new real output data.  return the delay associated with the first output sample
	float newData(std::vector<std::complex<float> >& complex_in);
	//get the nextOutput Time -- includes delay offset for the next output sample
	float getNextOutputDelay();
	float getInRate();
	std::deque<float>* getRealHistory();
	std::deque<std::complex<float> >* getComplexHistory();

private:
	template<typename T>
	void next(T& val,  std::vector<T>& output, std::deque<T>& oldData);

	LanczosKernel<float,float> kernel;
	QuantizedCash<float, float> cache;
	boost::function<float(float)> func;

	float inRate;
	float outRate;
	double outputTime;
	float rateFactor;
	float filterDelay;
	std::vector<float>& realOut;
    std::vector<std::complex<float> >& cmplxOut;

    std::deque<float> realOldData;
    std::deque<std::complex<float> > cmplxOldData;
};


#endif /* RESAMPLER_H_ */
