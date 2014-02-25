/*!
 *  \file    CReal.hpp Real number template class wraps operations with
 *           real numbers and also gives methods for getting their limits
 *           values.
 *  \brief   Real number template wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Real number template wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   28.01.2006 23:01:52

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
#ifndef __CREAL_HPP__
#define __CREAL_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/AAbsolute.hpp>
#include <Depth/include/concept/base/MConceptReal.hpp>
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
//! Real number template wrapper class.
/*!
    Real number template wrapper emulates basic operations with  real  numbers
    and has special methods which returns corresponding limits values.
*/
template <typename T_Type>
class CReal
{
  //! Type for the MConceptReal constraint checking.
  typedef T_Type TRealCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CReal<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a real number type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptReal, TRealCheckType);
  // Check CReal class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Real value template type.
  typedef T_Type TType;

  //! Default class constructor.
  /*!
      \param a_cValue - Real number value (default is 0.0).
  */
  CReal(const T_Type a_cValue = (T_Type)0.0);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReal class.
  */
  template <typename T_OtherType>
  CReal(const CReal<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CReal();

  //! Operator: Equal to real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if real number class is equal to real value. \n
              false - if real number class is not equal to real value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Equal to another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if CReal class instance is equal to another one. \n
              false - if CReal class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Equal to real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if real value is equal to real number class. \n
              false - if real value is not equal to real number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);

  //! Operator: Not equal to real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if real number class is not equal to real value. \n
              false - if real number class is equal to real value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Not equal to another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if CReal class instance is not equal to another one. \n
              false - if CReal class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Not equal to real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if real value is not equal to real number class. \n
              false - if real value is equal to real number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);

  //! Operator: Less than real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if real number class is less than real value. \n
              false - if real number class is not less than real value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Less than another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if CReal class instance is less than another one. \n
              false - if CReal class instance is not less than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator < (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Less than real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if real value is less than real number class. \n
              false - if real value is not less than real number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);
  //! Operator: More than real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if real number class is more than real value. \n
              false - if real number class is not more than real value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: More than another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if CReal class instance is more than another one. \n
              false - if CReal class instance is not more than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator > (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: More than real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if real value is more than real number class. \n
              false - if real value is not more than real number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);
  //! Operator: Less or equal than real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if real number class is less or equal than real value. \n
              false - if real number class is not less or equal than real value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Less or equal than another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if CReal class instance is less or equal than another one. \n
              false - if CReal class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator <= (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Less or equal than real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if real value is less or equal than real number class. \n
              false - if real value is not less or equal than real number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);
  //! Operator: More or equal than real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if real number class is more or equal than real value. \n
              false - if real number class is not more or equal than real value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: More or equal than another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if CReal class instance is more or equal than another one. \n
              false - if CReal class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator >= (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: More or equal than real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if real value is more or equal than real number class. \n
              false - if real value is not more or equal than real number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);

  //! Operator: Logic AND with real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator && (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Logic AND with another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator && (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Logic AND with real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator && (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);
  //! Operator: Logic OR with real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator || (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Logic OR with another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator || (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Logic OR with real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator || (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);

  //! Operator: Unary plus.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return New instance of CReal class with applied plus operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator + (const CReal<T_OtherType>& a_crInstance);
  //! Operator: Unary minus.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return New instance of CReal class with applied minus operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator - (const CReal<T_OtherType>& a_crInstance);
  //! Operator: Unary not.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return New instance of CReal class with applied not operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator ! (const CReal<T_OtherType>& a_crInstance);

  //! Operator: Add real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return New instance of CReal class with applied add operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator + (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Add another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return New instance of CReal class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CReal<T_OtherType> operator + (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Add real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return New instance of CReal class with applied add operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator + (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);
  //! Operator: Sub real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return New instance of CReal class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator - (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Sub another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return New instance of CReal class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CReal<T_OtherType> operator - (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Sub real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return New instance of CReal class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator - (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);
  //! Operator: Mul real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return New instance of CReal class with applied mul operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator * (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Mul another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return New instance of CReal class with applied mul operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CReal<T_OtherType> operator * (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Mul real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return New instance of CReal class with applied mul operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator * (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);
  //! Operator: Div real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \param a_cValue - Real number value.
      \return New instance of CReal class with applied div operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator / (const CReal<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Div another CReal class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CReal class.
      \param a_crInstance2 - Constant reference to another instance of the CReal class.
      \return New instance of CReal class with applied div operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CReal<T_OtherType> operator / (const CReal<T_OtherType>& a_crInstance1, const CReal<T_OtherOtherType>& a_crInstance2);
  //! Operator: Div real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CReal class.
      \return New instance of CReal class with applied div operator.
  */
  template <typename T_OtherType>
  friend CReal<T_OtherType> operator / (const T_OtherType a_cValue, const CReal<T_OtherType>& a_crInstance);

  //! Operator: Assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CReal<T_Type>& operator = (const T_Type a_cValue);
  //! Operator: Assign another CReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReal class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CReal<T_Type>& operator = (const CReal<T_OtherType>& a_crInstance);

  //! Operator: Add and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CReal<T_Type>& operator += (const T_Type a_cValue);
  //! Operator: Add and assign another CReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReal class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CReal<T_Type>& operator += (const CReal<T_OtherType>& a_crInstance);
  //! Operator: Sub and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CReal<T_Type>& operator -= (const T_Type a_cValue);
  //! Operator: Sub and assign another CReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReal class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CReal<T_Type>& operator -= (const CReal<T_OtherType>& a_crInstance);
  //! Operator: Mul and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CReal<T_Type>& operator *= (const T_Type a_cValue);
  //! Operator: Mul and assign another CReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReal class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CReal<T_Type>& operator *= (const CReal<T_OtherType>& a_crInstance);
  //! Operator: Div and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CReal<T_Type>& operator /= (const T_Type a_cValue);
  //! Operator: Div and assign another CReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReal class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CReal<T_Type>& operator /= (const CReal<T_OtherType>& a_crInstance);

  //! Operator: Increment real value. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CReal<T_Type>& operator ++ ();
  //! Operator: Increment real value. Postfix version.
  /*!
      \return New instance of CReal class with applied increment operator.
  */
  CReal<T_Type> operator ++ (int);

  //! Operator: Decrement real value. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CReal<T_Type>& operator -- ();
  //! Operator: Decrement real value. Postfix version.
  /*!
      \return New instance of CReal class with applied increment operator.
  */
  CReal<T_Type> operator -- (int);

  //! Operator: Get reference to the current real value.
  /*!
      \return Reference to the current real value.
  */
  operator T_Type& ();
  //! Operator: Get constant reference to the current real value.
  /*!
      \return Constant reference to the current real value.
  */
  operator const T_Type& () const;

  //! Operator: Get pointer to the current real value.
  /*!
      \return Pointer to the current real value.
  */
  operator T_Type* ();
  //! Operator: Get constant pointer to the current real value.
  /*!
      \return Constant pointer to the current real value.
  */
  operator const T_Type* () const;

  //! Set real value.
  /*!
      \param a_cValue - Real number value.
  */
  void set(const T_Type a_cValue);
  //! Set another CReal class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReal class.
  */
  template <typename T_OtherType>
  void set(const CReal<T_OtherType>& a_crInstance);

  //! Get real value.
  /*!
      \return Real number value.
  */
  T_Type getValue() const;

  //! Set current real number value to zero.
  void clear();
  //! Set current real number value to it absolute value.
  void absolute();
  //! Negative current real number value.
  void negate();

  //! Get size of one real value in bits.
  /*!
      \return Size of one real value in bits.
  */
  static Tsint getBitSize();
  //! Get size of one real value in bytes.
  /*!
      \return Size of one real value in bytes.
  */
  static Tsint getByteSize();

  //! Get minimal possible real value.
  /*!
      \return Minimal possible real number value.
  */
  static T_Type getMin();
  //! Get maximal possible real value.
  /*!
      \return Maximal possible real number value.
  */
  static T_Type getMax();
  //! Get smallest X such that (1.0 + X != 1.0).
  /*!
      \return Smallest X real number.
  */
  static T_Type getEpsilon();
  //! Get compare smallest X such that (1.0 + X != 1.0).
  /*!
      \return Compare smallest X real number.
  */
  static T_Type getCompareEpsilon();

  //! Get decimal digits of precision.
  /*!
      \return Decimal digits of precision.
  */
  static Tsint getPrecDigits();
  //! Get number bits in mantissa.
  /*!
      \return Count of bits in mantissa.
  */
  static Tsint getMantDigits();
  //! Get minimal binary exponent.
  /*!
      \return Minimal binary exponent.
  */
  static Tsint getMinExp();
  //! Get maximal binary exponent.
  /*!
      \return Maximal binary exponent.
  */
  static Tsint getMaxExp();
  //! Get minimal decimal exponent.
  /*!
      \return Minimal decimal exponent.
  */
  static Tsint getMin10Exp();
  //! Get maximal decimal exponent.
  /*!
      \return Maximal decimal exponent.
  */
  static Tsint getMax10Exp();

  //! Serialize CReal class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CReal class instances.
  /*!
      \param a_rInstance - Reference to another CReal class instance.
  */
  void swap(CReal<T_Type>& a_rInstance);

private:
  T_Type m_Value;                       //!< Real number.
};
/*==========================================================================*/
/* TYPE DECLARATIONS                                                        */
/*==========================================================================*/
//! Wrapper for real values.
typedef CReal<Treal> CRealNumber;
//! Wrapper for float real values.
typedef CReal<Tfloat> CFloat;
//! Wrapper for double real values.
typedef CReal<Tdouble> CDouble;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CReal.inl>
/*==========================================================================*/
//! \example example-base-CReal.cpp
/*--------------------------------------------------------------------------*/
//! \test test-base-CReal.cpp
/*==========================================================================*/
#endif
