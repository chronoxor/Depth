/*!
 *  \file    i386FPU-floor.s
 *  \brief   floor assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: floor assembler function.
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
#   double floor(double x)
#=============================================================================
.text
.global _i386FPU_floor
_i386FPU_floor:
	fldl	4(%esp)
	subl	$8,%esp

	fstcw	4(%esp)			# store fpu control word

	# We use here %edx although only the low 1 bits are defined.
	# But none of the operations should care and they are faster
	# than the 16 bit operations.
	movl	$0x400,		%edx	# round towards -oo
	orl	4(%esp),	%edx
	andl	$0xf7ff,	%edx
	movl	%edx,		(%esp)
	fldcw	(%esp)			# load modified control word

	frndint				# round

	fldcw	4(%esp)			# restore original control word

	addl	$8,		%esp
	ret
#=============================================================================
