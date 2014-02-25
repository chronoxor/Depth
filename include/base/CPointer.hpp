/*!
 *  \file    CPointer.hpp Pointer template class emulates pointers thorough
 *           the class wrapper.
 *  \brief   Pointer template wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pointer template wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   10.10.2006 00:21:33

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
#ifndef __CPOINTER_HPP__
#define __CPOINTER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IPtr.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Pointer template wrapper class.
/*!
    Pointer template wrapper emulates basic operations with  pointers  through
    the class wrapper.
*/
template <typename T_Type>
class CPointer :
  public NCommon::IPtr<T_Type>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CPointer<T_Type> TDepthCheckType;

  // Check CPointer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! CPointer value type.
  typedef typename NCommon::IPtr<T_Type>::TType TType;
  //! CPointer constant reference type.
  typedef typename NCommon::IPtr<T_Type>::TConstReference TConstReference;
  //! CPointer reference type.
  typedef typename NCommon::IPtr<T_Type>::TReference TReference;
  //! CPointer pointer type.
  typedef typename NCommon::IPtr<T_Type>::TPointer TPointer;

  //! Default class constructor.
  /*!
      \param a_pValue - Pointer to the wrapping object (default is NULL).
  */
  CPointer(T_Type* a_pValue = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CPointer class.
  */
  template <typename T_OtherType>
  CPointer(const CPointer<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CPointer();

  //! Operator: Add signed integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \param a_cValue - Signed integer number value.
      \return New instance of CPointer class with applied add operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator + (const CPointer<T_OtherType>& a_crInstance, const Tsint a_cValue);
  //! Operator: Add unsigned integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \param a_cValue - Unsigned integer number value.
      \return New instance of CPointer class with applied add operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator + (const CPointer<T_OtherType>& a_crInstance, const Tuint a_cValue);
  //! Operator: Add pointer.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \param a_cpValue - Constant pointer.
      \return New instance of CPointer class with applied add operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator + (const CPointer<T_OtherType>& a_crInstance, const T_OtherType* a_cpValue);
  //! Operator: Add another CPointer class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPointer class.
      \param a_crInstance2 - Constant reference to another instance of the CPointer class.
      \return New instance of CPointer class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPointer<T_OtherType> operator + (const CPointer<T_OtherType>& a_crInstance1, const CPointer<T_OtherOtherType>& a_crInstance2);
  //! Operator: Add signed integer number.
  /*!
      \param a_cValue - Signed integer number value.
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \return New instance of CPointer class with applied add operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator + (const Tsint a_cValue, const CPointer<T_OtherType>& a_crInstance);
  //! Operator: Add unsigned integer number.
  /*!
      \param a_cValue - Unsigned integer number value.
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \return New instance of CPointer class with applied add operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator + (const Tuint a_cValue, const CPointer<T_OtherType>& a_crInstance);
  //! Operator: Add pointer.
  /*!
      \param a_cpValue - Constant pointer.
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \return New instance of CPointer class with applied add operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator + (const T_OtherType* a_cpValue, const CPointer<T_OtherType>& a_crInstance);

  //! Operator: Sub signed integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \param a_cValue - Signed integer number value.
      \return New instance of CPointer class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator - (const CPointer<T_OtherType>& a_crInstance, const Tsint a_cValue);
  //! Operator: Sub unsigned integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \param a_cValue - Unsigned integer number value.
      \return New instance of CPointer class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator - (const CPointer<T_OtherType>& a_crInstance, const Tuint a_cValue);
  //! Operator: Sub pointer.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \param a_cpValue - Constant pointer.
      \return New instance of CPointer class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator - (const CPointer<T_OtherType>& a_crInstance, const T_OtherType* a_cpValue);
  //! Operator: Sub another CPointer class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPointer class.
      \param a_crInstance2 - Constant reference to another instance of the CPointer class.
      \return New instance of CPointer class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPointer<T_OtherType> operator - (const CPointer<T_OtherType>& a_crInstance1, const CPointer<T_OtherOtherType>& a_crInstance2);
  //! Operator: Sub signed integer number.
  /*!
      \param a_cValue - Signed integer number value.
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \return New instance of CPointer class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator - (const Tsint a_cValue, const CPointer<T_OtherType>& a_crInstance);
  //! Operator: Sub unsigned integer number.
  /*!
      \param a_cValue - Unsigned integer number value.
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \return New instance of CPointer class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator - (const Tuint a_cValue, const CPointer<T_OtherType>& a_crInstance);
  //! Operator: Sub pointer.
  /*!
      \param a_cpValue - Constant pointer.
      \param a_crInstance - Constant reference to the current instance of the CPointer class.
      \return New instance of CPointer class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CPointer<T_OtherType> operator - (const T_OtherType* a_cpValue, const CPointer<T_OtherType>& a_crInstance);

  //! Operator: Assign pointer.
  /*!
      \param a_pValue - Pointer to the wrapping object.
      \return Pointer to the current class instance.
  */
  CPointer<T_Type>& operator = (T_Type* a_pValue);
  //! Operator: Assign another CPointer class instance.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CPointer class.
      \return Pointer to the current class instance.
  */
  template <typename T_OtherType>
  CPointer<T_Type>& operator = (const CPointer<T_OtherType>& a_crInstance);

  //! Operator: Add and assign signed integer number.
  /*!
      \param a_cValue - Signed integer number value.
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator += (const Tsint a_cValue);
  //! Operator: Add and assign unsigned integer number.
  /*!
      \param a_cValue - Signed uninteger number value.
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator += (const Tuint a_cValue);
  //! Operator: Add and assign another pointer.
  /*!
      \param a_cpValue - Constant pointer.
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator += (const T_Type* a_cpValue);
  //! Operator: Add and assign another CPointer class instance.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CPointer class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CPointer<T_Type>& operator += (const CPointer<T_OtherType>& a_crInstance);
  //! Operator: Sub and assign signed integer number.
  /*!
      \param a_cValue - Signed integer number value.
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator -= (const Tsint a_cValue);
  //! Operator: Sub and assign unsigned integer number.
  /*!
      \param a_cValue - Signed uninteger number value.
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator -= (const Tuint a_cValue);
  //! Operator: Sub and assign another pointer.
  /*!
      \param a_cpValue - Constant pointer.
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator -= (const T_Type* a_cpValue);
  //! Operator: Sub and assign another CPointer class instance.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CPointer class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CPointer<T_Type>& operator -= (const CPointer<T_OtherType>& a_crInstance);

  //! Operator: Increment pointer. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator ++ ();
  //! Operator: Increment pointer. Postfix version.
  /*!
      \return New instance of CPointer class with applied increment operator.
  */
  CPointer<T_Type> operator ++ (int);

  //! Operator: Decrement pointer. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CPointer<T_Type>& operator -- ();
  //! Operator: Decrement pointer. Postfix version.
  /*!
      \return New instance of CPointer class with applied increment operator.
  */
  CPointer<T_Type> operator -- (int);

  //! Operator: Indexing into the non constant pointer's buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to pointer's item under the given index.
  */
  T_Type& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the non constant pointer's buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to pointer's item under the given index.
  */
  T_Type& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the constant pointer's buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to pointer's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the constant pointer's buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to pointer's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex) const;

  //! Set pointer.
  /*!
      \param a_pValue - Pointer to the wrapping object.
  */
  void set(T_Type* a_pValue);
  //! Set another CPointer class instance.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CPointer class.
  */
  template <typename T_OtherType>
  void set(const CPointer<T_OtherType>& a_crInstance);

  //! Set current pointer value to NULL.
  void clear();

  //! Get NULL value of the pointers.
  /*!
      \return NULL value of the pointers.
  */
  static T_Type* getNULL();

  //! Get minimal possible pointer value.
  /*!
      \return Minimal possible pointer value.
  */
  static T_Type* getMin();
  //! Get maximal possible pointer value.
  /*!
      \return Maximal value of the pointers.
  */
  static T_Type* getMax();

  //! Serialize CPointer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPointer class instances.
  /*!
      \param a_rInstance - Reference to another CPointer class instance.
  */
  void swap(CPointer<T_Type>& a_rInstance);
};
/*==========================================================================*/
/* TYPE DECLARATIONS                                                        */
/*==========================================================================*/
//! Wrapper for system pointer.
typedef CPointer<Tbyte> CPtr;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CPointer.inl>
/*==========================================================================*/
//! \example example-base-CPointer.cpp
/*--------------------------------------------------------------------------*/
//! \test test-base-CPointer.cpp
/*==========================================================================*/
#endif
