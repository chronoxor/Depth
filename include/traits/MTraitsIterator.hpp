/*!
 *  \file    MTraitsIterator.hpp Traits meta-class that helps to determine
 *           iterator's attributes.
 *  \brief   Traits meta-class: iterator's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: iterator's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   29.03.2006 20:48:42

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
#ifndef __MTRAITSITERATOR_HPP__
#define __MTRAITSITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/iterators/MConceptIteratorAny.hpp>
#include <Depth/include/traits/MType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: non constant iterator's traits.
/*!
    Traits meta-class helps to determine non constant  iterator's  attributes.
    With this traits you can determine type  of  the  iterator,  its  constant
    attribute, type of iterator container and iterator properties.
*/
template <class T_Iterator>
class MTraitsIterator :
  public MType<T_Iterator>
{
  //! Type for the MConceptIteratorAny constraint checking.
  typedef T_Iterator TIteratorAnyCheckType;

  // Check T_Iterator template argument constraint to be an any iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAny, TIteratorAnyCheckType);

public:
  //! Iterator value type.
  typedef typename T_Iterator::TType value;
  //! Iterator return type.
  typedef typename T_Iterator::TReturn result;
  //! Iterator container type.
  typedef typename T_Iterator::TContainer container;
  //! Iterator base type.
  typedef typename T_Iterator::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = false; //!< Is iterator supports forward moving?
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
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant iterator's traits.
/*!
    Traits meta-class helps to determine constant iterator's attributes.  With
    this  traits  you  can  determine  type  of  the  iterator,  its  constant
    attribute, type of iterator container and iterator properties.
*/
template <class T_Iterator>
class MTraitsIterator<const T_Iterator> :
  public MType<const T_Iterator>
{
  //! Type for the MConceptIteratorAny constraint checking.
  typedef T_Iterator TIteratorAnyCheckType;

  // Check T_Iterator template argument constraint to be an any iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAny, TIteratorAnyCheckType);

public:
  //! Iterator value type.
  typedef typename T_Iterator::TType value;
  //! Iterator return type.
  typedef typename T_Iterator::TReturn result;
  //! Iterator container type.
  typedef typename T_Iterator::TContainer container;
  //! Iterator base type.
  typedef typename T_Iterator::TIterator iterator;

  static const Tbool isConst             = true;                                           //!< Is iterator constant?
  static const Tbool isCircled           = MTraitsIterator<T_Iterator>::isCircled;         //!< Is iterator container circled?
  static const Tbool isMoveForward       = MTraitsIterator<T_Iterator>::isMoveForward;     //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = MTraitsIterator<T_Iterator>::isMoveBackward;    //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = MTraitsIterator<T_Iterator>::isMoveRandom;      //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = MTraitsIterator<T_Iterator>::isMoveAssociative; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = MTraitsIterator<T_Iterator>::isMoveTree;        //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = MTraitsIterator<T_Iterator>::isMoveGraph;       //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false;                                          //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false;                                          //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false;                                          //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false;                                          //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false;                                          //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false;                                          //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false;                                          //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false;                                          //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false;                                          //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false;                                          //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false;                                          //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false;                                          //!< Is iterator supports graph removing?
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
