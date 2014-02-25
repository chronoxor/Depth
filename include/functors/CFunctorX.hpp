/*!
 *  \file    CFunctorX.hpp Functor class emulates an object that can be called
 *           as a function with 'operator()'.
 *  \brief   Functor class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors
    VERSION:   1.0
    CREATED:   04.05.2006 22:03:43

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
#ifndef __CFUNCTORX_HPP__
#define __CFUNCTORX_HPP__
/*==========================================================================*/
#include <Depth/include/functors/CFunctor0.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Functor class.
/*!
    Functor is an object, that emulates function call. It has 'operator()'  so
    you can use this objects in  various  algorithm.  Functor  object  can  be
    initialized with a pointer to function, with class method in  given  class
    instance or with another functor.

    Note that before using functor it must be initialized. To check initialize
    state you can use 'CFunctor::isValid()' method. If you  use  uninitialized
    functor it leads to the error.
*/
template <typename T_Function>
class CFunctor :
  public NDetails::CFunctorHelper<T_Function>
{
  //! Type for MConceptAnyFunction constraint checking.
  typedef T_Function TAnyFunctionCheckType;
  //! Type for MConceptSwappable constraint checking.
  typedef CFunctor<T_Function> TSwappableCheckType;

  // Check T_Function class constraint to be an any function declaration.
  REQUIRES_CONCEPT1(NConcept::NFunctions, MConceptAnyFunction, TAnyFunctionCheckType);
  // Check CFunctor class constraint to be a swappable class.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

public:
  //! Empty functor.
  using NDetails::CFunctorHelper<T_Function>::e_EMPTY;
  //! Functor initialized with the pointer to function.
  using NDetails::CFunctorHelper<T_Function>::e_FUNCTION;
  //! Functor initialized with the class instance and class method.
  using NDetails::CFunctorHelper<T_Function>::e_METHOD;
  //! Functor initialized with the class instance and class constant method.
  using NDetails::CFunctorHelper<T_Function>::e_METHOD_CONST;
  //! Functor initialized with the class instance and class volatile method.
  using NDetails::CFunctorHelper<T_Function>::e_METHOD_VOLATILE;
  //! Functor initialized with the class instance and class constant volatile method.
  using NDetails::CFunctorHelper<T_Function>::e_METHOD_CONST_VOLATILE;
  //! Functor initialized with the connector instance and connector method.
  using NDetails::CFunctorHelper<T_Function>::e_CONNECTOR_METHOD;
  //! Functor initialized with the connector instance and connector constant method.
  using NDetails::CFunctorHelper<T_Function>::e_CONNECTOR_METHOD_CONST;
  //! Functor initialized with the connector instance and connector volatile method.
  using NDetails::CFunctorHelper<T_Function>::e_CONNECTOR_METHOD_VOLATILE;
  //! Functor initialized with the connector instance and connector constant volatile method.
  using NDetails::CFunctorHelper<T_Function>::e_CONNECTOR_METHOD_CONST_VOLATILE;

  //! Type of the functor.
  typedef typename NDetails::CFunctorHelper<T_Function>::EFunctorType EFunctorType;
  //! Functor function type.
  typedef typename NDetails::CFunctorHelper<T_Function>::TFunction TFunction;

  //! Default class constructor.
  CFunctor();
  //! Class constructor with setting functor function.
  /*!
      Initialize current functor with suitable pointer to function. After this
      initializing you can safely call 'operator()'.

      \param a_fFunction - Pointer to function.
  */
  CFunctor(TFunction a_fFunction);
  //! Class constructor with setting functor class instance and use its 'operator()'.
  /*!
      Initialize current functor with reference to the class  instance.  After
      this initializing you can safely call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
  */
  template <class T_Class>
  CFunctor(T_Class& a_rClassInstance);
  //! Class constructor with setting functor constant class instance and use its 'operator()'.
  /*!
      Initialize  current  functor  with  constant  reference  to  the   class
      instance. After this initializing you can safely call 'operator()'.

      \param a_crClassInstance - Constant reference to the class instance.
  */
  template <class T_Class>
  CFunctor(const T_Class& a_crClassInstance);
  //! Class constructor with setting functor volatile class instance and use its 'operator()'.
  /*!
      Initialize  current  functor  with  volatile  reference  to  the   class
      instance. After this initializing you can safely call 'operator()'.

      \param a_vrClassInstance - Volatile reference to the class instance.
  */
  template <class T_Class>
  CFunctor(volatile T_Class& a_vrClassInstance);
  //! Class constructor with setting functor constant volatile class instance and use its 'operator()'.
  /*!
      Initialize current functor with constant volatile reference to the class
      instance. After this initializing you can safely call 'operator()'.

      \param a_cvrClassInstance - Constant volatile reference to the class instance.
  */
  template <class T_Class>
  CFunctor(const volatile T_Class& a_cvrClassInstance);
  //! Class constructor with setting functor class instance and class method.
  /*!
      Initialize current functor with reference  to  the  class  instance  and
      suitable pointer to class method. After this initializing you can safely
      call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class method.
  */
  template <class T_Class, typename T_Method>
  CFunctor(T_Class& a_rClassInstance, T_Method a_fMethod);
  //! Class constructor with setting functor constant class instance and class method.
  /*!
      Initialize current functor with constant reference to the class instance
      and suitable pointer to class method. After this  initializing  you  can
      safely call 'operator()'.

      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class method.
  */
  template <class T_Class, typename T_Method>
  CFunctor(const T_Class& a_crClassInstance, T_Method a_fMethod);
  //! Class constructor with setting functor volatile class instance and class method.
  /*!
      Initialize current functor with volatile reference to the class instance
      and suitable pointer to class method. After this  initializing  you  can
      safely call 'operator()'.

      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class method.
  */
  template <class T_Class, typename T_Method>
  CFunctor(volatile T_Class& a_vrClassInstance, T_Method a_fMethod);
  //! Class constructor with setting functor constant volatile class instance and class method.
  /*!
      Initialize current functor with constant volatile reference to the class
      instance and suitable pointer to class method. After  this  initializing
      you can safely call 'operator()'.

      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \param a_fMethod - Pointer to the class method.
  */
  template <class T_Class, typename T_Method>
  CFunctor(const volatile T_Class& a_cvrClassInstance, T_Method a_fMethod);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFunctor class.
  */
  CFunctor(const CFunctor<T_Function>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFunctor();

  //! Operator: Equal to another CFunctor class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CFunctor class.
      \param a_crInstance2 - Constant reference to another instance of the CFunctor class.
      \return true  - if CFunctor class instance is equal to another one. \n
              false - if CFunctor class instance is not equal to another one. \n
  */
  template <typename T_OtherRoutine>
  friend Tbool operator == (const CFunctor<T_OtherRoutine>& a_crInstance1, const CFunctor<T_OtherRoutine>& a_crInstance2);
  //! Operator: Not equal to another CFunctor class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CFunctor class.
      \param a_crInstance2 - Constant reference to another instance of the CFunctor class.
      \return true  - if CFunctor class instance is not equal to another one. \n
              false - if CFunctor class instance is equal to another one. \n
  */
  template <typename T_OtherRoutine>
  friend Tbool operator != (const CFunctor<T_OtherRoutine>& a_crInstance1, const CFunctor<T_OtherRoutine>& a_crInstance2);

  //! Operator: Assign with pointer to function.
  /*!
      \param a_fFunction - Pointer to function.
      \return Reference to the current class instance.
  */
  CFunctor<T_Function>& operator = (TFunction a_fFunction);
  //! Operator: Assign with functor class instance and use its 'operator()'.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \return Reference to the current class instance.
  */
  template <class T_Class>
  CFunctor<T_Function>& operator = (T_Class& a_rClassInstance);
  //! Operator: Assign with functor constant class instance and use its 'operator()'.
  /*!
      \param a_crClassInstance - Constant reference to the class instance.
      \return Reference to the current class instance.
  */
  template <class T_Class>
  CFunctor<T_Function>& operator = (const T_Class& a_crClassInstance);
  //! Operator: Assign with functor volatile class instance and use its 'operator()'.
  /*!
      \param a_vrClassInstance - Volatile reference to the class instance.
      \return Reference to the current class instance.
  */
  template <class T_Class>
  CFunctor<T_Function>& operator = (volatile T_Class& a_vrClassInstance);
  //! Operator: Assign with functor constant volatile class instance and use its 'operator()'.
  /*!
      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \return Reference to the current class instance.
  */
  template <class T_Class>
  CFunctor<T_Function>& operator = (const volatile T_Class& a_cvrClassInstance);
  //! Operator: Assign another CFunctor class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFunctor class.
      \return Reference to the current class instance.
  */
  CFunctor<T_Function>& operator = (const CFunctor<T_Function>& a_crInstance);

  //! Set pointer to function.
  /*!
      \param a_fFunction - Pointer to function.
      \return true  - if functor was successfully initialized with pointer to function. \n
              false - if functor was not successfully initialized with pointer to function. \n
  */
  Tbool set(TFunction a_fFunction);
  //! Set functor class instance and use its 'operator()'.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \return true  - if functor was successfully initialized with class instance. \n
              false - if functor was not successfully initialized with class instance. \n
  */
  template <class T_Class>
  Tbool set(T_Class& a_rClassInstance);
  //! Set functor constant class instance and use its 'operator()'.
  /*!
      \param a_crClassInstance - Constant reference to the class instance.
      \return true  - if functor was successfully initialized with constant class instance. \n
              false - if functor was not successfully initialized with constant class instance. \n
  */
  template <class T_Class>
  Tbool set(const T_Class& a_crClassInstance);
  //! Set functor volatile class instance and use its 'operator()'.
  /*!
      \param a_vrClassInstance - Volatile reference to the class instance.
      \return true  - if functor was successfully initialized with volatile class instance. \n
              false - if functor was not successfully initialized with volatile class instance. \n
  */
  template <class T_Class>
  Tbool set(volatile T_Class& a_vrClassInstance);
  //! Set functor constant volatile class instance and use its 'operator()'.
  /*!
      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \return true  - if functor was successfully initialized with constant volatile class instance. \n
              false - if functor was not successfully initialized with constant volatile class instance. \n
  */
  template <class T_Class>
  Tbool set(const volatile T_Class& a_cvrClassInstance);
  //! Set functor class instance and class method.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return true  - if functor was successfully initialized with class instance and class method. \n
              false - if functor was not successfully initialized with class instance and class method. \n
  */
  template <class T_Class, typename T_Method>
  Tbool set(T_Class& a_rClassInstance, T_Method a_fMethod);
  //! Set functor constant class instance and class method.
  /*!
      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return true  - if functor was successfully initialized with constant class instance and class method. \n
              false - if functor was not successfully initialized with constant class instance and class method. \n
  */
  template <class T_Class, typename T_Method>
  Tbool set(const T_Class& a_crClassInstance, T_Method a_fMethod);
  //! Set functor volatile class instance and class method.
  /*!
      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return true  - if functor was successfully initialized with volatile class instance and class method. \n
              false - if functor was not successfully initialized with volatile class instance and class method. \n
  */
  template <class T_Class, typename T_Method>
  Tbool set(volatile T_Class& a_vrClassInstance, T_Method a_fMethod);
  //! Set functor constant volatile class instance and class method.
  /*!
      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return true  - if functor was successfully initialized with constant volatile class instance and class method. \n
              false - if functor was not successfully initialized with constant volatile class instance and class method. \n
  */
  template <class T_Class, typename T_Method>
  Tbool set(const volatile T_Class& a_cvrClassInstance, T_Method a_fMethod);
  //! Set another CFunctor class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFunctor class.
      \return true  - if functor was successfully initialized with another functor. \n
              false - if functor was not successfully initialized with another functor. \n
  */
  Tbool set(const CFunctor<T_Function>& a_crInstance);

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

  //! Swap two CFunctor class instances.
  /*!
      \param a_rInstance - Reference to another CFunctor class instance.
  */
  void swap(CFunctor<T_Function>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/CFunctorX.inl>
/*==========================================================================*/
#endif
