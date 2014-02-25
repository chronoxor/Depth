/*-----------------------------------------------------------------------------*\
| Matpack base class MpBase                                            mpbase.h |
|                                                                               |
| Last change: Apr 13, 2004							|
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel. All rights reserved.             |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
| warranty.  In no event will the author be held liable for any damages arising |
| from the use of this software.						|
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.							|
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.			|
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration	|
| and installation of Matpack.							|
|                                                                               |
\*-----------------------------------------------------------------------------*/

#ifndef _MPBASE_H_
#define _MPBASE_H_

//-----------------------------------------------------------------------------//
// class MpBase supplies basic definitions for all classes used within Matpack
//-----------------------------------------------------------------------------//

class MpBase
{
  public:

    /*! 
       Alignment definitions are used e.g. in class MpNotebook for tab positions
       in class MpLabel for text adjustment, in class Scene for text alignment.
       Horizontal and vertical alignments can be OR-ed like "AlignLeft | AlignTop"
    
       When testing a value always use
       an expression like
       
          if ( (mode & AlignHMask) == compare_value ) { ... }
	  
    */ 
    enum { AlignHCenter = 0x0000,       // horizontal alignments
           AlignLeft    = 0x0001,
	   AlignRight   = 0x0002,

	   AlignVCenter = 0x0000,       // vertical alignments
	   AlignTop     = 0x0004,
	   AlignBottom  = 0x0008,
	   AlignBase    = 0x0010,       // character base line

	   AlignHMask   = 0x0003,       // mask for horizontal alignment
	   AlignVMask   = 0x001C,       // mask for vertical alignment
           AlignMask    = 0x001F        // mask for alignment
    };
};

//-----------------------------------------------------------------------------//

#endif

