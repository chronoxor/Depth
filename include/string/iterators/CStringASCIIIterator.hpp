/*!
 *  \file    CStringASCIIIterator.hpp ASCII string non constant iterator
 *           definitions. It gives ability to get and modify ASCII string
 *           characters and to do random moving through the ASCII string
 *           characters.
 *  \brief   ASCII string non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.08.2008 02:52:09

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
#ifndef __CSTRINGASCIIITERATOR_HPP__
#define __CSTRINGASCIIITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertRandom.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveRandom.hpp>
#include <Depth/include/string/CStringASCII.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! ASCII string non constant iterator class.
/*!
    ASCII string non constant  iterator  represents  ASCII  string  iterations
    method. With this iterator you can perform  random  moving  and  modifying
    ASCII string characters.
*/
class BASE_API CStringASCIIIterator :
  public NCommon::NIterators::IIterator<CStringASCIIIterator, Tschar, Tschar, CStringASCII>,
  public NCommon::NIterators::IIteratorMoveRandom<CStringASCIIIterator, Tschar, Tschar, CStringASCII>,
  public NCommon::NIterators::IIteratorInsertRandom<CStringASCIIIterator, Tschar, Tschar, CStringASCII>,
  public NCommon::NIterators::IIteratorRemoveRandom<CStringASCIIIterator, Tschar, Tschar, CStringASCII>,
  public NCommon::ISeekable
{
  // Friend class: ASCII string class (CStringASCII).
  friend class NDepth::NString::CStringASCII;
  // Friend class: ASCII string constant iterator class (CStringASCIIIteratorConst).
  friend class NDepth::NString::NIterators::CStringASCIIIteratorConst;

  //! Type for MConceptDepthType constraint checking.
  typedef CStringASCIIIterator TDepthCheckType;

  // Check CStringASCIIIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef Tschar TType;
  //! Iterator return type.
  typedef Tschar TReturn;
  //! Iterator container type.
  typedef CStringASCII TContainer;
  //! Iterator base type.
  typedef CStringASCIIIterator TIterator;

  //! Default class constructor.
  CStringASCIIIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringASCIIIterator class.
  */
  CStringASCIIIterator(const CStringASCIIIterator& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringASCIIIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIteratorConst& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CStringASCIIIteratorConst& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIteratorConst& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CStringASCIIIteratorConst& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIterator& a_crInstance2);

  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIteratorConst& a_crInstance2);
  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CStringASCIIIteratorConst& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIteratorConst& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CStringASCIIIteratorConst& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIteratorConst& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CStringASCIIIteratorConst& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIteratorConst& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CStringASCIIIteratorConst& a_crInstance1, const CStringASCIIIterator& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CStringASCIIIterator& a_crInstance1, const CStringASCIIIterator& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CStringASCIIIterator& operator = (const CStringASCIIIterator& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CStringASCIIIterator& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CStringASCIIIterator& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CStringASCIIIterator& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CStringASCIIIterator& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CStringASCIIIterator operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CStringASCIIIterator operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CStringASCIIIterator operator + (const CStringASCIIIterator& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CStringASCIIIterator operator - (const CStringASCIIIterator& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new ASCII string non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed ASCII string position to return.
      \return ASCII string non constant iterator under the given index.
  */
  CStringASCIIIterator operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new ASCII string non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed ASCII string position to return.
      \return ASCII string non constant iterator under the given index.
  */
  CStringASCIIIterator operator [] (const Tuint a_cIndex) const;

  //! Set another CStringASCIIIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringASCIIIteratorConst class.
  */
  void set(const CStringASCIIIterator& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CStringASCIIIterator getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CStringASCIIIterator getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CStringASCIIIterator getIndex(const Tuint a_cIndex) const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CStringASCII& getContainerRef() const;
  virtual CStringASCII* getContainerPtr() const;
  virtual Tschar& getValueRef() const;
  virtual Tschar* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // IIteratorInsertRandom interface overriding methods.
  virtual Tbool insertForward(const Tschar& a_crItem);
  virtual Tbool insertForward(const CStringASCII& a_crItem);
  virtual Tbool insertNext(const Tschar& a_crItem);
  virtual Tbool insertNext(const CStringASCII& a_crItem);
  virtual Tbool insertBackward(const Tschar& a_crItem);
  virtual Tbool insertBackward(const CStringASCII& a_crItem);
  virtual Tbool insertPrev(const Tschar& a_crItem);
  virtual Tbool insertPrev(const CStringASCII& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const Tschar& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const CStringASCII& a_crItem);

  // IIteratorRemoveRandom interface overriding methods.
  virtual Tbool removeForward();
  virtual Tbool removeForward(Tschar& a_rItem);
  virtual Tbool removeForward(const Tuint a_cSize);
  virtual Tbool removeForward(const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(Tschar& a_rItem);
  virtual Tbool removeNext(const Tuint a_cSize);
  virtual Tbool removeNext(const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool removeBackward();
  virtual Tbool removeBackward(Tschar& a_rItem);
  virtual Tbool removeBackward(const Tuint a_cSize);
  virtual Tbool removeBackward(const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool removePrev();
  virtual Tbool removePrev(Tschar& a_rItem);
  virtual Tbool removePrev(const Tuint a_cSize);
  virtual Tbool removePrev(const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, Tschar& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialize CStringASCIIIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringASCIIIterator class instances.
  /*!
      \param a_rInstance - Reference to another CStringASCIIIterator class instance.
  */
  void swap(CStringASCIIIterator& a_rInstance);

private:
  CStringASCII* m_pContainer;           //!< Pointer to the iterator container.
  Tuint m_Index;                        //!< Index of the current ASCII character.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CStringASCIIIterator(CStringASCII* a_pContainer);
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
//! Traits meta-class: ASCII string non constant iterator's traits specialization.
template <>
class MTraitsIterator<NString::NIterators::CStringASCIIIterator> :
  public MType<NString::NIterators::CStringASCIIIterator>
{
public:
  //! Iterator value type.
  typedef NString::NIterators::CStringASCIIIterator::TType value;
  //! Iterator return type.
  typedef NString::NIterators::CStringASCIIIterator::TReturn result;
  //! Iterator container type.
  typedef NString::NIterators::CStringASCIIIterator::TContainer container;
  //! Iterator base type.
  typedef NString::NIterators::CStringASCIIIterator::TIterator iterator;

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
#include <Depth/include/string/iterators/CStringASCIIIterator.inl>
/*==========================================================================*/
#endif
