/*!
 *  \file    CTreeIteratorConst.hpp Tree constant iterator definitions. It
 *           gives ability to get tree items.
 *  \brief   Tree constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   23.06.2006 22:43:27

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
#ifndef __CTREEITERATORCONST_HPP__
#define __CTREEITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveTree.hpp>
#include <Depth/include/containers/CTree.hpp>
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
//! Tree constant iterator class.
/*!
    Tree constant  iterator  represents  tree  iterations  method.  With  this
    iterator you can perform looking into tree items.  Note  that  you  cannot
    modify tree items with constant iterator. In this case  use  non  constant
    tree iterator.

    Serialization: Tree constant iterator cannot be loaded.
*/
template <typename T_Type, class T_Allocator>
class CTreeIteratorConst :
  public NCommon::NIterators::IIteratorConst<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveTree<CTreeIteratorConst<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >
{
  // Friend class: Tree class (CTree).
  friend class CTree<T_Type, T_Allocator>;
  // Friend structure: Tree node structure (CTree::STreeNode).
  friend struct CTree<T_Type, T_Allocator>::STreeNode;

  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CTreeIteratorConst<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CTreeIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef const T_Type TReturn;
  //! Iterator container type.
  typedef const CTree<T_Type, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CTreeIteratorConst<T_Type, T_Allocator> TIterator;

  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CTreeIteratorConst();
  //! Initialize with non constant tree iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CTreeIterator class.
  */
  CTreeIteratorConst(const CTreeIterator<T_Type, T_Allocator>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorConst class.
  */
  CTreeIteratorConst(const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTreeIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator>& operator = (const CTreeIterator<T_Type, T_Allocator>& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator>& operator = (const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIteratorConst<T_Type, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend CTreeIteratorConst<T_OtherType, T_OtherAllocator> operator + (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend CTreeIteratorConst<T_OtherType, T_OtherAllocator> operator - (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Set CTreeIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CTreeIterator class.
  */
  void set(const CTreeIterator<T_Type, T_Allocator>& a_crInstance);
  //! Set another CTreeIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorConst class.
  */
  void set(const CTreeIteratorConst<T_Type, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CTreeIteratorConst<T_Type, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CTreeIteratorConst<T_Type, T_Allocator> getBackward() const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CTree<T_Type, T_Allocator>& getContainerRef() const;
  virtual const CTree<T_Type, T_Allocator>* getContainerPtr() const;
  virtual const T_Type& getValueRef() const;
  virtual const T_Type* getValuePtr() const;

  // IIteratorMoveTree interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool isRoot() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getRoot() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getParent() const;
  virtual Tuint getSiblingIndex() const;
  virtual Tuint getSiblingsCount() const;
  virtual Tuint getPrevSiblingsCount() const;
  virtual Tuint getNextSiblingsCount() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getFirstSibling() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getLastSibling() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getPrevSibling() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getNextSibling() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getIndexSibling(const Tuint a_cIndex) const;
  virtual Tuint getChildCount() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getFirstChild() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getLastChild() const;
  virtual CTreeIteratorConst<T_Type, T_Allocator> getIndexChild(const Tuint a_cIndex) const;

  //! Serialization load CTreeIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CTreeIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CTreeIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTreeIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CTreeIteratorConst class instance.
  */
  void swap(CTreeIteratorConst<T_Type, T_Allocator>& a_rInstance);

private:
  const CTree<T_Type, T_Allocator>* m_cpContainer;                //!< Constant pointer to the iterator container.
  const typename CTree<T_Type, T_Allocator>::STreeNode* m_cpNode; //!< Constant pointer to the current tree node.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CTreeIteratorConst(const CTree<T_Type, T_Allocator>* a_cpContainer);
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
//! Traits meta-class: tree constant iterator's traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CTreeIteratorConst<T_Type, T_Allocator> > :
  public MType<NContainers::NIterators::CTreeIteratorConst<T_Type, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CTreeIteratorConst<T_Type, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CTreeIteratorConst<T_Type, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CTreeIteratorConst<T_Type, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CTreeIteratorConst<T_Type, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = true;  //!< Is iterator supports tree moving?
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
#include <Depth/include/containers/iterators/CTreeIteratorConst.inl>
/*==========================================================================*/
#endif
