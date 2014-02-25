/*!
 *  \file    MBoundItHelper.hpp Contains iterator sequence bound wrapper types
 *           for different types of iterators.
 *  \brief   Iterator sequence bound algorithm helper meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator sequence bound algorithm helper meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   04.04.2007 02:40:23

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
#ifndef __MBOUNDITHELPER_HPP__
#define __MBOUNDITHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
#include <Depth/include/utility/iterators/CBoundForwardIterator.hpp>
#include <Depth/include/utility/iterators/CBoundBackwardIterator.hpp>
#include <Depth/include/utility/iterators/CBoundRandomIterator.hpp>
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
//! Iterator sequence bound algorithm helper meta-class.
/*!
    Iterator  sequence  bound   algorithm   helper   meta-class   uses   class
    specialization  to  provide  various  kinds  of  iterator  sequence  bound
    wrappers.
*/
template <class T_Iterator>
class MBoundItHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Bound sequence iterator wrapper type.
  typedef typename NTraits::MIfThenElse<NTraits::MTraitsIterator<T_Iterator>::isMoveRandom, NUtility::NIterators::CBoundRandomIterator<T_Iterator>, typename NTraits::MIfThenElse<NTraits::MTraitsIterator<T_Iterator>::isMoveBackward, NUtility::NIterators::CBoundBackwardIterator<T_Iterator>, NUtility::NIterators::CBoundForwardIterator<T_Iterator> >::type>::type TBoundIteratorWrapper;
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
