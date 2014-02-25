#################################################################################
#  										#
# Makefile for the Matpack C++ Library			      			#
#  									  	#
# Last change: Jul 18, 2002						  	#
#  										#
# Matpack Library Release 1.9.0							#
# Copyright (C) 1991-2002 by Berndt M. Gammel. All rights reserved. 		#
#  										#
# Permission to use , copy, and  distribute  Matpack  in  its entirety  and its #
# documentation  for non-commercial purpose and  without fee is hereby granted, #
# provided that this license information and copyright notice appear unmodified #
# in all copies.  This software is provided 'as is'  without express or implied #
# warranty.  In no event will the author be held liable for any damages arising #
# from the use of this software.						#
# Note that distributing Matpack 'bundled' in with any product is considered to #
# be a 'commercial purpose'.							#
# The software may be modified for your own purposes, but modified versions may #
# not be distributed without prior consent of the author.			#
#                                                                               #
# Read the  COPYRIGHT and  README files in this distribution about registration	#
# and installation of Matpack.							#
#                                                                               #
#################################################################################

###########################################################################
### set path to matpack home directory
###########################################################################

MATPACK = ../..

###########################################################################
### include common rules
###########################################################################

include ${MATPACK}/Makefile.common

###########################################################################
### make all objects
###########################################################################

RANINC=	${INCLUDE}/mprandom.h 

RANOBJ= ran000.o \
	ran001.o \
	ran002.o \
	ran004.o \
	ran005.o \
	ran250.o \
	ran013.o \
	ran055.o \
	ran056.o \
	ran088.o \
	ran205.o \
	ran800.o \
	ran19937.o \
	ran32k3a.o \
	ranbeta.o \
	ranbinomial.o \
	ranchisqr.o \
	ranclass.o \
	ranerlang.o \
	ranexpo.o \
	ranfdistrib.o \
	rangamma.o \
	ranlognormal.o \
	rannormal.o \
	ranuniform.o \
	ranu01.o \
	ranpoisson.o \
	ranlux.o \
	ranmar.o \
	ransphere.o

RANPIC=	${RANOBJ:%.o=%.pic.o}

RANSRC=	${RANOBJ:%.o=%.cpp}

ALL: ${RANOBJ} OBJLIST

pic: ${RANPIC} PICLIST

###########################################################################
### include file dependencies
###########################################################################

${RANOBJ}: ${RANINC}

###########################################################################
### make a file "Objects" with a list of all ".o" files
###########################################################################

OBJLIST:
	@echo ${RANOBJ} > Objects

PICLIST:
	@echo ${RANPIC} > PicObjects

###########################################################################
### exceptions
###########################################################################

###########################################################################
### make clean 								###
###########################################################################
 
clean:
	rm -f ${RANOBJ} ${RANPIC} core a.out

new:
	${MAKE} clean
	${MAKE}

update: 
	${MAKE}
	${ADDAR} ${MATLIB} `cat Objects`

###########################################################################
### make protected save subdirectory
###########################################################################

save:
	@mkdir -p SAVE
	@chmod 755 SAVE
	@find *.c *.cpp *.h *.doc *.tbl *.scn *.xpm *.cmp *.tex *.sty *.html \
	 *.xmgr *.xvgr Makefile* makefile* *.ps README COPYRIGHT > Files ; \
	 for i in `cat Files` ; do \
	     gzip -c $$i > SAVE/$$i.gz ; \
	 done 
	@chmod 500 SAVE

###########################################################################
