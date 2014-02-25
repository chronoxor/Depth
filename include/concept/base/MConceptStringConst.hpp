/*!
 *  \file    MConceptStringConst.hpp Template checking conception. Checks if
 *           template argument is a constant string type.
 *  \brief   Constant string value template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant string value template checking conception.

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
#ifndef __MCONCEPTSTRINGCONST_HPP__
#define __MCONCEPTSTRINGCONST_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept1.hpp>
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
//! Constant string template checking conception meta-class (base version).
/*!
    This conception helps to constrain template  argument  to  be  a  constant
    string type.
*/
template <typename T_Type>
class MConceptStringConst :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();

private:
  typename NTraits::MTraitsConcept<T_Type>::attribute m_X; //!< First constant string value.
  typename NTraits::MTraitsConcept<T_Type>::attribute m_Y; //!< Second constant string value.
};
/*--------------------------------------------------------------------------*/
//! Single byte non-constant string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    non-constant string type.
*/
template <>
class MConceptStringConst<Tschar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte constant string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    constant string type.
*/
template <>
class MConceptStringConst<const Tschar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    volatile string type.
*/
template <>
class MConceptStringConst<volatile Tschar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte constant volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    constant volatile string type.
*/
template <>
class MConceptStringConst<const volatile Tschar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte non-constant string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    non-constant string array type.
*/
template <>
class MConceptStringConst<Tschar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte constant string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    constant string array type.
*/
template <>
class MConceptStringConst<const Tschar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte volatile string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    volatile string array type.
*/
template <>
class MConceptStringConst<volatile Tschar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte constant volatile string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    constant volatile string array type.
*/
template <>
class MConceptStringConst<const volatile Tschar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte non-constant fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    non-constant fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<Tschar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte constant fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    constant fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<const Tschar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte volatile fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    volatile fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<volatile Tschar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Single byte constant volatile fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  single  byte
    constant volatile fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<const volatile Tschar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide non-constant string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    non-constant string type.
*/
template <>
class MConceptStringConst<Twchar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide constant string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    constant string type.
*/
template <>
class MConceptStringConst<const Twchar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    volatile string type.
*/
template <>
class MConceptStringConst<volatile Twchar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide constant volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    constant volatile string type.
*/
template <>
class MConceptStringConst<const volatile Twchar*> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide non-constant string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    non-constant string array type.
*/
template <>
class MConceptStringConst<Twchar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide constant string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    constant string array type.
*/
template <>
class MConceptStringConst<const Twchar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    volatile string array type.
*/
template <>
class MConceptStringConst<volatile Twchar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide constant volatile string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    constant volatile string array type.
*/
template <>
class MConceptStringConst<const volatile Twchar[]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide non-constant fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    non-constant fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<Twchar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide constant fixed-size string array template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    constant fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<const Twchar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide volatile fixed-size string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    volatile fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<volatile Twchar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*--------------------------------------------------------------------------*/
//! Wide constant volatile fixed-size string template checking conception meta-class.
/*!
    This conception helps to constrain template argument to  be  a  wide  byte
    constant volatile fixed-size string array type.
*/
template <Tuint t_N>
class MConceptStringConst<const volatile Twchar[t_N]> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptStringConst();
  //! Meta-class protected destructor.
  virtual ~MConceptStringConst();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptStringConst.inl>
/*==========================================================================*/
#endif
