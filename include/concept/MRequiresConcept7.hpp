/*!
 *  \file    MRequiresConcept7.hpp Macros and meta-class for conception
 *           checking with 7 template arguments.
 *  \brief   Macros and meta-class for conception checking with 7 template arguments.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Macros and meta-class for conception checking with 7 template arguments.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template arguments checking conception
    VERSION:   1.0
    CREATED:   18.01.2006 20:08:34

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
#ifndef __MREQUIRESCONCEPT7_HPP__
#define __MREQUIRESCONCEPT7_HPP__
/*==========================================================================*/
#include <Depth/include/concept/details/MRequiresConceptX.hpp>
/*==========================================================================*/
/* DEFINE DECLARATIONS                                                      */
/*==========================================================================*/
/*!
    \def REQUIRES_CONCEPT7(NNamespace, MConcept, T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7)
    Force  to   check  template  arguments \a T_Type1, \a T_Type2, \a T_Type3,
    \a T_Type4,  \a T_Type5,  \a T_Type6,  \a T_Type7  to  be   suitable  with
    conseption \a MConcept from namespace \a NNamespace.
*/
#define REQUIRES_CONCEPT7(NNamespace, MConcept, T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7) \
  typedef void (NNamespace::MConcept<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>::* TFunction##MConcept##T_Type1##T_Type2##T_Type3##T_Type4##T_Type5##T_Type6##T_Type7)(); \
  template <TFunction##MConcept##T_Type1##T_Type2##T_Type3##T_Type4##T_Type5##T_Type6##T_Type7 t_ConstraintsFunction> \
  struct SCheck##MConcept##T_Type1##T_Type2##T_Type3##T_Type4##T_Type5##T_Type6##T_Type7 { }; \
  typedef SCheck##MConcept##T_Type1##T_Type2##T_Type3##T_Type4##T_Type5##T_Type6##T_Type7<&NNamespace::MConcept<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>::constraints> TCheckType##MConcept##T_Type1##T_Type2##T_Type3##T_Type4##T_Type5##T_Type6##T_Type7
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
#define DEF_CONCEPT_ARITY                        7
#define DEF_TEMPLATE_DECLARATION                 typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7
#define DEF_TEMPLATE_PARAMETERS                  T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7
#define DEF_TEMPLATE_TEMPLATE_DECLARATION        typename, typename, typename, typename, typename, typename, typename
#include <Depth/include/concept/details/templates/MRequiresConcept.hpp.tpl>
#undef DEF_CONCEPT_ARITY
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_TEMPLATE_DECLARATION
/*==========================================================================*/
#endif
