/*!
 *  \file    AFindString.inl Contains general template implementation of
 *           the algorithm to find (sub)string in the given string object
 *           using Brute Force searching algorithm.
 *  \brief   Algorithm to find (sub)string in the given string using Brute Force searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.12.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find (sub)string in the given string using Brute Force searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   03.12.2009 20:04:19

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
#ifndef __AFINDSTRING_INL__
#define __AFINDSTRING_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool findString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const T_PatternStringType& a_crPattern)
{ CALL
  if (a_cReverseSearch)
    return findString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_crSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax);
  else
    return findString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_crSource, 0, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool findString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength)
{ CALL
  if (a_cReverseSearch)
    return findString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_crSource, NConstants::CConstants::uintMax, a_cSourceLength, a_crPattern, 0, a_cPatternLength);
  else
    return findString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_crSource, 0, a_cSourceLength, a_crPattern, 0, a_cPatternLength);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool findString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (a_cReverseSearch)
  {
    Tuint pattern_length = stringLength(a_crPattern, a_cPatternIndex, a_cPatternLength);
    Tuint source_index = NCommon::min((a_cSourceIndex < NConstants::CConstants::uintMax) ? (a_cSourceIndex + 1) : a_cSourceIndex, stringLength(a_crSource));
    Tuint source_length = NCommon::min(source_index, a_cSourceLength);

    // Check if the pattern string is not empty.
    ASSERT((pattern_length > 0), STR("Pattern string cannot be empty. Its length should be greater than zero."))
    {
      return false;
    }
    // Check if the source string is not empty.
    ASSERT((source_length > 0), STR("Source string cannot be empty. Its length should be greater than zero."))
    {
      return false;
    }

    --source_index;

    if (source_length >= pattern_length)
    {
      Tuint i, j;
      Tuint n = source_length;
      Tuint m = pattern_length;

      if (a_cIgnoreCase)
      {
        for (j = 0; j <= (n - m); ++j)
        {
          for (i = 0; i < m; ++i)
          {
            if (NDepth::NString::CCharacter(a_crSource[source_index - i - j]).toLowerCase() != NDepth::NString::CCharacter(a_crPattern[a_cPatternIndex + m - i - 1]).toLowerCase())
              break;
          }

          if (i >= m)
          {
            a_rFoundStart = source_index - j - i + 1;
            a_rFoundEnd = source_index - j;
            return true;
          }
        }
      }
      else
      {
        for (j = 0; j <= (n - m); ++j)
        {
          for (i = 0; i < m; ++i)
          {
            if (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[source_index - i - j]) != ((typename NTraits::MTraitsString<T_PatternStringType>::ucharacter)a_crPattern[a_cPatternIndex + m - i - 1]))
              break;
          }

          if (i >= m)
          {
            a_rFoundStart = source_index - j - i + 1;
            a_rFoundEnd = source_index - j;
            return true;
          }
        }
      }
    }
    return false;
  }
  else
  {
    Tuint pattern_length = stringLength(a_crPattern, a_cPatternIndex, a_cPatternLength);
    Tuint source_length = stringLength(a_crSource, a_cSourceIndex, a_cSourceLength);

    // Check if the pattern string is not empty.
    ASSERT((pattern_length > 0), STR("Pattern string cannot be empty. Its length should be greater than zero."))
    {
      return false;
    }
    // Check if the source string is not empty.
    ASSERT((source_length > 0), STR("Source string cannot be empty. Its length should be greater than zero."))
    {
      return false;
    }

    if (source_length >= pattern_length)
    {
      Tuint i, j;
      Tuint n = source_length;
      Tuint m = pattern_length;

      if (a_cIgnoreCase)
      {
        for (j = 0; j <= (n - m); ++j)
        {
          for (i = 0; i < m; ++i)
          {
            if (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(a_crPattern[a_cPatternIndex + i]).toLowerCase())
              break;
          }

          if (i >= m)
          {
            a_rFoundStart = a_cSourceIndex + j;
            a_rFoundEnd = a_cSourceIndex + j + i - 1;
            return true;
          }
        }
      }
      else
      {
        for (j = 0; j <= (n - m); ++j)
        {
          for (i = 0; i < m; ++i)
          {
            if (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<T_PatternStringType>::ucharacter)a_crPattern[a_cPatternIndex + i]))
              break;
          }

          if (i >= m)
          {
            a_rFoundStart = a_cSourceIndex + j;
            a_rFoundEnd = a_cSourceIndex + j + i - 1;
            return true;
          }
        }
      }
    }
    return false;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
