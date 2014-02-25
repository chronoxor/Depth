/*!
 *  \file    CReferenceMaker.hpp Utility class that helps to make CReference
 *           instances from specified values.
 *  \brief   Reference maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reference maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   30.07.2006 22:36:23

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
#ifndef __CREFERENCEMAKER_HPP__
#define __CREFERENCEMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CReference.hpp>
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
//! Reference maker class.
/*!
    With this utility class template CReference instances can be made  without
    specifying template arguments.
*/
class BASE_API CReferenceMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CReference instance from specified reference value.
  /*!
      \param a_rValue - Reference to the wrapping object.
      \return CReference class instance.
  */
  template <typename T_Type>
  static CReference<T_Type> make(T_Type& a_rValue);

  //! Make CReference instance from specified CReference class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReference class.
      \return CReference class instance.
  */
  template <typename T_Type>
  static CReference<T_Type> make(const CReference<T_Type>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CReferenceMaker.inl>
/*==========================================================================*/
#endif
