/*!
 *  \file    MConceptAssert.hpp Template checking conception. Checks if
 *           boolean template argument assertion is 'true'.
 *  \brief   Boolean template argument assertion checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Boolean template argument assertion checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common conception checking
    VERSION:   1.0
    CREATED:   20.09.2006 02:26:33

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
#ifndef __MCONCEPTASSERT_HPP__
#define __MCONCEPTASSERT_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept1.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Boolean template argument assertion checking conception meta-class (false version).
/*!
    This conception helps to  constrain  template  argument  assertion  to  be
    truth.
*/
template <Tbool t_Assertion>
class MConceptAssert :
  public NDepth::NCommon::IStatic
{

};
/*--------------------------------------------------------------------------*/
//! Boolean template argument assertion checking conception meta-class (truth version).
/*!
    This conception helps to  constrain  template  argument  assertion  to  be
    truth.
*/
template <>
class MConceptAssert<true> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptAssert();
  //! Meta-class protected destructor.
  virtual ~MConceptAssert();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/common/MConceptAssert.inl>
/*==========================================================================*/
#endif
