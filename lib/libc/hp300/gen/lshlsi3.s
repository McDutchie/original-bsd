/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * the Systems Programming Group of the University of Utah Computer
 * Science Department.
 *
 * %sccs.include.redist.c%
 */

#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "@(#)lshlsi3.s	8.1 (Berkeley) 06/04/93"
#endif /* LIBC_SCCS and not lint */

#include "DEFS.h"

/* unsigned << unsigned */
ENTRY(__lshlsi3)
	movel	sp@(8),d1
	movel	sp@(4),d0
	lsll	d1,d0
	rts
