/*!
 *  \file    CClassFunctorHelper.hpp.tpl Class functor helper class emulates
 *           an object that can be called as a function with 'operator()'.
 *  \brief   Class functor helper class (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class functor helper class (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   10.05.2006 03:40:25

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
//! Class functor helper with DEF_FUNCTOR_ARITY arguments.
/*!
    This  class  specialize  class  functor  helper   with   DEF_FUNCTOR_ARITY
    arguments.
*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
class CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION> :
  public DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>
{
  //! Type for MConceptSwappable constraint checking.
  typedef CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION> TSwappableCheckType;

  // Check CClassFunctorHelper class constraint to be a swappable class.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

public:
  enum EFunctorType                     //! Type of the functor.
  {
    e_EMPTY,                            //!< Empty functor.
    e_METHOD,                           //!< Functor initialized with the class method.
    e_METHOD_CONST,                     //!< Functor initialized with the class constant method.
    e_METHOD_VOLATILE,                  //!< Functor initialized with the class volatile method.
    e_METHOD_CONST_VOLATILE             //!< Functor initialized with the class constant volatile method.
  };

  //! Functor class method type.
  typedef typename DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod TMethod;

  //! Swap two CClassFunctorHelper class instances.
  /*!
      \param a_rInstance - Reference to another CClassFunctorHelper class instance.
  */
  void swap(CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_rInstance);

protected:
  //! Default class constructor.
  CClassFunctorHelper();
  //! Class constructor with setting functor class method.
  /*!
      Initialize current functor with suitable pointer to class method.  After
      this initializing you can safely call 'operator()'.

      \param a_fMethod - Pointer to the class method.
  */
  CClassFunctorHelper(TMethod a_fMethod);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CClassFunctorHelper class.
  */
  CClassFunctorHelper(const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CClassFunctorHelper();

  //! Operator: Equal to another CClassFunctorHelper class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CClassFunctorHelper class.
      \param a_crInstance2 - Constant reference to another instance of the CClassFunctorHelper class.
      \return true  - if CClassFunctorHelper class instance is equal to another one. \n
              false - if CClassFunctorHelper class instance is not equal to another one. \n
  */
  template <class T_OtherClass, DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator == (const CClassFunctorHelper<DEF_TEMPLATE_OTHER_SPECIALIZATION>& a_crInstance1, const CClassFunctorHelper<DEF_TEMPLATE_OTHER_SPECIALIZATION>& a_crInstance2);
  //! Operator: Not equal to another CClassFunctorHelper class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CClassFunctorHelper class.
      \param a_crInstance2 - Constant reference to another instance of the CClassFunctorHelper class.
      \return true  - if CClassFunctorHelper class instance is not equal to another one. \n
              false - if CClassFunctorHelper class instance is equal to another one. \n
  */
  template <class T_OtherClass, DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator != (const CClassFunctorHelper<DEF_TEMPLATE_OTHER_SPECIALIZATION>& a_crInstance1, const CClassFunctorHelper<DEF_TEMPLATE_OTHER_SPECIALIZATION>& a_crInstance2);

  //! Operator: Assign with class method.
  /*!
      \param a_fMethod - Pointer to the class method.
      \return Reference to the current class instance.
  */
  CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& operator = (TMethod a_fMethod);
  //! Operator: Assign another CClassFunctorHelper class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CClassFunctorHelper class.
      \return Reference to the current class instance.
  */
  CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& operator = (const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance);

  //! Set functor class method.
  /*!
      \param a_fMethod - Pointer to the class method.
      \return true  - if functor was successfully initialized with class method. \n
              false - if functor was not successfully initialized with class method. \n
  */
  Tbool set(TMethod a_fMethod);
  //! Set another CClassFunctorHelper class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CClassFunctorHelper class.
      \return true  - if functor was successfully initialized with another functor. \n
              false - if functor was not successfully initialized with another functor. \n
  */
  Tbool set(const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance);

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

private:
  EFunctorType m_Type;                  //!< Current functor type.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/details/templates/CClassFunctorHelper.inl.tpl>
/*==========================================================================*/
