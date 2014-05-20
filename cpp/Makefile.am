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

