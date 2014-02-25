/*!
 *  \file    ISharedLibrary.hpp Shared library interface provides OS
 *           independent functionality to handle shared libraries
 *           load/unload procedures.
 *  \brief   Shared library interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Shared library interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Shared library interface
    VERSION:   1.0
    CREATED:   02.05.2008 22:27:48

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
#ifndef __ISHAREDLIBRARY_HPP__
#define __ISHAREDLIBRARY_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NShared {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Shared library interface.
/*!
    Shared library interface unifies handling of the load/unload procedure for
    shared libraries under different platforms.

    To define shared library in user code simple inherit your class  from  the
    ISharedLibrary interface, overload onLoad()/onUnload() methods if you want
    to handle corresponding processes.

    Example:
    \code
    // Define unified shared library in user code.
    class CMyLibrary :
      public NShared::ISharedLibrary
    {
      // Handle load process of the shared library.
      virtual Tbool onLoad()
      {
        ...
        return true;
      }

      // Handle unload process of the shared library.
      virtual Tbool onUnload()
      {
        ...
        return true;
      }
    };
    \endcode

    Finally you should create 'shared.hpp' file with the following content and
    add its path to the additional directories settings of the compiler:

    \code
    // Define name of the shared library.
    #define SHARED_LIBRARY_NAME MyLibrary
    // Define full class name of the shared library (including namespace).
    #define SHARED_LIBRARY_CLASS CMyLibrary
    // Include the header file of the shared library.
    #include "include/CMyLibrary.hpp"
    \endcode
*/
class BASE_API ISharedLibrary
{
protected:
  //! Default interface protected constructor.
  ISharedLibrary();

public:
  //! Interface virtual destructor.
  virtual ~ISharedLibrary();

  //! Handle load process of the shared library.
  /*!
      Method is called from the system automatically when the  current  shared
      library is loading to the system. Overloading of the  function  manually
      handles shared library load behavior. Overloaded  method  should  return
      'true' on success. If the method returns 'false' loading of  the  shared
      library is finished unsuccessfully and the execution process terminates.

      \return true  - if the current shared library was loaded successfully. \n
              false - if the current shared library was not loaded successfully. \n
  */
  virtual Tbool onLoad();
  //! Handle unload process of the shared library.
  /*!
      Method is called from the system automatically when the  current  shared
      library is unloading to the system. Overloading of the function manually
      handles shared library unload behavior. Overloaded method should  return
      'true' on success. If the method returns 'false' unloading of the shared
      library is finished unsuccessfully and the execution process terminates.

      \return true  - if the current shared library was unloaded successfully. \n
              false - if the current shared library was not unloaded successfully. \n
  */
  virtual Tbool onUnload();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/shared/ISharedLibrary.inl>
/*==========================================================================*/
#endif
