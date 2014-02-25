/*!
 *  \file    CBufferIterator.hpp Byte buffer non constant iterator
 *           definitions. It gives ability to get and modify single
 *           bytes inside the byte buffer and to do random moving
 *           through the bytes.
 *  \brief   Byte buffer non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   20.08.2008 01:19:57

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
#ifndef __CBUFFERITERATOR_HPP__
#define __CBUFFERITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertRandom.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveRandom.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
#include <Depth/include/utility/CBuffer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Byte buffer non constant iterator class.
/*!
    Byte buffer  non  constant  iterator  represents  byte  buffer  iterations
    method. With this iterator you can perform  random  moving  and  modifying
    bytes inside the byte buffer.
*/
class BASE_API CBufferIterator :
  public NCommon::NIterators::IIterator<CBufferIterator, Tbyte, Tbyte, CBuffer>,
  public NCommon::NIterators::IIteratorMoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>,
  public NCommon::NIterators::IIteratorInsertRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>,
  public NCommon::NIterators::IIteratorRemoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>,
  public NCommon::ISeekable
{
  // Friend class: Byte buffer class (CBuffer).
  friend class NDepth::NUtility::CBuffer;
  // Friend class: Byte buffer constant iterator class (CBufferIteratorConst).
  friend class NDepth::NUtility::NIterators::CBufferIteratorConst;

  //! Type for MConceptDepthType constraint checking.
  typedef CBufferIterator TDepthCheckType;

  // Check CBufferIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef Tbyte TType;
  //! Iterator return type.
  typedef Tbyte TReturn;
  //! Iterator container type.
  typedef CBuffer TContainer;
  //! Iterator base type.
  typedef CBufferIterator TIterator;

  //! Default class constructor.
  CBufferIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBufferIterator class.
  */
  CBufferIterator(const CBufferIterator& a_crInstance);
  //! Class virtual destructor.
  virtual ~CBufferIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CBufferIterator& a_crInstance1, const CBufferIteratorConst& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CBufferIteratorConst& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CBufferIterator& a_crInstance1, const CBufferIteratorConst& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CBufferIteratorConst& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2);

  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CBufferIterator& a_crInstance1, const CBufferIteratorConst& a_crInstance2);
  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CBufferIteratorConst& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CBufferIterator& a_crInstance1, const CBufferIteratorConst& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CBufferIteratorConst& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CBufferIterator& a_crInstance1, const CBufferIteratorConst& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CBufferIteratorConst& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CBufferIterator& a_crInstance1, const CBufferIteratorConst& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CBufferIteratorConst& a_crInstance1, const CBufferIterator& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CBufferIterator& operator = (const CBufferIterator& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CBufferIterator& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CBufferIterator& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CBufferIterator& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CBufferIterator& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CBufferIterator operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CBufferIterator operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CBufferIterator operator + (const CBufferIterator& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CBufferIterator operator - (const CBufferIterator& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new byte buffer non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed byte buffer position to return.
      \return Byte buffer non constant iterator under the given index.
  */
  CBufferIterator operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new byte buffer non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed byte buffer position to return.
      \return Byte buffer non constant iterator under the given index.
  */
  CBufferIterator operator [] (const Tuint a_cIndex) const;

  //! Set another CBufferIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBufferIteratorConst class.
  */
  void set(const CBufferIterator& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CBufferIterator getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CBufferIterator getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CBufferIterator getIndex(const Tuint a_cIndex) const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CBuffer& getContainerRef() const;
  virtual CBuffer* getContainerPtr() const;
  virtual Tbyte& getValueRef() const;
  virtual Tbyte* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // IIteratorInsertRandom interface overriding methods.
  virtual Tbool insertForward(const Tbyte& a_crItem);
  virtual Tbool insertForward(const CBuffer& a_crItem);
  virtual Tbool insertNext(const Tbyte& a_crItem);
  virtual Tbool insertNext(const CBuffer& a_crItem);
  virtual Tbool insertBackward(const Tbyte& a_crItem);
  virtual Tbool insertBackward(const CBuffer& a_crItem);
  virtual Tbool insertPrev(const Tbyte& a_crItem);
  virtual Tbool insertPrev(const CBuffer& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const Tbyte& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const CBuffer& a_crItem);

  // IIteratorRemoveRandom interface overriding methods.
  virtual Tbool removeForward();
  virtual Tbool removeForward(Tbyte& a_rItem);
  virtual Tbool removeForward(const Tuint a_cSize);
  virtual Tbool removeForward(const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(Tbyte& a_rItem);
  virtual Tbool removeNext(const Tuint a_cSize);
  virtual Tbool removeNext(const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool removeBackward();
  virtual Tbool removeBackward(Tbyte& a_rItem);
  virtual Tbool removeBackward(const Tuint a_cSize);
  virtual Tbool removeBackward(const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool removePrev();
  virtual Tbool removePrev(Tbyte& a_rItem);
  virtual Tbool removePrev(const Tuint a_cSize);
  virtual Tbool removePrev(const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, Tbyte& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CBuffer& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialize CBufferIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBufferIterator class instances.
  /*!
      \param a_rInstance - Reference to another CBufferIterator class instance.
  */
  void swap(CBufferIterator& a_rInstance);

private:
  CBuffer* m_pContainer;                //!< Pointer to the iterator container.
  Tuint m_Index;                        //!< Index of the current byte in the byte buffer.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CBufferIterator(CBuffer* a_pContainer);
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
//! Traits meta-class: byte buffer non constant iterator's traits specialization.
template <>
class MTraitsIterator<NUtility::NIterators::CBufferIterator> :
  public MType<NUtility::NIterators::CBufferIterator>
{
public:
  //! Iterator value type.
  typedef NUtility::NIterators::CBufferIterator::TType value;
  //! Iterator return type.
  typedef NUtility::NIterators::CBufferIterator::TReturn result;
  //! Iterator container type.
  typedef NUtility::NIterators::CBufferIterator::TContainer container;
  //! Iterator base type.
  typedef NUtility::NIterators::CBufferIterator::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = true;  //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = true;  //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = true;  //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = true;  //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = true;  //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = true;  //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = true;  //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CBufferIterator.inl>
/*==========================================================================*/
#endif
