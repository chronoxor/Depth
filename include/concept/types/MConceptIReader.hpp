/*!
 *  \file    MConceptIReader.hpp Template checking conception. Checks if
 *           template argument is a reader type.
 *  \brief   Reader template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types conception checking
    VERSION:   1.0
    CREATED:   17.08.2008 22:56:09

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
#ifndef __MCONCEPTIREADER_HPP__
#define __MCONCEPTIREADER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept1.hpp>
#include <Depth/include/stream/IReader.hpp>
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
//! Reader template checking conception meta-class.
/*!
    This conception checks if template argument type is a reader class.
*/
template <class T_Class>
class MConceptIReader :
  public MConcept
{
public:
  // MConcept meta-class overriding methods.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptIReader();
  //! Meta-class protected destructor.
  virtual ~MConceptIReader();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute m_Reader; //!< Reference to the reader instance.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptIReader.inl>
/*==========================================================================*/
#endif
