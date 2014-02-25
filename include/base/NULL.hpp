/*!
 *  \file    NULL.hpp NULL pointer wrapper which solves the problem of the
 *           overloading pointer-integer function arguments.
 *  \brief   NULL pointer wrapper.
 *  \author  Scott Meyers (smeyers@aristeia.com)
 *  \version 1.0
 *  \date    16.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: NULL pointer wrapper.

    AUTHOR:    Scott Meyers (smeyers@aristeia.com)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   16.01.2007 20:21:47

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
#ifndef __NULL_HPP__
#define __NULL_HPP__
/*==========================================================================*/
#include <Depth/include/types.hpp>
#include <Depth/include/macros.hpp>
/*==========================================================================*/
// Remove obsolete NULL declaration.
#if defined(NULL)
  #undef NULL
#endif
/*==========================================================================*/
/* MACRO DECLARATIONS                                                       */
/*==========================================================================*/
/*!
    \def NULL
    Defines NULL pointer value for  compilers  that  does  not  support  fully
    functional class NULL pointer operations.
*/
#ifndef SYS_SUPPORT_CNULL
  #if defined(__cplusplus)
    #define NULL 0
  #else
    #define NULL ((void*)0)
  #endif
#endif
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
#ifdef SYS_SUPPORT_CNULL
/*--------------------------------------------------------------------------*/
//! NULL pointer wrapper.
/*!
    The NULL pointer wrapper is a NULL value that that would convert  only  to
    pointer types. If it is used as a overloaded  function  argument  it  will
    invoke function with pointer type argument instead of integer number one.

    Example:
    \code
    void f(int);
    void f(int*);

    void test()
    {
      // Overloaded function with pointer argument will be invoked!
      f(NULL);
    }
    \endcode
*/
const class Cnull
{
public:
  //! Default constructor.
  Cnull();

  //! Operator: Equal to NULL value (non-member pointer version).
  /*!
      \param a_pPointer - Non-member pointer of any type.
      \param a_cNULL - Constant NULL wrapper instance.
      \return true  - if the given non-member pointer is equal to NULL. \n
              false - if the given non-member pointer is not equal to NULL. \n
  */
  template<typename T_Type>
  friend NTypes::Tbool operator == (T_Type* a_pPointer, const Cnull a_cNULL);
  //! Operator: Equal to NULL value (non-member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Non-member pointer of any type.
      \return true  - if the given non-member pointer is equal to NULL. \n
              false - if the given non-member pointer is not equal to NULL. \n
  */
  template<typename T_Type>
  friend NTypes::Tbool operator == (const Cnull a_cNULL, T_Type* a_pPointer);
  //! Operator: Equal to NULL value (member pointer version).
  /*!
      \param a_pPointer - Member pointer of any type.
      \param a_cNULL - Constant NULL wrapper instance.
      \return true  - if the given member pointer is equal to NULL. \n
              false - if the given member pointer is not equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend NTypes::Tbool operator == (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL);
  //! Operator: Equal to NULL value (member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Member pointer of any type.
      \return true  - if the given member pointer is equal to NULL. \n
              false - if the given member pointer is not equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend NTypes::Tbool operator == (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer));

  //! Operator: Not equal to NULL value (non-member pointer version).
  /*!
      \param a_pPointer - Non-member pointer of any type.
      \param a_cNULL - Constant NULL wrapper instance.
      \return true  - if the given non-member pointer is not equal to NULL. \n
              false - if the given non-member pointer is equal to NULL. \n
  */
  template<typename T_Type>
  friend NTypes::Tbool operator != (T_Type* a_pPointer, const Cnull a_cNULL);
  //! Operator: Not equal to NULL value (non-member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Non-member pointer of any type.
      \return true  - if the given non-member pointer is not equal to NULL. \n
              false - if the given non-member pointer is equal to NULL. \n
  */
  template<typename T_Type>
  friend NTypes::Tbool operator != (const Cnull a_cNULL, T_Type* a_pPointer);
  //! Operator: Not equal to NULL value (member pointer version).
  /*!
      \param a_pPointer - Member pointer of any type.
      \param a_cNULL - Constant NULL wrapper instance.
      \return true  - if the given member pointer is not equal to NULL. \n
              false - if the given member pointer is equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend NTypes::Tbool operator != (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL);
  //! Operator: Not equal to NULL value (member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Member pointer of any type.
      \return true  - if the given member pointer is not equal to NULL. \n
              false - if the given member pointer is equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend NTypes::Tbool operator != (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer));

  //! Operator: Convert to any type of NULL non-member pointer.
  /*!
      Method converts class instance  to  the  any  type  of  NULL  non-member
      pointer and returns NULL value.

      \return NULL non-member pointer.
  */
  template<typename T_Type>
  operator T_Type* () const;
  //! Operator: Convert to any type of NULL member pointer.
  /*!
      Method converts class instance to the any type of  NULL  member  pointer
      and returns NULL value.

      \return NULL member pointer.
  */
  template<class T_Class, typename T_Type>
  operator T_Type T_Class::* () const;

private:
  //! Operator: Deny access to the address of the NULL class instance.
  void operator& () const;
} NULL;
/*--------------------------------------------------------------------------*/
#endif
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/NULL.inl>
/*==========================================================================*/
#endif
