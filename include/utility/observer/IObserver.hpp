/*!
 *  \file    IObserver.hpp Observer interface unites IConnector and IListener
 *           interfaces functionality in a solid interface.
 *  \brief   Observer interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Observer interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities observer
    VERSION:   1.0
    CREATED:   04.07.2007 21:16:56

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
#ifndef __IOBSERVER_HPP__
#define __IOBSERVER_HPP__
/*==========================================================================*/
#include <Depth/include/utility/observer/IConnector.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NObserver {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Observer interface.
/*!
    Observer   interface   unites   IConnector   and   IListener    interfaces
    functionality in a solid interface.

    The following example will illustrate how to use observers:
    \code
    class CMyObserver :
      public IObserver
    {
    public:
      virtual ~CMyObserver()
      {
        // Note that  we  must disconnect all  connections in this destructor!
        // It's important if you use  overriding  IObserver methods, otherwise
        // it's not so important and you may not manual disconnect connections
        // in destructor,  because  base IObserver class destructor also calls
        // 'IObserver::clear()' method.
        IObserver::clear();
      }

    private:
      // Overriding 'onConnect()' handler.
      virtual Tbool onConnect(const IConnector& a_rIConnector)
      {
        printf("Connect\n");
        return true;
      }

      // Overriding 'onDisconnect()' handler.
      virtual Tbool onDisconnect(const IConnector& a_rIConnector)
      {
        printf("Disconnect\n");
        return true;
      }
    };
    int main(int argc, char* argv[])
    {
      // Create empty observer A.
      // Observer A ->
      CMyObserver a;
      // Create empty observer B.
      // Observer A ->
      // Observer B ->
      CMyObserver b;
      // Connect observer B to A.
      // Observer A -> Observer B
      // Observer B -> Observer A
      a.insert(b);
      // Create empty observer C.
      // Observer A -> Observer B
      // Observer B -> Observer A
      // Observer C ->
      CMyObserver c;
      // Copy all connections from observer B to observer C.
      // Observer A -> Observer B
      // Observer A -> Observer C
      // Observer B -> Observer A
      // Observer C -> Observer A
      c.set(b);
      // Connect observer B to C.
      // Observer A -> Observer B
      // Observer A -> Observer C
      // Observer B -> Observer A
      // Observer B -> Observer C
      // Observer C -> Observer A
      // Observer C -> Observer B
      c.insert(b);
      // Disconnect all observers from A.
      // Observer A ->
      // Observer B -> Observer C
      // Observer C -> Observer B
      a.clear();
      // Disconnect observer C from B.
      // Observer A ->
      // Observer B ->
      // Observer C ->
      c.remove(b);
      return 0;
    }
    \endcode
*/
class BASE_API IObserver :
  public IConnector,
  public IListener
{
  //! Type for MConceptSwappable constraint checking.
  typedef IObserver TSwappableCheckType;

  // Check IObserver interface constraint to be a swappable interface.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

protected:
  //! Default interface protected constructor.
  IObserver();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IObserver interface.
  */
  IObserver(const IObserver& a_crInstance);

public:
  //! Container associative key type.
  typedef IConnector::TKey TKey;
  //! Container associative value type.
  typedef IConnector::TValue TValue;

  //! Container value type.
  typedef IConnector::TType TType;
  //! Container type.
  typedef IConnector::TContainer TContainer;
  //! Non constant set iterator type.
  typedef IConnector::TIterator TIterator;
  //! Constant set iterator type.
  typedef IConnector::TIteratorConst TIteratorConst;

  //! Interface virtual destructor.
  virtual ~IObserver();

  //! Swap two IObserver class instances.
  /*!
      \param a_rInstance - Reference to another IObserver class instance.
  */
  void swap(IObserver& a_rInstance);
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
//! Traits meta-class: IObserver container traits specialization.
template <>
class MTraitsContainer<NUtility::NObserver::IObserver> :
  public MType<NUtility::NObserver::IObserver>
{
public:
  //! Container value type.
  typedef NUtility::NObserver::IObserver::TType value;
  //! Container type.
  typedef NUtility::NObserver::IObserver::TContainer container;
  //! Container non constant iterator type.
  typedef NUtility::NObserver::IObserver::TIterator iterator;
  //! Container constant iterator type.
  typedef NUtility::NObserver::IObserver::TIteratorConst citerator;

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
#include <Depth/include/utility/observer/IObserver.inl>
/*==========================================================================*/
//! \example example-utility-IObserver.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-IObserver.cpp
/*==========================================================================*/
#endif
