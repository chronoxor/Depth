/*!
 *  \file    FWarning.cpp Helper function that invokes warning handler.
 *  \brief   Warning helper function (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Warning helper function (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Errors handling details
    VERSION:   1.0
    CREATED:   29.12.2006 02:16:25

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
#undef FILE
#include <cstdio>
#define FILE STR(SYS_FILE)
/*==========================================================================*/
#ifndef __FWARNING_CPP__
#define __FWARNING_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NErrors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION IMPLEMENTATIONS                                                 */
/*==========================================================================*/
BASE_API void warning(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcstr a_cpMessage, ...)
{ CALL
  /*!
      \todo Implement warning helper function.
  */
  IGNORE_UNUSED(a_cpFunctionSignature);
  IGNORE_UNUSED(a_cpFileName);
  IGNORE_UNUSED(a_cLine);
  IGNORE_UNUSED(a_cpMessage);
  printf("warning\n");
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
