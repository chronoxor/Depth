/*!
 *  \file    CComparableTuple.hpp Comparable tuple represents template
 *           comparable data structure with many elements inside. It
 *           can be used as a function return value to give ability to
 *           return from function more than one value. Comparison can
 *           be made with '<' operator.
 *  \brief   Comparable tuple template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable tuple template class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   30.01.2007 00:03:38

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
#ifndef __CCOMPARABLETUPLE_HPP__
#define __CCOMPARABLETUPLE_HPP__
/*==========================================================================*/
#include <Depth/include/base/CBlank.hpp>
#include <Depth/include/tuple/MComparableTupleValue.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Comparable tuple template class.
/*!
    Comparable tuple represents template comparable data structure  with  many
    elements inside. It can be used as a function return value to give ability
    to return from function more than one value.

    Comparison can be made with '<' operator.
*/
template <typename T_Type1, typename T_Type2 = NBase::CBlank, typename T_Type3 = NBase::CBlank, typename T_Type4 = NBase::CBlank, typename T_Type5 = NBase::CBlank, typename T_Type6 = NBase::CBlank, typename T_Type7 = NBase::CBlank, typename T_Type8 = NBase::CBlank, typename T_Type9 = NBase::CBlank, typename T_Type10 = NBase::CBlank>
class CComparableTuple :
  public NDetails::CComparableDuo<T_Type1, typename CComparableTuple<T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10, NBase::CBlank>::TBase>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10> TDepthCheckType;

  // Check CComparableTuple class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Comparable tuple base template type.
  typedef NDetails::CComparableDuo<T_Type1, typename CComparableTuple<T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10, NBase::CBlank>::TBase> TBase;

  //! Default class constructor.
  CComparableTuple();
  //! Initialize comparable tuple with given values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st comparable tuple value.
      \param a_crValue2 - Constant reference to the 2'nd comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th comparable tuple value (default is NDepth::Base::CBlank()).
  */
  CComparableTuple(const T_Type1& a_crValue1, const T_Type2& a_crValue2 = NBase::CBlank(), const T_Type3& a_crValue3 = NBase::CBlank(), const T_Type4& a_crValue4 = NBase::CBlank(), const T_Type5& a_crValue5 = NBase::CBlank(), const T_Type6& a_crValue6 = NBase::CBlank(), const T_Type7& a_crValue7 = NBase::CBlank(), const T_Type8& a_crValue8 = NBase::CBlank(), const T_Type9& a_crValue9 = NBase::CBlank(), const T_Type10& a_crValue10 = NBase::CBlank());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
  CComparableTuple(const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance);
  //! Class destructor.
 ~CComparableTuple();

  //! Operator: Equal to another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is equal to another one. \n
              false - if CComparableTuple class instance is not equal to another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3, typename T_OtherOtherType4, typename T_OtherOtherType5, typename T_OtherOtherType6, typename T_OtherOtherType7, typename T_OtherOtherType8, typename T_OtherOtherType9, typename T_OtherOtherType10>
  friend Tbool operator == (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, T_OtherOtherType3, T_OtherOtherType4, T_OtherOtherType5, T_OtherOtherType6, T_OtherOtherType7, T_OtherOtherType8, T_OtherOtherType9, T_OtherOtherType10>& a_crInstance2);
  //! Operator: Not equal to another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is not equal to another one. \n
              false - if CComparableTuple class instance is equal to another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3, typename T_OtherOtherType4, typename T_OtherOtherType5, typename T_OtherOtherType6, typename T_OtherOtherType7, typename T_OtherOtherType8, typename T_OtherOtherType9, typename T_OtherOtherType10>
  friend Tbool operator != (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, T_OtherOtherType3, T_OtherOtherType4, T_OtherOtherType5, T_OtherOtherType6, T_OtherOtherType7, T_OtherOtherType8, T_OtherOtherType9, T_OtherOtherType10>& a_crInstance2);

  //! Operator: Less than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is less than another one. \n
              false - if CComparableTuple class instance is not less than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3, typename T_OtherOtherType4, typename T_OtherOtherType5, typename T_OtherOtherType6, typename T_OtherOtherType7, typename T_OtherOtherType8, typename T_OtherOtherType9, typename T_OtherOtherType10>
  friend Tbool operator < (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, T_OtherOtherType3, T_OtherOtherType4, T_OtherOtherType5, T_OtherOtherType6, T_OtherOtherType7, T_OtherOtherType8, T_OtherOtherType9, T_OtherOtherType10>& a_crInstance2);
  //! Operator: More than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is more than another one. \n
              false - if CComparableTuple class instance is not more than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3, typename T_OtherOtherType4, typename T_OtherOtherType5, typename T_OtherOtherType6, typename T_OtherOtherType7, typename T_OtherOtherType8, typename T_OtherOtherType9, typename T_OtherOtherType10>
  friend Tbool operator > (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, T_OtherOtherType3, T_OtherOtherType4, T_OtherOtherType5, T_OtherOtherType6, T_OtherOtherType7, T_OtherOtherType8, T_OtherOtherType9, T_OtherOtherType10>& a_crInstance2);
  //! Operator: Less or equal than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is less or equal than another one. \n
              false - if CComparableTuple class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3, typename T_OtherOtherType4, typename T_OtherOtherType5, typename T_OtherOtherType6, typename T_OtherOtherType7, typename T_OtherOtherType8, typename T_OtherOtherType9, typename T_OtherOtherType10>
  friend Tbool operator <= (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, T_OtherOtherType3, T_OtherOtherType4, T_OtherOtherType5, T_OtherOtherType6, T_OtherOtherType7, T_OtherOtherType8, T_OtherOtherType9, T_OtherOtherType10>& a_crInstance2);
  //! Operator: More or equal than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is more or equal than another one. \n
              false - if CComparableTuple class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3, typename T_OtherOtherType4, typename T_OtherOtherType5, typename T_OtherOtherType6, typename T_OtherOtherType7, typename T_OtherOtherType8, typename T_OtherOtherType9, typename T_OtherOtherType10>
  friend Tbool operator >= (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, T_OtherOtherType3, T_OtherOtherType4, T_OtherOtherType5, T_OtherOtherType6, T_OtherOtherType7, T_OtherOtherType8, T_OtherOtherType9, T_OtherOtherType10>& a_crInstance2);

  //! Operator: Assign another CComparableTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
  CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& operator = (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance);

  //! Set comparable tuple values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st comparable tuple value.
      \param a_crValue2 - Constant reference to the 2'nd comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th comparable tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th comparable tuple value (default is NDepth::Base::CBlank()).
  */
  void set(const T_Type1& a_crValue1, const T_Type2& a_crValue2 = NBase::CBlank(), const T_Type3& a_crValue3 = NBase::CBlank(), const T_Type4& a_crValue4 = NBase::CBlank(), const T_Type5& a_crValue5 = NBase::CBlank(), const T_Type6& a_crValue6 = NBase::CBlank(), const T_Type7& a_crValue7 = NBase::CBlank(), const T_Type8& a_crValue8 = NBase::CBlank(), const T_Type9& a_crValue9 = NBase::CBlank(), const T_Type10& a_crValue10 = NBase::CBlank());
  //! Set another CComparableTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
  void set(const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance);

  //! Get N'th comparable tuple value.
  /*!
      \return Reference to the N'th comparable tuple value.
  */
  template <Tsint t_N>
  typename MComparableTupleType<t_N, TBase>::TType& getValue();
  //! Get N'th comparable tuple value (constant version).
  /*!
      \return Constant reference to the N'th comparable tuple value.
  */
  template <Tsint t_N>
  const typename MComparableTupleType<t_N, TBase>::TType& getValue() const;

  //! Serialize CComparableTuple class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CComparableTuple class instances.
  /*!
      \param a_rInstance - Reference to another CComparableTuple class instance.
  */
  void swap(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_rInstance);
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple template class (single comparable value specialization).
/*!
    Comparable tuple class specialization for comparable tuple with one value.
*/
template <typename T_Type>
class CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> :
  public NDetails::CComparableDuo<T_Type, void>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> TDepthCheckType;

  // Check CComparableTuple class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Comparable tuple base template type.
  typedef NDetails::CComparableDuo<T_Type, void> TBase;

  //! Default class constructor.
  CComparableTuple();
  //! Initialize comparable tuple with given values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st comparable tuple value.
      \param a_crValue2 - Constant reference to the 2'nd comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th comparable tuple empty value (default is NDepth::Base::CBlank()).
  */
  CComparableTuple(const T_Type& a_crValue1, const NBase::CBlank& a_crValue2 = NBase::CBlank(), const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
  */
  template <typename T_OtherType>
  CComparableTuple(const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);
  //! Class destructor.
 ~CComparableTuple();

  //! Operator: Equal to another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is equal to another one. \n
              false - if CComparableTuple class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: Not equal to another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is not equal to another one. \n
              false - if CComparableTuple class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);

  //! Operator: Less than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is less than another one. \n
              false - if CComparableTuple class instance is not less than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator < (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: More than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is more than another one. \n
              false - if CComparableTuple class instance is not more than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator > (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: Less or equal than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is less or equal than another one. \n
              false - if CComparableTuple class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator <= (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: More or equal than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is more or equal than another one. \n
              false - if CComparableTuple class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator >= (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);

  //! Operator: Assign another CComparableTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& operator = (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Set comparable tuple values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st comparable tuple value.
      \param a_crValue2 - Constant reference to the 2'nd comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th comparable tuple empty value (default is NDepth::Base::CBlank()).
  */
  void set(const T_Type& a_crValue1, const NBase::CBlank& a_crValue2 = NBase::CBlank(), const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Set another CComparableTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
  */
  template <typename T_OtherType>
  void set(const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Get N'th comparable tuple value.
  /*!
      \return Reference to the N'th comparable tuple value.
  */
  template <Tsint t_N>
  typename MComparableTupleType<t_N, TBase>::TType& getValue();
  //! Get N'th comparable tuple value (constant version).
  /*!
      \return Constant reference to the N'th comparable tuple value.
  */
  template <Tsint t_N>
  const typename MComparableTupleType<t_N, TBase>::TType& getValue() const;

  //! Serialize CComparableTuple class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CComparableTuple class instances.
  /*!
      \param a_rInstance - Reference to another CComparableTuple class instance.
  */
  void swap(CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_rInstance);
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple template class (double comparable values specialization).
/*!
    Comparable tuple  class  specialization  for  comparable  tuple  with  two
    values.
*/
template <typename T_Type1, typename T_Type2>
class CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> :
  public NDetails::CComparableDuo<T_Type1, T_Type2>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> TDepthCheckType;

  // Check CComparableTuple class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Comparable tuple base template type.
  typedef NDetails::CComparableDuo<T_Type1, T_Type2> TBase;

  //! Default class constructor.
  CComparableTuple();
  //! Initialize comparable tuple with given values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st comparable tuple value.
      \param a_crValue2 - Constant reference to the 2'nd comparable tuple value.
      \param a_crValue3 - Constant reference to the 3'rd comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th comparable tuple empty value (default is NDepth::Base::CBlank()).
  */
  CComparableTuple(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2>
  CComparableTuple(const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);
  //! Class destructor.
 ~CComparableTuple();

  //! Operator: Equal to another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is equal to another one. \n
              false - if CComparableTuple class instance is not equal to another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherOtherType1, typename T_OtherOtherType2>
  friend Tbool operator == (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: Not equal to another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is not equal to another one. \n
              false - if CComparableTuple class instance is equal to another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherOtherType1, typename T_OtherOtherType2>
  friend Tbool operator != (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);

  //! Operator: Less than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is less than another one. \n
              false - if CComparableTuple class instance is not less than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherOtherType1, typename T_OtherOtherType2>
  friend Tbool operator < (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: More than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is more than another one. \n
              false - if CComparableTuple class instance is not more than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherOtherType1, typename T_OtherOtherType2>
  friend Tbool operator > (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: Less or equal than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is less or equal than another one. \n
              false - if CComparableTuple class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherOtherType1, typename T_OtherOtherType2>
  friend Tbool operator <= (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);
  //! Operator: More or equal than another CComparableTuple class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableTuple class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableTuple class.
      \return true  - if CComparableTuple class instance is more or equal than another one. \n
              false - if CComparableTuple class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherOtherType1, typename T_OtherOtherType2>
  friend Tbool operator >= (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherOtherType1, T_OtherOtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2);

  //! Operator: Assign another CComparableTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType1, typename T_OtherType2>
  CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& operator = (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Set comparable tuple values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st comparable tuple value.
      \param a_crValue2 - Constant reference to the 2'nd comparable tuple value.
      \param a_crValue3 - Constant reference to the 3'rd comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th comparable tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th comparable tuple empty value (default is NDepth::Base::CBlank()).
  */
  void set(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Set another CComparableTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2>
  void set(const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Get N'th comparable tuple value.
  /*!
      \return Reference to the N'th comparable tuple value.
  */
  template <Tsint t_N>
  typename MComparableTupleType<t_N, TBase>::TType& getValue();
  //! Get N'th comparable tuple value (constant version).
  /*!
      \return Constant reference to the N'th comparable tuple value.
  */
  template <Tsint t_N>
  const typename MComparableTupleType<t_N, TBase>::TType& getValue() const;

  //! Serialize CComparableTuple class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CComparableTuple class instances.
  /*!
      \param a_rInstance - Reference to another CComparableTuple class instance.
  */
  void swap(CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/CComparableTuple.inl>
/*==========================================================================*/
//! \example example-tuple-CComparableTuple.cpp
/*--------------------------------------------------------------------------*/
//! \test test-tuple-CComparableTuple.cpp
/*==========================================================================*/
#endif
