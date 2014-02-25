/*!
 *  \file    MRequiresConcept.hpp.tpl Macros and meta-class for conception
 *           checking with DEF_CONCEPT_ARITY template arguments.
 *  \brief   Macros and meta-class for conception checking with DEF_CONCEPT_ARITY template arguments (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Macros and meta-class for conception checking with DEF_CONCEPT_ARITY template arguments (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Conception checking details (templates)
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
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Checking conseption meta-class with DEF_CONCEPT_ARITY template arguments.
/*!
    This meta-class should be used for conception checking  strategy.  If  you
    want to constrain some template arguments to fixed conception, you  should
    inherit class from this  MRequiresConcept  class  with  defining  template
    arguments to constrain and checking conception to apply.
*/
template <template <DEF_TEMPLATE_TEMPLATE_DECLARATION> class T_Consept, DEF_TEMPLATE_DECLARATION>
class MRequiresConcept<T_Consept<DEF_TEMPLATE_PARAMETERS>, DEF_TEMPLATE_PARAMETERS>
{
public:
  //! Define new type - pinter to 'constraints' method in conseption class.
  typedef void (T_Consept<DEF_TEMPLATE_PARAMETERS>::*TConceptMethodPtr)();

  //! Declare template class which depends on fixed 'constraints' method.
  template <TConceptMethodPtr t_ConceptMethodPtr>
  class SConceptChecker
  {

  };

  // Define new type - fixed conception checking implementation
  typedef SConceptChecker<&T_Consept<DEF_TEMPLATE_PARAMETERS>::constraints> TConceptChecker;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
