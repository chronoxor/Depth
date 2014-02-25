/*!
 *  \file    CFunctorHelperMethodConst.inl.tpl Functor helper class
 *           that emulates class instance constant method calling
 *           with DEF_FUNCTOR_ARITY arguments.
 *  \brief   Functor helper class: class instance constant method calling with DEF_FUNCTOR_ARITY arguments (template inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor helper class: class instance constant method calling with DEF_FUNCTOR_ARITY arguments (template inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   05.05.2006 03:49:53

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
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)() :
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_cpClassInstance(NULL),
  m_fMethod(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)(const TClass* a_cpClassInstance, TMethod a_fMethod) :
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_cpClassInstance(a_cpClassInstance),
  m_fMethod(a_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)(const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance) :
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_cpClassInstance(a_crInstance.m_cpClassInstance),
  m_fMethod(a_crInstance.m_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::~DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool operator == (const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance2)
{ CALL
  return (a_crInstance1.isEqual(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool operator != (const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance2)
{ CALL
  return (a_crInstance1.isNotEqual(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::operator = (const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::set(const TClass* a_cpClassInstance, TMethod a_fMethod)
{ CALL
  m_cpClassInstance = a_cpClassInstance;
  m_fMethod = a_fMethod;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::set(const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_crInstance)
{ CALL
  m_cpClassInstance = a_crInstance.m_cpClassInstance;
  m_fMethod = a_crInstance.m_fMethod;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline const typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TClass* DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::getClass() const
{ CALL
  return m_cpClassInstance;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::getMethod() const
{ CALL
  return m_fMethod;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::isValid() const
{ CALL
  return ((m_cpClassInstance != NULL) && (m_fMethod != NULL));
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline T_Result DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::operator () (DEF_CALL_DECLARATION) const
{ CALL
  // Verify the functor to be the valid one.
  VERIFY(isValid(), STR("Calling invalid functor leads to the error."));

  return (m_cpClassInstance->*m_fMethod)(DEF_CALL_PARAMETERS);
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::isEqual(const IFunctor<DEF_TEMPLATE_PARAMETERS>& a_crFunctor) const
{ CALL
  const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>* temp = NAlgorithms::NCommon::polymorphicCast<const DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>*>(&a_crFunctor);

  if (temp != NULL)
    return ((m_cpClassInstance == temp->m_cpClassInstance) && (m_fMethod == temp->m_fMethod));
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline IFunctor<DEF_TEMPLATE_PARAMETERS>* DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::clone() const
{ CALL
  IFunctor<DEF_TEMPLATE_PARAMETERS>* result = newex DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new functor instance (requested size is %u bytes).") COMMA (sizeof(DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
inline void DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::swap(DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpClassInstance, a_rInstance.m_cpClassInstance);
  NAlgorithms::NCommon::swap(m_fMethod, a_rInstance.m_fMethod);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
