/*!
 *  \file    CMemoryBlock.hpp GC memory block class. It describes one memory
 *           block and contains a pointer, an allocated size, and a place of
 *           allocation.
 *  \brief   GC memory block class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC memory block class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   20.06.2007 02:34:53

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
#ifndef __CMEMORYBLOCK_HPP__
#define __CMEMORYBLOCK_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
namespace NGC {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! GC memory block class.
/*!
    Garbage collection memory block. It contains a pointer, an allocated size,
    and a place of allocation. GC memory blocks are stored in a  solid  memory
    container and used to perform GC operation and to detect memory leaks.

    Serialization: GC memory block cannot be loaded.
*/
class BASE_API CMemoryBlock
{
  // Friend class: Static memory class (CMemory).
  friend class NDepth::NMemory::CMemory;

  //! Type for MConceptDepthType constraint checking.
  typedef CMemoryBlock TDepthCheckType;

  // Check CMemoryBlock class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CMemoryBlock();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMemoryBlock class.
  */
  CMemoryBlock(const CMemoryBlock& a_crInstance);
  //! Class destructor.
 ~CMemoryBlock();

  //! Operator: Equal to another CMemoryBlock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMemoryBlock class.
      \param a_crInstance2 - Constant reference to another instance of the CMemoryBlock class.
      \return true  - if CMemoryBlock class instance is equal to another one. \n
              false - if CMemoryBlock class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2);
  //! Operator: Not equal to another CMemoryBlock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMemoryBlock class.
      \param a_crInstance2 - Constant reference to another instance of the CMemoryBlock class.
      \return true  - if CMemoryBlock class instance is not equal to another one. \n
              false - if CMemoryBlock class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2);

  //! Operator: Less than another CMemoryBlock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMemoryBlock class.
      \param a_crInstance2 - Constant reference to another instance of the CMemoryBlock class.
      \return true  - if CMemoryBlock class instance is less than another one. \n
              false - if CMemoryBlock class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2);
  //! Operator: More than another CMemoryBlock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMemoryBlock class.
      \param a_crInstance2 - Constant reference to another instance of the CMemoryBlock class.
      \return true  - if CMemoryBlock class instance is more than another one. \n
              false - if CMemoryBlock class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2);
  //! Operator: Less or equal than another CMemoryBlock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMemoryBlock class.
      \param a_crInstance2 - Constant reference to another instance of the CMemoryBlock class.
      \return true  - if CMemoryBlock class instance is less or equal than another one. \n
              false - if CMemoryBlock class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2);
  //! Operator: More or equal than another CMemoryBlock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMemoryBlock class.
      \param a_crInstance2 - Constant reference to another instance of the CMemoryBlock class.
      \return true  - if CMemoryBlock class instance is more or equal than another one. \n
              false - if CMemoryBlock class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2);

  //! Operator: Assign another CMemoryBlock class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMemoryBlock class.
      \return Reference to the current class instance.
  */
  CMemoryBlock& operator = (const CMemoryBlock& a_crInstance);

  //! Set another CMemoryBlock class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMemoryBlock class.
  */
  void set(const CMemoryBlock& a_crInstance);

  //! Check if current memory block is a valid allocated GC memory block.
  /*!
      Method checks if current memory block is properly initialized and can be
      used to receive valid values from it.

      \return true  - if GC memory block is valid. \n
              false - if GC memory block is not valid. \n
  */
  Tbool isValid() const;

  //! Get allocated memory block pointer value.
  /*!
      \return Pointer value to the allocated memory block.
  */
  Tptr getPointer() const;
  //! Get allocated memory block size.
  /*!
      \return Allocated memory block size.
  */
  Tuint getSize() const;
  //! Get function name where the allocation was.
  /*!
      \return Function name where the allocation was.
  */
  Tcsstr getFunctionName() const;
  //! Get file name where the allocation was.
  /*!
      \return File name where the allocation was.
  */
  Tcstr getFileName() const;
  //! Get line number in file where allocation was.
  /*!
      \return Line number in file where allocation was.
  */
  Tuint getLine() const;

  //! Check if current memory block contains given pointer.
  /*!
      \param a_cpPointer - Constant checked pointer.
      \return true  - if GC memory block contains given pointer. \n
              false - if GC memory block does not contain given pointer. \n
  */
  Tbool contains(Tcptr a_cpPointer) const;

  //! Serialization load CMemoryBlock class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CMemoryBlock class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CMemoryBlock class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMemoryBlock class instances.
  /*!
      \param a_rInstance - Reference to another CMemoryBlock class instance.
  */
  void swap(CMemoryBlock& a_rInstance);

private:
  Tptr   m_pPointer;                    //!< Pointer to the allocated block of memory.
  Tuint  m_Size;                        //!< Size of the allocated memory block in bytes.
  Tcsstr m_cpFunctionName;              //!< Function name where the allocation was.
  Tcstr  m_cpFileName;                  //!< File name where the allocation was.
  Tuint  m_Line;                        //!< Line number in file where allocation was.

  bool   m_IsMarked;                    //!< Is memory block marked by the GC process?
  Tptr   m_pObjectPointer;              //!< Pointer to the constructed object.
  void   (*m_fObjectDestructor)(Tptr);  //!< Pointer to the object destructor function.

  //! Initialize GC memory block with a valid parameters.
  /*!
      Make constructor private to prevent of creation memory blocks outside of
      the CMemory class.

      \param a_pPointer - Pointer to the allocated memory block.
      \param a_cSize - Size of the allocated memory block.
      \param a_cpFunctionName - Function name where the allocation was.
      \param a_cpFileName - File name where the allocation was.
      \param a_cLine - Line number in file where the allocation was.
      \param a_cIsMarked - Block marker value (default is false).
  */
  CMemoryBlock(Tptr a_pPointer, const Tuint a_cSize, Tcsstr a_cpFunctionName, Tcstr a_cpFileName, const Tuint a_cLine, const Tbool a_cIsMarked = false);

  //! Update GC memory block.
  /*!
      Make updated GC memory block with instance of the constructed object and
      object destroy function.

      \param a_pObjectPointer - Pointer to the object instance.
      \param a_fObjectDestructor - Object destructor function.
      \return true  - if memory block was successfully updated. \n
              false - if memory block was not been successfully update. \n
  */
  Tbool update(Tptr a_pObjectPointer, void (*a_fObjectDestructor)(Tptr));
  //! Release GC memory block.
  /*!
      Make releases GC memory block by calling object  destroy  function  with
      the pointer to the constructed object.
      \return true  - if memory block was successfully released. \n
              false - if memory block was not been successfully released. \n
  */
  Tbool release();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/gc/CMemoryBlock.inl>
/*==========================================================================*/
#endif
