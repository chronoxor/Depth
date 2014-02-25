/*!
 *  \file    CStreamStdError.cpp Standard error stream class gives ability to
 *           write buffer into the 'stderr' system stream.
 *  \brief   Standard error stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Standard error stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   25.08.2008 21:08:00

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/CStreamStdError.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CSTREAMSTDERROR_CPP__
#define __CSTREAMSTDERROR_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CStreamStdError::set(const CStreamStdError& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamStdError class instance."))
  {
    return false;
  }

  // Close opened standard error stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize base writer interface.
  return IWriter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStdError::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::stdErrorWriteBinary(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStdError::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::stdErrorWriteText(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStdError::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::stdErrorWriteText(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStdError::onFlush()
{ CALL
  return NSystem::CSystemBase::stdErrorFlush();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
