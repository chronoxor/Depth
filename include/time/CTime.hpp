/*!
 *  \file    CTime.hpp Time class represents a time with hours, minutes,
 *           seconds and milliseconds values.
 *  \brief   Time class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   24.02.2010 21:31:32

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
#ifndef __CTIME_HPP__
#define __CTIME_HPP__
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
//! Time class.
/*!
    Time class represents a time with hours, minutes, seconds and milliseconds
    values.

    Time class provides functionality to calculate and extract hours, minutes,
    seconds, and milliseconds from time class instance.

    Also it is possible to get process time  value  and  get/set  system  time
    values in UTC or local time forms.
*/
class BASE_API CTime
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTime TDepthCheckType;

  // Check CTime class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create and initialize time class instance with the system time in  local
      time form.
  */
  CTime();
  //! Initialize time class instance with the given time values.
  /*!
      Create and initialize time class instance with the given hours, minutes,
      seconds and milliseconds values.

      Hours value should be less than 24, minutes value should  be  less  than
      60, seconds value should be less than 60, milliseconds value  should  be
      less than 1000. If time values are  gone  out  of  range  they  will  be
      bounded automatically.

      \param a_cHours - Hours value.
      \param a_cMinutes - Minutes value (default is 0).
      \param a_cSeconds - Seconds value (default is 0).
      \param a_cMilliseconds - Milliseconds value (default is 0).
  */
  CTime(const Tuint a_cHours, const Tuint a_cMinutes = 0, const Tuint a_cSeconds = 0, const Tuint a_cMilliseconds = 0);
  //! Initialize time class instance form the time values in the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
  */
  CTime(const CTimeStamp& a_crTimeStamp);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTime class.
  */
  CTime(const CTime& a_crInstance);
  //! Class destructor.
 ~CTime();

  //! Operator: Equal to the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if time class is equal to the time value from the given time stamp. \n
              false - if time class is not equal to the time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator == (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Equal to another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return true  - if CTime class instance is equal to another one. \n
              false - if CTime class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: Equal to the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return true  - if the time value from the given time stamp is equal to time class. \n
              false - if the time value from the given time stamp is not equal to time class. \n
  */
  friend BASE_API Tbool operator == (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);

  //! Operator: Not equal to the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if time class is not equal to the time value from the given time stamp. \n
              false - if time class is equal to the time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator != (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Not equal to another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return true  - if CTime class instance is not equal to another one. \n
              false - if CTime class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: Not equal to the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return true  - if the time value from the given time stamp is not equal to time class. \n
              false - if the time value from the given time stamp is equal to time class. \n
  */
  friend BASE_API Tbool operator != (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);

  //! Operator: Less than the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if time class is less than the time value from the given time stamp. \n
              false - if time class is not less than the time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator < (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Less than another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return true  - if CTime class instance is less than another one. \n
              false - if CTime class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: Less than the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return true  - if the time value from the given time stamp is less than time class. \n
              false - if the time value from the given time stamp is not less than time class. \n
  */
  friend BASE_API Tbool operator < (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);
  //! Operator: More than the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if time class is more than the time value from the given time stamp. \n
              false - if time class is not more than the time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator > (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: More than another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return true  - if CTime class instance is more than another one. \n
              false - if CTime class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: More than the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return true  - if the time value from the given time stamp is more than time class. \n
              false - if the time value from the given time stamp is not more than time class. \n
  */
  friend BASE_API Tbool operator > (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);
  //! Operator: Less or equal than the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if time class is less or equal than the time value from the given time stamp. \n
              false - if time class is not less or equal than the time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator <= (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Less or equal than another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return true  - if CTime class instance is less or equal than another one. \n
              false - if CTime class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: Less or equal than the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return true  - if the time value from the given time stamp is less or equal than time class. \n
              false - if the time value from the given time stamp is not less or equal than time class. \n
  */
  friend BASE_API Tbool operator <= (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);
  //! Operator: More or equal than the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return true  - if time class is more or equal than the time value from the given time stamp. \n
              false - if time class is not more or equal than the time value from the given time stamp. \n
  */
  friend BASE_API Tbool operator >= (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: More or equal than another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return true  - if CTime class instance is more or equal than another one. \n
              false - if CTime class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: More or equal than the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return true  - if the time value from the given time stamp is more or equal than time class. \n
              false - if the time value from the given time stamp is not more or equal than time class. \n
  */
  friend BASE_API Tbool operator >= (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);

  //! Operator: Add the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Add another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: Add the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return New instance of CTimeStamp class with applied add operator.
  */
  friend BASE_API CTimeStamp operator + (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);
  //! Operator: Sub the time value from the given time stamp.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp);
  //! Operator: Sub another CTime class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTime class.
      \param a_crInstance2 - Constant reference to another instance of the CTime class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CTime& a_crInstance1, const CTime& a_crInstance2);
  //! Operator: Sub the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \param a_crInstance - Constant reference to the current instance of the CTime class.
      \return New instance of CTimeStamp class with applied sub operator.
  */
  friend BASE_API CTimeStamp operator - (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance);

  //! Operator: Assign the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CTime& operator = (const CTimeStamp& a_crTimeStamp);
  //! Operator: Assign another CTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTime class.
      \return Reference to the current class instance.
  */
  CTime& operator = (const CTime& a_crInstance);

  //! Operator: Add and assign the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CTime& operator += (const CTimeStamp& a_crTimeStamp);
  //! Operator: Add and assign another CTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTime class.
      \return Reference to the current class instance.
  */
  CTime& operator += (const CTime& a_crInstance);
  //! Operator: Sub and assign the time value from the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
      \return Reference to the current class instance.
  */
  CTime& operator -= (const CTimeStamp& a_crTimeStamp);
  //! Operator: Sub and assign another CTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTime class.
      \return Reference to the current class instance.
  */
  CTime& operator -= (const CTime& a_crInstance);

  //! Operator: Get time stamp of the current time.
  /*!
      \return Time stamp of the current time.
  */
  operator CTimeStamp () const;

  //! Set the given time values (hours, minutes, seconds and milliseconds).
  /*!
      Hours value should be less than 24, minutes value should  be  less  than
      60, seconds value should be less than 60, milliseconds value  should  be
      less than 1000. If time values are  gone  out  of  range  they  will  be
      bounded automatically.

      \param a_cHours - Hours value.
      \param a_cMinutes - Minutes value (default is 0).
      \param a_cSeconds - Seconds value (default is 0).
      \param a_cMilliseconds - Milliseconds value (default is 0).
  */
  void set(const Tuint a_cHours, const Tuint a_cMinutes = 0, const Tuint a_cSeconds = 0, const Tuint a_cMilliseconds = 0);
  //! Set time class instance form the time values in the given time stamp.
  /*!
      \param a_crTimeStamp - Constant reference to the instance of the CTimeStamp class.
  */
  void set(const CTimeStamp& a_crTimeStamp);
  //! Set another CTime class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTime class.
  */
  void set(const CTime& a_crInstance);

  //! Is current time is AM (Ante Meridiem)?
  /*!
      \return true  - if current time is AM. \n
              false - if current time is PM. \n
  */
  Tbool isAM() const;
  //! Is current time is PM (Post Meridiem)?
  /*!
      \return true  - if current time is PM. \n
              false - if current time is AM. \n
  */
  Tbool isPM() const;

  //! Get time stamp of the current time.
  /*!
      \return Time stamp of the current time.
  */
  CTimeStamp getTimeStamp() const;

  //! Get hours of the current time.
  /*!
      \return Hour of the current time.
  */
  Tuint getHour() const;
  //! Get minute of the current time.
  /*!
      \return Minute of the current time.
  */
  Tuint getMinute() const;
  //! Get second of the current time.
  /*!
      \return Second of the current time.
  */
  Tuint getSecond() const;
  //! Get millisecond of the current time.
  /*!
      \return Millisecond of the current time.
  */
  Tuint getMillisecond() const;

  //! Get count of clear hours in the current time.
  /*!
      \return Count of clear hours in the current time.
  */
  Tuint getClearHours() const;
  //! Get count of clear minutes in the current time.
  /*!
      \return Count of clear minutes in the current time.
  */
  Tuint getClearMinutes() const;
  //! Get count of clear seconds in the current time.
  /*!
      \return Count of clear seconds in the current time.
  */
  Tuint getClearSeconds() const;
  //! Get count of clear milliseconds in the current time.
  /*!
      \return Count of clear milliseconds in the current time.
  */
  Tuint getClearMilliseconds() const;

  //! Get total count of hours in the current time.
  /*!
      \return Total count of hours in the current time.
  */
  Tuint getTotalHours() const;
  //! Get total count of minutes in the current time.
  /*!
      \return Total count of minutes in the current time.
  */
  Tuint getTotalMinutes() const;
  //! Get total count of seconds in the current time.
  /*!
      \return Total count of seconds in the current time.
  */
  Tuint getTotalSeconds() const;
  //! Get total count of milliseconds in the current time.
  /*!
      \return Total count of milliseconds in the current time.
  */
  Tuint getTotalMilliseconds() const;

  //! Add the given hours to the current time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cHours - Hours value.
      \return The current time with the given hours value.
  */
  CTime addHours(const Tsint a_cHours) const;
  //! Add the given minutes to the current time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cMinutes - Minutes value.
      \return The current time with the given minutes value.
  */
  CTime addMinutes(const Tsint a_cMinutes) const;
  //! Add the given seconds to the current time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cSeconds - Seconds value.
      \return The current time with the given seconds value.
  */
  CTime addSeconds(const Tsint a_cSeconds) const;
  //! Add the given milliseconds to the current time.
  /*!
      Argument could be negative to perform a subtract operation.

      \param a_cMilliseconds - Milliseconds value.
      \return The current time with the given milliseconds value.
  */
  CTime addMilliseconds(const Tsint a_cMilliseconds) const;

  //! Get process time.
  /*!
      Process time is calculated starting from the execution  of  the  current
      process.

      Note that if current process is run for several days  its  process  time
      will be overflowed.

      \return Process time.
  */
  static CTime getProcessTime();
  //! Get system time.
  /*!
      \param a_cIsUTC - Get time in UTC time flag (default is true).
      \return System time.
  */
  static CTime getSystemTime(const Tbool a_cIsUTC = true);

  //! Set system time in UTC form.
  /*!
      \param a_crTime - Constant reference to the instance of the CTime class.
      \return true  - if system time was successfully set. \n
              false - if system time was not successfully set. \n
  */
  static Tbool setSystemTimeUTC(const CTime& a_crTime);
  //! Set system time in local time form.
  /*!
      \param a_crTime - Constant reference to the instance of the CTime class.
      \return true  - if system time was successfully set. \n
              false - if system time was not successfully set. \n
  */
  static Tbool setSystemTimeLocal(const CTime& a_crTime);

  //! Get minimal possible time value.
  /*!
      \return Minimal possible time value.
  */
  static CTime getMin();
  //! Get maximal possible time value.
  /*!
      \return Maximal possible time value.
  */
  static CTime getMax();

  //! Serialize CTime class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTime class instances.
  /*!
      \param a_rInstance - Reference to another CTime class instance.
  */
  void swap(CTime& a_rInstance);

private:
  Tuint m_Hours;                        //!< Time hours value.
  Tuint m_Minutes;                      //!< Time minutes value.
  Tuint m_Seconds;                      //!< Time seconds value.
  Tuint m_Milliseconds;                 //!< Time milliseconds value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/CTime.inl>
/*==========================================================================*/
//! \example example-time-CTime.cpp
/*--------------------------------------------------------------------------*/
//! \test test-time-CTime.cpp
/*==========================================================================*/
#endif
