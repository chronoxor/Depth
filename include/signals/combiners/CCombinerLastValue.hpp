/*!
 *  \file    CCombinerLastValue.hpp Last value returning combiner class.
 *  \brief   Last value returning combiner class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Last value returning combiner class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Signal containers
    VERSION:   1.0
    CREATED:   02.06.2006 02:24:27

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
#ifndef __CCOMBINERLASTVALUE_HPP__
#define __CCOMBINERLASTVALUE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/common/MConceptConvert.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
//! Last value returning combiner class.
/*!
    This signal combiner stores and returns last slot value.
*/
template <typename T_SlotReturn, typename T_SignalResult = T_SlotReturn>
class CCombinerLastValue :
  public ICombiner<T_SlotReturn, T_SignalResult>
{
  //! Type for MConceptConstructible constraint checking.
  typedef T_SlotReturn TConstructibleCheckType;
  //! Type for MConceptConvert constraint checking (source type).
  typedef T_SlotReturn TConvertCheckSrcType;
  //! Type for MConceptConvert constraint checking (destination type).
  typedef T_SignalResult TConvertCheckDstType;
  //! Type for MConceptDepthType constraint checking.
  typedef CCombinerLastValue<T_SlotReturn, T_SignalResult> TDepthCheckType;

  // Check T_SlotReturn template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_SlotReturn template argument constraint to be convertible to T_SignalResult.
  REQUIRES_CONCEPT2(NConcept::NCommon, MConceptConvert, TConvertCheckSrcType, TConvertCheckDstType);
  // Check CCombinerLastValue class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CCombinerLastValue();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCombinerLastValue class.
  */
  CCombinerLastValue(const CCombinerLastValue<T_SlotReturn, T_SignalResult>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CCombinerLastValue();

  //! Operator: Equal to another combiner instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the combiner class.
      \param a_crInstance2 - Another instance of the combiner class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherSlotReturn, typename T_OtherSignalResult>
  friend Tbool operator == (const CCombinerLastValue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance1, const CCombinerLastValue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance2);
  //! Operator: Not equal to another combiner instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the combiner class.
      \param a_crInstance2 - Another instance of the combiner class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherSlotReturn, typename T_OtherSignalResult>
  friend Tbool operator != (const CCombinerLastValue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance1, const CCombinerLastValue<T_OtherSlotReturn, T_OtherSignalResult>& a_crInstance2);

  //! Operator: Assign another combiner class instance.
  /*!
      \param a_crInstance - Another instance of the combiner class.
      \return Reference to the current combiner class instance.
  */
  CCombinerLastValue<T_SlotReturn, T_SignalResult>& operator = (const CCombinerLastValue<T_SlotReturn, T_SignalResult>& a_crInstance);

  //! Set another CCombinerLastValue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCombinerLastValue class.
  */
  void set(const CCombinerLastValue<T_SlotReturn, T_SignalResult>& a_crInstance);

  // ICombiner interface overriding methods.
  virtual Tbool onStart();
  virtual Tbool onNext(const T_SlotReturn& a_crSlotReturn);
  virtual T_SignalResult onEnd();

  //! Serialize CCombinerLastValue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CCombinerLastValue class instances.
  /*!
      \param a_rInstance - Reference to another CCombinerLastValue class instance.
  */
  void swap(CCombinerLastValue<T_SlotReturn, T_SignalResult>& a_rInstance);

private:
  T_SlotReturn m_Result;                //!< Result value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/signals/combiners/CCombinerLastValue.inl>
/*==========================================================================*/
#endif
