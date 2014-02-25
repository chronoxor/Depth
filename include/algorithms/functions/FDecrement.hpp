/*!
 *  \file    FDecrement.hpp Decrement function class is used as decremental
 *           generator functor.
 *  \brief   Decrement function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Decrement function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   21.05.2007 21:12:26

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
#ifndef __FDECREMENT_HPP__
#define __FDECREMENT_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/operators/MConceptUnaryPostfixDec.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Decrement function class.
/*!
    This  class  implements  function  object  which  is  provide  decremental
    generator functionality.
*/
template <typename T_Type>
class FDecrement
{
  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptUnaryPostfixDec constraint checking.
  typedef T_Type TUnaryPostfixDecCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FDecrement<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Type template argument constraint to support an unary postfix decrement operator.
  REQUIRES_CONCEPT1(NConcept::NOperators, MConceptUnaryPostfixDec, TUnaryPostfixDecCheckType);
  // Check FDecrement class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef T_Type TReturn;

  //! Default class constructor.
  FDecrement();
  //! Initialize decremental generator with the given value.
  /*!
      \param a_crInitialValue - Constant reference to the initial value.
  */
  FDecrement(const T_Type& a_crInitialValue);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the FDecrement class.
  */
  template <typename T_OtherType>
  FDecrement(const FDecrement<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~FDecrement();

  //! Operator: Assign another FDecrement class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the FDecrement class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  FDecrement<T_Type>& operator = (const FDecrement<T_OtherType>& a_crInstance);

  //! Set decremental generator value.
  /*!
      \param a_crInitialValue - Constant reference to the initial value.
  */
  void set(const T_Type& a_crInitialValue);
  //! Set another FDecrement class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the FDecrement class.
  */
  template <typename T_OtherType>
  void set(const FDecrement<T_OtherType>& a_crInstance);

  //! Operator: Call function - return current value then decrement it.
  /*!
      \return Current value.
  */
  T_Type operator () () const;

  //! Serialize FDecrement class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FDecrement class instances.
  /*!
      \param a_rInstance - Reference to another FDecrement class instance.
  */
  void swap(FDecrement<T_Type>& a_rInstance);

private:
  mutable T_Type m_Value;               //!< Current decremental generator value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FDecrement.inl>
/*==========================================================================*/
#endif
