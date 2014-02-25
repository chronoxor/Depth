/*!
 *  \file    CMemoryBlockContainer.inl GC allocated memory blocks container
 *           class.
 *  \brief   GC allocated memory blocks container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC allocated memory blocks container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   26.06.2007 02:30:49

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
#ifndef __CMEMORYBLOCKCONTAINER_INL__
#define __CMEMORYBLOCKCONTAINER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CMemoryBlockContainer::CMemoryBlockContainer() :
  NCommon::NContainers::IAssociativeConst<CMemoryBlockContainer, Tcptr, CMemoryBlock, CMemoryBlock, CMemoryBlockIterator, CMemoryBlockIterator>(),
  NCommon::NContainers::IDequeConst<CMemoryBlockContainer, CMemoryBlock, CMemoryBlockIterator, CMemoryBlockIterator>()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockContainer::~CMemoryBlockContainer()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockContainer::operator [] (const Tcptr& a_cpPointer)
{ CALL
  return find(a_cpPointer);
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockContainer::operator [] (const Tcptr& a_cpPointer) const
{ CALL
  return find(a_cpPointer);
}
/*--------------------------------------------------------------------------*/
inline Tbool CMemoryBlockContainer::isLessThan(const Tcptr& a_cpPointer1, const Tcptr& a_cpPointer2) const
{ CALL
  return (a_cpPointer1 < a_cpPointer2);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlockContainer::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("GC allocated memory blocks container cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlockContainer::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the memory blocks container header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMemory::NGC::CMemoryBlockContainer")));
    CHECK(a_rArchive.doProperty(getSize(), STR("size")));
  CHECK(a_rArchive.body());

  // Save the memory blocks container content.
  if (!isEmpty())
  {
    TIteratorConst it_first = getItFirst();
    TIteratorConst it_current = it_first;

    // Save all memory blocks container items.
    while (it_current.isValid())
    {
      // Save next memory blocks container item.
      CHECK(a_rArchive.doValue(it_current.getValueRef(), STR("item")));
      // Switch to the next memory blocks container item.
      if ((it_current.stepForward() == 0) || (it_current == it_first))
        break;
    }
  }

  // Save the memory blocks container end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlockContainer::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CMemoryBlockContainer::swap(CMemoryBlockContainer& a_rInstance)
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
