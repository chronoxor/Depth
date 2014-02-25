/*!
 *  \file    MConceptIteratorMoveRandom.inl Template checking conception.
 *           Checks if template argument is a random move iterator type.
 *  \brief   Random move iterator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Random move iterator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   05.04.2006 22:55:32

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
#ifndef __MCONCEPTITERATORMOVERANDOM_INL__
#define __MCONCEPTITERATORMOVERANDOM_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptIteratorMoveRandom<T_Class>::MConceptIteratorMoveRandom() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIteratorMoveRandom<T_Class>::~MConceptIteratorMoveRandom()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIteratorMoveRandom<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a backward move iterator.
  MConstraint::requiresConcept<MConceptIteratorMoveBackward<T_Class> >();

  Tbool result;
  Tsint sindex = 0;
  Tuint uindex = 0;
  Tuint size = 0;

  // Check for the random move iterator types.
  typename T_Class::TIterator it;

  // Check for the random move iterator operators.
  it = m_It[sindex];
  it = m_It[uindex];

  // Check for the random move iterator methods.
  it = m_It.getIndex(uindex);
  result = m_It.stepIndex(uindex);

  // Check for the ISeekable interface methods.
  size   = m_It.getSize();
  uindex = m_It.getPosition();
  result = m_It.setPosition(uindex);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
