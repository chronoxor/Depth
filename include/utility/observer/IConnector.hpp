/*!
 *  \file    IConnector.hpp Connector interface contains IListener interface
 *           instances and sends notifications to them.
 *  \brief   Connector interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Connector interface.

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
#ifndef __ICONNECTOR_HPP__
#define __ICONNECTOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptSwappable.hpp>
#include <Depth/include/containers/CSet.hpp>
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
//! Connector interface.
/*!
    Connector interface  contains  IListener  interface  instances  and  sends
    notification to them. Types of the notifications are the following:

    When  IListener  interface  instance  is  inserted  into  the   IConnector
    interface instance 'onConnect()' notification is send to the IListener. If
    IListener accepts the connection by returning 'true', a new connection  is
    established.

    When IListener interface instance is removed from the IConnector interface
    instance 'onDisconnect()'  notification  is  send  to  the  IListener.  If
    IListener accepts the disconnection by returning 'true', the connection is
    broke off.

    IConnector interface instance can send Information notification by calling
    'notify()' and 'notifyAll()' method. In the case 'onNotify()' notification
    is invoked in IListener interface instance(s).
*/
class BASE_API IConnector :
  public NCommon::NContainers::IAssociative<IConnector, IListener, IListener, IListener, CConnectorIterator, CConnectorIteratorConst>,
  public NCommon::NContainers::IAssociativeConst<IConnector, IListener, IListener, IListener, CConnectorIterator, CConnectorIteratorConst>,
  public NCommon::NContainers::IDequeConst<IConnector, IListener, CConnectorIterator, CConnectorIteratorConst>
{
  // Friend class: Connector iterator class (CConnectorIterator).
  friend class CConnectorIterator;
  // Friend class: Constant connector iterator class (CConnectorIteratorConst).
  friend class CConnectorIteratorConst;

  //! Type for MConceptSwappable constraint checking.
  typedef IConnector TSwappableCheckType;

  // Check IConnector interface constraint to be a swappable interface.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

protected:
  //! Default interface protected constructor.
  IConnector();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IConnector interface.
  */
  IConnector(const IConnector& a_crInstance);

  //! Operator: Assign another IConnector interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IConnector interface.
      \return Reference to the current interface instance.
  */
  IConnector& operator = (const IConnector& a_crInstance);

  //! Set another IConnector interface instance.
  /*!
      This method disconnects  all  IListener  interface  instances  from  the
      current IConnector interface instance. Then it  connects  all  IListener
      instances  form  the  given  IConnector  with  the  current   IConnector
      instance.

      \param a_crInstance - Constant reference to another instance of the IConnector interface.
      \return true  - if another IConnector interface instance was successfully set. \n
              false - if another IConnector interface instance was not successfully set. \n
  */
  Tbool set(const IConnector& a_crInstance);

public:
  //! Container associative key type.
  typedef IListener TKey;
  //! Container associative value type.
  typedef IListener TValue;

  //! Container value type.
  typedef IListener TType;
  //! Container type.
  typedef IConnector TContainer;
  //! Non constant set iterator type.
  typedef CConnectorIterator TIterator;
  //! Constant set iterator type.
  typedef CConnectorIteratorConst TIteratorConst;

  //! Interface virtual destructor.
  virtual ~IConnector();

  //! Operator: Insert IListener into IConnector.
  /*!
      \param a_crIListener - Constant reference to the IListener to insert.
      \return Reference to the current class instance.
  */
  IConnector& operator += (const IListener& a_crIListener);
  //! Operator: Insert another IConnector into IConnector.
  /*!
      \param a_crIConnector - Constant reference to the IConnector to insert.
      \return Reference to the current class instance.
  */
  IConnector& operator += (const IConnector& a_crIConnector);
  //! Operator: Insert IObserver into IConnector.
  /*!
      \param a_crIObserver - Constant reference to the IObserver to insert.
      \return Reference to the current class instance.
  */
  IConnector& operator += (const IObserver& a_crIObserver);
  //! Operator: Remove IListener from IConnector.
  /*!
      \param a_crIListener - Constant reference to the IListener to remove.
      \return Reference to the current class instance.
  */
  IConnector& operator -= (const IListener& a_crIListener);
  //! Operator: Remove another IConnector from IConnector.
  /*!
      \param a_crIConnector - Constant reference to the IConnector to remove.
      \return Reference to the current class instance.
  */
  IConnector& operator -= (const IConnector& a_crIConnector);
  //! Operator: Remove IObserver from IConnector.
  /*!
      \param a_crIObserver - Constant reference to the IObserver to remove.
      \return Reference to the current class instance.
  */
  IConnector& operator -= (const IObserver& a_crIObserver);

  //! Operator: Return non constant iterator to the IConnector item with given IListener.
  /*!
      \param a_crIListener - Constant reference to the searching IListener.
      \return Non constant iterator with given value or invalid empty iterator.
  */
  TIterator operator [] (const IListener& a_crIListener);
  //! Operator: Return constant iterator to the IConnector item with given IListener.
  /*!
      \param a_crIListener - Constant reference to the searching IListener.
      \return Constant iterator with given key or invalid empty iterator.
  */
  TIteratorConst operator [] (const IListener& a_crIListener) const;

  //! Is the given IListener interface instance connected with the current IConnector?
  /*!
      Method checks if the given IListener  interface  instance  is  connected
      with the current IConnector interface instance.

      \param a_crIListener - Constant reference to the IListener interface instance.
      \return true  - if the given IListener interface instance is connected with current IConnector instance. \n
              false - if the given IListener interface instance is not connected with current IConnector instance. \n
  */
  Tbool isConnected(const IListener& a_crIListener) const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociative interface overriding methods.
  virtual Tbool insert(const IListener& a_crIListener);
  virtual Tbool insert(const IConnector& a_crIConnector);
  virtual Tbool insert(const IObserver& a_crIObserver);
  virtual Tbool remove(const IListener& a_crIListener, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const IConnector& a_crIConnector, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const IObserver& a_crIObserver, const Tbool a_cRemoveSame = false);

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const IListener& a_crIListener1, const IListener& a_crIListener2) const;
  virtual TIterator      find(const IListener& a_crIListener);
  virtual TIteratorConst find(const IListener& a_crIListener) const;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Notify given IListener interface instance which is connected to the current IConnector.
  /*!
      Method send information notification to the  given  IListener  interface
      instance by invoking its 'onNotify()' method.

      \param a_crIListener - Constant reference to the IListener interface instance.
      \return true  - if the given IListener interface instance is connected with current IConnector instance. \n
              false - if the given IListener interface instance is not connected with current IConnector instance. \n
  */
  Tbool notify(const IListener& a_crIListener) const;
  //! Notify all connected IListener interface instances.
  /*!
      Method  send  information  notification  to  all   connected   IListener
      interface instances by invoking their 'onNotify()' methods.
  */
  void notifyAll() const;

  //! Swap two IConnector class instances.
  /*!
      \param a_rInstance - Reference to another IConnector class instance.
  */
  void swap(IConnector& a_rInstance);

