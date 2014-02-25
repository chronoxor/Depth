/*!
 *  \file    CCombinerQueue.hpp Queue collecting combiner class.
 *  \brief   Queue collecting combiner class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Queue collecting combiner class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Signal containers
    VERSION:   1.0
    CREATED:   23.06.2008 03:57:04

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
#ifndef __CCOMBINERQUEUE_HPP__
#define __CCOMBINERQUEUE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/containers/MConceptQueue.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CQueue.hpp>
#include <Depth/include/signals/combiners/ICombiner.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSignals {
/*--------------------------------------------------------------------------*/
namespace NCombiners {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Queue collecting combiner class.
/*!
    This signal combiner collects all slot values in the queue container.
*/
template <typename T_SlotReturn, typename T_SignalResult = NContainers::CQueue<T_SlotReturn> >
class CCombinerQueue :
  public ICombiner<T_SlotReturn, T_SignalResult>
{
  //! Type for MConceptQueue constraint checking.
  typedef T_SignalResult TQueueCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CCombinerQueue<T_SlotReturn, T_SignalResult> TDepthCheckType;

  // Check T_SignalResult template argument constraint to be a queue container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptQueue, TQueueCheckType);
  // Check CCombinerQueue class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CCombinerQueue();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCombinerQueue class.
  */
  CCombinerQueue(const CCombinerQueue<T_SlotReturn, T_SignalResult>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CCombinerQueue();

  //! Operator: Equal to another combiner instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the combiner class.
      \param a_crInstance2 - Another instance of the combiner class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherSlotReturn, typename T_OtherSignalResult>
  friend Tbool operator == (const CCombinerQueue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance1, const CCombinerQueue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance2);
  //! Operator: Not equal to another combiner instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the combiner class.
      \param a_crInstance2 - Another instance of the combiner class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherSlotReturn, typename T_OtherSignalResult>
  friend Tbool operator != (const CCombinerQueue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance1, const CCombinerQueue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance2);

  //! Operator: Assign another combiner class instance.
  /*!
      \param a_crInstance - Another instance of the combiner class.
      \return Reference to the current combiner class instance.
  */
  CCombinerQueue<T_SlotReturn, T_SignalResult>& operator = (const CCombinerQueue<T_SlotReturn, T_SignalResult>& a_crInstance);

  //! Set another CCombinerQueue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCombinerQueue class.
  */
  void set(const CCombinerQueue<T_SlotReturn, T_SignalResult>& a_crInstance);

  // ICombiner interface overriding methods.
  virtual Tbool onStart();
  virtual Tbool onNext(const T_SlotReturn& a_crSlotReturn);
  virtual T_SignalResult onEnd();

  //! Serialize CCombinerQueue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CCombinerQueue class instances.
  /*!
      \param a_rInstance - Reference to another CCombinerQueue class instance.
  */
  void swap(CCombinerQueue<T_SlotReturn, T_SignalResult>& a_rInstance);

private:
  T_SignalResult m_Result;              //!< Result queue container.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/signals/combiners/CCombinerQueue.inl>
/*==========================================================================*/
#endif
