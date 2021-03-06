/*      $OpenBSD: fnmatch.h,v 1.5 2000/03/24 17:13:23 millert Exp $        */
/*      $NetBSD: fnmatch.h,v 1.5 1994/10/26 00:55:53 cgd Exp $        */

/*-
 * Copyright (c) 1992, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      @(#)fnmatch.h        8.1 (Berkeley) 6/2/93
 */

#ifndef _FNMATCH_H_
#define _FNMATCH_H_

#define FNM_NOMATCH        1        /* Match failed. */
#define FNM_NOSYS        2        /* Function not supported (unused). */

#define FNM_NOESCAPE        0x01        /* Disable backslash escaping. */
#define FNM_PATHNAME        0x02        /* Slash must be matched by slash. */
#define FNM_PERIOD        0x04        /* Period must be matched by period. */
#ifndef _POSIX_SOURCE
#define FNM_LEADING_DIR        0x08        /* Ignore /<tail> after Imatch. */
#define FNM_CASEFOLD        0x10        /* Case insensitive search. */
#define FNM_IGNORECASE        FNM_CASEFOLD
#define FNM_FILE_NAME        FNM_PATHNAME
#endif

/* sys/cdefs.h

   Copyright 1998, 2000, 2001 Red Hat, Inc.

This file is part of Cygwin.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

#ifndef    _SYS_CDEFS_H
#define _SYS_CDEFS_H
#ifdef    __cplusplus
#define	__BEGIN_DECLS	extern "C" {
#define	__END_DECLS	}
#else
#define    __BEGIN_DECLS
#define    __END_DECLS
#endif
#define __P(protos)     protos        /* full-blown ANSI C */
#define  __CONCAT(__x, __y)   __x##__y
#endif

/* end sys/cdefs.h */

__BEGIN_DECLS
int fnmatch __P((const char *, const char *, int));

__END_DECLS

#endif /* !_FNMATCH_H_ */


