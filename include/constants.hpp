/*!
 *  \file    constants.hpp Contains base constants definitions for the Depth
 *           project.
 *  \brief   Constants definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constants definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Constants definitions
    VERSION:   1.0
    CREATED:   02.01.2006 00:07:17

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
#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__
/*==========================================================================*/
#include <Depth/include/configure.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConstants {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class with base constants.
/*!
    Class with base constants definition.
*/
class BASE_API CConstants
{
public:
  // Debug/Release build type constants.
  static const NTypes::Tbool isDebug;            //!< Is current build type is Debug?
  static const NTypes::Tbool isRelease;          //!< Is current build type is Release?

  // Endian byte orders constants.
  static const NTypes::Tbool isBigEndian;        //!< Is system have big-endian byte order?
  static const NTypes::Tbool isLittleEndian;     //!< Is system have little-endian byte order?

  // ASCII/Unicode constants.
  static const NTypes::Tbool isASCII;            //!< Is ASCII character encoding used as default?
  static const NTypes::Tbool isUnicode;          //!< Is Unicode character encoding used as default?

  // Platform bits/bytes count constant.
  static const NTypes::Tuint platformBits;       //!< Platform bits count.
  static const NTypes::Tuint platformBytes;      //!< Platform bytes count.
  static const NTypes::Tuint platformMaxBits;    //!< Platform maximal bits count.
  static const NTypes::Tuint platformMaxBytes;   //!< Platform maximal bytes count.

  // Pointer constants.
  static const NTypes::Tptr ptrMin;              //!< Minimal pointer value.
  static const NTypes::Tptr ptrMax;              //!< Maximal pointer value.

  // Characters constants.
  static const NTypes::Tchar   charMin;          //!< Minimal system character value.
  static const NTypes::Tchar   charMax;          //!< Maximal system character value.
  static const NTypes::Tcharu  charAbsMin;       //!< Minimal absolute system character value.
  static const NTypes::Tcharu  charAbsMax;       //!< Maximal absolute system character value.
  static const NTypes::Tschar  scharMin;         //!< Minimal character value.
  static const NTypes::Tschar  scharMax;         //!< Maximal character value.
  static const NTypes::Tscharu scharAbsMin;      //!< Minimal absolute character value.
  static const NTypes::Tscharu scharAbsMax;      //!< Maximal absolute character value.
  static const NTypes::Twchar  wcharMin;         //!< Minimal wide character value.
  static const NTypes::Twchar  wcharMax;         //!< Maximal wide character value.
  static const NTypes::Twcharu wcharAbsMin;      //!< Minimal absolute wide character value.
  static const NTypes::Twcharu wcharAbsMax;      //!< Maximal absolute wide character value.

  // Integer numbers constants.
  static const NTypes::Tsint   sintMin;          //!< Minimal signed integer value.
  static const NTypes::Tsint   sintMax;          //!< Maximal signed integer value.
  static const NTypes::Tuint   uintMin;          //!< Minimal unsigned integer value.
  static const NTypes::Tuint   uintMax;          //!< Maximal unsigned integer value.
  static const NTypes::Tsint08 sint08Min;        //!< Minimal signed byte value.
  static const NTypes::Tsint08 sint08Max;        //!< Maximal signed byte value.
  static const NTypes::Tuint08 uint08Min;        //!< Minimal unsigned byte value.
  static const NTypes::Tuint08 uint08Max;        //!< Maximal unsigned byte value.
  static const NTypes::Tsint16 sint16Min;        //!< Minimal signed word value.
  static const NTypes::Tsint16 sint16Max;        //!< Maximal signed word value.
  static const NTypes::Tuint16 uint16Min;        //!< Minimal unsigned word value.
  static const NTypes::Tuint16 uint16Max;        //!< Maximal unsigned word value.
  static const NTypes::Tsint32 sint32Min;        //!< Minimal signed double word value.
  static const NTypes::Tsint32 sint32Max;        //!< Maximal signed double word value.
  static const NTypes::Tuint32 uint32Min;        //!< Minimal unsigned double word value.
  static const NTypes::Tuint32 uint32Max;        //!< Maximal unsigned double word value.
  static const NTypes::Tsint64 sint64Min;        //!< Minimal signed quadra word value.
  static const NTypes::Tsint64 sint64Max;        //!< Maximal signed quadra word value.
  static const NTypes::Tuint64 uint64Min;        //!< Minimal unsigned quadra word value.
  static const NTypes::Tuint64 uint64Max;        //!< Maximal unsigned quadra word value.

  // Real numbers constants.
  static const NTypes::Tbool isRealFloat;        //!< Is real number have float type?
  static const NTypes::Tbool isRealDouble;       //!< Is real number have double type?

  // Float numbers constants.
  static const NTypes::Tfloat floatEps;          //!< Float epsilon value.
  static const NTypes::Tfloat floatCompareEps;   //!< Float compare epsilon value.
  static const NTypes::Tfloat floatMin;          //!< Minimal float value.
  static const NTypes::Tfloat floatMax;          //!< Maximal float value.
  static const NTypes::Tsint  floatPrec;         //!< Float precision value.
  static const NTypes::Tsint  floatMant;         //!< Float mantissa value.
  static const NTypes::Tsint  floatMinExp;       //!< Float minimal exponent value.
  static const NTypes::Tsint  floatMaxExp;       //!< Float maximal exponent value.
  static const NTypes::Tsint  floatMin10Exp;     //!< Float minimal 10 exponent value.
  static const NTypes::Tsint  floatMax10Exp;     //!< Float maximal 10 exponent value.

  // Double numbers constants.
  static const NTypes::Tdouble doubleEps;        //!< Double epsilon value.
  static const NTypes::Tdouble doubleCompareEps; //!< Double compare epsilon value.
  static const NTypes::Tdouble doubleMin;        //!< Minimal double value.
  static const NTypes::Tdouble doubleMax;        //!< Maximal double value.
  static const NTypes::Tsint   doublePrec;       //!< Double precision value.
  static const NTypes::Tsint   doubleMant;       //!< Double mantissa value.
  static const NTypes::Tsint   doubleMinExp;     //!< Double minimal exponent value.
  static const NTypes::Tsint   doubleMaxExp;     //!< Double maximal exponent value.
  static const NTypes::Tsint   doubleMin10Exp;   //!< Double minimal 10 exponent value.
  static const NTypes::Tsint   doubleMax10Exp;   //!< Double maximal 10 exponent value.

  // Real numbers constants.
  static const NTypes::Treal realEps;            //!< Real epsilon value.
  static const NTypes::Treal realCompareEps;     //!< Real compare epsilon value.
  static const NTypes::Treal realMin;            //!< Minimal real value.
  static const NTypes::Treal realMax;            //!< Maximal real value.
  static const NTypes::Tsint realPrec;           //!< Real precision value.
  static const NTypes::Tsint realMant;           //!< Real mantissa value.
  static const NTypes::Tsint realMinExp;         //!< Real minimal exponent value.
  static const NTypes::Tsint realMaxExp;         //!< Real maximal exponent value.
  static const NTypes::Tsint realMin10Exp;       //!< Real minimal 10 exponent value.
  static const NTypes::Tsint realMax10Exp;       //!< Real maximal 10 exponent value.

private:
  //! Default class private constructor.
  CConstants();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
