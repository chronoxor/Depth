/*!
 *  \file    base.hpp Contains base definitions of the Depth project.
 *  \brief   Base definitions of the Depth project.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base definitions of the Depth project.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base definitions
    VERSION:   1.0
    CREATED:   04.01.2006 01:04:35

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
#ifndef __BASE_HPP__
#define __BASE_HPP__
/*==========================================================================*/
#include <Depth/include/base/NULL.hpp>
#include <Depth/include/types.hpp>
#include <Depth/include/macros.hpp>
/*==========================================================================*/
/* DEFINE DECLARATIONS                                                      */
/*==========================================================================*/
/*!
    \def BASE_API
    Base API definition.
*/
#if (defined(__BASE_DLL__) || defined(__DLL__))
  #if defined(__BASE_EXPORT__)
    #if defined(__DLL_EXPORT__)
      #define BASE_API __declspec(dllexport)
    #else
      #define BASE_API
    #endif
  #else
    #if defined(__DLL_IMPORT__)
      #define BASE_API __declspec(dllimport)
    #else
      #define BASE_API
    #endif
  #endif
#else
  #define BASE_API
#endif
/*==========================================================================*/
#include <Depth/include/constants.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
/*!
    \namespace NDepth
    \brief Depth project definitions.

    \namespace NDepth::NAlgorithms
    \brief Algorithms definitions.

    \namespace NDepth::NAlgorithms::NCommon
    \brief Common algorithms definitions.

    \namespace NDepth::NAlgorithms::NCommon::NDetails
    \brief Common algorithms details definitions.

    \namespace NDepth::NAlgorithms::NContainers
    \brief Template common containers algorithms definitions.

    \namespace NDepth::NAlgorithms::NContainers::NDetails
    \brief Template common containers algorithms details definitions.

    \namespace NDepth::NAlgorithms::NContainers::NTree
    \brief Template tree containers algorithms definitions.

    \namespace NDepth::NAlgorithms::NFunctions
    \brief Function object algorithms definitions.

    \namespace NDepth::NAlgorithms::NHash
    \brief Hash functions algorithms definitions.

    \namespace NDepth::NAlgorithms::NIterators
    \brief Template common iterators algorithms definitions.

    \namespace NDepth::NAlgorithms::NIterators::NDetails
    \brief Template common iterators algorithms details definitions.

    \namespace NDepth::NAlgorithms::NIterators::NTree
    \brief Template tree iterators algorithms definitions.

    \namespace NDepth::NAlgorithms::NMath
    \brief Math algorithms definitions.

    \namespace NDepth::NAlgorithms::NNumeric
    \brief Numeric algorithms definitions.

    \namespace NDepth::NAlgorithms::NString
    \brief String algorithms definitions.

    \namespace NDepth::NAlgorithms::NString::NBuffer
    \brief String buffer algorithms definitions.

    \namespace NDepth::NAlgorithms::NString::NDetails
    \brief String algorithms details definitions.

    \namespace NDepth::NAlgorithms::NString::NFormat
    \brief String format algorithms definitions.

    \namespace NDepth::NAlgorithms::NString::NSearch
    \brief String search algorithms definitions.

    \namespace NDepth::NBase
    \brief Base definitions.

    \namespace NDepth::NCommon
    \brief Common definitions.

    \namespace NDepth::NCommon::NContainers
    \brief Common containers definitions.

    \namespace NDepth::NCommon::NIterators
    \brief Common iterators definitions.

    \namespace NDepth::NConcept
    \brief Template arguments checking conception definitions.

    \namespace NDepth::NConcept::NBase
    \brief Base types conception checking definitions.

    \namespace NDepth::NConcept::NClass
    \brief Class conception checking definitions.

    \namespace NDepth::NConcept::NCommon
    \brief Common conception checking definitions.

    \namespace NDepth::NConcept::NContainers
    \brief Containers conception checking definitions.

    \namespace NDepth::NConcept::NDetails
    \brief Conception checking details definitions.

    \namespace NDepth::NConcept::NFunctions
    \brief Functions conception checking definitions.

    \namespace NDepth::NConcept::NIterators
    \brief Iterators conception checking definitions.

    \namespace NDepth::NConcept::NOperators
    \brief Operators conception checking definitions.

    \namespace NDepth::NConcept::NTypes
    \brief Types conception checking definitions.

    \namespace NDepth::NConfigure
    \brief OS dependant configuration definitions.

    \namespace NDepth::NConfigure::NDetails
    \brief OS dependant configuration details definitions.

    \namespace NDepth::NContainers
    \brief Template common containers definitions.

    \namespace NDepth::NContainers::NDetails
    \brief Template common containers details definitions.

    \namespace NDepth::NContainers::NIterators
    \brief Template common containers iterators definitions.

    \namespace NDepth::NContainers::NPolicy
    \brief Template common containers policy definitions.

    \namespace NDepth::NConstants
    \brief Constants definitions.

    \namespace NDepth::NDebug
    \brief Debugging definitions.

    \namespace NDepth::NDebug::NDetails
    \brief Debugging details definitions.

    \namespace NDepth::NErrors
    \brief Errors handling definitions.

    \namespace NDepth::NErrors::NDetails
    \brief Errors handling details definitions.

    \namespace NDepth::NFunctors
    \brief Functors definitions.

    \namespace NDepth::NFunctors::NDetails
    \brief Functors details definitions.

    \namespace NDepth::NMath
    \brief Math definitions.

    \namespace NDepth::NMemory
    \brief Memory definitions.

    \namespace NDepth::NMemory::NAllocators
    \brief Memory allocators definitions.

    \namespace NDepth::NMemory::NDetails
    \brief Memory details definitions.

    \namespace NDepth::NMemory::NGC
    \brief Memory garbage collection definitions.

    \namespace NDepth::NMemory::NManagers
    \brief Memory managers definitions.

    \namespace NDepth::NProcess
    \brief Process definitions.

    \namespace NDepth::NSerialization
    \brief Serialization definitions.

    \namespace NDepth::NSerialization::NDetails
    \brief Serialization details definitions.

    \namespace NDepth::NShared
    \brief Shared utilities definitions.

    \namespace NDepth::NSignals
    \brief Signals definitions.

    \namespace NDepth::NSignals::NCombiners
    \brief Signal combiners definitions.

    \namespace NDepth::NStream
    \brief Stream definitions.

    \namespace NDepth::NStream::NDetails
    \brief Stream details definitions.

    \namespace NDepth::NStream::NIterators
    \brief Stream iterators definitions.

    \namespace NDepth::NStream::NOperators
    \brief Stream operators definitions.

    \namespace NDepth::NStream::NPack
    \brief Stream pack definitions.

    \namespace NDepth::NStream::NText
    \brief Stream text definitions.

    \namespace NDepth::NString
    \brief String definitions.

    \namespace NDepth::NString::NDetails
    \brief String details definitions.

    \namespace NDepth::NString::NIterators
    \brief String iterators definitions.

    \namespace NDepth::NString::NUCD
    \brief Unicode Character Database (UCD) definitions.

    \namespace NDepth::NString::NUCD::NDetails
    \brief Unicode Character Database (UCD) details definitions.

    \namespace NDepth::NSystem
    \brief System definitions.

    \namespace NDepth::NTime
    \brief Time definitions.

    \namespace NDepth::NTime::NTimezone
    \brief Time zone definitions.

    \namespace NDepth::NTime::NTimezone::NDetails
    \brief Time zone details definitions.

    \namespace NDepth::NTraits
    \brief Type traits definitions.

    \namespace NDepth::NTraits::NDetails
    \brief Type traits details definitions.

    \namespace NDepth::NTraits::NFunctions
    \brief Functions traits definitions.

    \namespace NDepth::NTuple
    \brief Tuple definitions.

    \namespace NDepth::NTuple::NDetails
    \brief Tuple details definitions.

    \namespace NDepth::NTypes
    \brief Types definitions.

    \namespace NDepth::NUtility
    \brief Utilities definitions.

    \namespace NDepth::NUtility::NIterators
    \brief Utilities iterators definitions.

    \namespace NDepth::NUtility::NObserver
    \brief Utilities observer definitions.
*/
namespace NDepth {
// Explicitly use constants definitions.
using namespace NConstants;
// Explicitly use types definitions.
using namespace NTypes;

#if defined(SYS_SUPPORT_CNULL)
// Explicitly use NULL wrapper.
using NBase::NULL;
#endif
}
/*==========================================================================*/
#include <Depth/include/debug.hpp>
#include <Depth/include/errors.hpp>
#include <Depth/include/memory.hpp>
#include <Depth/include/concept.hpp>
/*==========================================================================*/
#endif
