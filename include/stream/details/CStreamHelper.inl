/*!
 *  \file    CStreamHelper.inl Stream helper class uses template method
 *           specialization to call read/peek and write/push stream methods.
 *  \brief   Stream helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream details
    VERSION:   1.0
    CREATED:   04.09.2008 23:16:34

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
#ifndef __CSTREAMHELPER_INL__
#define __CSTREAMHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_Stream>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cPeekRead);
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_cSize);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, IReader& a_rStream, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_cPeekRead ? a_rStream.peekBuffer(a_pBuffer, a_cSize) : a_rStream.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  IGNORE_UNUSED(a_cPeekRead);
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_cSingleSize);
  IGNORE_UNUSED(a_cCount);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, IReader& a_rStream, Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  return a_cPeekRead ? a_rStream.peekBuffer(a_pBuffer, a_cSingleSize, a_cCount) : a_rStream.readBuffer(a_pBuffer, a_cSingleSize, a_cCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cPeekRead);
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_cSize);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, IReader& a_rStream, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_cPeekRead ? a_rStream.peekBuffer(a_pBuffer, a_cSize) : a_rStream.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cPeekRead);
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_cSize);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::inputBuffer(const Tbool a_cPeekRead, IReader& a_rStream, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_cPeekRead ? a_rStream.peekBuffer(a_pBuffer, a_cSize) : a_rStream.readBuffer(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
/*!
    \def INPUT_SCHAR(type)
    Input new character of given \a type from the binary exchange stream.
*/
#define INPUT_SCHAR(type)                                                                                                                                                                                                           \
{                                                                                                                                                                                                                                   \
  type value;                                                                                                                                                                                                                       \
  Tuint result = inputBuffer(a_cPeekRead, a_rStream, &value, sizeof(type), 1);                                                                                                                                                      \
  Tbool success = (result == sizeof(type));                                                                                                                                                                                         \
  if (success)                                                                                                                                                                                                                      \
  {                                                                                                                                                                                                                                 \
    ASSERT(NString::CCharacter((Tuint)((Tscharu)value)).isValidASCII(), STR("Character value which was inputted from stream does not fit into the system character bounds (character code is %hU).") COMMA (Tuint)((Tscharu)value)) \
    {                                                                                                                                                                                                                               \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                                                          \
    }                                                                                                                                                                                                                               \
                                                                                                                                                                                                                                    \
    a_rCharacter = (Tschar)value;                                                                                                                                                                                                   \
  }                                                                                                                                                                                                                                 \
  return NUtility::CPair<Tbool, Tuint>(success, result);                                                                                                                                                                            \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputChar(const Tbool a_cPeekRead, T_Stream& a_rStream, Tschar& a_rCharacter)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    switch (a_rStream.internalGetSCharSize())
    {
      case 1:
      {
        #if defined(__SCHAR_S_ASCII__)
        INPUT_SCHAR(Tsint08);
        #else
        INPUT_SCHAR(Tuint08);
        #endif
      }
      case 2:
      {
        #if defined(__SCHAR_S_ASCII__)
        INPUT_SCHAR(Tsint16);
        #else
        INPUT_SCHAR(Tuint16);
        #endif
      }
      case 4:
      {
        #if defined(__SCHAR_S_ASCII__)
        INPUT_SCHAR(Tsint32);
        #else
        INPUT_SCHAR(Tuint32);
        #endif
      }
      case 8:
      {
        #if defined(__SCHAR_S_ASCII__)
        INPUT_SCHAR(Tsint64);
        #else
        INPUT_SCHAR(Tuint64);
        #endif
      }
      default:
      {
        WARNING(STR("Current platform is not able to accept character data type from the exchange stream."));
        return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }
  }
  else
  {
    Tuint result = inputBuffer(a_cPeekRead, a_rStream, &a_rCharacter, 1);
    return NUtility::CPair<Tbool, Tuint>((result == 1), result);
  }
}
/*--------------------------------------------------------------------------*/
#undef INPUT_SCHAR
/*--------------------------------------------------------------------------*/
/*!
    \def INPUT_WCHAR(type)
    Input new wide character of given \a type from the binary exchange stream.
*/
#define INPUT_WCHAR(type)                                                                                                                                                                                                                       \
{                                                                                                                                                                                                                                               \
  type value;                                                                                                                                                                                                                                   \
  Tuint result = inputBuffer(a_cPeekRead, a_rStream, &value, sizeof(type), 1);                                                                                                                                                                  \
  Tbool success = (result == sizeof(type));                                                                                                                                                                                                     \
  if (success)                                                                                                                                                                                                                                  \
  {                                                                                                                                                                                                                                             \
    ASSERT(NString::CCharacter((Tuint)((Twcharu)value)).isValidUnicode(), STR("Wide character value which was inputted from stream does not fit into the system wide character bounds (character code is %hU).") COMMA (Tuint)((Twcharu)value)) \
    {                                                                                                                                                                                                                                           \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                                                                      \
    }                                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                \
    a_rCharacter = (Twchar)value;                                                                                                                                                                                                               \
  }                                                                                                                                                                                                                                             \
  return NUtility::CPair<Tbool, Tuint>(success, result);                                                                                                                                                                                        \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputChar(const Tbool a_cPeekRead, T_Stream& a_rStream, Twchar& a_rCharacter)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    switch (a_rStream.internalGetWCharSize())
    {
      case 1:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        INPUT_WCHAR(Tsint08);
        #else
        INPUT_WCHAR(Tuint08);
        #endif
      }
      case 2:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        INPUT_WCHAR(Tsint16);
        #else
        INPUT_WCHAR(Tuint16);
        #endif
      }
      case 4:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        INPUT_WCHAR(Tsint32);
        #else
        INPUT_WCHAR(Tuint32);
        #endif
      }
      case 8:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        INPUT_WCHAR(Tsint64);
        #else
        INPUT_WCHAR(Tuint64);
        #endif
      }
      default:
      {
        WARNING(STR("Current platform is not able to accept wide character data type from the exchange stream."));
        return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }
  }
  else
  {
    Tuint result = inputBuffer(a_cPeekRead, a_rStream, &a_rCharacter, 1);
    return NUtility::CPair<Tbool, Tuint>((result == 1), result);
  }
}
/*--------------------------------------------------------------------------*/
#undef INPUT_WCHAR
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, Tsstr& a_rpString, const Tuint a_cSize/* = 0 */)
{ CALL
  // Check if the given ASCII string buffer is NULL.
  ASSERT((a_rpString == NULL), STR("Given ASCII string buffer should be NULL. Otherwise memory leak could happen."));

  // Read ASCII string from the stream.
  NString::CStringASCII temp;
  NUtility::CPair<Tbool, Tuint> result = inputString(a_cPeekRead, a_rStream, temp, a_cSize);

  // Allocate memory for the new ASCII 'C' string.
  Tuint size = temp.getSize() + 1;
  a_rpString = newex Tschar[size];
  if (a_rpString == NULL)
  {
    WARNING(STR("Cannot allocate buffer for the ASCII 'C' string (requested size is %u bytes).") COMMA (size * sizeof(Tschar)));
    result.getFirst() = false;
    return result;
  }

  // Copy ASCII string content.
  NMemory::CMemory::copy(a_rpString, temp.getBuffer(), (size - 1) * sizeof(Tschar));
  a_rpString[size - 1] = ASC('\0');
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, Twstr& a_rpString, const Tuint a_cSize/* = 0 */)
{ CALL
  // Check if the given Unicode string buffer is NULL.
  ASSERT((a_rpString == NULL), STR("Given Unicode string buffer should be NULL. Otherwise memory leak could happen."));

  // Read Unicode string from the stream.
  NString::CStringUnicode temp;
  NUtility::CPair<Tbool, Tuint> result = inputString(a_cPeekRead, a_rStream, temp, a_cSize);

  // Allocate memory for the new Unicode 'C' string.
  Tuint size = temp.getSize() + 1;
  a_rpString = newex Twchar[size];
  if (a_rpString == NULL)
  {
    WARNING(STR("Cannot allocate buffer for the Unicode 'C' string (requested size is %u bytes).") COMMA (size * sizeof(Twchar)));
    result.getFirst() = false;
    return result;
  }

  // Copy Unicode string content.
  NMemory::CMemory::copy(a_rpString, temp.getBuffer(), (size - 1) * sizeof(Twchar));
  a_rpString[size - 1] = UNC('\0');
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, NString::CStringASCII& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  Tschar c;
  Tuint size = a_cSize;
  Tbool toel = (size == 0);
  NUtility::CPair<Tbool, Tuint> result(true, 0);
  NUtility::CPair<Tbool, Tuint> temp(false, 0);

  // Clear the given string.
  if (!a_rString.clear())
    return temp;

  while (result.getFirst() && (toel || (size-- > 0)))
  {
    // Get next character.
    temp = inputChar(a_cPeekRead, a_rStream, c);
    if (temp.getFirst())
    {
      result.getSecond() += temp.getSecond();

      // Check if character is an end line character.
      if (toel && ((c == ASC('\0')) || (c == ASC('\n'))))
        return result;

      // Check if character is a part of the end line character.
      if (toel && (c == ASC('\r')))
      {
        temp = inputChar(a_cPeekRead, a_rStream, c);
        if (temp.getFirst())
        {
          result.getSecond() += temp.getSecond();

          // Check if character is an end line character.
          if ((c == ASC('\0')) || (c == ASC('\n')))
            return result;

          // Insert character into the result string.
          if (!a_rString.insertLast(ASC('\r')) || !a_rString.insertLast(c))
          {
            result.getFirst() = false;
            return result;
          }
        }
        else
          break;
      }
      else
      {
        // Insert character into the result string.
        if (!a_rString.insertLast(c))
        {
          result.getFirst() = false;
          return result;
        }
      }
    }
    else
    {
      // Check if we reach EOF.
      if (result.getSecond() == 0)
        result.getFirst() = false;
      break;
    }
  }

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, NString::CStringUnicode& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  Twchar c;
  Tuint size = a_cSize;
  Tbool toel = (size == 0);
  NUtility::CPair<Tbool, Tuint> result(true, 0);
  NUtility::CPair<Tbool, Tuint> temp(false, 0);

  // Clear the given string.
  if (!a_rString.clear())
    return temp;

  while (result.getFirst() && (toel || (size-- > 0)))
  {
    // Get next character.
    temp = inputChar(a_cPeekRead, a_rStream, c);
    if (temp.getFirst())
    {
      result.getSecond() += temp.getSecond();

      // Check if character is an end line character.
      if (toel && ((c == UNC('\0')) || (c == UNC('\n'))))
        return result;

      // Check if character is a part of the end line character.
      if (toel && (c == UNC('\r')))
      {
        temp = inputChar(a_cPeekRead, a_rStream, c);
        if (temp.getFirst())
        {
          result.getSecond() += temp.getSecond();

          // Check if character is an end line character.
          if ((c == UNC('\0')) || (c == UNC('\n')))
            return result;

          // Insert character into the result string.
          if (!a_rString.insertLast(UNC('\r')) || !a_rString.insertLast(c))
          {
            result.getFirst() = false;
            return result;
          }
        }
        else
          break;
      }
      else
      {
        // Insert character into the result string.
        if (!a_rString.insertLast(c))
        {
          result.getFirst() = false;
          return result;
        }
      }
    }
    else
    {
      // Check if we reach EOF.
      if (result.getSecond() == 0)
        result.getFirst() = false;
      break;
    }
  }

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, NString::CSystemString& a_rString, const Tuint a_cSize/* = 0 */)
{ CALL
  // Read common string from the stream.
  NString::CString temp;
  NUtility::CPair<Tbool, Tuint> result = inputString(a_cPeekRead, a_rStream, temp, a_cSize);

  // Convert common string to the system one.
  a_rString = temp.operator NString::CSystemString();
  return result;
}
/*--------------------------------------------------------------------------*/
/*!
    \def CACHE_PEEK
    Read new character from the stream and put them into the cache string.
*/
#define CACHE_PEEK                                                           \
{                                                                            \
  if (!stop)                                                                 \
  {                                                                          \
    if (is_ascii)                                                            \
      current = inputChar(a_cPeekRead, a_rStream, c_ascii);                  \
    else                                                                     \
      current = inputChar(a_cPeekRead, a_rStream, c_unicode);                \
    if (current.getFirst())                                                  \
    {                                                                        \
      result.getSecond() += current.getSecond();                             \
      if (is_ascii)                                                          \
      {                                                                      \
        if (!cache_ascii.insertLast(c_ascii))                                \
          stop = true;                                                       \
        if (NString::CCharacter(c_ascii).isValidSystem())                    \
          c = (Tchar)NString::CCharacter(c_ascii).toLowerCase();             \
        else                                                                 \
          stop = true;                                                       \
      }                                                                      \
      else                                                                   \
      {                                                                      \
        if (!cache_unicode.insertLast(c_unicode))                            \
          stop = true;                                                       \
        if (NString::CCharacter(c_unicode).isValidSystem())                  \
          c = (Tchar)NString::CCharacter(c_unicode).toLowerCase();           \
        else                                                                 \
          stop = true;                                                       \
      }                                                                      \
    }                                                                        \
    else                                                                     \
      stop = true;                                                           \
  }                                                                          \
}
/*--------------------------------------------------------------------------*/
/*!
    \def CACHE_PUSH
    Push characters from the cache string back into the buffer.
*/
#define CACHE_PUSH                                                                                       \
{                                                                                                        \
  if (is_ascii)                                                                                          \
  {                                                                                                      \
    if (!cache_ascii.isEmpty() && !a_cPeekRead)                                                          \
      result.getSecond() -= outputBuffer(a_rStream, cache_ascii.getBuffer(), cache_ascii.getSize());     \
  }                                                                                                      \
  else                                                                                                   \
  {                                                                                                      \
    if (!cache_unicode.isEmpty() && !a_cPeekRead)                                                        \
      result.getSecond() -= outputBuffer(a_rStream, cache_unicode.getBuffer(), cache_unicode.getSize()); \
  }                                                                                                      \
}
/*--------------------------------------------------------------------------*/
/*!
    \def CACHE_CLEAR
    Clear cache string.
*/
#define CACHE_CLEAR                                                          \
{                                                                            \
  if (!cache_ascii.clear())                                                  \
    stop = true;                                                             \
  if (!cache_unicode.clear())                                                \
    stop = true;                                                             \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
NUtility::CPair<Tbool, Tuint> CStreamHelper::inputBool(const Tbool a_cPeekRead, T_Stream& a_rStream, Tbool& a_rBoolean, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    Tbyte b;
    Tuint result = inputBuffer(a_cPeekRead, a_rStream, &b, sizeof(Tbyte), 1);
    Tbool success = (result == sizeof(Tbyte));
    if (success)
      a_rBoolean = (b != 0);
    return NUtility::CPair<Tbool, Tuint>(success, result);
  }
  else
  {
    static Tchar true_num[] = STR("1");
    static Tchar true_str[] = STR("true");
    static Tchar false_num[] = STR("0");
    static Tchar false_str[] = STR("false");
    static Tuint true_num_count = sizeof(true_num) / sizeof(true_num[0]);
    static Tuint true_str_count = sizeof(true_str) / sizeof(true_str[0]);
    static Tuint false_num_count = sizeof(false_num) / sizeof(false_num[0]);
    static Tuint false_str_count = sizeof(false_str) / sizeof(false_str[0]);

    // Input result parameters.
    Tchar c = 0;
    Tschar c_ascii;
    Twchar c_unicode;
    Tbool stop = false;
    Tbool is_ascii = (a_cParseFlags & IStream::PARSE_ASCII) ? true : NString::CCharacter::isSystemASCII();
    NString::CStringASCII cache_ascii;
    NString::CStringUnicode cache_unicode;
    NUtility::CPair<Tbool, Tuint> current(false, 0);
    NUtility::CPair<Tbool, Tuint> result(false, 0);

    // Boolean number parameters.
    Tuint count = 1;
    Tuint type = 0;

    while (!stop)
    {
      CACHE_PEEK;
      if (!stop)
      {
        // Check if character is a space character.
        if (NString::CCharacter(c).isSpace() && (type == 0))
          continue;

        // Parse boolean number value.
        if ((c == true_num[count - 1]) && ((type == 1) || (type == 0)))
        {
          type = 1;
          if (++count == true_num_count)
          {
            a_rBoolean = true;
            result.getFirst() = true;
            CACHE_CLEAR;
            break;
          }
        }
        else if ((c == false_num[count - 1]) && ((type == 2) || (type == 0)))
        {
          type = 2;
          if (++count == false_num_count)
          {
            a_rBoolean = false;
            result.getFirst() = true;
            CACHE_CLEAR;
            break;
          }
        }
        else if ((c == true_str[count - 1]) && ((type == 3) || (type == 0)))
        {
          type = 3;
          if (++count == true_str_count)
          {
            a_rBoolean = true;
            result.getFirst() = true;
            CACHE_CLEAR;
            break;
          }
        }
        else if ((c == false_str[count - 1]) && ((type == 4) || (type == 0)))
        {
          type = 4;
          if (++count == false_str_count)
          {
            a_rBoolean = false;
            result.getFirst() = true;
            CACHE_CLEAR;
            break;
          }
        }
        else
          stop = true;
      }
    }

    CACHE_PUSH;
    return result;
  }
}
/*--------------------------------------------------------------------------*/
/*!
    \def INPUT_INTEGER(type)
    Input new integer number of given \a type from the binary exchange stream.
*/
#define INPUT_INTEGER(type)                                                                                                                                                                                            \
{                                                                                                                                                                                                                      \
  type value;                                                                                                                                                                                                          \
  Tuint result = inputBuffer(a_cPeekRead, a_rStream, &value, sizeof(type), 1);                                                                                                                                         \
  Tbool success = (result == sizeof(type));                                                                                                                                                                            \
  if (success)                                                                                                                                                                                                         \
  {                                                                                                                                                                                                                    \
    ASSERT(((value >= NBase::CInteger<type>::getMin()) && (value <= NBase::CInteger<type>::getMax())), STR("Integer number value which was inputted from stream does not fit into the system integer number bounds.")) \
    {                                                                                                                                                                                                                  \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                                             \
    }                                                                                                                                                                                                                  \
                                                                                                                                                                                                                       \
    a_rInteger = (T_Integer)value;                                                                                                                                                                                     \
  }                                                                                                                                                                                                                    \
  return NUtility::CPair<Tbool, Tuint>(success, result);                                                                                                                                                               \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream, typename T_Integer>
NUtility::CPair<Tbool, Tuint> CStreamHelper::inputInteger(const Tbool a_cPeekRead, T_Stream& a_rStream, T_Integer& a_rInteger, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  // Check T_Integer template argument constraint to be an integer number.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptInteger<T_Integer> >();

  if (a_rStream.isBinaryMode())
  {
    Tbool is_unsigned = NTraits::MIsUnsigned<T_Integer>::yes;
    if ((!is_unsigned && (sizeof(T_Integer) != sizeof(Tsint))) || (is_unsigned && (sizeof(T_Integer) != sizeof(Tuint))))
    {
      Tuint result = inputBuffer(a_cPeekRead, a_rStream, &a_rInteger, sizeof(T_Integer), 1);
      return NUtility::CPair<Tbool, Tuint>((result == sizeof(T_Integer)), result);
    }
    else
    {
      switch (is_unsigned ? a_rStream.internalGetSIntSize() : a_rStream.internalGetUIntSize())
      {
        case 1:
        {
          if (is_unsigned)
            INPUT_INTEGER(Tuint08)
          else
            INPUT_INTEGER(Tsint08)
        }
        case 2:
        {
          if (is_unsigned)
            INPUT_INTEGER(Tuint16)
          else
            INPUT_INTEGER(Tsint16)
        }
        case 4:
        {
          if (is_unsigned)
            INPUT_INTEGER(Tuint32)
          else
            INPUT_INTEGER(Tsint32)
        }
        case 8:
        {
          if (is_unsigned)
            INPUT_INTEGER(Tuint64)
          else
            INPUT_INTEGER(Tsint64)
        }
        default:
        {
          WARNING(STR("Current platform is not able to accept integer number data type from the exchange stream."));
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
    }
  }
  else
  {
    // Input result parameters.
    Tchar c = 0;
    Tschar c_ascii;
    Twchar c_unicode;
    Tbool stop = false;
    Tbool is_ascii = (a_cParseFlags & IStream::PARSE_ASCII) ? true : NString::CCharacter::isSystemASCII();
    NString::CStringASCII cache_ascii;
    NString::CStringUnicode cache_unicode;
    NUtility::CPair<Tbool, Tuint> current(false, 0);
    NUtility::CPair<Tbool, Tuint> result(false, 0);

    // Read leading space characters.
    while (!stop)
    {
      CACHE_PEEK;
      if (!stop)
      {
        // Check if character is not a space character.
        if (!NString::CCharacter(c).isSpace())
          break;
      }
    }

    // Check sign of the integer number.
    Tbool negative = false;
    if (!stop && ((c == STR('+')) || (c == STR('-'))))
    {
      negative = (c == STR('-'));

      if (negative && NTraits::MIsUnsigned<T_Integer>::yes)
      {
        WARNING(STR("Cannot apply negative sign to the input unsigned integer number."));
        negative = false;
      }

      CACHE_PEEK;
    }

    // Get radix of the integer number.
    T_Integer radix = (T_Integer)10;
    if (!stop && (c == STR('0')))
    {
      a_rInteger = (T_Integer)0;
      result.getFirst() = true;

      CACHE_CLEAR;
      if (!stop)
      {
        CACHE_PEEK;
        if (!stop)
        {
          // Check for the binary radix.
          if (c == STR('b'))
            radix = (T_Integer)2;
          // Check for the octal radix.
          else if (c == STR('o'))
            radix = (T_Integer)8;
          // Check for the hexadecimal radix.
          else if (c == STR('x'))
            radix = (T_Integer)16;

          if (radix != 10)
            CACHE_PEEK;
        }
      }
    }

    // Parse integer number.
    Tbool overflow = false;
    T_Integer min_vaule = NBase::CInteger<T_Integer>::getMin();
    T_Integer max_vaule = NBase::CInteger<T_Integer>::getMax();
    while (!stop)
    {
      Tsint number = -1;

      // Check for the group character.
      if (c == STR(','))
      {
        // Skip and do nothing.
      }
      else if ((c >= STR('0')) && (c <= STR('9')))
        number = c - STR('0');
      else if ((c >= STR('a')) && (c <= STR('f')))
        number = 10 + c - STR('a');
      else
        break;

      // Check bounds of the number.
      if ((number > 0) && ((T_Integer)number >= radix))
      {
        WARNING(STR("Cannot input digit which is greater than radix of the integer number (digit = %u, radix = %u).") COMMA (Tuint)number COMMA (Tuint)radix);
        break;
      }

      // Collect integer number.
      if (number >= 0)
      {
        CACHE_CLEAR;

        if (!overflow)
        {
          // Initialize integer number.
          if (!result.getFirst())
          {
            a_rInteger = (T_Integer)0;
            result.getFirst() = true;
          }

          if (negative)
          {
            if (a_rInteger >= (min_vaule / radix))
            {
              a_rInteger *= radix;
              if (a_rInteger >= (min_vaule + number))
                a_rInteger -= (T_Integer)number;
              else
                overflow = true;
            }
            else
              overflow = true;
          }
          else
          {
            if (a_rInteger <= (max_vaule / radix))
            {
              a_rInteger *= radix;
              if (a_rInteger <= (max_vaule - number))
                a_rInteger += (T_Integer)number;
              else
                overflow = true;
            }
            else
              overflow = true;
          }
        }
      }

      CACHE_PEEK;
    }

    if (overflow)
      WARNING(STR("Cannot input the whole integer number because of overflow."));

    CACHE_PUSH;
    return result;
  }
}
/*--------------------------------------------------------------------------*/
template <class T_Stream, typename T_Real>
NUtility::CPair<Tbool, Tuint> CStreamHelper::inputReal(const Tbool a_cPeekRead, T_Stream& a_rStream, T_Real& a_rReal, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  // Check T_Real template argument constraint to be a real number.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptReal<T_Real> >();

  if (a_rStream.isBinaryMode())
  {
    if (a_rStream.internalIsRealFloat())
    {
      Tfloat value;
      Tuint result = inputBuffer(a_cPeekRead, a_rStream, &value, sizeof(Tfloat), 1);
      Tbool success = (result == sizeof(Tfloat));
      if (success)
        a_rReal = (T_Real)value;
      return NUtility::CPair<Tbool, Tuint>(success, result);
    }
    else
    {
      Tdouble value;
      Tuint result = inputBuffer(a_cPeekRead, a_rStream, &value, sizeof(Tdouble), 1);
      Tbool success = (result == sizeof(Tdouble));
      if (success)
        a_rReal = (T_Real)value;
      return NUtility::CPair<Tbool, Tuint>(success, result);
    }
  }
  else
  {
    // Input result parameters.
    Tchar c = 0;
    Tschar c_ascii;
    Twchar c_unicode;
    Tbool stop = false;
    Tbool is_ascii = (a_cParseFlags & IStream::PARSE_ASCII) ? true : NString::CCharacter::isSystemASCII();
    NString::CStringASCII cache_ascii;
    NString::CStringUnicode cache_unicode;
    NUtility::CPair<Tbool, Tuint> current(false, 0);
    NUtility::CPair<Tbool, Tuint> result(false, 0);

    // Read leading space characters.
    while (!stop)
    {
      CACHE_PEEK;
      if (!stop)
      {
        // Check if character is not a space character.
        if (!NString::CCharacter(c).isSpace())
          break;
      }
    }

    // Check sign of the real number.
    Tbool negative = false;
    if (!stop && ((c == STR('+')) || (c == STR('-'))))
    {
      negative = (c == STR('-'));

      CACHE_PEEK;
    }

    // Parse integer part of the real number.
    Tbool overflow = false;
    while (!stop)
    {
      Tsint number = -1;

      // Check for the group character.
      if (c == STR(','))
      {
        // Skip and do nothing.
      }
      else if ((c >= STR('0')) && (c <= STR('9')))
        number = c - STR('0');
      else
        break;

      // Collect integer number.
      if (number >= 0)
      {
        CACHE_CLEAR;

        if (!overflow)
        {
          // Initialize real number.
          if (!result.getFirst())
          {
            a_rReal = (T_Real)0.0;
            result.getFirst() = true;
          }

          a_rReal = (T_Real)(10.0 * a_rReal + number);
        }
      }

      CACHE_PEEK;
    }

    // Parse fractional part of the real number.
    Tbool nan = false;
    if (!stop && (c == STR('.')))
    {
      T_Real factor = (T_Real)0.1;

      CACHE_PEEK;

      // Parse 'not a number'.
      if (!stop && (c == STR('#')) && result.getFirst() && NMath::CMath::isEqual((Treal)a_rReal, CONSTR(1.0)))
      {
        static Tchar inf[] = STR("inf");
        static Tchar qnan[] = STR("qnan");
        static Tchar snan[] = STR("snan");
        static Tuint inf_count = sizeof(inf) / sizeof(inf[0]);
        static Tuint qnan_count = sizeof(qnan) / sizeof(qnan[0]);
        static Tuint snan_count = sizeof(snan) / sizeof(snan[0]);

        Tuint count = 1;
        Tuint type = 0;

        while (!stop)
        {
          CACHE_PEEK;
          if (!stop)
          {
            if ((c == inf[count - 1]) && ((type == 1) || (type == 0)))
            {
              type = 1;
              if (++count == inf_count)
              {
                a_rReal = negative ? NMath::CMath::getNegInf() : NMath::CMath::getPosInf();
                result.getFirst() = true;
                CACHE_CLEAR;
                nan = true;
                break;
              }
            }
            else if ((c == qnan[count - 1]) && ((type == 2) || (type == 0)))
            {
              type = 2;
              if (++count == qnan_count)
              {
                a_rReal = NMath::CMath::getQNan();
                result.getFirst() = true;
                CACHE_CLEAR;
                nan = true;
                break;
              }
            }
            else if ((c == snan[count - 1]) && ((type == 3) || (type == 0)))
            {
              type = 3;
              if (++count == snan_count)
              {
                a_rReal = NMath::CMath::getSNan();
                result.getFirst() = true;
                CACHE_CLEAR;
                nan = true;
                break;
              }
            }
            else
              stop = true;
          }
        }
      }

      // Parse fractional part of the real number.
      while (!stop && !nan)
      {
        Tsint number = -1;

        if ((c >= STR('0')) && (c <= STR('9')))
          number = c - STR('0');
        else
          break;

        // Collect integer number.
        if (number >= 0)
        {
          CACHE_CLEAR;

          if (!overflow)
          {
            // Initialize real number.
            if (!result.getFirst())
            {
              a_rReal = (T_Real)0.0;
              result.getFirst() = true;
            }

            a_rReal = (T_Real)(a_rReal + factor * number);
            factor *= (T_Real)0.1;
          }
        }

        CACHE_PEEK;
      }

      // Parse exponent part of the real number.
      if (!stop && !nan && result.getFirst() && (c == STR('e')))
      {
        CACHE_PEEK;

        // Check sign of the exponent.
        Tbool exp_negative = false;
        if (!stop && ((c == STR('+')) || (c == STR('-'))))
        {
          exp_negative = (c == STR('-'));

          CACHE_PEEK;
        }

        // Parse exponent count.
        Tsint exp_count = 0;
        while (!stop)
        {
          Tsint number = -1;

          if ((c >= STR('0')) && (c <= STR('9')))
            number = c - STR('0');
          else
            break;

          // Collect exponent count.
          if (number >= 0)
          {
            CACHE_CLEAR;

            if (!overflow)
              exp_count = 10 * exp_count + number;
          }

          CACHE_PEEK;
        }

        // Final calculations.
        if (exp_count > 0)
        {
          Tsint count = exp_count;
          T_Real xexp = (T_Real)1.0;
          T_Real exp5 = (T_Real)5.0;
          while (true)
          {
            if (count & 1)
              xexp *= exp5;
            count >>= 1;
            if (count == 0)
              break;
            exp5 *= exp5;
          }

          if (exp_negative)
            a_rReal /= xexp;
          else
            a_rReal *= xexp;

          a_rReal = (T_Real)NMath::CMath::ldexp((Treal)a_rReal, (exp_negative ? -exp_count : exp_count));
        }
      }
    }

    if (negative && result.getFirst() && !nan)
      a_rReal = -a_rReal;

    if (overflow)
      WARNING(STR("Cannot input the whole real number because of overflow."));

    CACHE_PUSH;
    return result;
  }
}
/*--------------------------------------------------------------------------*/
/*!
    \def INPUT_POINTER(type)
    Input new pointer of given \a type from the binary exchange stream.
*/
#define INPUT_POINTER(type)                                                                                                                                                                        \
{                                                                                                                                                                                                  \
  type value;                                                                                                                                                                                      \
  Tuint result = inputBuffer(a_cPeekRead, a_rStream, &value, sizeof(type), 1);                                                                                                                     \
  Tbool success = (result == sizeof(type));                                                                                                                                                        \
  if (success)                                                                                                                                                                                     \
  {                                                                                                                                                                                                \
    ASSERT(((value >= (Tuint)NBase::CPtr::getMin()) && (value <= (Tuint)NBase::CPtr::getMax())), STR("Pointer value which was inputted from stream does not fit into the system pointer bounds.")) \
    {                                                                                                                                                                                              \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                         \
    }                                                                                                                                                                                              \
                                                                                                                                                                                                   \
    a_rpPointer = (Tptr)value;                                                                                                                                                                     \
  }                                                                                                                                                                                                \
  return NUtility::CPair<Tbool, Tuint>(success, result);                                                                                                                                           \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
NUtility::CPair<Tbool, Tuint> CStreamHelper::inputPointer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tptr& a_rpPointer, const Tuint a_cParseFlags/* = IStream::PARSE_DEFAULT */)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    switch (a_rStream.internalGetPtrSize())
    {
      case 1:
      {
        INPUT_POINTER(Tuint08);
      }
      case 2:
      {
        INPUT_POINTER(Tuint16);
      }
      case 4:
      {
        INPUT_POINTER(Tuint32);
      }
      case 8:
      {
        INPUT_POINTER(Tuint64);
      }
      default:
      {
        WARNING(STR("Current platform is not able to accept pointer data type from the exchange stream."));
        return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }
  }
  else
  {
    // Input result parameters.
    Tchar c = 0;
    Tschar c_ascii;
    Twchar c_unicode;
    Tbool stop = false;
    Tbool is_ascii = (a_cParseFlags & IStream::PARSE_ASCII) ? true : NString::CCharacter::isSystemASCII();
    NString::CStringASCII cache_ascii;
    NString::CStringUnicode cache_unicode;
    NUtility::CPair<Tbool, Tuint> current(false, 0);
    NUtility::CPair<Tbool, Tuint> result(false, 0);

    // Read leading space characters.
    while (!stop)
    {
      CACHE_PEEK;
      if (!stop)
      {
        // Check if character is not a space character.
        if (!NString::CCharacter(c).isSpace())
          break;
      }
    }

    // Get radix of the integer number.
    if (!stop && (c == STR('0')))
    {
      a_rpPointer = NULL;
      result.getFirst() = true;

      CACHE_CLEAR;
      if (!stop)
      {
        CACHE_PEEK;
        if (!stop)
        {
          // Check for the hexadecimal radix.
          if (c == STR('x'))
          {
            CACHE_PEEK;
            if (!stop)
            {
              // Parse pointer value.
              Tbool overflow = false;
              Tptr max_vaule = NBase::CPtr::getMax();
              while (!stop)
              {
                Tsint number = -1;
                if ((c >= STR('0')) && (c <= STR('9')))
                  number = c - STR('0');
                else if ((c >= STR('a')) && (c <= STR('f')))
                  number = 10 + c - STR('a');
                else
                  break;

                // Collect pointer value.
                if (number >= 0)
                {
                  CACHE_CLEAR;

                  if (!overflow)
                  {
                    if ((Tuint)a_rpPointer <= ((Tuint)max_vaule >> 4))
                    {
                      a_rpPointer = (Tptr)((Tuint)a_rpPointer << 4);
                      if ((Tuint)a_rpPointer <= ((Tuint)max_vaule - number))
                        a_rpPointer = (Tptr)((Tuint)a_rpPointer + number);
                      else
                        overflow = true;
                    }
                    else
                      overflow = true;
                  }
                }

                CACHE_PEEK;
              }

              if (overflow)
                WARNING(STR("Cannot input the whole integer number because of overflow."));
            }
          }
        }
      }
    }

    CACHE_PUSH;
    return result;
  }
}
/*--------------------------------------------------------------------------*/
#undef INPUT_POINTER
/*--------------------------------------------------------------------------*/
template <class T_Stream, typename T_StringConst>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputFormat(const Tbool a_cPeekRead, T_Stream& a_rStream, T_StringConst a_cpFormatString, const Tuint a_cFormatStringSize, va_list a_VariableList)
{ CALL
  // Check T_StringConst template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringConst> >();

  // Input result parameters.
  Tchar c = 0;
  Tschar c_ascii;
  Twchar c_unicode;
  Tbool stop = false;
  Tbool is_ascii = NTraits::MTraitsString<T_StringConst>::isASCII;
  NString::CStringASCII cache_ascii;
  NString::CStringUnicode cache_unicode;
  NUtility::CPair<Tbool, Tuint> current(false, 0);
  NUtility::CPair<Tbool, Tuint> result(true, 0);

  // Format string parameters.
  Tchar fc;
  Tuint size = a_cFormatStringSize;
  T_StringConst buffer = a_cpFormatString;

  // Use internal peek buffer if stream does not have its own one.
  Tuint old_peek_buffer_size = a_rStream.m_PeekBufferSize;
  Tuint old_peek_buffer_free_size = a_rStream.m_PeekBufferFreeSize;
  Tbool use_peek_buffer = (a_rStream.m_pPeekBuffer == NULL);
  if (use_peek_buffer)
  {
    static Tbyte peek_buffer[1024];
    a_rStream.m_PeekBufferSize = NAlgorithms::NCommon::countOf(peek_buffer);
    a_rStream.m_PeekBufferFreeSize = NAlgorithms::NCommon::countOf(peek_buffer);
    a_rStream.m_pPeekBuffer = peek_buffer;
  }

  // Iterate through all format string characters.
  while ((size > 0) && (result.getFirst()))
  {
    fc = (Tchar)((typename NTraits::MTraitsString<T_StringConst>::ucharacter)(*buffer));

    // Check control character.
    if (fc == STR('%'))
    {
      static const Tuint PART_BEGIN = 0;
      static const Tuint PART_FLAGS = 1;
      static const Tuint PART_WIDTH = 2;
      static const Tuint PART_VALUE = 5;
      static const Tuint PART_END   = 6;

      Tbool format_zero_terminated = false;
      Tuint format_part = PART_BEGIN;
      Tuint format_width = 0;
      Tbool format_skip = false;

      ++buffer;
      --size;

      while (size > 0)
      {
        fc = (Tchar)((typename NTraits::MTraitsString<T_StringConst>::ucharacter)(*buffer));

        // Check next control character.
        switch (fc)
        {
          case STR('-'):
          {
            if (format_part < PART_FLAGS)
            {
              format_skip = true;
              format_part = PART_FLAGS;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('*'):
          {
            if (format_part < PART_VALUE)
            {
              format_width = va_arg(a_VariableList, Tuint);
              format_part = PART_WIDTH;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('b'):
          case STR('B'):
          case STR('o'):
          case STR('O'):
          case STR('h'):
          case STR('H'):
          case STR('e'):
          case STR('E'):
          {
            if (format_part < PART_WIDTH)
              format_part = PART_WIDTH;
            else
              format_part = PART_END;
            break;
          }
          case STR('Z'):
          {
            format_zero_terminated = true;
            if (format_part < PART_WIDTH)
              format_part = PART_WIDTH;
            else
              format_part = PART_END;
            break;
          }
          case STR('s'):
          {
            Tschar temp = 0;
            current = inputChar(a_cPeekRead, a_rStream, temp);
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Tschar* ptr = va_arg(a_VariableList, Tschar*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('w'):
          {
            Twchar temp = 0;
            current = inputChar(a_cPeekRead, a_rStream, temp);
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Twchar* ptr = va_arg(a_VariableList, Twchar*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('x'):
          {
            Tchar temp = 0;
            current = inputChar(a_cPeekRead, a_rStream, temp);
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Tchar* ptr = va_arg(a_VariableList, Tchar*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('S'):
          {
            NString::CStringASCII temp;
            current = inputString(a_cPeekRead, a_rStream, temp, format_width);
            if (current.getFirst())
            {
              if (!format_skip)
              {
                if (format_zero_terminated)
                {
                  Tsstr* ptr = va_arg(a_VariableList, Tsstr*);
                  if (ptr == NULL)
                  {
                    WARNING(STR("Format argument is NULL."));
                    result.getFirst() = false;
                  }
                  NMemory::CMemory::copy(ptr, temp.getBuffer(), (temp.getSize() * sizeof(Tschar)));
                  ptr[temp.getSize()] = ASC('\0');
                }
                else
                {
                  NString::CStringASCII* ptr = va_arg(a_VariableList, NString::CStringASCII*);
                  if (ptr == NULL)
                  {
                    WARNING(STR("Format argument is NULL."));
                    result.getFirst() = false;
                  }
                  else if (!ptr->set(temp))
                    result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('W'):
          {
            NString::CStringUnicode temp;
            current = inputString(a_cPeekRead, a_rStream, temp, format_width);
            if (current.getFirst())
            {
              if (!format_skip)
              {
                if (format_zero_terminated)
                {
                  Twstr* ptr = va_arg(a_VariableList, Twstr*);
                  if (ptr == NULL)
                  {
                    WARNING(STR("Format argument is NULL."));
                    result.getFirst() = false;
                  }
                  NMemory::CMemory::copy(ptr, temp.getBuffer(), (temp.getSize() * sizeof(Twchar)));
                  ptr[temp.getSize()] = UNC('\0');
                }
                else
                {
                  NString::CStringUnicode* ptr = va_arg(a_VariableList, NString::CStringUnicode*);
                  if (ptr == NULL)
                  {
                    WARNING(STR("Format argument is NULL."));
                    result.getFirst() = false;
                  }
                  else if (!ptr->set(temp))
                    result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('X'):
          {
            NString::CString temp;
            current = inputString(a_cPeekRead, a_rStream, temp, format_width);
            if (current.getFirst())
            {
              if (!format_skip)
              {
                if (format_zero_terminated)
                {
                  Tstr* ptr = va_arg(a_VariableList, Tstr*);
                  if (ptr == NULL)
                  {
                    WARNING(STR("Format argument is NULL."));
                    result.getFirst() = false;
                  }
                  NMemory::CMemory::copy(ptr, temp.getBuffer(), (temp.getSize() * sizeof(Tchar)));
                  ptr[temp.getSize()] = STR('\0');
                }
                else
                {
                  NString::CString* ptr = va_arg(a_VariableList, NString::CString*);
                  if (ptr == NULL)
                  {
                    WARNING(STR("Format argument is NULL."));
                    result.getFirst() = false;
                  }
                  else if (!ptr->set(temp))
                    result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('i'):
          case STR('I'):
          {
            Tsint temp = 0;
            current = inputInteger(a_cPeekRead, a_rStream, temp, (is_ascii ? IStream::PARSE_ASCII : IStream::PARSE_UNICODE));
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Tsint* ptr = va_arg(a_VariableList, Tsint*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('u'):
          case STR('U'):
          {
            Tuint temp = 0;
            current = inputInteger(a_cPeekRead, a_rStream, temp, (is_ascii ? IStream::PARSE_ASCII : IStream::PARSE_UNICODE));
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Tuint* ptr = va_arg(a_VariableList, Tuint*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('f'):
          {
            Tfloat temp = 0;
            current = inputReal(a_cPeekRead, a_rStream, temp, (is_ascii ? IStream::PARSE_ASCII : IStream::PARSE_UNICODE));
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Tfloat* ptr = va_arg(a_VariableList, Tfloat*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('d'):
          {
            Tdouble temp = 0;
            current = inputReal(a_cPeekRead, a_rStream, temp, (is_ascii ? IStream::PARSE_ASCII : IStream::PARSE_UNICODE));
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Tdouble* ptr = va_arg(a_VariableList, Tdouble*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          case STR('r'):
          {
            Treal temp = 0;
            current = inputReal(a_cPeekRead, a_rStream, temp, (is_ascii ? IStream::PARSE_ASCII : IStream::PARSE_UNICODE));
            if (current.getFirst())
            {
              if (!format_skip)
              {
                Treal* ptr = va_arg(a_VariableList, Treal*);
                if (ptr != NULL)
                  *ptr = temp;
                else
                {
                  WARNING(STR("Format argument is NULL."));
                  result.getFirst() = false;
                }
              }
              result.getSecond() += current.getSecond();
            }
            else
            {
              result.getFirst() = false;
              result.getSecond() += current.getSecond();
            }
            format_part = PART_VALUE;
            break;
          }
          default:
          {
            if ((fc >= STR('0')) && (fc <= STR('9')))
            {
              // Get format width or precession width.
              if (format_part < PART_VALUE)
              {
                format_width *= 10;
                format_width += fc - STR('0');
              }
              else
                format_part = PART_END;
            }
            else
              format_part = PART_END;
            break;
          }
        }

        if (format_part == PART_END)
        {
          // Input regular character.
          CACHE_PEEK;
          if (stop || (fc != c))
          {
            result.getFirst() = false;
            break;
          }
          else
          {
            CACHE_CLEAR;
            break;
          }
        }
        else if ((format_part == PART_VALUE) || (size == 0))
          break;

        ++buffer;
        --size;
      }
    }
    else
    {
      // Peek next character.
      CACHE_PEEK;
      if (stop || (fc != c))
      {
        result.getFirst() = false;
        break;
      }
      else
      {
        CACHE_CLEAR;
      }
    }

    if (size > 0)
    {
      ++buffer;
      --size;
    }
  }

  CACHE_PUSH;

  // Restore peek buffer if stream does not have its own one.
  if (use_peek_buffer)
  {
    a_rStream.m_PeekBufferSize = old_peek_buffer_size;
    a_rStream.m_PeekBufferFreeSize = old_peek_buffer_free_size;
    a_rStream.m_pPeekBuffer = NULL;
  }

  return result;
}
/*--------------------------------------------------------------------------*/
#undef CACHE_PEEK
#undef CACHE_PUSH
#undef CACHE_CLEAR
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputLineEndASCII(const Tbool a_cPeekRead, T_Stream& a_rStream)
{ CALL
  Tschar c[2];
  Tuint count = 0;
  NUtility::CPair<Tbool, Tuint> result(true, 0);
  NUtility::CPair<Tbool, Tuint> temp(false, 0);

  // Get first end line character.
  temp = inputChar(a_cPeekRead, a_rStream, c[0]);
  if (temp.getFirst())
  {
    ++count;
    result.getSecond() += temp.getSecond();

    // Check if character is an end line character.
    if ((c[0] == ASC('\0')) || (c[0] == ASC('\n')))
      return result;

    // Check if character is a part of the end line character.
    if (c[0] == ASC('\r'))
    {
      temp = inputChar(a_cPeekRead, a_rStream, c[1]);
      if (temp.getFirst())
      {
        ++count;
        result.getSecond() += temp.getSecond();

        // Check if character is an end line character.
        if ((c[1] == ASC('\0')) || (c[1] == ASC('\n')))
          return result;
      }
    }
  }

  result.getFirst() = false;

  // Try to push the read characters back into the reader.
  if (!a_cPeekRead)
    result.getSecond() -= outputBuffer(a_rStream, c, count);

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputLineEndUnicode(const Tbool a_cPeekRead, T_Stream& a_rStream)
{ CALL
  Twchar c[2];
  Tuint count = 0;
  NUtility::CPair<Tbool, Tuint> result(true, 0);
  NUtility::CPair<Tbool, Tuint> temp(false, 0);

  // Get first end line character.
  temp = inputChar(a_cPeekRead, a_rStream, c[0]);
  if (temp.getFirst())
  {
    ++count;
    result.getSecond() += temp.getSecond();

    // Check if character is an end line character.
    if ((c[0] == UNC('\0')) || (c[0] == UNC('\n')))
      return result;

    // Check if character is a part of the end line character.
    if (c[0] == UNC('\r'))
    {
      temp = inputChar(a_cPeekRead, a_rStream, c[1]);
      if (temp.getFirst())
      {
        ++count;
        result.getSecond() += temp.getSecond();

        // Check if character is an end line character.
        if ((c[1] == UNC('\0')) || (c[1] == UNC('\n')))
          return result;
      }
    }
  }

  result.getFirst() = false;

  // Try to push the read characters back into the reader.
  if (!a_cPeekRead)
    result.getSecond() -= outputBuffer(a_rStream, c, count);

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputToLineEndASCII(const Tbool a_cPeekRead, T_Stream& a_rStream)
{ CALL
  Tschar c;
  NUtility::CPair<Tbool, Tuint> result(true, 0);
  NUtility::CPair<Tbool, Tuint> temp(false, 0);

  while (result.getFirst())
  {
    // Get next character.
    temp = inputChar(a_cPeekRead, a_rStream, c);
    if (temp.getFirst())
    {
      result.getSecond() += temp.getSecond();

      // Check if character is an end line character.
      if ((c == ASC('\0')) || (c == ASC('\n')))
        return result;

      // Check if character is a part of the end line character.
      if (c == ASC('\r'))
      {
        temp = inputChar(a_cPeekRead, a_rStream, c);
        if (temp.getFirst())
        {
          result.getSecond() += temp.getSecond();

          // Check if character is an end line character.
          if ((c == ASC('\0')) || (c == ASC('\n')))
            return result;
        }
        else
          result.getFirst() = false;
      }
    }
    else
      result.getFirst() = false;
  }

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::inputToLineEndUnicode(const Tbool a_cPeekRead, T_Stream& a_rStream)
{ CALL
  Twchar c;
  NUtility::CPair<Tbool, Tuint> result(true, 0);
  NUtility::CPair<Tbool, Tuint> temp(false, 0);

  while (result.getFirst())
  {
    // Get next character.
    temp = inputChar(a_cPeekRead, a_rStream, c);
    if (temp.getFirst())
    {
      result.getSecond() += temp.getSecond();

      // Check if character is an end line character.
      if ((c == UNC('\0')) || (c == UNC('\n')))
        return result;

      // Check if character is a part of the end line character.
      if (c == UNC('\r'))
      {
        temp = inputChar(a_cPeekRead, a_rStream, c);
        if (temp.getFirst())
        {
          result.getSecond() += temp.getSecond();

          // Check if character is an end line character.
          if ((c == UNC('\0')) || (c == UNC('\n')))
            return result;
        }
        else
          result.getFirst() = false;
      }
    }
    else
      result.getFirst() = false;
  }

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline Tuint CStreamHelper::outputBuffer(T_Stream& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IReader& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rStream.pushBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IWriter& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rStream.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline Tuint CStreamHelper::outputBuffer(T_Stream& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSingleSize);
  IGNORE_UNUSED(a_cCount);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IReader& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  return a_rStream.pushBuffer(a_cpBuffer, a_cSingleSize, a_cCount);
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IWriter& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount)
{ CALL
  return a_rStream.writeBuffer(a_cpBuffer, a_cSingleSize, a_cCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline Tuint CStreamHelper::outputBuffer(T_Stream& a_rStream, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IReader& a_rStream, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rStream.pushBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IWriter& a_rStream, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rStream.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline Tuint CStreamHelper::outputBuffer(T_Stream& a_rStream, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_rStream);
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  ERROR(STR("Stream helper could be used only with IReader or IWriter interface."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IReader& a_rStream, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rStream.pushBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint CStreamHelper::outputBuffer(IWriter& a_rStream, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rStream.writeBuffer(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
/*!
    \def OUTPUT_SCHAR(type)
    Output character of given \a type into the binary exchange stream.
*/
#define OUTPUT_SCHAR(type)                                                                                                                                                                                                                     \
{                                                                                                                                                                                                                                              \
  ASSERT(((a_cCharacter >= NBase::CInteger<type>::getMin()) && (a_cCharacter <= NBase::CInteger<type>::getMax())), STR("Character value which is outputted into the exchange stream does not fit into the exchange stream character bounds.")) \
  {                                                                                                                                                                                                                                            \
    return NUtility::CPair<Tbool, Tuint>(false, 0);                                                                                                                                                                                            \
  }                                                                                                                                                                                                                                            \
                                                                                                                                                                                                                                               \
  type value = (type)a_cCharacter;                                                                                                                                                                                                             \
  Tuint result = outputBuffer(a_rStream, &value, sizeof(type), 1);                                                                                                                                                                             \
  return NUtility::CPair<Tbool, Tuint>((result == sizeof(type)), result);                                                                                                                                                                      \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputChar(T_Stream& a_rStream, const Tschar a_cCharacter)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    switch (a_rStream.internalGetSCharSize())
    {
      case 1:
      {
        #if defined(__SCHAR_S_ASCII__)
        OUTPUT_SCHAR(Tsint08);
        #else
        OUTPUT_SCHAR(Tuint08);
        #endif
      }
      case 2:
      {
        #if defined(__SCHAR_S_ASCII__)
        OUTPUT_SCHAR(Tsint16);
        #else
        OUTPUT_SCHAR(Tuint16);
        #endif
      }
      case 4:
      {
        #if defined(__SCHAR_S_ASCII__)
        OUTPUT_SCHAR(Tsint32);
        #else
        OUTPUT_SCHAR(Tuint32);
        #endif
      }
      case 8:
      {
        #if defined(__SCHAR_S_ASCII__)
        OUTPUT_SCHAR(Tsint64);
        #else
        OUTPUT_SCHAR(Tuint64);
        #endif
      }
      default:
      {
        WARNING(STR("Current platform is not able to place character data type into the exchange stream."));
        return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }
  }
  else
  {
    Tuint result = outputBuffer(a_rStream, &a_cCharacter, 1);
    return NUtility::CPair<Tbool, Tuint>((result == 1), result);
  }
}
/*--------------------------------------------------------------------------*/
#undef OUTPUT_SCHAR
/*--------------------------------------------------------------------------*/
/*!
    \def OUTPUT_WCHAR(type)
    Output wide character of given \a type into the binary exchange stream.
*/
#define OUTPUT_WCHAR(type)                                                                                                                                                                                                                               \
{                                                                                                                                                                                                                                                        \
  ASSERT(((a_cCharacter >= NBase::CInteger<type>::getMin()) && (a_cCharacter <= NBase::CInteger<type>::getMax())), STR("Wide character value which is outputted into the exchange stream does not fit into the exchange stream wide character bounds.")) \
  {                                                                                                                                                                                                                                                      \
    return NUtility::CPair<Tbool, Tuint>(false, 0);                                                                                                                                                                                                      \
  }                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                         \
  type value = (type)a_cCharacter;                                                                                                                                                                                                                       \
  Tuint result = outputBuffer(a_rStream, &value, sizeof(type), 1);                                                                                                                                                                                       \
  return NUtility::CPair<Tbool, Tuint>((result == sizeof(type)), result);                                                                                                                                                                                \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputChar(T_Stream& a_rStream, const Twchar a_cCharacter)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    switch (a_rStream.internalGetWCharSize())
    {
      case 1:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        OUTPUT_WCHAR(Tsint08);
        #else
        OUTPUT_WCHAR(Tuint08);
        #endif
      }
      case 2:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        OUTPUT_WCHAR(Tsint16);
        #else
        OUTPUT_WCHAR(Tuint16);
        #endif
      }
      case 4:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        OUTPUT_WCHAR(Tsint32);
        #else
        OUTPUT_WCHAR(Tuint32);
        #endif
      }
      case 8:
      {
        #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
        OUTPUT_WCHAR(Tsint64);
        #else
        OUTPUT_WCHAR(Tuint64);
        #endif
      }
      default:
      {
        WARNING(STR("Current platform is not able to place wide character data type into the exchange stream."));
        return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }
  }
  else
  {
    Tuint result = outputBuffer(a_rStream, &a_cCharacter, 1);
    return NUtility::CPair<Tbool, Tuint>((result == 1), result);
  }
}
/*--------------------------------------------------------------------------*/
#undef OUTPUT_WCHAR
/*--------------------------------------------------------------------------*/
/*!
    \def OUTPUT_SCHAR_BUFFER(type)
    Output character \a buffer of given \a size and \a type into the binary exchange stream.
*/
#define OUTPUT_SCHAR_BUFFER(type, buffer, size)                                                                                                                                                                                            \
{                                                                                                                                                                                                                                          \
  Tcsstr str = buffer;                                                                                                                                                                                                                     \
  Tuint result = 0;                                                                                                                                                                                                                        \
  Tuint count = size;                                                                                                                                                                                                                      \
  while (count-- > 0)                                                                                                                                                                                                                      \
  {                                                                                                                                                                                                                                        \
    ASSERT(((*str >= NBase::CInteger<type>::getMin()) && (*str <= NBase::CInteger<type>::getMax())), STR("Character value which is outputted into the exchange stream does not fit into the exchange stream character bounds."))           \
    {                                                                                                                                                                                                                                      \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                                                                 \
    }                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                           \
    type value = (type)(*str);                                                                                                                                                                                                             \
    if (outputBuffer(a_rStream, &value, sizeof(type), 1) == sizeof(type))                                                                                                                                                                  \
    {                                                                                                                                                                                                                                      \
      ++str;                                                                                                                                                                                                                               \
      result += sizeof(type);                                                                                                                                                                                                              \
    }                                                                                                                                                                                                                                      \
    else                                                                                                                                                                                                                                   \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                                                                 \
  }                                                                                                                                                                                                                                        \
  return NUtility::CPair<Tbool, Tuint>(true, result);                                                                                                                                                                                      \
}
/*--------------------------------------------------------------------------*/
/*!
    \def OUTPUT_WCHAR_BUFFER(type)
    Output wide character \a buffer of given \a size and \a type into the binary exchange stream.
*/
#define OUTPUT_WCHAR_BUFFER(type, buffer, size)                                                                                                                                                                                            \
{                                                                                                                                                                                                                                          \
  Tcwstr str = buffer;                                                                                                                                                                                                                     \
  Tuint result = 0;                                                                                                                                                                                                                        \
  Tuint count = size;                                                                                                                                                                                                                      \
  while (count-- > 0)                                                                                                                                                                                                                      \
  {                                                                                                                                                                                                                                        \
    ASSERT(((*str >= NBase::CInteger<type>::getMin()) && (*str <= NBase::CInteger<type>::getMax())), STR("Wide character value which is outputted into the exchange stream does not fit into the exchange stream wide character bounds.")) \
    {                                                                                                                                                                                                                                      \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                                                                 \
    }                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                           \
    type value = (type)(*str);                                                                                                                                                                                                             \
    if (outputBuffer(a_rStream, &value, sizeof(type), 1) == sizeof(type))                                                                                                                                                                  \
    {                                                                                                                                                                                                                                      \
      ++str;                                                                                                                                                                                                                               \
      result += sizeof(type);                                                                                                                                                                                                              \
    }                                                                                                                                                                                                                                      \
    else                                                                                                                                                                                                                                   \
      return NUtility::CPair<Tbool, Tuint>(false, result);                                                                                                                                                                                 \
  }                                                                                                                                                                                                                                        \
  return NUtility::CPair<Tbool, Tuint>(true, result);                                                                                                                                                                                      \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputString(T_Stream& a_rStream, const Tcsstr a_cpString)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpString);
    if (sizeof(Tschar) == a_rStream.internalGetSCharSize())
    {
      Tuint result = outputBuffer(a_rStream, a_cpString, sizeof(Tschar), length);
      return NUtility::CPair<Tbool, Tuint>((result == (sizeof(Tschar) * length)), result);
    }
    else
    {
      switch (a_rStream.internalGetSCharSize())
      {
        case 1:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint08, a_cpString, length);
          #else
          OUTPUT_SCHAR_BUFFER(Tuint08, a_cpString, length);
          #endif
        }
        case 2:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint16, a_cpString, length);
          #else
          OUTPUT_SCHAR_BUFFER(Tuint16, a_cpString, length);
          #endif
        }
        case 4:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint32, a_cpString, length);
          #else
          OUTPUT_SCHAR_BUFFER(Tuint32, a_cpString, length);
          #endif
        }
        case 8:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint64, a_cpString, length);
          #else
          OUTPUT_SCHAR_BUFFER(Tuint64, a_cpString, length);
          #endif
        }
        default:
        {
          WARNING(STR("Current platform is not able to place character data type into the exchange stream."));
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
    }
  }
  else
  {
    Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpString);
    Tuint result = outputBuffer(a_rStream, a_cpString, length);
    return NUtility::CPair<Tbool, Tuint>((result == length), result);
  }
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputString(T_Stream& a_rStream, const Tcwstr a_cpString)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpString);
    if (sizeof(Twchar) == a_rStream.internalGetWCharSize())
    {
      Tuint result = outputBuffer(a_rStream, a_cpString, sizeof(Twchar), length);
      return NUtility::CPair<Tbool, Tuint>((result == (sizeof(Twchar) * length)), result);
    }
    else
    {
      switch (a_rStream.internalGetWCharSize())
      {
        case 1:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint08, a_cpString, length);
          #else
          OUTPUT_WCHAR_BUFFER(Tuint08, a_cpString, length);
          #endif
        }
        case 2:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint16, a_cpString, length);
          #else
          OUTPUT_WCHAR_BUFFER(Tuint16, a_cpString, length);
          #endif
        }
        case 4:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint32, a_cpString, length);
          #else
          OUTPUT_WCHAR_BUFFER(Tuint32, a_cpString, length);
          #endif
        }
        case 8:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint64, a_cpString, length);
          #else
          OUTPUT_WCHAR_BUFFER(Tuint64, a_cpString, length);
          #endif
        }
        default:
        {
          WARNING(STR("Current platform is not able to place wide character data type into the exchange stream."));
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
    }
  }
  else
  {
    Tuint length = NAlgorithms::NString::NBuffer::strLen(a_cpString);
    Tuint result = outputBuffer(a_rStream, a_cpString, length);
    return NUtility::CPair<Tbool, Tuint>((result == length), result);
  }
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputString(T_Stream& a_rStream, const NString::CStringASCII& a_crString)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    if (sizeof(Tschar) == a_rStream.internalGetSCharSize())
    {
      Tuint result = outputBuffer(a_rStream, a_crString.getBuffer(), sizeof(Tschar), a_crString.getSize());
      return NUtility::CPair<Tbool, Tuint>((result == (sizeof(Tschar) * a_crString.getSize())), result);
    }
    else
    {
      switch (a_rStream.internalGetSCharSize())
      {
        case 1:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint08, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_SCHAR_BUFFER(Tuint08, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        case 2:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint16, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_SCHAR_BUFFER(Tuint16, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        case 4:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint32, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_SCHAR_BUFFER(Tuint32, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        case 8:
        {
          #if defined(__SCHAR_S_ASCII__)
          OUTPUT_SCHAR_BUFFER(Tsint64, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_SCHAR_BUFFER(Tuint64, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        default:
        {
          WARNING(STR("Current platform is not able to place character data type into the exchange stream."));
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
    }
  }
  else
  {
    Tuint result = outputBuffer(a_rStream, a_crString.getBuffer(), a_crString.getSize());
    return NUtility::CPair<Tbool, Tuint>((result == a_crString.getSize()), result);
  }
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputString(T_Stream& a_rStream, const NString::CStringUnicode& a_crString)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    if (sizeof(Twchar) == a_rStream.internalGetWCharSize())
    {
      Tuint result = outputBuffer(a_rStream, a_crString.getBuffer(), sizeof(Twchar), a_crString.getSize());
      return NUtility::CPair<Tbool, Tuint>((result == (sizeof(Twchar) * a_crString.getSize())), result);
    }
    else
    {
      switch (a_rStream.internalGetWCharSize())
      {
        case 1:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint08, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_WCHAR_BUFFER(Tuint08, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        case 2:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint16, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_WCHAR_BUFFER(Tuint16, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        case 4:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint32, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_WCHAR_BUFFER(Tuint32, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        case 8:
        {
          #if (defined(__WCHAR_S_UCS2__) || defined(__WCHAR_S_UCS4__))
          OUTPUT_WCHAR_BUFFER(Tsint64, a_crString.getBuffer(), a_crString.getSize());
          #else
          OUTPUT_WCHAR_BUFFER(Tuint64, a_crString.getBuffer(), a_crString.getSize());
          #endif
        }
        default:
        {
          WARNING(STR("Current platform is not able to place wide character data type into the exchange stream."));
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
    }
  }
  else
  {
    Tuint result = outputBuffer(a_rStream, a_crString.getBuffer(), a_crString.getSize());
    return NUtility::CPair<Tbool, Tuint>((result == a_crString.getSize()), result);
  }
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputString(T_Stream& a_rStream, const NString::CSystemString& a_crString)
{ CALL
  return outputString(a_rStream, NString::CString(a_crString));
}
/*--------------------------------------------------------------------------*/
#undef OUTPUT_SCHAR_BUFFER
#undef OUTPUT_WCHAR_BUFFER
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputBool(T_Stream& a_rStream, const Tbool a_cBoolean, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    Tbyte b = (a_cBoolean ? 1 : 0);
    Tuint result = outputBuffer(a_rStream, &b, sizeof(Tbyte), 1);
    return NUtility::CPair<Tbool, Tuint>((result == sizeof(Tbyte)), result);
  }
  else
  {
    // Check format flags.
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LOWER) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_UPPER) ? 1 : 0) <= 1), STR("Format flags FORMAT_LOWER and FORMAT_UPPER cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LALIGN) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_RALIGN) ? 1 : 0) <= 1), STR("Format flags FORMAT_LALIGN and FORMAT_RALIGN cannot be specified together."));

    NString::CString result;

    // Insert boolean number value.
    if (a_cFormatFlags & IStream::FORMAT_DECIMAL)
    {
      if (!result.insertFirst(a_cBoolean ? STR('1') : STR('0')))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }
    else if (a_cFormatFlags & IStream::FORMAT_UPPER)
    {
      if (!result.insertFirst(a_cBoolean ? STR("TRUE") : STR("FALSE")))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }
    else
    {
      if (!result.insertFirst(a_cBoolean ? STR("true") : STR("false")))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    // Insert alignment symbols.
    Tuint index;
    Tuint width = (a_cWidth > result.getSize() ? a_cWidth - result.getSize() : 0);
    if (a_cFormatFlags & IStream::FORMAT_LALIGN)
      index = result.getSize();
    else
      index = 0;
    while (width-- > 0)
    {
      if (!result.insertIndex(index, STR(' ')))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    if ((a_cFormatFlags & IStream::FORMAT_ASCII) ? true : NString::CCharacter::isSystemASCII())
      return outputString(a_rStream, NString::CStringASCII(result));
    else
      return outputString(a_rStream, NString::CStringUnicode(result));
  }
}
/*--------------------------------------------------------------------------*/
/*!
    \def OUTPUT_INTEGER(type)
    Output integer number of given \a type into the binary exchange stream.
*/
#define OUTPUT_INTEGER(type, srctype)                                                                                                                                                                                                                         \
{                                                                                                                                                                                                                                                    \
  ASSERT((((srctype)a_cInteger >= NBase::CInteger<type>::getMin()) && ((srctype)a_cInteger <= NBase::CInteger<type>::getMax())), STR("Integer number value which is outputted into the exchange stream does not fit into the exchange stream integer number bounds.")) \
  {                                                                                                                                                                                                                                                  \
    return NUtility::CPair<Tbool, Tuint>(false, 0);                                                                                                                                                                                                  \
  }                                                                                                                                                                                                                                                  \
                                                                                                                                                                                                                                                     \
  type value = (type)a_cInteger;                                                                                                                                                                                                                     \
  Tuint result = outputBuffer(a_rStream, &value, sizeof(type), 1);                                                                                                                                                                                   \
  return NUtility::CPair<Tbool, Tuint>((result == sizeof(type)), result);                                                                                                                                                                            \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream, typename T_Integer>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputInteger(T_Stream& a_rStream, const T_Integer a_cInteger, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cRadix/* = 0 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  // Check T_Integer template argument constraint to be an integer number.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptInteger<T_Integer> >();

  if (a_rStream.isBinaryMode())
  {
    Tbool is_unsigned = NTraits::MIsUnsigned<T_Integer>::yes;
    if ((!is_unsigned && (sizeof(T_Integer) != sizeof(Tsint))) || (is_unsigned && (sizeof(T_Integer) != sizeof(Tuint))))
    {
      Tuint result = outputBuffer(a_rStream, &a_cInteger, sizeof(T_Integer), 1);
      return NUtility::CPair<Tbool, Tuint>((result == sizeof(T_Integer)), result);
    }
    else
    {
      switch (is_unsigned ? a_rStream.internalGetSIntSize() : a_rStream.internalGetUIntSize())
      {
        case 1:
        {
          if (is_unsigned)
            OUTPUT_INTEGER(Tuint08, typename NTraits::MGetUnsigned<T_Integer>::type)
          else
            OUTPUT_INTEGER(Tsint08, typename NTraits::MGetSigned<T_Integer>::type)
        }
        case 2:
        {
          if (is_unsigned)
            OUTPUT_INTEGER(Tuint16, typename NTraits::MGetUnsigned<T_Integer>::type)
          else
            OUTPUT_INTEGER(Tsint16, typename NTraits::MGetSigned<T_Integer>::type)
        }
        case 4:
        {
          if (is_unsigned)
            OUTPUT_INTEGER(Tuint32, typename NTraits::MGetUnsigned<T_Integer>::type)
          else
            OUTPUT_INTEGER(Tsint32, typename NTraits::MGetSigned<T_Integer>::type)
        }
        case 8:
        {
          if (is_unsigned)
            OUTPUT_INTEGER(Tuint64, typename NTraits::MGetUnsigned<T_Integer>::type)
          else
            OUTPUT_INTEGER(Tsint64, typename NTraits::MGetSigned<T_Integer>::type)
        }
        default:
        {
          WARNING(STR("Current platform is not able to place integer number data type into the exchange stream."));
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
    }
  }
  else
  {
    // Check format flags.
    ASSERT((((a_cFormatFlags & IStream::FORMAT_PLUS) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_SPACE) ? 1 : 0) <= 1), STR("Format flags FORMAT_PLUS and FORMAT_SPACE cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_binary) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_BINARY) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_octal) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_OCTAL) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_DECIMAL) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_hex) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_HEX) ? 1 : 0) <= 1), STR("Format flags FORMAT_binary, FORMAT_BINARY, FORMAT_octal, FORMAT_OCTAL, FORMAT_DECIMAL, FORMAT_hex and FORMAT_HEX cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LOWER) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_UPPER) ? 1 : 0) <= 1), STR("Format flags FORMAT_LOWER and FORMAT_UPPER cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LALIGN) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_RALIGN) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_FILL_0) ? 1 : 0) <= 1), STR("Format flags FORMAT_LALIGN, FORMAT_RALIGN and FORMAT_FILL_0 cannot be specified together."));
    ASSERT((!(a_cFormatFlags & IStream::FORMAT_GROUPS) || (a_cFormatFlags & IStream::FORMAT_DECIMAL) || (a_cRadix == 10)), STR("Format flag FORMAT_GROUPS should be specified only with FORMAT_DECIMAL flag."));
    // Check radix range.
    ASSERT(((a_cRadix >= 2) || (((a_cFormatFlags & IStream::FORMAT_binary) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_BINARY) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_octal) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_OCTAL) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_DECIMAL) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_hex) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_HEX) ? 1 : 0) >= 1)), STR("Cannot output integer number with radix which is less than 2 (radix = %u).") COMMA a_cRadix)
    {
      return NUtility::CPair<Tbool, Tuint>(false, 0);
    }
    ASSERT(((a_cRadix <= 36) || (((a_cFormatFlags & IStream::FORMAT_binary) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_BINARY) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_octal) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_OCTAL) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_DECIMAL) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_hex) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_HEX) ? 1 : 0) >= 1)), STR("Cannot output integer number with radix which is greater than 36 (radix = %u).") COMMA a_cRadix)
    {
      return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    NString::CString result;

    // Insert sign of the integer number.
    T_Integer zero = 0;
    if (a_cInteger < zero)
    {
       if (!result.insertFirst(STR('-')))
         return NUtility::CPair<Tbool, Tuint>(false, 0);
    }
    else
    {
      if (a_cFormatFlags & IStream::FORMAT_PLUS)
      {
        if (!result.insertFirst(STR('+')))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else
        if (a_cFormatFlags & IStream::FORMAT_SPACE)
          if (!result.insertFirst(STR(' ')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    // Index radix symbols of the integer number.
    T_Integer radix = (T_Integer)NAlgorithms::NCommon::min(a_cRadix, CONSTU(36));
    if (radix < 2)
    {
      if (a_cFormatFlags & IStream::FORMAT_binary)
      {
        radix = (T_Integer)2;
        if (!result.insertLast(STR("0b")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else if (a_cFormatFlags & IStream::FORMAT_BINARY)
      {
        radix = (T_Integer)2;
        if (!result.insertLast(STR("0B")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else if (a_cFormatFlags & IStream::FORMAT_octal)
      {
        radix = (T_Integer)8;
        if (!result.insertLast(STR("0o")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else if (a_cFormatFlags & IStream::FORMAT_OCTAL)
      {
        radix = (T_Integer)8;
        if (!result.insertLast(STR("0O")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else if (a_cFormatFlags & IStream::FORMAT_DECIMAL)
      {
        radix = (T_Integer)10;
      }
      else if (a_cFormatFlags & IStream::FORMAT_hex)
      {
        radix = (T_Integer)16;
        if (!result.insertLast(STR("0x")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else if (a_cFormatFlags & IStream::FORMAT_HEX)
      {
        radix = (T_Integer)16;
        if (!result.insertLast(STR("0X")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }

    // Insert integer number.
    Tuint index = result.getSize();
    typename NTraits::MGetUnsigned<T_Integer>::type div_base = (a_cInteger < zero) ? -a_cInteger : a_cInteger;
    if (div_base == 0)
      if (!result.insertIndex(index, STR('0')))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    while (div_base > 0)
    {
      typename NTraits::MGetUnsigned<T_Integer>::type mod_base = div_base % radix;
      if (mod_base > 9)
      {
        if (!result.insertIndex(index, (Tchar)(((a_cFormatFlags & IStream::FORMAT_UPPER) ? STR('A') : STR('a')) + mod_base - 10)))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else
      {
        if (!result.insertIndex(index, (Tchar)(STR('0') + mod_base)))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      div_base /= radix;
    }

    // Insert thousands group symbols.
    Tuint group = 0;
    if ((a_cFormatFlags & IStream::FORMAT_GROUPS) && (radix == 10))
    {
      for (Tuint i = result.getSize() - 1; i > index; --i)
      {
        if (++group == 3)
        {
          group = 0;
          if (!result.insertIndex(i, STR(',')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
      ++group;
    }

    // Insert alignment symbols.
    Tuint width = (a_cWidth > result.getSize() ? a_cWidth - result.getSize() : 0);
    if (a_cFormatFlags & IStream::FORMAT_FILL_0)
      index = index;
    else if (a_cFormatFlags & IStream::FORMAT_LALIGN)
      index = result.getSize();
    else
      index = 0;
    while (width-- > 0)
    {
      if (a_cFormatFlags & IStream::FORMAT_FILL_0)
      {
        if (((a_cFormatFlags & IStream::FORMAT_GROUPS) && (radix == 10)) && (++group == 4))
        {
          if (width > 0)
          {
            group = 0;
            if (!result.insertIndex(index, STR(',')))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
          }
          else
            if (!result.insertFirst(STR(' ')))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
        else
          if (!result.insertIndex(index, STR('0')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else
      {
        if (!result.insertIndex(index, STR(' ')))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }

    if ((a_cFormatFlags & IStream::FORMAT_ASCII) ? true : NString::CCharacter::isSystemASCII())
      return outputString(a_rStream, NString::CStringASCII(result));
    else
      return outputString(a_rStream, NString::CStringUnicode(result));
  }
}
/*--------------------------------------------------------------------------*/
#undef OUTPUT_INTEGER
/*--------------------------------------------------------------------------*/
template <class T_Stream, typename T_Real>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputReal(T_Stream& a_rStream, const T_Real a_cReal, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cPrecision/* = 6 */, const Tuint a_cWidth/* = 0 */)
{ CALL
  // Check T_Real template argument constraint to be a real number.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptReal<T_Real> >();

  if (a_rStream.isBinaryMode())
  {
    if (a_rStream.internalIsRealFloat())
    {
      Tfloat value = (Tfloat)a_cReal;
      Tuint result = outputBuffer(a_rStream, &value, sizeof(Tfloat), 1);
      return NUtility::CPair<Tbool, Tuint>((result == sizeof(Tfloat)), result);
    }
    else
    {
      Tdouble value = (Tdouble)a_cReal;
      Tuint result = outputBuffer(a_rStream, &value, sizeof(Tdouble), 1);
      return NUtility::CPair<Tbool, Tuint>((result == sizeof(Tdouble)), result);
    }
  }
  else
  {
    // Check format flags.
    ASSERT((((a_cFormatFlags & IStream::FORMAT_PLUS) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_SPACE) ? 1 : 0) <= 1), STR("Format flags FORMAT_PLUS and FORMAT_SPACE cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LOWER) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_UPPER) ? 1 : 0) <= 1), STR("Format flags FORMAT_LOWER and FORMAT_UPPER cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LALIGN) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_RALIGN) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_FILL_0) ? 1 : 0) <= 1), STR("Format flags FORMAT_LALIGN, FORMAT_RALIGN and FORMAT_FILL_0 cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_DOT) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_exp) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_EXP) ? 1 : 0) <= 1), STR("Format flags FORMAT_DOT, FORMAT_exp and FORMAT_EXP cannot be specified together."));
    ASSERT((!(a_cFormatFlags & IStream::FORMAT_FILL_0) || (a_cFormatFlags & IStream::FORMAT_DOT)), STR("Format flag FORMAT_FILL_0 should be specified only with FORMAT_DOT flag."));
    ASSERT((!(a_cFormatFlags & IStream::FORMAT_GROUPS) || (a_cFormatFlags & IStream::FORMAT_DOT)), STR("Format flag FORMAT_GROUPS should be specified only with FORMAT_DOT flag."));

    NString::CString result;

    // Check state of the real number.
    Tbool nan = false;
    switch (NMath::CMath::getNumberState((Treal)a_cReal))
    {
      case NMath::CMath::e_NORMAL:
        break;
      case NMath::CMath::e_POSINF:
      {
        if (!result.insertFirst(STR("1.#INF")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        nan = true;
        break;
      }
      case NMath::CMath::e_NEGINF:
      {
        if (!result.insertFirst(STR("-1.#INF")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        nan = true;
        break;
      }
      case NMath::CMath::e_QNAN:
      {
        if (!result.insertFirst(STR("1.#QNAN")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        nan = true;
        break;
      }
      case NMath::CMath::e_SNAN:
      {
        if (!result.insertFirst(STR("1.#SNAN")))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        nan = true;
        break;
      }
    }

    // Output normal real number.
    if (!nan)
    {
      // Insert sign of the real number.
      if (a_cReal < 0.0)
      {
         if (!result.insertFirst(STR('-')))
           return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else
      {
        if (a_cFormatFlags & IStream::FORMAT_PLUS)
        {
          if (!result.insertFirst(STR('+')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
        else
          if (a_cFormatFlags & IStream::FORMAT_SPACE)
            if (!result.insertFirst(STR(' ')))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
      }

      // Insert real number: integer part.
      Tsint exponent = 0;
      Tuint index = result.getSize();
      T_Real number = NAlgorithms::NNumeric::absolute(a_cReal);
      T_Real integer, frac = NMath::CMath::modf(number, integer);
      while (integer > 0.0)
      {
        number = NMath::CMath::modf((T_Real)(integer * 0.1), integer);
        if (!result.insertIndex(index, (Tchar)(STR('0') + (number + 0.01) * 10.0)))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        // Collect exponent value.
        ++exponent;
      }

      // Insert real number: fraction part
      if ((a_cFormatFlags & IStream::FORMAT_exp) || (a_cFormatFlags & IStream::FORMAT_EXP))
      {
        Tuint precision_width = NAlgorithms::NCommon::max(CONSTU(1), a_cPrecision);

        // Correct real part for the given precision.
        if ((Tuint)exponent >= precision_width + 1)
        {
          Tuint min_exponent = index + precision_width + 1;

          // Round the real number if necessary.
          if (((min_exponent < result.getSize()) && (result[min_exponent] >= STR('5')) && (result[min_exponent - 1] < STR('9'))) || (((min_exponent == result.getSize())) && (frac >= 0.5)))
            result[min_exponent - 1] += 1;
          result.resize(min_exponent);

          // Required precision is get.
          precision_width = 0;
        }

        // Decrease exponent value if necessary.
        if (exponent > 0)
        {
          --exponent;
          precision_width -= (precision_width > (Tuint)exponent) ? exponent : 0;
        }
        else
        {
          // If real number have valid fractional part.
          if (frac > 0.0)
          {
            do
            {
              frac = NMath::CMath::modf((T_Real)(frac * 10.0), integer);
              --exponent;
            } while (integer <= 0.0);
            if (!result.insertLast((Tchar)(STR('0') + integer)))
             return NUtility::CPair<Tbool, Tuint>(false, 0);
          }
          else
            if (!result.insertLast(STR('0')))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
        }

        // Insert decimal point.
        if (!result.insertIndex(index + 1, STR('.')))
          return NUtility::CPair<Tbool, Tuint>(false, 0);

        // If there is a place for the fractional part.
        if (precision_width > 0)
        {
          // If real number have valid fractional part.
          if (frac > 0.0)
          {
            do
            {
              frac = NMath::CMath::modf((T_Real)(frac * 10.0), integer);
              if (!result.insertLast((Tchar)(STR('0') + integer)))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            } while ((--precision_width > 0) && (frac > 0.0));

            // Round the real number if necessary.
            if ((frac >= 0.5) && (result[result.getSize() - 1] < STR('9')))
              ++result[result.getSize() - 1];
          }

          // Put zeros into the empty fractional part.
          while (precision_width-- > 0)
          {
            if (!result.insertLast(STR('0')))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
          }
        }

        // Insert exponent symbols.
        if (!result.insertLast(((a_cFormatFlags & IStream::FORMAT_exp) ? STR('e') : STR('E'))))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
        if (!result.insertLast((exponent < 0) ? STR('-') : STR('+')))
          return NUtility::CPair<Tbool, Tuint>(false, 0);

        // Negate exponent value.
        if (exponent < 0)
          exponent = -exponent;

        // Insert exponent value.
        if (exponent < 10)
        {
          if (!result.insertLast(STR('0')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
          if (!result.insertLast(STR('0')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
          if (!result.insertLast((Tchar)(STR('0') + exponent)))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
        else if (exponent < 100)
        {
          if (!result.insertLast(STR('0')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
          if (!result.insertLast((Tchar)(STR('0') + exponent / 10)))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
          if (!result.insertLast((Tchar)(STR('0') + exponent % 10)))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
        else
        {
          Tuint min_exponent = result.getSize();
          do
          {
            if (!result.insertIndex(min_exponent, (Tchar)(STR('0') + exponent % 10)))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            exponent /= 10;
          } while (exponent > 9);
          if (!result.insertIndex(min_exponent, (Tchar)(STR('0') + exponent)))
           return NUtility::CPair<Tbool, Tuint>(false, 0);
        }

        // Insert alignment symbols.
        Tuint width = (a_cWidth > result.getSize() ? a_cWidth - result.getSize() : 0);
        if (a_cFormatFlags & IStream::FORMAT_LALIGN)
          index = result.getSize();
        else
          index = 0;
        while (width-- > 0)
        {
          if (!result.insertIndex(index, STR(' ')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
      }
      else
      {
        Tuint decimal_index = index;
        Tuint precision_width = a_cPrecision;

        // Insert zero integer part.
        if (exponent == 0)
        {
          if (!result.insertLast(STR('0')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
        }

        // If there is a place for the fractional part.
        if (precision_width > 0)
        {
          // Insert decimal point.
          decimal_index = result.getSize() - 1;
          if (!result.insertLast(STR('.')))
            return NUtility::CPair<Tbool, Tuint>(false, 0);

          // If real number have valid fractional part.
          if (frac > 0.0)
          {
            do
            {
              frac = NMath::CMath::modf((T_Real)(frac * 10.0), integer);
              if (!result.insertLast((Tchar)(STR('0') + integer)))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            } while ((--precision_width > 0) && (frac > 0.0));

            // Round the real number if necessary.
            if ((frac >= 0.5) && (result[result.getSize() - 1] < STR('9')))
              ++result[result.getSize() - 1];
          }

          // Put zeros into the empty fractional part.
          while (precision_width-- > 0)
          {
            if (!result.insertLast(STR('0')))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
          }
        }
        else
        {
          // Round the real number if necessary.
          if ((frac >= 0.5) && (result[result.getSize() - 1] < STR('9')))
            ++result[result.getSize() - 1];
        }

        // Insert thousands group symbols.
        Tuint group = 0;
        if (a_cFormatFlags & IStream::FORMAT_GROUPS)
        {
          for (Tuint i = decimal_index; i > index; --i)
          {
            if (++group == 3)
            {
              group = 0;
              if (!result.insertIndex(i, STR(',')))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
          }
          ++group;
        }

        // Insert alignment symbols.
        Tuint width = (a_cWidth > result.getSize() ? a_cWidth - result.getSize() : 0);
        if (a_cFormatFlags & IStream::FORMAT_FILL_0)
          index = index;
        else if (a_cFormatFlags & IStream::FORMAT_LALIGN)
          index = result.getSize();
        else
          index = 0;
        while (width-- > 0)
        {
          if (a_cFormatFlags & IStream::FORMAT_FILL_0)
          {
            if ((a_cFormatFlags & IStream::FORMAT_GROUPS) && (++group == 4))
            {
              if (width > 0)
              {
                group = 0;
                if (!result.insertIndex(index, STR(',')))
                  return NUtility::CPair<Tbool, Tuint>(false, 0);
              }
              else
                if (!result.insertFirst(STR(' ')))
                  return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
            else
              if (!result.insertIndex(index, STR('0')))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
          }
          else
          {
            if (!result.insertIndex(index, STR(' ')))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
          }
        }
      }
    }
    else
    {
      // Insert alignment symbols.
      Tuint index;
      Tuint width = (a_cWidth > result.getSize() ? a_cWidth - result.getSize() : 0);
      if (a_cFormatFlags & IStream::FORMAT_LALIGN)
        index = result.getSize();
      else
        index = 0;
      while (width-- > 0)
      {
        if (!result.insertIndex(index, STR(' ')))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }

    if ((a_cFormatFlags & IStream::FORMAT_ASCII) ? true : NString::CCharacter::isSystemASCII())
      return outputString(a_rStream, NString::CStringASCII(result));
    else
      return outputString(a_rStream, NString::CStringUnicode(result));
  }
}
/*--------------------------------------------------------------------------*/
/*!
    \def OUTPUT_POINTER(type)
    Output pointer of given \a type into the binary exchange stream.
*/
#define OUTPUT_POINTER(type)                                                                                                                                                                                                                           \
{                                                                                                                                                                                                                                                      \
  ASSERT(((a_cpPointer >= (Tcptr)NBase::CInteger<type>::getMin()) && (a_cpPointer <= (Tcptr)NBase::CInteger<type>::getMax())), STR("Pointer value which is outputted into the exchange stream does not fit into the exchange stream pointer bounds.")) \
  {                                                                                                                                                                                                                                                    \
    return NUtility::CPair<Tbool, Tuint>(false, 0);                                                                                                                                                                                                    \
  }                                                                                                                                                                                                                                                    \
                                                                                                                                                                                                                                                       \
  type value = ((type)((Tuint)a_cpPointer));                                                                                                                                                                                                           \
  Tuint result = outputBuffer(a_rStream, &value, sizeof(type), 1);                                                                                                                                                                                     \
  return NUtility::CPair<Tbool, Tuint>((result == sizeof(type)), result);                                                                                                                                                                              \
}
/*--------------------------------------------------------------------------*/
template <class T_Stream>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputPointer(T_Stream& a_rStream, Tcptr a_cpPointer, const Tuint a_cFormatFlags/* = IStream::FORMAT_DEFAULT */, const Tuint a_cWidth/* = 0 */)
{ CALL
  if (a_rStream.isBinaryMode())
  {
    switch (a_rStream.internalGetPtrSize())
    {
      case 1:
      {
        OUTPUT_POINTER(Tuint08);
      }
      case 2:
      {
        OUTPUT_POINTER(Tuint16);
      }
      case 4:
      {
        OUTPUT_POINTER(Tuint32);
      }
      case 8:
      {
        OUTPUT_POINTER(Tuint64);
      }
      default:
      {
        WARNING(STR("Current platform is not able to place pointer data type into the exchange stream."));
        return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
    }
  }
  else
  {
    ASSERT((((a_cFormatFlags & IStream::FORMAT_hex) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_HEX) ? 1 : 0) <= 1), STR("Format flags FORMAT_hex and FORMAT_HEX cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LOWER) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_UPPER) ? 1 : 0) <= 1), STR("Format flags FORMAT_LOWER and FORMAT_UPPER cannot be specified together."));
    ASSERT((((a_cFormatFlags & IStream::FORMAT_LALIGN) ? 1 : 0) + ((a_cFormatFlags & IStream::FORMAT_RALIGN) ? 1 : 0) <= 1), STR("Format flags FORMAT_LALIGN and FORMAT_RALIGN cannot be specified together."));

    NString::CString result;

    // Index radix symbols of the integer number.
    Tuint radix = 16;
    if (a_cFormatFlags & IStream::FORMAT_HEX)
    {
      if (!result.insertLast(STR("0X")))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }
    else
    {
      if (!result.insertLast(STR("0x")))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    // Insert integer number.
    Tuint count = 0;
    Tuint index = result.getSize();
    Tuint div_base = (Tuint)a_cpPointer;
    if (div_base == 0)
    {
      if (!result.insertIndex(index, STR('0')))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
      ++count;
    }
    while (div_base > 0)
    {
      Tuint mod_base = div_base % radix;
      if (mod_base > 9)
      {
        if (!result.insertIndex(index, (Tchar)(((a_cFormatFlags & IStream::FORMAT_UPPER) ? STR('A') : STR('a')) + mod_base - 10)))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      else
      {
        if (!result.insertIndex(index, (Tchar)(STR('0') + mod_base)))
          return NUtility::CPair<Tbool, Tuint>(false, 0);
      }
      div_base /= radix;
      ++count;
    }

    // Insert trailing zeros.
    while (count++ < (sizeof(Tcptr) << 1))
    {
      if (!result.insertIndex(index, STR('0')))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    // Insert alignment symbols.
    Tuint width = (a_cWidth > result.getSize() ? a_cWidth - result.getSize() : 0);
    if (a_cFormatFlags & IStream::FORMAT_LALIGN)
      index = result.getSize();
    else
      index = 0;
    while (width-- > 0)
    {
      if (!result.insertIndex(index, STR(' ')))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    if ((a_cFormatFlags & IStream::FORMAT_ASCII) ? true : NString::CCharacter::isSystemASCII())
      return outputString(a_rStream, NString::CStringASCII(result));
    else
      return outputString(a_rStream, NString::CStringUnicode(result));
  }
}
/*--------------------------------------------------------------------------*/
#undef OUTPUT_POINTER
/*--------------------------------------------------------------------------*/
template <class T_Stream, typename T_StringConst>
inline NUtility::CPair<Tbool, Tuint> CStreamHelper::outputFormat(T_Stream& a_rStream, T_StringConst a_cpFormatString, const Tuint a_cFormatStringSize, va_list a_VariableList)
{ CALL
  // Check T_StringConst template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringConst> >();

  NString::CStringUnicode result;

  Tchar c;
  Tuint size = a_cFormatStringSize;
  T_StringConst buffer = a_cpFormatString;

  // Iterate through all format string characters.
  while (size > 0)
  {
    c = (Tchar)((typename NTraits::MTraitsString<T_StringConst>::ucharacter)(*buffer));

    // Check control character.
    if (c == STR('%'))
    {
      static const Tuint PART_BEGIN = 0;
      static const Tuint PART_FLAGS = 1;
      static const Tuint PART_WIDTH = 2;
      static const Tuint PART_PREC  = 3;
      static const Tuint PART_RADIX = 4;
      static const Tuint PART_VALUE = 5;
      static const Tuint PART_END   = 6;

      Tbool format_zero_terminated = false;
      Tuint format_part = PART_BEGIN;
      Tuint format_flags = IStream::FORMAT_DEFAULT;
      Tuint format_width = 0;
      Tuint format_prec = 6;

      ++buffer;
      --size;

      while (size > 0)
      {
        c = (Tchar)((typename NTraits::MTraitsString<T_StringConst>::ucharacter)(*buffer));

        // Check next control character.
        switch (c)
        {
          case STR('-'):
          {
            if (format_part < PART_FLAGS)
            {
              format_flags &= ~(IStream::FORMAT_LALIGN | IStream::FORMAT_RALIGN | IStream::FORMAT_FILL_0);
              format_flags |= IStream::FORMAT_LALIGN;
              format_part = PART_FLAGS;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('+'):
          {
            if (format_part < PART_FLAGS)
            {
              format_flags &= ~(IStream::FORMAT_PLUS | IStream::FORMAT_SPACE);
              format_flags |= IStream::FORMAT_PLUS;
              format_part = PART_FLAGS;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR(' '):
          {
            if (format_part < PART_FLAGS)
            {
              format_flags &= ~(IStream::FORMAT_PLUS | IStream::FORMAT_SPACE);
              format_flags |= IStream::FORMAT_SPACE;
              format_part = PART_FLAGS;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('.'):
          {
            if (format_part < PART_PREC)
              format_part = PART_PREC;
            else
              format_part = PART_END;
            break;
          }
          case STR(','):
          {
            if (format_part < PART_PREC)
            {
              format_flags |= IStream::FORMAT_GROUPS;
              format_part = PART_PREC;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('*'):
          {
            if (format_part < PART_PREC)
            {
              format_width = va_arg(a_VariableList, Tuint);
              format_part = PART_WIDTH;
            }
            else
            {
              if (format_part == PART_PREC)
                format_prec = va_arg(a_VariableList, Tuint);
              else
                format_part = PART_END;
            }
            break;
          }
          case STR('b'):
          case STR('B'):
          {
            if (format_part < PART_RADIX)
            {
              format_flags &= ~(IStream::FORMAT_GROUPS | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX);
              format_flags |= ((c == STR('b')) ? IStream::FORMAT_binary : IStream::FORMAT_BINARY);
              format_part = PART_RADIX;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('o'):
          case STR('O'):
          {
            if (format_part < PART_RADIX)
            {
              format_flags &= ~(IStream::FORMAT_GROUPS | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX);
              format_flags |= ((c == STR('o')) ? IStream::FORMAT_octal : IStream::FORMAT_OCTAL);
              format_part = PART_RADIX;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('h'):
          case STR('H'):
          {
            if (format_part < PART_RADIX)
            {
              format_flags &= ~(IStream::FORMAT_GROUPS | IStream::FORMAT_octal | IStream::FORMAT_OCTAL | IStream::FORMAT_DECIMAL | IStream::FORMAT_hex | IStream::FORMAT_HEX);
              format_flags |= ((c == STR('h')) ? IStream::FORMAT_hex : IStream::FORMAT_HEX);
              format_part = PART_RADIX;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('e'):
          case STR('E'):
          {
            if (format_part < PART_RADIX)
            {
              format_flags &= ~(IStream::FORMAT_GROUPS | IStream::FORMAT_DOT | IStream::FORMAT_FILL_0);
              format_flags |= ((c == STR('e')) ? IStream::FORMAT_exp : IStream::FORMAT_EXP);
              format_part = PART_RADIX;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('Z'):
          {
            if (format_part < PART_RADIX)
            {
              format_zero_terminated = true;
              format_part = PART_RADIX;
            }
            else
              format_part = PART_END;
            break;
          }
          case STR('n'):
          {
            *va_arg(a_VariableList, Tuint*) = result.getSize();
            format_part = PART_VALUE;
            break;
          }
          case STR('s'):
          {
            Tschar temp = (Tschar)va_arg(a_VariableList, Tuint);
            if (!result.insertLast(temp))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('w'):
          {
            Twchar temp = (Twchar)va_arg(a_VariableList, Tuint);
            if (!result.insertLast(temp))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('x'):
          {
            Tchar temp = (Tchar)va_arg(a_VariableList, Tuint);
            if (!result.insertLast(temp))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('S'):
          {
            NString::CStringASCII str_to_insert;
            if (format_zero_terminated)
            {
              Tcsstr temp = va_arg(a_VariableList, Tcsstr);
              if (temp == NULL)
                return NUtility::CPair<Tbool, Tuint>(false, 0);
              Tuint str_length = NAlgorithms::NString::NBuffer::strLen(temp);
              if (!str_to_insert.set(temp, ((format_width > 0) && (format_width < str_length)) ? format_width : str_length))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
            else
            {
              const NString::CStringASCII* temp = va_arg(a_VariableList, const NString::CStringASCII*);
              if (temp == NULL)
                return NUtility::CPair<Tbool, Tuint>(false, 0);
              if (!str_to_insert.set(((format_width > 0) && (format_width < temp->getSize())) ? temp->getLeft(format_width) : *temp))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
            if (!result.insertLast(str_to_insert))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('W'):
          {
            NString::CStringUnicode str_to_insert;
            if (format_zero_terminated)
            {
              Tcwstr temp = va_arg(a_VariableList, Tcwstr);
              if (temp == NULL)
                return NUtility::CPair<Tbool, Tuint>(false, 0);
              Tuint str_length = NAlgorithms::NString::NBuffer::strLen(temp);
              if (!str_to_insert.set(temp, ((format_width > 0) && (format_width < str_length)) ? format_width : str_length))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
            else
            {
              const NString::CStringUnicode* temp = va_arg(a_VariableList, const NString::CStringUnicode*);
              if (temp == NULL)
                return NUtility::CPair<Tbool, Tuint>(false, 0);
              if (!str_to_insert.set(((format_width > 0) && (format_width < temp->getSize())) ? temp->getLeft(format_width) : *temp))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
            if (!result.insertLast(str_to_insert))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('X'):
          {
            NString::CString str_to_insert;
            if (format_zero_terminated)
            {
              Tcstr temp = va_arg(a_VariableList, Tcstr);
              if (temp == NULL)
                return NUtility::CPair<Tbool, Tuint>(false, 0);
              Tuint str_length = NAlgorithms::NString::NBuffer::strLen(temp);
              if (!str_to_insert.set(temp, ((format_width > 0) && (format_width < str_length)) ? format_width : str_length))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
            else
            {
              const NString::CString* temp = va_arg(a_VariableList, const NString::CString*);
              if (temp == NULL)
                return NUtility::CPair<Tbool, Tuint>(false, 0);
              if (!str_to_insert.set(((format_width > 0) && (format_width < temp->getSize())) ? temp->getLeft(format_width) : *temp))
                return NUtility::CPair<Tbool, Tuint>(false, 0);
            }
            if (!result.insertLast(str_to_insert))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('i'):
          case STR('I'):
          {
            format_flags &= ~(IStream::FORMAT_LOWER | IStream::FORMAT_UPPER);
            format_flags |= ((c == STR('i')) ? IStream::FORMAT_LOWER : IStream::FORMAT_UPPER);

            NText::CStreamString string_stream(true, a_rStream.getByteOrder(), a_rStream.getLineEnding());
            if (!string_stream.open(IStream::e_OPEN_WRITE))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            if (!string_stream.write(va_arg(a_VariableList, Tsint), format_flags, 0, format_width).getFirst())
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            if (!string_stream.close() || !result.insertLast(string_stream))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('u'):
          case STR('U'):
          {
            format_flags &= ~(IStream::FORMAT_LOWER | IStream::FORMAT_UPPER);
            format_flags |= ((c == STR('u')) ? IStream::FORMAT_LOWER : IStream::FORMAT_UPPER);

            NText::CStreamString string_stream(true, a_rStream.getByteOrder(), a_rStream.getLineEnding());
            if (!string_stream.open(IStream::e_OPEN_WRITE))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            if (!string_stream.write(va_arg(a_VariableList, Tuint), format_flags, 0, format_width).getFirst())
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            if (!string_stream.close() || !result.insertLast(string_stream))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          case STR('r'):
          case STR('f'):
          case STR('d'):
          {
            NText::CStreamString string_stream(true, a_rStream.getByteOrder(), a_rStream.getLineEnding());
            if (!string_stream.open(IStream::e_OPEN_WRITE))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            if (!string_stream.write(va_arg(a_VariableList, Tdouble), format_flags, format_part, format_width).getFirst())
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            if (!string_stream.close() || !result.insertLast(string_stream))
              return NUtility::CPair<Tbool, Tuint>(false, 0);
            format_part = PART_VALUE;
            break;
          }
          default:
          {
            // Check fill 0 flag.
            if ((c == STR('0')) && (format_part < PART_WIDTH))
            {
              format_flags &= ~(IStream::FORMAT_LALIGN | IStream::FORMAT_RALIGN | IStream::FORMAT_FILL_0);
              format_flags |= IStream::FORMAT_FILL_0;
              format_part = PART_WIDTH;
            }
            else if ((c >= STR('0')) && (c <= STR('9')))
            {
              // Get format width or precession width.
              if (format_part < PART_PREC)
              {
                format_width *= 10;
                format_width += c - STR('0');
              }
              else if (format_part == PART_PREC)
              {
                format_prec *= 10;
                format_prec += c - STR('0');
              }
              else
                format_part = PART_END;
            }
            else
              format_part = PART_END;
            break;
          }
        }

        if (format_part == PART_END)
        {
          // Output regular character.
          if (!result.insertLast(*buffer))
            return NUtility::CPair<Tbool, Tuint>(false, 0);
        }
        else if ((format_part == PART_VALUE) || (size == 0))
          break;

        ++buffer;
        --size;
      }
    }
    else
    {
      // Output regular character.
      if (!result.insertLast(*buffer))
        return NUtility::CPair<Tbool, Tuint>(false, 0);
    }

    if (size > 0)
    {
      ++buffer;
      --size;
    }
  }
  if (NTraits::MTraitsString<T_StringConst>::isASCII)
    return outputString(a_rStream, NString::CStringASCII(result));
  else
    return outputString(a_rStream, NString::CStringUnicode(result));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
