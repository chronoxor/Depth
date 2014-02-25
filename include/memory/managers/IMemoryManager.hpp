/*!
 *  \file    IMemoryManager.hpp Memory manager interface provides common
 *           memory management definitions of the memory allocation,
 *           reallocation and free functionality.
 *  \brief   Memory manager interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory manager interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory managers
    VERSION:   1.0
    CREATED:   28.06.2007 03:58:34

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
#ifndef __IMEMORYMANAGER_HPP__
#define __IMEMORYMANAGER_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS IN OTHER NAMESPACE                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
class CMemory;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NManagers {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Memory manager interface.
/*!
    Memory manager interface is a  base  interface  for  all  concrete  memory
    managers.  It  declares  common  memory  allocation  routines,   such   as
    allocation, reallocation and free operations. Note  that  memory  managers
    functionality cannot be invoked directly, only  CMemory  static  class  is
    granted to use them.
*/
class BASE_API IMemoryManager
{
  // Friend class: Static memory class (CMemory).
  friend class NDepth::NMemory::CMemory;

protected:
  //! Default interface protected constructor.
  IMemoryManager();

  //! Allocate new memory buffer.
  /*!
      Method is used to allocate memory buffer. It should  be  implemented  by
      the concrete memory manager. This  method  is  only  for  usage  in  the
      CMemory static class.

      \param a_cSize - Size of allocated buffer in bytes.
      \return Pointer to new allocated buffer of NULL if failed.
  */
  virtual Tptr allocate(const Tuint a_cSize) = 0;
  //! Reallocate existent memory buffer.
  /*!
      Method is used to reallocate existent memory buffer.  If  memory  buffer
      cannot be reallocated, a pointer to the new one is returned.  It  should
      be implemented by the concrete memory manager. This method is  only  for
      usage in the CMemory static class.

      \param a_pPointer - Pointer to old buffer.
      \param a_cSize - Size of new buffer in bytes.
      \return Pointer to reallocated buffer of NULL if failed.
  */
  virtual Tptr reallocate(Tptr a_pPointer, const Tuint a_cSize) = 0;
  //! Free memory buffer.
  /*!
      Method is used to free memory buffer. It should be  implemented  by  the
      concrete memory manager. This method is only for usage  in  the  CMemory
      static class.

      \param a_pPointer - Pointer to buffer.
      \return true  - if the memory buffer was successfully freed. \n
              false - if the memory buffer was not successfully freed. \n
  */
  virtual Tbool free(Tptr a_pPointer) = 0;

public:
  //! Interface virtual destructor.
  virtual ~IMemoryManager();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/managers/IMemoryManager.inl>
/*==========================================================================*/
#endif
