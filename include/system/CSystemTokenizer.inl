/*!
 *  \file    CSystemTokenizer.inl Tokenizer system class contains system
 *           dependant tokenizer functionality.
 *  \brief   Tokenizer system class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer system class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   20.04.2009 02:46:10

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
#ifndef __CSYSTEMTOKENIZER_INL__
#define __CSYSTEMTOKENIZER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline Tbool CSystemTokenizer::isInstalled()
{ CALL
  NProcess::CScopeReader rlocker(CSystemTokenizer::ms_Locker);

  return CSystemTokenizer::ms_InstallFlag;
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemTokenizer::onLoad()
{ CALL
  return CSystemTokenizer::install();
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemTokenizer::onUnload()
{ CALL
  return CSystemTokenizer::uninstall();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
