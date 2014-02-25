/*!
 *  \file    CListDLIteratorConst.hpp Double linked list constant iterator
 *           definitions. It gives ability to get double linked list items
 *           and to do forward and backward moving through the double linked
 *           list nodes.
 *  \brief   Double linked list constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Double linked list constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   17.02.2006 20:55:47

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
#ifndef __CLISTDLITERATORCONST_HPP__
#define __CLISTDLITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/containers/CListDL.hpp>
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
//! Double linked list constant iterator class.
/*!
    Double  linked  list  constant  iterator  represents  double  linked  list
    iterations method. With this iterator you can perform forward and backward
    double linked list moving and looking into double linked list items.  Note
    that you cannot  modify double linked list items with  constant  iterator.
    In this case use non constant double linked list iterator.

    Serialization: Double linked list constant iterator cannot be loaded.
*/
template <typename T_Type, class T_Allocator>
class CListDLIteratorConst :
  public NCommon::NIterators::IIteratorConst<CListDLIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveBackward<CListDLIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >
{
  // Friend class: Double linked list class (CListDL).
  friend class CListDL<T_Type, T_Allocator>;

  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CListDLIteratorConst<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CListDLIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef const T_Type TReturn;
  //! Iterator container type.
  typedef const CListDL<T_Type, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CListDLIteratorConst<T_Type, T_Allocator> TIterator;

  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CListDLIteratorConst();
  //! Initialize with non constant double linked list iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CListDLIterator class.
  */
  CListDLIteratorConst(const CListDLIterator<T_Type, T_Allocator>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CListDLIteratorConst class.
  */
  CListDLIteratorConst(const CListDLIteratorConst<T_Type, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CListDLIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CListDLIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListDLIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CListDLIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListDLIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator>& operator = (const CListDLIterator<T_Type, T_Allocator>& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator>& operator = (const CListDLIteratorConst<T_Type, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CListDLIteratorConst<T_Type, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend CListDLIteratorConst<T_OtherType, T_OtherAllocator> operator + (const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend CListDLIteratorConst<T_OtherType, T_OtherAllocator> operator - (const CListDLIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Set CListDLIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CListDLIterator class.
  */
  void set(const CListDLIterator<T_Type, T_Allocator>& a_crInstance);
  //! Set another CListDLIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CListDLIteratorConst class.
  */
  void set(const CListDLIteratorConst<T_Type, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CListDLIteratorConst<T_Type, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CListDLIteratorConst<T_Type, T_Allocator> getBackward() const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CListDL<T_Type, T_Allocator>& getContainerRef() const;
  virtual const CListDL<T_Type, T_Allocator>* getContainerPtr() const;
  virtual const T_Type& getValueRef() const;
  virtual const T_Type* getValuePtr() const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialization load CListDLIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CListDLIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CListDLIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CListDLIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CListDLIteratorConst class instance.
  */
  void swap(CListDLIteratorConst<T_Type, T_Allocator>& a_rInstance);

private:
  const CListDL<T_Type, T_Allocator>* m_cpContainer;                  //!< Constant pointer to the iterator container.
  const typename CListDL<T_Type, T_Allocator>::SListDLNode* m_cpNode; //!< Constant pointer to the current double linked list node.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CListDLIteratorConst(const CListDL<T_Type, T_Allocator>* a_cpContainer);
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
//! Traits meta-class: double linked list constant iterator's traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CListDLIteratorConst<T_Type, T_Allocator> > :
  public MType<NContainers::NIterators::CListDLIteratorConst<T_Type, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CListDLIteratorConst<T_Type, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CListDLIteratorConst<T_Type, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CListDLIteratorConst<T_Type, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CListDLIteratorConst<T_Type, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
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
#include <Depth/include/containers/iterators/CListDLIteratorConst.inl>
/*==========================================================================*/
#endif
