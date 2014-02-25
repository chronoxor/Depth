/*!
 *  \file    CFunctorMaker.hpp Utility class that helps to create CFunctor
 *           instances from specific values.
 *  \brief   Functor maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors
    VERSION:   1.0
    CREATED:   17.05.2006 03:44:31

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
#ifndef __CFUNCTORMAKER_HPP__
#define __CFUNCTORMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/functors/CFunctorX.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Functor maker class.
/*!
    With this utility class template CFunctor instances can be created without
    specifying template arguments.
*/
class BASE_API CFunctorMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CFunctor instance from specified functor function.
  /*!
      \param a_fFunction - Pointer to function.
      \return CFunctor class instance.
  */
  template <typename T_Function>
  static CFunctor<typename NTraits::NFunctions::MRemoveFunctionPtr<T_Function>::type> make(T_Function a_fFunction);
  //! Make CFunctor instance from specified class instance and class method.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return CFunctor class instance.
  */
  template <class T_Class, typename T_Method>
  static CFunctor<T_Method> make(T_Class& a_rClassInstance, T_Method a_fMethod);
  //! Make CFunctor instance from specified constant class instance and class method.
  /*!
      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return CFunctor class instance.
  */
  template <class T_Class, typename T_Method>
  static CFunctor<T_Method> make(const T_Class& a_crClassInstance, T_Method a_fMethod);
  //! Make CFunctor instance from specified volatile class instance and class method.
  /*!
      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return CFunctor class instance.
  */
  template <class T_Class, typename T_Method>
  static CFunctor<T_Method> make(volatile T_Class& a_vrClassInstance, T_Method a_fMethod);
  //! Make CFunctor instance from specified constant volatile class instance and class method.
  /*!
      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return CFunctor class instance.
  */
  template <class T_Class, typename T_Method>
  static CFunctor<T_Method> make(const volatile T_Class& a_cvrClassInstance, T_Method a_fMethod);

  //! Make CFunctor instance from specified CFunctor class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFunctor class.
      \return CFunctor class instance.
  */
  template <typename T_Function>
  static CFunctor<T_Function> make(const CFunctor<T_Function>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/CFunctorMaker.inl>
/*==========================================================================*/
#endif
