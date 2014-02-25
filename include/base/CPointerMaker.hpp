/*!
 *  \file    CPointerMaker.hpp Utility class that helps to make CPointer
 *           instances from specified values.
 *  \brief   Pointer maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pointer maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   10.10.2006 00:16:45

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
#ifndef __CPOINTERMAKER_HPP__
#define __CPOINTERMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CPointer.hpp>
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Pointer maker class.
/*!
    With this utility class template CPointer instances can  be  made  without
    specifying template arguments.
*/
class BASE_API CPointerMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CPointer instance from specified pointer value.
  /*!
      \param a_pValue - Pointer to the wrapping object.
      \return CPointer class instance.
  */
  template <typename T_Type>
  static CPointer<T_Type> make(T_Type* a_pValue);

  //! Make CPointer instance from specified CPointer class instance.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CPointer class.
      \return CPointer class instance.
  */
  template <typename T_Type>
  static CPointer<T_Type> make(const CPointer<T_Type>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CPointerMaker.inl>
/*==========================================================================*/
#endif
