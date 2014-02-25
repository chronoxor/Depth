/*!
 *  \file    CFunctorHelper.inl.tpl Functor helper class emulates an object
 *           that can be called as a function with 'operator()'.
 *  \brief   Functor helper class (template inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor helper class (template inline).

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
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <DEF_TEMPLATE_DECLARATION>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper() :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(TFunction a_fFunction) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_fFunction)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_rClassInstance, a_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_rClassInstance, a_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_rClassInstance, a_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_rClassInstance, a_fMethod)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_crClassInstance, a_fMethod, a_cConstFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_crClassInstance, a_fMethod, a_cConstFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_vrClassInstance, a_fMethod, a_cConstFlag, a_cVolatileFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_vrClassInstance, a_fMethod, a_cConstFlag, a_cVolatileFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
template <class T_Class>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(const volatile T_Class& a_cvrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag, const Tbool a_cConstVolatileFlag) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_cvrClassInstance, a_fMethod, a_cConstFlag, a_cVolatileFlag, a_cConstVolatileFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::CFunctorHelper(const CFunctorHelper<DEF_TEMPLATE_PARAMETERS>& a_crInstance) :
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline CFunctorHelper<DEF_TEMPLATE_SPECIALIZATION>::~CFunctorHelper()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
