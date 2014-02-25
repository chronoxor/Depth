/*!
 *  \file    CComparablePair.hpp Comparable pair template class represents
 *           data structure which contains two comparable fields: first (key),
 *           second (value). Comparison can be made with external 'LessThan'
 *           binary predicate comparators.
 *  \brief   Comparable pair template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable pair template class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   03.03.2006 20:33:27

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
#ifndef __CCOMPARABLEPAIR_HPP__
#define __CCOMPARABLEPAIR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIPair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Comparable pair template class.
/*!
    Comparable pair template class represents data  structure  which  contains
    two comparable fields: first (key), second(value). It can  be  used  as  a
    value in various kinds of a associative containers such  as  maps,  trees,
    etc.

    Comparison  can  be  made  with  external  'LessThan'   binary   predicate
    comparators.
*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_FirstType&>, typename T_SecondLessThanBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_SecondType&> >
class CComparablePair
{
  //! First type for the MConceptConstructible constraint checking.
  typedef T_FirstType TFirstConstructibleCheckType;
  //! First type for the MConceptPredicate2 constraint checking.
  typedef T_FirstLessThanBinaryPredicate TFirstPredicate2CheckType;
  //! First type for the MConceptPredicate2 constraint checking arguments.
  typedef const T_FirstType& TFirstPredicate2ArgumentCheckType;
  //! Second type for the MConceptConstructible constraint checking.
  typedef T_SecondType TSecondConstructibleCheckType;
  //! Second type for the MConceptPredicate2 constraint checking.
  typedef T_SecondLessThanBinaryPredicate TSecondPredicate2CheckType;
  //! Second type for the MConceptPredicate2 constraint checking arguments.
  typedef const T_SecondType& TSecondPredicate2ArgumentCheckType;
  //! Type for the MConceptIPair constraint checking.
  typedef CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> TPairCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> TDepthCheckType;

  // Check T_FirstType template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TFirstConstructibleCheckType);
  // Check T_FirstLessThanBinaryPredicate template argument constraint to be a suitable binary predicate type.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TFirstPredicate2CheckType, TFirstPredicate2ArgumentCheckType, TFirstPredicate2ArgumentCheckType);
  // Check T_SecondType template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TSecondConstructibleCheckType);
  // Check T_SecondLessThanBinaryPredicate template argument constraint to be a suitable binary predicate type.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TSecondPredicate2CheckType, TSecondPredicate2ArgumentCheckType, TSecondPredicate2ArgumentCheckType);
  // Check CComparablePair class constraint to be a pair type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIPair, TPairCheckType);
  // Check CComparablePair class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Pair first template type.
  typedef T_FirstType TFirst;
  //! Pair second template type.
  typedef T_SecondType TSecond;

  //! Pair first comparator type.
  typedef T_FirstLessThanBinaryPredicate TFirstLessThanBinaryPredicate;
  //! Pair second comparator type.
  typedef T_SecondLessThanBinaryPredicate TSecondLessThanBinaryPredicate;

  //! Default class constructor.
  /*!
      \param a_fFirstLessThan - 'LessThan' binary predicate comparator for the first type (default is T_FirstLessThanBinaryPredicate()).
      \param a_fSecondLessThan - 'LessThan' binary predicate comparator for the second type (default is T_SecondLessThanBinaryPredicate()).
  */
  CComparablePair(T_FirstLessThanBinaryPredicate a_fFirstLessThan = T_FirstLessThanBinaryPredicate(), T_SecondLessThanBinaryPredicate a_fSecondLessThan = T_SecondLessThanBinaryPredicate());
  //! Initialize pair with given values.
  /*!
      \param a_crFirstValue - Constant reference to the first comparable pair value.
      \param a_crSecondValue - Constant reference to the second comparable pair value.
      \param a_fFirstLessThan - 'LessThan' binary predicate comparator for the first type (default is T_FirstLessThanBinaryPredicate()).
      \param a_fSecondLessThan - 'LessThan' binary predicate comparator for the second type (default is T_SecondLessThanBinaryPredicate()).
  */
  CComparablePair(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue, T_FirstLessThanBinaryPredicate a_fFirstLessThan = T_FirstLessThanBinaryPredicate(), T_SecondLessThanBinaryPredicate a_fSecondLessThan = T_SecondLessThanBinaryPredicate());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparablePair class.
      \param a_fFirstLessThan - 'LessThan' binary predicate comparator for the first type (default is T_FirstLessThanBinaryPredicate()).
      \param a_fSecondLessThan - 'LessThan' binary predicate comparator for the second type (default is T_SecondLessThanBinaryPredicate()).
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
  CComparablePair(const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance, T_FirstLessThanBinaryPredicate a_fFirstLessThan = T_FirstLessThanBinaryPredicate(), T_SecondLessThanBinaryPredicate a_fSecondLessThan = T_SecondLessThanBinaryPredicate());
  //! Class destructor.
 ~CComparablePair();

  //! Operator: Equal to another CComparablePair class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparablePair class.
      \param a_crInstance2 - Constant reference to another instance of the CComparablePair class.
      \return true  - if CComparablePair class instance is equal to another one. \n
              false - if CComparablePair class instance is not equal to another one. \n
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate, typename T_OtherOtherFirstType, typename T_OtherOtherSecondType>
  friend Tbool operator == (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherOtherFirstType, T_OtherOtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance2);
  //! Operator: Not equal to another CComparablePair class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparablePair class.
      \param a_crInstance2 - Constant reference to another instance of the CComparablePair class.
      \return true  - if CComparablePair class instance is not equal to another one. \n
              false - if CComparablePair class instance is equal to another one. \n
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate, typename T_OtherOtherFirstType, typename T_OtherOtherSecondType>
  friend Tbool operator != (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherOtherFirstType, T_OtherOtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance2);

  //! Operator: Less than another CComparablePair class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparablePair class.
      \param a_crInstance2 - Constant reference to another instance of the CComparablePair class.
      \return true  - if CComparablePair class instance is less than another one. \n
              false - if CComparablePair class instance is not less than another one. \n
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate, typename T_OtherOtherFirstType, typename T_OtherOtherSecondType>
  friend Tbool operator < (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherOtherFirstType, T_OtherOtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance2);
  //! Operator: More than another CComparablePair class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparablePair class.
      \param a_crInstance2 - Constant reference to another instance of the CComparablePair class.
      \return true  - if CComparablePair class instance is more than another one. \n
              false - if CComparablePair class instance is not more than another one. \n
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate, typename T_OtherOtherFirstType, typename T_OtherOtherSecondType>
  friend Tbool operator > (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherOtherFirstType, T_OtherOtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance2);
  //! Operator: Less or equal than another CComparablePair class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparablePair class.
      \param a_crInstance2 - Constant reference to another instance of the CComparablePair class.
      \return true  - if CComparablePair class instance is less or equal than another one. \n
              false - if CComparablePair class instance is not less or equal than another one. \n
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate, typename T_OtherOtherFirstType, typename T_OtherOtherSecondType>
  friend Tbool operator <= (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherOtherFirstType, T_OtherOtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance2);
  //! Operator: More or equal than another CComparablePair class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CComparablePair class.
      \param a_crInstance2 - Constant reference to another instance of the CComparablePair class.
      \return true  - if CComparablePair class instance is more or equal than another one. \n
              false - if CComparablePair class instance is not more or equal than another one. \n
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate, typename T_OtherOtherFirstType, typename T_OtherOtherSecondType>
  friend Tbool operator >= (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherOtherFirstType, T_OtherOtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance2);

  //! Operator: Assign another CComparablePair class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparablePair class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
  CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& operator = (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance);

  //! Set comparable pair values.
  /*!
      \param a_crFirstValue - Constant reference to the first comparable pair value.
      \param a_crSecondValue - Constant reference to the second comparable pair value.
  */
  void set(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue);
  //! Set another CComparablePair class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CComparablePair class.
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
  void set(const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance);

  //! Get first comparable pair value.
  /*!
      \return Reference to the first comparable pair value.
  */
  T_FirstType& getFirst();
  //! Get first comparable pair value (constant version).
  /*!
      \return Constant reference to the first comparable pair value.
  */
  const T_FirstType& getFirst() const;

  //! Get second comparable pair value.
  /*!
      \return Reference to the second comparable pair value.
  */
  T_SecondType& getSecond();
  //! Get second comparable pair value (constant version).
  /*!
      \return Constant reference to the second comparable pair value.
  */
  const T_SecondType& getSecond() const;

  //! Compare two given values of the first pair type with the current first 'LessThan' binary predicate comparator.
  /*!
      This method use the current first 'LessThan' binary predicate comparator
      to compare two given values.

      \param a_crValue1 - Constant reference to the first value.
      \param a_crValue2 - Constant reference to the second value.
      \return true  - if first given value is less than second one. \n
              false - if first given value is not less than second one. \n
  */
  Tbool isFirstLessThan(const T_FirstType& a_crValue1, const T_FirstType& a_crValue2) const;
  //! Compare two given values of the second pair type with the current second 'LessThan' binary predicate comparator.
  /*!
      This method use the current first 'LessThan' binary predicate comparator
      to compare two given values.

      \param a_crValue1 - Constant reference to the first value.
      \param a_crValue2 - Constant reference to the second value.
      \return true  - if first given value is less than second one. \n
              false - if first given value is not less than second one. \n
  */
  Tbool isSecondLessThan(const T_SecondType& a_crValue1, const T_SecondType& a_crValue2) const;

  //! Serialize CComparablePair class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CComparablePair class instances.
  /*!
      \param a_rInstance - Reference to another CComparablePair class instance.
  */
  void swap(CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance);

private:
  TFirst  m_First;                      //!< Comparable pair first value (key).
  TSecond m_Second;                     //!< Comparable pair second value (value).

  T_FirstLessThanBinaryPredicate  m_fFirstLessThan;  //!< Current 'LessThan' binary predicate comparator for the first type.
  T_SecondLessThanBinaryPredicate m_fSecondLessThan; //!< Current 'LessThan' binary predicate comparator for the second type.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CComparablePair.inl>
/*==========================================================================*/
//! \example example-utility-CComparablePair.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-CComparablePair.cpp
/*==========================================================================*/
#endif
