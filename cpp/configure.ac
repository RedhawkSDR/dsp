# This file is protected by Copyright. Please refer to the COPYRIGHT file 
# distributed with this source distribution.
#
# This file is part of REDHAWK Basic Components dsp library.
#
# REDHAWK Basic Components dsp library is free software: you can redistribute
# it and/or modify it under the terms of the GNU Lesser General Public License 
# as published by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# REDHAWK Basic Components dsp library is distributed in the hope that it 
# will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License along
# with this program.  If not, see http://www.gnu.org/licenses/.
#
AC_PREREQ(2.59)
AC_INIT(dsp, 1.0.0)
RH_SPKG_INIT

AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE(nostdinc)
LT_INIT

AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL

AX_BOOST_BASE([1.41])
AX_BOOST_THREAD
AX_BOOST_SYSTEM

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_FILES([Makefile ${PACKAGE_NAME}.pc:dsp.pc.in ${PACKAGE_NAME}.spd.xml:../dsp.spd.xml.in])
AC_OUTPUT

