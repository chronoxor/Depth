/*!
 *  \file    MConceptDepthType.hpp Template checking conception. Checks if
 *           template argument can is true Depth type.
 *  \brief   Depth type template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Depth type template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types conception checking
    VERSION:   1.0
    CREATED:   26.01.2006 23:59:53

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
#ifndef __MCONCEPTDEPTHTYPE_HPP__
#define __MCONCEPTDEPTHTYPE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ASwap.hpp>
#include <Depth/include/concept/MRequiresConcept1.hpp>
#include <Depth/include/concept/class/MConceptSwappable.hpp>
#include <Depth/include/serialization.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NTypes {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Depth type template checking conception meta-class.
/*!
    Any object in Depth library has ability to serialize itself into/from  the
    archive and  to  swap  its  instances.  This  conception  implements  such
    template argument checking.
*/
template <class T_Class>
class MConceptDepthType :
  public MConcept
{
public:
  // MConcept meta-class overriding methods.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptDepthType();
  //! Meta-class protected destructor.
  virtual ~MConceptDepthType();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.inl>
/*==========================================================================*/
#endif
