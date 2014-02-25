/*!
 *  \file    CConnectorIteratorConst.cpp Connector constant iterator
 *           definitions. It gives ability to get IListener items.
 *  \brief   Connector constant iterator class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Connector constant iterator class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities observer
    VERSION:   1.0
    CREATED:   04.07.2007 22:03:42

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
#include <Depth/include/utility/observer/CConnectorIteratorConst.hpp>
/*==========================================================================*/
#ifndef __CCONNECTORITERATORCONST_CPP__
#define __CCONNECTORITERATORCONST_CPP__
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
Tbool CConnectorIteratorConst::notify() const
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot send information notification to the IListener in the invalid IConnector iterator."))
  {
    return false;
  }

  NAlgorithms::NCommon::constCast<IListener&, const IListener&>(*m_Iterator.getValueRef()).onNotify(*m_cpContainer);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CConnectorIteratorConst::notifyAll() const
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot send information notification to the all IListener items in the invalid IConnector container."))
  {
    return false;
  }

  m_cpContainer->notifyAll();
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
