/*!
 *  \file    CAllocatorNewEx.hpp Memory allocator class which uses extended
 *           memory new/delete operators.
 *  \brief   Extended memory allocator class which uses memory new/delete operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended memory allocator class which uses memory new/delete operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory allocators
    VERSION:   1.0
    CREATED:   15.01.2007 02:25:52

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
#ifndef __CALLOCATORNEWEX_HPP__
#define __CALLOCATORNEWEX_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIAllocator.hpp>
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
//! Extended memory allocator class which uses extended memory new/delete operators.
/*!
    Memory allocator class contains set of methods  which  help  to  allocate,
    create, initialize, delete and destroy type instances. All  those  methods
    can interact both with one type instance and with many ones (array of type
    instances).

    Allocation is the process when only memory for type instance is allocated.
    Note that in allocation process no class constructors are called.

    Creation is the complex process when both allocation  does  and  also  all
    class constructors are called.

    Initialize is the process when uninitialized allocated buffer is used  and
    then class constructors is called on it.

    Destroying is the process when all destructors are called with  no  meomry
    freeing.

    Deleting is the process when all allocated memory frees with  calling  all
    destructors.

    Freeing is the process when all allocated memory frees but no  destructors
    are called.
*/
class BASE_API CAllocatorNewEx :
  public IAllocator
{
  //! Type for the MConceptIAllocator constraint checking.
  typedef CAllocatorNewEx TAllocatorCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CAllocatorNewEx TDepthCheckType;

  // Check CAllocatorNewEx class constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CAllocatorNewEx class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  // IAllocator interface overriding methods.
  virtual Tptr allocate(const Tuint a_cSize);
  virtual Tbool free(Tptr a_pPointer);

public:
  //! Serialize CAllocatorNewEx class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CAllocatorNewEx class instances.
  /*!
      \param a_rInstance - Reference to another CAllocatorNewEx class instance.
  */
  void swap(CAllocatorNewEx& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/allocators/CAllocatorNewEx.inl>
/*==========================================================================*/
//! \example example-memory-CAllocatorNewEx.cpp
/*--------------------------------------------------------------------------*/
//! \test test-memory-CAllocatorNewEx.cpp
/*==========================================================================*/
#endif
