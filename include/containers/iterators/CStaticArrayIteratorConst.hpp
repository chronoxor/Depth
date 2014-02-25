/*!
 *  \file    CStaticArrayIteratorConst.hpp Static array constant iterator
 *           definitions. It gives ability to get static array items and
 *           to do random moving through the static array items.
 *  \brief   Static array constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static array constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   05.09.2006 22:44:13

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
#ifndef __CSTATICARRAYITERATORCONST_HPP__
#define __CSTATICARRAYITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/containers/CStaticArray.hpp>
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
//! Static array constant iterator class.
/*!
    Static array constant iterator represents static array iterations  method.
    With this iterator you can perform random static array moving and  looking
    into static array items. Note that you cannot  modify static  array  items
    with constant iterator.  In  this  case  use  non  constant  static  array
    iterator.

    Serialization: Static array constant iterator cannot be loaded.
*/
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
class CStaticArrayIteratorConst :
  public NCommon::NIterators::IIteratorConst<CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >,
  public NCommon::NIterators::IIteratorMoveRandom<CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>, T_Type, T_Type, CStaticArray<T_Type, t_Size, T_CopyPolicy> >,
  public NCommon::ISeekable
{
  // Friend class: Static array class (CStaticArray).
  friend class CStaticArray<T_Type, t_Size, T_CopyPolicy>;

  //! Type for MConceptICopyPolicy constraint checking.
  typedef T_CopyPolicy TCopyPolicyCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> TDepthCheckType;

  // Check T_CopyPolicy template argument constraint to be a copy policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptICopyPolicy, TCopyPolicyCheckType);
  // Check CStaticArrayIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef const T_Type TReturn;
  //! Iterator container type.
  typedef const CStaticArray<T_Type, t_Size, T_CopyPolicy> TContainer;
  //! Iterator base type.
  typedef CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> TIterator;

  //! Container copy policy type.
  typedef T_CopyPolicy TCopyPolicy;

  //! Default class constructor.
  CStaticArrayIteratorConst();
  //! Initialize with non constant static array iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CStaticArrayIterator class.
  */
  CStaticArrayIteratorConst(const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStaticArrayIteratorConst class.
  */
  CStaticArrayIteratorConst(const CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStaticArrayIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator == (const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator == (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator == (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator != (const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator != (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator != (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);

  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator < (const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator < (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator < (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator > (const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator > (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator > (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator <= (const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator <= (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator <= (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator >= (const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator >= (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIterator<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend Tbool operator >= (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance1, const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& operator = (const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& operator = (const CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy> operator + (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, Tuint t_OtherSize, class T_OtherCopyPolicy>
  friend CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy> operator - (const CStaticArrayIteratorConst<T_OtherType, t_OtherSize, T_OtherCopyPolicy>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new static array's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed static array position to return.
      \return Static array's constant iterator under the given index.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new static array's constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed static array position to return.
      \return Static array's constant iterator under the given index.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> operator [] (const Tuint a_cIndex) const;

  //! Set CStaticArrayIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CStaticArrayIterator class.
  */
  void set(const CStaticArrayIterator<T_Type, t_Size, T_CopyPolicy>& a_crInstance);
  //! Set another CStaticArrayIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStaticArrayIteratorConst class.
  */
  void set(const CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> getIndex(const Tuint a_cIndex) const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CStaticArray<T_Type, t_Size, T_CopyPolicy>& getContainerRef() const;
  virtual const CStaticArray<T_Type, t_Size, T_CopyPolicy>* getContainerPtr() const;
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

  //! Serialization load CStaticArrayIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStaticArrayIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStaticArrayIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStaticArrayIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CStaticArrayIteratorConst class instance.
  */
  void swap(CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>& a_rInstance);

private:
  const CStaticArray<T_Type, t_Size, T_CopyPolicy>* m_cpContainer; //!< Constant pointer to the iterator container.
  Tuint m_Index;                                                   //!< Index of the current static array item.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CStaticArrayIteratorConst(const CStaticArray<T_Type, t_Size, T_CopyPolicy>* a_cpContainer);
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
//! Traits meta-class: static array constant iterator's traits specialization.
template <typename T_Type, Tuint t_Size, class T_CopyPolicy>
class MTraitsIterator<NContainers::NIterators::CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> > :
  public MType<NContainers::NIterators::CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CStaticArrayIteratorConst<T_Type, t_Size, T_CopyPolicy>::TIterator iterator;

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
#include <Depth/include/containers/iterators/CStaticArrayIteratorConst.inl>
/*==========================================================================*/
#endif
