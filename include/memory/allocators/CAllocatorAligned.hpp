/*!
 *  \file    CAllocatorAligned.hpp Memory allocator class which uses aligned
 *           CMemory allocation.
 *  \brief   Memory allocator class which uses aligned CMemory allocation.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory allocator class which uses aligned CMemory allocation.

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
#ifndef __CALLOCATORALIGNED_HPP__
#define __CALLOCATORALIGNED_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIAllocator.hpp>
#include <Depth/include/memory/CMemory.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NAllocators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Memory allocator class which uses aligned CMemory allocation.
/*!
    The memory allocator uses aligned CMemory allocations to allocate and free
    memory blocks.
*/
template <Tuint t_Align = NConstants::CConstants::platformBits>
class CAllocatorAligned :
  public IAllocator
{
  //! Type for the MConceptIAllocator constraint checking.
  typedef CAllocatorAligned<t_Align> TAllocatorCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CAllocatorAligned<t_Align> TDepthCheckType;

  // Check CAllocatorAligned class constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CAllocatorAligned class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  // IAllocator interface overriding methods.
  virtual Tptr allocate(const Tuint a_cSize);
  virtual Tbool free(Tptr a_pPointer);

public:
  //! Serialization load CAllocatorAligned class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CAllocatorAligned class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CAllocatorAligned class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CAllocatorAligned class instances.
  /*!
      \param a_rInstance - Reference to another CAllocatorAligned class instance.
  */
  void swap(CAllocatorAligned<t_Align>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/allocators/CAllocatorAligned.inl>
/*==========================================================================*/
#endif
