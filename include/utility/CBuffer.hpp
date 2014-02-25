/*!
 *  \file    CBuffer.hpp Byte buffer container class provides random access
 *           to the static/dynamic byte buffer.
 *  \brief   Byte buffer container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   20.08.2008 23:35:51

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
#ifndef __CBUFFER_HPP__
#define __CBUFFER_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IRandom.hpp>
#include <Depth/include/common/containers/IRandomConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
class CBufferIterator;
class CBufferIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Byte buffer container class.
/*!
    Byte buffer container class provides random access functionality to access
    static/dynamic byte buffer.

    When the byte buffer is dynamic (created from the initial buffer size), it
    could be manually resized.

    When the byte buffer is static (created from the  given  buffer  of  fixed
    size), its size is constant and the buffer cannot be resized.
*/
class BASE_API CBuffer :
  public NCommon::NContainers::IRandom<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>,
  public NCommon::NContainers::IRandomConst<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>
{
  // Friend class: Byte buffer iterator class (CBufferIterator).
  friend class NDepth::NUtility::NIterators::CBufferIterator;
  // Friend class: Constant byte buffer iterator class (CBufferIteratorConst).
  friend class NDepth::NUtility::NIterators::CBufferIteratorConst;

  //! Type for the MConceptDepthType constraint checking.
  typedef CBuffer TDepthCheckType;

  // Check CBuffer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef Tbyte TType;
  //! Container type.
  typedef CBuffer TContainer;
  //! Non constant byte buffer iterator type.
  typedef CBufferIterator TIterator;
  //! Constant byte buffer iterator type.
  typedef CBufferIteratorConst TIteratorConst;

  //! Default class constructor. Initialize dynamic or static byte buffer of fixed size.
  /*!
      Creates dynamic or static byte buffer with the given size.

      \param a_cSize - Initial size of the dynamic or static byte buffer in bytes (default is 0).
      \param a_cStatic - Static buffer flag (default is false).
  */
  CBuffer(const Tuint a_cSize = 0, const Tbool a_cStatic = false);
  //! Initialize dynamic or static byte buffer from the given buffer of fixed size.
  /*!
      Creates dynamic or static byte buffer from the  given  buffer  of  fixed
      size. Given byte buffer will be copied to the created one.

      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is false).
  */
  CBuffer(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic = false);
  //! Initialize dynamic or static byte buffer from the given buffer of fixed size.
  /*!
      Creates dynamic or static byte buffer from the  given  buffer  of  fixed
      size. If the static flag is not set, dynamic buffer will be created  and
      the given buffer will be copied into it.  Otherwise  given  byte  buffer
      will be copied to the dynamically created one.

      \param a_pBuffer - Pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is true).
  */
  CBuffer(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic = true);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBuffer class.
  */
  CBuffer(const CBuffer& a_crInstance);
  //! Class virtual destructor.
  virtual ~CBuffer();

  //! Operator: Assign another CBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBuffer class.
      \return Reference to the current class instance.
  */
  CBuffer& operator = (const CBuffer& a_crInstance);

  //! Operator: Indexing into the non constant byte buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to the byte under the given index.
  */
  Tbyte& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the non constant byte buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to the byte under the given index.
  */
  Tbyte& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the constant byte buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to the byte under the given index.
  */
  const Tbyte& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the constant byte buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to the byte under the given index.
  */
  const Tbyte& operator [] (const Tuint a_cIndex) const;

  //! Operator: Get pointer to the byte buffer.
  /*!
      \return Pointer to the byte buffer.
      \see NDepth::NUtility::CBuffer::getBuffer()
  */
  operator Tbuffer ();
  //! Operator: Get constant pointer to the byte buffer.
  /*!
      \return Constant pointer to the byte buffer.
      \see NDepth::NUtility::CBuffer::getBuffer()
  */
  operator Tcbuffer () const;

  //! Set dynamic or static byte buffer of fixed size.
  /*!
      Prepare dynamic or static byte buffer with the given size.

      \param a_cSize - Initial size of the dynamic or static byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is false).
      \return true  - if byte buffer was successfully set. \n
              false - if byte buffer was not successfully set. \n
  */
  Tbool set(const Tuint a_cSize, const Tbool a_cStatic = false);
  //! Set dynamic or static byte buffer from the given buffer of fixed size.
  /*!
      Prepare dynamic or static byte buffer from the  given  buffer  of  fixed
      size. Given byte buffer will be copied to the created one.

      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is false).
      \return true  - if byte buffer was successfully set. \n
              false - if byte buffer was not successfully set. \n
  */
  Tbool set(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic = false);
  //! Set dynamic or static byte buffer from the given buffer of fixed size.
  /*!
      Prepare dynamic or static byte buffer from the  given  buffer  of  fixed
      size. If the static flag is not set, dynamic buffer will be created  and
      the given buffer will be copied into it.  Otherwise  given  byte  buffer
      will be copied to the dynamically created one.

      \param a_pBuffer - Pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is true).
      \return true  - if byte buffer was successfully set. \n
              false - if byte buffer was not successfully set. \n
  */
  Tbool set(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic = true);
  //! Set another CBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBuffer class.
      \return true  - if another byte buffer was successfully set. \n
              false - if another byte buffer was not successfully set. \n
  */
  Tbool set(const CBuffer& a_crInstance);

  //! Is byte buffer dynamic?
  /*!
      \return true  - if byte buffer is dynamic. \n
              false - if byte buffer is static. \n
  */
  Tbool isDynamic() const;
  //! Is byte buffer local?
  /*!
      \return true  - if byte buffer is local. \n
              false - if byte buffer is local. \n
  */
  Tbool isLocal() const;
  //! Is byte buffer static?
  /*!
      \return true  - if byte buffer is static. \n
              false - if byte buffer is dynamic. \n
  */
  Tbool isStatic() const;

  //! Get byte buffer free size.
  /*!
      Method returns count of free bytes in the byte buffer.

      \return Count of free bytes in the byte buffer.
  */
  Tuint getFreeSize() const;

  //! Get byte buffer lower capacity bound value.
  /*!
      Method returns lower bound size value before byte buffer reallocation.

      \return Byte buffer lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get byte buffer higher capacity bound value.
  /*!
      Method returns higher bound size value before byte buffer reallocation.

      \return Byte buffer higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Get ponter to the byte buffer.
  /*!
      Method returns pointer to the byte buffer.  Using  of  this  pointer  is
      quite dangerous cause it may lead to memory  errors.  That  is  why  you
      always have to check buffer bounds while working with this pointer.

      \return Pointer to the byte buffer.
  */
  Tbuffer getBuffer();
  //! Get constant ponter to the byte buffer.
  /*!
      Method returns constant pointer  to  the  byte  buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to check  buffer  bounds  while  working  with  this
      pointer.

      \return Constant pointer to the byte buffer.
  */
  Tcbuffer getBuffer() const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IRandom interface overriding methods.
  virtual Tbool insertFirst(const Tbyte& a_crItem);
  virtual Tbool insertFirst(const CBuffer& a_crItem);
  virtual Tbool insertLast(const Tbyte& a_crItem);
  virtual Tbool insertLast(const CBuffer& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const Tbyte& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const CBuffer& a_crItem);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(Tbyte& a_rItem);
  virtual Tbool removeFirst(const Tuint a_cSize);
  virtual Tbool removeFirst(const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool removeLast();
  virtual Tbool removeLast(Tbyte& a_rItem);
  virtual Tbool removeLast(const Tuint a_cSize);
  virtual Tbool removeLast(const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, Tbyte& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Resize byte buffer to the given size.
  /*!
      Method updates byte buffer to the given size.

      \param a_cSize - New byte buffer size in bytes.
      \param a_cValue - Initialize value (default is 0).
      \return true  - if byte buffer was successfully resized. \n
              false - if byte buffer was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize, const Tbyte a_cValue = 0);
  //! Resize byte buffer by given size.
  /*!
      Method updates byte buffer by adding/removing given size.

      \param a_cSize - Additional byte buffer size in bytes (may be less than 0).
      \param a_cValue - Initialize value (default is 0).
      \return true  - if byte buffer was successfully resized. \n
              false - if byte buffer was not successfully resized. \n
  */
  Tbool resizeBy(const Tsint a_cSize, const Tbyte a_cValue = 0);

  //! Serialization load CBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBuffer class instances.
  /*!
      \param a_rInstance - Reference to another CBuffer class instance.
  */
  void swap(CBuffer& a_rInstance);

private:
  Tbool   m_IsDynamic;                  //!< Is byte buffer dynamic?
  Tbool   m_IsLocal;                    //!< Is byte buffer is local and need to be deleted?
  Tuint   m_Size;                       //!< Byte buffer size.
  Tuint   m_HiCapacity;                 //!< Byte buffer higher capacity bound.
  Tbuffer m_pBuffer;                    //!< Byte buffer buffer.
};
/*==========================================================================*/
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
//! Traits meta-class: byte buffer container traits specialization.
template <>
class MTraitsContainer<NUtility::CBuffer> :
  public MType<NUtility::CBuffer>
{
public:
  //! Container value type.
  typedef NUtility::CBuffer::TType value;
  //! Container type.
  typedef NUtility::CBuffer::TContainer container;
  //! Container non constant iterator type.
  typedef NUtility::CBuffer::TIterator iterator;
  //! Container constant iterator type.
  typedef NUtility::CBuffer::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = true;  //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = true;  //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = true;  //!< Is container non constant random?
  static const Tbool isRandomConst      = true;  //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = false; //!< Is container constant associative?
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
#include <Depth/include/utility/iterators/CBufferIterator.hpp>
#include <Depth/include/utility/iterators/CBufferIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/utility/CBuffer.inl>
/*==========================================================================*/
//! \example example-utility-CBuffer.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-CBuffer.cpp
/*==========================================================================*/
#endif
