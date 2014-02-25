/*!
 *  \file    MTraitsContainer.hpp Traits meta-class that helps to determine
 *           container's attributes.
 *  \brief   Traits meta-class: container's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: container's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   20.09.2006 02:55:26

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
#ifndef __MTRAITSCONTAINER_HPP__
#define __MTRAITSCONTAINER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/containers/MConceptContainer.hpp>
#include <Depth/include/concept/containers/MConceptContainerConst.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: non constant container's traits.
/*!
    Traits meta-class helps to determine non constant container's  attributes.
    With this  traits  you  can  determine  type  of  the  container  and  its
    properties.
*/
template <class T_Container>
class MTraitsContainer :
  public MType<T_Container>
{
  //! Type for the MConceptContainer constraint checking.
  typedef T_Container TContainerCheckType;

  // Check T_Container template argument constraint to be a non constant container.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptContainer, TContainerCheckType);

public:
  //! Container value type.
  typedef typename T_Container::TType value;
  //! Container type.
  typedef typename T_Container::TContainer container;
  //! Container non constant iterator type.
  typedef typename T_Container::TIterator iterator;
  //! Container constant iterator type.
  typedef typename T_Container::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = false; //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = false; //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = false; //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: constant container's traits.
/*!
    Traits meta-class helps to determine constant container's attributes. With
    this traits you can determine type of the container and its properties.
*/
template <class T_Container>
class MTraitsContainer<const T_Container> :
  public MType<const T_Container>
{
  //! Type for the MConceptContainerConst constraint checking.
  typedef const T_Container TContainerConstCheckType;

  // Check T_Container template argument constraint to be a constant container.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptContainerConst, TContainerConstCheckType);

public:
  //! Container value type.
  typedef typename T_Container::TType value;
  //! Container type.
  typedef typename T_Container::TContainer container;
  //! Container non constant iterator type.
  typedef typename T_Container::TIteratorConst iterator;
  //! Container constant iterator type.
  typedef typename T_Container::TIteratorConst citerator;

  static const Tbool isConst            = true;                                              //!< Is container constant?
  static const Tbool isCircleSL         = false;                                             //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = MTraitsContainer<T_Container>::isCircleSLConst;    //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false;                                             //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = MTraitsContainer<T_Container>::isCircleDLConst;    //!< Is container constant double linked circle?
  static const Tbool isStack            = false;                                             //!< Is container non constant stack?
  static const Tbool isStackConst       = MTraitsContainer<T_Container>::isStackConst;       //!< Is container constant stack?
  static const Tbool isQueue            = false;                                             //!< Is container non constant queue?
  static const Tbool isQueueConst       = MTraitsContainer<T_Container>::isQueueConst;       //!< Is container constant queue?
  static const Tbool isDeque            = false;                                             //!< Is container non constant deque?
  static const Tbool isDequeConst       = MTraitsContainer<T_Container>::isDequeConst;       //!< Is container constant deque?
  static const Tbool isRandom           = false;                                             //!< Is container non constant random?
  static const Tbool isRandomConst      = MTraitsContainer<T_Container>::isRandomConst;      //!< Is container constant random?
  static const Tbool isAssociative      = false;                                             //!< Is container non constant associative?
  static const Tbool isAssociativeConst = MTraitsContainer<T_Container>::isAssociativeConst; //!< Is container constant associative?
  static const Tbool isTree             = false;                                             //!< Is container non constant tree?
  static const Tbool isTreeConst        = MTraitsContainer<T_Container>::isTreeConst;        //!< Is container constant tree?
  static const Tbool isGraph            = false;                                             //!< Is container non constant graph?
  static const Tbool isGraphConst       = MTraitsContainer<T_Container>::isGraphConst;       //!< Is container constant graph?
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
