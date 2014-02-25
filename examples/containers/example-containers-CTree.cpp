/*!
 *  \file    example-containers-CTree.cpp Example of using the CTree class.
 *  \brief   Example of using the CTree class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CTree class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   02.03.2007 20:49:35

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
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/containers/tree/ASearchBreadth.hpp>
#include <Depth/include/algorithms/containers/tree/ASearchDepthPostOrder.hpp>
#include <Depth/include/algorithms/containers/tree/ASearchDepthPreOrder.hpp>
#include <Depth/include/containers/CTree.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NContainers::NTree;
using namespace NDepth::NAlgorithms::NIterators::NTree;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    CTree<Tsint> a;

    // Fill the tree.
    fill(a);
    // Show the tree.
    show(stdoutput, a);

    // Iterate through the tree.
    iterate(stdoutput, a);

    // Find elements in the tree.
    find(stdoutput, a);

    // Copy the tree.
    CTree<Tsint> b(a);
    CTree<Tsint> c(a);

    // Remove items from the tree.
    remove(stdoutput, a);

    // Remove items from another tree.
    removeSubTree(stdoutput, b);

    // Clear another tree.
    c.clear();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Fill instance of the CTree<Tsint> class with predefined values.
  static void fill(CTree<Tsint>& a_rTree)
  { CALL
    a_rTree.insertFirstRoot(1);
    a_rTree.insertIndexRoot(1, 2);
    a_rTree.insertIndexRoot(2, 3);
    a_rTree.insertLastRoot(4);
    a_rTree.getItFirstRoot().insertFirstChild(11);
    a_rTree.getItFirstRoot().insertIndexChild(1, 12);
    a_rTree.getItFirstRoot().insertLastChild(13);
    a_rTree.getItIndexRoot(1).insertIndexChild(0, 21);
    a_rTree.getItIndexRoot(1).getIndexChild(0).insertIndexChild(0, 211);
    a_rTree.getItIndexRoot(2).insertLastChild(31);
    a_rTree.getItFirstRoot().getFirstChild().insertFirstChild(111);
    a_rTree.getItFirstRoot().getFirstChild().insertIndexChild(1, 112);
    a_rTree.getItFirstRoot().getFirstChild().insertLastChild(113);
    a_rTree.getItFirstRoot().getIndexChild(1).insertFirstChild(121);
    a_rTree.getItFirstRoot().getIndexChild(1).insertIndexChild(1, 122);
    a_rTree.getItFirstRoot().getLastChild().insertLastChild(131);
  }

  // Write instance of the CTree<Tsint> class into the given writer using tree iterators.
  static void showIt(IWriter& writer, const CTreeIteratorConst<Tsint>& a_crIt, Tuint level = 0)
  { CALL
    if (a_crIt.isValid())
    {
      for (Tuint i = 0; i < level; i++)
        writer << tab;
      writer << STR("item = ") << *a_crIt << ln;
      for (Tuint i = 0; i < a_crIt.getChildCount(); i++)
        showIt(writer, a_crIt.getIndexChild(i), level + 1);
    }
  }

  // Write instance of the CTree<Tsint> class into the given writer.
  static void show(IWriter& writer, const CTree<Tsint>& a_crTree)
  { CALL
    writer << STR("CTree<Tsint>(") << STR("size = ") << a_crTree.getSize() << STR(")") << ln;
    writer << STR("{") << ln;
    for (Tuint i = 0; i < a_crTree.getRootCount(); i++)
      showIt(writer, a_crTree.getItIndexRoot(i));
    writer << STR("}") << ln;
  }

  // Iterate through the instance of the CTree<Tsint> class.
  static void iterate(IWriter& writer, const CTree<Tsint>& a_crTree)
  { CALL
    writer << STR("CTree<Tsint>(") << STR("size = ") << a_crTree.getSize() << STR(")") << ln;
    CTreeIteratorConst<Tsint> it = a_crTree.getItFirstRoot();
    writer << STR("{") << ln;
    if (it.isValid())
    {
      do
      {
        writer << STR(" iterate item = ") << *it << ln;
      } while (it.stepForward() > 0);
    }
    writer << STR("}") << ln;
  }

  // Find items in the instance of the CTree<Tsint> class.
  static void find(IWriter& writer, const CTree<Tsint>& a_crTree)
  { CALL
    writer << STR("CTree<Tsint>(") << STR("size = ") << a_crTree.getSize() << STR(")") << ln;
    // Breadth next search.
    CTree<Tsint>::TIteratorConst breadthNext = searchBreadth(a_crTree, 122);
    writer << STR("Breadth next search of the '122': ") << (breadthNext.isValid() ? STR("found") : STR("not found")) << ln;
    // Breadth previous search.
    CTree<Tsint>::TIteratorConst breadthPrev = searchBreadthPrev(a_crTree.getItLastRoot(), 122);
    writer << STR("Breadth previous search of the '122': ") << (breadthPrev.isValid() ? STR("found") : STR("not found")) << ln;
    // Depth preorder next search.
    CTree<Tsint>::TIteratorConst depthPreOrderNext = searchDepthPreOrder(a_crTree, 122);
    writer << STR("Depth preorder next search of the '122': ") << (depthPreOrderNext.isValid() ? STR("found") : STR("not found")) << ln;
    // Depth preorder previous search.
    CTree<Tsint>::TIteratorConst depthPreOrderPrev = searchDepthPreOrderPrev(a_crTree.getItRightmostChild(), 122);
    writer << STR("Depth preorder previous search of the '122': ") << (depthPreOrderPrev.isValid() ? STR("found") : STR("not found")) << ln;
    // Depth postorder next search.
    CTree<Tsint>::TIteratorConst depthPostOrderNext = searchDepthPostOrder(a_crTree, 122);
    writer << STR("Depth postorder next search of the '122': ") << (depthPostOrderNext.isValid() ? STR("found") : STR("not found")) << ln;
    // Depth postorder previous search.
    CTree<Tsint>::TIteratorConst depthPostOrderPrev = searchDepthPostOrderPrev(a_crTree.getItRightmostChild(), 122);
    writer << STR("Depth postorder previous search of the '122': ") << (depthPostOrderPrev.isValid() ? STR("found") : STR("not found")) << ln;
  }

  // Remove items from the instance of the CTree<Tsint> class using iterators.
  static void removeIt(IWriter& writer, CTreeIterator<Tsint>& a_rIt, Tuint level = 0)
  { CALL
    if (a_rIt.isValid())
    {
      while (a_rIt.getChildCount() > 0)
      {
        CTreeIterator<Tsint> it = a_rIt.getFirstChild();
        removeIt(writer, it, level + 1);
      }
      for (Tuint i = 0; i < level; i++)
        writer << tab;
      writer << STR("removed item = ") << *a_rIt << ln;
      a_rIt.removeForward();
    }
  }

  // Remove all items from the instance of the CTree<Tsint> class.
  void remove(IWriter& writer, CTree<Tsint>& a_rTree)
  { CALL
    writer << STR("CTree<Tsint>(") << STR("size = ") << a_rTree.getSize() << STR(")") << ln;
    writer << STR("{") << ln;
    while (!a_rTree.isEmpty())
    {
      CTreeIterator<Tsint> it = a_rTree.getItFirstRoot();
      removeIt(writer, it);
    }
    writer << STR("}") << ln;
  }

  // Remove all subtree items from the instance of the CTree<Tsint> class.
  void removeSubTree(IWriter& writer, CTree<Tsint>& a_rTree)
  { CALL
    writer << STR("CTree<Tsint>(") << STR("size = ") << a_rTree.getSize() << STR(")") << ln;
    writer << STR("{") << ln;
    while (!a_rTree.isEmpty())
    {
      CTree<Tsint> sub_tree;
      a_rTree.subTreeFirstRoot(sub_tree);
      remove(writer, sub_tree);
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
