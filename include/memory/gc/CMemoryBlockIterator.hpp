/*!
 *  \file    CMemoryBlockIterator.hpp GC allocated memory blocks iterator
 *           definitions. It gives ability to enumerate all GC allocated
 *           memory blocks.
 *  \brief   Memory blocks iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory blocks iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   25.06.2007 22:47:17

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
#ifndef __CMEMORYBLOCKITERATOR_HPP__
#define __CMEMORYBLOCKITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/memory/gc/CMemoryBlockContainer.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
#if (defined(__CMEMORYBLOCKITERATOR_INCLUDED__) || defined(__DOXYGEN__))
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
//! Memory blocks iterator class.
/*!
    Memory blocks iterator represents GC allocated  memory  blocks  iterations
    method. With this iterator you  can  perform  looking  into  GC  allocated
    memory blocks.  Note  that  you  cannot  modify  memory  blocks  with  the
    iterator.

    Serialization: Memory blocks iterator cannot be loaded.
*/
class BASE_API CMemoryBlockIterator :
  public NCommon::NIterators::IIteratorConst<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>,
  public NCommon::NIterators::IIteratorMoveAssociative<CMemoryBlockIterator, Tcptr, CMemoryBlock, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>,
  public NCommon::NIterators::IIteratorMoveBackward<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>
{
  // Friend class: Memory blocks container class (CMemoryBlockContainer).
  friend class CMemoryBlockContainer;

  //! Type for MConceptDepthType constraint checking.
  typedef CMemoryBlockIterator TDepthCheckType;

  // Check CMemoryBlockIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator associative key type.
  typedef Tcptr TKey;
  //! Iterator associative value type.
  typedef CMemoryBlock TValue;

  //! Iterator value type.
  typedef CMemoryBlock TType;
  //! Iterator return type.
  typedef const CMemoryBlock TReturn;
  //! Iterator container type.
  typedef const CMemoryBlockContainer TContainer;
  //! Iterator base type.
  typedef CMemoryBlockIterator TIterator;

  //! Default class constructor.
  CMemoryBlockIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMemoryBlockIterator class.
  */
  CMemoryBlockIterator(const CMemoryBlockIterator& a_crInstance);
  //! Class virtual destructor.
  virtual ~CMemoryBlockIterator();

  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CMemoryBlockIterator& a_crInstance1, const CMemoryBlockIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CMemoryBlockIterator& a_crInstance1, const CMemoryBlockIterator& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CMemoryBlockIterator& operator = (const CMemoryBlockIterator& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CMemoryBlockIterator& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CMemoryBlockIterator& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CMemoryBlockIterator& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CMemoryBlockIterator& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CMemoryBlockIterator operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CMemoryBlockIterator operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CMemoryBlockIterator operator + (const CMemoryBlockIterator& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CMemoryBlockIterator operator - (const CMemoryBlockIterator& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Find iterator with given pointer to the memory block.
  /*!
      \param a_cpPointer - Constant pointer to the searching memory block.
      \return Iterator to the memory block with given pointer or invalid empty iterator.
  */
  CMemoryBlockIterator operator [] (const Tcptr& a_cpPointer) const;

  //! Set another CMemoryBlockIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMemoryBlockIterator class.
  */
  void set(const CMemoryBlockIterator& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CMemoryBlockIterator getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CMemoryBlockIterator getBackward() const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CMemoryBlockContainer& getContainerRef() const;
  virtual const CMemoryBlockContainer* getContainerPtr() const;
  virtual const CMemoryBlock& getValueRef() const;
  virtual const CMemoryBlock* getValuePtr() const;

  // IIteratorMoveAssociative interface overriding methods.
  virtual CMemoryBlockIterator find(const Tcptr& a_cpPointer) const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialization load CMemoryBlockIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CMemoryBlockIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CMemoryBlockIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMemoryBlockIterator class instances.
  /*!
      \param a_rInstance - Reference to another CMemoryBlockIterator class instance.
  */
  void swap(CMemoryBlockIterator& a_rInstance);

private:
  const CMemoryBlockContainer* m_cpContainer; //!< Constant pointer to the iterator container.
  const CMemoryBlock*          m_cpBlock;     //!< Constant pointer to the current memory block.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CMemoryBlockIterator(const CMemoryBlockContainer* a_cpContainer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* ITERATOR TRAITS SPECIALIZATION DECLARATIONS                              */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: memory blocks iterator's traits specialization.
template <>
class MTraitsIterator<NMemory::NGC::CMemoryBlockIterator> :
  public MType<NMemory::NGC::CMemoryBlockIterator>
{
public:
  //! Iterator value type.
  typedef NMemory::NGC::CMemoryBlockIterator::TType value;
  //! Iterator return type.
  typedef NMemory::NGC::CMemoryBlockIterator::TReturn result;
  //! Iterator container type.
  typedef NMemory::NGC::CMemoryBlockIterator::TContainer container;
  //! Iterator base type.
  typedef NMemory::NGC::CMemoryBlockIterator::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = true;  //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/gc/CMemoryBlockIterator.inl>
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
