/*!
 *  \file    i386FPU-frexp.s
 *  \brief   frexp assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: frexp assembler function.
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
#   double frexp(double x, int *y)
#=============================================================================
.text
.global _i386FPU_frexp
_i386FPU_frexp:
	movl	4(%esp),	%ecx
	movl	8(%esp),	%eax
	movl	%eax,		%edx
	andl	$0x7fffffff,	%eax
	orl	%eax,		%ecx
	jz	1f
	xorl	%ecx,		%ecx
	cmpl	$0x7ff00000,	%eax
	jae	1f

	cmpl	$0x00100000,	%eax
	jae	2f

	fldl	4(%esp)
	fmull	two54
	movl	$-54,		%ecx
	fstpl	4(%esp)
	fwait
	movl	8(%esp),	%eax
	movl	%eax,		%edx
	andl	$0x7fffffff,	%eax

2:	shrl	$20,		%eax
	andl	$0x800fffff,	%edx
	subl	$1022,		%eax
	orl	$0x3fe00000,	%edx
	addl	%eax,		%ecx
	movl	%edx,		8(%esp)

	# Store %ecx in the variable pointed to by the second argument, get the factor from the stack and return.
1:	movl	12(%esp),	%eax
	fldl	4(%esp)
	movl	%ecx,		(%eax)
	ret

.align	4, 0x90
two54:
	.byte 0, 0, 0, 0, 0, 0, 0x50, 0x43
#=============================================================================
