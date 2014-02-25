/*!
 *  \file    MConceptAssociativeConst.inl Template checking conception.
 *           Checks if template argument is a constant associative
 *           container type (inline).
 *  \brief   Constant associative container template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant associative container template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   23.09.2006 22:48:26

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
#ifndef __MCONCEPTCONSTASSOCIATIVE_INL__
#define __MCONCEPTCONSTASSOCIATIVE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptAssociativeConst<T_Class>::MConceptAssociativeConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptAssociativeConst<T_Class>::~MConceptAssociativeConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptAssociativeConst<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a constant container.
  MConstraint::requiresConcept<MConceptContainerConst<T_Class> >();

  Tbool result;

  // Check for the constant associative container's types.
  typename T_Class::TKey key;
  typename T_Class::TKey key1;
  typename T_Class::TKey key2;
  typename T_Class::TIterator iterator;
  typename T_Class::TIteratorConst citerator;

  // Check for the constant associative container's operators.
  iterator  = m_Container[key];
  citerator = m_cContainer[key];

  // Check for the constant associative container's methods.
  result = m_cContainer.isLessThan(key1, key2);

  // Check for the constant associative container's iterators.
  iterator  = m_Container.find(key);
  citerator = m_cContainer.find(key);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
