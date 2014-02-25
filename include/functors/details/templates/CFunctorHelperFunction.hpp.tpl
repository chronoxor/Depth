/*!
 *  \file    CFunctorHelperFunction.hpp.tpl Functor helper class that
 *           emulates single function calling with DEF_FUNCTOR_ARITY arguments.
 *  \brief   Functor helper class: function calling with DEF_FUNCTOR_ARITY arguments (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor helper class: function calling with DEF_FUNCTOR_ARITY arguments (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   04.05.2006 20:35:53

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
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
template <DEF_TEMPLATE_DECLARATION>
class DEF_FUNCTOR_DECLARATION(CFunctorHelper);
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Functor helper for functions with DEF_FUNCTOR_ARITY arguments.
/*!
    This  class  specialize  functor  with  DEF_FUNCTOR_ARITY  arguments.   It
    constructed from  pointer  to  function  with  0  arguments.  Functor  has
    'operator()' so you can use this objects in various algorithm.

    Note that before using functor it must be initialized. To check initialize
    state you can use 'CFunctor::isValid()' method. If you  use  uninitialized
    functor it leads to the error.
*/
template <DEF_TEMPLATE_DECLARATION>
class DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) :
  public IFunctor<DEF_TEMPLATE_PARAMETERS>
{
  // Friend class: Functor helper with DEF_FUNCTOR_ARITY arguments.
  friend class DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>;

  //! Type for MConceptSwappable constraint checking.
  typedef DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS> TSwappableCheckType;

  // Check DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class constraint to be a swappable class.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

public:
  //! Functor function type.
  typedef T_Result (*TFunction)(DEF_CALL_DECLARATION);

  // IFunctor interface overriding methods.
  virtual Tbool isValid() const;
  virtual T_Result operator () (DEF_CALL_DECLARATION) const;

  // IEquatable interface overriding methods.
  virtual Tbool isEqual(const IFunctor<DEF_TEMPLATE_PARAMETERS>& a_crFunctor) const;

  // IClonable interface overriding methods.
  virtual IFunctor<DEF_TEMPLATE_PARAMETERS>* clone() const;

  //! Swap two DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instances.
  /*!
      \param a_rInstance - Reference to another DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance.
  */
  void swap(DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_rInstance);

protected:
  //! Default class constructor.
  DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)();
  //! Class constructor with setting functor function.
  /*!
      Initialize current functor with suitable pointer to function. After this
      initializing you can safely call 'operator()'.

      \param a_fFunction - Pointer to function.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)(TFunction a_fFunction);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)(const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance);
  //! Class virtual destructor.
  virtual ~DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)();

  //! Operator: Equal to another DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class.
      \param a_crInstance2 - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class.
      \return true  - if DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance is equal to another one. \n
              false - if DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance is not equal to another one. \n
  */
  template <DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator == (const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance2);
  //! Operator: Not equal to another DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class.
      \param a_crInstance2 - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class.
      \return true  - if DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance is not equal to another one. \n
              false - if DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance is equal to another one. \n
  */
  template <DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator != (const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance2);

  //! Operator: Assign with pointer to function.
  /*!
      \param a_fFunction - Pointer to function.
      \return Reference to the current class instance.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& operator = (TFunction a_fFunction);
  //! Operator: Assign another DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class.
      \return Reference to the current class instance.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& operator = (const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance);

  //! Set pointer to function.
  /*!
      \param a_fFunction - Pointer to function.
      \return true  - if functor was successfully initialized with pointer to function. \n
              false - if functor was not successfully initialized with pointer to function. \n
  */
  Tbool set(TFunction a_fFunction);
  //! Set another DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction) class.
      \return true  - if functor was successfully initialized with another functor. \n
              false - if functor was not successfully initialized with another functor. \n
  */
  Tbool set(const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance);

  //! Get pointer to function.
  /*!
      \return Pointer to function.
  */
  TFunction getFunction() const;

private:
  TFunction m_fFunction;                //!< Functor's function.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/details/templates/CFunctorHelperFunction.inl.tpl>
/*==========================================================================*/
