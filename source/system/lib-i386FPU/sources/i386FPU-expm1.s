/*!
 *  \file    i386FPU-expm1.s
 *  \brief   expm1 assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: expm1 assembler function.
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
#   double expm1(double x)
#   These functions return a value equivalent to exp (x) - 1. They are
#   computed in a way that is accurate even if x is near zero--a case
#   where exp (x) - 1 would be inaccurate owing to subtraction of two
#   numbers that are nearly equal.
#
# ALGORYTHM:
#   e^x - 1 = 2^( x*log2( e ) ) - 1
#=============================================================================
.text
.global _i386FPU_expm1
_i386FPU_expm1:
	fldl	4(%esp)			# x
	fxam				# Is NaN or +-Inf?
	fstsw	%ax
	movb	$0x45,		%ch
	andb	%ah,		%ch
	cmpb	$0x40,		%ch
	je	3f			# If +-0, jump.
	cmpb	$0x05,		%ch
	je	2f			# If +-Inf, jump.

	fldt	l2e			# log2(e) : x
	fmulp				# log2(e)*x
	fld	%st			# log2(e)*x : log2(e)*x
	frndint				# int(log2(e)*x) : log2(e)*x
	fsubr	%st,		%st(1)	# int(log2(e)*x) : fract(log2(e)*x)
	fxch				# fract(log2(e)*x) : int(log2(e)*x)
	f2xm1				# 2^fract(log2(e)*x)-1 : int(log2(e)*x)
	fscale				# 2^(log2(e)*x)-2^int(log2(e)*x) : int(log2(e)*x)
	fxch				# int(log2(e)*x) : 2^(log2(e)*x)-2^int(log2(e)*x)
	fldl	one			# 1 : int(log2(e)*x) : 2^(log2(e)*x)-2^int(log2(e)*x)
	fscale				# 2^int(log2(e)*x) : int(log2(e)*x) : 2^(log2(e)*x)-2^int(log2(e)*x)
	fsubrl	one			# 1-2^int(log2(e)*x) : int(log2(e)*x) : 2^(log2(e)*x)-2^int(log2(e)*x)
	fstp	%st(1)			# 1-2^int(log2(e)*x) : 2^(log2(e)*x)-2^int(log2(e)*x)
	fsubrp	%st,		%st(1)	# 2^(log2(e)*x)
	ret

2:	testl	$0x200,		%eax	# Test sign.
	jz	3f			# If positive, jump.
	fstp	%st
	fldl	minus1			# Set result to -1.0.
3:	ret

.align	4, 0x90
minus1:
	.double -1.0
one:
	.double 1.0
l2e:
	.tfloat 1.442695040888963407359924681002
#=============================================================================
