/*!
 *  \file    CSystemStatisticInstall-All.cpp Statistic system class contains
 *           system dependant statistic functionality.
 *  \brief   Statistic system class - All OS - install methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Statistic system class - All OS - install methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   04.03.2009 03:53:59

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
#include <Depth/include/statistic.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/system/CSystemStatistic.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMSTATISTICINSTALL_ALL_CPP__
#define __CSYSTEMSTATISTICINSTALL_ALL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
STATISTIC_API Tbool CSystemStatistic::ms_InstallFlag = false;
STATISTIC_API NProcess::CRWLock CSystemStatistic::ms_Locker = NProcess::CRWLock(true);
/*--------------------------------------------------------------------------*/
Tbool CSystemStatistic::install()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemStatistic::ms_Locker);

  if (!CSystemStatistic::ms_InstallFlag)
  {
    CSystemStatistic::ms_InstallFlag = true;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStatistic::uninstall()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemStatistic::ms_Locker);

  if (CSystemStatistic::ms_InstallFlag)
  {
    CSystemStatistic::ms_InstallFlag = false;
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
