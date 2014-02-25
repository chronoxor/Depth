/*!
 *  \file    NULL.inl NULL pointer wrapper which solves the problem of the
 *           overloading pointer-integer function arguments.
 *  \brief   NULL pointer wrapper (inline).
 *  \author  Scott Meyers (smeyers@aristeia.com)
 *  \version 1.0
 *  \date    16.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: NULL pointer wrapper (inline).

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
#ifndef __NULL_INL__
#define __NULL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
#if defined(SYS_SUPPORT_CNULL)
/*--------------------------------------------------------------------------*/
inline Cnull::Cnull()
{

}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline NTypes::Tbool operator == (T_Type* a_pPointer, const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer == 0);
}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline NTypes::Tbool operator == (const Cnull a_cNULL, T_Type* a_pPointer)
{
  (void)a_cNULL;

  return (0 == a_pPointer);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline NTypes::Tbool operator == (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer == 0);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline NTypes::Tbool operator == (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer))
{
  (void)a_cNULL;

  return (0 == a_pPointer);
}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline NTypes::Tbool operator != (T_Type* a_pPointer, const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer != 0);
}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline NTypes::Tbool operator != (const Cnull a_cNULL, T_Type* a_pPointer)
{
  (void)a_cNULL;

  return (0 != a_pPointer);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline NTypes::Tbool operator != (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer != 0);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline NTypes::Tbool operator != (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer))
{
  (void)a_cNULL;

  return (0 != a_pPointer);
}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline Cnull::operator T_Type* () const
{
  return 0;
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline Cnull::operator T_Type T_Class::* () const
{
  return 0;
}
/*--------------------------------------------------------------------------*/
inline void Cnull::operator& () const
{

}
/*--------------------------------------------------------------------------*/
#endif
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
