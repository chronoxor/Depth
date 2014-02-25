/*!
 *  \file    CCallFrameContext.cpp Call stack frame context wrapper class is
 *           used to manage the call stack of the current thread.
 *  \brief   Call stack frame context wrapper class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Call stack frame context wrapper class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Debugging details
    VERSION:   1.0
    CREATED:   30.12.2006 22:19:42

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
/*==========================================================================*/
#ifndef __CCALLFRAMECONTEXT_CPP__
#define __CCALLFRAMECONTEXT_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NDebug {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CCallFrameContext::CCallFrameContext(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine)
{
  /*!
      \todo Implement CCallFrameContext constructor.
  */
  (void)a_cpFunctionSignature;
  (void)a_cpFileName;
  (void)a_cLine;
}
/*--------------------------------------------------------------------------*/
CCallFrameContext::~CCallFrameContext()
{
  /*!
      \todo Implement CCallFrameContext destructor.
  */
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
