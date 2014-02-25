/*!
 *  \file    MConcept.hpp Base template checking conception. Such conception
 *           helps to implement template arguments constrains.
 *  \brief   Base template checking conception meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base template checking conception meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template arguments checking conception
    VERSION:   1.0
    CREATED:   15.01.2006 21:37:27

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
#ifndef __MCONCEPT_HPP__
#define __MCONCEPT_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MTraitsConcept.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Base template checking conception meta-class.
/*!
    All template checking conception must implement constraints()  method.  In
    it template arguments checking algorithm applied.
*/
class BASE_API MConcept
{
public:
  //! Main template arguments checking method.
  /*!
      This  method  used  by  template  arguments  checking  algorithm.  While
      instantiating template with constrains this method signals  if  template
      arguments has wrong types.
  */
  virtual void constraints() = 0;

protected:
  //! Default meta-class protected constructor.
  MConcept();

public:
  //! Meta-class virtual destructor.
  virtual ~MConcept();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/MConcept.inl>
/*==========================================================================*/
#endif
