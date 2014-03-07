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
