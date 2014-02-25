/*!
 *  \file    CComparableDuoRecursive.hpp Comparable duo template class
 *           represents comparable data structure which contains two
 *           fields (v1, v2) with different data types. Comparison can
 *           be made with '<' operator. Specialization of the recursive
 *           comparable duo.
 *  \brief   Comparable duo template class (recursive comparable duo specialization).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable duo template class (recursive comparable duo specialization).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple details
    VERSION:   1.0
    CREATED:   30.01.2007 23:15:36

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
#ifndef __CCOMPARABLEDUORECURSIVE_HPP__
#define __CCOMPARABLEDUORECURSIVE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/details/CComparableDuoSingle.hpp>
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
//! Comparable duo template class (recursive comparable duo specialization).
/*!
    Comparable duo with another comparable duo in  the  second  value  of  the
    current comparable duo.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >
{
  //! Type for the MConceptConstructible constraint checking for T_Type1.
  typedef T_Type1 TType1ConstructibleCheckType;
  //! Type for MConceptBoolLessThan constraint checking for T_Type1.
  typedef T_Type1 TType1BoolLessThanCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> > TDepthCheckType;

  // Check T_Type1 template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TType1ConstructibleCheckType);
  // Check T_Type1 template argument constraint to be a '<' comparable type.
  REQUIRES_CONCEPT1(NConcept::NOperators, MConceptBoolLessThan, TType1BoolLessThanCheckType);
  // Check CComparableDuo class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  enum
  {
    N = CComparableDuo<T_Type2, T_Type3>::N + 1   //!< Number of fields in comparable duo.
  };

  //! Comparable duo first template type.
  typedef T_Type1 TType1;
  //! Comparable duo second template type.
  typedef CComparableDuo<T_Type2, T_Type3> TType2;

  //! Default class constructor.
  CComparableDuo();
  //! Initialize comparable duo with given value and another duo.
  /*!
      \param a_crValue1 - Constant reference to the first comparable duo value.
      \param a_crValue2 - Constant reference to the second comparable duo recursive value.
  */
  CComparableDuo(const T_Type1& a_crValue1, const CComparableDuo<T_Type2, T_Type3>& a_crValue2);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableDuo class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
  CComparableDuo(const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance);
  //! Class destructor.
 ~CComparableDuo();

  //! Operator: Equal to another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is equal to another one. \n
              false - if CComparableDuo class instance is not equal to another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3>
  friend Tbool operator == (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance1, const CComparableDuo<T_OtherOtherType1, CComparableDuo<T_OtherOtherType2, T_OtherOtherType3> >& a_crInstance2);
  //! Operator: Not equal to another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is not equal to another one. \n
              false - if CComparableDuo class instance is equal to another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3>
  friend Tbool operator != (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance1, const CComparableDuo<T_OtherOtherType1, CComparableDuo<T_OtherOtherType2, T_OtherOtherType3> >& a_crInstance2);

  //! Operator: Less than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is less than another one. \n
              false - if CComparableDuo class instance is not less than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3>
  friend Tbool operator < (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance1, const CComparableDuo<T_OtherOtherType1, CComparableDuo<T_OtherOtherType2, T_OtherOtherType3> >& a_crInstance2);
  //! Operator: More than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is more than another one. \n
              false - if CComparableDuo class instance is not more than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3>
  friend Tbool operator > (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance1, const CComparableDuo<T_OtherOtherType1, CComparableDuo<T_OtherOtherType2, T_OtherOtherType3> >& a_crInstance2);
  //! Operator: Less or equal than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is less or equal than another one. \n
              false - if CComparableDuo class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3>
  friend Tbool operator <= (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance1, const CComparableDuo<T_OtherOtherType1, CComparableDuo<T_OtherOtherType2, T_OtherOtherType3> >& a_crInstance2);
  //! Operator: More or equal than another CComparableDuo class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparableDuo class.
      \param a_crInstance2 - Constant reference to another instance of the CComparableDuo class.
      \return true  - if CComparableDuo class instance is more or equal than another one. \n
              false - if CComparableDuo class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherOtherType1, typename T_OtherOtherType2, typename T_OtherOtherType3>
  friend Tbool operator >= (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance1, const CComparableDuo<T_OtherOtherType1, CComparableDuo<T_OtherOtherType2, T_OtherOtherType3> >& a_crInstance2);

  //! Operator: Assign another CComparableDuo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableDuo class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
  CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& operator = (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance);

  //! Set comparable duo values.
  /*!
      \param a_crValue1 - Constant reference to the first comparable duo value.
      \param a_crValue2 - Constant reference to the second comparable duo recursive value.
  */
  void set(const T_Type1& a_crValue1, const CComparableDuo<T_Type2, T_Type3>& a_crValue2);
  //! Set another CComparableDuo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparableDuo class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
  void set(const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance);

  //! Get first comparable duo value.
  /*!
      \return Reference to the first comparable duo value.
  */
  T_Type1& getValue1();
  //! Get first comparable duo value (constant version).
  /*!
      \return Constant reference to the first comparable duo value.
  */
  const T_Type1& getValue1() const;

  //! Get second comparable duo recursive value.
  /*!
      \return Reference to the second comparable duo recursive value.
  */
  CComparableDuo<T_Type2, T_Type3>& getValue2();
  //! Get second comparable duo recursive value (constant version).
  /*!
      \return Constant reference to the second comparable duo recursive value.
  */
  const CComparableDuo<T_Type2, T_Type3>& getValue2() const;

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
  void swap(CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_rInstance);

private:
  T_Type1 m_Value1;                     //!< Comparable duo first value.
  CComparableDuo<T_Type2, T_Type3> m_Value2; //!< Comparable duo second recursive value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/details/CComparableDuoRecursive.inl>
/*==========================================================================*/
#endif
