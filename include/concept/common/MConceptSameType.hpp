/*!
 *  \file    MConceptSameType.hpp Template checking conception. Checks if two
 *           template arguments have a same type.
 *  \brief   Same type template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Same type template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common conception checking
    VERSION:   1.0
    CREATED:   02.06.2006 02:43:36

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
#ifndef __MCONCEPTSAMETYPE_HPP__
#define __MCONCEPTSAMETYPE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept2.hpp>
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
//! Same type template checking conception meta-class (base version).
/*!
    This conception checks if two template arguments have a same type.
*/
template <typename T_Type1, typename T_Type2>
class MConceptSameType :
  public NDepth::NCommon::IStatic
{

};
/*--------------------------------------------------------------------------*/
//! Same type template checking conception meta-class (specialization with two same types).
/*!
    This conception checks if two template arguments have a same type.
*/
template <typename T_Type>
class MConceptSameType<T_Type, T_Type> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptSameType();
  //! Meta-class protected destructor.
  virtual ~MConceptSameType();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/common/MConceptSameType.inl>
/*==========================================================================*/
#endif
