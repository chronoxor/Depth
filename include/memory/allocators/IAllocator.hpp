/*!
 *  \file    IAllocator.hpp Memory allocator interface provide functionality
 *           that helps to create and destroy various type instances.
 *  \brief   Memory allocator interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory allocator interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory allocators
    VERSION:   1.0
    CREATED:   15.01.2007 02:20:32

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
#ifndef __IALLOCATOR_HPP__
#define __IALLOCATOR_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NAllocators {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Memory allocator interface.
/*!
    Memory allocator interface contains set of methods which help to allocate,
    create, initialize, delete and destroy type instances. All  those  methods
    can interact both with one type instance and with many ones (array of type
    instances).

    Allocation is the process when only memory for type instance is allocated.
    Note that in allocation process no class constructors are called.

    Creation is the complex process when both allocation  does  and  also  all
    class constructors are called.

    Initialize is the process when uninitialized allocated buffer is used  and
    then class constructors is called on it.

    Destroying is the process when all destructors are called with  no  meomry
    freeing.

    Deleting is the process when all allocated memory frees with  calling  all
    destructors.

    Freeing is the process when all allocated memory frees but no  destructors
    are called.
*/
class BASE_API IAllocator
{
protected:
  //! Default interface protected constructor.
  IAllocator();

  //! Allocate new memory buffer.
  /*!
      Method is used to allocate memory buffer. It should  be  implemented  by
      the concrete memory allocator. This method is only for internal usage.

      \param a_cSize - Size of allocated buffer in bytes.
      \return Pointer to new allocated buffer of NULL if failed.
  */
  virtual Tptr allocate(const Tuint a_cSize) = 0;
  //! Free memory buffer.
  /*!
      Method is used to free memory buffer. It should be  implemented  by  the
      concrete memory allocator. This method is only for internal usage.

      \param a_pPointer - Pointer to buffer.
      \return true  - if the memory buffer was successfully freed. \n
              false - if the memory buffer was not successfully freed. \n
  */
  virtual Tbool free(Tptr a_pPointer) = 0;

public:
  //! Interface virtual destructor.
  virtual ~IAllocator();

  //! Allocate one instance of the given type.
  /*!
      \return Pointer to the allocated instance or NULL if failed.
  */
  template <typename T_Type>
  T_Type* allocateOne();
  //! Allocate many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of allocated instances.
      \return Pointer to the allocated instance or NULL if failed.
  */
  template <typename T_Type>
  T_Type* allocateMany(const Tuint a_cInstanceCount);

