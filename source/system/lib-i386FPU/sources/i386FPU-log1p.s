/*!
 *  \file    i386FPU-log1p.s
 *  \brief   log1p assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: log1p assembler function.
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
#   double log1p(double x)
#   These functions returns a value equivalent to log (1 + x). They are
#   computed in a way that is accurate even if x is near zero.
#
# ALGORYTHM:
#   The fyl2xp1 instruction has such a limited range:
#        -(1 - (sqrt(2) / 2)) <= x <= sqrt(2) - 1
#   it's not worth trying to use it.
#
#   Also, I'm not sure fyl2xp1's extra precision will
#   matter once the result is converted from extended
#   real (80 bits) back to double real (64 bits).
#=============================================================================
.text
.global _i386FPU_log1p
_i386FPU_log1p:
	fldln2

	fldl	4(%esp)

	fxam
	fnstsw
	fld	%st
	sahf
	jc	3f			# in case x is NaN or +Inf
4:	fabs
        fcompl	limit
	fnstsw
	sahf
	jc	2f

	faddl	one
	fyl2x
	ret

2:	fyl2xp1
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
