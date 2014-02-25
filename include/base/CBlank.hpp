/*!
 *  \file    CBlank.hpp Blank class which swallows any argument during the
 *           creation and assigning.
 *  \brief   Blank class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Blank class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   07.03.2006 21:45:31

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
#ifndef __CBLANK_HPP__
#define __CBLANK_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Blank class.
/*!
    This class has swallow constructor  and  assign  operator  so  it  can  be
    initialized with value of any type.
*/
class BASE_API CBlank
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CBlank TDepthCheckType;

  // Check CBlank class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CBlank();
  //! Swallow copy constructor.
  /*!
      \param a_crValue - Constant reference to the argument of any other type.
  */
  template <typename T_Type>
  explicit CBlank(const T_Type& a_crValue);

  //! Operator: Equal to another CBlank class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBlank class.
      \param a_crInstance2 - Constant reference to another instance of the CBlank class.
      \return true  - if CBlank class instance is equal to another one. \n
              false - if CBlank class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CBlank& a_crInstance1, const CBlank& a_crInstance2);
  //! Operator: Not equal to another CBlank class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBlank class.
      \param a_crInstance2 - Constant reference to another instance of the CBlank class.
      \return true  - if CBlank class instance is not equal to another one. \n
              false - if CBlank class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CBlank& a_crInstance1, const CBlank& a_crInstance2);

  //! Operator: Less than another CBlank class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBlank class.
      \param a_crInstance2 - Constant reference to another instance of the CBlank class.
      \return true  - if CBlank class instance is less than another one. \n
              false - if CBlank class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CBlank& a_crInstance1, const CBlank& a_crInstance2);
  //! Operator: More than another CBlank class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBlank class.
      \param a_crInstance2 - Constant reference to another instance of the CBlank class.
      \return true  - if CBlank class instance is more than another one. \n
              false - if CBlank class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CBlank& a_crInstance1, const CBlank& a_crInstance2);
  //! Operator: Less or equal than another CBlank class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBlank class.
      \param a_crInstance2 - Constant reference to another instance of the CBlank class.
      \return true  - if CBlank class instance is less or equal than another one. \n
              false - if CBlank class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CBlank& a_crInstance1, const CBlank& a_crInstance2);
  //! Operator: More or equal than another CBlank class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBlank class.
      \param a_crInstance2 - Constant reference to another instance of the CBlank class.
      \return true  - if CBlank class instance is more or equal than another one. \n
              false - if CBlank class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CBlank& a_crInstance1, const CBlank& a_crInstance2);

  //! Operator: Swallow assign of any other value.
  /*!
      \param a_crValue - Constant reference to the argument of any other type.
      \return Reference to the current class instance.
  */
  template <typename T_Type>
  CBlank& operator = (const T_Type& a_crValue);

  //! Serialize CBlank class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBlank class instances.
  /*!
      \param a_rInstance - Reference to another CBlank class instance.
  */
  void swap(CBlank& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CBlank.inl>
/*==========================================================================*/
//! \example example-base-CBlank.cpp
/*==========================================================================*/
#endif
