/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface                mpdevice.h |
| include file for class MpDevice                                               |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
| warranty.  In no event will the author be held liable for any damages arising |
| from the use of this software.                                                |
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.                                                    |
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.                       |
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration |
| and installation of Matpack.                                                  |
|                                                                               |
\*-----------------------------------------------------------------------------*/

#ifndef _MPDEVICE_H_
#define _MPDEVICE_H_

//----------------------------------------------------------------------------//

namespace MATPACK {

class MpColor;

//----------------------------------------------------------------------------//
// class MpDevice:
// basic information about graphics device (abstract class)
//----------------------------------------------------------------------------//

class MpDevice 
{ 
  friend class MpColor;

  public:
    bool true_color;
    bool color_allocation_failure;
   
    int bits_per_rgb;
    unsigned long red_mask, green_mask, blue_mask;
    int red_shift, green_shift, blue_shift;

    int HighBit (unsigned long ul);

    virtual ~MpDevice () { };
    virtual void Initialize (void) = 0;

    virtual unsigned long AllocateColor (MpColor *colordef,
                                         unsigned long default_pixel, 
                                         int color_dist) = 0;
};

//----------------------------------------------------------------------------//
// derived classes
//----------------------------------------------------------------------------//

class MpPSDevice: public MpDevice
{
  public:
    virtual void Initialize (void);
    virtual unsigned long AllocateColor (MpColor *colordef,
                                         unsigned long default_pixel, 
                                         int color_dist) 
      { return 0; }
};

//----------------------------------------------------------------------------//

class MpX11Device: public MpDevice
{
  public:
    virtual void Initialize (void);
    virtual unsigned long AllocateColor (MpColor *colordef,
                                         unsigned long default_pixel, 
                                         int color_dist);
};

//----------------------------------------------------------------------------//
// Returns position of highest set bit in 'ul' as an integer or -1 if none
//----------------------------------------------------------------------------//

inline int MpDevice::HighBit (unsigned long ul)
{ 
  const int w = (sizeof(unsigned long)<<3) - 1;
  unsigned long hb = (unsigned long)1 << w;
  int i;  
  for (i = w; ((ul & hb) == 0) && i >= 0;  i--, hb >>= 1);
  return i;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
