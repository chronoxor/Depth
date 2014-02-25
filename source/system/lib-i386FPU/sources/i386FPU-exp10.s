/*!
 *  \file    i386FPU-exp10.s
 *  \brief   exp10 assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: exp10 assembler function.
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
#   double exp10(double x)
#   These functions compute 10 raised to the power x. Mathematically,
#   exp10 (x) is the same as exp (x * log (10)).
#
# ALGORYTHM:
#   10^x = 2^(x * log2(10))
#=============================================================================
.text
.global _i386FPU_exp10
_i386FPU_exp10:
	fldl	4(%esp)
	# I added the following ugly construct because exp(+-Inf) resulted
	# in NaN.  The ugliness results from the bright minds at Intel.
	# For the i686 the code can be written better.
	# -- drepper@cygnus.com.
	fxam				# Is NaN or +-Inf?
	fstsw	%ax
	movb	$0x45,		%dh
	andb	%ah,		%dh
	cmpb	$0x05,		%dh
	je	1f			# Is +-Inf, jump.
	fldl2t
	fmulp				# x * log2(10)
	fld	%st
	frndint				# int(x * log2(10))
	fsubr	%st,		%st(1)	# fract(x * log2(10))
	fxch
	f2xm1				# 2^(fract(x * log2(10))) - 1
	fld1
	faddp				# 2^(fract(x * log2(10)))
	fscale				# e^x
	fstp	%st(1)
	ret

1:	testl	$0x200,		%eax	# Test sign.
	jz	2f			# If positive, jump.
	fstp	%st
	fldz				# Set result to 0.
2:	ret
#=============================================================================
