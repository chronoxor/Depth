/*!
 *  \file    CScopeWriter.hpp Scope writer is a synchronization object which
 *           allows single writer thread access to the set of protected
 *           code blocks in the exclusive mode.
 *  \brief   Scope writer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Scope writer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   24.01.2011 19:12:52

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
#ifndef __CSCOPEWRITER_HPP__
#define __CSCOPEWRITER_HPP__
/*==========================================================================*/
#include <Depth/include/process/CRWLock.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NProcess {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Scope writer class.
/*!
    Scope writer is a synchronization object which allows single writer thread
    access to the set of protected code  blocks  in  the  exclusive  mode.  It
    bounds code block from its declaration to its destruction - a scope. Scope
    writer is initialized with the instance of the reader/writer  lock.  Scope
    writer can be in a one of locked  or  unlocked  states.  When  the  writer
    thread meets locked scope reader or writer, it blocks until it is unlocked
    and then enters scope in the exclusive mode.

    Note that reader/writer lock does not support recursion,  therefore  avoid
    to enter one scope reader or writer from another with a same reader/writer
    lock!

    Example:
    \code
    class CSynchronizedTest
    {
    public:
      void test1()
      {
        CScopeReader locker(rwl);

        printf("CSynchronizedTest::test1()");
      }

      void test2()
      {
        CScopeWriter locker(rwl);

        printf("CSynchronizedTest::test2()");
      }

    private:
      CRWLock rwl;
    };
    \endcode
*/
class BASE_API CScopeWriter
{
public:
  //! Initialize scope writer.
  /*!
      Create and initialize scope writer with the  given  reader/writer  lock.
      Lock flag defines if the current thread should lock  the  created  scope
      writer. If the given reader/writer lock is not initialized,  constructor
      will initialize it automatically.

      \param a_crRWLock - Reference to the initial instance of the CRWLock class.
      \param a_cLock - Lock the scope reader flag (default is true).
  */
  CScopeWriter(CRWLock& a_crRWLock, const Tbool a_cLock = true);
  //! Class destructor.
  /*!
      Destructor  unlocks  the  locked  scope  writer  and  leaves  from   the
      reader/writer lock in the exclusive mode.
  */
 ~CScopeWriter();

  //! Get the current reader/writer lock instance.
  /*!
      \return Reference to the current reader/writer lock instance.
  */
  CRWLock& getRWLock();
  //! Get the current constant reader/writer lock instance.
  /*!
      \return Constant reference to the current reader/writer lock instance.
  */
  const CRWLock& getRWLock() const;

  //! Is scope writer locked?
  /*!
      \return true  - if scope writer is locked. \n
              false - if scope writer is unlocked. \n
  */
  Tbool isLocked() const;

  //! Lock the scope writer.
  /*!
      Method waits until the scope will  be  accessed  for  writing  and  then
      enters and locks it for exclusive  writing.  Therefore,  a  code  block,
      which is controlled by the scope writer, is  not  accessible  for  other
      reader or writer threads.

      \return true  - if the current writer thread successfully locked the scope writer. \n
              false - if the current writer thread did not successfully locked the scope writer. \n
  */
  Tbool lock();
  //! Unlock the scope writer.
  /*!
      Method unlocks the scope writer. After the scope writer is unlocked, any
      of readers and writers threads may lock it.

      \return true  - if the current writer thread successfully unlocks the scope writer. \n
              false - if the current writer thread did not successfully unlocks the scope writer. \n
  */
  Tbool unlock();
  //! Try to lock the scope writer.
  /*!
      Method tries to lock the scope writer. If the scope writer  is  unlocked
      for writing the writer thread locks it and the  method  returns  'true'.
      Otherwise, method does not block and returns 'false' immediately.

      \return true  - if the scope writer is unlocked and the current writer thread successfully locked it. \n
              false - if the scope writer is locked and the current writer thread did not locked it. \n
  */
  Tbool tryLock();

private:
  Tbool    m_IsLocked;                  //!< Scope writer lock flag.
  CRWLock& m_rRWLock;                   //!< Reference to the reader/writer lock instance.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/process/CScopeWriter.inl>
/*==========================================================================*/
#endif
