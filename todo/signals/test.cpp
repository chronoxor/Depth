/*==========================================================================*/
/*
    FILE DESCRIPTION: True Template

    AUTHOR:    shinkarenko
    GROUP:     The NULL workgroup
    PROJECT:   The project
    PART:      Main
    VERSION:   1.0
    CREATED:   10.07.2007 23:51:02

    EMAIL:     some@mail.net
    WWW:       http://some.net

    COPYRIGHT: (C) 2007 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2007 The NULL workgroup

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __TEST_CPP__
#define __TEST_CPP__
/*==========================================================================*/
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
  friend bool operator == (T_Type* a_pPointer, const Cnull a_cNULL);
  //! Operator: Equal to NULL value (non-member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Non-member pointer of any type.
      \return true  - if the given non-member pointer is equal to NULL. \n
              false - if the given non-member pointer is not equal to NULL. \n
  */
  template<typename T_Type>
  friend bool operator == (const Cnull a_cNULL, T_Type* a_pPointer);
  //! Operator: Equal to NULL value (member pointer version).
  /*!
      \param a_pPointer - Member pointer of any type.
      \param a_cNULL - Constant NULL wrapper instance.
      \return true  - if the given member pointer is equal to NULL. \n
              false - if the given member pointer is not equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend bool operator == (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL);
  //! Operator: Equal to NULL value (member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Member pointer of any type.
      \return true  - if the given member pointer is equal to NULL. \n
              false - if the given member pointer is not equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend bool operator == (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer));

  //! Operator: Not equal to NULL value (non-member pointer version).
  /*!
      \param a_pPointer - Non-member pointer of any type.
      \param a_cNULL - Constant NULL wrapper instance.
      \return true  - if the given non-member pointer is not equal to NULL. \n
              false - if the given non-member pointer is equal to NULL. \n
  */
  template<typename T_Type>
  friend bool operator != (T_Type* a_pPointer, const Cnull a_cNULL);
  //! Operator: Not equal to NULL value (non-member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Non-member pointer of any type.
      \return true  - if the given non-member pointer is not equal to NULL. \n
              false - if the given non-member pointer is equal to NULL. \n
  */
  template<typename T_Type>
  friend bool operator != (const Cnull a_cNULL, T_Type* a_pPointer);
  //! Operator: Not equal to NULL value (member pointer version).
  /*!
      \param a_pPointer - Member pointer of any type.
      \param a_cNULL - Constant NULL wrapper instance.
      \return true  - if the given member pointer is not equal to NULL. \n
              false - if the given member pointer is equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend bool operator != (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL);
  //! Operator: Not equal to NULL value (member pointer version).
  /*!
      \param a_cNULL - Constant NULL wrapper instance.
      \param a_pPointer - Member pointer of any type.
      \return true  - if the given member pointer is not equal to NULL. \n
              false - if the given member pointer is equal to NULL. \n
  */
  template<class T_Class, typename T_Type>
  friend bool operator != (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer));

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
/*==========================================================================*/
inline Cnull::Cnull()
{

}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline bool operator == (T_Type* a_pPointer, const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer == 0);
}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline bool operator == (const Cnull a_cNULL, T_Type* a_pPointer)
{
  (void)a_cNULL;

  return (0 == a_pPointer);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline bool operator == (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer == 0);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline bool operator == (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer))
{
  (void)a_cNULL;

  return (0 == a_pPointer);
}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline bool operator != (T_Type* a_pPointer, const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer != 0);
}
/*--------------------------------------------------------------------------*/
template<typename T_Type>
inline bool operator != (const Cnull a_cNULL, T_Type* a_pPointer)
{
  (void)a_cNULL;

  return (0 != a_pPointer);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline bool operator != (T_Type (T_Class::*a_pPointer), const Cnull a_cNULL)
{
  (void)a_cNULL;

  return (a_pPointer != 0);
}
/*--------------------------------------------------------------------------*/
template<class T_Class, typename T_Type>
inline bool operator != (const Cnull a_cNULL, T_Type (T_Class::*a_pPointer))
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
/*==========================================================================*/
class A
{
public:
  int test(int)
  {
    return 0;
  }
};
/*==========================================================================*/
int main(int argc, char* argv[])
{
  void (*t1)() = NULL;
  int (A::*t2)(int) = NULL;

  return ((t1 == NULL)||(t2 == NULL)) ? 0 : 1;
}
/*==========================================================================*/
#endif
