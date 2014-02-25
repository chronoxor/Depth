/*!
 *  \file    CTypeInfo.hpp Type information wrapper class provides common
 *           operations with 'C++' types.
 *  \brief   Type information wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Type information wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   16.02.2007 02:30:27

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
#ifndef __CTYPEINFO_HPP__
#define __CTYPEINFO_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Type information wrapper class.
/*!
    Type information wrapper class provides common operations with 'C++' type.
    The  wrapper  class  behaves  like  standard  'std::type_info'  class  and
    provides some more functionality as  well.  It  can  be  constructed  with
    'typeid' operator.
*/
class BASE_API CTypeInfo
{
public:
  //! Default class constructor.
  CTypeInfo();
  //! Initialize with the 'std::type_info' class instance.
  /*!
      \param a_crTypeInfo - Constant reference to the 'std::type_info' class instance.
  */
  CTypeInfo(const std::type_info& a_crTypeInfo);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTypeInfo class.
  */
  CTypeInfo(const CTypeInfo& a_crInstance);
  //! Class destructor.
 ~CTypeInfo();

  //! Operator: Equal to another CTypeInfo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTypeInfo class.
      \param a_crInstance2 - Constant reference to another instance of the CTypeInfo class.
      \return true  - if CTypeInfo class instance is equal to another one. \n
              false - if CTypeInfo class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2);
  //! Operator: Not equal to another CTypeInfo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTypeInfo class.
      \param a_crInstance2 - Constant reference to another instance of the CTypeInfo class.
      \return true  - if CTypeInfo class instance is not equal to another one. \n
              false - if CTypeInfo class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2);

  //! Operator: Less than another CTypeInfo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTypeInfo class.
      \param a_crInstance2 - Constant reference to another instance of the CTypeInfo class.
      \return true  - if CTypeInfo class instance is less than another one. \n
              false - if CTypeInfo class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2);
  //! Operator: More than another CTypeInfo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTypeInfo class.
      \param a_crInstance2 - Constant reference to another instance of the CTypeInfo class.
      \return true  - if CTypeInfo class instance is more than another one. \n
              false - if CTypeInfo class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2);
  //! Operator: Less or equal than another CTypeInfo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTypeInfo class.
      \param a_crInstance2 - Constant reference to another instance of the CTypeInfo class.
      \return true  - if CTypeInfo class instance is less or equal than another one. \n
              false - if CTypeInfo class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2);
  //! Operator: More or equal than another CTypeInfo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTypeInfo class.
      \param a_crInstance2 - Constant reference to another instance of the CTypeInfo class.
      \return true  - if CTypeInfo class instance is more or equal than another one. \n
              false - if CTypeInfo class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2);

  //! Get type name.
  /*!
      Method returns 'C++' name of  the  type.  Note  that  the  name  can  be
      unreadable and it can be not different from one compiler to another.

      \return Type name.
  */
  Tcsstr getName() const;

private:
  const std::type_info* m_cpTypeInfo;   //!< Constant pointer to the current type information value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CTypeInfo.inl>
/*==========================================================================*/
//! \example example-base-CTypeInfo.cpp
/*--------------------------------------------------------------------------*/
//! \test test-base-CTypeInfo.cpp
/*==========================================================================*/
#endif
