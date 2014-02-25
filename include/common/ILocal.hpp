/*!
 *  \file    ILocal.hpp Interface for all local defined variables. If class
 *           does not want to be created dynamically.
 *  \brief   Local interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Local interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   18.01.2006 22:58:34

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
#ifndef __ILOCAL_HPP__
#define __ILOCAL_HPP__
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
//! Local interface.
/*!
    If class has memory allocation operators in his body and they  are  inside
    private visibility scope, then this class cannot  be  created  dynamically
    outside its body.
*/
class BASE_API ILocal
{
protected:
  //! Default interface protected constructor.
  ILocal();

private:
  //! Operator: Content buffer with one obect from this class.
  /*!
      \param a_cSize - Size of buffer.
      \param a_pPointer - Pointer to the buffer.
      \return Pointer to contented buffer.
  */
  Tptr operator new (const Tuint a_cSize, Tptr a_pPointer);
  //! Operator: Content buffer with many obect from this class.
  /*!
      \param a_cSize - Size of buffer.
      \param a_pPointer - Pointer to the buffer.
      \return Pointer to contented buffer.
  */
  Tptr operator new[] (const Tuint a_cSize, Tptr a_pPointer);
  //! Operator: Allocate buffer for one obect from this class.
  /*!
      \param a_cSize - Size of allocated buffer.
      \return Pointer to allocated buffer.
  */
  Tptr operator new (const Tuint a_cSize);
  //! Operator: Allocate buffer for many obects from this class.
  /*!
      \param a_cSize - Size of allocated buffer.
      \return Pointer to allocated buffer.
  */
  Tptr operator new[] (const Tuint a_cSize);
  //! Operator: Allocate buffer for one obect from this class (with additional information).
  /*!
      \param a_cSize - Size of allocated buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation.
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to allocated buffer.
  */
  Tptr operator new (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);
  //! Operator: Allocate buffer for many obect from this class (with additional information).
  /*!
      \param a_cSize - Size of allocated buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation.
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to allocated buffer.
  */
  Tptr operator new[] (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);

public:
  //! Operator: Content buffer with one object opponent delete operator.
  /*!
      \param a_pPointer1 - Pointer to the buffer.
      \param a_pPointer2 - Pointer to the buffer.
  */
  void operator delete (Tptr a_pPointer1, Tptr a_pPointer2);
  //! Operator: Content buffer with many objects opponent delete operator.
  /*!
      \param a_pPointer1 - Pointer to the buffer.
      \param a_pPointer2 - Pointer to the buffer.
  */
  void operator delete[] (Tptr a_pPointer1, Tptr a_pPointer2);
  //! Operator: Release buffer from one object.
  /*!
      \param a_pPointer - Pointer to the buffer.
  */
  void operator delete (Tptr a_pPointer);
  //! Operator: Release buffer from many object.
  /*!
      \param a_pPointer - Pointer to the buffer.
  */
  void operator delete[] (Tptr a_pPointer);
  //! Operator: Release buffer from one object (with additional information).
  /*!
      \param a_pPointer - Pointer to the buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory releasing.
      \param a_cpFileName - File name, from where was initiated memory releasing.
      \param a_cLine - Line in file, from where was initiated memory releasing.
  */
  void operator delete (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine);
  //! Operator: Release buffer from many objects (with additional information).
  /*!
      \param a_pPointer - Pointer to the buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory releasing.
      \param a_cpFileName - File name, from where was initiated memory releasing.
      \param a_cLine - Line in file, from where was initiated memory releasing.
  */
  void operator delete[] (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine);
};
/*--------------------------------------------------------------------------*/
//! Local interface (except its derived classes).
/*!
    If class has memory allocation operators in his body and they  are  inside
    protected visibility scope, then this class cannot  be created dynamically
    outside its body or its derived classes body.
*/
class BASE_API ILocalBase
{
protected:
  //! Default interface protected constructor.
  ILocalBase();

protected:
  //! Operator: Content buffer with one obect from this class.
  /*!
      \param a_cSize - Size of buffer.
      \param a_pPointer - Pointer to the buffer.
      \return Pointer to contented buffer.
  */
  Tptr operator new (const Tuint a_cSize, Tptr a_pPointer);
  //! Operator: Content buffer with many obect from this class.
  /*!
      \param a_cSize - Size of buffer.
      \param a_pPointer - Pointer to the buffer.
      \return Pointer to contented buffer.
  */
  Tptr operator new[] (const Tuint a_cSize, Tptr a_pPointer);
  //! Operator: Allocate buffer for one obect from this class.
  /*!
      \param a_cSize - Size of allocated buffer.
      \return Pointer to allocated buffer.
  */
  Tptr operator new (const Tuint a_cSize);
  //! Operator: Allocate buffer for many obects from this class.
  /*!
      \param a_cSize - Size of allocated buffer.
      \return Pointer to allocated buffer.
  */
  Tptr operator new[] (const Tuint a_cSize);
  //! Operator: Allocate buffer for one obect from this class (with additional information).
  /*!
      \param a_cSize - Size of allocated buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation.
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to allocated buffer.
  */
  Tptr operator new (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);
  //! Operator: Allocate buffer for many obect from this class (with additional information).
  /*!
      \param a_cSize - Size of allocated buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory allocation.
      \param a_cpFileName - File name, from where was initiated memory allocation (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory allocation (default is 0).
      \return Pointer to allocated buffer.
  */
  Tptr operator new[] (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName = STR(""), const Tuint a_cLine = 0);

public:
  //! Operator: Content buffer with one object opponent delete operator.
  /*!
      \param a_pPointer1 - Pointer to the buffer.
      \param a_pPointer2 - Pointer to the buffer.
  */
  void operator delete (Tptr a_pPointer1, Tptr a_pPointer2);
  //! Operator: Content buffer with many objects opponent delete operator.
  /*!
      \param a_pPointer1 - Pointer to the buffer.
      \param a_pPointer2 - Pointer to the buffer.
  */
  void operator delete[] (Tptr a_pPointer1, Tptr a_pPointer2);
  //! Operator: Release buffer from one object.
  /*!
      \param a_pPointer - Pointer to the buffer.
  */
  void operator delete (Tptr a_pPointer);
  //! Operator: Release buffer from many object.
  /*!
      \param a_pPointer - Pointer to the buffer.
  */
  void operator delete[] (Tptr a_pPointer);
  //! Operator: Release buffer from one object (with additional information).
  /*!
      \param a_pPointer - Pointer to the buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory releasing.
      \param a_cpFileName - File name, from where was initiated memory releasing.
      \param a_cLine - Line in file, from where was initiated memory releasing.
  */
  void operator delete (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine);
  //! Operator: Release buffer from many objects (with additional information).
  /*!
      \param a_pPointer - Pointer to the buffer.
      \param a_cpFunctionSignature - Function signature name, from where was initiated memory releasing (default is ASC("")).
      \param a_cpFileName - File name, from where was initiated memory releasing (default is STR("")).
      \param a_cLine - Line in file, from where was initiated memory releasing (default is 0).
  */
  void operator delete[] (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/ILocal.inl>
/*==========================================================================*/
//! \example example-common-ILocal.cpp
/*==========================================================================*/
#endif
