/*!
 *  \file    CReference.hpp Reference template class emulates references
 *           thorough the class wrapper.
 *  \brief   Reference template wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reference template wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   30.07.2006 22:07:26

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
#ifndef __CREFERENCE_HPP__
#define __CREFERENCE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AAddress.hpp>
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
//! Reference template wrapper class.
/*!
    Reference template  wrapper  emulates  basic  operations  with  references
    through the class wrapper.
*/
template <typename T_Type>
class CReference
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CReference<T_Type> TDepthCheckType;

  // Check CReference class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Reference template type.
  typedef T_Type& TType;

  //! Default class constructor.
  CReference();
  //! Initialize reference value.
  /*!
      \param a_rValue - Reference to the wrapping object.
  */
  CReference(T_Type& a_rValue);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReference class.
  */
  template <typename T_OtherType>
  CReference(const CReference<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CReference();

  //! Operator: Equal to reference value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReference class.
      \param a_crValue - Constant reference.
      \return true  - if reference wrapper class is equal to reference. \n
              false - if reference wrapper class is not equal to reference. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CReference<T_OtherType>& a_crInstance, const T_OtherType& a_crValue);
  //! Operator: Equal to another CReference class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReference class.
      \param a_crInstance2 - Constant reference to another instance of the CReference class.
      \return true  - if CReference class instance is equal to another one. \n
              false - if CReference class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CReference<T_OtherType>& a_crInstance1, const CReference<T_OtherOtherType>& a_crInstance2);
  //! Operator: Equal to reference type.
  /*!
      \param a_crValue - Constant reference.
      \param a_crInstance - Constant reference to the current instance of the CReference class.
      \return true  - if reference is equal to reference wrapper class. \n
              false - if reference is not equal to reference wrapper class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const T_OtherType& a_crValue, const CReference<T_OtherType>& a_crInstance);

  //! Operator: Not equal to reference value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReference class.
      \param a_crValue - Constant reference.
      \return true  - if reference wrapper class is not equal to reference. \n
              false - if reference wrapper class is equal to reference. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CReference<T_OtherType>& a_crInstance, const T_OtherType& a_crValue);
  //! Operator: Not equal to another CReference class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReference class.
      \param a_crInstance2 - Constant reference to another instance of the CReference class.
      \return true  - if CReference class instance is not equal to another one. \n
              false - if CReference class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CReference<T_OtherType>& a_crInstance1, const CReference<T_OtherOtherType>& a_crInstance2);
  //! Operator: Not equal to reference type.
  /*!
      \param a_crValue - Constant reference.
      \param a_crInstance - Constant reference to the current instance of the CReference class.
      \return true  - if reference is not equal to reference wrapper class. \n
              false - if reference is equal to reference wrapper class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const T_OtherType& a_crValue, const CReference<T_OtherType>& a_crInstance);

  //! Operator: Assign reference.
  /*!
      \param a_rValue - Reference to the wrapping object.
      \return Reference to the current class instance.
  */
  CReference<T_Type>& operator = (T_Type& a_rValue);
  //! Operator: Assign another CReference class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReference class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CReference<T_Type>& operator = (const CReference<T_OtherType>& a_crInstance);

  //! Operator: Get non constant reference to the wrapping object.
  /*!
      \return Non constant reference to the wrapping object.
  */
  operator T_Type& ();
  //! Operator: Get constant reference to the wrapping object.
  /*!
      \return Constant reference to the wrapping object.
  */
  operator const T_Type& () const;

  //! Set reference.
  /*!
      \param a_rValue - Reference to the wrapping object.
  */
  void set(T_Type& a_rValue);
  //! Set another CReference class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReference class.
  */
  template <typename T_OtherType>
  void set(const CReference<T_OtherType>& a_crInstance);

  //! Is current reference valid?
  /*!
      \return true  - if current reference value is valid. \n
              false - if current reference value is not valid. \n
  */
  Tbool isValid() const;

  //! Get non constant reference to the wrapping object.
  /*!
      \return Non constant reference to the wrapping object.
  */
  T_Type& getValueRef();
  //! Get constant reference to the wrapping object.
  /*!
      \return Constant reference to the wrapping object.
  */
  const T_Type& getValueRef() const;

  //! Set current reference value to NULL.
  void clear();

  //! Serialize CReference class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CReference class instances.
  /*!
      \param a_rInstance - Reference to another CReference class instance.
  */
  void swap(CReference<T_Type>& a_rInstance);

private:
  T_Type* m_pValue;                     //!< Pointer to the wrapping reference.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CReference.inl>
/*==========================================================================*/
//! \example example-base-CReference.cpp
/*--------------------------------------------------------------------------*/
//! \test test-test-CReference.cpp
/*==========================================================================*/
#endif
