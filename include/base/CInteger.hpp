/*!
 *  \file    CInteger.hpp Integer number template class wraps operations with
 *           integer numbers and also gives methods for getting their limits
 *           values.
 *  \brief   Integer number template wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Integer number template wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   26.01.2006 23:09:32

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
#ifndef __CINTEGER_HPP__
#define __CINTEGER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/AAbsolute.hpp>
#include <Depth/include/concept/base/MConceptInteger.hpp>
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
//! Integer number template wrapper class.
/*!
    Integer number template wrapper emulates  basic  operations  with  integer
    numbers and has special methods which returns corresponding limits values.
*/
template <typename T_Type>
class CInteger
{
  //! Type for the MConceptInteger constraint checking.
  typedef T_Type TIntegerCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CInteger<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be an integer number type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptInteger, TIntegerCheckType);
  // Check CInteger class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Integer value template type.
  typedef T_Type TType;

  //! Default class constructor.
  /*!
      \param a_cValue - Integer number value (default is 0).
  */
  CInteger(const T_Type a_cValue = (T_Type)0);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
  */
  template <typename T_OtherType>
  CInteger(const CInteger<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CInteger();

  //! Operator: Equal to integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if integer number class is equal to integer value. \n
              false - if integer number class is not equal to integer value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Equal to another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if CInteger class instance is equal to another one. \n
              false - if CInteger class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Equal to integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if integer value is equal to integer number class. \n
              false - if integer value is not equal to integer number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Not equal to integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if integer number class is not equal to integer value. \n
              false - if integer number class is equal to integer value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Not equal to another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if CInteger class instance is not equal to another one. \n
              false - if CInteger class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Not equal to integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if integer value is not equal to integer number class. \n
              false - if integer value is equal to integer number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Less than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if integer number class is less than integer value. \n
              false - if integer number class is not less than integer value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Less than another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if CInteger class instance is less than another one. \n
              false - if CInteger class instance is not less than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator < (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Less than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if integer value is less than integer number class. \n
              false - if integer value is not less than integer number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: More than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if integer number class is more than integer value. \n
              false - if integer number class is not more than integer value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: More than another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if CInteger class instance is more than another one. \n
              false - if CInteger class instance is not more than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator > (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: More than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if integer value is more than integer number class. \n
              false - if integer value is not more than integer number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Less or equal than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if integer number class is less or equal than integer value. \n
              false - if integer number class is not less or equal than integer value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Less or equal than another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if CInteger class instance is less or equal than another one. \n
              false - if CInteger class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator <= (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Less or equal than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if integer value is less or equal than integer number class. \n
              false - if integer value is not less or equal than integer number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: More or equal than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if integer number class is more or equal than integer value. \n
              false - if integer number class is not more or equal than integer value. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: More or equal than another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if CInteger class instance is more or equal than another one. \n
              false - if CInteger class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator >= (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: More or equal than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if integer value is more or equal than integer number class. \n
              false - if integer value is not more or equal than integer number class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Logic AND with integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator && (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Logic AND with another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator && (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Logic AND with integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator && (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Logic OR with integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator || (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Logic OR with another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator || (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Logic OR with integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return true  - if operator returned true. \n
              false - if operator returned false. \n
  */
  template <typename T_OtherType>
  friend Tbool operator || (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Unary plus.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied plus operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator + (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Unary minus.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied minus operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator - (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Unary ones complete.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied ones complete operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator ~ (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Unary not.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied not operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator ! (const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Add integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied add operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator + (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Add another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator + (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Add integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied add operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator + (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Sub integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator - (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Sub another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator - (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Sub integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied sub operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator - (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Mul integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied mul operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator * (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Mul another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied mul operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator * (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Mul integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied mul operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator * (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Div integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied div operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator / (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Div another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied div operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator / (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Div integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied div operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator / (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Mod integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied mod operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator % (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Mod another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied mod operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator % (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Mod integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied mod operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator % (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: AND integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied AND operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator & (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: AND another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied AND operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator & (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: AND integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied AND operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator & (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: OR integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied OR operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator | (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: OR another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied OR operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator | (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: OR integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied OR operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator | (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: XOR integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied XOR operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator ^ (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: XOR another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied XOR operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator ^ (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: XOR integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied XOR operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator ^ (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Left shift integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied left shift operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator << (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Left shift another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied left shift operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator << (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Left shift integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied left shift operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator << (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Right shift integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \param a_cValue - Integer number value.
      \return New instance of CInteger class with applied right shift operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator >> (const CInteger<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Right shift another CInteger class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CInteger class.
      \param a_crInstance2 - Constant reference to another instance of the CInteger class.
      \return New instance of CInteger class with applied right shift operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CInteger<T_OtherType> operator >> (const CInteger<T_OtherType>& a_crInstance1, const CInteger<T_OtherOtherType>& a_crInstance2);
  //! Operator: Right shift integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CInteger class.
      \return New instance of CInteger class with applied right shift operator.
  */
  template <typename T_OtherType>
  friend CInteger<T_OtherType> operator >> (const T_OtherType a_cValue, const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator = (const T_Type a_cValue);
  //! Operator: Assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator = (const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Add and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator += (const T_Type a_cValue);
  //! Operator: Add and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator += (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Sub and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator -= (const T_Type a_cValue);
  //! Operator: Sub and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator -= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Mul and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator *= (const T_Type a_cValue);
  //! Operator: Mul and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator *= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Div and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator /= (const T_Type a_cValue);
  //! Operator: Div and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator /= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Mod and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator %= (const T_Type a_cValue);
  //! Operator: Mod and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator %= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: AND and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator &= (const T_Type a_cValue);
  //! Operator: AND and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator &= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: OR and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator |= (const T_Type a_cValue);
  //! Operator: OR and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator |= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: XOR and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator ^= (const T_Type a_cValue);
  //! Operator: XOR and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator ^= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Left shift and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator <<= (const T_Type a_cValue);
  //! Operator: Left shift and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator <<= (const CInteger<T_OtherType>& a_crInstance);
  //! Operator: Right shift and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator >>= (const T_Type a_cValue);
  //! Operator: Right shift and assign another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CInteger<T_Type>& operator >>= (const CInteger<T_OtherType>& a_crInstance);

  //! Operator: Increment integer value. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator ++ ();
  //! Operator: Increment integer value. Postfix version.
  /*!
      \return New instance of CInteger class with applied increment operator.
  */
  CInteger<T_Type> operator ++ (int);

  //! Operator: Decrement integer value. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CInteger<T_Type>& operator -- ();
  //! Operator: Decrement integer value. Postfix version.
  /*!
      \return New instance of CInteger class with applied increment operator.
  */
  CInteger<T_Type> operator -- (int);

  //! Operator: Get reference to the current integer value.
  /*!
      \return Reference to the current integer value.
  */
  operator T_Type& ();
  //! Operator: Get constant reference to the current integer value.
  /*!
      \return Constant reference to the current integer value.
  */
  operator const T_Type& () const;

  //! Operator: Get pointer to the current integer value.
  /*!
      \return Pointer to the current integer value.
  */
  operator T_Type* ();
  //! Operator: Get constant pointer to the current integer value.
  /*!
      \return Constant pointer to the current integer value.
  */
  operator const T_Type* () const;

  //! Set integer value.
  /*!
      \param a_cValue - Integer number value.
  */
  void set(const T_Type a_cValue);
  //! Set another CInteger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CInteger class.
  */
  template <typename T_OtherType>
  void set(const CInteger<T_OtherType>& a_crInstance);

  //! Get integer value.
  /*!
      \return Integer number value.
  */
  T_Type getValue() const;

  //! Set current integer number value to zero.
  void clear();
  //! Set current integer number value to it absolute value.
  void absolute();
  //! Negative current integer number value.
  void negate();

  //! Get size of one integer value in bits.
  /*!
      \return Size of one integer value in bits.
  */
  static Tsint getBitSize();
  //! Get size of one integer value in bytes.
  /*!
      \return Size of one integer value in bytes.
  */
  static Tsint getByteSize();

  //! Get minimal possible integer value.
  /*!
      \return Minimal possible integer number value.
  */
  static T_Type getMin();
  //! Get maximal possible integer value.
  /*!
      \return Maximal possible integer number value.
  */
  static T_Type getMax();

  //! Serialize CInteger class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CInteger class instances.
  /*!
      \param a_rInstance - Reference to another CInteger class instance.
  */
  void swap(CInteger<T_Type>& a_rInstance);

private:
  T_Type m_Value;                       //!< Integer number.
};
/*==========================================================================*/
/* TYPE DECLARATIONS                                                        */
/*==========================================================================*/
//! Wrapper for byte integer values.
typedef CInteger<Tbyte> CByteInteger;
//! Wrapper for signed integer values.
typedef CInteger<Tsint> CSignedInteger;
//! Wrapper for unsigned integer values.
typedef CInteger<Tuint> CUnsignedInteger;
//! Wrapper for signed 8-bit integer values.
typedef CInteger<Tsint08> CSignedInteger08;
//! Wrapper for signed 16-bit integer values.
typedef CInteger<Tsint16> CSignedInteger16;
//! Wrapper for signed 32-bit integer values.
typedef CInteger<Tsint32> CSignedInteger32;
//! Wrapper for signed 64-bit integer values.
typedef CInteger<Tsint64> CSignedInteger64;
//! Wrapper for unsigned 8-bit integer values.
typedef CInteger<Tuint08> CUnsignedInteger08;
//! Wrapper for unsigned 16-bit integer values.
typedef CInteger<Tuint16> CUnsignedInteger16;
//! Wrapper for unsigned 32-bit integer values.
typedef CInteger<Tuint32> CUnsignedInteger32;
//! Wrapper for unsigned 64-bit integer values.
typedef CInteger<Tuint64> CUnsignedInteger64;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CInteger.inl>
/*==========================================================================*/
//! \example example-base-CInteger.cpp
/*--------------------------------------------------------------------------*/
//! \test test-base-CInteger.cpp
/*==========================================================================*/
#endif
