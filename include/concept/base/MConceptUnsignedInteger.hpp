/*!
 *  \file    MConceptUnsignedInteger.hpp Template checking conception. Checks if
 *           template argument is unsigned integer number.
 *  \brief   Unsigned integer number template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unsigned integer number template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   15.01.2006 21:54:38

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
#ifndef __MCONCEPTUNSIGNEDINTEGER_HPP__
#define __MCONCEPTUNSIGNEDINTEGER_HPP__
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
//! Unsigned integer number template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    integer number.
*/
template <typename T_Type>
class MConceptUnsignedInteger :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptUnsignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptUnsignedInteger();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< First unsigned integer number value.
  typename NTraits::MTraitsConcept<T_Type>::attribute m_Y; //!< Second unsigned integer number value.
};
/*--------------------------------------------------------------------------*/
//! Unsigned byte template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    byte.
*/
template <>
class MConceptUnsignedInteger<Tuint08> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptUnsignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptUnsignedInteger();
};
/*--------------------------------------------------------------------------*/
//! Unsigned word template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    word.
*/
template <>
class MConceptUnsignedInteger<Tuint16> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptUnsignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptUnsignedInteger();
};
/*--------------------------------------------------------------------------*/
//! Unsigned double word template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    double word.
*/
template <>
class MConceptUnsignedInteger<Tuint32> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptUnsignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptUnsignedInteger();
};
/*--------------------------------------------------------------------------*/
//! Unsigned quadra word template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    quadra word.
*/
template <>
class MConceptUnsignedInteger<Tuint64> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptUnsignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptUnsignedInteger();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptUnsignedInteger.inl>
/*==========================================================================*/
#endif
