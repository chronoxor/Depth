/*!
 *  \file    CFunctorHelperFunction.inl.tpl Functor helper class that
 *           emulates single function calling with DEF_FUNCTOR_ARITY arguments.
 *  \brief   Functor helper class: function calling with DEF_FUNCTOR_ARITY arguments (template inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor helper class: function calling with DEF_FUNCTOR_ARITY arguments (template inline).

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
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)() :
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_fFunction(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)(TFunction a_fFunction) :
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_fFunction(a_fFunction)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)(const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance) :
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_fFunction(a_crInstance.m_fFunction)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::~DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool operator == (const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance2)
{ CALL
  return (a_crInstance1.isEqual(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool operator != (const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance2)
{ CALL
  return (a_crInstance1.isNotEqual(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::operator = (TFunction a_fFunction)
{ CALL
  set(a_fFunction);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::operator = (const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::set(TFunction a_fFunction)
{ CALL
  m_fFunction = a_fFunction;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::set(const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_crInstance)
{ CALL
  m_fFunction = a_crInstance.m_fFunction;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::getFunction() const
{ CALL
  return m_fFunction;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::isValid() const
{ CALL
  return (m_fFunction != NULL);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline T_Result DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::operator () (DEF_CALL_DECLARATION) const
{ CALL
  // Verify the functor to be the valid one.
  VERIFY(isValid(), STR("Calling invalid functor leads to the error."));

  return m_fFunction(DEF_CALL_PARAMETERS);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::isEqual(const IFunctor<DEF_TEMPLATE_PARAMETERS>& a_crFunctor) const
{ CALL
  const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>* temp = NAlgorithms::NCommon::polymorphicCast<const DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>*>(&a_crFunctor);

  if (temp != NULL)
    return (m_fFunction == temp->m_fFunction);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline IFunctor<DEF_TEMPLATE_PARAMETERS>* DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::clone() const
{ CALL
  IFunctor<DEF_TEMPLATE_PARAMETERS>* result = newex DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new functor instance (requested size is %u bytes).") COMMA (sizeof(DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>)));
  return result;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline void DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::swap(DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_fFunction, a_rInstance.m_fFunction);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
