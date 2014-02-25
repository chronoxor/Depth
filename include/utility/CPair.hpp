/*!
 *  \file    CPair.hpp Pair template class represents data structure which
 *           contains two fields: first (key), second (value).
 *  \brief   Pair template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pair template class.

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
#ifndef __CPAIR_HPP__
#define __CPAIR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptConstructible.hpp>
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
//! Pair template class.
/*!
    Pair template class represents data structure which contains  two  fields:
    first (key), second(value). It can be used as a value in various kinds  of
    a associative containers such as maps, trees, etc.
*/
template <typename T_FirstType, typename T_SecondType>
class CPair
{
  //! First type for the MConceptConstructible constraint checking.
  typedef T_FirstType TFirstConstructibleCheckType;
  //! Second type for the MConceptConstructible constraint checking.
  typedef T_SecondType TSecondConstructibleCheckType;
  //! Type for the MConceptIPair constraint checking.
  typedef CPair<T_FirstType, T_SecondType> TPairCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CPair<T_FirstType, T_SecondType> TDepthCheckType;

  // Check T_FirstType template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TFirstConstructibleCheckType);
  // Check T_SecondType template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TSecondConstructibleCheckType);
  // Check CPair class constraint to be a pair type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIPair, TPairCheckType);
  // Check CPair class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Pair first template type.
  typedef T_FirstType TFirst;
  //! Pair second template type.
  typedef T_SecondType TSecond;

  //! Default class constructor.
  CPair();
  //! Initialize pair with given values.
  /*!
      \param a_crFirstValue - Constant reference to the first pair value.
      \param a_crSecondValue - Constant reference to the second pair value.
  */
  CPair(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPair class.
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType>
  CPair(const CPair<T_OtherFirstType, T_OtherSecondType>& a_crInstance);
  //! Class destructor.
 ~CPair();

  //! Operator: Assign another CPair class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPair class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType>
  CPair<T_FirstType, T_SecondType>& operator = (const CPair<T_OtherFirstType, T_OtherSecondType>& a_crInstance);

  //! Set pair values.
  /*!
      \param a_crFirstValue - Constant reference to the first pair value.
      \param a_crSecondValue - Constant reference to the second pair value.
  */
  void set(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue);
  //! Set another CPair class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPair class.
  */
  template <typename T_OtherFirstType, typename T_OtherSecondType>
  void set(const CPair<T_OtherFirstType, T_OtherSecondType>& a_crInstance);

  //! Get first pair value.
  /*!
      \return Reference to the first pair value.
  */
  T_FirstType& getFirst();
  //! Get first pair value (constant version).
  /*!
      \return Constant reference to the first pair value.
  */
  const T_FirstType& getFirst() const;

  //! Get second pair value.
  /*!
      \return Reference to the second pair value.
  */
  T_SecondType& getSecond();
  //! Get second pair value (constant version).
  /*!
      \return Constant reference to the second pair value.
  */
  const T_SecondType& getSecond() const;

  //! Serialize CPair class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPair class instances.
  /*!
      \param a_rInstance - Reference to another CPair class instance.
  */
  void swap(CPair<T_FirstType, T_SecondType>& a_rInstance);

private:
  TFirst  m_First;                      //!< Pair first value (key).
  TSecond m_Second;                     //!< Pair second value (value).
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CPair.inl>
/*==========================================================================*/
//! \example example-utility-CPair.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-CPair.cpp
/*==========================================================================*/
#endif
