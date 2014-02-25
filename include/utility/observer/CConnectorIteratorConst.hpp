/*!
 *  \file    CConnectorIteratorConst.hpp Connector constant iterator
 *           definitions. It gives ability to get IListener items.
 *  \brief   Connector constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Connector constant iterator class.

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
#ifndef __CCONNECTORITERATORCONST_HPP__
#define __CCONNECTORITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/utility/observer/IConnector.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
#if (defined(__CCONNECTORITERATORCONST_INCLUDED__) || defined(__DOXYGEN__))
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NObserver {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Connector constant iterator class.
/*!
    Connector constant iterator represents IConnector iterations method.  With
    this iterator you can perform looking into IListener items. Note that  you
    cannot modify IListener items with constant iterator. In this case use non
    constant connector iterator.
*/
class BASE_API CConnectorIteratorConst :
  public NCommon::NIterators::IIteratorConst<CConnectorIteratorConst, IListener, IListener, IConnector>,
  public NCommon::NIterators::IIteratorMoveAssociative<CConnectorIteratorConst, IListener, IListener, IListener, IListener, IConnector>,
  public NCommon::NIterators::IIteratorMoveBackward<CConnectorIteratorConst, IListener, IListener, IConnector>
{
  // Friend interface: IConnector interface (IConnector).
  friend class IConnector;

  //! Type for MConceptSwappable constraint checking.
  typedef CConnectorIteratorConst TSwappableCheckType;

  // Check CConnectorIteratorConst class constraint to be a swappable class.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

public:
  //! Iterator associative key type.
  typedef IListener TKey;
  //! Iterator associative value type.
  typedef IListener TValue;

  //! Iterator value type.
  typedef IListener TType;
  //! Iterator return type.
  typedef const IListener TReturn;
  //! Iterator container type.
  typedef const IConnector TContainer;
  //! Iterator base type.
  typedef CConnectorIteratorConst TIterator;

  //! Default class constructor.
  CConnectorIteratorConst();
  //! Initialize with non constant set iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CConnectorIterator class.
  */
  CConnectorIteratorConst(const CConnectorIterator& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CConnectorIteratorConst class.
  */
  CConnectorIteratorConst(const CConnectorIteratorConst& a_crInstance);
  //! Class virtual destructor.
  virtual ~CConnectorIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CConnectorIterator& a_crInstance1, const CConnectorIteratorConst& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CConnectorIteratorConst& a_crInstance1, const CConnectorIterator& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CConnectorIteratorConst& a_crInstance1, const CConnectorIteratorConst& a_crInstance2);

  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CConnectorIterator& a_crInstance1, const CConnectorIteratorConst& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CConnectorIteratorConst& a_crInstance1, const CConnectorIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CConnectorIteratorConst& a_crInstance1, const CConnectorIteratorConst& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CConnectorIteratorConst& operator = (const CConnectorIterator& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CConnectorIteratorConst& operator = (const CConnectorIteratorConst& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CConnectorIteratorConst& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CConnectorIteratorConst& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CConnectorIteratorConst& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CConnectorIteratorConst& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CConnectorIteratorConst operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CConnectorIteratorConst operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CConnectorIteratorConst operator + (const CConnectorIteratorConst& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CConnectorIteratorConst operator - (const CConnectorIteratorConst& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Find iterator with given IListener in the current IConnector.
  /*!
      \param a_crIListener - Constant reference to the searching IListener.
      \return Iterator with given IListener or invalid empty iterator.
  */
  CConnectorIteratorConst operator [] (const IListener& a_crIListener) const;

  //! Set CConnectorIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CConnectorIterator class.
  */
  void set(const CConnectorIterator& a_crInstance);
  //! Set another CConnectorIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CConnectorIteratorConst class.
  */
  void set(const CConnectorIteratorConst& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CConnectorIteratorConst getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CConnectorIteratorConst getBackward() const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const IConnector& getContainerRef() const;
  virtual const IConnector* getContainerPtr() const;
  virtual const IListener& getValueRef() const;
  virtual const IListener* getValuePtr() const;

  // IIteratorMoveAssociative interface overriding methods.
  virtual CConnectorIteratorConst find(const IListener& a_crIListener) const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Notify current IListener interface instance.
  /*!
      \return true  - if the current iterator is valid and notification was sent. \n
              false - if the current iterator is not valid and notification was not sent. \n
  */
  Tbool notify() const;
  //! Notify all connected IListener interface instances.
  /*!
      \return true  - if the current container is valid and notification was sent. \n
              false - if the current container is not valid and notification was not sent. \n
  */
  Tbool notifyAll() const;

  //! Swap two CConnectorIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CConnectorIteratorConst class instance.
  */
  void swap(CConnectorIteratorConst& a_rInstance);

private:
  const IConnector* m_cpContainer;                          //!< Constant pointer to the iterator container.
  NContainers::CSet<IListener*>::TIteratorConst m_Iterator; //!< Connection set constant iterator.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CConnectorIteratorConst(const IConnector* a_cpContainer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* ITERATOR TRAITS SPECIALIZATION DECLARATIONS                              */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: Connector constant iterator's traits specialization.
template <>
class MTraitsIterator<NUtility::NObserver::CConnectorIteratorConst> :
  public MType<NUtility::NObserver::CConnectorIteratorConst>
{
public:
  //! Iterator value type.
  typedef NUtility::NObserver::CConnectorIteratorConst::TType value;
  //! Iterator return type.
  typedef NUtility::NObserver::CConnectorIteratorConst::TReturn result;
  //! Iterator container type.
  typedef NUtility::NObserver::CConnectorIteratorConst::TContainer container;
  //! Iterator base type.
  typedef NUtility::NObserver::CConnectorIteratorConst::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = true;  //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/observer/CConnectorIteratorConst.inl>
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
