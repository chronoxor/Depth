/*!
 *  \file    CSystemBase.hpp Base system class contains common functionality
 *           such as memory routines, math functions, error handling,
 *           standard I/O routines.
 *  \brief   Base system class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   07.01.2006 01:33:12

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
#ifndef __CSYSTEMBASE_HPP__
#define __CSYSTEMBASE_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
#include <Depth/include/process/CCriticalSection.hpp>
#include <Depth/include/process/CRWLock.hpp>
#include <Depth/include/process/CScopeLocker.hpp>
#include <Depth/include/process/CScopeReader.hpp>
#include <Depth/include/process/CScopeWriter.hpp>
#include <Depth/include/shared/ISharedLibrary.hpp>
#include <Depth/include/time/CTime.hpp>
#include <Depth/include/time/CDate.hpp>
#include <Depth/include/time/CDateTime.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Base system class.
/*!
    Base system class contains common functionality such as  critical  section
    routines, memory routines, math functions.
*/
class BASE_API CSystemBase :
  public NDepth::NShared::ISharedLibrary
{
public:
  //! Is system installed?
  /*!
      \return true  - if system was installed. \n
              false - if system was not installed. \n
  */
  static Tbool isInstalled();

  /*------------------------------------------------------------------------*/
  /* INSLALL/UNINSTALL METHODS                                              */
  /*------------------------------------------------------------------------*/
  //! Install system.
  /*!
      \return true  - if system was successfully installed. \n
              false - if system was not successfully installed. \n
  */
  static Tbool install();
  //! Uninstall system.
  /*!
      \return true  - if system was successfully uninstalled. \n
              false - if system was not successfully uninstalled. \n
  */
  static Tbool uninstall();

  /*------------------------------------------------------------------------*/
  /* CRITICAL SECTION'S METHODS                                             */
  /*------------------------------------------------------------------------*/
  //! Create a new critical section.
  /*!
      Method creates a new critical section instance and returns  its  handle.
      If critical section cannot be created the NULL value is returned.

      \return Handle to the new critical section.
  */
  static Tptr criticalSectionCreate();
  //! Destroy the given critical section.
  /*!
      Method destroys the critical section represented with its handle.

      \param a_cpCSHandle - Constant handle to the critical section.
      \return true  - if the critical section was successfully destroyed. \n
              false - if the critical section was not successfully destroyed. \n
  */
  static Tbool criticalSectionDestroy(const Tptr a_cpCSHandle);
  //! Lock the given critical section.
  /*!
      Method blocks the current thread until the  given  critical  section  is
      free and then enter into and lock it. Therefore, a code block, which  is
      controlled by a critical section, is accessible only for one  thread  at
      one time.

      \param a_cpCSHandle - Constant handle to the critical section.
      \return true  - if the current thread successfully entered into and lock the given critical section. \n
              false - if the current thread did not successfully enter into and lock the given critical section. \n
  */
  static Tbool criticalSectionLock(const Tptr a_cpCSHandle);
  //! Unlock the given critical section.
  /*!
      Method leaves and unlocks the given  critical  section.  After  critical
      section is unlock, other threads may enter into it.

      \param a_cpCSHandle - Constant handle to the critical section.
      \return true  - if the current thread successfully left the given critical section and unlock it. \n
              false - if the current thread did not successfully leave the given critical section and unlock it. \n
  */
  static Tbool criticalSectionUnlock(const Tptr a_cpCSHandle);
  //! Try to lock the given critical section.
  /*!
      Method tries to enter into and lock the given critical section.  If  the
      critical section is free the current thread enter into it, locks it  and
      the method returns 'true'. Otherwise, method does not blocks and returns
      'false' immediately.

      \param a_cpCSHandle - Constant handle to the critical section.
      \return true  - if the given critical section is free and the current thread successfully entered into and lock it. \n
              false - if the given critical section is busy and the current thread did not enter into and lock it. \n
  */
  static Tbool criticalSectionTryLock(const Tptr a_cpCSHandle);

  /*------------------------------------------------------------------------*/
  /* DEBUGGER METHODS                                                       */
  /*------------------------------------------------------------------------*/
  //! Write buffer of bytes into the debugger stream.
  /*!
      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of buffer (in bytes).
      \return Count of written bytes.
  */
  static Tuint debuggerWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize);
  //! Write buffer of ASCII text into the debugger stream.
  /*!
      \param a_cpBuffer - Constant pointer to the ASCII text buffer.
      \param a_cSize - Size of the ASCII buffer (in characters).
      \return Count of written characters.
  */
  static Tuint debuggerWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Write buffer of Unicode text into the debugger stream.
  /*!
      \param a_cpBuffer - Constant pointer to the Unicode text buffer.
      \param a_cSize - Size of the Unicode buffer (in characters).
      \return Count of written characters.
  */
  static Tuint debuggerWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Flush debugger stream.
  /*!
      \return true  - if debugger stream was successfully flushed. \n
              false - if debugger stream was not successfully flushed. \n
  */
  static Tbool debuggerFlush();

  /*------------------------------------------------------------------------*/
  /* MEMORY MANAGEMENT METHODS                                              */
  /*------------------------------------------------------------------------*/
  //! Allocate a new buffer from the system memory pool.
  /*!
      \param a_cSize - Size of the allocated buffer in bytes.
      \return Pointer to the new allocated buffer.
  */
  static Tptr memoryAllocate(const Tuint a_cSize);
  //! Allocate a new buffer from the system memory pool. The buffer is initialized with zero values.
  /*!
      \param a_cSize - Size of the allocated buffer in bytes.
      \return Pointer to the new zero initialized allocated buffer.
  */
  static Tptr memoryAllocateZero(const Tuint a_cSize);
  //! Allocate a new buffer from the system memory pool. The buffer is initialized with zero values.
  /*!
      \param a_cOneElementSize - Size of a one element in the allocated buffer in bytes.
      \param a_cElementsCount - Count of elements in the allocated buffer.
      \return Pointer to the new zero initialized allocated buffer.
  */
  static Tptr memoryAllocateZero(const Tuint a_cOneElementSize, const Tuint a_cElementsCount);
  //! Reallocate a system memory buffer.
  /*!
      \param a_pPointer - Pointer to the old buffer.
      \param a_cSize - Size of the new buffer in bytes.
      \return Pointer to the reallocated buffer.
  */
  static Tptr memoryReallocate(Tptr a_pPointer, const Tuint a_cSize);
  //! Free a system memory buffer.
  /*!
      \param a_pPointer - Pointer to the buffer.
      \return true  - if the buffer was successfully released. \n
              false - if the buffer was not successfully released. \n
  */
  static Tbool memoryFree(Tptr a_pPointer);

  /*------------------------------------------------------------------------*/
  /* STANDARD I/O STREAMS METHODS                                           */
  /*------------------------------------------------------------------------*/
  //! Write buffer of bytes into the standard error stream.
  /*!
      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of buffer (in bytes).
      \return Count of written bytes.
  */
  static Tuint stdErrorWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize);
  //! Write buffer of ASCII text into the standard error stream.
  /*!
      \param a_cpBuffer - Constant pointer to the ASCII text buffer.
      \param a_cSize - Size of the ASCII buffer (in characters).
      \return Count of written characters.
  */
  static Tuint stdErrorWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Write buffer of Unicode text into the standard error stream.
  /*!
      \param a_cpBuffer - Constant pointer to the Unicode text buffer.
      \param a_cSize - Size of the Unicode buffer (in characters).
      \return Count of written characters.
  */
  static Tuint stdErrorWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Flush standard error stream.
  /*!
      \return true  - if standard error stream was successfully flushed. \n
              false - if standard error stream was not successfully flushed. \n
  */
  static Tbool stdErrorFlush();

  //! Read buffer of bytes from the standard input stream.
  /*!
      \param a_pBuffer - Pointer to the byte buffer.
      \param a_cSize - Size of buffer (in bytes).
      \return Count of read bytes.
  */
  static Tuint stdInputReadBinary(Tptr a_pBuffer, const Tuint a_cSize);
  //! Read buffer of ASCII text from the standard input stream.
  /*!
      \param a_pBuffer - Pointer to the ASCII text buffer.
      \param a_cSize - Size of ASCII text buffer (in characters).
      \return Count of read characters.
  */
  static Tuint stdInputReadText(Tsstr a_pBuffer, const Tuint a_cSize);
  //! Read buffer of Unicode text from the standard input stream.
  /*!
      \param a_pBuffer - Pointer to the Unicode text buffer.
      \param a_cSize - Size of Unicode text buffer (in characters).
      \return Count of read characters.
  */
  static Tuint stdInputReadText(Twstr a_pBuffer, const Tuint a_cSize);
  //! Flush standard input stream.
  /*!
      \return true  - if standard input stream was successfully flushed. \n
              false - if standard input stream was not successfully flushed. \n
  */
  static Tbool stdInputFlush();

  //! Write buffer of bytes into the standard output stream.
  /*!
      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of buffer (in bytes).
      \return Count of written bytes.
  */
  static Tuint stdOutputWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize);
  //! Write buffer of ASCII text into the standard output stream.
  /*!
      \param a_cpBuffer - Constant pointer to the ASCII text buffer.
      \param a_cSize - Size of the ASCII buffer (in characters).
      \return Count of written characters.
  */
  static Tuint stdOutputWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Write buffer of Unicode text into the standard output stream.
  /*!
      \param a_cpBuffer - Constant pointer to the Unicode text buffer.
      \param a_cSize - Size of the Unicode buffer (in characters).
      \return Count of written characters.
  */
  static Tuint stdOutputWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Flush standard output stream.
  /*!
      \return true  - if standard output stream was successfully flushed. \n
              false - if standard output stream was not successfully flushed. \n
  */
  static Tbool stdOutputFlush();

  /*------------------------------------------------------------------------*/
  /* DATE & TIME METHODS                                                    */
  /*------------------------------------------------------------------------*/
  //! Get process time stamp as 64-bit integer number.
  /*!
      Process time stamp is calculated starting  from  the  execution  of  the
      current process.

      \return Process time stamp as 64-bit integer number.
  */
  static Tsint64 getProcessTimeStamp();
  //! Get system time stamp as 64-bit integer number.
  /*!
      \param a_cIsUTC - Get time stamp in UTC time flag (default is true).
      \return System time stamp as 64-bit integer number.
  */
  static Tsint64 getSystemTimeStamp(const Tbool a_cIsUTC = true);

  //! Get process time.
  /*!
      Process time is calculated starting from the execution  of  the  current
      process.

      \return Process time.
  */
  static NTime::CTime getProcessTime();
  //! Get system time.
  /*!
      \param a_cIsUTC - Get time in UTC time flag (default is true).
      \return System time.
  */
  static NTime::CTime getSystemTime(const Tbool a_cIsUTC = true);

  //! Set system time.
  /*!
      \param a_crTime - Constant reference to the instance of the CTime class.
      \param a_cIsUTC - Set time in UTC time flag (default is true).
      \return true  - if system time was successfully set. \n
              false - if system time was not successfully set. \n
  */
  static Tbool setSystemTime(const NTime::CTime& a_crTime, const Tbool a_cIsUTC = true);

  //! Get process date.
  /*!
      Process date is calculated starting from the execution  of  the  current
      process.

      \return Process date.
  */
  static NTime::CDate getProcessDate();
  //! Get system date.
  /*!
      \param a_cIsUTC - Get date in UTC time flag (default is true).
      \return System date.
  */
  static NTime::CDate getSystemDate(const Tbool a_cIsUTC = true);

  //! Set system date.
  /*!
      \param a_crDate - Constant reference to the instance of the CDate class.
      \param a_cIsUTC - Set date in UTC time flag (default is true).
      \return true  - if system date was successfully set. \n
              false - if system date was not successfully set. \n
  */
  static Tbool setSystemDate(const NTime::CDate& a_crDate, const Tbool a_cIsUTC = true);

  //! Get process date & time.
  /*!
      Process date & time is calculated starting from  the  execution  of  the
      current process.

      \return Process date & time.
  */
  static NTime::CDateTime getProcessDateTime();
  //! Get system date & time.
  /*!
      \param a_cIsUTC - Get date & time in UTC time flag (default is true).
      \return System date & time.
  */
  static NTime::CDateTime getSystemDateTime(const Tbool a_cIsUTC = true);

  //! Set system date & time.
  /*!
      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \param a_cIsUTC - Set date & time in UTC time flag (default is true).
      \return true  - if system date & time was successfully set. \n
              false - if system date & time was not successfully set. \n
  */
  static Tbool setSystemDateTime(const NTime::CDateTime& a_crDateTime, const Tbool a_cIsUTC = true);

  /*------------------------------------------------------------------------*/
  /* MATH METHODS                                                           */
  /*------------------------------------------------------------------------*/
  //! Copy sign from Y to X.
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return Number X with sign as in number Y.
  */
  static Tdouble copysign(const Tdouble a_cX, const Tdouble a_cY);
  //! Returns arccos(X).
  /*!
      \param a_cX - Double number.
      \return arccos(X).
  */
  static Tdouble acos(const Tdouble a_cX);
  //! Returns the inverse hyperbolic cosine of X.
  /*!
      \param a_cX - Double number.
      \return arccosh(X).
  */
  static Tdouble acosh(const Tdouble a_cX);
  //! Returns arcsin(X).
  /*!
      \param a_cX - Double number.
      \return arcsin(X).
  */
  static Tdouble asin(const Tdouble a_cX);
  //! Returns the inverse hyperbolic sine of X.
  /*!
      \param a_cX - Double number.
      \return arcsinh(X).
  */
  static Tdouble asinh(const Tdouble a_cX);
  //! Returns arctan(X).
  /*!
      \param a_cX - Double number.
      \return arctan(X).
  */
  static Tdouble atan(const Tdouble a_cX);
  //! Returns the inverse hyperbolic tangent of X.
  /*!
      \param a_cX - Double number.
      \return arctanh(X)
  */
  static Tdouble atanh(const Tdouble a_cX);
  //! Returns arctan2(X, Y).
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return arctan2(X, Y).
  */
  static Tdouble atan2(const Tdouble a_cX, const Tdouble a_cY);
  //! Returns cos(X).
  /*!
      \param a_cX - Double number.
      \return cos(X).
  */
  static Tdouble cos(const Tdouble a_cX);
  //! Returns cosh(X).
  /*!
      \param a_cX - Double number.
      \return cosh(X).
  */
  static Tdouble cosh(const Tdouble a_cX);
  //! Returns sin(X).
  /*!
      \param a_cX - Double number.
      \return sin(X).
  */
  static Tdouble sin(const Tdouble a_cX);
  //! Returns sinh(X).
  /*!
      \param a_cX - Double number.
      \return sinh(X).
  */
  static Tdouble sinh(const Tdouble a_cX);
  //! Returns tan(X).
  /*!
      \param a_cX - Double number.
      \return tan(X).
  */
  static Tdouble tan(const Tdouble a_cX);
  //! Returns tanh(X).
  /*!
      \param a_cX - Double number.
      \return tanh(X).
  */
  static Tdouble tanh(const Tdouble a_cX);
  //! Returns ln(X).
  /*!
      \param a_cX - Double number.
      \return ln(X).
  */
  static Tdouble log(const Tdouble a_cX);
  //! Returns log2(X).
  /*!
      \param a_cX - Double number.
      \return log2(X).
  */
  static Tdouble log2(const Tdouble a_cX);
  //! Returns log10(X).
  /*!
      \param a_cX - Double number.
      \return Log10(X).
  */
  static Tdouble log10(const Tdouble a_cX);
  //! Returns X^Y.
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return X^Y.
  */
  static Tdouble pow(const Tdouble a_cX, const Tdouble a_cY);
  //! Returns e^X.
  /*!
      \param a_cX - Double number.
      \return e^X.
  */
  static Tdouble exp(const Tdouble a_cX);
  //! Returns 2^X.
  /*!
      \param a_cX - Double number.
      \return 2^X.
  */
  static Tdouble exp2(const Tdouble a_cX);
  //! Returns 10^X.
  /*!
      \param a_cX - Double number.
      \return 10^X.
  */
  static Tdouble exp10(const Tdouble a_cX);
  //! Returns e^X-1 (Using: e^x-1=2^(x*log2(e))-1).
  /*!
      \param a_cX - Double number.
      \return e^X-1.
  */
  static Tdouble expm1(const Tdouble a_cX);
  //! Returns square root of X.
  /*!
      \param a_cX - Double number.
      \return sqrt(X).
  */
  static Tdouble sqrt(const Tdouble a_cX);
  //! Returns cubic root of X.
  /*!
      \param a_cX - Double number.
      \return cbrt(X).
  */
  static Tdouble cbrt(const Tdouble a_cX);
  //! Returns |X|.
  /*!
      \param a_cX - Double number.
      \return |X|.
  */
  static Tdouble fabs(const Tdouble a_cX);
  //! Compute positive difference.
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return Positive difference.
  */
  static Tdouble fdim(const Tdouble a_cX, const Tdouble a_cY);
  //! Compute (X * Y) + Z as ternary operation.
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \param a_cZ - Double number Z.
      \return (X * Y) + Z.
  */
  static Tdouble fma(const Tdouble a_cX, const Tdouble a_cY, const Tdouble a_cZ);
  //! Compute maximum of two numbers, regarding NaN as missing argument.
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return Maximum of two numbers.
  */
  static Tdouble fmax(const Tdouble a_cX, const Tdouble a_cY);
  //! Compute minimum of two numbers, regarding NaN as missing argument.
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return Minimum of two numbers.
  */
  static Tdouble fmin(const Tdouble a_cX, const Tdouble a_cY);
  //! Returns X mod Y.
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return X mod Y.
  */
  static Tdouble fmod(const Tdouble a_cX, const Tdouble a_cY);
  //! Returns ceil(X).
  /*!
      \param a_cX - Double number.
      \return ceil(X).
  */
  static Tdouble ceil(const Tdouble a_cX);
  //! Returns floor(X).
  /*!
      \param a_cX - Double number.
      \return floor(X).
  */
  static Tdouble floor(const Tdouble a_cX);
  //! Calculate polynome p=C[n-1]*X^n+C[n-2]*X^(n-1)+...+C[1]*X+C[0].
  /*!
      \param a_cX - Double number X.
      \param a_cN - Size of the polynome coefficients.
      \param a_cpC - Constant pointer to the polynome coefficient array.
      \return Polinome value.
  */
  static Tdouble poly(const Tdouble a_cX, const Tsint a_cN, const Tdouble* a_cpC);
  //! Calculate hypotinuse C=sqrt(X^2+Y^2).
  /*!
      \param a_cX - Double number X.
      \param a_cY - Double number Y.
      \return Hypotinuse value.
  */
  static Tdouble hypot(const Tdouble a_cX, const Tdouble a_cY);
  //! Get M and P where X=M*2^P (0.5<=M<1).
  /*!
      \param a_cX - Double number X.
      \param a_pExp - Pointer to result value - exponent.
      \return frexp(X, Exp).
  */
  static Tdouble frexp(const Tdouble a_cX, Tsint* a_pExp);
  //! Calculate value=X*2^exp (0.5<=X<1).
  /*!
      \param a_cX - Double number X.
      \param a_cExp - Exponent.
      \return ldexp(X, Exp).
  */
  static Tdouble ldexp(const Tdouble a_cX, const Tsint a_cExp);
  //! Make integer and real part of a number.
  /*!
      \param a_cX - Double number.
      \param a_pInteger - Pointer to result value - integer part of the number.
      \return Real part.
  */
  static Tdouble modf(const Tdouble a_cX, Tdouble* a_pInteger);
  //! Calculate both sin(X) and cos(X).
  /*!
      \param a_cX - Double number.
      \param a_pSin - Pointer to result value - sin(X).
      \param a_pCos - Pointer to result value - cos(X).
  */
  static void sincos(const Tdouble a_cX, Tdouble* a_pSin, Tdouble* a_pCos);

  /*------------------------------------------------------------------------*/
  /* READER/WRITER LOCK METHODS                                             */
  /*------------------------------------------------------------------------*/
  //! Create a new reader/writer lock.
  /*!
      Method creates a new reader/writer lock instance and returns its handle.
      If reader/writer lock cannot be created the NULL value is returned.

      \return Handle to the new reader/writer lock.
  */
  static Tptr RWLCreate();
  //! Destroy the given reader/writer lock.
  /*!
      Method destroys the reader/writer lock represented with its handle.

      \param a_cpRWLHandle - Constant handle to the reader/writer lock.
      \return true  - if the reader/writer lock was successfully destroyed. \n
              false - if the reader/writer lock was not successfully destroyed. \n
  */
  static Tbool RWLDestroy(const Tptr a_cpRWLHandle);
  //! Reader lock the given reader/writer lock.
  /*!
      Method locks given reader/writer lock  for  reading.  Many  readers  can
      perform reader lock. If some writer locks data for  writing  the  method
      blocks the current thread until the given reader/writer lock is free for
      readig and then enter into and lock it for reading.  Therefore,  a  code
      block, which is controlled by a reader lock, is accessible only for  the
      current thread and readers from other threads at one time.

      \param a_cpRWLHandle - Constant handle to the reader/writer lock.
      \return true  - if the current reader thread successfully lock the given reader/writer lock. \n
              false - if the current reader thread did not successfully lock the given reader/writer lock. \n
  */
  static Tbool RWLLockReader(const Tptr a_cpRWLHandle);
  //! Writer lock the given reader/writer lock.
  /*!
      Method locks given reader/writer lock for writing. Only one  writer  can
      perform writer lock. Method blocks the current thread until all  readers
      and writers are free for writing and then enter into  and  lock  it  for
      writing. Therefore, a code block, which is controlled by a writer  lock,
      is accessible only for the current thread at one time.

      \param a_cpRWLHandle - Constant handle to the reader/writer lock.
      \return true  - if the current writer thread successfully lock the given reader/writer lock. \n
              false - if the current writer thread did not successfully lock the given reader/writer lock. \n
  */
  static Tbool RWLLockWriter(const Tptr a_cpRWLHandle);
  //! Reader unlock the given given reader/writer lock.
  /*!
      Method release reader lock for the given reader/writer lock.

      \param a_cpRWLHandle - Constant handle to the reader/writer lock.
      \return true  - if the current reader thread successfully unlock the given reader/writer lock. \n
              false - if the current reader thread did not successfully unlock the given reader/writer lock. \n
  */
  static Tbool RWLUnlockReader(const Tptr a_cpRWLHandle);
  //! Writer unlock the given given reader/writer lock.
  /*!
      Method release writer lock for the given reader/writer lock.

      \param a_cpRWLHandle - Constant handle to the reader/writer lock.
      \return true  - if the current writer thread successfully unlock the given reader/writer lock. \n
              false - if the current writer thread did not successfully unlock the given reader/writer lock. \n
  */
  static Tbool RWLUnlockWriter(const Tptr a_cpRWLHandle);
  //! Try to reader lock the given reader/writer lock.
  /*!
      Method tries to lock the given reader/writer lock for  reading.  If  the
      reader/writer lock is free for reading the current thread locks  it  for
      reading and the method returns 'true'. Otherwise, method does not blocks
      and returns 'false' immediately.

      \param a_cpRWLHandle - Constant handle to the reader/writer lock.
      \return true  - if the given reader/writer lock is free for reading and the current thread successfully lock it for reading. \n
              false - if the given reader/writer lock is busy for reading and the current thread did not lock it for reading. \n
  */
  static Tbool RWLTryLockReader(const Tptr a_cpRWLHandle);
  //! Try to writer lock the given reader/writer lock.
  /*!
      Method tries to lock the given reader/writer lock for  writing.  If  the
      reader/writer lock is free for writing the current thread locks  it  for
      writing and the method returns 'true'. Otherwise, method does not blocks
      and returns 'false' immediately.

      \param a_cpRWLHandle - Constant handle to the reader/writer lock.
      \return true  - if the given reader/writer lock is free for writing and the current thread successfully lock it for writing. \n
              false - if the given reader/writer lock is busy for writing and the current thread did not lock it for writing. \n
  */
  static Tbool RWLTryLockWriter(const Tptr a_cpRWLHandle);

private:
  static Tbool ms_InstallFlag;          //!< Is system installed?
  static NProcess::CRWLock ms_Locker;   //!< Shared library reader/writer locker.

  static NProcess::CCriticalSection ms_StdErrorLocker;  //!< Critical section locker for the standard error stream.
  static NProcess::CCriticalSection ms_StdInputLocker;  //!< Critical section locker for the standard input stream.
  static NProcess::CCriticalSection ms_StdOutputLocker; //!< Critical section locker for the standard output stream.

  static Tsint64 ms_ProcessTimeStamp;   //!< Process start time stamp.

  // ISharedLibrary interface overriding methods.
  virtual Tbool onLoad();
  virtual Tbool onUnload();

  //! Install system encoding functionality.
  /*!
      \return true  - if system encoding functionality was successfully installed. \n
              false - if system encoding functionality was not successfully installed. \n
  */
  static Tbool installSystemEncoding();
  //! Install system encoding functionality.
  /*!
      \return true  - if system encoding functionality was successfully uninstalled. \n
              false - if system encoding functionality was not successfully uninstalled. \n
  */
  static Tbool uninstallSystemEncoding();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/system/CSystemBase.inl>
/*==========================================================================*/
#endif
