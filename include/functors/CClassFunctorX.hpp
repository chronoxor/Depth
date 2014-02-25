/*!
 *  \file    CClassFunctorX.hpp Class functor class emulates an object that
 *           can be called as a class method with 'operator()'.
 *  \brief   Class functor class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class functor class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors
    VERSION:   1.0
    CREATED:   10.05.2006 03:04:31

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
#ifndef __CCLASSFUNCTORX_HPP__
#define __CCLASSFUNCTORX_HPP__
/*==========================================================================*/
#include <Depth/include/functors/CClassFunctor0.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Class functor class.
/*!
    Class functor is an object,  that  emulates  class  method  call.  It  has
    'operator()' so you can use  this  objects  in  various  algorithm.  Class
    functor object can be initialized with a  class  method  or  with  another
    functor.

    Note that before using functor it must be initialized. To check initialize
    state  you  can  use  'CClassFunctor::isValid()'  method.   If   you   use
    uninitialized functor it leads to the error.
*/
template <typename T_Method>
class CClassFunctor :
  public NDetails::CClassFunctorHelper<T_Method>
{
  //! Type for MConceptAnyMethod constraint checking.
  typedef T_Method TAnyMethodCheckType;
  //! Type for MConceptSwappable constraint checking.
  typedef CClassFunctor<T_Method> TSwappableCheckType;

  // Check T_Method class constraint to be an any class method declaration.
  REQUIRES_CONCEPT1(NConcept::NFunctions, MConceptAnyMethod, TAnyMethodCheckType);
  // Check CClassFunctor class constraint to be a swappable class.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

public:
  //! Empty functor.
  using NDetails::CClassFunctorHelper<T_Method>::e_EMPTY;
  //! Functor initialized with the class method.
  using NDetails::CClassFunctorHelper<T_Method>::e_METHOD;
  //! Functor initialized with the class constant method.
  using NDetails::CClassFunctorHelper<T_Method>::e_METHOD_CONST;
  //! Functor initialized with the class volatile method.
  using NDetails::CClassFunctorHelper<T_Method>::e_METHOD_VOLATILE;
  //! Functor initialized with the class constant volatile method.
  using NDetails::CClassFunctorHelper<T_Method>::e_METHOD_CONST_VOLATILE;

  //! Type of the functor.
  typedef typename NDetails::CClassFunctorHelper<T_Method>::EFunctorType EFunctorType;
  //! Functor class method type.
  typedef typename NDetails::CClassFunctorHelper<T_Method>::TMethod TMethod;

  //! Default class constructor.
  CClassFunctor();
  //! Class constructor with setting functor class method.
  /*!
      Initialize current functor with suitable pointer to class method.  After
      this initializing you can safely call 'operator()'.

      \param a_fMethod - Pointer to the class method.
  */
  CClassFunctor(TMethod a_fMethod);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CClassFunctor class.
  */
  CClassFunctor(const CClassFunctor<T_Method>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CClassFunctor();

  //! Operator: Equal to another CClassFunctor class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CClassFunctor class.
      \param a_crInstance2 - Constant reference to another instance of the CClassFunctor class.
      \return true  - if CClassFunctor class instance is equal to another one. \n
              false - if CClassFunctor class instance is not equal to another one. \n
  */
  template <typename T_OtherClassRoutine>
  friend Tbool operator == (const CClassFunctor<T_OtherClassRoutine>& a_crInstance1, const CClassFunctor<T_OtherClassRoutine>& a_crInstance2);
  //! Operator: Not equal to another CClassFunctor class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CClassFunctor class.
      \param a_crInstance2 - Constant reference to another instance of the CClassFunctor class.
      \return true  - if CClassFunctor class instance is not equal to another one. \n
              false - if CClassFunctor class instance is equal to another one. \n
  */
  template <typename T_OtherClassRoutine>
  friend Tbool operator != (const CClassFunctor<T_OtherClassRoutine>& a_crInstance1, const CClassFunctor<T_OtherClassRoutine>& a_crInstance2);

  //! Operator: Assign with class method.
  /*!
      \param a_fMethod - Pointer to the class method.
      \return Reference to the current class instance.
  */
  CClassFunctor<T_Method>& operator = (TMethod a_fMethod);
  //! Operator: Assign another CClassFunctor class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CClassFunctor class.
      \return Reference to the current class instance.
  */
  CClassFunctor<T_Method>& operator = (const CClassFunctor<T_Method>& a_crInstance);

  //! Set functor class method.
  /*!
      \param a_fMethod - Pointer to the class method.
      \return true  - if functor was successfully initialized with class method. \n
              false - if functor was not successfully initialized with class method. \n
  */
  Tbool set(TMethod a_fMethod);
  //! Set another CClassFunctor class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CClassFunctor class.
      \return true  - if functor was successfully initialized with another functor. \n
              false - if functor was not successfully initialized with another functor. \n
  */
  Tbool set(const CClassFunctor<T_Method>& a_crInstance);

  //! Get type of the current functor.
  /*!
      \return Type of the current functor.
  */
  EFunctorType getType() const;

  //! Clean current functor instance.
  /*!
      \return true  - if functor was successfully cleaned. \n
              false - if functor was not successfully cleaned. \n
  */
  Tbool clean();

  //! Swap two CClassFunctor class instances.
  /*!
      \param a_rInstance - Reference to another CClassFunctor class instance.
  */
  void swap(CClassFunctor<T_Method>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/CClassFunctorX.inl>
/*==========================================================================*/
#endif
