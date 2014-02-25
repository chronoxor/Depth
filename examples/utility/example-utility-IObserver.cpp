/*!
 *  \file    example-utility-IObserver.cpp Example of using the IObserver
 *           interface.
 *  \brief   Example of using the IObserver interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the IObserver interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility examples
    VERSION:   1.0
    CREATED:   04.07.2007 23:28:28

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
#include <Depth/include/utility/observer/IObserver.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NUtility::NObserver;
/*==========================================================================*/
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
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("A connects with something") << ln;
    return true;
  }
  virtual Tbool onDisconnect(const IConnector&)
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("A disconnects with something") << ln;
    return true;
  }
  virtual void onNotify(const IConnector&)
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("A received information notification") << ln;
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
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("B connects with something") << ln;
    return true;
  }
  virtual Tbool onDisconnect(const IConnector&)
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("B disconnects with something") << ln;
    return true;
  }
  virtual void onNotify(const IConnector&)
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("B received information notification") << ln;
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
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("C connects with something") << ln;
    return true;
  }
  virtual Tbool onDisconnect(const IConnector&)
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("C disconnects with something") << ln;
    return true;
  }
  virtual void onNotify(const IConnector&)
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("C received information notification") << ln;
  }
};
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    CObserverA a;
    CObserverB b;
    CObserverC c;

    // Connect 'a' with 'b'.
    a.insert(b);

    // Copy 'a' connection from 'b' to 'c'.
    c.set(b);
    // Connect 'c' with 'b'.
    c.insert(b);

    // Send information notification to all 'a' connections.
    a.notifyAll();
    // Send information notification to all 'b' connections.
    b.notifyAll();
    // Send information notification to all 'c' connections.
    c.notifyAll();

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
