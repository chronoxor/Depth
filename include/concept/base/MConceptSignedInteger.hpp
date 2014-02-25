/*!
 *  \file    MConceptSignedInteger.hpp Template checking conception. Checks if
 *           template argument is signed integer number.
 *  \brief   Signed integer number template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Signed integer number template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   15.01.2006 21:45:24

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
#ifndef __MCONCEPTSIGNEDINTEGER_HPP__
#define __MCONCEPTSIGNEDINTEGER_HPP__
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
//! Signed integer number template checking conception meta-class.
/*!
    This conception helps to  constrain  template  argument  to  be  a  signed
    integer number.
*/
template <typename T_Type>
class MConceptSignedInteger :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptSignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptSignedInteger();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< First signed integer number value.
  typename NTraits::MTraitsConcept<T_Type>::attribute m_Y; //!< Second signed integer number value.
};
/*--------------------------------------------------------------------------*/
//! Signed byte template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed byte.
*/
template <>
class MConceptSignedInteger<Tsint08> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptSignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptSignedInteger();
};
/*--------------------------------------------------------------------------*/
//! Signed word template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed word.
*/
template <>
class MConceptSignedInteger<Tsint16> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptSignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptSignedInteger();
};
/*--------------------------------------------------------------------------*/
//! Signed double word template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed double
    word.
*/
template <>
class MConceptSignedInteger<Tsint32> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptSignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptSignedInteger();
};
/*--------------------------------------------------------------------------*/
//! Signed quadra word template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed quadra
    word.
*/
template <>
class MConceptSignedInteger<Tsint64> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptSignedInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptSignedInteger();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptSignedInteger.inl>
/*==========================================================================*/
#endif
