/*!
 *  \file    MTraitsType.hpp Traits meta-class that helps to determine type's
 *           attributes.
 *  \brief   Traits meta-class: type's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: type's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   12.03.2006 22:57:41

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
#ifndef __MTRAITSTYPE_HPP__
#define __MTRAITSTYPE_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIsArithmetic.hpp>
#include <Depth/include/traits/MIsPointer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: type's traits.
/*!
    Traits meta-class helps to determine type's attributes.  Here  comes  some
    examples of using this trait:

    Expression:                                              Result type:
    MTraitsType<int>::type                                   int
    MTraitsType<int>::base                                   int
    MTraitsType<int>::bottom                                 int
    MTraitsType<int>::parent                                 void
    MTraitsType<int>::value                                  int
    MTraitsType<int>::param                                  const int
    MTraitsType<int>::ref                                    int&
    MTraitsType<int>::cref                                   const int&

    MTraitsType<int*>::type                                  int*
    MTraitsType<int*>::base                                  int
    MTraitsType<int*>::bottom                                int
    MTraitsType<int*>::parent                                void
    MTraitsType<int*>::value                                 int*
    MTraitsType<int*>::param                                 int* const
    MTraitsType<int*>::ref                                   int*&
    MTraitsType<int*>::cref                                  int* const&

    MTraitsType<int&>::type                                  int&
    MTraitsType<int&>::base                                  int
    MTraitsType<int&>::bottom                                int
    MTraitsType<int&>::parent                                void
    MTraitsType<int&>::value                                 int&
    MTraitsType<int&>::param                                 int&
    MTraitsType<int&>::ref                                   int&
    MTraitsType<int&>::cref                                  const int&

    MTraitsType<int[3]>::type                                int[3]
    MTraitsType<int[3]>::base                                int
    MTraitsType<int[3]>::bottom                              int
    MTraitsType<int[3]>::parent                              void
    MTraitsType<int[3]>::value                               const int*
    MTraitsType<int[3]>::param                               const int* const
    MTraitsType<int[3]>::ref                                 int (&) [3]
    MTraitsType<int[3]>::cref                                const int (&) [3]

    MTraitsType<const int[3]>::type                          const int[3]
    MTraitsType<const int[3]>::base                          const int
    MTraitsType<const int[3]>::bottom                        const int
    MTraitsType<const int[3]>::parent                        void
    MTraitsType<const int[3]>::value                         const int*
    MTraitsType<const int[3]>::param                         const int* const
    MTraitsType<const int[3]>::ref                           const int (&) [3]
    MTraitsType<const int[3]>::cref                          const int (&) [3]

    MTraitsType<myclass>::type                               myclass
    MTraitsType<myclass>::base                               myclass
    MTraitsType<myclass>::bottom                             myclass
    MTraitsType<myclass>::parent                             void
    MTraitsType<myclass>::value                              myclass
    MTraitsType<myclass>::param                              const myclass&
    MTraitsType<myclass>::ref                                myclass&
    MTraitsType<myclass>::cref                               const myclass&
*/
template <typename T_Type>
class MTraitsType :
  public MType<T_Type>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef T_Type bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef T_Type value;
  //! Parameter type.
  typedef typename MIfThenElse<MIsOr<MIsArithmetic<T_Type>::yes, MIsPointer<T_Type>::yes>::yes, const T_Type, const T_Type&>::type param;
  //! Reference type.
  typedef T_Type& ref;
  //! Constant reference type.
  typedef const T_Type& cref;
  //! Pointer type.
  typedef T_Type* ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (void specialization).
