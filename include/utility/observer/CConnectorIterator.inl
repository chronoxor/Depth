/*!
 *  \file    CConnectorIterator.inl Connector non constant iterator
 *           definitions. It gives ability to get IListener items
 *           and to connect/disconnect another ones.
 *  \brief   Connector non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Connector non constant iterator class (inline).

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
#ifndef __CCONNECTORITERATOR_INL__
#define __CCONNECTORITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NObserver {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CConnectorIterator::CConnectorIterator() :
  NCommon::NIterators::IIterator<CConnectorIterator, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorMoveAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorMoveBackward<CConnectorIterator, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorInsertAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorRemoveAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  m_pContainer(NULL),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator::CConnectorIterator(IConnector* a_pContainer) :
  NCommon::NIterators::IIterator<CConnectorIterator, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorMoveAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorMoveBackward<CConnectorIterator, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorInsertAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorRemoveAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  m_pContainer(a_pContainer),
  m_Iterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator::CConnectorIterator(const CConnectorIterator& a_crInstance) :
  NCommon::NIterators::IIterator<CConnectorIterator, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorMoveAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorMoveBackward<CConnectorIterator, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorInsertAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  NCommon::NIterators::IIteratorRemoveAssociative<CConnectorIterator, IListener, IListener, IListener, IListener, IConnector>(),
  m_pContainer(NULL),
  m_Iterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator::~CConnectorIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CConnectorIterator& a_crInstance1, const CConnectorIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Iterator == a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CConnectorIterator& a_crInstance1, const CConnectorIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Iterator != a_crInstance2.m_Iterator));
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator& CConnectorIterator::operator = (const CConnectorIterator& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator& CConnectorIterator::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator& CConnectorIterator::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator& CConnectorIterator::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator& CConnectorIterator::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator CConnectorIterator::operator ++ (int)
{ CALL
  CConnectorIterator temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator CConnectorIterator::operator -- (int)
{ CALL
  CConnectorIterator temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CConnectorIterator operator + (const CConnectorIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CConnectorIterator temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CConnectorIterator operator - (const CConnectorIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CConnectorIterator temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator CConnectorIterator::operator [] (const IListener& a_crIListener) const
{ CALL
  return find(a_crIListener);
}
/*--------------------------------------------------------------------------*/
inline void CConnectorIterator::set(const CConnectorIterator& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Iterator = a_crInstance.m_Iterator;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator CConnectorIterator::getForward() const
{ CALL
  CConnectorIterator it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CConnectorIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator CConnectorIterator::getBackward() const
{ CALL
  CConnectorIterator it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CConnectorIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline Tbool CConnectorIterator::isValid() const
{ CALL
  return (isValidContainer() && m_Iterator.isValid());
}
/*--------------------------------------------------------------------------*/
inline Tbool CConnectorIterator::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
inline IConnector& CConnectorIterator::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline IConnector* CConnectorIterator::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline IListener& CConnectorIterator::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return *m_Iterator.getValueRef();
}
/*--------------------------------------------------------------------------*/
inline IListener* CConnectorIterator::getValuePtr() const
{ CALL
  if (isValid())
    return *m_Iterator.getValuePtr();
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
inline CConnectorIterator CConnectorIterator::find(const IListener& a_crIListener) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given IListener in the IConnector with the invalid iterator container."));

  return m_pContainer->find(a_crIListener);
}
/*--------------------------------------------------------------------------*/
inline Tuint CConnectorIterator::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid set iterator."))
  {
    return 0;
  }

  return m_Iterator.stepForward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
inline Tuint CConnectorIterator::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid set iterator."))
  {
    return 0;
  }

  return m_Iterator.stepBackward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
inline void CConnectorIterator::swap(CConnectorIterator& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_Iterator, a_rInstance.m_Iterator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
