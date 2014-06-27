#!/usr/bin/env python
#
# This file is protected by Copyright. Please refer to the COPYRIGHT file distributed with this 
# source distribution.
# 
# This file is part of REDHAWK Basic Components dsp.
# 
# REDHAWK Basic Components dsp is free software: you can redistribute it and/or modify it under the terms of 
# the GNU Lesser General Public License as published by the Free Software Foundation, either 
# version 3 of the License, or (at your option) any later version.
# 
# REDHAWK Basic Components dsp is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
# PURPOSE.  See the GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License along with this 
# program.  If not, see http://www.gnu.org/licenses/.
#
%{!?_sdrroot: %define _sdrroot /var/redhawk/sdr}
%define _prefix %{_sdrroot}

Name:           dsp
Version:        1.0.0
Release:        2%{?dist}
Summary:        Component Library %{name}

Group:          REDHAWK/Components
License:        LGPLv3+
Source0:        %{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:  autoconf automake libtool
%if 0%{?rhel} >= 6 || 0%{?fedora} >= 12
BuildRequires:  boost-devel >= 1.41
%else
BuildRequires:  boost141-devel
%endif


%description
Component Library %{name}
 * Commit: __REVISION__
 * Source Date/Time: __DATETIME__

%package devel
Summary:        %{name} development package
Group:          REDHAWK/Components
Requires:       %{name} = %{version}
%if 0%{?rhel} >= 6 || 0%{?fedora} >= 12
Requires:       boost-devel >= 1.41
%else
Requires:       boost141-devel
%endif

%description devel
Development headers and libraries for %{name}


%prep
%setup -q


%build
export SDRROOT=%{_sdrroot}
# Implementation cpp
pushd cpp
./reconf
%configure
make %{?_smp_mflags}
popd


%install
rm -rf $RPM_BUILD_ROOT
# Implementation cpp
pushd cpp
make install DESTDIR=$RPM_BUILD_ROOT
popd


%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,redhawk,redhawk,-)
%dir %{_prefix}/dom/deps/%{name}
%{_prefix}/dom/deps/%{name}/dsp.spd.xml
%{_prefix}/dom/deps/%{name}/cpp
%exclude %{_prefix}/dom/deps/%{name}/cpp/include
%exclude %{_prefix}/dom/deps/%{name}/cpp/lib/pkgconfig

%files devel
%{_prefix}/dom/deps/%{name}/cpp/include
%{_prefix}/dom/deps/%{name}/cpp/lib/pkgconfig

