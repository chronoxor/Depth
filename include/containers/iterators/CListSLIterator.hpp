/*!
 *  \file    CListSLIterator.hpp Single linked list non constant iterator
 *           definitions. It gives ability to get and modify single linked
 *           list items and to do forward moving through the single linked
 *           list nodes.
 *  \brief   Single linked list non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Single linked list non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   17.02.2006 20:36:23

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
#ifndef __CLISTSLITERATOR_HPP__
#define __CLISTSLITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertForward.hpp>
#include <Depth/include/common/iterators/IIteratorMoveForward.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveForward.hpp>
#include <Depth/include/containers/CListSL.hpp>
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
//! Single linked list non constant iterator class.
/*!
    Single linked list non constant iterator  represents  single  linked  list
    iterations method. With this  iterator  you  can  perform  forward  single
    linked list moving and modifying single linked list items.
*/
template <typename T_Type, class T_Allocator>
class CListSLIterator :
  public NCommon::NIterators::IIterator<CListSLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListSL<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveForward<CListSLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListSL<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertForward<CListSLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListSL<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveForward<CListSLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListSL<T_Type, T_Allocator> >
{
  // Friend class: Single linked list class (CListSL).
  friend class CListSL<T_Type, T_Allocator>;
  // Friend class: Single linked list constant iterator class (CListSLIteratorConst).
  friend class CListSLIteratorConst<T_Type, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CListSLIterator<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CListSLIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Type TReturn;
  //! Iterator container type.
  typedef CListSL<T_Type, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CListSLIterator<T_Type, T_Allocator> TIterator;

  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CListSLIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CListSLIterator class.
  */
  CListSLIterator(const CListSLIterator<T_Type, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CListSLIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListSLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CListSLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListSLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CListSLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CListSLIterator<T_Type, T_Allocator>& operator = (const CListSLIterator<T_Type, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CListSLIterator<T_Type, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CListSLIterator<T_Type, T_Allocator>& operator ++ ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CListSLIterator<T_Type, T_Allocator> operator ++ (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend CListSLIterator<T_OtherType, T_OtherAllocator> operator + (const CListSLIterator<T_OtherType, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another CListSLIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CListSLIterator class.
  */
  void set(const CListSLIterator<T_Type, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CListSLIterator<T_Type, T_Allocator> getForward() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CListSL<T_Type, T_Allocator>& getContainerRef() const;
  virtual CListSL<T_Type, T_Allocator>* getContainerPtr() const;
  virtual T_Type& getValueRef() const;
  virtual T_Type* getValuePtr() const;

  // IIteratorMoveForward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);

  // IIteratorInsertForward interface overriding methods.
  virtual Tbool insertBackward(const T_Type& a_crItem);
  virtual Tbool insertNext(const T_Type& a_crItem);

  // IIteratorRemoveForward interface overriding methods.
  virtual Tbool removeForward();
  virtual Tbool removeForward(T_Type& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(T_Type& a_rItem);

  //! Serialize CListSLIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CListSLIterator class instances.
  /*!
      \param a_rInstance - Reference to another CListSLIterator class instance.
  */
  void swap(CListSLIterator<T_Type, T_Allocator>& a_rInstance);

private:
  CListSL<T_Type, T_Allocator>* m_pContainer;                  //!< Pointer to the iterator container.
  typename CListSL<T_Type, T_Allocator>::SListSLNode* m_pNode; //!< Pointer to the current single linked list node.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CListSLIterator(CListSL<T_Type, T_Allocator>* a_pContainer);
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
//! Traits meta-class: single linked list non constant iterator's traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CListSLIterator<T_Type, T_Allocator> > :
  public MType<NContainers::NIterators::CListSLIterator<T_Type, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CListSLIterator<T_Type, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CListSLIterator<T_Type, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CListSLIterator<T_Type, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CListSLIterator<T_Type, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = false; //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = true;  //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = true;  //!< Is iterator supports forward removing?
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
#include <Depth/include/containers/iterators/CListSLIterator.inl>
/*==========================================================================*/
#endif
