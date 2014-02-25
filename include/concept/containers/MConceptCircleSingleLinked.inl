/*!
 *  \file    MConceptCircleSingleLinked.inl Template checking conception.
 *           Checks if template argument is a non constant single linked
 *           circle container type.
 *  \brief   Non constant single linked circle container template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant single linked circle container template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   04.10.2006 20:48:38

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
#ifndef __MCONCEPTCIRCLESINGLELINKED_INL__
#define __MCONCEPTCIRCLESINGLELINKED_INL__
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
inline MConceptCircleSingleLinked<T_Class>::MConceptCircleSingleLinked() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptCircleSingleLinked<T_Class>::~MConceptCircleSingleLinked()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptCircleSingleLinked<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a non constant container.
  MConstraint::requiresConcept<MConceptContainer<T_Class> >();

  Tbool result;
  Tuint step;

  // Check for the non constant single linked circle container's types.
  typename T_Class::TType item;

  // Check for the non constant single linked circle container's methods.
  result = m_Container.insertCurrent(item);
  result = m_Container.insertNext(item);
  result = m_Container.removeCurrent();
  result = m_Container.removeCurrent(item);
  result = m_Container.removeNext();
  result = m_Container.removeNext(item);
  step = m_Container.stepForward(step);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
