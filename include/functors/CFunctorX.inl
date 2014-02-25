/*!
 *  \file    CFunctorX.inl Functor class emulates an object that can be called
 *           as a function with 'operator()'.
 *  \brief   Functor class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor class (inline).

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
#ifndef __CFUNCTORX_INL__
#define __CFUNCTORX_INL__
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
inline CFunctor<T_Function>::CFunctor() :
  NDetails::CFunctorHelper<T_Function>()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline CFunctor<T_Function>::CFunctor(TFunction a_fFunction) :
  NDetails::CFunctorHelper<T_Function>(a_fFunction)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>::CFunctor(T_Class& a_rClassInstance) :
  NDetails::CFunctorHelper<T_Function>(a_rClassInstance, &T_Class::operator())
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>::CFunctor(const T_Class& a_crClassInstance) :
  NDetails::CFunctorHelper<T_Function>(a_crClassInstance, &T_Class::operator(), true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>::CFunctor(volatile T_Class& a_vrClassInstance) :
  NDetails::CFunctorHelper<T_Function>(a_vrClassInstance, &T_Class::operator(), true, true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>::CFunctor(const volatile T_Class& a_cvrClassInstance) :
  NDetails::CFunctorHelper<T_Function>(a_cvrClassInstance, &T_Class::operator(), true, true, true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline CFunctor<T_Function>::CFunctor(T_Class& a_rClassInstance, T_Method a_fMethod) :
  NDetails::CFunctorHelper<T_Function>(a_rClassInstance, a_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline CFunctor<T_Function>::CFunctor(const T_Class& a_crClassInstance, T_Method a_fMethod) :
  NDetails::CFunctorHelper<T_Function>(a_crClassInstance, a_fMethod, true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline CFunctor<T_Function>::CFunctor(volatile T_Class& a_vrClassInstance, T_Method a_fMethod) :
  NDetails::CFunctorHelper<T_Function>(a_vrClassInstance, a_fMethod, true, true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline CFunctor<T_Function>::CFunctor(const volatile T_Class& a_cvrClassInstance, T_Method a_fMethod) :
  NDetails::CFunctorHelper<T_Function>(a_cvrClassInstance, a_fMethod, true, true, true)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline CFunctor<T_Function>::CFunctor(const CFunctor<T_Function>& a_crInstance) :
  NDetails::CFunctorHelper<T_Function>(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline CFunctor<T_Function>::~CFunctor()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline Tbool operator == (const CFunctor<T_Function>& a_crInstance1, const CFunctor<T_Function>& a_crInstance2)
{ CALL
  return (((const NDetails::CFunctorHelper<T_Function>&)a_crInstance1) == ((const NDetails::CFunctorHelper<T_Function>&)a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline Tbool operator != (const CFunctor<T_Function>& a_crInstance1, const CFunctor<T_Function>& a_crInstance2)
{ CALL
  return (((const NDetails::CFunctorHelper<T_Function>&)a_crInstance1) != ((const NDetails::CFunctorHelper<T_Function>&)a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline CFunctor<T_Function>& CFunctor<T_Function>::operator = (TFunction a_fFunction)
{ CALL
  set(a_fFunction);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>& CFunctor<T_Function>::operator = (T_Class& a_rClassInstance)
{ CALL
  set(a_rClassInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>& CFunctor<T_Function>::operator = (const T_Class& a_crClassInstance)
{ CALL
  set(a_crClassInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>& CFunctor<T_Function>::operator = (volatile T_Class& a_vrClassInstance)
{ CALL
  set(a_vrClassInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline CFunctor<T_Function>& CFunctor<T_Function>::operator = (const volatile T_Class& a_cvrClassInstance)
{ CALL
  set(a_cvrClassInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline CFunctor<T_Function>& CFunctor<T_Function>::operator = (const CFunctor<T_Function>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline Tbool CFunctor<T_Function>::set(TFunction a_fFunction)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_fFunction);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline Tbool CFunctor<T_Function>::set(T_Class& a_rClassInstance)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_rClassInstance, &T_Class::operator());
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline Tbool CFunctor<T_Function>::set(const T_Class& a_crClassInstance)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_crClassInstance, &T_Class::operator(), true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline Tbool CFunctor<T_Function>::set(volatile T_Class& a_vrClassInstance)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_vrClassInstance, &T_Class::operator(), true, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class>
inline Tbool CFunctor<T_Function>::set(const volatile T_Class& a_cvrClassInstance)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_cvrClassInstance, &T_Class::operator(), true, true, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline Tbool CFunctor<T_Function>::set(T_Class& a_rClassInstance, T_Method a_fMethod)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_rClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline Tbool CFunctor<T_Function>::set(const T_Class& a_crClassInstance, T_Method a_fMethod)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_crClassInstance, a_fMethod, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline Tbool CFunctor<T_Function>::set(volatile T_Class& a_vrClassInstance, T_Method a_fMethod)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_vrClassInstance, a_fMethod, true, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
template <class T_Class, typename T_Method>
inline Tbool CFunctor<T_Function>::set(const volatile T_Class& a_cvrClassInstance, T_Method a_fMethod)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_cvrClassInstance, a_fMethod, true, true, true);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline Tbool CFunctor<T_Function>::set(const CFunctor<T_Function>& a_crInstance)
{ CALL
  return NDetails::CFunctorHelper<T_Function>::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline typename CFunctor<T_Function>::EFunctorType CFunctor<T_Function>::getType() const
{ CALL
  return NDetails::CFunctorHelper<T_Function>::getType();
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline Tbool CFunctor<T_Function>::clean()
{ CALL
  return NDetails::CFunctorHelper<T_Function>::clean();
}
/*--------------------------------------------------------------------------*/
template <typename T_Function>
inline void CFunctor<T_Function>::swap(CFunctor<T_Function>& a_rInstance)
{ CALL
  NDetails::CFunctorHelper<T_Function>::swap(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
