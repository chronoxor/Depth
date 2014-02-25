/*!
 *  \file    IAllocator.inl Memory allocator interface provide functionality
 *           that helps to create and destroy various type instances.
 *  \brief   Memory allocator interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory allocator interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory allocators
    VERSION:   1.0
    CREATED:   15.01.2007 02:20:32

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
#ifndef __IALLOCATOR_INL__
#define __IALLOCATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NAllocators {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IAllocator::IAllocator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IAllocator::~IAllocator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IAllocator::allocateOne()
{ CALL
  return (T_Type*)allocate(sizeof(T_Type));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IAllocator::allocateMany(const Tuint a_cInstanceCount)
{ CALL
  return (T_Type*)allocate(sizeof(T_Type) * a_cInstanceCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IAllocator::createOne()
{ CALL
  return IAllocator::initializeOne<T_Type>(IAllocator::allocateOne<T_Type>());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1>(IAllocator::allocateOne<T_Type>(), a_crArgument1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
inline T_Type* IAllocator::createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10)
{ CALL
  return IAllocator::initializeOne<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9>(IAllocator::allocateOne<T_Type>(), a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9, a_crArgument10);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount)
{ CALL
  return IAllocator::initializeMany<T_Type>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
inline T_Type* IAllocator::createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10)
{ CALL
  return IAllocator::initializeMany<T_Type, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9>(IAllocator::allocateMany<T_Type>(a_cInstanceCount), a_cInstanceCount, a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9, a_crArgument10);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
inline T_Type* IAllocator::initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_pPointer != NULL), STR("Cannot initialize NULL pointer."))
  {
    return NULL;
  }

  return cntr (a_pPointer) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9, a_crArgument10);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type();
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
inline T_Type* IAllocator::initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_pArrayOfPointers != NULL), STR("Cannot initialize NULL array pointer."))
  {
    return NULL;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    cntr (&a_pArrayOfPointers[i]) T_Type(a_crArgument1, a_crArgument2, a_crArgument3, a_crArgument4, a_crArgument5, a_crArgument6, a_crArgument7, a_crArgument8, a_crArgument9, a_crArgument10);
  return a_pArrayOfPointers;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IAllocator::destroyOne(T_Type* a_prPointer)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_prPointer != NULL), STR("Cannot destroy NULL pointer."))
  {
    return false;
  }

  a_prPointer->~T_Type();
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IAllocator::destroyMany(T_Type* a_prArrayOfPointers, const Tuint a_cInstanceCount)
{ CALL
  // Check if the given array pointer is not NULL.
  ASSERT((a_prArrayOfPointers != NULL), STR("Cannot destroy NULL array pointer."))
  {
    return false;
  }

  for (Tuint i = 0; i < a_cInstanceCount; ++i)
    (&a_prArrayOfPointers[i])->~T_Type();
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IAllocator::deleteOne(T_Type*& a_prPointer)
{ CALL
  if (destroyOne(a_prPointer))
    return freeOne(a_prPointer);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IAllocator::deleteMany(T_Type*& a_prArrayOfPointers, const Tuint a_cInstanceCount)
{ CALL
  if (destroyMany(a_prArrayOfPointers, a_cInstanceCount))
    return freeMany(a_prArrayOfPointers, a_cInstanceCount);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IAllocator::freeOne(T_Type*& a_prPointer)
{ CALL
  // Check if the given pointer is not NULL.
  ASSERT((a_prPointer != NULL), STR("Cannot free NULL pointer."))
  {
    return false;
  }

  if (free(a_prPointer))
  {
    a_prPointer = NULL;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool IAllocator::freeMany(T_Type*& a_prArrayOfPointers, const Tuint a_cInstanceCount)
{ CALL
  IGNORE_UNUSED(a_cInstanceCount);

  // Check if the given array pointer is not NULL.
  ASSERT((a_prArrayOfPointers != NULL), STR("Cannot free NULL array pointer."))
  {
    return false;
  }

  if (free(a_prArrayOfPointers))
  {
    a_prArrayOfPointers = NULL;
    return true;
  }
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
