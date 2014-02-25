/*!
 *  \file    MReverseItHelper.hpp Contains reverse iterator wrapper types for
 *           different types of iterators.
 *  \brief   Reverse iterator algorithm helper meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reverse iterator algorithm helper meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   16.04.2007 02:51:27

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
#ifndef __MREVERSEITHELPER_HPP__
#define __MREVERSEITHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
#include <Depth/include/utility/iterators/CReverseIterator.hpp>
#include <Depth/include/utility/iterators/CReverseRandomIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Reverse iterator algorithm helper meta-class.
/*!
    Reverse iterator algorithm helper meta-class uses class specialization  to
    provide various kinds of reverse iterator wrappers.
*/
template <class T_Iterator>
class MReverseItHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Reverse iterator wrapper type.
  typedef typename NTraits::MIfThenElse<NTraits::MTraitsIterator<T_Iterator>::isMoveRandom, NUtility::NIterators::CReverseRandomIterator<T_Iterator>, NUtility::NIterators::CReverseIterator<T_Iterator> >::type TReverseIteratorWrapper;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
