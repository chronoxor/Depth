/*!
 *  \file    ACast.hpp Contains general template implementation of the cast
 *           algorithms.
 *  \brief   Cast algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Cast algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   08.05.2006 21:56:53

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
#ifndef __ACAST_HPP__
#define __ACAST_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/details/ACastHelper.hpp>
#include <Depth/include/traits/MIsPolymorphic.hpp>
#include <Depth/include/traits/MRemovePointer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Constant cast.
/*!
    This algorithm emulates C++ 'const_cast' casting.

    \param a_X - Source casting value.
    \return Destination casting value.
*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType constCast(T_SourceType a_X);
/*--------------------------------------------------------------------------*/
//! Algorithm: Dynamic cast.
/*!
    This algorithm emulates C++ 'dynamic_cast' casting.

    \param a_X - Source casting value.
    \return Destination casting value.
*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType dynamicCast(T_SourceType a_X);
/*--------------------------------------------------------------------------*/
//! Algorithm: Reinterpret cast.
/*!
    This algorithm emulates C++ 'reinterpret_cast' casting.

    \param a_X - Source casting value.
    \return Destination casting value.
*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType reinterpretCast(T_SourceType a_X);
/*--------------------------------------------------------------------------*/
//! Algorithm: Static cast.
/*!
    This algorithm emulates C++ 'static_cast' casting.

    \param a_X - Source casting value.
    \return Destination casting value.
*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType staticCast(T_SourceType a_X);
/*--------------------------------------------------------------------------*/
//! Algorithm: Polymorphic cast.
/*!
    This algorithm casting pointer from source type to destination. If casting
    fails than return value is NULL. If source type is  not  polymorphic  than
    code will not compile and you dive compilation error.

    \param a_pX - Pointer to the source casting value.
    \return Pointer to the destination casting value.
*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType polymorphicCast(T_SourceType* a_pX);
/*--------------------------------------------------------------------------*/
//! Algorithm: Non polymorphic cast.
/*!
    This algorithm casting pointer from source type to destination. If casting
    fails than return value is NULL. If source type is  not  polymorphic  than
    code will successfully compile.

    \param a_pX - Pointer to the source casting value.
    \return Pointer to the destination casting value.
*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType nonPolymorphicCast(T_SourceType* a_pX);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/ACast.inl>
/*==========================================================================*/
//! \example example-algorithms-ACast.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-ACast.cpp
/*==========================================================================*/
#endif
