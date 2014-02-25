/*!
 *  \file    CMemoryManagerSystem.hpp Memory manager class which uses system
 *           memory allocation.
 *  \brief   Memory manager class which uses system memory allocation.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory manager class which uses system memory allocation.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory managers
    VERSION:   1.0
    CREATED:   28.06.2007 02:16:18

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
#ifndef __CMEMORYMANAGERSYSTEM_HPP__
#define __CMEMORYMANAGERSYSTEM_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/memory/managers/IMemoryManager.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NManagers {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Memory manager class which uses system memory allocation.
/*!
    The memory manager uses system memory allocations  to  allocate  and  free
    memory blocks.
*/
class BASE_API CMemoryManagerSystem :
  public IMemoryManager
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CMemoryManagerSystem TDepthCheckType;

  // Check CMemoryManagerSystem class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  // IMemoryManager interface overriding methods.
  virtual Tptr allocate(const Tuint a_cSize);
  virtual Tptr reallocate(Tptr a_pPointer, const Tuint a_cSize);
  virtual Tbool free(Tptr a_pPointer);

public:
  //! Serialize CMemoryManagerSystem class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMemoryManagerSystem class instances.
  /*!
      \param a_rInstance - Reference to another CMemoryManagerSystem class instance.
  */
  void swap(CMemoryManagerSystem& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/managers/CMemoryManagerSystem.inl>
/*==========================================================================*/
#endif
