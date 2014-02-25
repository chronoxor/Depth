/*!
 *  \file    CStringBufferHelper.inl Helper class for manipulations with a
 *           string buffer.
 *  \brief   Helper class for manipulations with a string buffer (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.05.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Helper class for manipulations with a string buffer (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   18.05.2010 19:51:36

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
#ifndef __CSTRINGBUFFERHELPER_INL__
#define __CSTRINGBUFFERHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CALSS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <Tbool t_IsStringClass>
template <typename T_StringType, class T_Allocator>
inline Tbool CStringBufferHelper<t_IsStringClass>::copy(typename NTraits::MAddPointer<T_StringType>::type& a_rpDestination, const T_StringType& a_crSource, T_Allocator& a_rAllocator)
{ CALL
  // Check T_StringType template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType> >();
  // Check T_Allocator template argument constraint to be a memory allocator.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIAllocator<T_Allocator> >();

  // Copy string buffers.
  Tuint length = NAlgorithms::NString::NBuffer::strLen(a_crSource) + 1;
  a_rpDestination = a_rAllocator.template createOne<T_StringType>();
  if (a_rpDestination == NULL)
  {
    WARNING(STR("Cannot create a new string pointer for the string buffer (requested size is %u bytes).") COMMA (sizeof(T_StringType)));
    return false;
  }

  *a_rpDestination = (T_StringType)a_rAllocator.template allocateMany<typename NTraits::MRemovePointer<T_StringType>::type>(length);
  if (*a_rpDestination == NULL)
  {
    WARNING(STR("Cannot create a new string for the string buffer (requested size is %u bytes).") COMMA (sizeof(typename NTraits::MRemovePointer<T_StringType>::type) * length));
    a_rAllocator.deleteOne(a_rpDestination);
    return false;
  }

  NAlgorithms::NString::NBuffer::strCpy(*a_rpDestination, a_crSource);
  return true;
}
/*--------------------------------------------------------------------------*/
template <>
template <typename T_StringType, class T_Allocator>
inline Tbool CStringBufferHelper<true>::copy(typename NTraits::MAddPointer<T_StringType>::type& a_rpDestination, const T_StringType& a_crSource, T_Allocator& a_rAllocator)
{ CALL
  // Check T_StringType template argument constraint to be a constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringConst<T_StringType> >();
  // Check T_Allocator template argument constraint to be a memory allocator.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIAllocator<T_Allocator> >();

  // Copy string class.
  a_rpDestination = a_rAllocator.template createOne<T_StringType>(a_crSource);
  if (a_rpDestination == NULL)
  {
    WARNING(STR("Cannot create a new string for the string buffer (requested size is %u bytes).") COMMA (sizeof(T_StringType)));
    return false;
  }

  *a_rpDestination = a_crSource;
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
