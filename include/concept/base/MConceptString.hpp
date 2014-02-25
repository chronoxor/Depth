/*!
 *  \file    MConceptString.hpp Template checking conception. Checks if
 *           template argument is a mutable string type.
 *  \brief   Mutable string value template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Mutable string value template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   27.03.2008 00:53:10

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
#ifndef __MCONCEPTSTRING_HPP__
#define __MCONCEPTSTRING_HPP__
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptStringConst.hpp>
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
//! Mutable string template checking conception meta-class (base version).
/*!
    This conception helps to constrain  template  argument  to  be  a  mutable
    string type.
*/
template <typename T_Type>
class MConceptString :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< First string value.
  typename NTraits::MTraitsConcept<T_Type>::attribute m_Y; //!< Second string value.
};
/*--------------------------------------------------------------------------*/
//! Single byte non-constant string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    non-constant string type.
*/
template <>
class MConceptString<Tschar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Single byte volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    volatile string type.
*/
template <>
class MConceptString<volatile Tschar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Single byte non-constant string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    non-constant string array type.
*/
template <>
class MConceptString<Tschar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Single byte volatile string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    volatile string array type.
*/
template <>
class MConceptString<volatile Tschar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Single byte non-constant fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    non-constant fixed-size string array type.
*/
template <Tuint t_N>
class MConceptString<Tschar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Single byte volatile fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    volatile fixed-size string array type.
*/
template <Tuint t_N>
class MConceptString<volatile Tschar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Wide non-constant string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    non-constant string type.
*/
template <>
class MConceptString<Twchar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Wide volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    volatile string type.
*/
template <>
class MConceptString<volatile Twchar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Wide non-constant string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    non-constant string array type.
*/
template <>
class MConceptString<Twchar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Wide volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    volatile string array type.
*/
template <>
class MConceptString<volatile Twchar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Wide non-constant fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    non-constant fixed-size string array type.
*/
template <Tuint t_N>
class MConceptString<Twchar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*--------------------------------------------------------------------------*/
//! Wide volatile fixed-size string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    volatile fixed-size string array type.
*/
template <Tuint t_N>
class MConceptString<volatile Twchar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptString();
  //! Meta-class protected destructor.
  virtual ~MConceptString();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptString.inl>
/*==========================================================================*/
#endif
