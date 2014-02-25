/*!
 *  \file    MTraitsConcept.hpp Traits meta-class that helps to determine
 *           template checking conception type.
 *  \brief   Traits meta-class: template checking conception type's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: template checking conception type's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   28.04.2006 03:02:31

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
#ifndef __MTRAITSCONCEPT_HPP__
#define __MTRAITSCONCEPT_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: template checking conception type's traits.
/*!
    Traits meta-class helps to determine template checking  conception  type's
    attributes. This class  used  for  all  attributes  in  template  checking
    conception.
*/
template <typename T_Type>
class MTraitsConcept :
  public MType<T_Type>
{
public:
  //! Template checking attribute type.
  typedef T_Type& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (void specialization).
template <>
class MTraitsConcept<void> :
  public MType<void>
{
public:
  //! Template checking attribute type.
  typedef void attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (constant void specialization).
template <>
class MTraitsConcept<const void> :
  public MType<const void>
{
public:
  //! Template checking attribute type.
  typedef const void attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (volatile void specialization).
template <>
class MTraitsConcept<volatile void> :
  public MType<volatile void>
{
public:
  //! Template checking attribute type.
  typedef volatile void attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (constant volatile void specialization).
template <>
class MTraitsConcept<const volatile void> :
  public MType<const volatile void>
{
public:
  //! Template checking attribute type.
  typedef const volatile void attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (reference specialization).
template <typename T_Type>
class MTraitsConcept<T_Type&> :
  public MType<T_Type&>
{
public:
  //! Template checking attribute type.
  typedef T_Type& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (pointer specialization).
template <typename T_Type>
class MTraitsConcept<T_Type*> :
  public MType<T_Type*>
{
public:
  //! Template checking attribute type.
  typedef T_Type*& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (constant pointer specialization).
template <typename T_Type>
class MTraitsConcept<T_Type* const> :
  public MType<T_Type* const>
{
public:
  //! Template checking attribute type.
  typedef T_Type* const& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (volatile pointer specialization).
template <typename T_Type>
class MTraitsConcept<T_Type* volatile> :
  public MType<T_Type* volatile>
{
public:
  //! Template checking attribute type.
  typedef T_Type* volatile& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (constant volatile pointer specialization).
template <typename T_Type>
class MTraitsConcept<T_Type* const volatile> :
  public MType<T_Type* const volatile>
{
public:
  //! Template checking attribute type.
  typedef T_Type* const volatile& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (array specialization).
template <typename T_Type>
class MTraitsConcept<T_Type[]> :
  public MType<T_Type[]>
{
public:
  //! Template checking attribute type.
  typedef T_Type*& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (constant array specialization).
template <typename T_Type>
class MTraitsConcept<const T_Type[]> :
  public MType<const T_Type[]>
{
public:
  //! Template checking attribute type.
  typedef const T_Type*& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (indexed array specialization).
template <typename T_Type, Tuint t_N>
class MTraitsConcept<T_Type[t_N]> :
  public MType<T_Type[t_N]>
{
private:
  //! Temporary type.
  typedef T_Type temp[t_N];

public:
  //! Template checking attribute type.
  typedef temp& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (constant indexed array specialization).
template <typename T_Type, Tuint t_N>
class MTraitsConcept<const T_Type[t_N]> :
  public MType<const T_Type[t_N]>
{
private:
  //! Temporary type.
  typedef T_Type temp[t_N];

public:
  //! Template checking attribute type.
  typedef const temp& attribute;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: template checking conception type's traits (pointer to class member specialization).
template <class T_Class, typename T_Type>
class MTraitsConcept<T_Type T_Class::*> :
  public MType<T_Type T_Class::*>
{
public:
  //! Template checking attribute type.
  typedef typename MType<T_Type T_Class::*>::type& attribute;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
