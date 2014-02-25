/*!
 *  \file    CFunctorMaker.inl Utility class that helps to create CFunctor
 *           instances from specific values.
 *  \brief   Functor maker class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor maker class (inline).

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
#ifndef __CFUNCTORMAKER_INL__
#define __CFUNCTORMAKER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Function>
inline CFunctor<typename NTraits::NFunctions::MRemoveFunctionPtr<T_Function>::type> CFunctorMaker::make(T_Function a_fFunction)
{ CALL
  return CFunctor<typename NTraits::NFunctions::MRemoveFunctionPtr<T_Function>::type>(a_fFunction);
}
/*--------------------------------------------------------------------------*/
template <class T_Class, typename T_Method>
inline CFunctor<T_Method> CFunctorMaker::make(T_Class& a_rClassInstance, T_Method a_fMethod)
{ CALL
  return CFunctor<T_Method>(a_rClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <class T_Class, typename T_Method>
inline CFunctor<T_Method> CFunctorMaker::make(const T_Class& a_crClassInstance, T_Method a_fMethod)
{ CALL
  return CFunctor<T_Method>(a_crClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <class T_Class, typename T_Method>
inline CFunctor<T_Method> CFunctorMaker::make(volatile T_Class& a_vrClassInstance, T_Method a_fMethod)
{ CALL
  return CFunctor<T_Method>(a_vrClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <class T_Class, typename T_Method>
inline CFunctor<T_Method> CFunctorMaker::make(const volatile T_Class& a_cvrClassInstance, T_Method a_fMethod)
{ CALL
  return CFunctor<T_Method>(a_cvrClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline CFunctor<T_Function> CFunctorMaker::make(const CFunctor<T_Function>& a_crInstance)
{ CALL
  return CFunctor<T_Function>(a_crInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