private:
  NContainers::CSet<IListener*> m_Connections; //!< Set of connections.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: IConnector container traits specialization.
template <>
class MTraitsContainer<NUtility::NObserver::IConnector> :
  public MType<NUtility::NObserver::IConnector>
{
public:
  //! Container value type.
  typedef NUtility::NObserver::IConnector::TType value;
  //! Container type.
  typedef NUtility::NObserver::IConnector::TContainer container;
  //! Container non constant iterator type.
  typedef NUtility::NObserver::IConnector::TIterator iterator;
  //! Container constant iterator type.
  typedef NUtility::NObserver::IConnector::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = true;  //!< Is container non constant associative?
  static const Tbool isAssociativeConst = true;  //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/observer/IListener.hpp>
#include <Depth/include/utility/observer/IObserver.hpp>
/*--------------------------------------------------------------------------*/
#if (!defined(__CCONNECTORITERATOR_INCLUDED__) && !defined(__CCONNECTORITERATORCONST_INCLUDED__))
#define __CCONNECTORITERATOR_INCLUDED__
#define __CCONNECTORITERATORCONST_INCLUDED__
/*--------------------------------------------------------------------------*/
#undef __CCONNECTORITERATOR_HPP__
#include <Depth/include/utility/observer/CConnectorIterator.hpp>
#undef __CCONNECTORITERATORCONST_HPP__
#include <Depth/include/utility/observer/CConnectorIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#undef __CCONNECTORITERATOR_INCLUDED__
#undef __CCONNECTORITERATORCONST_INCLUDED__
#endif
/*--------------------------------------------------------------------------*/
#include <Depth/include/utility/observer/IConnector.inl>
/*==========================================================================*/
#endif
