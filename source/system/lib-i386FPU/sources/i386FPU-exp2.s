/*!
 *  \file    i386FPU-exp2.s
 *  \brief   exp2 assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: exp2 assembler function.
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
#   double exp2(double x)
#   These functions compute 2 raised to the power x. Mathematically, exp2 (x)
#   is the same as exp (x * log (2)).
#=============================================================================
.text
.global _i386FPU_exp2
_i386FPU_exp2:
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
	fld	%st
	frndint				# int(x)
	fsubr	%st,		%st(1)	# fract(x)
	fxch
	f2xm1				# 2^(fract(x)) - 1
	fld1
	faddp				# 2^(fract(x))
	fscale				# e^x
	fstp	%st(1)
	ret

1:	testl	$0x200,		%eax	# Test sign.
	jz	2f			# If positive, jump.
	fstp	%st
	fldz				# Set result to 0.
2:	ret
#=============================================================================
