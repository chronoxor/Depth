/*!
 *  \file    ATie.hpp Contains general template implementation of the tie
 *           algorithm.
 *  \brief   Tie algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tie algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   04.09.2006 22:27:44

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
#ifndef __ATIE_HPP__
#define __ATIE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/CTupleTier.hpp>
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
//! Algorithm: Tie given 1 reference with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 1 given  reference.  Than  it
    returns this tuple to caller.

    \param a_rValue - Reference to the tying object.
    \return CTuple class instance with a tied reference.
*/
template <typename T_Type>
NTuple::CTuple<NBase::CReference<T_Type> > tie(T_Type& a_rValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 2 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 2 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 3 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 3 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 4 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 4 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \param a_rValue4 - Reference to the 4'th tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 5 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 5 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \param a_rValue4 - Reference to the 4'th tuple value.
    \param a_rValue5 - Reference to the 5'th tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 6 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 6 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \param a_rValue4 - Reference to the 4'th tuple value.
    \param a_rValue5 - Reference to the 5'th tuple value.
    \param a_rValue6 - Reference to the 6'th tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 7 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 7 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \param a_rValue4 - Reference to the 4'th tuple value.
    \param a_rValue5 - Reference to the 5'th tuple value.
    \param a_rValue6 - Reference to the 6'th tuple value.
    \param a_rValue7 - Reference to the 7'th tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 8 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 8 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \param a_rValue4 - Reference to the 4'th tuple value.
    \param a_rValue5 - Reference to the 5'th tuple value.
    \param a_rValue6 - Reference to the 6'th tuple value.
    \param a_rValue7 - Reference to the 7'th tuple value.
    \param a_rValue8 - Reference to the 8'th tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 9 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 9 given references.  Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \param a_rValue4 - Reference to the 4'th tuple value.
    \param a_rValue5 - Reference to the 5'th tuple value.
    \param a_rValue6 - Reference to the 6'th tuple value.
    \param a_rValue7 - Reference to the 7'th tuple value.
    \param a_rValue8 - Reference to the 8'th tuple value.
    \param a_rValue9 - Reference to the 9'th tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9);
/*--------------------------------------------------------------------------*/
//! Algorithm: Tie given 10 references with the tuple and return it.
/*!
    This algorithm constructs a tuple which ties 10 given references. Than  it
    returns this tuple to caller.

    \param a_rValue1 - Reference to the 1'st tuple value.
    \param a_rValue2 - Reference to the 2'nd tuple value.
    \param a_rValue3 - Reference to the 3'rd tuple value.
    \param a_rValue4 - Reference to the 4'th tuple value.
    \param a_rValue5 - Reference to the 5'th tuple value.
    \param a_rValue6 - Reference to the 6'th tuple value.
    \param a_rValue7 - Reference to the 7'th tuple value.
    \param a_rValue8 - Reference to the 8'th tuple value.
    \param a_rValue9 - Reference to the 9'th tuple value.
    \param a_rValue10 - Reference to the 10'th tuple value.
    \return CTuple class instance with a tied references.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
NTuple::CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9, T_Type10& a_rValue10);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/ATie.inl>
/*==========================================================================*/
#endif
