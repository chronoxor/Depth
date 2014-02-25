/*!
 *  \file    CSystemTokenizerInstall-All.cpp Tokenizer system class contains
 *           system dependant tokenizer functionality.
 *  \brief   Tokenizer system class - All OS - install methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer system class - All OS - install methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   20.04.2009 02:44:20

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
#include <Depth/include/tokenizer.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/system/CSystemTokenizer.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMTOKENIZERINSTALL_ALL_CPP__
#define __CSYSTEMTOKENIZERINSTALL_ALL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
TOKENIZER_API Tbool CSystemTokenizer::ms_InstallFlag = false;
TOKENIZER_API NProcess::CRWLock CSystemTokenizer::ms_Locker = NProcess::CRWLock(true);
/*--------------------------------------------------------------------------*/
Tbool CSystemTokenizer::install()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemTokenizer::ms_Locker);

  if (!CSystemTokenizer::ms_InstallFlag)
  {
    CSystemTokenizer::ms_InstallFlag = true;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemTokenizer::uninstall()
{ CALL
  NProcess::CScopeWriter wlocker(CSystemTokenizer::ms_Locker);

  if (CSystemTokenizer::ms_InstallFlag)
  {
    CSystemTokenizer::ms_InstallFlag = false;
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
