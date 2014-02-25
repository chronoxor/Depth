/*!
 *  \file    CFunctorHelperX.inl.tpl Functor helper class emulates an object
 *           that can be called as a function with 'operator()'.
 *  \brief   Functor helper class: functor with DEF_FUNCTOR_ARITY arguments (template inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor helper class: functor with DEF_FUNCTOR_ARITY arguments (template inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   04.05.2006 20:43:32

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
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)() :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction a_fFunction) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_fFunction);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_rClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_rClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_rClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_rClassInstance, a_fMethod);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_crClassInstance, a_fMethod, a_cConstFlag);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_crClassInstance, a_fMethod, a_cConstFlag);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_vrClassInstance, a_fMethod, a_cConstFlag, a_cVolatileFlag);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_vrClassInstance, a_fMethod, a_cConstFlag, a_cVolatileFlag);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const volatile T_Class& a_cvrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag, const Tbool a_cConstVolatileFlag) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_cvrClassInstance, a_fMethod, a_cConstFlag, a_cVolatileFlag, a_cConstVolatileFlag);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance) :
  NUtility::NObserver::IObserver(),
  IFunctor<DEF_TEMPLATE_PARAMETERS>(),
  m_Type(e_EMPTY),
  m_pFunctor(NULL),
  m_cpCaller(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::~DEF_FUNCTOR_DECLARATION(CFunctorHelper)()
{ CALL
  clean();
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool operator == (const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance2)
{ CALL
  return (a_crInstance1.isEqual(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool operator != (const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance2)
{ CALL
  return (a_crInstance1.isNotEqual(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::operator = (typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction a_fFunction)
{ CALL
  set(a_fFunction);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::operator = (const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction a_fFunction)
{ CALL
  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to function).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>(a_fFunction);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a function (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_FUNCTION;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod)
{ CALL
  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the class instance and class method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_rClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a class instance and a class method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD;

  // If given class is IObserver, then connect to it.
  IObserver* observer = NAlgorithms::NCommon::nonPolymorphicCast<IObserver*>(&a_rClassInstance);
  if (observer != NULL)
  {
    if (IObserver::insert(*observer))
    {
      m_Type = e_CONNECTOR_METHOD;
      m_cpCaller = observer;
      return true;
    }
    else
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod)
{ CALL
  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the class instance and class constant method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_rClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a class instance and a class constant method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_CONST;

  // If given class is IObserver, then connect to it.
  IObserver* observer = NAlgorithms::NCommon::nonPolymorphicCast<IObserver*>(&a_rClassInstance);
  if (observer != NULL)
  {
    if (IObserver::insert(*observer))
    {
      m_Type = e_CONNECTOR_METHOD_CONST;
      m_cpCaller = observer;
      return true;
    }
    else
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod)
{ CALL
  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the class instance and class volatile method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_rClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a class instance and a class volatile method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_VOLATILE;

  // If given class is IObserver, then connect to it.
  IObserver* observer = NAlgorithms::NCommon::nonPolymorphicCast<IObserver*>(&a_rClassInstance);
  if (observer != NULL)
  {
    if (IObserver::insert(*observer))
    {
      m_Type = e_CONNECTOR_METHOD_VOLATILE;
      m_cpCaller = observer;
      return true;
    }
    else
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod)
{ CALL
  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the class instance and class constant volatile method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_rClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a class instance and a class constant volatile method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_CONST_VOLATILE;

  // If given class is IObserver, then connect to it.
  IObserver* observer = NAlgorithms::NCommon::nonPolymorphicCast<IObserver*>(&a_rClassInstance);
  if (observer != NULL)
  {
    if (IObserver::insert(*observer))
    {
      m_Type = e_CONNECTOR_METHOD_CONST_VOLATILE;
      m_cpCaller = observer;
      return true;
    }
    else
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag)
{ CALL
  IGNORE_UNUSED(a_cConstFlag);

  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the constant class instance and class constant method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_crClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a constant class instance and a class constant method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_CONST;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag)
{ CALL
  IGNORE_UNUSED(a_cConstFlag);

  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the constant class instance and class constant volatile method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_crClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a constant class instance and a class constant volatile method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_CONST_VOLATILE;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag)
{ CALL
  IGNORE_UNUSED(a_cConstFlag);
  IGNORE_UNUSED(a_cVolatileFlag);

  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the volatile class instance and class volatile method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_vrClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a volatile class instance and a class volatile method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_VOLATILE;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag)
{ CALL
  IGNORE_UNUSED(a_cConstFlag);
  IGNORE_UNUSED(a_cVolatileFlag);

  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the volatile class instance and class constant volatile method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_vrClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a volatile class instance and a class constant volatile method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_CONST_VOLATILE;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(const volatile T_Class& a_cvrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag, const Tbool a_cConstVolatileFlag)
{ CALL
  IGNORE_UNUSED(a_cConstFlag);
  IGNORE_UNUSED(a_cVolatileFlag);
  IGNORE_UNUSED(a_cConstVolatileFlag);

  // Clean current functor.
  if (!clean())
    return false;

  // Create new functor instance (pointer to the constant volatile class instance and class constant volatile method).
  m_pFunctor = newex NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>(&a_cvrClassInstance, a_fMethod);
  if (m_pFunctor == NULL)
  {
    WARNING(STR("Cannot create a new functor instance from the pointer to a constant volatile class instance and a class constant volatile method (requested size is %u bytes).") COMMA (sizeof(NDetails::DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>)));
    return false;
  }

  // Setup functor type.
  m_Type = e_METHOD_CONST_VOLATILE;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::set(const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance."))
  {
    return false;
  }

  // Clean current functor.
  if (!clean())
    return false;

  // Set empty functor.
  if (a_crInstance.m_pFunctor == NULL)
    return false;

  // Clone functor instance.
  m_pFunctor = a_crInstance.m_pFunctor->clone();
  if (m_pFunctor == NULL)
    return false;

  // Setup functor type.
  m_Type = a_crInstance.m_Type;
  m_cpCaller = a_crInstance.m_cpCaller;

  // Connect to the functor's connections.
  return IObserver::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline typename DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::EFunctorType DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::getType() const
{ CALL
  return m_Type;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::isValid() const
{ CALL
  return ((m_pFunctor != NULL) && (m_pFunctor->isValid()) && (((m_Type != e_CONNECTOR_METHOD) && (m_Type != e_CONNECTOR_METHOD_CONST)) || ((m_cpCaller != NULL) && !m_cpCaller->isEmpty())));
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline T_Result DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::operator () (DEF_CALL_DECLARATION) const
{ CALL
  // Verify the functor to be the valid one.
  VERIFY(isValid(), STR("Calling invalid functor leads to the error."));

  return (*m_pFunctor)(DEF_CALL_PARAMETERS);
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::isEqual(const IFunctor<DEF_TEMPLATE_PARAMETERS>& a_crFunctor) const
{ CALL
  const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>* temp = NAlgorithms::NCommon::polymorphicCast<const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>*>(&a_crFunctor);

  if (temp != NULL)
  {
    // Functors with different types are different ones.
    if (m_Type != temp->m_Type)
      return false;
    // Empty functors are same ones.
    if ((m_pFunctor == NULL) && (temp->m_pFunctor == NULL))
      return true;
    // One empty functor and non empty one different ones.
    if ((m_pFunctor == NULL) || (temp->m_pFunctor == NULL))
      return false;
    // Compare two call connectors.
    if ((m_cpCaller != temp->m_cpCaller))
      return false;

    // Deeper lookup in functor implementations.
    return m_pFunctor->isEqual(a_crFunctor);
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline IFunctor<DEF_TEMPLATE_PARAMETERS>* DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::clone() const
{ CALL
  IFunctor<DEF_TEMPLATE_PARAMETERS>* result = newex DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new functor instance (requested size is %u bytes).") COMMA (sizeof(DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>)));
  return result;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::clean()
{ CALL
  // Disconnect all functor's connections.
  if (!IObserver::clear())
  {
    WARNING(STR("Cannot disconnect all functor's connections."));
    return false;
  }

  // Destroy functor object.
  if (m_pFunctor != NULL)
    delete m_pFunctor;

  // Clean functor's type.
  m_Type = e_EMPTY;
  m_pFunctor = NULL;
  m_cpCaller = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::onConnect(const NUtility::NObserver::IConnector& a_crIConnector)
{ CALL
  IGNORE_UNUSED(a_crIConnector);

  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline Tbool DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::onDisconnect(const NUtility::NObserver::IConnector& a_crIConnector)
{ CALL
  if (m_cpCaller == &a_crIConnector)
    m_cpCaller = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline void DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>::swap(DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NUtility::NObserver::IObserver&)(*this), (NUtility::NObserver::IObserver&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Type, a_rInstance.m_Type);
  NAlgorithms::NCommon::swap(m_pFunctor, a_rInstance.m_pFunctor);
  NAlgorithms::NCommon::swap(m_cpCaller, a_rInstance.m_cpCaller);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
