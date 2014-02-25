/*!
 *  \file    test-containers-CTree.cpp Testing of the CTree class.
 *  \brief   Testing of the CTree class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTree class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   05.03.2007 03:54:25

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
// Temporary headers.
#include <Depth/todo/serialize/serialize.hpp>
/*--------------------------------------------------------------------------*/
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/containers/tree/ASearchBreadth.hpp>
#include <Depth/include/algorithms/containers/tree/ASearchDepthPostOrder.hpp>
#include <Depth/include/algorithms/containers/tree/ASearchDepthPreOrder.hpp>
#include <Depth/include/containers/CTree.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NContainers::NTree;
using namespace NDepth::NAlgorithms::NIterators::NTree;
using namespace NDepth::NContainers;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CTree<Tsint> a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the tree.
    UT_ASSERT_CHECK_FILL_DEPTH(a);
    UT_ASSERT_EQUAL(a.getSize(), 16);

    // Show the tree.
    UT_ASSERT_CHECK_SHOW(a);

    // Iterate through the tree.
    UT_ASSERT_CHECK_ITERATE(a);

    // Find elements in the tree.
    UT_ASSERT_CHECK_FIND(a);

    // Copy the tree.
    CTree<Tsint> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 16);

    // Show another tree.
    UT_ASSERT_CHECK_SHOW(b);

    // Clear another tree.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    CTree<Tsint> c;
    CTree<Tsint> d;
    UT_ASSERT_ZERO(c.getSize());
    UT_ASSERT_ZERO(d.getSize());

    // Fill trees.
    UT_ASSERT_CHECK_FILL_BREADTH(c);
    UT_ASSERT_CHECK_FILL_BREADTH(d);
    UT_ASSERT_EQUAL(c.getSize(), 16);
    UT_ASSERT_EQUAL(d.getSize(), 16);

    // Remove items from trees.
    UT_ASSERT_CHECK_REMOVE(c);
    UT_ASSERT_CHECK_REMOVE_SUBTREE(d);
    UT_ASSERT_ZERO(c.getSize());
    UT_ASSERT_ZERO(d.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill breadth functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_FILL_BREADTH(CTree<Tsint>& a_rTree)
  { CALL
    UT_ASSERT(a_rTree.insertFirstRoot(10));
    UT_ASSERT(a_rTree.insertIndexRoot(1, 13));
    UT_ASSERT(a_rTree.insertIndexRoot(2, 15));
    UT_ASSERT(a_rTree.insertLastRoot(16));
    UT_ASSERT(a_rTree.getItFirstRoot().insertFirstChild(4));
    UT_ASSERT(a_rTree.getItFirstRoot().insertIndexChild(1, 7));
    UT_ASSERT(a_rTree.getItFirstRoot().insertLastChild(9));
    UT_ASSERT(a_rTree.getItIndexRoot(1).insertIndexChild(0, 12));
    UT_ASSERT(a_rTree.getItIndexRoot(1).getIndexChild(0).insertIndexChild(0, 11));
    UT_ASSERT(a_rTree.getItIndexRoot(2).insertLastChild(14));
    UT_ASSERT(a_rTree.getItFirstRoot().getFirstChild().insertFirstChild(1));
    UT_ASSERT(a_rTree.getItFirstRoot().getFirstChild().insertIndexChild(1, 2));
    UT_ASSERT(a_rTree.getItFirstRoot().getFirstChild().insertLastChild(3));
    UT_ASSERT(a_rTree.getItFirstRoot().getIndexChild(1).insertFirstChild(5));
    UT_ASSERT(a_rTree.getItFirstRoot().getIndexChild(1).insertIndexChild(1, 6));
    UT_ASSERT(a_rTree.getItFirstRoot().getLastChild().insertLastChild(8));
  }

  // Check the fill depth functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_FILL_DEPTH(CTree<Tsint>& a_rTree)
  { CALL
    UT_ASSERT(a_rTree.insertFirstRoot(1));
    UT_ASSERT(a_rTree.insertIndexRoot(1, 11));
    UT_ASSERT(a_rTree.insertIndexRoot(2, 14));
    UT_ASSERT(a_rTree.insertLastRoot(16));
    UT_ASSERT(a_rTree.getItFirstRoot().insertFirstChild(2));
    UT_ASSERT(a_rTree.getItFirstRoot().insertIndexChild(1, 6));
    UT_ASSERT(a_rTree.getItFirstRoot().insertLastChild(9));
    UT_ASSERT(a_rTree.getItIndexRoot(1).insertIndexChild(0, 12));
    UT_ASSERT(a_rTree.getItIndexRoot(1).getIndexChild(0).insertIndexChild(0, 13));
    UT_ASSERT(a_rTree.getItIndexRoot(2).insertLastChild(15));
    UT_ASSERT(a_rTree.getItFirstRoot().getFirstChild().insertFirstChild(3));
    UT_ASSERT(a_rTree.getItFirstRoot().getFirstChild().insertIndexChild(1, 4));
    UT_ASSERT(a_rTree.getItFirstRoot().getFirstChild().insertLastChild(5));
    UT_ASSERT(a_rTree.getItFirstRoot().getIndexChild(1).insertFirstChild(7));
    UT_ASSERT(a_rTree.getItFirstRoot().getIndexChild(1).insertIndexChild(1, 8));
    UT_ASSERT(a_rTree.getItFirstRoot().getLastChild().insertLastChild(10));
  }

  // Check the show functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CTree<Tsint>& a_crTree)
  { CALL
    for (Tuint i = 0; i < a_crTree.getRootCount(); i++)
      UT_ASSERT_CHECK_SHOW_ITERATOR(a_crTree.getItIndexRoot(i));
  }

  // Check the show iterator functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_SHOW_ITERATOR(const CTreeIteratorConst<Tsint>& a_crIt)
  { CALL
    static Tsint value = 1;

    if (value > 16)
      value = 1;

    if (a_crIt.isValid())
    {
      UT_ASSERT(*a_crIt == value++);
      for (Tuint i = 0; i < a_crIt.getChildCount(); i++)
        UT_ASSERT_CHECK_SHOW_ITERATOR(a_crIt.getIndexChild(i));
    }
  }

  // Check the iterate functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_ITERATE(const CTree<Tsint>& a_crTree)
  { CALL
    Tsint value = 1;
    CTreeIteratorConst<Tsint> it = a_crTree.getItFirstRoot();

    if (it.isValid())
    {
      do
      {
        UT_ASSERT(*it == value++);
      } while (it.stepForward() > 0);
    }
  }

  // Check the find functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_FIND(const CTree<Tsint>& a_crTree)
  { CALL
    // Breadth next search.
    UT_ASSERT(searchBreadth(a_crTree, 8).isValid());
    // Breadth previous search.
    UT_ASSERT(searchBreadthPrev(a_crTree.getItLastRoot(), 8).isValid());
    // Depth preorder next search.
    UT_ASSERT(searchDepthPreOrder(a_crTree, 8).isValid());
    // Depth preorder previous search.
    UT_ASSERT(searchDepthPreOrderPrev(a_crTree.getItRightmostChild(), 8).isValid());
    // Depth postorder next search.
    UT_ASSERT(searchDepthPostOrder(a_crTree, 8).isValid());
    // Depth postorder previous search.
    UT_ASSERT(searchDepthPostOrderPrev(a_crTree.getItRightmostChild(), 8).isValid());
  }

  // Check the remove functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CTree<Tsint>& a_rTree)
  { CALL
    while (!a_rTree.isEmpty())
    {
      CTreeIterator<Tsint> it = a_rTree.getItFirstRoot();
      UT_ASSERT_CHECK_REMOVE_ITERATOR(it);
    }
  }

  // Check the remove iterator functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_REMOVE_ITERATOR(CTreeIterator<Tsint>& a_rIt)
  { CALL
    static Tsint value = 1;

    if (value > 16)
      value = 1;

    if (a_rIt.isValid())
    {
      while (a_rIt.getChildCount() > 0)
      {
        CTreeIterator<Tsint> it = a_rIt.getFirstChild();
        UT_ASSERT_CHECK_REMOVE_ITERATOR(it);
      }
      UT_ASSERT(*a_rIt == value++);
      UT_ASSERT(a_rIt.removeForward());
    }
  }

  // Check the remove sub-tree functionality of the CTree<Tsint>.
  void UT_ASSERT_CHECK_REMOVE_SUBTREE(CTree<Tsint>& a_rTree)
  { CALL
    while (!a_rTree.isEmpty())
    {
      CTree<Tsint> sub_tree;
      UT_ASSERT(a_rTree.subTreeFirstRoot(sub_tree));
      UT_ASSERT_CHECK_REMOVE(sub_tree);
    }
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CTree<Tsint> instance;

    // Fill the tree.
    UT_ASSERT_CHECK_FILL_DEPTH(instance);

    // Show the tree before serialization.
    UT_ASSERT_CHECK_SHOW(instance);

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Clear instance.
    UT_ASSERT(instance.clear());

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());

    // Show the tree after serialization.
    UT_ASSERT_CHECK_SHOW(instance);
  }
} the_Test;
/*==========================================================================*/
