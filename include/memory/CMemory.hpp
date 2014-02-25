/*!
 *  \file    CMemory.hpp Static memory class gives a set of memory allocation
 *           routines and memory manipulation utilities.
 *  \brief   Static memory class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static memory class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory
    VERSION:   1.0
    CREATED:   21.01.2006 01:15:21

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
#ifndef __CMEMORY_HPP__
#define __CMEMORY_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/process/CRWLock.hpp>
#include <Depth/include/process/CScopeReader.hpp>
#include <Depth/include/process/CScopeWriter.hpp>
#include <Depth/include/memory/managers/IMemoryManager.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NGC {
/*--------------------------------------------------------------------------*/
class CMemoryBlock;
class CMemoryBlockContainer;
class CMemoryBlockIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type>
class CGCPtr;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NGC;
using namespace NManagers;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static memory class.
/*!
    Memory class implements memory allocation routines. It givers  ability  to
    use memory managers for allocating blocks of memory.  Per  default  memory
    class is using system memory manager. If you  need,  you  can  change  the
    default memory manager with your own version.

    Important: When the memory manager is changed, do not  forget  to  restore
    the previous one after the work is done. All memory blocks allocated  with
    old manager must be freed with it. Do not mix old allocation and new  free
    operations.

    If garbage collection (GC) is  enabled  all  information  about  allocated
    memory blocks are stored inside the GC engine.  It  helps  to  perform  GC
    operation and to detect memory leaks. GC engine  can  be  enabled  by  the
    'enableGC()' method call. GC engine can be disabled by  the  'disableGC()'
    method call. Enable/Disable operations invoke garbage collection.

    GC is based on the Mark & Sweep algorithm, which was  adapted  to  C++  by
    William E. Kempf. For more information follow the links:
    1) A garbage collection framework for C++
       http://www.codeproject.com/cpp/garbage_collect.asp
    2) A garbage collection framework for C++ - Part II
       http://www.codeproject.com/cpp/garbage_collect2.asp

    Static memory class also a has set  of  utility  methods  which  helps  to
    manipulate blocks of memory.
*/
class BASE_API CMemory :
  public NDepth::NCommon::IStatic
{
  // Friend class: GC memory blocks container class (CMemoryBlockContainer).
  friend class NDepth::NMemory::NGC::CMemoryBlockContainer;
  // Friend class: GC memory blocks iterator class (CMemoryBlockIterator).
  friend class NDepth::NMemory::NGC::CMemoryBlockIterator;
  // Friend class: GC smart pointer class (CGCPtr).
  template <typename T_Type>
  friend class NDepth::NMemory::NGC::CGCPtr;

public:
  //! Is garbage collection enabled?
  /*!
      \return true  - if garbage collection is enabled. \n
              false - if garbage collection is disabled. \n
  */
  static Tbool isGCEnabled();

  //! Enable garbage collection.
  /*!
      Method enables GC and performs initial garbage collection operation.

      \return true  - if garbage collection was successfully enabled. \n
              false - if garbage collection was not successfully enabled. \n
  */
  static Tbool enableGC();
  //! Disable garbage collection.
  /*!
      Method disables GC and performs final garbage collection operation.

      \return true  - if garbage collection was successfully disabled. \n
              false - if garbage collection was not successfully disabled. \n
  */
  static Tbool disableGC();

  //! Perform a garbage collection.
  /*!
      \return true  - if garbage collection was successfully performed. \n
              false - if garbage collection was not successfully performed. \n
  */
  static Tbool performGC();

  //! Get GC allocated memory size.
  /*!
      \return Allocated memory size in GC mode.
  */
  static Tuint getGCAllocatedSize();
  //! Get count of GC allocated memory blocks.
  /*!
      \return Count of allocated memory blocks in GC mode.
  */
  static Tuint getGCAllocatedBlocks();

  //! Allocate new buffer from memory pool.
  /*!
      \param a_cSize - Size of allocated buffer in bytes.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to new allocated buffer of NULL if failed.
  */
  static Tptr allocate(const Tuint a_cSize, Tcsstr a_cpFunctionSignature = ASC(""), Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);
  //! Allocate new buffer from memory pool. Buffer initialized to zero.
  /*!
      \param a_cSize - Size of allocated buffer in bytes.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to new allocated buffer of NULL if failed.
  */
  static Tptr allocateZero(const Tuint a_cSize, Tcsstr a_cpFunctionSignature = ASC(""), Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);
  //! Allocate new buffer from memory pool. Buffer initialized to zero.
  /*!
      \param a_cOneElementSize - Size of one element in allocated buffer in bytes.
      \param a_cElementsCount - Count of elements in allocated buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to new allocated buffer of NULL if failed.
  */
  static Tptr allocateZero(const Tuint a_cOneElementSize, const Tuint a_cElementsCount, Tcsstr a_cpFunctionSignature = ASC(""), Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);
  //! Reallocate buffer.
  /*!
      \param a_pPointer - Pointer to old buffer.
      \param a_cSize - Size of new buffer in bytes.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory reallocation (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory reallocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory reallocation (default is 0).
      \return Pointer to reallocated buffer of NULL if failed.
  */
  static Tptr reallocate(Tptr a_pPointer, const Tuint a_cSize, Tcsstr a_cpFunctionSignature = ASC(""), Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);
  //! Free buffer.
  /*!
      \param a_pPointer - Pointer to buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory reallocation (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory reallocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory reallocation (default is 0).
      \return true  - if buffer was successfully freed. \n
              false - if buffer was not successfully freed. \n
  */
  static Tbool free(Tptr a_pPointer, Tcsstr a_cpFunctionSignature = ASC(""), Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);

  //! Allocate aligned buffer from memory pool.
  /*!
      \param a_cSize - Size of allocated buffer in bytes.
      \param a_cAlign - Alignment value (must be an integer power of 2).
      \param a_cOffset - Left offset from align bound (default is 0).
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to new allocated aligned buffer of NULL if failed.
  */
  static Tptr allocateAligned(const Tuint a_cSize, const Tuint a_cAlign, const Tuint a_cOffset = 0, Tcsstr a_cpFunctionSignature = ASC(""), Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);
  //! Free aligned buffer.
  /*!
      \param a_pPointer - Pointer to aligned buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory reallocation (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory reallocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory reallocation (default is 0).
      \return true  - if aligned buffer was successfully freed. \n
              false - if aligned buffer was not successfully freed. \n
  */
  static Tbool freeAligned(Tptr a_pPointer, Tcsstr a_cpFunctionSignature = ASC(""), Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);

  //! Set new memory manager.
  /*!
      Replace the current memory manager with a new one.

      Important: When the memory manager is changed, do not forget to  restore
      the previous one after the work is done.  All  memory  blocks  allocated
      with old manager must be freed with it. Do not mix  old  allocation  and
      new free operations.

      \param a_pMemoryManager - Pointer to the new memory manager instance.
      \return true  - if the current memory manager was successfully changed. \n
              false - if the current memory manager was not successfully changed. \n
  */
  static Tbool setMemoryManager(IMemoryManager* a_pMemoryManager);
  //! Get current memory manager instance.
  /*!
      \return Pointer to the current memory manager instance.
  */
  static IMemoryManager* getMemoryManager();
  //! Restore default system memory manager.
  static void restoreDefaultMemoryManager();

  //! Compare two memory blocks with fixed length.
  /*!
      Compare starts from first byte  of  both  blocks.  Method  compares  two
      current bytes. If they are equal then takes  next  bytes.  If  they  are
      different then immediately returns their difference.

      \param a_cpFirst - Constant pointer to first memory block.
      \param a_cpSecond - Constant pointer to second memory block.
      \param a_cSize - Size of compared blocks in bytes.
      \return One of the following values: \n
              <0 - if first block less than second block. \n
              =0 - if first block equals to second block. \n
              >0 - if first block greater than second block. \n
  */
  static Tsint compare(Tcptr a_cpFirst, Tcptr a_cpSecond, const Tuint a_cSize);
  //! Inverse compare two memory blocks with fixed length.
  /*!
      Compare starts from first byte of first block  and  from  last  byte  of
      second block. Method compares two current bytes. If they are equal  then
      takes next bytes. If they are different then immediately  returns  their
      difference.

      \param a_cpFirst - Constant pointer to first memory block.
      \param a_cpSecond - Constant pointer to second memory block.
      \param a_cSize - Size of compared blocks in bytes.
      \return One of the following values: \n
              <0 - if first block less than second block. \n
              =0 - if first block equals to second block. \n
              >0 - if first block greater than second block. \n
  */
  static Tsint compareInverse(Tcptr a_cpFirst, Tcptr a_cpSecond, const Tuint a_cSize);
  //! Reverse compare two memory blocks with fixed length.
  /*!
      Compare starts from last  byte  of  both  blocks.  Method  compares  two
      current bytes. If they are equal then takes  next  bytes.  If  they  are
      different then immediately returns their difference.

      \param a_cpFirst - Constant pointer to first memory block.
      \param a_cpSecond - Constant pointer to second memory block.
      \param a_cSize - Size of compared blocks in bytes.
      \return One of the following values: \n
              <0 - if first block less than second block. \n
              =0 - if first block equals to second block. \n
              >0 - if first block greater than second block. \n
  */
  static Tsint compareReverse(Tcptr a_cpFirst, Tcptr a_cpSecond, const Tuint a_cSize);

  //! Copy one block of memory to another.
  /*!
      Method copy one memory block to another one. It copies  bytes  from  the
      begin to the end of block. Note that if two blocks are overlapped,  then
      this overlapped region could be overwritten.  To  avoid  it  use  'move'
      method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cSize - Size of copied blocks in bytes.
  */
  static void copy(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize);
  //! Reverse copy one block of memory to another.
  /*!
      Method copy one memory block to another one. It copies  bytes  from  the
      end to the begin of block. Note that if two blocks are overlapped,  then
      this  overlapped  region  could  be  overwritten.  To   avoid   it   use
      'moveReverse' method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cSize - Size of copied blocks in bytes.
  */
  static void copyReverse(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize);

  //! Move one block of memory to another.
  /*!
      Method copy one memory block to another one. It copies  bytes  from  the
      begin to the end of block. Note that if two blocks are overlapped,  then
      this overlapped region could not be overwritten. This is safe method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cSize - Size of moved blocks in bytes.
  */
  static void move(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize);
  //! Reverse move one block of memory to another.
  /*!
      Method copy one memory block to another one. It copies  bytes  from  the
      end to the begin of block. Note that if two blocks are overlapped,  then
      this overlapped region could not be overwritten. This is safe method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cSize - Size of moved blocks in bytes.
  */
  static void moveReverse(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize);

  //! Fill block of memory with the given byte value.
  /*!
      \param a_pBlock - Pointer to memory block.
      \param a_cSize - Size of filled blocks in bytes.
      \param a_cValue - Filled byte value.
  */
  static void fill(Tptr a_pBlock, const Tuint a_cSize, const Tbyte a_cValue);
  //! Fill block of memory with the given value from buffer.
  /*!
      \param a_pBlock - Pointer to memory block.
      \param a_cSize - Size of filled blocks in bytes.
      \param a_cpValueBuffer - Constant pointer to the filled value buffer.
      \param a_cValueSize - Size of filled value buffer in bytes.
  */
  static void fill(Tptr a_pBlock, const Tuint a_cSize, Tcptr a_cpValueBuffer, const Tuint a_cValueSize);
  //! Fill block of memory with zero value.
  /*!
      \param a_pBlock - Pointer to memory block.
      \param a_cSize - Size of moved blocks in bytes.
  */
  static void zero(Tptr a_pBlock, const Tuint a_cSize);

  //! XOR block of memory with fixed mask.
  /*!
      Method applies 'exclusive or' operation to memory block and a mask.

      \param a_pBlock - Pointer to memory block.
      \param a_cpMask - Constant pointer to mask memory block.
      \param a_cSize - Size of moved blocks in bytes.
  */
  static void xorMask(Tptr a_pBlock, Tcptr a_cpMask, const Tuint a_cSize);
  //! XOR block of memory with fixed mask.
  /*!
      Method applies 'exclusive or' operation to memory block and a mask.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cpMask - Constant pointer to mask memory block.
      \param a_cSize - Size of moved blocks in bytes.
  */
  static void xorMask(Tptr a_pDestination, Tcptr a_cpSource, Tcptr a_cpMask, const Tuint a_cSize);

private:
  static Tbool ms_isGCEnabled;          //!< Memory GC enabled flag.
  static Tuint ms_GCAllocatedSize;      //!< Allocated memory size in GC mode.
  static Tuint ms_GCAllocatedBlocks;    //!< Count of allocated memory blocks in GC mode.

  static IMemoryManager* ms_pMemoryManager; //!< Pointer to the current memory manager instance.

  // Synchronization objects.
  static NProcess::CRWLock ms_GCEnabledLocker;     //!< Memory GC enabled reader/writer locker.
  static NProcess::CRWLock ms_GCPerformLocker;     //!< Memory GC perform reader/writer locker.
  static NProcess::CRWLock ms_GCRegisterLocker;    //!< Memory GC register reader/writer locker.
  static NProcess::CRWLock ms_MemoryManagerLocker; //!< Memory manager reader/writer locker.

  //! Recursive mark all allocated memory blocks for the given root memory block.
  /*!
      \param a_pRootMemoryBlock - Pointer to the root memory block.
  */
  static void mark(Tptr a_pRootMemoryBlock);

  //! Register new GC smart pointer.
  /*!
      \param a_pGCPointer - Pointer to the GC smart pointer.
      \return true  - if GC smart pointer was successfully registered. \n
              false - if GC smart pointer was not successfully registered. \n
  */
  static Tbool registerGCPointer(Tptr a_pGCPointer);
  //! Unregister existent GC smart pointer.
  /*!
      \param a_pGCPointer - Pointer to the GC smart pointer.
      \return true  - if GC smart pointer was successfully unregistered. \n
              false - if GC smart pointer was not successfully unregistered. \n
  */
  static Tbool unregisterGCPointer(Tptr a_pGCPointer);
  //! Update existent GC smart pointer.
  /*!
      Method updates existent GC smart pointer with an object instance and  an
      object destructor function.

      \param a_pGCPointer - Pointer to the GC smart pointer.
      \param a_pObjectPointer - Pointer to the object instance.
      \param a_fObjectDestructor - Object destructor function.
      \return true  - if GC smart pointer was successfully updated. \n
              false - if GC smart pointer was not successfully updated. \n
  */
  static Tbool updateGCPointer(Tptr a_pGCPointer, Tptr a_pObjectPointer, void (*a_fObjectDestructor)(Tptr));

  //! Get constant pointer to the first GC allocated memory block.
  /*!
      \return Constant pointer to the first GC allocated memory block.
  */
  static const CMemoryBlock* getFirstGCBlock();
  //! Get constant pointer to the last GC allocated memory block.
  /*!
      \return Constant pointer to the last GC allocated memory block.
  */
  static const CMemoryBlock* getLastGCBlock();
  //! Get constant pointer to the previous GC allocated memory block.
  /*!
      \param a_cpGCBlock - Constant pointer to the GC allocated memory block.
      \return Constant pointer to the previous GC allocated memory block.
  */
  static const CMemoryBlock* getPrevGCBlock(const CMemoryBlock* a_cpGCBlock);
  //! Get constant pointer to the next GC allocated memory block.
  /*!
      \param a_cpGCBlock - Constant pointer to the GC allocated memory block.
      \return Constant pointer to the next GC allocated memory block.
  */
  static const CMemoryBlock* getNextGCBlock(const CMemoryBlock* a_cpGCBlock);
  //! Get constant pointer to the GC allocated memory block which contains given pointer value.
  /*!
      \param a_cpPointer - Constant pointer to search.
      \return Constant pointer to the GC allocated memory block which contains given pointer value.
  */
  static const CMemoryBlock* getGCBlockByPointer(Tcptr a_cpPointer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/CMemory.inl>
/*==========================================================================*/
//! \example example-memory-CMemory.cpp
/*--------------------------------------------------------------------------*/
//! \test test-memory-CMemory.cpp
/*==========================================================================*/
#endif
