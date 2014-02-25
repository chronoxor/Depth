/*!
 *  \file    CGetItIndexHelper.inl Contains template implementations of the
 *           get indexed container's iterator algorithm for different types
 *           of containers.
 *  \brief   Get indexed container's iterator algorithm helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Get indexed container's iterator algorithm helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms details
    VERSION:   1.0
    CREATED:   28.03.2007 01:48:22

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
#ifndef __CGETITINDEXHELPER_INL__
#define __CGETITINDEXHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <Tuint t_Algorithm>
template <class T_Container>
inline typename NTraits::MTraitsContainer<T_Container>::iterator CGetItIndexHelper<t_Algorithm>::getItIndex(T_Container& a_rContainer, const Tuint a_cIndex)
{ CALL
  // Check T_Container class constraint to be an any constant container.
  NConcept::MConstraint::requiresConcept<NConcept::NContainers::MConceptContainerConst<typename NTraits::MTraitsContainer<T_Container>::container> >();

  Tuint distance = a_cIndex;
  typename NTraits::MTraitsContainer<T_Container>::iterator it(getItFirst(a_rContainer));

  if (it.isValid())
    if (it.stepForward(distance) == distance)
      return it;

  return typename NTraits::MTraitsContainer<T_Container>::iterator();
}
/*--------------------------------------------------------------------------*/
template <>
template <class T_Container>
inline typename NTraits::MTraitsContainer<T_Container>::iterator CGetItIndexHelper<1>::getItIndex(T_Container& a_rContainer, const Tuint a_cIndex)
{ CALL
  // Check T_Container class constraint to be an any constant random accessible container.
  NConcept::MConstraint::requiresConcept<NConcept::NContainers::MConceptRandomConst<typename NTraits::MTraitsContainer<T_Container>::container> >();

  return a_rContainer.getItIndex(a_cIndex);
}
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
