/*!
 *  \file    CStreamDebugger.cpp Debugger stream class gives ability to write
 *           buffer into the system debugger stream.
 *  \brief   Debugger stream class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Debugger stream class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   01.09.2008 01:52:10

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
#include <Depth/include/stream/CStreamDebugger.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CSTREAMDEBUGGER_CPP__
#define __CSTREAMDEBUGGER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CStreamDebugger::set(const CStreamDebugger& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CStreamDebugger class instance."))
  {
    return false;
  }

  // Close opened debugger stream.
  if (isOpened())
    if (!close())
      return false;

  // Initialize base writer interface.
  return IWriter::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamDebugger::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::debuggerWriteBinary(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamDebugger::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::debuggerWriteText(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tuint CStreamDebugger::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::debuggerWriteText(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CStreamDebugger::onFlush()
{ CALL
  return NSystem::CSystemBase::debuggerFlush();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
