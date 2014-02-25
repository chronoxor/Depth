/*!
 *  \file    IListener.hpp Listener interface receives notifications form
 *           IConnector interface.
 *  \brief   Listener interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Listener interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities observer
    VERSION:   1.0
    CREATED:   03.07.2007 00:01:44

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
#ifndef __ILISTENER_HPP__
#define __ILISTENER_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NObserver {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
class IListener;
class IObserver;
class CConnectorIterator;
class CConnectorIteratorConst;
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Listener interface.
/*!
    Listener interface receives notifications from  the  IConnector  interface
    instance. Types of the notifications are the following:

    \li <b>IListener::onConnect()</b> - connection notification. It is invoked
        from  IConnector  interface  instance  when  it  connects   with   the
        IListener.
    \li <b>IListener::onDisconnect()</b> - disconnection notification.  It  is
        invoked from IConnector interface instance when  it  disconnects  from
        the IListener.
    \li <b>IListener::onNotify()</b>  -  information   notification.   It   is
        manually invoked from IConnector interface instance.
*/
class BASE_API IListener
{
  // Friend interface: Connector interface (IConnector).
  friend class IConnector;
  // Friend class: Connector iterator class (CConnectorIterator).
  friend class CConnectorIterator;
  // Friend class: Constant connector iterator class (CConnectorIteratorConst).
  friend class CConnectorIteratorConst;

protected:
  //! Default interface protected constructor.
  IListener();

  //! Connection notification.
  /*!
      Method is called when IConnector interface instance try to  establish  a
      new connection. If this method returns 'false', then connection will not
      establish.

      Default implementation of this method always returns 'true'.

      \param a_crIConnector - Constant reference to the connected IConnector interface instance.
      \return true  - if connection was successfully established. \n
              false - if connection was not successfully established. \n
  */
  virtual Tbool onConnect(const IConnector& a_crIConnector);
  //! Disconnection notification.
  /*!
      Method is called when IConnector interface instance try to  remove  some
      connection. If this method returns 'false',  then  connection  will  not
      removed.

      Default implementation of this method always returns 'true'.

      \param a_crIConnector - Constant reference to disconnected IConnector interface instance.
      \return true  - if connection was successfully removed. \n
              false - if connection was not successfully removed. \n
  */
  virtual Tbool onDisconnect(const IConnector& a_crIConnector);

  //! Information notification.
  /*!
      Method is called from IConnector interface instance to inform about some
      changes in state.

      \param a_crIConnector - Constant reference to disconnected IConnector interface instance.
  */
  virtual void onNotify(const IConnector& a_crIConnector);

public:
  //! Interface virtual destructor.
  virtual ~IListener();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/observer/IConnector.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/utility/observer/IListener.inl>
/*==========================================================================*/
#endif
