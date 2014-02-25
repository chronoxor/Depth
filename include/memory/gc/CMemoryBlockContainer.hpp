/*!
 *  \file    CMemoryBlockContainer.hpp GC allocated memory blocks container
 *           class.
 *  \brief   GC allocated memory blocks container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC allocated memory blocks container class.

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
#ifndef __CMEMORYBLOCKCONTAINER_HPP__
#define __CMEMORYBLOCKCONTAINER_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IAssociativeConst.hpp>
#include <Depth/include/common/containers/IDequeConst.hpp>
#include <Depth/include/memory/gc/CMemoryBlock.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
class CMemoryBlockIterator;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! GC allocated memory blocks container class.
/*!
    GC allocated memory blocks container represents an allocated memory blocks
    collection. It gives ability to receive iterators to the memory blocks. It
    can be used in various container algorithms.

    Serialization: GC allocated memory blocks container cannot be loaded.
*/
class BASE_API CMemoryBlockContainer :
  public NCommon::NContainers::IAssociativeConst<CMemoryBlockContainer, Tcptr, CMemoryBlock, CMemoryBlock, CMemoryBlockIterator, CMemoryBlockIterator>,
  public NCommon::NContainers::IDequeConst<CMemoryBlockContainer, CMemoryBlock, CMemoryBlockIterator, CMemoryBlockIterator>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CMemoryBlockContainer TDepthCheckType;

  // Check CMemoryBlockContainer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef Tcptr TKey;
  //! Container associative value type.
  typedef CMemoryBlock TValue;

  //! Container value type.
  typedef CMemoryBlock TType;
  //! Container type.
  typedef CMemoryBlockContainer TContainer;
  //! Non constant set iterator type.
  typedef CMemoryBlockIterator TIterator;
  //! Constant set iterator type.
  typedef CMemoryBlockIterator TIteratorConst;

  //! Default class constructor.
  CMemoryBlockContainer();
  //! Class virtual destructor.
  virtual ~CMemoryBlockContainer();

  //! Operator: Return non constant iterator to the memory block with given pointer.
  /*!
      \param a_cpPointer - Constant pointer to the searching memory block.
      \return Non constant iterator to the memory block with given pointer or invalid empty iterator.
  */
  TIterator operator [] (const Tcptr& a_cpPointer);
  //! Operator: Return constant iterator to the memory block with given pointer.
  /*!
      \param a_cpPointer - Constant pointer to the searching memory block.
      \return Constant iterator to the memory block with given pointer or invalid empty iterator.
  */
  TIteratorConst operator [] (const Tcptr& a_cpPointer) const;

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const Tcptr& a_cpPointer1, const Tcptr& a_cpPointer2) const;
  virtual TIterator      find(const Tcptr& a_cpPointer);
  virtual TIteratorConst find(const Tcptr& a_cpPointer) const;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Serialization load CMemoryBlockContainer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CMemoryBlockContainer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CMemoryBlockContainer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMemoryBlockContainer class instances.
  /*!
      \param a_rInstance - Reference to another CMemoryBlockContainer class instance.
  */
  void swap(CMemoryBlockContainer& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: GC allocated memory blocks container traits specialization.
template <>
class MTraitsContainer<NMemory::NGC::CMemoryBlockContainer> :
  public MType<NMemory::NGC::CMemoryBlockContainer>
{
public:
  //! Container value type.
  typedef NMemory::NGC::CMemoryBlockContainer::TType value;
  //! Container type.
  typedef NMemory::NGC::CMemoryBlockContainer::TContainer container;
  //! Container non constant iterator type.
  typedef NMemory::NGC::CMemoryBlockContainer::TIterator iterator;
  //! Container constant iterator type.
  typedef NMemory::NGC::CMemoryBlockContainer::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = true;  //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#if (!defined(__CMEMORYBLOCKITERATOR_INCLUDED__))
#define __CMEMORYBLOCKITERATOR_INCLUDED__
/*--------------------------------------------------------------------------*/
#undef __CMEMORYBLOCKITERATOR_HPP__
#include <Depth/include/memory/gc/CMemoryBlockIterator.hpp>
/*--------------------------------------------------------------------------*/
#undef __CMEMORYBLOCKITERATOR_INCLUDED__
#endif
/*--------------------------------------------------------------------------*/
#include <Depth/include/memory/gc/CMemoryBlockContainer.inl>
/*==========================================================================*/
#endif