  //! Create one instance of the given type.
  /*!
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type>
  T_Type* createOne();
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1>
  T_Type* createOne(const T_Argument1& a_crArgument1);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \param a_crArgument8 - Constant reference to the create argument 8.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \param a_crArgument8 - Constant reference to the create argument 8.
      \param a_crArgument9 - Constant reference to the create argument 9.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9);
  //! Create one instance of the given type.
  /*!
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \param a_crArgument8 - Constant reference to the create argument 8.
      \param a_crArgument9 - Constant reference to the create argument 9.
      \param a_crArgument10 - Constant reference to the create argument 10.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
  T_Type* createOne(const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10);

  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type>
  T_Type* createMany(const Tuint a_cInstanceCount);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \param a_crArgument8 - Constant reference to the create argument 8.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \param a_crArgument8 - Constant reference to the create argument 8.
      \param a_crArgument9 - Constant reference to the create argument 9.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9);
  //! Create many instances of the given type.
  /*!
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the create argument 1.
      \param a_crArgument2 - Constant reference to the create argument 2.
      \param a_crArgument3 - Constant reference to the create argument 3.
      \param a_crArgument4 - Constant reference to the create argument 4.
      \param a_crArgument5 - Constant reference to the create argument 5.
      \param a_crArgument6 - Constant reference to the create argument 6.
      \param a_crArgument7 - Constant reference to the create argument 7.
      \param a_crArgument8 - Constant reference to the create argument 8.
      \param a_crArgument9 - Constant reference to the create argument 9.
      \param a_crArgument10 - Constant reference to the create argument 10.
      \return Pointer to the created instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
  T_Type* createMany(const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10);

  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type>
  T_Type* initializeOne(T_Type* a_pPointer);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \param a_crArgument8 - Constant reference to the initialize argument 8.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \param a_crArgument8 - Constant reference to the initialize argument 8.
      \param a_crArgument9 - Constant reference to the initialize argument 9.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9);
  //! Initialize one instance of the given type.
  /*!
      \param a_pPointer - Pointer to the uninitialized instance.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \param a_crArgument8 - Constant reference to the initialize argument 8.
      \param a_crArgument9 - Constant reference to the initialize argument 9.
      \param a_crArgument10 - Constant reference to the initialize argument 10.
      \return Pointer to the initialized instance or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
  T_Type* initializeOne(T_Type* a_pPointer, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10);

  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \param a_crArgument8 - Constant reference to the initialize argument 8.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \param a_crArgument8 - Constant reference to the initialize argument 8.
      \param a_crArgument9 - Constant reference to the initialize argument 9.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9);
  //! Initialize many instances of the given type.
  /*!
      \param a_pArrayOfPointers - Pointer to the uninitialized array of instances.
      \param a_cInstanceCount - Count of created instances.
      \param a_crArgument1 - Constant reference to the initialize argument 1.
      \param a_crArgument2 - Constant reference to the initialize argument 2.
      \param a_crArgument3 - Constant reference to the initialize argument 3.
      \param a_crArgument4 - Constant reference to the initialize argument 4.
      \param a_crArgument5 - Constant reference to the initialize argument 5.
      \param a_crArgument6 - Constant reference to the initialize argument 6.
      \param a_crArgument7 - Constant reference to the initialize argument 7.
      \param a_crArgument8 - Constant reference to the initialize argument 8.
      \param a_crArgument9 - Constant reference to the initialize argument 9.
      \param a_crArgument10 - Constant reference to the initialize argument 10.
      \return Pointer to the initialized array of instances or NULL if failed.
  */
  template <typename T_Type, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9, typename T_Argument10>
  T_Type* initializeMany(T_Type* a_pArrayOfPointers, const Tuint a_cInstanceCount, const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2, const T_Argument3& a_crArgument3, const T_Argument4& a_crArgument4, const T_Argument5& a_crArgument5, const T_Argument6& a_crArgument6, const T_Argument7& a_crArgument7, const T_Argument8& a_crArgument8, const T_Argument9& a_crArgument9, const T_Argument10& a_crArgument10);

  //! Destroy one pointer.
  /*!
      \param a_prPointer - Reference to the pointer.
      \return true  - if one pointer was destroyed. \n
              false - if one pointer was not destroyed. \n
  */
  template <typename T_Type>
  Tbool destroyOne(T_Type* a_prPointer);
  //! Destroyed many pointers (array of pointers).
  /*!
      \param a_prArrayOfPointers - Reference to the array of pointers.
      \param a_cInstanceCount - Count of destroyed instances.
      \return true  - if many pointers were destroyed. \n
              false - if many pointers were not destroyed. \n
  */
  template <typename T_Type>
  Tbool destroyMany(T_Type* a_prArrayOfPointers, const Tuint a_cInstanceCount);

  //! Delete one pointer.
  /*!
      \param a_prPointer - Reference to the pointer.
      \return true  - if one pointer was deleted. \n
              false - if one pointer was not deleted. \n
  */
  template <typename T_Type>
  Tbool deleteOne(T_Type*& a_prPointer);
  //! Delete many pointers (array of pointers).
  /*!
      \param a_prArrayOfPointers - Reference to the array of pointers.
      \param a_cInstanceCount - Count of deleted instances.
      \return true  - if many pointers were deleted. \n
              false - if many pointers were not deleted. \n
  */
  template <typename T_Type>
  Tbool deleteMany(T_Type*& a_prArrayOfPointers, const Tuint a_cInstanceCount);

  //! Free one pointer.
  /*!
      \param a_prPointer - Reference to the pointer.
      \return true  - if one pointer was freed. \n
              false - if one pointer was not freed. \n
  */
  template <typename T_Type>
  Tbool freeOne(T_Type*& a_prPointer);
  //! Free many pointers (array of pointers).
  /*!
      \param a_prArrayOfPointers - Reference to the array of pointers.
      \param a_cInstanceCount - Count of freed instances.
      \return true  - if many pointers were freed. \n
              false - if many pointers were not freed. \n
  */
  template <typename T_Type>
  Tbool freeMany(T_Type*& a_prArrayOfPointers, const Tuint a_cInstanceCount);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/allocators/IAllocator.inl>
/*==========================================================================*/
#endif
