/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This file is part of REDHAWK Basic Components dsp library.
 *
 * REDHAWK Basic Components dsp library is free software: you can redistribute it and/or modify it under the terms of
 * the GNU Lesser General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * REDHAWK Basic Components dsp library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this
 * program.  If not, see http://www.gnu.org/licenses/.
 */

#ifndef FIRFILTERDESIGNER_H_
#define FIRFILTERDESIGNER_H_

#include "DataTypes.h"
#include "FIRFilter.h"

template<typename T, typename U>
void muxImaginaryZeros(T& fromVec, U& toVec);

class KaiserWindowDesigner
{
	/*
	 * Design a Kaiser Window to use for your FIR filters
	 * Here is the typical conop for this class
	 * 1.  Construct/reset values
	 * 2.  Validate window size is OK - if not call overrideSize to change it
	 * 3.  Call getWindow to construct your filter
	 *
	 * twNorm = twHz/fsHz
	 */
public:
	KaiserWindowDesigner();
	KaiserWindowDesigner(double ripple, double twHz, double fsHz);
	KaiserWindowDesigner(double ripple, double twNorm);

	size_t reset(double ripple, double twHz, double fsHz);
	size_t reset(double ripple, double twNorm);

	size_t getWindowSize();
	void overrideSize(size_t val);

	void getWindow(RealArray &w);

private:
	Real getBeta();
	Real in0 (Real x);
	void calculateWindow (RealArray &w, Real beta);
	size_t size;
	size_t attenDB;
};

class FirFilterDesigner {
public:
	/*
	 * The API for the filter designer is similar for all methods - so I will document it ONCE here.
	 *
	 * Use the RealArray or ComplexArray depending on if you want to design real or complex filter taps
	 *
	 * All of the Norm frequencies are scaled so that the sampling frequency (fs) is 1
	 * and the Nyquist rate (fs/2) is 1/2. In otherwords: fNorm = fHz/samplingFrequencyHz.
	 * Here are the valid frequency inputs:
	 *   	for filter type: lowpass, highpass, real bandpass, real bandstop:
	 *      	fNorm [0:.5]
	 *         	fHz [0:fs/2]
	 *		for filter type complex bandpass, complex bandstop:
	 *			fNorm [-.5:.5]
	 *         	fHz [-fs/2:fs/2]
	 * fl and fh represent the lower and higher transition frequencies to design the filter.
	 * fh is IGNORED for lowpass/highpass filters and required only for bandpass and bandstop filter types
	 *
	 * ripple (in amplitude) represents the maximium amplitude deviation in passband and stopband
	 * tw (transition width) represents the frequency duration to transition from pass to stop band
	 * These two parameters are used to determine the number of taps to meet the design constraints.
	 * However, minTaps and maxTaps can provide bounds on the filter length to override these values if necessary.
	 *
	 * Here is the expected frequency domain filter results for each of the various cases.
	 * Note that the bandpass and bandstop filters have DIFFERENT behavior for the real/complex filter types,
	 * but the lowpass and highpass filters give the same results for the real and complex APIs.
	 *
	 *    	               Lowpass (Real/Cx)
	 *                    |-----------------|
	 *                    |                 |
	 *  -----------------------------------------------------
	 *  -1/2             -flNorm  0        flNorm           1/2
	 *  -fs/2            -flHz    0        flHz             fs/2
	 *
	 *
	 *    	               Highpass (Real/Cx)
	 *  ------------------|                 |----------------
	 *                    |                 |
	 *  -----------------------------------------------------
	 *  -1/2             -flNorm  0        flNorm           1/2
	 *  -fs/2            -flHz    0        flHz             fs/2
	 *
	 *
	 *  	               Bandpass (Real)
	 *           |--------|                 |-------|
	 *           |        |                 |       |
	 *  -----------------------------------------------------
	 *  -1/2    -fhNorm  -flNorm  0        flNorm   fhNorm  1/2
	 *  -fs/2   -fhHz/2   -flHz   0        flHz     fhHz    fs/2
	 *
	 *  	               Bandpass (Cx)
	 *                                      |-------|
	 *                                      |       |
	 *  -----------------------------------------------------
	 *  -1/2                      0        flNorm   fhNorm  1/2
	 *  -fs/2                     0        flHz     fhHz    fs/2
	 *
	 *
	 *    	               Bandstop (Real)
	 *  ---------|        |-----------------|       |--------
	 *           |        |                 |       |
	 *  -----------------------------------------------------
	 *  -1/2    -fhNorm  -flNorm  0        flNorm   fhNorm  1/2
	 *  -fs/2   -fhHz/2   -flHz   0        flHz     fhHz    fs/2
	 *
	 *
	 *    	               Bandstop (Cx)
	 *  ------------------------------------|       |--------
	 *                                      |       |
	 *  -----------------------------------------------------
	 *  -1/2                      0        flNorm   fhNorm  1/2
	 *  -fs/2                     0        flHz     fhHz    fs/2
	 */
	template<typename T>
	size_t wdfir (T& filtCoeff,
				FIRFilter::filter_type type,
		    Real  ripple,
		    Real twNorm,
		    Real  flNorm,
		    Real  fhNorm=0,
		    size_t minTaps=0,
		    size_t maxTaps=0);
	template<typename T>
	size_t wdfirHz (T& filtCoeff,
				FIRFilter::filter_type type,
		    Real  ripple,
		    Real twHz,
		    Real  flHz,
		    Real  fhHz=0,
		    Real fsHz=1.0,
		    size_t minTaps=0,
		    size_t maxTaps=0);
//	size_t wdfir (RealArray& filtCoeff,
//			FIRFilter::filter_type type,
//	    Real  ripple,
//	    Real twNorm,
//	    Real  flNorm,
//	    Real  fhNorm=0,
//	    size_t minTaps=0,
//	    size_t maxTaps=0);
//	size_t wdfirHz (RealArray& filtCoeff,
//			FIRFilter::filter_type type,
//	    Real  ripple,
//	    Real twHz,
//	    Real  flHz,
//	    Real  fhHz=0,
//	    Real fsHz=1.0,
//	    size_t minTaps=0,
//	    size_t maxTaps=0);
//	size_t wdfir (ComplexArray& filtCoeff,
//			FIRFilter::filter_type type,
//	    Real  ripple,
//	    Real twNorm,
//	    Real  flNorm,
//	    Real  fhNorm=0,
//	    size_t minTaps=0,
//	   	size_t maxTaps=0);
//	size_t wdfirHz (ComplexArray& filtCoeff,
//			FIRFilter::filter_type type,
//	    Real  ripple,
//	    Real twHz,
//	    Real  flHz,
//	    Real  fhHz=0,
//	    Real fsHz=1.0,
//	    size_t minTaps=0,
//   	    size_t maxTaps=0);

private:
	KaiserWindowDesigner kaiser;
	template<typename T>
	size_t wdfirCx (T& filtCoeff,
				FIRFilter::filter_type type,
		    Real  ripple,
		    Real twNorm,
		    Real  flNorm,
		    Real  fhNorm=0,
		    size_t minTaps=0,
		    size_t maxTaps=0);
};

#endif /* FIRFILTERDESIGNER_H_ */
