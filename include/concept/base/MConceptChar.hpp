/*!
 *  \file    MConceptChar.hpp Template checking conception. Checks if
 *           template argument is character type.
 *  \brief   Character value template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character value template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   10.03.2006 23:42:18

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
#ifndef __MCONCEPTCHAR_HPP__
#define __MCONCEPTCHAR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptConstructible.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Character template checking conception meta-class (base version).
/*!
    This conception helps to constrain template argument  to  be  a  character
    type.
*/
template <typename T_Type>
class MConceptChar :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptChar();
  //! Meta-class protected destructor.
  virtual ~MConceptChar();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< First character value.
  typename NTraits::MTraitsConcept<T_Type>::attribute m_Y; //!< Second character value.
};
/*--------------------------------------------------------------------------*/
//! Single byte character template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    character type.
*/
template <>
class MConceptChar<Tschar> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptChar();
  //! Meta-class protected destructor.
  virtual ~MConceptChar();
};
/*--------------------------------------------------------------------------*/
//! Wide character template checking conception meta-class.
/*!
    This conception  helps  to  constrain  template  argument  to  be  a  wide
    character type.
*/
template <>
class MConceptChar<Twchar> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptChar();
  //! Meta-class protected destructor.
  virtual ~MConceptChar();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptChar.inl>
/*==========================================================================*/
#endif
