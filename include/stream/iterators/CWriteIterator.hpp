/*!
 *  \file    CWriteIterator.hpp Write iterator definitions for the writer
 *           stream. It gives ability to write sequence of items into the
 *           writer.
 *  \brief   Write iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Write iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   19.08.2008 21:32:01

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
#ifndef __CWRITEITERATOR_HPP__
#define __CWRITEITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertForward.hpp>
#include <Depth/include/common/iterators/IIteratorMoveForward.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/stream/IWriter.hpp>
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
//! Write iterator class.
/*!
    Write iterator class represents writer functionality. It gives ability  to
    write sequence of items into the writer.

    Behavior of the write iterator methods are the following:
    \li <b>CWriteIterator::stepForward()</b>  -  write  the  current  iterator
        value into the writer.
    \li <b>CWriteIterator::insertBackward()</b> -  write  the  given  iterator
        value into the writer.
    \li <b>CWriteIterator::insertNext()</b>  -  assign  the  current  iterator
        value.

    With this behavior write iterator could be used in the copy, count,  fill,
    find, generate and transform algorithms.
*/
template <typename T_Type>
class CWriteIterator :
  public NCommon::NIterators::IIterator<CWriteIterator<T_Type>, T_Type, T_Type, IWriter>,
  public NCommon::NIterators::IIteratorMoveForward<CWriteIterator<T_Type>, T_Type, T_Type, IWriter>,
  public NCommon::NIterators::IIteratorInsertForward<CWriteIterator<T_Type>, T_Type, T_Type, IWriter>
{
  // Friend interface: Writer interface (IWriter).
  friend class NDepth::NStream::IWriter;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CWriteIterator<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check CWriteIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Type TReturn;
  //! Iterator container type.
  typedef IWriter TContainer;
  //! Iterator base type.
  typedef CWriteIterator<T_Type> TIterator;

  //! Default class constructor.
  CWriteIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWriteIterator class.
  */
  CWriteIterator(const CWriteIterator<T_Type>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CWriteIterator();

  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CWriteIterator<T_OtherType>& a_crInstance1, const CWriteIterator<T_OtherType>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CWriteIterator<T_OtherType>& a_crInstance1, const CWriteIterator<T_OtherType>& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CWriteIterator<T_Type>& operator = (const CWriteIterator<T_Type>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CWriteIterator<T_Type>& operator += (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CWriteIterator<T_Type>& operator ++ ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CWriteIterator<T_Type> operator ++ (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType>
  friend CWriteIterator<T_OtherType> operator + (const CWriteIterator<T_OtherType>& a_crInstance, const Tuint a_cStepCount);

  //! Set another CWriteIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWriteIterator class.
  */
  void set(const CWriteIterator<T_Type>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CWriteIterator<T_Type> getForward() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual IWriter& getContainerRef() const;
  virtual IWriter* getContainerPtr() const;
  virtual T_Type& getValueRef() const;
  virtual T_Type* getValuePtr() const;

  // IIteratorMoveForward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);

  // IIteratorInsertForward interface overriding methods.
  virtual Tbool insertNext(const T_Type& a_crItem);
  virtual Tbool insertBackward(const T_Type& a_crItem);

  //! Serialize CWriteIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CWriteIterator class instances.
  /*!
      \param a_rInstance - Reference to another CWriteIterator class instance.
  */
  void swap(CWriteIterator<T_Type>& a_rInstance);

private:
  IWriter* m_pContainer;                //!< Pointer to the iterator container.
  Tbool    m_IsValid;                   //!< Iterator valid flag.
  mutable T_Type m_Value;               //!< Current iterator value.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CWriteIterator(IWriter* a_pContainer);
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
//! Traits meta-class: write iterator's traits specialization.
template <typename T_Type>
class MTraitsIterator<NStream::NIterators::CWriteIterator<T_Type> > :
  public MType<NStream::NIterators::CWriteIterator<T_Type> >
{
public:
  //! Iterator value type.
  typedef typename NStream::NIterators::CWriteIterator<T_Type>::TType value;
  //! Iterator return type.
  typedef typename NStream::NIterators::CWriteIterator<T_Type>::TReturn result;
  //! Iterator container type.
  typedef typename NStream::NIterators::CWriteIterator<T_Type>::TContainer container;
  //! Iterator base type.
  typedef typename NStream::NIterators::CWriteIterator<T_Type>::TIterator iterator;

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
#include <Depth/include/stream/iterators/CWriteIterator.inl>
/*==========================================================================*/
#endif
