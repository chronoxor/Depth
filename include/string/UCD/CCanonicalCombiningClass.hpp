/*!
 *  \file    CCanonicalCombiningClass.hpp Character Canonical Combining class.
 *  \brief   Character Canonical Combining class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character Canonical Combining class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 22:45:54

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
#ifndef __CCANONICALCOMBININGCLASS_HPP__
#define __CCANONICALCOMBININGCLASS_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NUCD {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class of the character Canonical Combining class.
/*!
    Character Canonical Combining class.

    The classes used for the  Canonical  Ordering  Algorithm  in  the  Unicode
    Standard. This property could be considered either an enumerated  property
    or a numeric property: the principal use of the property is  in  terms  of
    the numeric values.

    Value for each character is taken from "UnicodeData.txt" file.
*/
class BASE_API CCanonicalCombiningClass :
  public NDepth::NCommon::IStatic
{
public:
  static const Tuint08 CCC_Spacing;            //! Canonical Combining class is "Spacing, split, enclosing, reordrant, and Tibetan subjoined".
  static const Tuint08 CCC_Overlays;           //! Canonical Combining class is "Overlays and interior".
  static const Tuint08 CCC_Nuktas;             //! Canonical Combining class is "Nuktas".
  static const Tuint08 CCC_VoicingMarks;       //! Canonical Combining class is "Hiragana/Katakana voicing marks".
  static const Tuint08 CCC_Viramas;            //! Canonical Combining class is "Viramas".
  static const Tuint08 CCC_StartFixedPosition; //! Canonical Combining class is "Start of fixed position classes".
  static const Tuint08 CCC_EndFixedPosition;   //! Canonical Combining class is "End of fixed position classes".
  static const Tuint08 CCC_BelowLeftAttached;  //! Canonical Combining class is "Below left attached".
  static const Tuint08 CCC_BelowAttached;      //! Canonical Combining class is "Below attached".
  static const Tuint08 CCC_BelowRightAttached; //! Canonical Combining class is "Below right attached".
  static const Tuint08 CCC_LeftAttached;       //! Canonical Combining class is "Left attached (reordrant around single base character)".
  static const Tuint08 CCC_RightAttached;      //! Canonical Combining class is "Right attached".
  static const Tuint08 CCC_AboveLeftAttached;  //! Canonical Combining class is "Above left attached".
  static const Tuint08 CCC_AboveAttached;      //! Canonical Combining class is "Above attached".
  static const Tuint08 CCC_AboveRightAttached; //! Canonical Combining class is "Above right attached".
  static const Tuint08 CCC_BelowLeft;          //! Canonical Combining class is "Below left".
  static const Tuint08 CCC_Below;              //! Canonical Combining class is "Below".
  static const Tuint08 CCC_BelowRight;         //! Canonical Combining class is "Below right".
  static const Tuint08 CCC_Left;               //! Canonical Combining class is "Left (reordrant around single base character)".
  static const Tuint08 CCC_Right;              //! Canonical Combining class is "Right".
  static const Tuint08 CCC_AboveLeft;          //! Canonical Combining class is "Above left".
  static const Tuint08 CCC_Above;              //! Canonical Combining class is "Above".
  static const Tuint08 CCC_AboveRight;         //! Canonical Combining class is "Above right".
  static const Tuint08 CCC_DoubleBelow;        //! Canonical Combining class is "Double below".
  static const Tuint08 CCC_DoubleAbove;        //! Canonical Combining class is "Double above".
  static const Tuint08 CCC_IotaSubscript;      //! Canonical Combining class is "Below (iota subscript)".
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