template <>
class MTraitsType<void> :
  public MType<void>
{
public:
  //! Base type.
  typedef void base;
  //! Bottom type.
  typedef void bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef void value;
  //! Parameter type.
  typedef const void param;
  //! Reference type.
  typedef void ref;
  //! Constant reference type.
  typedef const void cref;
  //! Pointer type.
  typedef Tptr ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (constant void specialization).
template <>
class MTraitsType<const void> :
  public MType<const void>
{
public:
  //! Base type.
  typedef void base;
  //! Bottom type.
  typedef void bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef const void value;
  //! Parameter type.
  typedef const void param;
  //! Reference type.
  typedef const void ref;
  //! Constant reference type.
  typedef const void cref;
  //! Pointer type.
  typedef Tcptr ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (volatile void specialization).
template <>
class MTraitsType<volatile void> :
  public MType<volatile void>
{
public:
  //! Base type.
  typedef void base;
  //! Bottom type.
  typedef void bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef volatile void value;
  //! Parameter type.
  typedef const volatile void param;
  //! Reference type.
  typedef volatile void ref;
  //! Constant reference type.
  typedef const volatile void cref;
  //! Pointer type.
  typedef volatile Tptr ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (constant volatile void specialization).
template <>
class MTraitsType<const volatile void> :
  public MType<const volatile void>
{
public:
  //! Base type.
  typedef void base;
  //! Bottom type.
  typedef void bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef const volatile void value;
  //! Parameter type.
  typedef const volatile void param;
  //! Reference type.
  typedef const volatile void ref;
  //! Constant reference type.
  typedef const volatile void cref;
  //! Pointer type.
  typedef const volatile Tptr ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (reference specialization).
template <typename T_Type>
class MTraitsType<T_Type&> :
  public MType<T_Type&>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef T_Type& value;
  //! Parameter type.
  typedef T_Type& param;
  //! Reference type.
  typedef T_Type& ref;
  //! Constant reference type.
  typedef const T_Type& cref;
  //! Pointer type.
  typedef T_Type* ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (pointer specialization).
template <typename T_Type>
class MTraitsType<T_Type*> :
  public MType<T_Type*>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef T_Type* value;
  //! Parameter type.
  typedef T_Type* const param;
  //! Reference type.
  typedef T_Type*& ref;
  //! Constant reference type.
  typedef const T_Type*& cref;
  //! Pointer type.
  typedef T_Type** ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (constant pointer specialization).
template <typename T_Type>
class MTraitsType<T_Type* const> :
  public MType<T_Type* const>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef T_Type* const value;
  //! Parameter type.
  typedef T_Type* const param;
  //! Reference type.
  typedef T_Type* const& ref;
  //! Constant reference type.
  typedef const T_Type* const& cref;
  //! Pointer type.
  typedef T_Type* const* ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (volatile pointer specialization).
template <typename T_Type>
class MTraitsType<T_Type* volatile> :
  public MType<T_Type* volatile>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef T_Type* volatile value;
  //! Parameter type.
  typedef T_Type* volatile param;
  //! Reference type.
  typedef T_Type* volatile& ref;
  //! Constant reference type.
  typedef const T_Type* volatile& cref;
  //! Pointer type.
  typedef T_Type* volatile* ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (constant volatile pointer specialization).
template <typename T_Type>
class MTraitsType<T_Type* const volatile> :
  public MType<T_Type* const volatile>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef T_Type* const volatile value;
  //! Parameter type.
  typedef T_Type* const volatile param;
  //! Reference type.
  typedef T_Type* const volatile& ref;
  //! Constant reference type.
  typedef const T_Type* const volatile& cref;
  //! Pointer type.
  typedef T_Type* const volatile* ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (array specialization).
template <typename T_Type>
class MTraitsType<T_Type[]> :
  public MType<T_Type[]>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef const T_Type* value;
  //! Parameter type.
  typedef const T_Type* const param;
  //! Reference type.
  typedef T_Type*& ref;
  //! Constant reference type.
  typedef const T_Type*& cref;
  //! Pointer type.
  typedef T_Type** ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (constant array specialization).
template <typename T_Type>
class MTraitsType<const T_Type[]> :
  public MType<const T_Type[]>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef const T_Type* value;
  //! Parameter type.
  typedef const T_Type* const param;
  //! Reference type.
  typedef const T_Type*& ref;
  //! Constant reference type.
  typedef const T_Type*& cref;
  //! Pointer type.
  typedef const T_Type** ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (indexed array specialization).
template <typename T_Type, Tuint t_N>
class MTraitsType<T_Type[t_N]> :
  public MType<T_Type[t_N]>
{
private:
  //! Temporary type.
  typedef T_Type temp[t_N];

public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef const T_Type* value;
  //! Parameter type.
  typedef const T_Type* const param;
  //! Reference type.
  typedef temp& ref;
  //! Constant reference type.
  typedef const temp& cref;
  //! Pointer type.
  typedef temp* ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (constant indexed array specialization).
template <typename T_Type, Tuint t_N>
class MTraitsType<const T_Type[t_N]> :
  public MType<const T_Type[t_N]>
{
private:
  //! Temporary type.
  typedef T_Type temp[t_N];

public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef void parent;
  //! Value type.
  typedef const T_Type* value;
  //! Parameter type.
  typedef const T_Type* const param;
  //! Reference type.
  typedef const temp& ref;
  //! Constant reference type.
  typedef const temp& cref;
  //! Pointer type.
  typedef const temp* ptr;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: type's traits (pointer to class member specialization).
template <class T_Class, typename T_Type>
class MTraitsType<T_Type T_Class::*> :
  public MType<T_Type T_Class::*>
{
public:
  //! Base type.
  typedef T_Type base;
  //! Bottom type.
  typedef typename MTraitsType<T_Type>::bottom bottom;
  //! Parent class type.
  typedef T_Class parent;
  //! Value type.
  typedef typename MType<T_Type T_Class::*>::type value;
  //! Parameter type.
  typedef typename MIfThenElse<MIsOr<MIsArithmetic<T_Type>::yes, MIsPointer<T_Type>::yes>::yes, const typename MType<T_Type T_Class::*>::type, const typename MType<T_Type T_Class::*>::type&>::type param;
  //! Reference type.
  typedef typename MType<T_Type T_Class::*>::type& ref;
  //! Constant reference type.
  typedef const typename MType<T_Type T_Class::*>::type& cref;
  //! Pointer type.
  typedef typename MType<T_Type T_Class::*>::type* ptr;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
//! \example example-traits-MTraitsType.cpp
/*--------------------------------------------------------------------------*/
//! \test example-traits-MTraitsType.cpp
/*==========================================================================*/
#endif
