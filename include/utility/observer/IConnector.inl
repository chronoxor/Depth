/*!
 *  \file    IConnector.inl Connector interface contains IListener interface
 *           instances and sends notifications to them.
 *  \brief   Connector interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Connector interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities observer
    VERSION:   1.0
    CREATED:   03.07.2007 01:22:47

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
#ifndef __ICONNECTOR_INL__
#define __ICONNECTOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NObserver {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IConnector::IConnector() :
  NCommon::NContainers::IAssociative<IConnector, IListener, IListener, IListener, CConnectorIterator, CConnectorIteratorConst>(),
  NCommon::NContainers::IAssociativeConst<IConnector, IListener, IListener, IListener, CConnectorIterator, CConnectorIteratorConst>(),
  NCommon::NContainers::IDequeConst<IConnector, IListener, CConnectorIterator, CConnectorIteratorConst>(),
  m_Connections()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IConnector::IConnector(const IConnector& a_crInstance) :
  NCommon::NContainers::IAssociative<IConnector, IListener, IListener, IListener, CConnectorIterator, CConnectorIteratorConst>(),
  NCommon::NContainers::IAssociativeConst<IConnector, IListener, IListener, IListener, CConnectorIterator, CConnectorIteratorConst>(),
  NCommon::NContainers::IDequeConst<IConnector, IListener, CConnectorIterator, CConnectorIteratorConst>(),
  m_Connections()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IConnector::~IConnector()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline IConnector& IConnector::operator = (const IConnector& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline IConnector& IConnector::operator += (const IListener& a_crIListener)
{ CALL
  insert(a_crIListener);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline IConnector& IConnector::operator += (const IConnector& a_crIConnector)
{ CALL
  insert(a_crIConnector);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline IConnector& IConnector::operator += (const IObserver& a_crIObserver)
{ CALL
  insert(a_crIObserver);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline IConnector& IConnector::operator -= (const IListener& a_crIListener)
{ CALL
  remove(a_crIListener);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline IConnector& IConnector::operator -= (const IConnector& a_crIConnector)
{ CALL
  remove(a_crIConnector);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline IConnector& IConnector::operator -= (const IObserver& a_crIObserver)
{ CALL
  remove(a_crIObserver);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline IConnector::TIterator IConnector::operator [] (const IListener& a_crIListener)
{ CALL
  return find(a_crIListener);
}
/*--------------------------------------------------------------------------*/
inline IConnector::TIteratorConst IConnector::operator [] (const IListener& a_crIListener) const
{ CALL
  return find(a_crIListener);
}
/*--------------------------------------------------------------------------*/
inline Tbool IConnector::isConnected(const IListener& a_crIListener) const
{ CALL
  return find(a_crIListener).isValid();
}
/*--------------------------------------------------------------------------*/
inline Tbool IConnector::isEmpty() const
{ CALL
  return m_Connections.isEmpty();
}
/*--------------------------------------------------------------------------*/
inline Tuint IConnector::getSize() const
{ CALL
  return m_Connections.getSize();
}
/*--------------------------------------------------------------------------*/
inline Tbool IConnector::isLessThan(const IListener& a_crIListener1, const IListener& a_crIListener2) const
{ CALL
  return ((&a_crIListener1) < (&a_crIListener2));
}
/*--------------------------------------------------------------------------*/
inline void IConnector::swap(IConnector& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Connections, a_rInstance.m_Connections);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
