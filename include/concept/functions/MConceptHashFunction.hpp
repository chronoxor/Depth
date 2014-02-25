/*!
 *  \file    MConceptHashFunction.hpp Template checking conception. Checks if
 *           template argument is a hash function.
 *  \brief   Hash function template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash function template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   06.05.2008 22:11:35

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
#ifndef __MCONCEPTHASHFUNCTION_HPP__
#define __MCONCEPTHASHFUNCTION_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept2.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Hash function template checking conception meta-class.
/*!
    This conception  helps  to  constrain  template  argument  to  be  a  hash
    function.
*/
template <typename T_HashFunction, typename T_Argument>
class MConceptHashFunction :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptHashFunction();
  //! Meta-class protected destructor.
  virtual ~MConceptHashFunction();

private:
  typename NTraits::MTraitsConcept<T_HashFunction>::attribute m_fHashFunction; //!< Hash function.
  typename NTraits::MTraitsConcept<T_Argument>::attribute     m_Argument;      //!< Hash function argument.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptHashFunction.inl>
/*==========================================================================*/
#endif
