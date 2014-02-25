/*!
 *  \file    CBoolean.hpp Boolean value template class wraps operations with
 *           boolean values.
 *  \brief   Boolean values template wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Boolean value template wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   31.01.2006 02:49:35

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
#ifndef __CBOOLEAN_HPP__
#define __CBOOLEAN_HPP__
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptBool.hpp>
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
//! Boolean value template wrapper class.
/*!
    Boolean value template wrapper  emulates  basic  operations  with  boolean
    values.
*/
template <typename T_Type>
class CBoolean
{
  //! Type for the MConceptBool constraint checking.
  typedef T_Type TBoolCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CBoolean<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a boolean type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptBool, TBoolCheckType);
  // Check CBoolean class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Boolean value template type.
  typedef T_Type TType;

  //! Default class constructor.
  /*!
      \param a_cValue - Boolean value (default is false).
  */
  CBoolean(const T_Type a_cValue = (T_Type)false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoolean class.
  */
  template <typename T_OtherType>
  CBoolean(const CBoolean<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CBoolean();

  //! Operator: Equal to boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \param a_cValue - Boolean value.
      \return true  - if boolean value class is equal to boolean value. \n
              false - if boolean value class is not equal to boolean value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CBoolean<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Equal to another CBoolean class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBoolean class.
      \param a_crInstance2 - Constant reference to another instance of the CBoolean class.
      \return true  - if CBoolean class instance is equal to another one. \n
              false - if CBoolean class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CBoolean<T_OtherType>& a_crInstance1, const CBoolean<T_OtherOtherType>& a_crInstance2);
  //! Operator: Equal to boolean value.
  /*!
      \param a_cValue - Boolean value.
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return true  - if boolean value is equal to boolean value class. \n
              false - if boolean value is not equal to boolean value class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const T_OtherType a_cValue, const CBoolean<T_OtherType>& a_crInstance);

  //! Operator: Not equal to boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \param a_cValue - Boolean value.
      \return true  - if boolean value class is not equal to boolean value. \n
              false - if boolean value class is equal to boolean value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CBoolean<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Not equal to another CBoolean class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBoolean class.
      \param a_crInstance2 - Constant reference to another instance of the CBoolean class.
      \return true  - if CBoolean class instance is not equal to another one. \n
              false - if CBoolean class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CBoolean<T_OtherType>& a_crInstance1, const CBoolean<T_OtherOtherType>& a_crInstance2);
  //! Operator: Not equal to boolean value.
  /*!
      \param a_cValue - Boolean value.
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return true  - if boolean value is not equal to boolean value class. \n
              false - if boolean value is equal to boolean value class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const T_OtherType a_cValue, const CBoolean<T_OtherType>& a_crInstance);

  //! Operator: Logic AND with boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \param a_cValue - Boolean value.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator && (const CBoolean<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Logic AND with another CBoolean class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBoolean class.
      \param a_crInstance2 - Constant reference to another instance of the CBoolean class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator && (const CBoolean<T_OtherType>& a_crInstance1, const CBoolean<T_OtherOtherType>& a_crInstance2);
  //! Operator: Logic AND with boolean value.
  /*!
      \param a_cValue - Boolean value.
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator && (const T_OtherType a_cValue, const CBoolean<T_OtherType>& a_crInstance);
  //! Operator: Logic OR with boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \param a_cValue - Boolean value.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator || (const CBoolean<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Logic OR with another CBoolean class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBoolean class.
      \param a_crInstance2 - Constant reference to another instance of the CBoolean class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator || (const CBoolean<T_OtherType>& a_crInstance1, const CBoolean<T_OtherOtherType>& a_crInstance2);
  //! Operator: Logic OR with boolean value.
  /*!
      \param a_cValue - Boolean value.
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator || (const T_OtherType a_cValue, const CBoolean<T_OtherType>& a_crInstance);

  //! Operator: Unary not.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return New instance of CBoolean class with applied not operator.
  */
  template <typename T_OtherType>
  friend CBoolean<T_OtherType> operator ! (const CBoolean<T_OtherType>& a_crInstance);

  //! Operator: AND boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \param a_cValue - Boolean value.
      \return New instance of CBoolean class with applied AND operator.
  */
  template <typename T_OtherType>
  friend CBoolean<T_OtherType> operator & (const CBoolean<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: AND another CBoolean class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBoolean class.
      \param a_crInstance2 - Constant reference to another instance of the CBoolean class.
      \return New instance of CBoolean class with applied AND operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBoolean<T_OtherType> operator & (const CBoolean<T_OtherType>& a_crInstance1, const CBoolean<T_OtherOtherType>& a_crInstance2);
  //! Operator: AND boolean value.
  /*!
      \param a_cValue - Boolean value.
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return New instance of CBoolean class with applied AND operator.
  */
  template <typename T_OtherType>
  friend CBoolean<T_OtherType> operator & (const T_OtherType a_cValue, const CBoolean<T_OtherType>& a_crInstance);
  //! Operator: OR boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \param a_cValue - Boolean value.
      \return New instance of CBoolean class with applied OR operator.
  */
  template <typename T_OtherType>
  friend CBoolean<T_OtherType> operator | (const CBoolean<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: OR another CBoolean class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBoolean class.
      \param a_crInstance2 - Constant reference to another instance of the CBoolean class.
      \return New instance of CBoolean class with applied OR operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBoolean<T_OtherType> operator | (const CBoolean<T_OtherType>& a_crInstance1, const CBoolean<T_OtherOtherType>& a_crInstance2);
  //! Operator: OR boolean value.
  /*!
      \param a_cValue - Boolean value.
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return New instance of CBoolean class with applied OR operator.
  */
  template <typename T_OtherType>
  friend CBoolean<T_OtherType> operator | (const T_OtherType a_cValue, const CBoolean<T_OtherType>& a_crInstance);
  //! Operator: XOR boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \param a_cValue - Boolean value.
      \return New instance of CBoolean class with applied XOR operator.
  */
  template <typename T_OtherType>
  friend CBoolean<T_OtherType> operator ^ (const CBoolean<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: XOR another CBoolean class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBoolean class.
      \param a_crInstance2 - Constant reference to another instance of the CBoolean class.
      \return New instance of CBoolean class with applied XOR operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBoolean<T_OtherType> operator ^ (const CBoolean<T_OtherType>& a_crInstance1, const CBoolean<T_OtherOtherType>& a_crInstance2);
  //! Operator: XOR boolean value.
  /*!
      \param a_cValue - Boolean value.
      \param a_crInstance - Constant reference to the current instance of the CBoolean class.
      \return New instance of CBoolean class with applied XOR operator.
  */
  template <typename T_OtherType>
  friend CBoolean<T_OtherType> operator ^ (const T_OtherType a_cValue, const CBoolean<T_OtherType>& a_crInstance);

  //! Operator: Assign boolean value.
  /*!
      \param a_cValue - Boolean value.
      \return Reference to the current class instance.
  */
  CBoolean<T_Type>& operator = (const T_Type a_cValue);
  //! Operator: Assign another CBoolean class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoolean class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CBoolean<T_Type>& operator = (const CBoolean<T_OtherType>& a_crInstance);

  //! Operator: AND and assign boolean value.
  /*!
      \param a_cValue - Boolean value.
      \return Reference to the current class instance.
  */
  CBoolean<T_Type>& operator &= (const T_Type a_cValue);
  //! Operator: AND and assign another CBoolean class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoolean class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CBoolean<T_Type>& operator &= (const CBoolean<T_OtherType>& a_crInstance);
  //! Operator: OR and assign boolean value.
  /*!
      \param a_cValue - Boolean value.
      \return Reference to the current class instance.
  */
  CBoolean<T_Type>& operator |= (const T_Type a_cValue);
  //! Operator: OR and assign another CBoolean class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoolean class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CBoolean<T_Type>& operator |= (const CBoolean<T_OtherType>& a_crInstance);
  //! Operator: XOR and assign boolean value.
  /*!
      \param a_cValue - Boolean value.
      \return Reference to the current class instance.
  */
  CBoolean<T_Type>& operator ^= (const T_Type a_cValue);
  //! Operator: XOR and assign another CBoolean class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoolean class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CBoolean<T_Type>& operator ^= (const CBoolean<T_OtherType>& a_crInstance);

  //! Operator: Get reference to the current boolean value.
  /*!
      \return Reference to the current boolean value.
  */
  operator T_Type& ();
  //! Operator: Get constant reference to the current boolean value.
  /*!
      \return Constant reference to the current boolean value.
  */
  operator const T_Type& () const;

  //! Operator: Get pointer to the current boolean value.
  /*!
      \return Pointer to the current boolean value.
  */
  operator T_Type* ();
  //! Operator: Get constant pointer to the current boolean value.
  /*!
      \return Constant pointer to the current boolean value.
  */
  operator const T_Type* () const;

  //! Operator: Get current boolean value.
  /*!
      \return true  - if current boolean value is 'true'. \n
              false - if current boolean value is 'false'. \n
  */
  operator Tbool () const;
  //! Operator: Get current boolean inverse value.
  /*!
      \return true  - if current boolean value is 'false'. \n
              false - if current boolean value is 'true'. \n
  */
  Tbool operator ! () const;

  //! Set boolean value.
  /*!
      \param a_cValue - Boolean value.
  */
  void set(const T_Type a_cValue);
  //! Set another CBoolean class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoolean class.
  */
  template <typename T_OtherType>
  void set(const CBoolean<T_OtherType>& a_crInstance);

  //! Get boolean value.
  /*!
      \return Boolean value.
  */
  T_Type getValue() const;

  //! Is current boolean value 'true'?
  /*!
      \return true  - if current boolean value is 'true'. \n
              false - if current boolean value is 'false'. \n
  */
  Tbool isTrue() const;
  //! Is current boolean value 'false'?
  /*!
      \return true  - if current boolean value is 'false'. \n
              false - if current boolean value is 'true'. \n
  */
  Tbool isFalse() const;

  //! Set current boolean value to 'true'.
  void setTrue();
  //! Set current boolean value to 'false'.
  void setFalse();

  //! Flip current boolean value to opposite.
  void flip();

  //! Get 'true' constant value.
  /*!
      \return 'true' constant value.
  */
  static T_Type getTrue();
  //! Get 'false' constant value.
  /*!
      \return 'false' constant value.
  */
  static T_Type getFalse();

  //! Serialize CBoolean class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBoolean class instances.
  /*!
      \param a_rInstance - Reference to another CBoolean class instance.
  */
  void swap(CBoolean<T_Type>& a_rInstance);

private:
  T_Type m_Value;                       //!< Boolean value.
};
/*==========================================================================*/
/* TYPE DECLARATIONS                                                        */
/*==========================================================================*/
//! Wrapper for build in boolean values.
typedef CBoolean<Tbool> CBool;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CBoolean.inl>
/*==========================================================================*/
//! \example example-base-CBoolean.cpp
/*--------------------------------------------------------------------------*/
//! \test test-base-CBoolean.cpp
/*==========================================================================*/
#endif
