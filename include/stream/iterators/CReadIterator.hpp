/*!
 *  \file    CReadIterator.hpp Read iterator definitions for the reader
 *           stream. It gives ability to read sequence of items from the
 *           reader.
 *  \brief   Read iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Read iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   20.08.2008 03:21:59

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
#ifndef __CREADITERATOR_HPP__
#define __CREADITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorMoveForward.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveForward.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Read iterator class.
/*!
    Read iterator class represents reader functionality. It gives  ability  to
    read sequence of items from the reader.

    Behavior of the read iterator methods are the following:
    \li <b>CReadIterator::stepForward()</b> - read the current iterator  value
        from the reader.
    \li <b>CReadIterator::removeForward()</b> - return  the  current  iterator
        value, then read new current iterator value from the reader.
    \li <b>CReadIterator::removeNext()</b> - read the next iterator value from
        the reader and return its value.

    With this behavior read iterator could be used in the copy,  count,  fill,
    find, generate and transform algorithms.
*/
template <typename T_Type>
class CReadIterator :
  public NCommon::NIterators::IIterator<CReadIterator<T_Type>, T_Type, T_Type, IReader>,
  public NCommon::NIterators::IIteratorMoveForward<CReadIterator<T_Type>, T_Type, T_Type, IReader>,
  public NCommon::NIterators::IIteratorRemoveForward<CReadIterator<T_Type>, T_Type, T_Type, IReader>
{
  // Friend interface: Reader interface (IReader).
  friend class NDepth::NStream::IReader;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CReadIterator<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check CReadIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Type TReturn;
  //! Iterator container type.
  typedef IReader TContainer;
  //! Iterator base type.
  typedef CReadIterator<T_Type> TIterator;

  //! Default class constructor.
  CReadIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReadIterator class.
  */
  CReadIterator(const CReadIterator<T_Type>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CReadIterator();

  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CReadIterator<T_OtherType>& a_crInstance1, const CReadIterator<T_OtherType>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CReadIterator<T_OtherType>& a_crInstance1, const CReadIterator<T_OtherType>& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CReadIterator<T_Type>& operator = (const CReadIterator<T_Type>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CReadIterator<T_Type>& operator += (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CReadIterator<T_Type>& operator ++ ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CReadIterator<T_Type> operator ++ (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType>
  friend CReadIterator<T_OtherType> operator + (const CReadIterator<T_OtherType>& a_crInstance, const Tuint a_cStepCount);

  //! Set another CReadIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReadIterator class.
  */
  void set(const CReadIterator<T_Type>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CReadIterator<T_Type> getForward() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual IReader& getContainerRef() const;
  virtual IReader* getContainerPtr() const;
  virtual T_Type& getValueRef() const;
  virtual T_Type* getValuePtr() const;

  // IIteratorMoveForward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);

  // IIteratorRemoveForward interface overriding methods.
  virtual Tbool removeForward();
  virtual Tbool removeForward(T_Type& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(T_Type& a_rItem);

  //! Serialize CReadIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CReadIterator class instances.
  /*!
      \param a_rInstance - Reference to another CReadIterator class instance.
  */
  void swap(CReadIterator<T_Type>& a_rInstance);

private:
  IReader* m_pContainer;                //!< Pointer to the iterator container.
  Tbool    m_IsValid;                   //!< Iterator valid flag.
  mutable T_Type m_Value;               //!< Current iterator value.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CReadIterator(IReader* a_pContainer);
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
//! Traits meta-class: read iterator's traits specialization.
template <typename T_Type>
class MTraitsIterator<NStream::NIterators::CReadIterator<T_Type> > :
  public MType<NStream::NIterators::CReadIterator<T_Type> >
{
public:
  //! Iterator value type.
  typedef typename NStream::NIterators::CReadIterator<T_Type>::TType value;
  //! Iterator return type.
  typedef typename NStream::NIterators::CReadIterator<T_Type>::TReturn result;
  //! Iterator container type.
  typedef typename NStream::NIterators::CReadIterator<T_Type>::TContainer container;
  //! Iterator base type.
  typedef typename NStream::NIterators::CReadIterator<T_Type>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = false; //!< Is iterator supports forward and backward moving?
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
#include <Depth/include/stream/iterators/CReadIterator.inl>
/*==========================================================================*/
#endif
