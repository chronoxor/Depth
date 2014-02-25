/*!
 *  \file    CClassFunctorHelperMethodVolatile.hpp.tpl Class functor helper
 *           class that emulates class volatile method calling with
 *           DEF_FUNCTOR_ARITY arguments.
 *  \brief   Class functor helper class: class volatile method calling with DEF_FUNCTOR_ARITY arguments (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class functor helper class: class volatile method calling with DEF_FUNCTOR_ARITY arguments (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   10.05.2006 03:19:31

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
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Class functor helper for class volatile method with DEF_FUNCTOR_ARITY arguments.
/*!
    This class specialize class functor with DEF_FUNCTOR_ARITY  arguments.  It
    constructed from class volatile method with  DEF_FUNCTOR_ARITY  arguments.
    Functor has 'operator()' so you can use this objects in various algorithm.

    Note that before using functor it must be initialized. To check initialize
    state you can use 'CFunctor::isValid()' method. If you  use  uninitialized
    functor it leads to the error.
*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
class DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) :
  public IClassFunctorVolatile<T_Class, DEF_TEMPLATE_PARAMETERS>
{
  //! Type for MConceptSwappable constraint checking.
  typedef DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS> TSwappableCheckType;

  // Check DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class constraint to be a swappable class.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

public:
  //! Functor class volatile method type.
  typedef T_Result (T_Class::*TMethod)(DEF_CALL_DECLARATION) volatile;

  // IClassFunctorVolatile interface overriding methods.
  virtual Tbool isValid() const;
  virtual T_Result operator () (volatile T_Class& a_vrInstance DEF_CALL_COMMA DEF_CALL_DECLARATION) const;

  // IEquatable interface overriding methods.
  virtual Tbool isEqual(const IClassFunctorVolatile<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crFunctor) const;

  // IClonable interface overriding methods.
  virtual IClassFunctorVolatile<T_Class, DEF_TEMPLATE_PARAMETERS>* clone() const;

  //! Swap two DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instances.
  /*!
      \param a_rInstance - Reference to another DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance.
  */
  void swap(DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_rInstance);

protected:
  //! Default class constructor.
  DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)();
  //! Class constructor with setting functor class volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  volatile
      method. After this initializing you can safely call 'operator()'.

      \param a_fMethod - Pointer to the class volatile method.
  */
  DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)(TMethod a_fMethod);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class.
  */
  DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)(const DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance);
  //! Class virtual destructor.
  virtual ~DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)();

  //! Operator: Equal to another DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class.
      \param a_crInstance2 - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class.
      \return true  - if DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance is equal to another one. \n
              false - if DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance is not equal to another one. \n
  */
  template <class T_OtherClass, DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator == (const DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_OtherClass, DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_OtherClass, DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance2);
  //! Operator: Not equal to another DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class.
      \param a_crInstance2 - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class.
      \return true  - if DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance is not equal to another one. \n
              false - if DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance is equal to another one. \n
  */
  template <class T_OtherClass, DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator != (const DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_OtherClass, DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_OtherClass, DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance2);

  //! Operator: Assign with class volatile method.
  /*!
      \param a_fMethod - Pointer to the class volatile method.
      \return Reference to the current class instance.
  */
  DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>& operator = (TMethod a_fMethod);
  //! Operator: Assign another DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class.
      \return Reference to the current class instance.
  */
  DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>& operator = (const DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance);

  //! Set functor class volatile method.
  /*!
      \param a_fMethod - Pointer to the class volatile method.
      \return true  - if functor was successfully initialized with class volatile method. \n
              false - if functor was not successfully initialized with class volatile method. \n
  */
  Tbool set(TMethod a_fMethod);
  //! Set another DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile) class.
      \return true  - if functor was successfully initialized with another functor. \n
              false - if functor was not successfully initialized with another functor. \n
  */
  Tbool set(const DEF_FUNCTOR_DECLARATION(CClassFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance);

  //! Get pointer to class volatile method.
  /*!
      \return Pointer to class volatile method.
  */
  TMethod getMethod() const;

private:
  TMethod m_fMethod;                    //!< Functor's class volatile method.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/details/templates/CClassFunctorHelperMethodVolatile.inl.tpl>
/*==========================================================================*/
