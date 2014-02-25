/*!
 *  \file    example-memory-GC.cpp Example of using the garbage collection
 *           functionality.
 *  \brief   Example of using the garbage collection functionality.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the garbage collection functionality.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth memory examples
    VERSION:   1.0
    CREATED:   24.06.2007 22:18:35

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
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/memory/gc/CGCPtr.hpp>
#include <Depth/include/memory/gc/CMemoryBlockContainer.hpp>
#include <Depth/include/algorithms/containers/AForEach.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMemory;
using namespace NDepth::NAlgorithms::NContainers;
/*==========================================================================*/
class A
{
public:
  A()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("A::A()") << ln;
  }
  virtual ~A()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("A::~A()") << ln;
  }
};
/*--------------------------------------------------------------------------*/
class B :
  virtual public A
{
public:
  B()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("B::B()") << ln;
  }
  virtual ~B()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("B::~B()") << ln;
  }
};
/*--------------------------------------------------------------------------*/
class C :
  virtual public A
{
public:
  C()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("C::C()") << ln;
  }
  virtual ~C()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("C::~C()") << ln;
  }
};
/*--------------------------------------------------------------------------*/
class D :
  public B,
  public C
{
public:
  D()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("D::D()") << ln;
  }
  virtual ~D()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("D::~D()") << ln;
  }
};
/*--------------------------------------------------------------------------*/
class circle
{
public:
  circle()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("circle::circle()") << ln;
  }
 ~circle()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("circle::~circle()") << ln;
  }

  CGCPtr<circle> ptr;
};
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    showGCState();

    // Enable GC.
    CMemory::enableGC();

    // Line hierarchy.
    {
      CGCPtr<A> ptr1 = newex D();
      CGCPtr<B> ptr2 = newex D();
      CGCPtr<C> ptr3 = NAlgorithms::NCommon::dynamicCast<C*, A*>(ptr1);

      showGCState();
    }

    // Circle hierarchy.
    {
      CGCPtr<circle> ptr1 = newex circle();
      CGCPtr<circle> ptr2 = newex circle();
      CGCPtr<circle> ptr3 = newex circle();

      ptr1->ptr = ptr2;
      ptr2->ptr = ptr3;
      ptr3->ptr = ptr1;

      showGCState();
    }

    // Perform GC.
    CMemory::performGC();

    // Disable GC.
    CMemory::disableGC();

    showGCState();

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Show current state of the GC.
  static void showGCState()
  { CALL
    CStreamStdOutput stdoutput(true);

    stdoutput << STR("================================") << ln;
    stdoutput << STR("Allocated memory size = ") << CMemory::getGCAllocatedSize() << ln;
    stdoutput << STR("Allocated memory blocks = ") << CMemory::getGCAllocatedBlocks() << ln;

    CMemoryBlockContainer container;
    forEach(container, showGCBlock);

    stdoutput << STR("================================") << ln;
  }

  // Show information concerning state of the single memory block in the GC.
  static void showGCBlock(const CMemoryBlock& block)
  { CALL
    CStreamStdOutput stdoutput(true);

    stdoutput << STR("--------------------------------") << ln;
    stdoutput << STR("Block pointer = ") << block.getPointer() << ln;
    stdoutput << STR("Block size = ") << block.getSize() << ln;
    stdoutput << STR("Allocation function name = ") << block.getFunctionName() << ln;
    stdoutput << STR("Allocation file name = ") << block.getFileName() << ln;
    stdoutput << STR("Allocation line number = ") << block.getLine() << ln;
  }
} the_Application;
/*==========================================================================*/
