#
# This file is protected by Copyright. Please refer to the COPYRIGHT file distributed with this 
# source distribution.
# 
# This file is part of REDHAWK Basic Components dsp library.
# 
# REDHAWK Basic Components DataWriter is free software: you can redistribute it and/or modify it under the terms of 
# the GNU Lesser General Public License as published by the Free Software Foundation, either 
# version 3 of the License, or (at your option) any later version.
# 
# REDHAWK Basic Components DataWriter is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
# PURPOSE.  See the GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License along with this 
# program.  If not, see http://www.gnu.org/licenses/.
#
lib_LTLIBRARIES = lib@PACKAGE_NAME@.la
lib@PACKAGE_NAME@_la_CXXFLAGS = -Wall -I$(top_srcdir)/inc $(BOOST_CPPFLAGS)
lib@PACKAGE_NAME@_la_LDFLAGS = $(BOOST_LDFLAGS) $(BOOST_THREAD_LIB) $(BOOST_SYSTEM_LIB)

libdir = $(spkg_lib_dir)
dsp_src = \
src/am_fm_pm_baseband_demod.cpp \
src/Decimate.cpp \
src/exp_agc.cpp \
src/FIRFilter.cpp \
src/FirFilterDesigner.cpp \
src/framebuffer.cpp \
src/RealFIRFilter.cpp \
src/resampler.cpp \
src/Tuner.cpp
lib@PACKAGE_NAME@_la_SOURCES = $(dsp_src)

incdir = $(spkg_include_dir)
dsp_inc = \
inc/am_fm_pm_baseband_demod.h \
inc/DataTypes.h \
inc/Decimate.h \
inc/exp_agc.h \
inc/FirFilterDesigner.h \
inc/FIRFilter.h \
inc/framebuffer.h \
inc/quantized_cache.h \
inc/RealFIRFilter.h \
inc/resampler.h \
inc/Tuner.h \
inc/vectormean.h \
inc/zeromean.h
dist_inc_DATA = $(dsp_inc)

xmldir = $(spkg_dir)
dist_xml_DATA = ../@PACKAGE_NAME@.spd.xml

pkgconfigdir = $(spkg_pkgconfig_dir)
dist_pkgconfig_DATA = @PACKAGE_NAME@.pc


distclean-local:
	rm -f config.*
	rm -rf autom4te.cache
	rm -f acinclude.m4
	rm -f aclocal.m4
	rm -f configure
	rm -f depcomp
	rm -f install-sh
	rm -f ltmain.sh
	rm -f Makefile
	rm -f Makefile.in
	rm -f missing
	rm -rf .deps
	rm -rf .libs
	rm -f *.o
	rm -f *.lo
	rm -f libdsp.la
	rm -f libtool

