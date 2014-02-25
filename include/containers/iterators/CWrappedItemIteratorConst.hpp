/*!
 *  \file    CWrappedItemIteratorConst.hpp Wrapped item constant iterator
 *           definitions. It gives ability to get wrapped item and
 *           to do random moving through the single wrapped item.
 *  \brief   Wrapped item constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Wrapped item constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   06.05.2009 03:44:57

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
#ifndef __CWRAPPEDITEMITERATORCONST_HPP__
#define __CWRAPPEDITEMITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AAddress.hpp>
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Wrapped item constant iterator class.
/*!
    Wrapped item constant iterator represents wrapped item iterations  method.
    With this iterator you can perform random wrapped item moving and  looking
    into the single wrapped item. Note that you  cannot  modify  wrapped  item
    with constant iterator.  In  this  case  use  non  constant  wrapped  item
    iterator.

    Serialization: Wrapped item constant iterator cannot be loaded.
*/
template <typename T_Type>
class CWrappedItemIteratorConst :
  public NCommon::NIterators::IIteratorConst<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>,
  public NCommon::NIterators::IIteratorMoveRandom<CWrappedItemIteratorConst<T_Type>, T_Type, T_Type, T_Type>,
  public NCommon::ISeekable
{
  //! Type for MConceptDepthType constraint checking.
  typedef CWrappedItemIteratorConst<T_Type> TDepthCheckType;

  // Check CWrappedItemIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef const T_Type TReturn;
  //! Iterator container type.
  typedef const T_Type TContainer;
  //! Iterator base type.
  typedef CWrappedItemIteratorConst<T_Type> TIterator;

  //! Default class constructor.
  CWrappedItemIteratorConst();
  //! Initialize iterator with the given wrapped item value.
  /*!
      \param a_crValue - Constant reference to the wrapped item value.
  */
  CWrappedItemIteratorConst(const T_Type& a_crValue);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedItemIteratorConst class.
  */
  CWrappedItemIteratorConst(const CWrappedItemIteratorConst<T_Type>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CWrappedItemIteratorConst();

  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance1, const CWrappedItemIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance1, const CWrappedItemIteratorConst<T_OtherType>& a_crInstance2);

  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance1, const CWrappedItemIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance1, const CWrappedItemIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance1, const CWrappedItemIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance1, const CWrappedItemIteratorConst<T_OtherType>& a_crInstance2);

  //! Operator: Set new wrapped item value.
  /*!
      \param a_crValue - Constant reference to the wrapped item value.
      \return Reference to the current iterator class instance.
  */
  CWrappedItemIteratorConst<T_Type>& operator = (const T_Type& a_crValue);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CWrappedItemIteratorConst<T_Type>& operator = (const CWrappedItemIteratorConst<T_Type>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CWrappedItemIteratorConst<T_Type>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CWrappedItemIteratorConst<T_Type>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CWrappedItemIteratorConst<T_Type>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CWrappedItemIteratorConst<T_Type>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CWrappedItemIteratorConst<T_Type> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CWrappedItemIteratorConst<T_Type> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType>
  friend CWrappedItemIteratorConst<T_OtherType> operator + (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType>
  friend CWrappedItemIteratorConst<T_OtherType> operator - (const CWrappedItemIteratorConst<T_OtherType>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new wrapped item's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed wrapped item position to return.
      \return Wrapped item's constant iterator under the given index.
  */
  CWrappedItemIteratorConst<T_Type> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new wrapped item's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed wrapped item position to return.
      \return Wrapped item's constant iterator under the given index.
  */
  CWrappedItemIteratorConst<T_Type> operator [] (const Tuint a_cIndex) const;

  //! Set new wrapped item value.
  /*!
      \param a_crValue - Constant reference to the wrapped item value.
  */
  void set(const T_Type& a_crValue);
  //! Set another CWrappedItemIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedItemIteratorConst class.
  */
  void set(const CWrappedItemIteratorConst<T_Type>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CWrappedItemIteratorConst<T_Type> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CWrappedItemIteratorConst<T_Type> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CWrappedItemIteratorConst<T_Type> getIndex(const Tuint a_cIndex) const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const T_Type& getContainerRef() const;
  virtual const T_Type* getContainerPtr() const;
  virtual const T_Type& getValueRef() const;
  virtual const T_Type* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialization load CWrappedItemIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CWrappedItemIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CWrappedItemIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CWrappedItemIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CWrappedItemIteratorConst class instance.
  */
  void swap(CWrappedItemIteratorConst<T_Type>& a_rInstance);

private:
  const T_Type* m_cpValue;              //!< Constant pointer to the wrapped item.
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
//! Traits meta-class: wrapped item constant iterator's traits specialization.
template <typename T_Type>
class MTraitsIterator<NContainers::NIterators::CWrappedItemIteratorConst<T_Type> > :
  public MType<NContainers::NIterators::CWrappedItemIteratorConst<T_Type> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CWrappedItemIteratorConst<T_Type>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CWrappedItemIteratorConst<T_Type>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CWrappedItemIteratorConst<T_Type>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CWrappedItemIteratorConst<T_Type>::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = true;  //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
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
#include <Depth/include/containers/iterators/CWrappedItemIteratorConst.inl>
/*==========================================================================*/
#endif
