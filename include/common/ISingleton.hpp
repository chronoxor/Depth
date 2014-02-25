/*!
 *  \file    ISingleton.hpp Singleton pattern interface. It can be used as a
 *           base class for all singletons objects.
 *  \brief   Singleton pattern interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Singleton pattern interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   04.02.2006 21:36:27

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
#ifndef __ISINGLETON_HPP__
#define __ISINGLETON_HPP__
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
//! Singleton pattern interface.
/*!
    Singleton is a non static class that has only one instance.  To  create  a
    singleton you should inherit you class from ISingleton with self type as a
    template argument. After it you can get reference to  this  instance  with
    'getInstance()' method. Note that you class  constructors  should  not  be
    public to prevent of creating class instances outside of the get  instance
    method.

    The current singleton pattern is not save from Dead Reference problem.  So
    it is non safe to invoke other singletons from any singleton destructors.

    Example:
    \code
    class CTrueSingleton :
      public ISingleton<CTrueSingleton>
    {
      // Friend interface: Base ISingleton interface.
      friend class ISingleton<CTrueSingleton>;

    public:
      void test()
      {
        printf("CTrueSingleton::test()");
      }

    private:
      CTrueSingleton() : ISingleton<CTrueSingleton>()
      {
        // Constructor body...
      }
     ~CTrueSingleton()
      {
        // Destructor body...
      }
    };

    int main(int argc, char* argv[])
    {
      CTrueSingleton::getInstance().test();
      return 0;
    }
    \endcode
*/
template <class T_Class>
class ISingleton
{
public:
  //! ISingleton value template type.
  typedef T_Class TType;

protected:
  //! Default interface protected constructor.
  ISingleton();

public:
  //! Get reference to the current singleton instance.
  /*!
      Method gets current singleton instance and return reference to it.

      \return Reference to the current singleton instance.
  */
  static T_Class& getInstance();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/ISingleton.inl>
/*==========================================================================*/
//! \example example-common-ISingleton.cpp
/*--------------------------------------------------------------------------*/
//! \test test-common-ISingleton.cpp
/*==========================================================================*/
#endif
