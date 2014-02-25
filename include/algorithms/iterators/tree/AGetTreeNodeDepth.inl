/*!
 *  \file    AGetTreeNodeDepth.inl Contains implementation of the tree node
 *           get depth algorithm.
 *  \brief   Algorithm to find tree node depth value (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find tree node depth value (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree iterators algorithms
    VERSION:   1.0
    CREATED:   30.06.2006 23:38:17

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
#ifndef __AGETTREENODEDEPTH_INL__
#define __AGETTREENODEDEPTH_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
namespace NTree {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_TreeIterator>
inline Tuint getTreeNodeDepth(const T_TreeIterator& a_crTreeIterator)
{ CALL
  // Check T_TreeIterator class constraint to be an any tree iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyTree<T_TreeIterator> >();

  // Check if the iterator is in the valid state.
  ASSERT(a_crTreeIterator.isValid(), STR("Cannot perform the algorithm to the the invalid tree iterator."))
  {
    return 0;
  }

  Tuint count = 0;
  T_TreeIterator it_parent(a_crTreeIterator.getParent());

  while (it_parent.isValid())
  {
    ++count;
    it_parent = it_parent.getParent();
  }
  return count;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
