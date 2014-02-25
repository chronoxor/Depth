/*!
 *  \file    CAllocatorAligned.inl Memory allocator class which uses aligned
 *           CMemory allocation.
 *  \brief   Memory allocator class which uses aligned CMemory allocation (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory allocator class which uses aligned CMemory allocation (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory allocators
    VERSION:   1.0
    CREATED:   28.06.2007 23:45:23

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
#ifndef __CALLOCATORALIGNED_INL__
#define __CALLOCATORALIGNED_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NAllocators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <Tuint t_Align>
inline Tptr CAllocatorAligned<t_Align>::allocate(const Tuint a_cSize)
{ CALL
  return CMemory::allocateAligned(a_cSize, t_Align, 0, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Align>
inline Tbool CAllocatorAligned<t_Align>::free(Tptr a_pPointer)
{ CALL
  return CMemory::freeAligned(a_pPointer, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Align>
template <class T_Archive>
inline Tbool CAllocatorAligned<t_Align>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint align = t_Align;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMemory::NAllocators::CAllocatorAligned")));
    CHECK(a_rArchive.doProperty(align, STR("align")));
  CHECK(a_rArchive.body());

  // Check if the loaded alignment value is equal the current one.
  ASSERT((align == t_Align), STR("Cannot load CAllocatorAligned class instance with different alignment values (align = %u, t_Align = %u).") COMMA align COMMA t_Align)
  {
    return false;
  }

  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Align>
template <class T_Archive>
inline Tbool CAllocatorAligned<t_Align>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint align = t_Align;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMemory::NAllocators::CAllocatorAligned")));
    CHECK(a_rArchive.doProperty(align, STR("align")));
  CHECK(a_rArchive.body());
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Align>
template <class T_Archive>
inline Tbool CAllocatorAligned<t_Align>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <Tuint t_Align>
inline void CAllocatorAligned<t_Align>::swap(CAllocatorAligned<t_Align>& a_rInstance)
{ CALL
  IGNORE_UNUSED(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
