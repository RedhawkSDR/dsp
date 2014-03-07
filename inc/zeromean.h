/**
 * \file zeromean.h
 * \date Jan 29, 2014
 * \author bsg
 */

#ifndef ZEROMEAN_H_
#define ZEROMEAN_H_

/**
 * Remove the mean from data in a container
 * 
 * \tparam T iterator
 * \tparam U iterator
 */
template<typename T, typename U>
float zeroMean(T begin, T end, U out)
{
    float total=0;
    T i = begin;
    size_t count=0;
    for (; i!=end; i++, count++)
    {
        total+=*i;
    }
    float mean = total/count;
    for (i=begin; i!=end; i++, out++)
    {
        *out=*i -mean;
    }
    return mean;
}

#endif /* ZEROMEAN_H_ */
