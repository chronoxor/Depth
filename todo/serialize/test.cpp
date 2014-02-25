/*==========================================================================*/
/*
    FILE DESCRIPTION: True Template

    AUTHOR:    shinkarenko
    GROUP:     The NULL workgroup
    PROJECT:   The project
    PART:      Main
    VERSION:   1.0
    CREATED:   19.12.2006 23:29:48

    EMAIL:     some@mail.net
    WWW:       http://some.net

    COPYRIGHT: (C) 2006 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2006 The NULL workgroup

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
#include <map>
#include <string>
#include <stdio.h>
#include <typeinfo>
/*==========================================================================*/
class AbstractCreator
{
public:
  virtual void* create() = 0;
};
/*==========================================================================*/
std::map<std::string, AbstractCreator*> theMap;
/*==========================================================================*/
struct A { virtual ~A() {}; virtual void test() = 0; };
struct B : public A { void test() { printf("B"); } };
struct C : public A { void test() { printf("C"); } };
/*==========================================================================*/
template <typename T>
T* dojob()
{
  return NULL; // new T()
}
/*==========================================================================*/
template <typename T>
class ObjectCreator : public AbstractCreator
{
public:
  void* create()
  {
    return dojob<T>();
  }
};
/*==========================================================================*/
template <typename T>
void reg(std::string str, T* ptr = NULL)
{
  theMap[str] = new ObjectCreator<T>();
}
/*==========================================================================*/
template <>
C* dojob<C>()
{
  printf("Cool!!!");
  return new C();
}
/*==========================================================================*/
int main(int argc, char* argv[])
{
  reg<A>("A");
  reg<B>("B");
  reg<C>("C");

  A* ptr = (A*)theMap["C"]->create();
  //ptr->test();
  printf("%s \n", typeid(*ptr).name());
  return 0;
}
/*==========================================================================*/
#endif
