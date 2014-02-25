/*!
 *  \file    CWrappedConstArray.hpp Template wrapped constant array container
 *           class. Wrapped constant array represents a fixed-sized random
 *           access constant container which is built on a existing provided
 *           constant items.
 *  \brief   Template constant wrapped array container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template constant wrapped array container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   24.04.2007 23:41:53

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
#ifndef __CWRAPPEDCONSTARRAY_HPP__
#define __CWRAPPEDCONSTARRAY_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CWrappedArray.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template wrapped constant array container class.
/*!
    Wrapped constant array  container  represents  fixed-sized  random  access
    constant container based on a existing provided constant items. You cannot
    insert/remove items into/from the fixed-sized constant array.  You  cannot
    change values of the fixed-sized constant array.

    The wrapped constant array container is different from  the  static  array
    container. The wrapped constant array container does not  allocate  a  new
    block for items, but uses an existing items' block which is described with
    provided constant pointer to it (or constant  reference  for  the  special
    case with single item).

    Serialization: Wrapped constant array container cannot be loaded.
*/
template <typename T_Type>
class CWrappedArray<const T_Type> :
  public NCommon::NContainers::IContainer<CWrappedArray<const T_Type>, const T_Type, CWrappedArrayIteratorConst<const T_Type>, CWrappedArrayIteratorConst<const T_Type> >,
  public NCommon::NContainers::IRandomConst<CWrappedArray<const T_Type>, const T_Type, CWrappedArrayIteratorConst<const T_Type>, CWrappedArrayIteratorConst<const T_Type> >
{
  // Friend class: Constant wrapped array iterator class (CWrappedArrayIteratorConst).
  friend class CWrappedArrayIteratorConst<const T_Type>;

  //! Type for MConceptDepthType constraint checking.
  typedef CWrappedArray<const T_Type> TDepthCheckType;

  // Check CWrappedArray class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef const T_Type TType;
  //! Container type.
  typedef CWrappedArray<const T_Type> TContainer;
  //! Non constant wrapped array iterator type.
  typedef CWrappedArrayIteratorConst<const T_Type> TIterator;
  //! Constant wrapped array iterator type.
  typedef CWrappedArrayIteratorConst<const T_Type> TIteratorConst;

  //! Create an empty wrapped constant array.
  /*!
      Constructor creates an empty wrapped constant array.
  */
  CWrappedArray();
  //! Create wrapped constant array from single constant item.
  /*!
      Constructor creates wrapped  constant  array  based  on  given  constant
      single item.

      \param a_crValue - Initialize constant value.
  */
  CWrappedArray(const T_Type& a_crValue);
  //! Create wrapped constant array from constant array of fixed size.
  /*!
      Constructor creates wrapped constant array based on given constant array
      of fixed size.

      \param a_cpArray - Constant pointer to the array of fixed size.
  */
  template <Tuint t_Size>
  CWrappedArray(const T_Type (&a_cpArray)[t_Size]);
  //! Create wrapped constant array from constant buffer with given size.
  /*!
      Constructor creates wrapped  constant  array  based  on  given  constant
      buffer with given size.

      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
  */
  CWrappedArray(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArray class.
  */
  CWrappedArray(const CWrappedArray<const T_Type>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CWrappedArray();

  //! Operator: Assign constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CWrappedArray<const T_Type>& operator = (const T_Type (&a_cpArray)[t_Size]);
  //! Operator: Assign another CWrappedArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArray class.
      \return Reference to the current class instance.
  */
  CWrappedArray<const T_Type>& operator = (const CWrappedArray<const T_Type>& a_crInstance);

  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Constant reference to array's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Constant reference to array's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Constant reference to array's item under the given index.
  */
  const T_Type& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the array's buffer.
  /*!
      \param a_cIndex - Indexed array position to return.
      \return Constant reference to array's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex) const;

  //! Operator: Get constant pointer to the current array's buffer.
  /*!
      \return Constant pointer to the current array's buffer.
      \see NDepth::NContainers::CWrappedArray::getBuffer()
  */
  operator const T_Type* ();
  //! Operator: Get constant pointer to the current array's buffer.
  /*!
      \return Constant pointer to the current array's buffer.
      \see NDepth::NContainers::CWrappedArray::getBuffer()
  */
  operator const T_Type* () const;

  //! Set wrapped constant array from single constant item.
  /*!
      \param a_rValue - Initialize constant value.
      \return true  - if wrapped constant array was successfully set. \n
              false - if wrapped constant array was not successfully set. \n
  */
  Tbool set(const T_Type& a_rValue);
  //! Set wrapped constant array from constant array of fixed size.
  /*!
      \param a_cpArray - Constant pointer to the array of fixed size.
      \return true  - if wrapped array was successfully set. \n
              false - if wrapped array was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(const T_Type (&a_cpArray)[t_Size]);
  //! Set wrapped constant array from constant buffer with given size.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return true  - if wrapped constant array was successfully set. \n
              false - if wrapped constant array was not successfully set. \n
  */
  Tbool set(const T_Type a_cpBuffer[], const Tuint a_cSize);
  //! Set another CWrappedArray class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArray class.
      \return true  - if another wrapped constant array was successfully set. \n
              false - if another wrapped constant array was not successfully set. \n
  */
  Tbool set(const CWrappedArray<const T_Type>& a_crInstance);

  //! Get wrapped constant array free size.
  /*!
      Method always returns  0,  because  wrapped  constant  array  cannot  be
      resized.

      \return Count of free elements in the wrapped constant array (always 0).
  */
  Tuint getFreeSize() const;

  //! Get wrapped constant array lower capacity bound value.
  /*!
      Method returns lower bound size  value  before  wrapped  constant  array
      reallocation. As wrapped constant array does not support resizing,  this
      method always returns 0.

      \return Wrapped array lower capacity bound value (always 0).
  */
  Tuint getLoCapacity() const;
  //! Get wrapped constant array higher capacity bound value.
  /*!
      Method  returns  higher  bound   size   value   before   wrapped   array
      reallocation. As wrapped constant array does not support resizing,  this
      method always returns m_Size.

      \return Wrapped array higher capacity bound value (always m_Size).
  */
  Tuint getHiCapacity() const;

  //! Get ponter to the wrapped constant array buffer.
  /*!
      Method returns pointer to  the  wrapped  array  buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to check wrapped constant array bounds while working
      with this pointer.

      \return Constant pointer to the wrapped constant array buffer.
  */
  const T_Type* getBuffer();
  //! Get constant ponter to the wrapped constant array buffer.
  /*!
      Method returns constant pointer to the wrapped  constant  array  buffer.
      Using of this pointer is quite dangerous cause it  may  lead  to  memory
      errors. That is why you always have  to  check  wrapped  constant  array
      bounds while working with this pointer.

      \return Constant pointer to the wrapped constant array buffer.
  */
  const T_Type* getBuffer() const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Serialization load CWrappedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CWrappedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CWrappedArray class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CWrappedArray class instances.
  /*!
      \param a_rInstance - Reference to another CWrappedArray class instance.
  */
  void swap(CWrappedArray<const T_Type>& a_rInstance);

private:
  Tuint         m_Size;                 //!< Wrapped constant array's size.
  const T_Type* m_pData;                //!< Constant pointer to wrapped constant array's buffer.
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
//! Traits meta-class: wrapped constant array container traits specialization.
template <typename T_Type>
class MTraitsContainer<NContainers::CWrappedArray<const T_Type> > :
  public MType<NContainers::CWrappedArray<const T_Type> >
{
public:
  //! Container value type.
  typedef typename NContainers::CWrappedArray<const T_Type>::TType value;
  //! Container type.
  typedef typename NContainers::CWrappedArray<const T_Type>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CWrappedArray<const T_Type>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CWrappedArray<const T_Type>::TIteratorConst citerator;

  static const Tbool isConst            = true;  //!< Is container constant?
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
#include <Depth/include/containers/CWrappedConstArray.inl>
/*==========================================================================*/
#endif
