/*!
 *  \file    concept.hpp Contains checking conception definitions for the
 *           Depth project.
 *  \brief   Checking conception definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Checking conception definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template argument checking conception
    VERSION:   1.0
    CREATED:   15.01.2007 20:07:36

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
#ifndef __CONCEPT_HPP__
#define __CONCEPT_HPP__
/*==========================================================================*/
#include <Depth/include/concept/details/MIgnoreUnusedHelper.hpp>
/*==========================================================================*/
/* CONCEPT MACRO DECLARATIONS                                               */
/*==========================================================================*/
/*!
    \def IGNORE_UNUSED(variable)
    Defines ignore unused variable macros. It helps  to  remove  the  compiler
    warning about declaring unused variable \a variable.

    Example:
    \code
    void function(Tuint unused)
    {
      IGNORE_UNUSED(unused);
      ...
      Tuint another_unused;
      ...
      IGNORE_UNUSED(another_unused);
    }
    \endcode
*/
#define IGNORE_UNUSED(variable) NDepth::NConcept::NDetails::MIgnoreUnusedHelper::ignoreUnusedVariableWarning(variable)
/*==========================================================================*/
#endif
