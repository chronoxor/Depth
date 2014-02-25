/*!
 *  \file    MConceptIString.hpp Template checking conception. Checks if
 *           template argument is a non constant string class.
 *  \brief   Non constant string class template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant string class template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types conception checking
    VERSION:   1.0
    CREATED:   06.05.2008 21:25:54

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
#ifndef __MCONCEPTISTRING_HPP__
#define __MCONCEPTISTRING_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptIStringConst.hpp>
#include <Depth/include/string/CSystemString.hpp>
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
//! Non constant string class template checking conception meta-class.
/*!
    This conception checks if template argument type is a non constant  string
    class.
*/
template <class T_Class>
class MConceptIString :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptIString();
  //! Meta-class protected destructor.
  virtual ~MConceptIString();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute m_String; //!< Reference to the non constant string instance.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptIString.inl>
/*==========================================================================*/
#endif
