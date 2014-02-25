/*!
 *  \file    IClonable.hpp Interface for all classes that wants to have
 *           virtual constructor.
 *  \brief   Clonable interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Clonable interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   18.01.2006 22:23:25

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
#ifndef __ICLONABLE_HPP__
#define __ICLONABLE_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Clonable interface.
/*!
    Sometimes is very useful to have virtual constructors. For example, if  we
    have valid pointer to some interface, but we do not know anything about it
    implementation and we want to create another copy of such  implementation,
    then we should have virtual constructor. Clonable interface  helps  us  by
    declaring 'clone' method. This method returns pointer to a new instance of
    IClonable template argument class, which then can be cast to class we need
    (or to NULL if failed).

    Example:
    \code
    class CBase :
      public NCommon::IClonable<CBase>
    {

    };

    class CDerived1 :
      public CBase
    {
      CBase* clone() const
      {
        return new CDerived1();
      }
    };

    class CDerived2 :
      public CBase
    {
      CBase* clone() const
      {
        return new CDerived2();
      }
    };

    int main(int argc, char* argv[])
    {
      CBase* base_ptr = new CDerived2();
      CBase* base_clon_ptr = base_ptr->clone();

      if (dynamic_cast<CDerived1*>(base_clon_ptr) != NULL)
      {
        printf("CDerived1 clone!");
        return 0;
      }

      if (dynamic_cast<CDerived2*>(base_clon_ptr) != NULL)
      {
        printf("CDerived2 clone!");
        return 0;
      }

      printf("Unknown clone!");
      return -1;
    }
    \endcode
*/
template <class T_Class>
class IClonable
{
public:
  //! IClonable value template type.
  typedef T_Class TType;

protected:
  //! Default interface protected constructor.
  IClonable();

public:
  //! Interface virtual destructor.
  virtual ~IClonable();

  //! Clone method.
  /*!
      Method clones current object  and  return  pointer  to  the  new  object
      instance, taking into account object type.

      \return Pointer to clone of the object with exact type.
  */
  virtual T_Class* clone() const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/IClonable.inl>
/*==========================================================================*/
//! \example example-common-IClonable.cpp
/*--------------------------------------------------------------------------*/
//! \test test-common-IClonable.cpp
/*==========================================================================*/
#endif
