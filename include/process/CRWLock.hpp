/*!
 *  \file    CRWLock.hpp Reader/Writer lock is a synchronization object
 *           which prevents multiple reading and writing threads access
 *           to the protected code block.
 *  \brief   Reader/Writer lock class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader/Writer lock class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Process
    VERSION:   1.0
    CREATED:   21.01.2011 20:28:50

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
#ifndef __CRWLOCK_HPP__
#define __CRWLOCK_HPP__
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
//! Reader/Writer lock class.
/*!
    Reader/Writer lock is  a  synchronization  object  which  prevents  multiple
    reading and writing threads access to the protected code block.

    Reader/Writer lock support the recursion lock only for reading threads. In
    case of recursion lock for writing the behavior is undefined an may  cause
    the deadlock.

    Important: Each new  initialized  reader/writer  lock  has  unique  system
    handle, which is destroyed manually or through the destructor. Copy of the
    reader/writer lock just copies the system handle, but does not destroy it.
    Only main reader/writer lock can destroy its system handle.

    Serialization: Reader/Writer lock cannot be serialized.

    <b>Overview.</b>\n
    In computer science, a readers-writer or shared-exclusive lock (also known
    by the name multi-reader  lock,  or  by  typographical  variants  such  as
    readers/writers lock) is a synchronization primitive that  solves  one  of
    the readers-writers problems. A readers-writer lock is like  a  mutex,  in
    that it controls access to some shared memory area, but it allows multiple
    threads to read from the shared area concurrently. Any thread  that  needs
    to write to the shared memory, of course, needs to  acquire  an  exclusive
    lock.

    One potential problem with a conventional RW lock is that it can  lead  to
    write-starvation, meaning that as long as  at  least  one  reading  thread
    holds the lock, no writer  thread  will  be  able  to  acquire  it.  Since
    multiple reader threads may hold the lock  at  once,  this  means  that  a
    writer thread may continue waiting for the lock while new  reader  threads
    are able to acquire the lock, even to the point where the writer may still
    be waiting after all of the readers which were holding the  lock  when  it
    first attempted to acquire it have finished their work in the shared  area
    and released the  lock.  To  avoid  writer  starvation,  a  variant  on  a
    readers-writer lock can be constructed which prevents any new readers from
    acquiring the lock if there is a writer queued and waiting for  the  lock,
    so that the writer will acquire the lock as soon as the readers which were
    already holding the lock are finished with it. This variation is sometimes
    known as a "write-preferring" or "write-biased" readers-writer lock.

    Readers-writer locks  are  usually  constructed  on  top  of  mutexes  and
    condition variables, or on top of semaphores. They are rarely  implemented
    from scratch.

    The  read-copy-update   (RCU)   algorithm   is   one   solution   to   the
    readers-writers problem. RCU is wait-free for  readers.  The  Linux-Kernel
    implements a special solution for few writers called seqlock.

    A read/write lock pattern or simply RWL is a software design pattern  that
    allows concurrent read access to an object but requires  exclusive  access
    for write operations.

    In this pattern, multiple readers can read the data  in  parallel  but  an
    exclusive lock is needed while writing the data. When a writer is  writing
    the data, readers will be blocked until the writer is finished writing.

    Note that operations(either read or write) which  you  want  to  allow  in
    parallel should grab the lock in read mode, and operations(either read  or
    write) that you want to be exclusive should grab the lock in write mode.

    <b>Taken from:</b>\n
    Reader/Writer lock from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Readers-writer_lock
*/
class BASE_API CRWLock
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRWLock TDepthCheckType;

  // Check CRWLock class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create initialized or non initialized reader/writer lock.

      \param a_cInitialize - Reader/Writer lock initialize flag (default is false).
  */
  CRWLock(const Tbool a_cInitialize = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRWLock class.
  */
  CRWLock(const CRWLock& a_crInstance);
  //! Class destructor.
  /*!
      Destructor will destroy system handle of initialized reader/writer lock.
  */
 ~CRWLock();

  //! Operator: Equal to another CRWLock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRWLock class.
      \param a_crInstance2 - Constant reference to another instance of the CRWLock class.
      \return true  - if CRWLock class instance is equal to another one. \n
              false - if CRWLock class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CRWLock& a_crInstance1, const CRWLock& a_crInstance2);
  //! Operator: Not equal to another CRWLock class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRWLock class.
      \param a_crInstance2 - Constant reference to another instance of the CRWLock class.
      \return true  - if CRWLock class instance is not equal to another one. \n
              false - if CRWLock class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CRWLock& a_crInstance1, const CRWLock& a_crInstance2);

  //! Operator: Assign another CRWLock class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRWLock class.
      \return Reference to the current class instance.
  */
  CRWLock& operator = (const CRWLock& a_crInstance);

  //! Set another CRWLock class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRWLock class.
      \return true  - if another reader/writer lock was successfully set. \n
              false - if another reader/writer lock was not successfully set. \n
  */
  Tbool set(const CRWLock& a_crInstance);

  //! Get system handle of the current reader/writer lock.
  /*!
      \return System handle of the current reader/writer lock.
  */
  Tptr getHandle();
  //! Get constant system handle of the current reader/writer lock.
  /*!
      \return Constant system handle of the current reader/writer lock.
  */
  Tcptr getHandle() const;

  //! Is reader/writer lock initialized?
  /*!
      \return true  - if reader/writer lock is initialized. \n
              false - if reader/writer lock is not initialized. \n
  */
  Tbool isInitialized() const;

  //! Initialize reader/writer lock with a new system handle.
  /*!
      Method initialize the current reader/writer lock  instance  with  a  new
      system handle. If the current reader/writer lock is already initialized,
      it will be destroyed and new instance will be created.

      \return true  - if reader/writer lock was successfully initialized. \n
              false - if reader/writer lock was not successfully initialized. \n
  */
  Tbool initialize();
  //! Destroy reader/writer lock and remove its system handle.
  /*!
      Method destroy the current reader/writer lock instance  and  remove  its
      system handle.

      \return true  - if reader/writer lock was successfully destroyed. \n
              false - if reader/writer lock was not successfully destroyed. \n
  */
  Tbool destroy();

  //! Lock the reader lock.
  /*!
      Method enters the  reader/writer  lock  as  a  reader  acquiring  shared
      resources. If no writer threads entered reader/writer lock  method  will
      not block. Method blocks the current thread until current writer release
      its lock and shared resources will be available for reading.  Therefore,
      a code block, which is controlled by a reader lock,  is  accessible  for
      all readers threads of the current process at one time.

      \return true  - if the current reader thread successfully entered into the reader/writer lock and lock it. \n
              false - if the current reader thread did not successfully enter into the reader/writer lock and lock it. \n
  */
  Tbool lockReader();
  //! Lock the writer lock.
  /*!
      Method enters the  reader/writer  lock  as  a  writer  acquiring  shared
      resources with exclusive rights. Method blocks the current thread  until
      all current readers or current writer release  their  locks  and  shared
      resources will be available for writing. Therefore, a code block,  which
      is controlled by a writer  lock,  is  not  accessible  for  readers  and
      writers threads of the current process until the current writer  release
      its lock.

      \return true  - if the current writer thread successfully entered into the reader/writer lock and lock it. \n
              false - if the current writer thread did not successfully enter into the reader/writer lock and lock it. \n
  */
  Tbool lockWriter();
  //! Unlock the reader lock.
  /*!
      Method leaves and unlocks the reader lock. Only after all  reader  locks
      are unlock, writers threads may enter into and lock.

      \return true  - if the current thread successfully left the reader lock and unlock it. \n
              false - if the current thread did not successfully leave the reader lock and unlock it. \n
  */
  Tbool unlockReader();
  //! Unlock the writer lock.
  /*!
      Method leaves and unlocks the writer lock. Only  after  writer  lock  is
      unlock, reader threads may enter into and lock.

      \return true  - if the current thread successfully left the writer lock and unlock it. \n
              false - if the current thread did not successfully leave the writer lock and unlock it. \n
  */
  Tbool unlockWriter();
  //! Try to lock the reader lock.
  /*!
      Method  tries  to  enter  reader/writer  lock  as  a  reader.   If   the
      reader/writer lock is free for reading the thread enters into  and  lock
      it for reading and the method returns 'true'. Otherwise, method does not
      blocks and returns 'false' immediately.

      \return true  - if the reader/writer lock is free and the current thread successfully entered into and lock it for reading. \n
              false - if the reader/writer lock is busy and the current thread did not enter into and lock it for reading. \n
  */
  Tbool tryLockReader();
  //! Try to lock the writer lock.
  /*!
      Method  tries  to  enter  reader/writer  lock  as  a  writer.   If   the
      reader/writer lock is free for writing the thread enters into  and  lock
      it for writing and the method returns 'true'. Otherwise, method does not
      blocks and returns 'false' immediately.

      \return true  - if the reader/writer lock is free and the current thread successfully entered into and lock it for writing. \n
              false - if the reader/writer lock is busy and the current thread did not enter into and lock it for writing. \n
  */
  Tbool tryLockWriter();

  //! Serialize CRWLock class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRWLock class instances.
  /*!
      \param a_rInstance - Reference to another CRWLock class instance.
  */
  void swap(CRWLock& a_rInstance);

private:
  Tbool m_IsMainHandle;                 //!< Main system handle flag.
  Tptr  m_pHandle;                      //!< Reader/Writer lock system handle.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/process/CRWLock.inl>
/*==========================================================================*/
#endif
