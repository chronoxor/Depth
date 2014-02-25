/*!
 *  \file    FHashString.inl Hash string function class.
 *  \brief   Hash string function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash string function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   06.05.2008 22:20:37

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
#ifndef __FHASHSTRING_INL__
#define __FHASHSTRING_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Argument, class T_HashAlgorithm>
inline FHashString<T_Argument, T_HashAlgorithm>::FHashString(T_HashAlgorithm a_fHashAlgorithm/* = T_HashAlgorithm() */, const Tuint a_cSeed/* = 0 */) :
  m_fHashAlgorithm(a_fHashAlgorithm),
  m_Seed(a_cSeed)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Argument, class T_HashAlgorithm>
inline FHashString<T_Argument, T_HashAlgorithm>::FHashString(const FHashString<T_Argument, T_HashAlgorithm>& a_crInstance) :
  m_fHashAlgorithm(a_crInstance.m_fHashAlgorithm),
  m_Seed(a_crInstance.m_Seed)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Argument, class T_HashAlgorithm>
inline Tuint FHashString<T_Argument, T_HashAlgorithm>::operator () (const T_Argument& a_crArgument) const
{ CALL
  Tuint index = 0;
  Tuint length = NString::stringLength(a_crArgument);

  // Initialize hash function context.
  if (!m_fHashAlgorithm.initialize(m_Seed))
    return 0;
  // Feed hash function context.
  while (index < length)
  {
    if (m_fHashAlgorithm.hash((Tcbuffer)&a_crArgument[index], sizeof(typename NTraits::MTraitsString<T_Argument>::character)) != sizeof(typename NTraits::MTraitsString<T_Argument>::character))
      return 0;
    else
      ++index;
  }
  // Close hash function context.
  if (!m_fHashAlgorithm.close())
    return 0;
  // Return hash value.
  return m_fHashAlgorithm.getHash();
}
/*--------------------------------------------------------------------------*/
template <typename T_Argument, class T_HashAlgorithm>
template <class T_Archive>
inline Tbool FHashString<T_Argument, T_HashAlgorithm>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NFunctions::FHashString<T_Argument, T_HashAlgorithm>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_fHashAlgorithm, STR("m_fHashAlgorithm")));
    CHECK(a_rArchive.doValue(m_Seed, STR("m_Seed")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Argument, class T_HashAlgorithm>
inline void FHashString<T_Argument, T_HashAlgorithm>::swap(FHashString<T_Argument, T_HashAlgorithm>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_fHashAlgorithm, a_rInstance.m_fHashAlgorithm);
  NAlgorithms::NCommon::swap(m_Seed, a_rInstance.m_Seed);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
