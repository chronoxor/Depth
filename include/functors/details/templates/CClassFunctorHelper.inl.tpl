/*!
 *  \file    CClassFunctorHelper.inl.tpl Class functor helper class emulates
 *           an object that can be called as a function with 'operator()'.
 *  \brief   Class functor helper class (template inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class functor helper class (template inline).

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
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CClassFunctorHelper() :
  DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CClassFunctorHelper(TMethod a_fMethod) :
  DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY)
{ CALL
  set(a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CClassFunctorHelper(const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance) :
  DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::~CClassFunctorHelper()
{ CALL
  clean();
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool operator == (const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance1, const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance2)
{ CALL
  return (((const DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>&)a_crInstance1) == ((const DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>&)a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool operator != (const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance1, const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance2)
{ CALL
  return (((const DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>&)a_crInstance1) != ((const DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>&)a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::operator = (TMethod a_fMethod)
{ CALL
  set(a_fMethod);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::operator = (const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::set(TMethod a_fMethod)
{ CALL
  if (DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>::set(a_fMethod))
  {
    m_Type = DEF_FUNCTOR_TYPE;
    return true;
  }
  else
   return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::set(const CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_crInstance)
{ CALL
  if (DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>::set(a_crInstance))
  {
    m_Type = a_crInstance.m_Type;
    return true;
  }
  else
   return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline typename CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::EFunctorType CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::getType() const
{ CALL
  return m_Type;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::clean()
{ CALL
  if (DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>::set(NULL))
  {
    // Cleaned functor has 'empty' type.
    m_Type = e_EMPTY;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline void CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::swap(CClassFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>&)(*this), (DEF_FUNCTOR_DECLARATION(DEF_FUNCTOR_SPECIALIZATION)<T_Class, DEF_TEMPLATE_PARAMETERS>&)(a_rInstance));
  NAlgorithms::NCommon::swap(m_Type, a_rInstance.m_Type);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
