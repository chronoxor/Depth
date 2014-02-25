/*!
 *  \file    CDate.hpp Date class represents a date with year, month and day
 *           values.
 *  \brief   Date class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Date class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   26.02.2010 03:35:59

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
#ifndef __CDATE_HPP__
#define __CDATE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
//! Date class.
/*!
    Date class represents a date with year, month and day values.

    Date class provides functionality to calculate and extract year, month and
    day from date class instance.

    Also it is possible to get process date  value  and  get/set  system  date
    values in UTC or local time forms.
*/
class BASE_API CDate
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDate TDepthCheckType;

  // Check CDate class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  enum EWeekDay                         //! Week days enumeration.
  {
    e_SUNDAY,                           //!< Sunday.
    e_MONDAY,                           //!< Monday.
    e_TUESDAY,                          //!< Tuesday.
    e_WEDNESDAY,                        //!< Wednesday.
    e_THURSDAY,                         //!< Thursday.
    e_FRIDAY,                           //!< Friday.
    e_SATURDAY                          //!< Saturday.
  };

  //! Default class constructor.
  /*!
      Create and initialize date class instance with the system date in  local
      time form.
  */
  CDate();
  //! Initialize date class instance with the given date values.
  /*!
      Create and initialize date class instance with the given year, month and
      day values.

      If date values are gone out of range they will be bounded automatically.

      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
  */
  CDate(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay);
  //! Initialize date class instance form the time values in the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
  */
  CDate(const CTimeStamp& a_crTimeStamp);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDate class.
  */
  CDate(const CDate& a_crInstance);
  //! Class destructor.
 ~CDate();

  //! Operator: Equal to the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date class is equal to the date value from the given time stamp. \n
              false - if date class is not equal to the date value from the given time stamp. \n
  */
  friend BASE_API Tbool operator == (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Equal to another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return true  - if CDate class instance is equal to another one. \n
              false - if CDate class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: Equal to the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return true  - if the date value from the given time stamp is equal to date class. \n
              false - if the date value from the given time stamp is not equal to date class. \n
  */
  friend BASE_API Tbool operator == (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);

  //! Operator: Not equal to the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date class is not equal to the date value from the given time stamp. \n
              false - if date class is equal to the date value from the given time stamp. \n
  */
  friend BASE_API Tbool operator != (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Not equal to another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return true  - if CDate class instance is not equal to another one. \n
              false - if CDate class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: Not equal to the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return true  - if the date value from the given time stamp is not equal to date class. \n
              false - if the date value from the given time stamp is equal to date class. \n
  */
  friend BASE_API Tbool operator != (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);

  //! Operator: Less than the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date class is less than the date value from the given time stamp. \n
              false - if date class is not less than the date value from the given time stamp. \n
  */
  friend BASE_API Tbool operator < (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Less than another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return true  - if CDate class instance is less than another one. \n
              false - if CDate class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: Less than the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return true  - if the date value from the given time stamp is less than date class. \n
              false - if the date value from the given time stamp is not less than date class. \n
  */
  friend BASE_API Tbool operator < (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);
  //! Operator: More than the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date class is more than the date value from the given time stamp. \n
              false - if date class is not more than the date value from the given time stamp. \n
  */
  friend BASE_API Tbool operator > (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: More than another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return true  - if CDate class instance is more than another one. \n
              false - if CDate class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: More than the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return true  - if the date value from the given time stamp is more than date class. \n
              false - if the date value from the given time stamp is not more than date class. \n
  */
  friend BASE_API Tbool operator > (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);
  //! Operator: Less or equal than the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date class is less or equal than the date value from the given time stamp. \n
              false - if date class is not less or equal than the date value from the given time stamp. \n
  */
  friend BASE_API Tbool operator <= (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Less or equal than another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return true  - if CDate class instance is less or equal than another one. \n
              false - if CDate class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: Less or equal than the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return true  - if the date value from the given time stamp is less or equal than date class. \n
              false - if the date value from the given time stamp is not less or equal than date class. \n
  */
  friend BASE_API Tbool operator <= (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);
  //! Operator: More or equal than the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if date class is more or equal than the date value from the given time stamp. \n
              false - if date class is not more or equal than the date value from the given time stamp. \n
  */
  friend BASE_API Tbool operator >= (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: More or equal than another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return true  - if CDate class instance is more or equal than another one. \n
              false - if CDate class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: More or equal than the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return true  - if the date value from the given time stamp is more or equal than date class. \n
              false - if the date value from the given time stamp is not more or equal than date class. \n
  */
  friend BASE_API Tbool operator >= (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);

  //! Operator: Add the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Add another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: Add the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);
  //! Operator: Sub the date value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Sub another CDate class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CDate class.
      \param a_crInstance2 - Constant reference to another instance of the CDate class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CDate& a_crInstance1, const CDate& a_crInstance2);
  //! Operator: Sub the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CDate class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance);

  //! Operator: Assign the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CDate& operator = (const CTimeStamp& a_crTimeStamp);
  //! Operator: Assign another CDate class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDate class.
      \return Reference to the current class instance.
  */
  CDate& operator = (const CDate& a_crInstance);

  //! Operator: Add and assign the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CDate& operator += (const CTimeStamp& a_crTimeStamp);
  //! Operator: Add and assign another CDate class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDate class.
      \return Reference to the current class instance.
  */
  CDate& operator += (const CDate& a_crInstance);
  //! Operator: Sub and assign the date value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CDate& operator -= (const CTimeStamp& a_crTimeStamp);
  //! Operator: Sub and assign another CDate class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDate class.
      \return Reference to the current class instance.
  */
  CDate& operator -= (const CDate& a_crInstance);

  //! Operator: Get time stamp of the current date.
  /*!
      \return Time stamp of the current date.
  */
  operator CTimeStamp () const;

  //! Set the given date values (year, month and day).
  /*!
      If date values are gone out of range they will be bounded automatically.

      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
  */
  void set(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay);
  //! Set date class instance form the time values in the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
  */
  void set(const CTimeStamp& a_crTimeStamp);
  //! Set another CDate class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDate class.
  */
  void set(const CDate& a_crInstance);

  //! Is current date is BC (Before Christ)?
  /*!
      \return true  - if current date is BC. \n
              false - if current date is AD. \n
  */
  Tbool isBC() const;
  //! Is current time is AD (Anno Domini)?
  /*!
      \return true  - if current time is AD. \n
              false - if current time is BC. \n
  */
  Tbool isAD() const;

  //! Get time stamp of the current date.
  /*!
      \return Time stamp of the current date.
  */
  CTimeStamp getTimeStamp() const;

  //! Get years of the current date.
  /*!
      \return Year of the current date.
  */
  Tsint getYear() const;
  //! Get month of the current date.
  /*!
      \return Month of the current date.
  */
  Tuint getMonth() const;
  //! Get day of the current date.
  /*!
      \return Day of the current date.
  */
  Tuint getDay() const;

  //! Get count of clear years in the current date.
  /*!
      \return Count of clear years in the current date.
  */
  Tsint getClearYears() const;
  //! Get count of clear months in the current date.
  /*!
      \return Count of clear months in the current date.
  */
  Tuint getClearMonths() const;
  //! Get count of clear days in the current date.
  /*!
      \return Count of clear days in the current date.
  */
  Tuint getClearDays() const;

  //! Get total count of years in the current date.
  /*!
      \return Total count of years in the current date.
  */
  Tsint getTotalYears() const;
  //! Get total count of months in the current date.
  /*!
      \return Total count of months in the current date.
  */
  Tsint getTotalMonths() const;
  //! Get total count of days in the current date.
  /*!
      \return Total count of days in the current date.
  */
  Tsint getTotalDays() const;

  //! Get week day of the current date.
  /*!
      \return Week day of the current date.
  */
  EWeekDay getWeekDay() const;

  //! Add the given years to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cYears - Years value.
      \return The current date with the given years value.
  */
  CDate addYears(const Tsint a_cYears) const;
  //! Add the given months to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cMonths - Months value.
      \return The current date with the given months value.
  */
  CDate addMonths(const Tsint a_cMonths) const;
  //! Add the given weeks to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cWeeks - Weeks value.
      \return The current date with the given weeks value.
  */
  CDate addWeeks(const Tsint a_cWeeks) const;
  //! Add the given days to the current date.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cDays - Days value.
      \return The current date with the given days value.
  */
  CDate addDays(const Tsint a_cDays) const;

  //! Is the given year is leap?
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \return true  - if the given year is leap. \n
              false - if the given year is not leap. \n
  */
  static Tbool isLeapYear(const Tsint a_cYear);

  //! Get days count in the given month for the given year.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \return Days count in the given month for the given year.
  */
  static Tuint getDaysInMonth(const Tsint a_cYear, const Tuint a_cMonth);

  //! Get full days count from Epoch (00:00:00 UTC, January 1, 0000) of the given year.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \return Full days count from Epoch of the given year.
  */
  static Tsint getEpochDays(const Tsint a_cYear);
  //! Get full days count from Epoch (00:00:00 UTC, January 1, 0000) of the given month for the given year.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \return Full days count from Epoch of the given month for the given year.
  */
  static Tsint getEpochDays(const Tsint a_cYear, const Tuint a_cMonth);
  //! Get full days count from Epoch (00:00:00 UTC, January 1, 0000) of the given date.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
      \return Full days count from Epoch of the given date.
  */
  static Tsint getEpochDays(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay);

  //! Get full weeks count from Epoch (00:00:00 UTC, January 1, 0000) of the given date.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
      \return Full weeks count from Epoch of the given date.
  */
  static Tsint getEpochWeeks(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay);

  //! Get days count to the given month of the given year.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \return Days count to given month of the given year.
  */
  static Tsint getYearDays(const Tsint a_cYear, const Tuint a_cMonth);
  //! Get days count to the given month and day of the given year.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
      \return Days count to the given month and day of the given year.
  */
  static Tsint getYearDays(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay);

  //! Get weeks count to the given month and day of the given year.
  /*!
      \param a_cYear - Year value (should be negative for BC dates).
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_cDay - Day value in range from 1 to 31.
      \return Days count to the given month and day of the given year.
  */
  static Tsint getYearWeeks(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay);

  //! Get process date.
  /*!
      Process date is calculated starting from the execution  of  the  current
      process.

      \return Process date.
  */
  static CDate getProcessDate();
  //! Get system date.
  /*!
      \param a_cIsUTC - Get date in UTC time flag (default is true).
      \return System date.
  */
  static CDate getSystemDate(const Tbool a_cIsUTC = true);

  //! Set system date in UTC form.
  /*!
      \param a_crDate - Constant reference to the instance of the CDate class.
      \return true  - if system date was successfully set. \n
              false - if system date was not successfully set. \n
  */
  static Tbool setSystemDateUTC(const CDate& a_crDate);
  //! Set system date in local time form.
  /*!
      \param a_crDate - Constant reference to the instance of the CDate class.
      \return true  - if system date was successfully set. \n
              false - if system date was not successfully set. \n
  */
  static Tbool setSystemDateLocal(const CDate& a_crDate);

  //! Get minimal possible date value.
  /*!
      \return Minimal possible date value.
  */
  static CDate getMin();
  //! Get maximal possible date value.
  /*!
      \return Maximal possible date value.
  */
  static CDate getMax();

  //! Serialize CDate class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDate class instances.
  /*!
      \param a_rInstance - Reference to another CDate class instance.
  */
  void swap(CDate& a_rInstance);

private:
  Tsint m_Year;                         //!< Date year value.
  Tuint m_Month;                        //!< Date month value.
  Tuint m_Day;                          //!< Date day value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SERIALIZATION FUNCTION DECLARATIONS                                      */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
//! Serialization load week days enumeration value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized week days enumeration value instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NTime::CDate::EWeekDay& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save week days enumeration value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized week days enumeration value instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NTime::CDate::EWeekDay& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize week days enumeration value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized week days enumeration value instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NTime::CDate::EWeekDay& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/CDate.inl>
/*==========================================================================*/
//! \example example-time-CDate.cpp
/*--------------------------------------------------------------------------*/
//! \test test-time-CDate.cpp
/*==========================================================================*/
#endif
