/*!
 *  \file    CSystemRandomInstall-All.cpp Random numbers system class contains
 *           system dependant random functionality.
 *  \brief   Random numbers system class - All OS - install methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Random numbers system class - All OS - install methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   24.02.2009 23:49:47

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
#include <Depth/include/random.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/system/CSystemRandom.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMRANDOMINSTALL_ALL_CPP__
#define __CSYSTEMRANDOMINSTALL_ALL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
RANDOM_API Tbool CSystemRandom::ms_InstallFlag = false;
RANDOM_API NProcess::CRWLock CSystemRandom::ms_Locker = NProcess::CRWLock(true);
/*--------------------------------------------------------------------------*/
Tbool CSystemRandom::install()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemRandom::ms_Locker);

  if (!CSystemRandom::ms_InstallFlag)
  {
    CSystemRandom::ms_InstallFlag = true;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemRandom::uninstall()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemRandom::ms_Locker);

  if (CSystemRandom::ms_InstallFlag)
  {
    CSystemRandom::ms_InstallFlag = false;
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
