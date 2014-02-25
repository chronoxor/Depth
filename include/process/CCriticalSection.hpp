/*!
 *  \file    CCriticalSection.hpp Critical section is a synchronization object
 *           which prevents multiple thread access to the protected code block.
 *  \brief   Critical section class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Critical section class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   14.06.2007 21:42:33

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
#ifndef __CCRITICALSECTION_HPP__
#define __CCRITICALSECTION_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Critical section class.
/*!
    Critical section is  a  synchronization  object  which  prevents  multiple
    thread access to the protected code block.

    Critical section does not support the recursion lock of  the  same  thread
    for multiple times. In case of recursion lock the behavior is undefined an
    may cause the deadlock.

    Important: Each new initialized critical section has unique system handle,
    which is destroyed  manually  or  through  the  destructor.  Copy  of  the
    critical section just copies the system handle, but does not  destroy  it.
    Only main critical section can destroy its system handle.

    Serialization: Critical section cannot be serialized.

    <b>Overview.</b>\n
    In concurrent programming a critical section  is  a  piece  of  code  that
    accesses a shared resource (data structure or device)  that  must  not  be
    urrently accessed by more than one thread of execution. A critical section
    will usually terminate in fixed time, and a thread, task or  process  will
    only have to wait a fixed time to enter it (i.e.  bounded  waiting).  Some
    synchronization mechanism is  required  at  the  entry  and  exit  of  the
    critical section to ensure exclusive use, for example a semaphore.

    By carefully controlling which variables are modified inside  and  outside
    the critical section (usually, by  accessing  important  state  only  from
    within), concurrent access to that state is prevented. A critical  section
    is typically used  when  a  multithreaded  program  must  update  multiple
    related variables without a separate thread making conflicting changes  to
    that data. In a related situation, a  critical  section  may  be  used  to
    ensure a shared resource, for example a printer, can only be  accessed  by
    one process at a time.

    How critical sections are implemented varies among operating systems.

    The simplest method is to prevent any change of processor  control  inside
    the critical section. On  uni-processor  systems,  this  can  be  done  by
    disabling interrupts on entry into the critical section,  avoiding  system
    calls that can cause  a  context  switch  while  inside  the  section  and
    restoring interrupts to their  previous  state  on  exit.  Any  thread  of
    execution entering any critical section anywhere in the system will,  with
    this implementation, prevent any other  thread,  including  an  interrupt,
    from getting the CPU  and  therefore  from  entering  any  other  critical
    section or, indeed, any code whatsoever, until the original thread  leaves
    its critical section.

    This brute-force approach can be improved upon  by  using  semaphores.  To
    enter a critical section, a thread  must  obtain  a  semaphore,  which  it
    releases on leaving the section. Other threads are prevented from entering
    the critical section at the same time as the original thread, but are free
    to gain control of  the  CPU  and  execute  other  code,  including  other
    critical sections that are protected by different semaphores.

    Some confusion exists in the literature  about  the  relationship  between
    different critical sections in the same program. In  general,  a  resource
    that must be protected from concurrent access may be accessed  by  several
    pieces of code. Each piece must be guarded by a common semaphore. Is  each
    piece now a critical section or are all the pieces  guarded  by  the  same
    semaphore in aggregate  a  single  critical  section?  This  confusion  is
    evident in definitions of a critical section such as "... a piece of  code
    that can only be executed by one process or thread at a time".  This  only
    works if all access to a protected resource is contained in one "piece  of
    code", which requires either the definition of a piece of code or the code
    itself to be somewhat contrived.

    <b>Taken from:</b>\n
    Critical section from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Critical_section
*/
class BASE_API CCriticalSection
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CCriticalSection TDepthCheckType;

  // Check CCriticalSection class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create initialized or non initialized critical section.

      \param a_cInitialize - Critical section initialize flag (default is false).
  */
  CCriticalSection(const Tbool a_cInitialize = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCriticalSection class.
  */
  CCriticalSection(const CCriticalSection& a_crInstance);
  //! Class destructor.
  /*!
      Destructor will destroy system handle of initialized critical section.
  */
 ~CCriticalSection();

  //! Operator: Equal to another CCriticalSection class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCriticalSection class.
      \param a_crInstance2 - Constant reference to another instance of the CCriticalSection class.
      \return true  - if CCriticalSection class instance is equal to another one. \n
              false - if CCriticalSection class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CCriticalSection& a_crInstance1, const CCriticalSection& a_crInstance2);
  //! Operator: Not equal to another CCriticalSection class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCriticalSection class.
      \param a_crInstance2 - Constant reference to another instance of the CCriticalSection class.
      \return true  - if CCriticalSection class instance is not equal to another one. \n
              false - if CCriticalSection class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CCriticalSection& a_crInstance1, const CCriticalSection& a_crInstance2);

  //! Operator: Assign another CCriticalSection class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCriticalSection class.
      \return Reference to the current class instance.
  */
  CCriticalSection& operator = (const CCriticalSection& a_crInstance);

  //! Set another CCriticalSection class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCriticalSection class.
      \return true  - if another critical section was successfully set. \n
              false - if another critical section was not successfully set. \n
  */
  Tbool set(const CCriticalSection& a_crInstance);

  //! Get system handle of the current critical section.
  /*!
      \return System handle of the current critical section.
  */
  Tptr getHandle();
  //! Get constant system handle of the current critical section.
  /*!
      \return Constant system handle of the current critical section.
  */
  Tcptr getHandle() const;

  //! Is critical section initialized?
  /*!
      \return true  - if critical section is initialized. \n
              false - if critical section is not initialized. \n
  */
  Tbool isInitialized() const;

  //! Initialize critical section with a new system handle.
  /*!
      Method initialize the current  critical  section  instance  with  a  new
      system handle. If the current critical section is  already  initialized,
      it will be destroyed and new instance will be created.

      \return true  - if critical section was successfully initialized. \n
              false - if critical section was not successfully initialized. \n
  */
  Tbool initialize();
  //! Destroy critical section and remove its system handle.
  /*!
      Method destroy the current critical  section  instance  and  remove  its
      system handle.

      \return true  - if critical section was successfully destroyed. \n
              false - if critical section was not successfully destroyed. \n
  */
  Tbool destroy();

  //! Lock the critical section.
  /*!
      Method blocks the current thread until the critical section is free  and
      then enter into it. Therefore, a code block, which is  controlled  by  a
      critical section, is accessible only  for  one  thread  of  the  current
      process at one time.

      \return true  - if the current thread successfully entered into the critical section and lock it. \n
              false - if the current thread did not successfully enter into the critical section and lock it. \n
  */
  Tbool lock();
  //! Unlock the critical section.
  /*!
      Method leaves and unlocks the critical section. After  critical  section
      is unlock, other threads may enter into and lock it.

      \return true  - if the current thread successfully left the critical section and unlock it. \n
              false - if the current thread did not successfully leave the critical section and unlock it. \n
  */
  Tbool unlock();
  //! Try to lock the critical section.
  /*!
      Method tries to enter into the critical section  and  lock  it.  If  the
      critical section is free the thread enters into  and  lock  it  and  the
      method returns 'true'. Otherwise, method does  not  blocks  and  returns
      'false' immediately.

      \return true  - if the critical section is free and the current thread successfully entered into and lock it. \n
              false - if the critical section is busy and the current thread did not enter into and lock it. \n
  */
  Tbool tryLock();

  //! Serialize CCriticalSection class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CCriticalSection class instances.
  /*!
      \param a_rInstance - Reference to another CCriticalSection class instance.
  */
  void swap(CCriticalSection& a_rInstance);

private:
  Tbool m_IsMainHandle;                 //!< Main system handle flag.
  Tptr  m_pHandle;                      //!< Critical section system handle.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/process/CCriticalSection.inl>
/*==========================================================================*/
#endif
