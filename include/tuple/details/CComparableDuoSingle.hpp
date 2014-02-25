/*!
 *  \file    CComparableDuoSingle.hpp Comparable duo template class represents
 *           comparable data structure which contains two fields (v1, v2) with
 *           different data types. Comparison can be made with '<' operator.
 *           Specialization of the comparable duo with single value.
 *  \brief   Comparable duo template class (single comparable value specialization).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable duo template class (single comparable value specialization).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple details
    VERSION:   1.0
    CREATED:   30.01.2007 23:16:28

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
#ifndef __CCOMPARABLEDUOSINGLE_HPP__
#define __CCOMPARABLEDUOSINGLE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/details/CComparableDuo.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Comparable duo template class (single comparable value specialization).
/*!
    Comparable duo with only one comparable value (second one is 'void').
*/
template <typename T_Type>
class CComparableDuo<T_Type, void>
{
  //! Type for the MConceptConstructible constraint checking for T_Type.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptBoolLessThan constraint checking for T_Type.
  typedef T_Type TTypeBoolLessThanCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CComparableDuo<T_Type, void> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Type template argument constraint to be a '<' comparable type.
  REQUIRES_CONCEPT1(NConcept::NOperators, MConceptBoolLessThan, TTypeBoolLessThanCheckType);
  // Check CComparableDuo class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  enum
  {
    N = 1                               //!< Number of fields in comparable duo.
  };

  //! Comparable duo first template type.
  typedef T_Type TType1;
  //! Comparable duo second template type.
  typedef void TType2;

  //! Default class constructor.
  CComparableDuo();
  //! Initialize comparable duo with given value.
  /*!
      \param a_crValue - Constant reference to the comparable duo value.
  */
  CComparableDuo(const T_Type& a_crValue);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableDuo class.
  */
  template <typename T_OtherType>
  CComparableDuo(const CComparableDuo<T_OtherType, void>& a_crInstance);
  //! Class destructor.
 ~CComparableDuo();

  //! Operator: Equal to another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is equal to another one. \n
              false - if CComparableDuo class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CComparableDuo<T_OtherType, void>& a_crInstance1, const CComparableDuo<T_OtherOtherType, void>& a_crInstance2);
  //! Operator: Not equal to another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is not equal to another one. \n
              false - if CComparableDuo class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CComparableDuo<T_OtherType, void>& a_crInstance1, const CComparableDuo<T_OtherOtherType, void>& a_crInstance2);

  //! Operator: Less than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is less than another one. \n
              false - if CComparableDuo class instance is not less than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator < (const CComparableDuo<T_OtherType, void>& a_crInstance1, const CComparableDuo<T_OtherOtherType, void>& a_crInstance2);
  //! Operator: More than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is more than another one. \n
              false - if CComparableDuo class instance is not more than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator > (const CComparableDuo<T_OtherType, void>& a_crInstance1, const CComparableDuo<T_OtherOtherType, void>& a_crInstance2);
  //! Operator: Less or equal than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is less or equal than another one. \n
              false - if CComparableDuo class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator <= (const CComparableDuo<T_OtherType, void>& a_crInstance1, const CComparableDuo<T_OtherOtherType, void>& a_crInstance2);
  //! Operator: More or equal than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is more or equal than another one. \n
              false - if CComparableDuo class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator >= (const CComparableDuo<T_OtherType, void>& a_crInstance1, const CComparableDuo<T_OtherOtherType, void>& a_crInstance2);

  //! Operator: Assign another CComparableDuo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableDuo class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CComparableDuo<T_Type, void>& operator = (const CComparableDuo<T_OtherType, void>& a_crInstance);

  //! Set comparable duo values.
  /*!
      \param a_crValue - Constant reference to the comparable duo value.
  */
  void set(const T_Type& a_crValue);
  //! Set another CComparableDuo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableDuo class.
  */
  template <typename T_OtherType>
  void set(const CComparableDuo<T_OtherType, void>& a_crInstance);

  //! Get first comparable duo value.
  /*!
      \return Reference to the first comparable duo value.
  */
  T_Type& getValue1();
  //! Get first comparable duo value (constant version).
  /*!
      \return Constant reference to the first comparable duo value.
  */
  const T_Type& getValue1() const;

  //! Get second comparable duo value.
  void getValue2();
  //! Get second comparable duo value (constant version).
  void getValue2() const;

  //! Serialize CComparableDuo class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CComparableDuo class instances.
  /*!
      \param a_rInstance - Reference to another CComparableDuo class instance.
  */
  void swap(CComparableDuo<T_Type, void>& a_rInstance);

private:
  T_Type m_Value;                       //!< Comparable duo value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/details/CComparableDuoSingle.inl>
/*==========================================================================*/
#endif
