/*!
 *  \file    i386FPU-cbrt.s
 *  \brief   cbrt assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: cbrt assembler function.
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
#   double cbrt(double x)
#   These functions return the cube root of x. They cannot fail; every
#   representable real value has a representable real cube root.
#=============================================================================
.text
.global _i386FPU_cbrt
_i386FPU_cbrt:
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
	movl	8(%esp),	%eax
	movl	%eax,		%edx
	andl	$0x7fffffff,	%eax

2:	shrl	$20,		%eax
	andl	$0x800fffff,	%edx
	subl	$1022,		%eax
	orl	$0x3fe00000,	%edx
	addl	%eax,		%ecx
	movl	%edx,		8(%esp)

	fldl	4(%esp)			# xm
	fabs

	# The following code has two tracks:
	#  a) compute the normalized cbrt value
	#  b) compute xe/3 and xe%3
	# The right track computes the value for b) and this is done
	# in an optimized way by avoiding division.
	#
	# But why two tracks at all?  Very easy: efficiency.  Some FP
	# instruction can overlap with a certain amount of integer (and
	# FP) instructions.  So we get (except for the imull) all
	# instructions for free.

	fld	%st(0)			# xm : xm

	fmull	f7			# f7*xm : xm
	movl	$1431655766,	%eax
	faddl	f6			# f6+f7*xm : xm
	imull	%ecx
	fmul	%st(1)			# (f6+f7*xm)*xm : xm
	movl	%ecx,		%eax
	faddl	f5			# f5+(f6+f7*xm)*xm : xm
	sarl	$31,		%eax
	fmul	%st(1)			# (f5+(f6+f7*xm)*xm)*xm : xm
	subl	%eax,		%edx
	faddl	f4			# f4+(f5+(f6+f7*xm)*xm)*xm : xm
	fmul	%st(1)			# (f4+(f5+(f6+f7*xm)*xm)*xm)*xm : xm
	faddl	f3			# f3+(f4+(f5+(f6+f7*xm)*xm)*xm)*xm : xm
	fmul	%st(1)			# (f3+(f4+(f5+(f6+f7*xm)*xm)*xm)*xm)*xm : xm
	faddl	f2			# f2+(f3+(f4+(f5+(f6+f7*xm)*xm)*xm)*xm)*xm : xm
	fmul	%st(1)			# (f2+(f3+(f4+(f5+(f6+f7*xm)*xm)*xm)*xm)*xm)*xm : xm
	faddl	f1			# u:=f1+(f2+(f3+(f4+(f5+(f6+f7*xm)*xm)*xm)*xm)*xm)*xm : xm

	fld	%st			# u : u : xm
	fmul	%st(1)			# u*u : u : xm
	fld	%st(2)			# xm : u*u : u : xm
	fadd	%st			# 2*xm : u*u : u : xm
	fxch	%st(1)			# u*u : 2*xm : u : xm
	fmul	%st(2)			# t2:=u*u*u : 2*xm : u : xm
	movl	%edx,		%eax
	fadd	%st,		%st(1)	# t2 : t2+2*xm : u : xm
	leal	(%edx,%edx,2),	%edx
	fadd	%st(0)			# 2*t2 : t2+2*xm : u : xm
	subl	%edx,		%ecx
	faddp	%st,		%st(3)	# t2+2*xm : u : 2*t2+xm
	shll	$3,		%ecx
	fmulp				# u*(t2+2*xm) : 2*t2+xm
	fdivp	%st,		%st(1)	# u*(t2+2*xm)/(2*t2+xm)
	fmull	16+factor(%ecx)		# u*(t2+2*xm)/(2*t2+xm)*FACT
	pushl	%eax
	fildl	(%esp)			# xe/3 : u*(t2+2*xm)/(2*t2+xm)*FACT
	fxch				# u*(t2+2*xm)/(2*t2+xm)*FACT : xe/3
	fscale				# u*(t2+2*xm)/(2*t2+xm)*FACT*2^xe/3
	popl	%edx
	movl	8(%esp),	%eax
	testl	%eax,		%eax
	fstp	%st(1)
	jns	4f
	fchs
4:	ret

	# Return the argument.
1:	fldl	4(%esp)
	ret

.align	4, 0x90
f7:
	.double -0.145263899385486377
f6:
	.double 0.784932344976639262
f5:
	.double -1.83469277483613086
f4:
	.double 2.44693122563534430
f3:
	.double -2.11499494167371287
f2:
	.double 1.50819193781584896
f1:
	.double 0.354895765043919860
factor:
	.double 0.629960524947436582364439673883
	.double 0.793700525984099737355196796584
	.double 1.0
	.double 1.2599210498948731648
	.double 1.5874010519681994748
two54:
	.byte 0, 0, 0, 0, 0, 0, 0x50, 0x43
#=============================================================================
