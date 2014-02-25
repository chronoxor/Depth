/*!
 *  \file    CEndians.inl System byte order utilities definition.
 *  \brief   Static class with system byte order utility methods (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class with system byte order utility methods (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   26.01.2006 02:44:14

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __CENDIANS_INL__
#define __CENDIANS_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline Tbool CEndians::isBigEndian()
{ CALL
  #if defined(__BIG_ENDIAN__)
  return true;
  #else
  return false;
  #endif
}
/*--------------------------------------------------------------------------*/
inline Tbool CEndians::isLittleEndian()
{ CALL
  #if defined(__BIG_ENDIAN__)
  return false;
  #else
  return true;
  #endif
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert8(Tptr a_pBuffer)
{ CALL
  ((Tbuffer)a_pBuffer)[0] = ((Tbuffer)a_pBuffer)[0];
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert8(Tptr a_pDestination, Tcptr a_cpSource)
{ CALL
  ((Tbuffer)a_pDestination)[0] = ((Tbuffer)a_cpSource)[0];
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert16(Tptr a_pBuffer)
{ CALL
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[0], ((Tbuffer)a_pBuffer)[1]);
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert16(Tptr a_pDestination, Tcptr a_cpSource)
{ CALL
  ((Tbuffer)a_pDestination)[0] = ((Tbuffer)a_cpSource)[1];
  ((Tbuffer)a_pDestination)[1] = ((Tbuffer)a_cpSource)[0];
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert32(Tptr a_pBuffer)
{ CALL
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[0], ((Tbuffer)a_pBuffer)[3]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[1], ((Tbuffer)a_pBuffer)[2]);
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert32(Tptr a_pDestination, Tcptr a_cpSource)
{ CALL
  ((Tbuffer)a_pDestination)[0] = ((Tbuffer)a_cpSource)[3];
  ((Tbuffer)a_pDestination)[1] = ((Tbuffer)a_cpSource)[2];
  ((Tbuffer)a_pDestination)[2] = ((Tbuffer)a_cpSource)[1];
  ((Tbuffer)a_pDestination)[3] = ((Tbuffer)a_cpSource)[0];
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert64(Tptr a_pBuffer)
{ CALL
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[0], ((Tbuffer)a_pBuffer)[7]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[1], ((Tbuffer)a_pBuffer)[6]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[2], ((Tbuffer)a_pBuffer)[5]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[3], ((Tbuffer)a_pBuffer)[4]);
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convert64(Tptr a_pDestination, Tcptr a_cpSource)
{ CALL
  ((Tbuffer)a_pDestination)[0] = ((Tbuffer)a_cpSource)[7];
  ((Tbuffer)a_pDestination)[1] = ((Tbuffer)a_cpSource)[6];
  ((Tbuffer)a_pDestination)[2] = ((Tbuffer)a_cpSource)[5];
  ((Tbuffer)a_pDestination)[3] = ((Tbuffer)a_cpSource)[4];
  ((Tbuffer)a_pDestination)[4] = ((Tbuffer)a_cpSource)[3];
  ((Tbuffer)a_pDestination)[5] = ((Tbuffer)a_cpSource)[2];
  ((Tbuffer)a_pDestination)[6] = ((Tbuffer)a_cpSource)[1];
  ((Tbuffer)a_pDestination)[7] = ((Tbuffer)a_cpSource)[0];
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convertFloat(Tptr a_pBuffer)
{ CALL
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[0], ((Tbuffer)a_pBuffer)[3]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[1], ((Tbuffer)a_pBuffer)[2]);
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convertFloat(Tptr a_pDestination, Tcptr a_cpSource)
{ CALL
  ((Tbuffer)a_pDestination)[0] = ((Tbuffer)a_cpSource)[3];
  ((Tbuffer)a_pDestination)[1] = ((Tbuffer)a_cpSource)[2];
  ((Tbuffer)a_pDestination)[2] = ((Tbuffer)a_cpSource)[1];
  ((Tbuffer)a_pDestination)[3] = ((Tbuffer)a_cpSource)[0];
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convertDouble(Tptr a_pBuffer)
{ CALL
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[0], ((Tbuffer)a_pBuffer)[7]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[1], ((Tbuffer)a_pBuffer)[6]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[2], ((Tbuffer)a_pBuffer)[5]);
  NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[3], ((Tbuffer)a_pBuffer)[4]);
}
/*--------------------------------------------------------------------------*/
inline void CEndians::convertDouble(Tptr a_pDestination, Tcptr a_cpSource)
{ CALL
  ((Tbuffer)a_pDestination)[0] = ((Tbuffer)a_cpSource)[7];
  ((Tbuffer)a_pDestination)[1] = ((Tbuffer)a_cpSource)[6];
  ((Tbuffer)a_pDestination)[2] = ((Tbuffer)a_cpSource)[5];
  ((Tbuffer)a_pDestination)[3] = ((Tbuffer)a_cpSource)[4];
  ((Tbuffer)a_pDestination)[4] = ((Tbuffer)a_cpSource)[3];
  ((Tbuffer)a_pDestination)[5] = ((Tbuffer)a_cpSource)[2];
  ((Tbuffer)a_pDestination)[6] = ((Tbuffer)a_cpSource)[1];
  ((Tbuffer)a_pDestination)[7] = ((Tbuffer)a_cpSource)[0];
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
