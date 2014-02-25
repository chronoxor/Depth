/*!
 *  \file    MConceptIteratorMoveForward.inl Template checking conception.
 *           Checks if template argument is a forward move iterator type.
 *  \brief   Forward move iterator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Forward move iterator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   16.02.2006 02:49:26

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
#ifndef __MCONCEPTITERATORMOVEFORWARD_INL__
#define __MCONCEPTITERATORMOVEFORWARD_INL__
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
inline MConceptIteratorMoveForward<T_Class>::MConceptIteratorMoveForward() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIteratorMoveForward<T_Class>::~MConceptIteratorMoveForward()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIteratorMoveForward<T_Class>::constraints()
{ CALL
  Tuint steps = 0;

  // Check for the forward move iterator types.
  typename T_Class::TIterator it;

  // Check for the forward move iterator operators.
  it = m_It += steps;
  it = ++m_It;
  it = m_It++;

  // Check for the forward move iterator methods.
  it = m_It.getForward();
  steps = m_It.stepForward(steps);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
