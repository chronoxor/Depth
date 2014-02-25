/*!
 *  \file    IConnector.cpp Connector interface contains IListener interface
 *           instances and sends notifications to them.
 *  \brief   Connector interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Connector interface (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/utility/observer/IConnector.hpp>
/*==========================================================================*/
#ifndef __ICONNECTOR_CPP__
#define __ICONNECTOR_CPP__
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
Tbool IConnector::set(const IConnector& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IConnector interface instance."))
  {
    return false;
  }

  // Clear current IConnector.
  if (!clear())
    return false;

  TIteratorConst it_first = a_crInstance.getItFirst();
  TIteratorConst it_current = it_first;

  // Connect all IListener items.
  if (it_current.isValid())
  {
    do
    {
      if (!insert(it_current.getValueRef()))
        return false;
    } while ((it_current.stepForward() > 0) && (it_current != it_first));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::clear()
{ CALL
  TIterator it = getItFirst();

  while (it.isValid())
  {
    if (!it.remove())
      return false;
    it = getItFirst();
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::insert(const IListener& a_crIListener)
{ CALL
  return getItFirst().insert(a_crIListener);
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::insert(const IConnector& a_crIConnector)
{ CALL
  TIteratorConst it_first = a_crIConnector.getItFirst();
  TIteratorConst it_current = it_first;

  if (it_current.isValid())
  {
    do
    {
      if (!find(it_current.getValueRef()).isValid())
        if (!insert(it_current.getValueRef()))
          return false;
    } while ((it_current.stepForward() > 0) && (it_current != it_first));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::insert(const IObserver& a_crIObserver)
{ CALL
  return insert((const IListener&)a_crIObserver);
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::remove(const IListener& a_crIListener, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIterator it = find(a_crIListener);

  if (it.isValid())
  {
    if (a_cRemoveSame)
    {
      do
      {
        if (!it.remove())
          return false;
        it = find(a_crIListener);
      } while (it.isValid());
    }
    else
    {
      if (!it.remove())
        return false;
    }
    return true;
  }
  else
  {
    WARNING(STR("Given IListener is not connected with the current IConnector."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::remove(const IConnector& a_crIConnector, const Tbool a_cRemoveSame/* = false */)
{ CALL
  TIteratorConst it_first = a_crIConnector.getItFirst();
  TIteratorConst it_current = it_first;

  if (it_current.isValid())
  {
    do
    {
      const IListener* value = &it_current.getValueRef();
      TIterator it = find(*value);

      if (it.isValid())
      {
        if (a_cRemoveSame)
        {
          do
          {
            if (!it.remove())
              return false;
            it = find(*value);
          } while (it.isValid());
        }
        else
        {
          if (!it.remove())
            return false;
        }
      }
    } while ((it_current.stepForward() > 0) && (it_current != it_first));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::remove(const IObserver& a_crIObserver, const Tbool a_cRemoveSame/* = false */)
{ CALL
  return remove((const IListener&)a_crIObserver, a_cRemoveSame);
}
/*--------------------------------------------------------------------------*/
IConnector::TIterator IConnector::find(const IListener& a_crIListener)
{ CALL
  TIterator find_iterator;

  // Filling iterator inner structure.
  find_iterator.m_pContainer = this;
  find_iterator.m_Iterator = m_Connections.find(NAlgorithms::NCommon::constCast<IListener*, const IListener*>(&a_crIListener));
  return find_iterator;
}
/*--------------------------------------------------------------------------*/
IConnector::TIteratorConst IConnector::find(const IListener& a_crIListener) const
{ CALL
  TIteratorConst find_iterator;

  // Filling iterator inner structure.
  find_iterator.m_cpContainer = this;
  find_iterator.m_Iterator = m_Connections.find(NAlgorithms::NCommon::constCast<IListener*, const IListener*>(&a_crIListener));
  return find_iterator;
}
/*--------------------------------------------------------------------------*/
IConnector::TIterator IConnector::getItFirst()
{ CALL
  TIterator first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_pContainer = this;
  first_iterator.m_Iterator = m_Connections.getItFirst();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
IConnector::TIteratorConst IConnector::getItFirst() const
{ CALL
  TIteratorConst first_iterator;

  // Filling iterator inner structure.
  first_iterator.m_cpContainer = this;
  first_iterator.m_Iterator = m_Connections.getItFirst();
  return first_iterator;
}
/*--------------------------------------------------------------------------*/
IConnector::TIterator IConnector::getItLast()
{ CALL
  TIterator last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_pContainer = this;
  last_iterator.m_Iterator = m_Connections.getItLast();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
IConnector::TIteratorConst IConnector::getItLast() const
{ CALL
  TIteratorConst last_iterator;

  // Filling iterator inner structure.
  last_iterator.m_cpContainer = this;
  last_iterator.m_Iterator = m_Connections.getItLast();
  return last_iterator;
}
/*--------------------------------------------------------------------------*/
Tbool IConnector::notify(const IListener& a_crIListener) const
{ CALL
  TIteratorConst it = find(a_crIListener);

  if (it.isValid())
  {
    it.notify();
    return true;
  }
  else
  {
    WARNING(STR("Given IListener is not connected with the current IConnector."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
void IConnector::notifyAll() const
{ CALL
  TIteratorConst it_first = getItFirst();
  TIteratorConst it_current = it_first;

  if (it_current.isValid())
  {
    do
    {
      it_current.notify();
    } while ((it_current.stepForward() > 0) && (it_current != it_first));
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
