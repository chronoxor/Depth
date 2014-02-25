/*!
 *  \file    i386FPU-hypot.s
 *  \brief   hypot assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: hypot assembler function.
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
#   double hypot(double x, double y)
#   These functions return sqrt (x*x + y*y). This is the length of the
#   hypotenuse of a right triangle with sides of length x and y, or the
#   distance of the point (x, y) from the origin. Using this function
#   instead of the direct formula is wise, since the error is much smaller.
#=============================================================================
.text
.global _i386FPU_hypot
_i386FPU_hypot:
	fldl	4(%esp)			# x
	fxam
	fnstsw
	fldl	12(%esp)		# y : x
	movb	%ah,		%ch
	fxam
	fnstsw
	movb	%ah,		%al
	orb	%ch,		%ah
	sahf
	jc	1f
	fmul	%st(0)			# y * y : x
	fxch				# x : y * y
	fmul	%st(0)			# x * x : y * y
	faddp				# x * x + y * y
	fsqrt
2:	ret

	# We have to test whether any of the parameters is Inf.
	# In this case the result is infinity.
1:	andb	$0x45,		%al
	cmpb	$5,		%al
	je	3f			# jump if y is Inf
	andb	$0x45,		%ch
	cmpb	$5,		%ch
	jne	4f			# jump if x is not Inf
	fxch
3:	fstp	%st(1)
	fabs
	jmp	2b

4:	testb	$1,		%al
	jnz	5f			# y is NaN
	fxch
5:	fstp	%st(1)
	jmp	2b
#=============================================================================
