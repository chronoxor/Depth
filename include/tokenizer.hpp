/*!
 *  \file    tokenizer.hpp Contains tokenizer library definitions for the
 *           Depth project.
 *  \brief   Tokenizer library definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer library definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   20.04.2009 02:37:23

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
#ifndef __TOKENIZER_HPP__
#define __TOKENIZER_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* DEFINE DECLARATIONS                                                      */
/*==========================================================================*/
/*!
    \def TOKENIZER_API
    Tokenizer API definition.
*/
#if (defined(__TOKENIZER_DLL__) || defined(__DLL__))
  #if defined(__TOKENIZER_EXPORT__)
    #if defined(__DLL_EXPORT__)
      #define TOKENIZER_API __declspec(dllexport)
    #else
      #define TOKENIZER_API
    #endif
  #else
    #if defined(__DLL_IMPORT__)
      #define TOKENIZER_API __declspec(dllimport)
    #else
      #define TOKENIZER_API
    #endif
  #endif
#else
  #define TOKENIZER_API
#endif
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
/*!
    \namespace NDepth::NTokenizer
    \brief Tokenizer definitions.

    \namespace NDepth::NTokenizer::NDetails
    \brief Tokenizer details definitions.

    \namespace NDepth::NTokenizer::NIterators
    \brief Tokenizer iterator definitions.
*/
/*==========================================================================*/
#endif
