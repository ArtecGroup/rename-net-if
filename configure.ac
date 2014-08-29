#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rename-net-if], [1.0], [nkulikov@artec-group.com])
AC_CONFIG_SRCDIR([rename-net-if.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

AM_INIT_AUTOMAKE(foreign -Wall -Werror)

AC_PROG_CC

AC_CHECK_HEADERS([string.h sys/ioctl.h])
AC_CHECK_FUNCS([memset socket])

AC_OUTPUT
