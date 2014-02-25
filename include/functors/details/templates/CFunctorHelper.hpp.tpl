/*!
 *  \file    CFunctorHelper.hpp.tpl Functor helper class emulates an object that
 *           can be called as a function with 'operator()'.
 *  \brief   Functor helper class (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor helper class (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   04.05.2006 21:33:42

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
//! Functor helper with DEF_FUNCTOR_ARITY arguments.
/*!
    This class specialize functor helper with DEF_FUNCTOR_ARITY arguments.
*/
template <DEF_TEMPLATE_DECLARATION>
class CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION> :
  public DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>
{
public:
  //! Functor function type.
  typedef typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction TFunction;

protected:
  //! Default class constructor.
  CFunctorHelper();
  //! Class constructor with setting functor function.
  /*!
      Initialize current functor with suitable pointer to function. After this
      initializing you can safely call 'operator()'.

      \param a_fFunction - Pointer to function.
  */
  CFunctorHelper(TFunction a_fFunction);
  //! Class constructor with setting functor class instance and class method.
  /*!
      Initialize current functor with suitable pointer  to  class  method  and
      reference to the class instance. After this initializing you can  safely
      call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class method.
  */
  template <class T_Class>
  CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor class instance and class constant method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      method and reference to the class instance. After this initializing  you
      can safely call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class constant method.
  */
  template <class T_Class>
  CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor class instance and class volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  volatile
      method and reference to the class instance. After this initializing  you
      can safely call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class volatile method.
  */
  template <class T_Class>
  CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile  method  and  reference  to  the  class  instance.  After  this
      initializing you can safely call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
  */
  template <class T_Class>
  CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor constant class instance and class constant method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      method and reference to the class instance. After this initializing  you
      can safely call 'operator()'.

      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class constant method.
      \param a_cConstFlag - Constant version additional parameter.
  */
  template <class T_Class>
  CFunctorHelper(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag);
  //! Class constructor with setting functor constant class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile  method  and  reference  to  the  class  instance.  After  this
      initializing you can safely call 'operator()'.

      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
  */
  template <class T_Class>
  CFunctorHelper(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag);
  //! Class constructor with setting functor volatile class instance and class volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  volatile
      method and reference to the class instance. After this initializing  you
      can safely call 'operator()'.

      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
  */
  template <class T_Class>
  CFunctorHelper(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag);
  //! Class constructor with setting functor volatile class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile  method  and  reference  to  the  class  instance.  After  this
      initializing you can safely call 'operator()'.

      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
  */
  template <class T_Class>
  CFunctorHelper(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag);
  //! Class constructor with setting functor constant volatile class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile  method  and  reference  to  the  class  instance.  After  this
      initializing you can safely call 'operator()'.

      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
      \param a_cConstVolatileFlag - Constant volatile version additional parameter.
  */
  template <class T_Class>
  CFunctorHelper(const volatile T_Class& a_cvrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag, const Tbool a_cConstVolatileFlag);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFunctorHelper class.
  */
  CFunctorHelper(const CFunctorHelper<DEF_TEMPLATE_PARAMETERS>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFunctorHelper();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/details/templates/CFunctorHelper.inl.tpl>
/*==========================================================================*/
