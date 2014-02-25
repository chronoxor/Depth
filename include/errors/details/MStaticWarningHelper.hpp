/*!
 *  \file    MStaticWarningHelper.hpp Helper meta-class that helps to implement
 *           static warning construction.
 *  \brief   Static warning helper meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static warning helper meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Warnings handling details
    VERSION:   1.0
    CREATED:   31.07.2006 01:13:28

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
#ifndef __MSTATICWARNINGHELPER_HPP__
#define __MSTATICWARNINGHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NErrors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
/*!
    \def STATIC_WARNING_HELPER(message, line)
    Static warning helper. It  use  the  following  rule  to  generate  static
    warning: deleting of incomplete structure leads to compile-time warning.
*/
#define STATIC_WARNING_HELPER(message, line)                                 \
class JOIN(MStaticWarningHelper, line)                                       \
{                                                                            \
  struct WARNING;                                                            \
                                                                             \
  JOIN(MStaticWarningHelper, line)() :                                       \
    m_pWarning(NULL),                                                        \
    m_MessageSize(sizeof(message))                                           \
  { CALL                                                                     \
    delete m_pWarning;                                                       \
  }                                                                          \
                                                                             \
  WARNING* m_pWarning;                                                       \
  Tuint m_MessageSize;                                                       \
};                                                                           \
typedef JOIN(MStaticWarningHelper, line) JOIN(TStaticWarning, line);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
