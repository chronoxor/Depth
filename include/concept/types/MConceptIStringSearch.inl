/*!
 *  \file    MConceptIStringSearch.inl Template checking conception. Checks if
 *           template argument is a (sub)string searching algorithm.
 *  \brief   String searching algorithm template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String searching algorithm template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types conception checking
    VERSION:   1.0
    CREATED:   26.11.2009 02:45:49

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
#ifndef __MCONCEPTISTRINGSEARCH_INL__
#define __MCONCEPTISTRINGSEARCH_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NTypes {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptIStringSearch<T_Class>::MConceptIStringSearch() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIStringSearch<T_Class>::~MConceptIStringSearch()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIStringSearch<T_Class>::constraints()
{ CALL
  const typename T_Class::TStringType source;
  const typename T_Class::TPatternType pattern;

  Tbool result;
  Tuint found_start = 0;
  Tuint found_end = 0;
  Tuint index = 0;
  Tuint size = 0;

  // Initialize (sub)string searching algorithm context.
  result = m_StringSearchBackward.initialize(pattern);
  result = m_StringSearchBackward.initialize(pattern, size);
  result = m_StringSearchBackward.initialize(pattern, index, size);
  // Perform forward searching operations.
  result = m_StringSearchBackward.findNext(found_start, found_end, source);
  result = m_StringSearchBackward.findNext(found_start, found_end, source, size);
  result = m_StringSearchBackward.findNext(found_start, found_end, source, index, size);
  // Perform backward searching operations.
  result = m_StringSearchBackward.findPrev(found_start, found_end, source);
  result = m_StringSearchBackward.findPrev(found_start, found_end, source, size);
  result = m_StringSearchBackward.findPrev(found_start, found_end, source, index, size);
  // Close (sub)string searching algorithm context.
  result = m_StringSearchBackward.close();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
