/*!
 *  \file    CClassFunctorX.inl Class functor class emulates an object that
 *           can be called as a function with 'operator()'.
 *  \brief   Class functor class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class functor class (inline).

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
#ifndef __CCLASSFUNCTORX_INL__
#define __CCLASSFUNCTORX_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Method>
inline CClassFunctor<T_Method>::CClassFunctor() :
  NDetails::CClassFunctorHelper<T_Method>()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline CClassFunctor<T_Method>::CClassFunctor(TMethod a_fMethod) :
  NDetails::CClassFunctorHelper<T_Method>(a_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline CClassFunctor<T_Method>::CClassFunctor(const CClassFunctor<T_Method>& a_crInstance) :
  NDetails::CClassFunctorHelper<T_Method>(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline CClassFunctor<T_Method>::~CClassFunctor()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline Tbool operator == (const CClassFunctor<T_Method>& a_crInstance1, const CClassFunctor<T_Method>& a_crInstance2)
{ CALL
  return (((const NDetails::CClassFunctorHelper<T_Method>&)a_crInstance1) == ((const NDetails::CClassFunctorHelper<T_Method>&)a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline Tbool operator != (const CClassFunctor<T_Method>& a_crInstance1, const CClassFunctor<T_Method>& a_crInstance2)
{ CALL
  return (((const NDetails::CClassFunctorHelper<T_Method>&)a_crInstance1) != ((const NDetails::CClassFunctorHelper<T_Method>&)a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline CClassFunctor<T_Method>& CClassFunctor<T_Method>::operator = (TMethod a_fMethod)
{ CALL
  set(a_fMethod);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline CClassFunctor<T_Method>& CClassFunctor<T_Method>::operator = (const CClassFunctor<T_Method>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline Tbool CClassFunctor<T_Method>::set(TMethod a_fMethod)
{ CALL
  return NDetails::CClassFunctorHelper<T_Method>::set(a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline Tbool CClassFunctor<T_Method>::set(const CClassFunctor<T_Method>& a_crInstance)
{ CALL
  return NDetails::CClassFunctorHelper<T_Method>::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline typename CClassFunctor<T_Method>::EFunctorType CClassFunctor<T_Method>::getType() const
{ CALL
  return NDetails::CClassFunctorHelper<T_Method>::getType();
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline Tbool CClassFunctor<T_Method>::clean()
{ CALL
  return NDetails::CClassFunctorHelper<T_Method>::clean();
}
/*--------------------------------------------------------------------------*/
template <typename T_Method>
inline void CClassFunctor<T_Method>::swap(CClassFunctor<T_Method>& a_rInstance)
{ CALL
  NDetails::CClassFunctorHelper<T_Method>::swap(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
