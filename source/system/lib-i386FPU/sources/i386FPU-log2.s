/*!
 *  \file    i386FPU-log2.s
 *  \brief   log2 assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: log2 assembler function.
#
#   AUTHOR:    J.T. Conklin (jtc@wimsey.com)
#   GROUP:     Winning Strategies, Inc.
#   PROJECT:   The Depth
#   PART:      i386 FPU math library
#   VERSION:   1.0
#   CREATED:   03.01.2006 01:14:28
#
#   EMAIL:     chronoxor@gmail.com
#   WWW:       http://code.google.com/p/depth
#
#   COPYRIGHT: (C) 2006 The NULL workgroup. All Rights Reserved.
#-----------------------------------------------------------------------------
#   Copyright (C) 2006 The NULL workgroup
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#-----------------------------------------------------------------------------
#   FILE ID: $Id$
#
#   CHANGE LOG:
#
#   $Log$
#=============================================================================
# DESCRIPTION:
#   double log2(double x)
#   These functions return the base-2 logarithm of x. log2 (x) equals
#   log (x) / log (2).
#=============================================================================
.text
.global _i386FPU_log2
_i386FPU_log2:
	fldl	one
	fldl	4(%esp)			# x : 1
	fxam
	fnstsw
	fld	%st			# x : x : 1
	sahf
	jc	3f			# in case x is NaN or +Inf
4:	fsub	%st(2),		%st	# x-1 : x : 1
	fld	%st			# x-1 : x-1 : x : 1
	fabs				# |x-1| : x-1 : x : 1
	fcompl	limit			# x-1 : x : 1
	fnstsw				# x-1 : x : 1
	andb	$0x45,		%ah
	jz	2f
	fstp	%st(1)			# x-1 : 1
	fyl2xp1				# log(x)
	ret

2:	fstp	%st(0)			# x : 1
	fyl2x				# log(x)
	ret

3:	jp	4b			# in case x is +Inf
	fstp	%st(1)
	fstp	%st(1)
	ret

.align	4, 0x90
one:
	.double 1.0
limit:
	.double 0.29
#=============================================================================
