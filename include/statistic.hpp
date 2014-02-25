/*!
 *  \file    statistic.hpp Contains statistic library definitions for the
 *           Depth project.
 *  \brief   Statistic library definitions for the Depth project.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Statistic library definitions for the Depth project.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   04.03.2009 03:58:30

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
#ifndef __STATISTIC_HPP__
#define __STATISTIC_HPP__
/*==========================================================================*/
#include <Depth/include/random/CRandomGenerator.hpp>
/*==========================================================================*/
/* DEFINE DECLARATIONS                                                      */
/*==========================================================================*/
/*!
    \def STATISTIC_API
    Statistic API definition
*/
#if (defined(__STATISTIC_DLL__) || defined(__DLL__))
  #if defined(__STATISTIC_EXPORT__)
    #if defined(__DLL_EXPORT__)
      #define STATISTIC_API __declspec(dllexport)
    #else
      #define STATISTIC_API
    #endif
  #else
    #if defined(__DLL_IMPORT__)
      #define STATISTIC_API __declspec(dllimport)
    #else
      #define STATISTIC_API
    #endif
  #endif
#else
  #define STATISTIC_API
#endif
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
/*!
    \namespace NDepth::NStatistic
    \brief Statistic definitions.
*/
/*==========================================================================*/
#endif
