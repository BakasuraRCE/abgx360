#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.60)
AC_INIT([abgx360], [1.0.6])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/abgx360.c])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_GCC_TRADITIONAL

# Checks for libraries.
AC_CHECK_LIB([z], [crc32], [], [AC_MSG_ERROR(["zlib not found!"])])
LIBCURL_CHECK_CONFIG([yes], [7.7.2], [], [AC_MSG_ERROR(["libcurl not found!"])])
CFLAGS="$CFLAGS $LIBCURL_CPPFLAGS"
LIBS="$LIBCURL -lz -lm"
# check for CAM if __FreeBSD__ is defined
AC_EGREP_CPP(yes,
[#ifdef __FreeBSD__
  yes
#endif
], is_freebsd=yes, is_freebsd=no)
if test $is_freebsd = yes; then
   AC_CHECK_HEADERS([camlib.h])
   AC_CHECK_LIB([cam], [cam_open_device], [LIBS="$LIBS -lcam"], [AC_MSG_ERROR(["CAM library not found!"])])
fi

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([zlib.h curl/curl.h fnmatch.h pwd.h limits.h malloc.h stddef.h stdlib.h string.h strings.h sys/time.h termios.h unistd.h fcntl.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_VOLATILE
AC_TYPE_SIZE_T
AC_TYPE_OFF_T
AC_TYPE_INT32_T
AC_HEADER_TIME
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_REPLACE_FNMATCH
AC_FUNC_FSEEKO
#AC_FUNC_MALLOC commented out because this will define malloc to rpl_malloc if malloc isn't GNU compatible :/
AC_FUNC_MEMCMP
AC_FUNC_REALLOC
AC_FUNC_STAT
AC_FUNC_ERROR_AT_LINE
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([atexit gettimeofday memset strcasecmp strerror strncasecmp strtol strtoul strstr mkdir pow])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
