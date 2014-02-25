/*!
 *  \file    CScopeLocker.hpp Scope locker is a synchronization object which
 *           prevents multiple thread access to the set of protected code
 *           blocks.
 *  \brief   Scope locker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Scope locker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   20.06.2007 22:17:42

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
#ifndef __CSCOPELOCKER_HPP__
#define __CSCOPELOCKER_HPP__
/*==========================================================================*/
#include <Depth/include/process/CCriticalSection.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Scope locker class.
/*!
    Scope locker is a synchronization object which  prevents  multiple  thread
    access to the set of protected code blocks. It bounds code block from  its
    declaration to its destruction - a scope. Scope locker is initialized with
    the instance of the critical section. Scope locker can  be  in  a  one  of
    locked or unlocked states. When the thread meets locked scope  locker,  it
    blocks until scope locker becomes unlocked.  Then  the  thread  locks  the
    scope locker and resume its flow.

    Note that critical section does not support recursion, therefore avoid  to
    enter one scope locker from another with a same critical section!

    Example:
    \code
    class CSynchronizedTest
    {
    public:
      void test1()
      {
        CScopeLocker locker(cs);

        printf("CSynchronizedTest::test1()");
      }

      void test2()
      {
        CScopeLocker locker(cs);

        printf("CSynchronizedTest::test2()");
      }

    private:
      CCriticalSection cs;
    };
    \endcode
*/
class BASE_API CScopeLocker
{
public:
  //! Initialize scope locker.
  /*!
      Create and initialize scope locker with the given critical section. Lock
      flag defines if the current thread should lock the created scope locker.
      If the given critical  section  is  not  initialized,  constructor  will
      initialize it automatically.

      \param a_crCriticalSection - Reference to the initial instance of the CCriticalSection class.
      \param a_cLock - Lock the scope locker flag (default is true).
  */
  CScopeLocker(CCriticalSection& a_crCriticalSection, const Tbool a_cLock = true);
  //! Class destructor.
  /*!
      Destructor unlocks the locked scope locker and leaves from the  critical
      section.
  */
 ~CScopeLocker();

  //! Get the current critical section instance.
  /*!
      \return Reference to the current critical section instance.
  */
  CCriticalSection& getCriticalSection();
  //! Get the current constant critical section instance.
  /*!
      \return Constant reference to the current critical section instance.
  */
  const CCriticalSection& getCriticalSection() const;

  //! Is scope locker locked?
  /*!
      \return true  - if scope locker is locked. \n
              false - if scope locker is unlocked. \n
  */
  Tbool isLocked() const;

  //! Lock the scope locker.
  /*!
      Method blocks the current thread until the scope locker is unlocked  and
      then locks it. Therefore, a code block, which is controlled by  a  scope
      locker, is accessible only for one thread at one time.

      \return true  - if the current thread successfully locked the scope locker. \n
              false - if the current thread did not successfully locked the scope locker. \n
  */
  Tbool lock();
  //! Unlock the scope locker.
  /*!
      Method unlocks the scope locker. After scope locker is  unlocked,  other
      threads may lock it.

      \return true  - if the current thread successfully unlocks the scope locker. \n
              false - if the current thread did not successfully unlocks the scope locker. \n
  */
  Tbool unlock();
  //! Try to lock the scope locker.
  /*!
      Method tries to lock the scope locker. If the scope locker  is  unlocked
      the thread locks it and the method  returns  'true'.  Otherwise,  method
      does not block and returns 'false' immediately.

      \return true  - if the scope locker is unlocked and the current thread successfully locked it. \n
              false - if the scope locker is locked and the current thread did not locked it. \n
  */
  Tbool tryLock();

private:
  Tbool             m_IsLocked;                     //!< Scope locker lock flag.
  CCriticalSection& m_rCriticalSection;             //!< Reference to the critical section instance.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/process/CScopeLocker.inl>
/*==========================================================================*/
#endif
