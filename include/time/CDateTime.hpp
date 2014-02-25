/*!
 *  \file    CDateTime.hpp Date & Time class represents a date & time with
 *           year, month, day, hours, minutes, seconds and milliseconds
 *           values.
 *  \brief   Date & Time class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Date & Time class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   04.03.2010 02:11:01

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
#ifndef __CDATETIME_HPP__
#define __CDATETIME_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/time/CDate.hpp>
#include <Depth/include/time/CTime.hpp>
#include <Depth/include/time/CTimeStamp.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Date & Time class.
/*!
    Date & Time class represents a date with year, month, day, hours, minutes,
    seconds and milliseconds values.

    Also it is possible to get process date & time value  and  get/set  system
    date & time values in UTC or local time forms.
*/
class BASE_API CDateTime
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDateTime TDepthCheckType;

  // Check CDateTime class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create and initialize date & time class instance with the system date  &
      time in local time form.
  */
  CDateTime();
  //! Initialize date & time class instance with the given date & time values.
  /*!
      Create and initialize date class instance with the  given  year,  month,
      day, hours, minutes, seconds and milliseconds values.

      If date & time values are  gone  out  of  range  they  will  be  bounded
      automatically.

      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
      \param a_cHours - Hours value (default is 0).
      \param a_cMinutes - Minutes value (default is 0).
      \param a_cSeconds - Seconds value (default is 0).
      \param a_cMilliseconds - Milliseconds value (default is 0).
  */
  CDateTime(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay, const Tuint a_cHours = 0, const Tuint a_cMinutes = 0, const Tuint a_cSeconds = 0, const Tuint a_cMilliseconds = 0);
  //! Initialize date & time class instance with the given date and time values.
  /*!
      \param a_crDate - Constant reference to the instance of the CDate class.
      \param a_crTime - Constant reference to the instance of the CTime class.
  */
  CDateTime(const CDate& a_crDate, const CTime& a_crTime);
  //! Initialize date & time class instance form the time values in the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
  */
  CDateTime(const CTimeStamp& a_crTimeStamp);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDateTime class.
  */
  CDateTime(const CDateTime& a_crInstance);
  //! Class destructor.
 ~CDateTime();

  //! Operator: Equal to the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date & time class is equal to the date & time value from the given time stamp. \n
              false - if date & time class is not equal to the date & time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator == (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Equal to another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return true  - if CDateTime class instance is equal to another one. \n
              false - if CDateTime class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: Equal to the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return true  - if the date & time value from the given time stamp is equal to date & time class. \n
              false - if the date & time value from the given time stamp is not equal to date & time class. \n
  */
  friend BASE_API Tbool operator == (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);

  //! Operator: Not equal to the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date & time class is not equal to the date & time value from the given time stamp. \n
              false - if date & time class is equal to the date & time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator != (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Not equal to another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return true  - if CDateTime class instance is not equal to another one. \n
              false - if CDateTime class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: Not equal to the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return true  - if the date & time value from the given time stamp is not equal to date & time class. \n
              false - if the date & time value from the given time stamp is equal to date & time class. \n
  */
  friend BASE_API Tbool operator != (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);

  //! Operator: Less than the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date & time class is less than the date & time value from the given time stamp. \n
              false - if date & time class is not less than the date & time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator < (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Less than another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return true  - if CDateTime class instance is less than another one. \n
              false - if CDateTime class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: Less than the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return true  - if the date & time value from the given time stamp is less than date & time class. \n
              false - if the date & time value from the given time stamp is not less than date & time class. \n
  */
  friend BASE_API Tbool operator < (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);
  //! Operator: More than the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date & time class is more than the date & time value from the given time stamp. \n
              false - if date & time class is not more than the date & time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator > (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: More than another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return true  - if CDateTime class instance is more than another one. \n
              false - if CDateTime class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: More than the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return true  - if the date & time value from the given time stamp is more than date & time class. \n
              false - if the date & time value from the given time stamp is not more than date & time class. \n
  */
  friend BASE_API Tbool operator > (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);
  //! Operator: Less or equal than the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date & time class is less or equal than the date & time value from the given time stamp. \n
              false - if date & time class is not less or equal than the date & time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator <= (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Less or equal than another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return true  - if CDateTime class instance is less or equal than another one. \n
              false - if CDateTime class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: Less or equal than the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return true  - if the date & time value from the given time stamp is less or equal than date & time class. \n
              false - if the date & time value from the given time stamp is not less or equal than date & time class. \n
  */
  friend BASE_API Tbool operator <= (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);
  //! Operator: More or equal than the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date & time class is more or equal than the date & time value from the given time stamp. \n
              false - if date & time class is not more or equal than the date & time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator >= (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: More or equal than another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return true  - if CDateTime class instance is more or equal than another one. \n
              false - if CDateTime class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: More or equal than the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return true  - if the date & time value from the given time stamp is more or equal than date & time class. \n
              false - if the date & time value from the given time stamp is not more or equal than date & time class. \n
  */
  friend BASE_API Tbool operator >= (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);

  //! Operator: Add the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Add another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: Add the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);
  //! Operator: Sub the date & time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Sub another CDateTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDateTime class.
      \param a_crInstance2 - Constant reference to another instance of the CDateTime class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2);
  //! Operator: Sub the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDateTime class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance);

  //! Operator: Assign the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CDateTime& operator = (const CTimeStamp& a_crTimeStamp);
  //! Operator: Assign another CDateTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDateTime class.
      \return Reference to the current class instance.
  */
  CDateTime& operator = (const CDateTime& a_crInstance);

  //! Operator: Add and assign the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CDateTime& operator += (const CTimeStamp& a_crTimeStamp);
  //! Operator: Add and assign another CDateTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDateTime class.
      \return Reference to the current class instance.
  */
  CDateTime& operator += (const CDateTime& a_crInstance);
  //! Operator: Sub and assign the date & time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CDateTime& operator -= (const CTimeStamp& a_crTimeStamp);
  //! Operator: Sub and assign another CDateTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDateTime class.
      \return Reference to the current class instance.
  */
  CDateTime& operator -= (const CDateTime& a_crInstance);

  //! Operator: Get date of the current date & time.
  /*!
      \return Constant reference to the date of the current date & time.
  */
  operator const CDate& () const;
  //! Operator: Get time of the current date & time.
  /*!
      \return Constant reference to the time of the current date & time.
  */
  operator const CTime& () const;
  //! Operator: Get time stamp of the current time.
  /*!
      \return Time stamp of the current time.
  */
  operator CTimeStamp () const;

  //! Set the given date & time values (year, month, day, hours, minutes, seconds and milliseconds).
  /*!
      If date & time values are  gone  out  of  range  they  will  be  bounded
      automatically.

      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
      \param a_cHours - Hours value (default is 0).
      \param a_cMinutes - Minutes value (default is 0).
      \param a_cSeconds - Seconds value (default is 0).
      \param a_cMilliseconds - Milliseconds value (default is 0).
  */
  void set(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay, const Tuint a_cHours = 0, const Tuint a_cMinutes = 0, const Tuint a_cSeconds = 0, const Tuint a_cMilliseconds = 0);
  //! Set date & time class instance with the given date and time values.
  /*!
      \param a_crDate - Constant reference to the instance of the CDate class.
      \param a_crTime - Constant reference to the instance of the CTime class.
  */
  void set(const CDate& a_crDate, const CTime& a_crTime);
  //! Set date & time class instance form the time values in the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
  */
  void set(const CTimeStamp& a_crTimeStamp);
  //! Set another CDateTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDateTime class.
  */
  void set(const CDateTime& a_crInstance);

  //! Get date of the current date & time.
  /*!
      \return Constant reference to the date of the current date & time.
  */
  const CDate& getDate() const;
  //! Get time of the current date & time.
  /*!
      \return Constant reference to the time of the current date & time.
  */
  const CTime& getTime() const;
  //! Get time stamp of the current date & time.
  /*!
      \return Time stamp of the current date & time.
  */
  CTimeStamp getTimeStamp() const;

  //! Add the given years to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cYears - Years value.
      \return The current date with the given years value.
  */
  CDateTime addYears(const Tsint a_cYears) const;
  //! Add the given months to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cMonths - Months value.
      \return The current date with the given months value.
  */
  CDateTime addMonths(const Tsint a_cMonths) const;
  //! Add the given weeks to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cWeeks - Weeks value.
      \return The current date with the given weeks value.
  */
  CDateTime addWeeks(const Tsint a_cWeeks) const;
  //! Add the given days to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cDays - Days value.
      \return The current date with the given days value.
  */
  CDateTime addDays(const Tsint a_cDays) const;
  //! Add the given hours to the current date & time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cHours - Hours value.
      \return The current date & time with the given hours value.
  */
  CDateTime addHours(const Tsint a_cHours) const;
  //! Add the given minutes to the current date & time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cMinutes - Minutes value.
      \return The current date & time with the given minutes value.
  */
  CDateTime addMinutes(const Tsint a_cMinutes) const;
  //! Add the given seconds to the current date & time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cSeconds - Seconds value.
      \return The current date & time with the given seconds value.
  */
  CDateTime addSeconds(const Tsint a_cSeconds) const;
  //! Add the given milliseconds to the current date & time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cMilliseconds - Milliseconds value.
      \return The current date & time with the given milliseconds value.
  */
  CDateTime addMilliseconds(const Tsint a_cMilliseconds) const;

  //! Get process date & time.
  /*!
      Process date & time is calculated starting from  the  execution  of  the
      current process.

      \return Process date & time.
  */
  static CDateTime getProcessDateTime();
  //! Get system date & time.
  /*!
      \param a_cIsUTC - Get date & time in UTC time flag (default is true).
      \return System date & time.
  */
  static CDateTime getSystemDateTime(const Tbool a_cIsUTC = true);

  //! Set system date & time in UTC form.
  /*!
      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return true  - if system date & time was successfully set. \n
              false - if system date & time was not successfully set. \n
  */
  static Tbool setSystemDateTimeUTC(const CDateTime& a_crDateTime);
  //! Set system date & time in local time form.
  /*!
      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return true  - if system date & time was successfully set. \n
              false - if system date & time was not successfully set. \n
  */
  static Tbool setSystemDateTimeLocal(const CDateTime& a_crDateTime);

  //! Get minimal possible date & time value.
  /*!
      \return Minimal possible date & time value.
  */
  static CDateTime getMin();
  //! Get maximal possible date & time value.
  /*!
      \return Maximal possible date & time value.
  */
  static CDateTime getMax();

  //! Serialize CDateTime class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDateTime class instances.
  /*!
      \param a_rInstance - Reference to another CDateTime class instance.
  */
  void swap(CDateTime& a_rInstance);

private:
  CDate m_Date;                         //!< Date value.
  CTime m_Time;                         //!< Time value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/CDateTime.inl>
/*==========================================================================*/
//! \example example-time-CDateTime.cpp
/*--------------------------------------------------------------------------*/
//! \test test-time-CDateTime.cpp
/*==========================================================================*/
#endif
