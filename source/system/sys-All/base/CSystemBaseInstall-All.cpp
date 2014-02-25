/*!
 *  \file    CSystemBaseInstall-All.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - All OS - install methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - All OS - install methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   07.01.2006 01:33:12

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMBASEINSTALL_ALL_CPP__
#define __CSYSTEMBASEINSTALL_ALL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API Tbool CSystemBase::ms_InstallFlag = false;
BASE_API NProcess::CRWLock CSystemBase::ms_Locker = NProcess::CRWLock(true);
BASE_API NProcess::CCriticalSection CSystemBase::ms_StdErrorLocker = NProcess::CCriticalSection(true);
BASE_API NProcess::CCriticalSection CSystemBase::ms_StdInputLocker = NProcess::CCriticalSection(true);
BASE_API NProcess::CCriticalSection CSystemBase::ms_StdOutputLocker = NProcess::CCriticalSection(true);
BASE_API Tsint64 CSystemBase::ms_ProcessTimeStamp = 0;
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::install()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemBase::ms_Locker);

  if (!CSystemBase::ms_InstallFlag)
  {
    // Install start process time stamp.
    CSystemBase::ms_ProcessTimeStamp = CSystemBase::getSystemTimeStamp();

    // Install system string encoding.
    if (!installSystemEncoding())
      return false;

    CSystemBase::ms_InstallFlag = true;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::uninstall()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemBase::ms_Locker);

  if (CSystemBase::ms_InstallFlag)
  {
    // Uninstall system string encoding.
    if (!uninstallSystemEncoding())
      return false;

    CSystemBase::ms_InstallFlag = false;
    return true;
  }
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
