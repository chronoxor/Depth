/*!
 *  \file    MConceptRandomConst.inl Template checking conception. Checks if
 *           template argument is a constant random container type.
 *  \brief   Constant random container template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant random container template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   04.10.2006 03:49:35

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
#ifndef __MCONCEPTCONSTRANDOM_INL__
#define __MCONCEPTCONSTRANDOM_INL__
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
inline MConceptRandomConst<T_Class>::MConceptRandomConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptRandomConst<T_Class>::~MConceptRandomConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptRandomConst<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a constant deque container.
  MConstraint::requiresConcept<MConceptDequeConst<T_Class> >();

  Tsint sindex;
  Tuint uindex;

  // Check for the constant random container's types.
  typename T_Class::TIterator iterator;
  typename T_Class::TIteratorConst citerator;

  // Check for the constant random container's operators.
  typename T_Class::TType& item1 = m_Container[sindex];
  typename T_Class::TType& item2 = m_Container[uindex];
  const typename T_Class::TType& item3 = m_cContainer[sindex];
  const typename T_Class::TType& item4 = m_cContainer[uindex];

  // Check for the constant random container's iterators.
  iterator  = m_Container.getItIndex(uindex);
  citerator = m_cContainer.getItIndex(uindex);

  IGNORE_UNUSED(item1);
  IGNORE_UNUSED(item2);
  IGNORE_UNUSED(item3);
  IGNORE_UNUSED(item4);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
