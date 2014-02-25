/*!
 *  \file    AGetNextSameDepth.inl Contains implementation of the algorithm
 *           which searches next tree node with same depth as in given one.
 *  \brief   Algorithm to find next tree node with same depth (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find next tree node with same depth (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree iterators algorithms
    VERSION:   1.0
    CREATED:   30.06.2006 00:47:53

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
#ifndef __AGETNEXTSAMEDEPTH_INL__
#define __AGETNEXTSAMEDEPTH_INL__
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
inline T_TreeIterator getNextSameDepth(const T_TreeIterator& a_crTreeIterator)
{ CALL
  // Check T_TreeIterator class constraint to be an any tree iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyTree<T_TreeIterator> >();

  // Check if the iterator is in the valid state.
  ASSERT(a_crTreeIterator.isValid(), STR("Cannot perform the algorithm to the the invalid tree iterator."))
  {
    return T_TreeIterator();
  }

  T_TreeIterator it_result(a_crTreeIterator);

  if (it_result.getNextSibling().isValid())
    it_result = a_crTreeIterator.getNextSibling();
  else
  {
    Tsint depth = 0;

upper:
    do
    {
      it_result = it_result.getParent();
      if (!it_result.isValid())
        return it_result;
      --depth;
    } while (!it_result.getNextSibling().isValid());

lower:
    it_result = it_result.getNextSibling();
    while (!it_result.getFirstChild().isValid())
    {
      if (!it_result.getNextSibling().isValid())
        goto upper;
      it_result = it_result.getNextSibling();
      if (!it_result.isValid())
        return it_result;
    }
    while ((depth < 0) && it_result.getFirstChild().isValid())
    {
      it_result = it_result.getFirstChild();
      ++depth;
    }
    if (depth < 0)
    {
      if (!it_result.getNextSibling().isValid())
        goto upper;
      else
        goto lower;
    }
  }
  return it_result;
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
