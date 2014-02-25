/*!
 *  \file    i386FPU-scalb.s
 *  \brief   scalb assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: scalb assembler function.
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
#   double scalb(double x, double y)
#=============================================================================
.text
.global _i386FPU_scalb
_i386FPU_scalb:
	fldl	12(%esp)
	fxam
	fnstsw
	fldl	4(%esp)
	andl	$0x4700,	%eax
	cmpl	$0x0700,	%eax
	je	1f
	andl	$0x4500,	%eax
	cmpl	$0x0100,	%eax
	je	2f
	fxam
	fnstsw
	andl	$0x4500,	%eax
	cmpl	$0x0100,	%eax
	je	3f
	fld	%st(1)
	frndint
	fcomp	%st(2)
	fnstsw
	sahf
	jne	4f
	fscale
	fstp	%st(1)
	ret

	# y is -inf
1:	fxam
	fnstsw
	movl	8(%esp),	%edx
	shrl	$5,		%eax
	fstp	%st
	fstp	%st
	andl	$0x80000000,	%edx
	andl	$8,		%eax
	jnz	4f
	shrl	$27,		%edx
	addl	%edx,		%eax
	fldl	zero_nan(,%eax,1)
	ret

	# The result is NaN, but we must not raise an exception. So use a variable.
2:	fstp	%st
	fstp	%st
	fldl	nan
	ret

        # The first parameter is a NaN.  Return it.
3:	fstp	%st(1)
	ret

	# Return NaN and raise the invalid exception.
4:	fstp	%st
	fstp	%st
	fldz
	fdiv	%st
	ret

.align	4, 0x90
zero_nan:
	.double 0.0
nan:
	.byte 0, 0, 0, 0, 0, 0, 0xff, 0x7f
#=============================================================================
