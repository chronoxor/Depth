/*!
 *  \file    CTuple.hpp Tuple represents template data structure with many
 *           elements inside. It can be used as a function return value to
 *           give ability to return from function more than one value.
 *  \brief   Tuple template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple template class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   07.03.2006 22:03:53

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
#ifndef __CTUPLE_HPP__
#define __CTUPLE_HPP__
/*==========================================================================*/
#include <Depth/include/base/CBlank.hpp>
#include <Depth/include/tuple/MTupleValue.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Tuple template class.
/*!
    Tuple represents template data structure with many elements inside. It can
    be used as a function return value to give ability to return from function
    more than one value.
*/
template <typename T_Type1, typename T_Type2 = NBase::CBlank, typename T_Type3 = NBase::CBlank, typename T_Type4 = NBase::CBlank, typename T_Type5 = NBase::CBlank, typename T_Type6 = NBase::CBlank, typename T_Type7 = NBase::CBlank, typename T_Type8 = NBase::CBlank, typename T_Type9 = NBase::CBlank, typename T_Type10 = NBase::CBlank>
class CTuple :
  public NDetails::CDuo<T_Type1, typename CTuple<T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10, NBase::CBlank>::TBase>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10> TDepthCheckType;

  // Check CTuple class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Tuple base template type.
  typedef NDetails::CDuo<T_Type1, typename CTuple<T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10, NBase::CBlank>::TBase> TBase;

  //! Default class constructor.
  CTuple();
  //! Initialize tuple with given values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th tuple value (default is NDepth::Base::CBlank()).
  */
  CTuple(const T_Type1& a_crValue1, const T_Type2& a_crValue2 = NBase::CBlank(), const T_Type3& a_crValue3 = NBase::CBlank(), const T_Type4& a_crValue4 = NBase::CBlank(), const T_Type5& a_crValue5 = NBase::CBlank(), const T_Type6& a_crValue6 = NBase::CBlank(), const T_Type7& a_crValue7 = NBase::CBlank(), const T_Type8& a_crValue8 = NBase::CBlank(), const T_Type9& a_crValue9 = NBase::CBlank(), const T_Type10& a_crValue10 = NBase::CBlank());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
  CTuple(const CTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance);
  //! Class destructor.
 ~CTuple();

  //! Operator: Assign another CTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
  CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& operator = (const CTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance);

  //! Set tuple values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th tuple value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th tuple value (default is NDepth::Base::CBlank()).
  */
  void set(const T_Type1& a_crValue1, const T_Type2& a_crValue2 = NBase::CBlank(), const T_Type3& a_crValue3 = NBase::CBlank(), const T_Type4& a_crValue4 = NBase::CBlank(), const T_Type5& a_crValue5 = NBase::CBlank(), const T_Type6& a_crValue6 = NBase::CBlank(), const T_Type7& a_crValue7 = NBase::CBlank(), const T_Type8& a_crValue8 = NBase::CBlank(), const T_Type9& a_crValue9 = NBase::CBlank(), const T_Type10& a_crValue10 = NBase::CBlank());
  //! Set another CTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
  void set(const CTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance);

  //! Get N'th tuple value.
  /*!
      \return Reference to the N'th tuple value.
  */
  template <Tsint t_N>
  typename MTupleType<t_N, TBase>::TType& getValue();
  //! Get N'th tuple value (constant version).
  /*!
      \return Constant reference to the N'th tuple value.
  */
  template <Tsint t_N>
  const typename MTupleType<t_N, TBase>::TType& getValue() const;

  //! Serialize CTuple class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTuple class instances.
  /*!
      \param a_rInstance - Reference to another CTuple class instance.
  */
  void swap(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_rInstance);
};
/*--------------------------------------------------------------------------*/
//! Tuple template class (single value specialization).
/*!
    Tuple class specialization for tuple with one value.
*/
template <typename T_Type>
class CTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> :
  public NDetails::CDuo<T_Type, void>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> TDepthCheckType;

  // Check CTuple class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Tuple base template type.
  typedef NDetails::CDuo<T_Type, void> TBase;

  //! Default class constructor.
  CTuple();
  //! Initialize tuple with given values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th tuple empty value (default is NDepth::Base::CBlank()).
  */
  CTuple(const T_Type& a_crValue1, const NBase::CBlank& a_crValue2 = NBase::CBlank(), const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
  */
  template <typename T_OtherType>
  CTuple(const CTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);
  //! Class destructor.
 ~CTuple();

  //! Operator: Assign another CTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& operator = (const CTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Set tuple values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue3 - Constant reference to the 3'rd tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th tuple empty value (default is NDepth::Base::CBlank()).
  */
  void set(const T_Type& a_crValue1, const NBase::CBlank& a_crValue2 = NBase::CBlank(), const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Set another CTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
  */
  template <typename T_OtherType>
  void set(const CTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Get N'th tuple value.
  /*!
      \return Reference to the N'th tuple value.
  */
  template <Tsint t_N>
  typename MTupleType<t_N, TBase>::TType& getValue();
  //! Get N'th tuple value (constant version).
  /*!
      \return Constant reference to the N'th tuple value.
  */
  template <Tsint t_N>
  const typename MTupleType<t_N, TBase>::TType& getValue() const;

  //! Serialize CTuple class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTuple class instances.
  /*!
      \param a_rInstance - Reference to another CTuple class instance.
  */
  void swap(CTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_rInstance);
};
/*--------------------------------------------------------------------------*/
//! Tuple template class (double value specialization).
/*!
    Tuple class specialization for tuple with two value.
*/
template <typename T_Type1, typename T_Type2>
class CTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> :
  public NDetails::CDuo<T_Type1, T_Type2>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank> TDepthCheckType;

  // Check CTuple class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Tuple base template type.
  typedef NDetails::CDuo<T_Type1, T_Type2> TBase;

  //! Default class constructor.
  CTuple();
  //! Initialize tuple with given values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th tuple empty value (default is NDepth::Base::CBlank()).
  */
  CTuple(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2>
  CTuple(const CTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);
  //! Class destructor.
 ~CTuple();

  //! Operator: Assign another CTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType1, typename T_OtherType2>
  CTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& operator = (const CTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Set tuple values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue4 - Constant reference to the 4'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue5 - Constant reference to the 5'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue6 - Constant reference to the 6'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue7 - Constant reference to the 7'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue8 - Constant reference to the 8'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue9 - Constant reference to the 9'th tuple empty value (default is NDepth::Base::CBlank()).
      \param a_crValue10 - Constant reference to the 10'th tuple empty value (default is NDepth::Base::CBlank()).
  */
  void set(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const NBase::CBlank& a_crValue3 = NBase::CBlank(), const NBase::CBlank& a_crValue4 = NBase::CBlank(), const NBase::CBlank& a_crValue5 = NBase::CBlank(), const NBase::CBlank& a_crValue6 = NBase::CBlank(), const NBase::CBlank& a_crValue7 = NBase::CBlank(), const NBase::CBlank& a_crValue8 = NBase::CBlank(), const NBase::CBlank& a_crValue9 = NBase::CBlank(), const NBase::CBlank& a_crValue10 = NBase::CBlank());
  //! Set another CTuple class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
  */
  template <typename T_OtherType1, typename T_OtherType2>
  void set(const CTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance);

  //! Get N'th tuple value.
  /*!
      \return Reference to the N'th tuple value.
  */
  template <Tsint t_N>
  typename MTupleType<t_N, TBase>::TType& getValue();
  //! Get N'th tuple value (constant version).
  /*!
      \return Constant reference to the N'th tuple value.
  */
  template <Tsint t_N>
  const typename MTupleType<t_N, TBase>::TType& getValue() const;

  //! Serialize CTuple class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTuple class instances.
  /*!
      \param a_rInstance - Reference to another CTuple class instance.
  */
  void swap(CTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/CTuple.inl>
/*==========================================================================*/
//! \example example-tuple-CTuple.cpp
/*--------------------------------------------------------------------------*/
//! \test test-tuple-CTuple.cpp
/*==========================================================================*/
#endif
