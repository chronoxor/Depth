/*!
 *  \file    CSpanValue.hpp Template single span value class. Span value
 *           represents open/close interval of values, which is kept inside
 *           CSpan container.
 *  \brief   Span value class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Span value class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   12.09.2007 22:42:08

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
#ifndef __CSPANVALUE_HPP__
#define __CSPANVALUE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIPair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Span value class.
/*!
    Span value represents single open/close interval,  which  is  kept  inside
    CSpan container.
*/
template <typename T_Type>
class CSpanValue
{
  //! Type for the MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for the MConceptIPair constraint checking.
  typedef CSpanValue<T_Type> TPairCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CSpanValue<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check CSpanValue class constraint to be a pair type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIPair, TPairCheckType);
  // Check CSpanValue class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Span value first template type.
  typedef T_Type TFirst;
  //! Span value second template type.
  typedef T_Type TSecond;

  //! Default class constructor.
  CSpanValue();
  //! Initialize span value with a single value.
  /*!
      \param a_crValue - Constant reference to the single span value.
  */
  CSpanValue(const T_Type& a_crValue);
  //! Initialize span value with given values.
  /*!
      \param a_crFirstValue - Constant reference to the first span value.
      \param a_crSecondValue - Constant reference to the second span value.
      \param a_cIncludeFirstValue - Include first span value flag (default is true).
      \param a_cIncludeSecondValue - Include second span value flag (default is true).
  */
  CSpanValue(const T_Type& a_crFirstValue, const T_Type& a_crSecondValue, const Tbool a_cIncludeFirstValue = true, const Tbool a_cIncludeSecondValue = true);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpanValue class.
  */
  template <typename T_OtherType>
  CSpanValue(const CSpanValue<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CSpanValue();

  //! Operator: Assign another CSpanValue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpanValue class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CSpanValue<T_Type>& operator = (const CSpanValue<T_OtherType>& a_crInstance);

  //! Set single span value.
  /*!
      \param a_crValue - Constant reference to the single span value.
  */
  void set(const T_Type& a_crValue);
  //! Set span values.
  /*!
      \param a_crFirstValue - Constant reference to the first span value.
      \param a_crSecondValue - Constant reference to the second span value.
      \param a_cIncludeFirstValue - Include first span value flag (default is true).
      \param a_cIncludeSecondValue - Include second span value flag (default is true).
  */
  void set(const T_Type& a_crFirstValue, const T_Type& a_crSecondValue, const Tbool a_cIncludeFirstValue = true, const Tbool a_cIncludeSecondValue = true);
  //! Set another CSpanValue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSpanValue class.
  */
  template <typename T_OtherType>
  void set(const CSpanValue<T_OtherType>& a_crInstance);

  //! Get first span value.
  /*!
      \return Reference to the first span value.
  */
  T_Type& getFirst();
  //! Get first span value (constant version).
  /*!
      \return Constant reference to the first span value.
  */
  const T_Type& getFirst() const;

  //! Get second span value.
  /*!
      \return Reference to the second span value.
  */
  T_Type& getSecond();
  //! Get second span value (constant version).
  /*!
      \return Constant reference to the second span value.
  */
  const T_Type& getSecond() const;

  //! Is first span value included?
  /*!
      \return true  - if first span value is included into the span. \n
              false - if first span value is not included into the span. \n
  */
  Tbool isIncludeFirst() const;
  //! Is second span value included?
  /*!
      \return true  - if second span value is included into the span. \n
              false - if second span value is not included into the span. \n
  */
  Tbool isIncludeSecond() const;

  //! Include first span value.
  void includeFirst();
  //! Include second span value.
  void includeSecond();

  //! Exclude first span value.
  void excludeFirst();
  //! Exclude second span value.
  void excludeSecond();

  //! Reverse span value.
  void reverse();

  //! Serialize CSpanValue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSpanValue class instances.
  /*!
      \param a_rInstance - Reference to another CSpanValue class instance.
  */
  void swap(CSpanValue<T_Type>& a_rInstance);

private:
  TFirst  m_First;                      //!< Span first value (begin of the interval).
  TSecond m_Second;                     //!< Span second value (end of the interval).
  Tbool   m_IsIncludeFirst;             //!< Span first value include flag.
  Tbool   m_IsIncludeSecond;            //!< Span second value include flag.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/details/CSpanValue.inl>
/*==========================================================================*/
#endif
