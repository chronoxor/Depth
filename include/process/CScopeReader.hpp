/*!
 *  \file    CScopeReader.hpp Scope reader is a synchronization object which
 *           allows multiple reader threads access to the set of protected
 *           code blocks in the shared mode.
 *  \brief   Scope reader class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Scope reader class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   24.01.2011 18:56:25

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
#ifndef __CSCOPEREADER_HPP__
#define __CSCOPEREADER_HPP__
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
//! Scope reader class.
/*!
    Scope reader is a synchronization  object  which  allows  multiple  reader
    threads access to the set of protected code blocks in the shared mode.  It
    bounds code block from its declaration to its destruction - a scope. Scope
    reader is initialized with the instance of the reader/writer  lock.  Scope
    reader can be in a one of locked  or  unlocked  states.  When  the  reader
    thread meets locked scope reader, it does not block and  enters  scope  in
    the shared mode.

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
        CScopeReader rlocker(rwl);

        printf("CSynchronizedTest::test1()");
      }

      void test2()
      {
        CScopeWriter wlocker(rwl);

        printf("CSynchronizedTest::test2()");
      }

    private:
      CRWLock rwl;
    };
    \endcode
*/
class BASE_API CScopeReader
{
public:
  //! Initialize scope reader.
  /*!
      Create and initialize scope reader with the  given  reader/writer  lock.
      Lock flag defines if the current thread should lock  the  created  scope
      reader. If the given reader/writer lock is not initialized,  constructor
      will initialize it automatically.

      \param a_crRWLock - Reference to the initial instance of the CRWLock class.
      \param a_cLock - Lock the scope reader flag (default is true).
  */
  CScopeReader(CRWLock& a_crRWLock, const Tbool a_cLock = true);
  //! Class destructor.
  /*!
      Destructor  unlocks  the  locked  scope  reader  and  leaves  from   the
      reader/writer lock in the shared mode.
  */
 ~CScopeReader();

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

  //! Is scope reader locked?
  /*!
      \return true  - if scope reader is locked. \n
              false - if scope reader is unlocked. \n
  */
  Tbool isLocked() const;

  //! Lock the scope reader.
  /*!
      Method waits until the scope will  be  accessed  for  reading  and  then
      enters and locks it for the shared reading.  Therefore,  a  code  block,
      which is controlled by the scope  reader,  is  accessible  for  multiple
      reader threads in the shared mode.

      \return true  - if the current reader thread successfully locked the scope reader. \n
              false - if the current reader thread did not successfully locked the scope reader. \n
  */
  Tbool lock();
  //! Unlock the scope reader.
  /*!
      Method unlocks the scope reader. After all  similar  scope  readers  are
      unlocked, writer thread may lock it in the exclusive mode.

      \return true  - if the current reader thread successfully unlocks the scope reader. \n
              false - if the current reader thread did not successfully unlocks the scope reader. \n
  */
  Tbool unlock();
  //! Try to lock the scope reader.
  /*!
      Method tries to lock the scope reader. If the scope reader  is  unlocked
      for reading the reader thread locks it and the  method  returns  'true'.
      Otherwise, method does not block and returns 'false' immediately.

      \return true  - if the scope reader is unlocked and the current reader thread successfully locked it. \n
              false - if the scope reader is locked and the current reader thread did not locked it. \n
  */
  Tbool tryLock();

private:
  Tbool    m_IsLocked;                  //!< Scope reader lock flag.
  CRWLock& m_rRWLock;                   //!< Reference to the reader/writer lock instance.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/process/CScopeReader.inl>
/*==========================================================================*/
#endif
