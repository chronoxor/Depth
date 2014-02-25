/*!
 *  \file    CStreamStdOutput.cpp Standard output stream class gives ability
 *           to write buffer into the 'stdout' system stream.
 *  \brief   Standard output stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Standard output stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   25.08.2008 21:27:26

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
#include <Depth/include/stream/CStreamStdOutput.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CSTREAMSTDOUTPUT_CPP__
#define __CSTREAMSTDOUTPUT_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CStreamStdOutput::set(const CStreamStdOutput& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamStdOutput class instance."))
  {
    return false;
  }

  // Close opened output stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize base writer interface.
  return IWriter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStdOutput::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::stdOutputWriteBinary(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStdOutput::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::stdOutputWriteText(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamStdOutput::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::stdOutputWriteText(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamStdOutput::onFlush()
{ CALL
  return NSystem::CSystemBase::stdOutputFlush();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
