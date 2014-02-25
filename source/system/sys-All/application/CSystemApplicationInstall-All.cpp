/*!
 *  \file    CSystemApplicationInstall-All.cpp Application system class
 *           contains system dependant application functionality.
 *  \brief   Application system class - All OS - install methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Application system class - All OS - install methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   10.01.2009 21:30:15

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
#include <Depth/include/application.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/system/CSystemApplication.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMAPPLICATIONINSTALL_ALL_CPP__
#define __CSYSTEMAPPLICATIONINSTALL_ALL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
APPLICATION_API Tbool CSystemApplication::ms_InstallFlag = false;
APPLICATION_API NProcess::CRWLock CSystemApplication::ms_Locker = NProcess::CRWLock(true);
/*--------------------------------------------------------------------------*/
Tbool CSystemApplication::install()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemApplication::ms_Locker);

  if (!CSystemApplication::ms_InstallFlag)
  {
    CSystemApplication::ms_InstallFlag = true;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemApplication::uninstall()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemApplication::ms_Locker);

  if (CSystemApplication::ms_InstallFlag)
  {
    CSystemApplication::ms_InstallFlag = false;
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
