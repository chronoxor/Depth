/*!
 *  \file    i386FPU-ilogb.s
 *  \brief   ilogb assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: ilogb assembler function.
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
#   int ilogb(double x)
#   These functions are equivalent to the corresponding logb functions except
#   that they return signed integer values.
#=============================================================================
.text
.global _i386FPU_ilogb
_i386FPU_ilogb:
	fldl	4(%esp)
	# I added the following ugly construct because ilogb(+-Inf) is
	# required to return INT_MAX in ISO C99.
	# -- jakub@redhat.com.
	fxam				# Is NaN or +-Inf?
	fstsw	%ax
	movb	$0x45,		%dh
	andb	%ah,		%dh
	cmpb	$0x05,		%dh
	je	1f			# Is +-Inf, jump.

	fxtract
	pushl	%eax
	fstp	%st

	fistpl	(%esp)
	fwait
	popl	%eax

	ret

1:	fstp	%st
	movl	$0x7fffffff,	%eax
	ret
#=============================================================================
