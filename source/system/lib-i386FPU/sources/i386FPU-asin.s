/*!
 *  \file    i386FPU-asin.s
 *  \brief   asin assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: asin assembler function.
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
#   double asin(double x)
#   These functions compute the arc sine of x---that is, the value whose sine
#   is x. The value is in units of radians. Mathematically, there are
#   infinitely many such values; the one actually returned is the one between
#   -pi/2 and pi/2 (inclusive).
#
# ALGORYTHM:
#   asin = atan (x / sqrt(1 - x^2))
#=============================================================================
.text
.global	_i386FPU_asin
_i386FPU_asin:
	fldl	4(%esp)			# x
	fld	%st
	fmul	%st(0)			# x^2
	fld1
	fsubp				# 1 - x^2
	fsqrt				# sqrt (1 - x^2)
	fpatan
	ret
#=============================================================================
