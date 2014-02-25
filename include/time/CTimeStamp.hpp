/*!
 *  \file    CTimeStamp.hpp Time stamp class represents a time stamp with a
 *           the 64-bit integer value.
 *  \brief   Time stamp class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time stamp class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   19.02.2010 20:29:05

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
#ifndef __CTIMESTAMP_HPP__
#define __CTIMESTAMP_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/AAbsolute.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Time stamp class.
/*!
    Time stamp class represents a time stamp with a 64-bit integer value.  The
    value of time stamp is calculated in milliseconds.

    Time  stamp  class  provides  functionality  to  calculate   and   extract
    milliseconds, seconds, minutes, hours and days from time stamp.

    Also it is possible to get process time stamp and system time stamp in UTC
    or local time forms.
*/
class BASE_API CTimeStamp
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTimeStamp TDepthCheckType;

  // Check CTimeStamp class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create and initialize time stamp with the system  time  stamp  in  local
      time form.
  */
  CTimeStamp();
  //! Initialize time stamp with the given time values.
  /*!
      Create and initialize time stamp with the given  milliseconds,  seconds,
      minutes, hours and days values.

      Time stamp value is calculated using the following formula:
      timestamp = milliseconds + (seconds + (minutes + (hours + days * 24) * 60) * 60) * 1000

      \param a_cMilliseconds - Milliseconds value.
      \param a_cSeconds - Seconds value (default is 0).
      \param a_cMinutes - Minutes value (default is 0).
      \param a_cHours - Hours value (default is 0).
      \param a_cDays - Days value (default is 0).
  */
  CTimeStamp(const Tsint64 a_cMilliseconds, const Tsint64 a_cSeconds = 0, const Tsint64 a_cMinutes = 0, const Tsint64 a_cHours = 0, const Tsint64 a_cDays = 0);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeStamp class.
  */
  CTimeStamp(const CTimeStamp& a_crInstance);
  //! Class destructor.
 ~CTimeStamp();

  //! Operator: Equal to integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return true  - if time stamp class is equal to integer value. \n
              false - if time stamp class is not equal to integer value. \n
  */
  friend BASE_API Tbool operator == (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: Equal to another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return true  - if CTimeStamp class instance is equal to another one. \n
              false - if CTimeStamp class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: Equal to integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return true  - if integer value is equal to time stamp class. \n
              false - if integer value is not equal to time stamp class. \n
  */
  friend BASE_API Tbool operator == (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);

  //! Operator: Not equal to integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return true  - if time stamp class is not equal to integer value. \n
              false - if time stamp class is equal to integer value. \n
  */
  friend BASE_API Tbool operator != (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: Not equal to another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return true  - if CTimeStamp class instance is not equal to another one. \n
              false - if CTimeStamp class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: Not equal to integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return true  - if integer value is not equal to time stamp class. \n
              false - if integer value is equal to time stamp class. \n
  */
  friend BASE_API Tbool operator != (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);

  //! Operator: Less than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return true  - if time stamp class is less than integer value. \n
              false - if time stamp class is not less than integer value. \n
  */
  friend BASE_API Tbool operator < (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: Less than another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return true  - if CTimeStamp class instance is less than another one. \n
              false - if CTimeStamp class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: Less than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return true  - if integer value is less than time stamp class. \n
              false - if integer value is not less than time stamp class. \n
  */
  friend BASE_API Tbool operator < (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);
  //! Operator: More than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return true  - if time stamp class is more than integer value. \n
              false - if time stamp class is not more than integer value. \n
  */
  friend BASE_API Tbool operator > (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: More than another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return true  - if CTimeStamp class instance is more than another one. \n
              false - if CTimeStamp class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: More than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return true  - if integer value is more than time stamp class. \n
              false - if integer value is not more than time stamp class. \n
  */
  friend BASE_API Tbool operator > (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);
  //! Operator: Less or equal than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return true  - if time stamp class is less or equal than integer value. \n
              false - if time stamp class is not less or equal than integer value. \n
  */
  friend BASE_API Tbool operator <= (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: Less or equal than another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return true  - if CTimeStamp class instance is less or equal than another one. \n
              false - if CTimeStamp class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: Less or equal than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return true  - if integer value is less or equal than time stamp class. \n
              false - if integer value is not less or equal than time stamp class. \n
  */
  friend BASE_API Tbool operator <= (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);
  //! Operator: More or equal than integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return true  - if time stamp class is more or equal than integer value. \n
              false - if time stamp class is not more or equal than integer value. \n
  */
  friend BASE_API Tbool operator >= (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: More or equal than another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return true  - if CTimeStamp class instance is more or equal than another one. \n
              false - if CTimeStamp class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: More or equal than integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return true  - if integer value is more or equal than time stamp class. \n
              false - if integer value is not more or equal than time stamp class. \n
  */
  friend BASE_API Tbool operator >= (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);

  //! Operator: Unary plus.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied plus operator.
  */
  friend BASE_API CTimeStamp operator + (const CTimeStamp& a_crInstance);
  //! Operator: Unary minus.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied minus operator.
  */
  friend BASE_API CTimeStamp operator - (const CTimeStamp& a_crInstance);

  //! Operator: Add integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: Add another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: Add integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);
  //! Operator: Sub integer number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \param a_cValue - Integer number value.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CTimeStamp& a_crInstance, const Tsint64 a_cValue);
  //! Operator: Sub another CTimeStamp class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTimeStamp class.
      \param a_crInstance2 - Constant reference to another instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2);
  //! Operator: Sub integer number.
  /*!
      \param a_cValue - Integer number value.
      \param a_crInstance - Constant reference to the current instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const Tsint64 a_cValue, const CTimeStamp& a_crInstance);

  //! Operator: Assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CTimeStamp& operator = (const Tsint64 a_cValue);
  //! Operator: Assign another CTimeStamp class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CTimeStamp& operator = (const CTimeStamp& a_crInstance);

  //! Operator: Add and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CTimeStamp& operator += (const Tsint64 a_cValue);
  //! Operator: Add and assign another CTimeStamp class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CTimeStamp& operator += (const CTimeStamp& a_crInstance);
  //! Operator: Sub and assign integer number.
  /*!
      \param a_cValue - Integer number value.
      \return Reference to the current class instance.
  */
  CTimeStamp& operator -= (const Tsint64 a_cValue);
  //! Operator: Sub and assign another CTimeStamp class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CTimeStamp& operator -= (const CTimeStamp& a_crInstance);

  //! Operator: Increment timestep on one millisecond. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTimeStamp& operator ++ ();
  //! Operator: Increment timestep on one millisecond. Postfix version.
  /*!
      \return New instance of CTimeStamp class with applied increment operator.
  */
  CTimeStamp operator ++ (int);

  //! Operator: Decrement timestep on one millisecond. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTimeStamp& operator -- ();
  //! Operator: Decrement timestep on one millisecond. Postfix version.
  /*!
      \return New instance of CTimeStamp class with applied increment operator.
  */
  CTimeStamp operator -- (int);

  //! Set the given time values (milliseconds, seconds, minutes, hours and days).
  /*!
      Time stamp value is calculated using the following formula:
      timestamp = milliseconds + (seconds + (minutes + (hours + days * 24) * 60) * 60) * 1000

      \param a_cMilliseconds - Milliseconds value.
      \param a_cSeconds - Seconds value (default is 0).
      \param a_cMinutes - Minutes value (default is 0).
      \param a_cHours - Hours value (default is 0).
      \param a_cDays - Days value (default is 0).
  */
  void set(const Tsint64 a_cMilliseconds, const Tsint64 a_cSeconds = 0, const Tsint64 a_cMinutes = 0, const Tsint64 a_cHours = 0, const Tsint64 a_cDays = 0);
  //! Set another CTimeStamp class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeStamp class.
  */
  void set(const CTimeStamp& a_crInstance);

  //! Is current time stamp is zero?
  /*!
      \return true  - if current time stamp is zero. \n
              false - if current time stamp is not zero. \n
  */
  Tbool isZero() const;
  //! Is current time stamp is positive?
  /*!
      \return true  - if current time stamp is positive. \n
              false - if current time stamp is negative. \n
  */
  Tbool isPositive() const;
  //! Is current time stamp is negative?
  /*!
      \return true  - if current time stamp is negative. \n
              false - if current time stamp is positive. \n
  */
  Tbool isNegative() const;

  //! Get time stamp only for time value.
  /*!
      \return Time stamp only for time value.
  */
  CTimeStamp getTimeStampForTime() const;
  //! Get time stamp only for date value.
  /*!
      \return Time stamp only for date value.
  */
  CTimeStamp getTimeStampForDate() const;

  //! Get time stamp value.
  /*!
      \return Wrapped 64-bit integer number value.
  */
  Tsint64 getTimeStampValue() const;

  //! Get count of clear milliseconds in the current time stamp.
  /*!
      \return Count of clear milliseconds in the current time stamp.
  */
  Tsint getClearMilliseconds() const;
  //! Get count of clear seconds in the current time stamp.
  /*!
      \return Count of clear seconds in the current time stamp.
  */
  Tsint getClearSeconds() const;
  //! Get count of clear minutes in the current time stamp.
  /*!
      \return Count of clear minutes in the current time stamp.
  */
  Tsint getClearMinutes() const;
  //! Get count of clear hours in the current time stamp.
  /*!
      \return Count of clear hours in the current time stamp.
  */
  Tsint getClearHours() const;
  //! Get count of clear days in the current time stamp.
  /*!
      \return Count of clear days in the current time stamp.
  */
  Tsint getClearDays() const;

  //! Get total count of milliseconds in the current time stamp.
  /*!
      \return Total count of milliseconds in the current time stamp.
  */
  Tsint64 getTotalMilliseconds() const;
  //! Get total count of seconds in the current time stamp.
  /*!
      \return Total count of seconds in the current time stamp.
  */
  Tsint64 getTotalSeconds() const;
  //! Get total count of minutes in the current time stamp.
  /*!
      \return Total count of minutes in the current time stamp.
  */
  Tsint64 getTotalMinutes() const;
  //! Get total count of hours in the current time stamp.
  /*!
      \return Total count of hours in the current time stamp.
  */
  Tsint64 getTotalHours() const;
  //! Get total count of days in the current time stamp.
  /*!
      \return Total count of days in the current time stamp.
  */
  Tsint64 getTotalDays() const;

  //! Set current time stamp value to zero.
  void clear();
  //! Set current time stamp value to it absolute value.
  void absolute();
  //! Negative current time stamp value.
  void negate();

  //! Get process time stamp.
  /*!
      Process time stamp is calculated starting  from  the  execution  of  the
      current process.

      \return Process time stamp.
  */
  static CTimeStamp getProcessTimeStamp();
  //! Get system time stamp.
  /*!
      \param a_cIsUTC - Get time stamp in UTC time flag (default is true).
      \return System time stamp.
  */
  static CTimeStamp getSystemTimeStamp(const Tbool a_cIsUTC = true);

  //! Get minimal possible time stamp value.
  /*!
      \return Minimal possible time stamp value.
  */
  static CTimeStamp getMin();
  //! Get maximal possible time stamp value.
  /*!
      \return Maximal possible time stamp value.
  */
  static CTimeStamp getMax();

  //! Serialize CTimeStamp class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTimeStamp class instances.
  /*!
      \param a_rInstance - Reference to another CTimeStamp class instance.
  */
  void swap(CTimeStamp& a_rInstance);

private:
  Tsint64 m_TimeStampValue;             //!< Time stamp value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/CTimeStamp.inl>
/*==========================================================================*/
//! \example example-time-CTimeStamp.cpp
/*--------------------------------------------------------------------------*/
//! \test test-time-CTimeStamp.cpp
/*==========================================================================*/
#endif
