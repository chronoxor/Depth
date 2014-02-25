/*!
 *  \file    test-utility-IObserver.cpp Testing of the IObserver class.
 *  \brief   Testing of the IObserver class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the IObserver class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility tests
    VERSION:   1.0
    CREATED:   04.07.2007 23:48:18

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
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/utility/observer/IObserver.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NUtility::NObserver;
/*==========================================================================*/
static Tuint the_Connections = 0;
static Tuint the_Notifications = 0;
/*--------------------------------------------------------------------------*/
class CObserverA :
  public IObserver
{
public:
  virtual ~CObserverA()
  { CALL
    IObserver::clear();
  }

  Tbool set(const IObserver& a_crInstance)
  { CALL
    return IObserver::set(a_crInstance);
  }

protected:
  virtual Tbool onConnect(const IConnector&)
  { CALL
    ++the_Connections;
    return true;
  }
  virtual Tbool onDisconnect(const IConnector&)
  { CALL
    --the_Connections;
    return true;
  }
  virtual void onNotify(const IConnector&)
  { CALL
    ++the_Notifications;
  }
};
/*--------------------------------------------------------------------------*/
class CObserverB :
  public IObserver
{
public:
  ~CObserverB()
  { CALL
    IObserver::clear();
  }

  Tbool set(const IObserver& a_crInstance)
  { CALL
    return IObserver::set(a_crInstance);
  }

protected:
  virtual Tbool onConnect(const IConnector&)
  { CALL
    ++the_Connections;
    return true;
  }
  virtual Tbool onDisconnect(const IConnector&)
  { CALL
    --the_Connections;
    return true;
  }
  virtual void onNotify(const IConnector&)
  { CALL
    ++the_Notifications;
  }
};
/*--------------------------------------------------------------------------*/
class CObserverC :
  public IObserver
{
public:
  ~CObserverC()
  { CALL
    IObserver::clear();
  }

  Tbool set(const IObserver& a_crInstance)
  { CALL
    return IObserver::set(a_crInstance);
  }

protected:
  virtual Tbool onConnect(const IConnector&)
  { CALL
    ++the_Connections;
    return true;
  }
  virtual Tbool onDisconnect(const IConnector&)
  { CALL
    --the_Connections;
    return true;
  }
  virtual void onNotify(const IConnector&)
  { CALL
    ++the_Notifications;
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Test observers in a separate scope.
    UT_ASSERT_ZERO(the_Connections);
    {
      CObserverA a;
      CObserverB b;
      CObserverC c;

      // Connect 'a' with 'b'.
      UT_ASSERT(a.insert(b));
      UT_ASSERT_EQUAL(the_Connections, 2);

      // Copy 'a' connection from 'b' to 'c'.
      UT_ASSERT(c.set(b));
      UT_ASSERT_EQUAL(the_Connections, 4);
      // Connect 'c' with 'b'.
      UT_ASSERT(c.insert(b));
      UT_ASSERT_EQUAL(the_Connections, 6);

      // Send information notification to all 'a' connections.
      a.notifyAll();
      UT_ASSERT_EQUAL(the_Notifications, 2);
      // Send information notification to all 'b' connections.
      b.notifyAll();
      UT_ASSERT_EQUAL(the_Notifications, 4);
      // Send information notification to all 'c' connections.
      c.notifyAll();
      UT_ASSERT_EQUAL(the_Notifications, 6);
    }
    UT_ASSERT_ZERO(the_Connections);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
