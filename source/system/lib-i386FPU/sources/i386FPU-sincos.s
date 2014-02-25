/*!
 *  \file    i386FPU-sincos.s
 *  \brief   sincos assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: sincos assembler function.
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
#   void sincos(double x, double *sinx, double *cosx)
#   These functions return the sine of x in *sinx and the cosine of x
#   in *cos, where x is given in radians. Both values, *sinx and *cosx,
#   are in the range of -1 to 1.
#=============================================================================
.text
.global _i386FPU_sincos
_i386FPU_sincos:
	fldl	4(%esp)
	fsincos
	movl	12(%esp),	%ecx
	movl	16(%esp),	%edx
	fnstsw	%ax
	testl	$0x400,		%eax
	jnz	1f
	fstpl	(%edx)
	fstpl	(%ecx)
	ret

.align	4, 0x90
1:	fldpi
	fadd	%st(0)
	fxch	%st(1)
2:	fprem1
	fnstsw	%ax
	testl	$0x400,		%eax
	jnz	2b
	fstp	%st(1)
	fsincos
	fstpl	(%edx)
	fstpl	(%ecx)
	ret
#=============================================================================
