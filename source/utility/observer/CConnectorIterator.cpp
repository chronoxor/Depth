/*!
 *  \file    CConnectorIterator.cpp Connector non constant iterator
 *           definitions. It gives ability to get IListener items
 *           and to connect/disconnect another ones.
 *  \brief   Connector non constant iterator class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Connector non constant iterator class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities observer
    VERSION:   1.0
    CREATED:   04.07.2007 21:54:32

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/utility/observer/CConnectorIterator.hpp>
/*==========================================================================*/
#ifndef __CCONNECTORITERATOR_CPP__
#define __CCONNECTORITERATOR_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NObserver {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool CConnectorIterator::insert(const IListener& a_crIListener, const Tbool a_cUpdate/* = false */)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new IListener into the invalid IConnector container."))
  {
    return false;
  }
  // Check if the given IListener is not connected with IConnector.
  ASSERT(!m_pContainer->isConnected(a_crIListener), STR("Given IListener is already connected with the current IConnector."))
  {
    return false;
  }

  // Try to connect with given IListener.
  if (NAlgorithms::NCommon::constCast<IListener&, const IListener&>(a_crIListener).onConnect(*m_pContainer))
  {
    if (!m_Iterator.insert(NAlgorithms::NCommon::constCast<IListener*, const IListener*>(&a_crIListener), a_cUpdate))
      return false;

    IConnector* connector = NAlgorithms::NCommon::dynamicCast<IConnector*>(NAlgorithms::NCommon::constCast<IListener*, const IListener*>(&a_crIListener));
    IListener* listener = NAlgorithms::NCommon::dynamicCast<IListener*>(m_pContainer);

    // If the given IListener is also IConnector, then connect to it.
    if ((connector != NULL) && (listener != NULL))
    {
      // Check if the given IConnector is not connected with IListener.
      if (connector->isConnected(*listener))
      {
        WARNING(STR("Given IConnector is already connected with the current IListener."));
        return false;
      }

      // Try to connect current IListener.
      if (!listener->onConnect(*connector))
        return false;
      // Connect given IConnector to the current IListener.
      if (!connector->m_Connections.insert(listener))
        return false;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CConnectorIterator::remove()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove IListener from the invalid IConnector iterator."))
  {
    return false;
  }

  // Try to disconnect given IListener.
  if (m_Iterator.getValueRef()->onDisconnect(*m_pContainer))
  {
    IConnector* connector = NAlgorithms::NCommon::dynamicCast<IConnector*>(NAlgorithms::NCommon::constCast<IListener*, const IListener*>(m_Iterator.getValueRef()));
    IListener* listener = NAlgorithms::NCommon::dynamicCast<IListener*>(m_pContainer);

    if (!m_Iterator.remove())
      return false;

    // If the given IListener is also IConnector, then disconnect from it.
    if ((connector != NULL) && (listener != NULL))
    {
      NContainers::CSet<IListener*>::TIterator iterator = connector->m_Connections.find(listener);
      if (iterator.isValid())
      {
        // Try to disconnect current IListener.
        if (listener->onDisconnect(*connector))
        {
          if (!iterator.remove())
            return false;
        }
        else
          return false;
      }
      else
      {
        WARNING(STR("Given IConnector is not connected with the current IListener."));
        return false;
      }
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CConnectorIterator::remove(IListener& a_rIListener)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove IListener from the invalid IConnector iterator."))
  {
    return false;
  }

  // Try to disconnect given IListener.
  if (m_Iterator.getValueRef()->onDisconnect(*m_pContainer))
  {
    IConnector* connector = NAlgorithms::NCommon::dynamicCast<IConnector*>(NAlgorithms::NCommon::constCast<IListener*, const IListener*>(m_Iterator.getValueRef()));
    IListener* listener = NAlgorithms::NCommon::dynamicCast<IListener*>(m_pContainer);

    a_rIListener = *m_Iterator.getValueRef();
    if (!m_Iterator.remove())
      return false;

    // If the given IListener is also IConnector, then disconnect from it.
    if ((connector != NULL) && (listener != NULL))
    {
      NContainers::CSet<IListener*>::TIterator iterator = connector->m_Connections.find(listener);
      if (iterator.isValid())
      {
        // Try to disconnect current IListener.
        if (listener->onDisconnect(*connector))
        {
          if (!iterator.remove())
            return false;
        }
        else
          return false;
      }
      else
      {
        WARNING(STR("Given IConnector is not connected with the current IListener."));
        return false;
      }
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CConnectorIterator::notify() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot send information notification to the IListener in the invalid IConnector iterator."))
  {
    return false;
  }

  (*m_Iterator.getValueRef()).onNotify(*m_pContainer);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CConnectorIterator::notifyAll() const
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot send information notification to the all IListener items in the invalid IConnector container."))
  {
    return false;
  }

  m_pContainer->notifyAll();
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
