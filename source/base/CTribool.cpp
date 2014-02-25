/*!
 *  \file    CTribool.cpp Three state boolean logic class. It represents all
 *           operations with 3-state boolean logic values.
 *  \brief   Three state boolean logic class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Three state boolean logic class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   01.02.2006 02:42:24

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
#include <Depth/include/base/CTribool.hpp>
/*==========================================================================*/
#ifndef __CTRIBOOL_CPP__
#define __CTRIBOOL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTribool::ETriboolState CTribool::getEqual(const ETriboolState a_cValue1, const ETriboolState a_cValue2)
{ CALL
  if ((a_cValue1 == CTribool::e_NULL) || (a_cValue2 == CTribool::e_NULL))
    return CTribool::e_NULL;
  else if (((a_cValue1 == CTribool::e_TRUE) && (a_cValue2 == CTribool::e_TRUE)) || ((a_cValue1 == CTribool::e_FALSE) && (a_cValue2 == CTribool::e_FALSE)))
    return CTribool::e_TRUE;
  else
    return CTribool::e_NULL;
}
/*--------------------------------------------------------------------------*/
CTribool::ETriboolState CTribool::getNotEqual(const ETriboolState a_cValue1, const ETriboolState a_cValue2)
{ CALL
  if ((a_cValue1 == CTribool::e_NULL) || (a_cValue2 == CTribool::e_NULL))
    return CTribool::e_NULL;
  else if (((a_cValue1 != CTribool::e_TRUE) || (a_cValue2 != CTribool::e_TRUE)) && ((a_cValue1 != CTribool::e_FALSE) || (a_cValue2 != CTribool::e_FALSE)))
    return CTribool::e_TRUE;
  else
    return CTribool::e_NULL;
}
/*--------------------------------------------------------------------------*/
CTribool::ETriboolState CTribool::getNot(const ETriboolState a_cValue)
{ CALL
  return ((a_cValue == CTribool::e_TRUE) ? CTribool::e_FALSE : ((a_cValue == CTribool::e_FALSE) ? CTribool::e_TRUE : CTribool::e_NULL));
}
/*--------------------------------------------------------------------------*/
CTribool::ETriboolState CTribool::getConjuction(const ETriboolState a_cValue1, const ETriboolState a_cValue2)
{ CALL
  if ((a_cValue1 == CTribool::e_FALSE) || (a_cValue2 == CTribool::e_FALSE))
    return CTribool::e_FALSE;
  else if ((a_cValue1 == CTribool::e_TRUE) && (a_cValue2 == CTribool::e_TRUE))
    return CTribool::e_TRUE;
  else
    return CTribool::e_NULL;
}
/*--------------------------------------------------------------------------*/
CTribool::ETriboolState CTribool::getDisjunction(const ETriboolState a_cValue1, const ETriboolState a_cValue2)
{ CALL
  if ((a_cValue1 == CTribool::e_FALSE) && (a_cValue2 == CTribool::e_FALSE))
    return CTribool::e_FALSE;
  else if ((a_cValue1 == CTribool::e_TRUE) || (a_cValue2 == CTribool::e_TRUE))
    return CTribool::e_TRUE;
  else
    return CTribool::e_NULL;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
