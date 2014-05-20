# SYNOPSIS
#
#   RH_SPKG_INIT([VARIANT-NAME])
#
# DESCRIPTION
#
#   This macro initializes the variables needed for REDHAWK softpackage 
#   libraries. If VARIANT-NAME is given, the resulting softpackage library name
#   will be:
#       [PACKAGE_NAME]_v[VARIANT-NAME]
#
#   If VARIANT-NAME is not provided the resulting name will be:
#       [PACKAGE_NAME]
#
#   The PACKAGE_NAME variable is updated to reflect the correct name of the 
#   library.
#
#   This macro updates:
#
#     PACKAGE_NAME
#     prefix
#
#   And sets:
#
#     spkg_base_dir
#     spkg_dir
#     spkg_impl_dir
#     spkg_lib_dir
#     spkg_include_dir
#     spkg_pkgconfig_dir
#
# LICENSE
#
#   This file is protected by Copyright. Please refer to the COPYRIGHT file 
#   distributed with this source distribution.
#
#   Copying and distribution of this file, with or without modification, are 
#   permitted in any medium without royalty provided the copyright notice
#   and this notice are preserved. This file is offered as-is, without any 
#   warranty.
#

AC_DEFUN([RH_SPKG_INIT],
[
    m4_define(tmp_var_name, '$1')
    AC_SUBST([VARIANT], m4_if(tmp_var_name, '', '', '_v'tmp_var_name))

    AC_PREFIX_DEFAULT(${SDRROOT})
    AC_SUBST([PACKAGE_NAME],        [${PACKAGE_NAME}${VARIANT}])
    AC_SUBST([spkg_base_dir],       [${SDRROOT}/dom/deps])
    AC_SUBST([spkg_dir],            [${spkg_base_dir}/${PACKAGE_NAME}])
    AC_SUBST([spkg_impl_dir],       [${spkg_dir}/cpp])
    AC_SUBST([spkg_lib_dir],        [${spkg_impl_dir}/lib])
    AC_SUBST([spkg_include_dir],    [${spkg_impl_dir}/include])
    AC_SUBST([spkg_pkgconfig_dir],  [${spkg_lib_dir}/pkgconfig])
])

