/*!
 *  \file    MConceptInteger.hpp Template checking conception. Checks if
 *           template argument is integer number.
 *  \brief   Integer number template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Integer number template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   27.01.2006 22:14:24

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
#ifndef __MCONCEPTINTEGER_HPP__
#define __MCONCEPTINTEGER_HPP__
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
//! Integer number template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a integer
    number.
*/
template <typename T_Type>
class MConceptInteger :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< First integer number value.
  typename NTraits::MTraitsConcept<T_Type>::attribute m_Y; //!< Second integer number value.
};
/*--------------------------------------------------------------------------*/
//! Signed byte template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed byte.
*/
template <>
class MConceptInteger<Tsint08> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*--------------------------------------------------------------------------*/
//! Signed word template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed word.
*/
template <>
class MConceptInteger<Tsint16> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*--------------------------------------------------------------------------*/
//! Signed double word template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed double
    word.
*/
template <>
class MConceptInteger<Tsint32> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*--------------------------------------------------------------------------*/
//! Signed quadra word template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a signed quadra
    word.
*/
template <>
class MConceptInteger<Tsint64> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*--------------------------------------------------------------------------*/
//! Unsigned byte template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    byte.
*/
template <>
class MConceptInteger<Tuint08> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*--------------------------------------------------------------------------*/
//! Unsigned word template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    word.
*/
template <>
class MConceptInteger<Tuint16> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*--------------------------------------------------------------------------*/
//! Unsigned double word template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    double word.
*/
template <>
class MConceptInteger<Tuint32> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*--------------------------------------------------------------------------*/
//! Unsigned quadra word template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  unsigned
    quadra word.
*/
template <>
class MConceptInteger<Tuint64> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptInteger();
  //! Meta-class protected destructor.
  virtual ~MConceptInteger();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptInteger.inl>
/*==========================================================================*/
#endif
