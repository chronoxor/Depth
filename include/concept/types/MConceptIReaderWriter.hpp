/*!
 *  \file    MConceptIReaderWriter.hpp Template checking conception. Checks if
 *           template argument is a reader & writer type.
 *  \brief   Reader & writer template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader & writer template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types conception checking
    VERSION:   1.0
    CREATED:   17.08.2008 23:00:37

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
#ifndef __MCONCEPTIREADERWRITER_HPP__
#define __MCONCEPTIREADERWRITER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept1.hpp>
#include <Depth/include/stream/IReaderWriter.hpp>
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
//! ReaderWriter template checking conception meta-class.
/*!
    This conception checks if template argument type  is  a  reader  &  writer
    class.
*/
template <class T_Class>
class MConceptIReaderWriter :
  public MConcept
{
public:
  // MConcept meta-class overriding methods.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptIReaderWriter();
  //! Meta-class protected destructor.
  virtual ~MConceptIReaderWriter();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute m_ReaderWriter; //!< Reference to the reader & writer instance.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptIReaderWriter.inl>
/*==========================================================================*/
#endif
