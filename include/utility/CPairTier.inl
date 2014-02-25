/*!
 *  \file    CPairTier.inl Utility class that helps to tie CPair instances
 *           with specified references to values.
 *  \brief   Pair tier class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pair tier class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   05.03.2006 22:16:28

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
#ifndef __CPAIRTIER_INL__
#define __CPAIRTIER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_FirstType, typename T_SecondType>
inline CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > CPairTier::tie(T_FirstType& a_rFirstValue, T_SecondType& a_rSecondValue)
{ CALL
  return CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> >(NBase::CReference<T_FirstType>(a_rFirstValue), NBase::CReference<T_SecondType>(a_rSecondValue));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > CPairTier::tie(CPair<T_FirstType, T_SecondType>& a_rInstance)
{ CALL
  return CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> >(NBase::CReference<T_FirstType>(a_rInstance.getFirst()), NBase::CReference<T_SecondType>(a_rInstance.getSecond()));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType>
inline CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > CPairTier::tie(CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> >& a_rInstance)
{ CALL
  return CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> >(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
