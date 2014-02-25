/*!
 *  \file    MConceptCircleDoubleLinkedConst.inl Template checking conception.
 *           Checks if template argument is a constant double linked circle
 *           container type.
 *  \brief   Constant double linked circle container template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant double linked circle container template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   04.10.2006 20:51:23

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
#ifndef __MCONCEPTCONSTCIRCLEDOUBLELINKED_INL__
#define __MCONCEPTCONSTCIRCLEDOUBLELINKED_INL__
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
inline MConceptCircleDoubleLinkedConst<T_Class>::MConceptCircleDoubleLinkedConst() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptCircleDoubleLinkedConst<T_Class>::~MConceptCircleDoubleLinkedConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptCircleDoubleLinkedConst<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a constant container.
  MConstraint::requiresConcept<MConceptContainerConst<T_Class> >();

  // Check for the constant double linked circle container's types.
  typename T_Class::TIterator iterator;
  typename T_Class::TIteratorConst citerator;

  // Check for the constant double linked circle container's iterators.
  iterator  = m_Container.getItCurrent();
  iterator  = m_Container.getItNext();
  iterator  = m_Container.getItPrev();
  citerator = m_cContainer.getItCurrent();
  citerator = m_cContainer.getItNext();
  citerator = m_cContainer.getItPrev();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
