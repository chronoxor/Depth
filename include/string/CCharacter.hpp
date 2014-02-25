/*!
 *  \file    CCharacter.hpp Character class wraps operations with a single
 *           ASCII/Unicode character.
 *  \brief   Character wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   28.08.2007 22:38:11

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
#ifndef __CCHARACTER_HPP__
#define __CCHARACTER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
class CCharacterProperties;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Character wrapper class.
/*!
    Character wrapper emulates  basic  operations  with  single  ASCII/Unicode
    characters and has special  methods  which  returns  corresponding  limits
    values and modify characters.
*/
class BASE_API CCharacter
{
  // Friend class: Character properties class (CCharacterProperties).
  friend class CCharacterProperties;

  //! Type for the MConceptDepthType constraint checking.
  typedef CCharacter TDepthCheckType;

  // Check CCharacter class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CCharacter();
  //! Initialize character with a given ASCII one.
  /*!
      \param a_cCharacter - ASCII character.
  */
  CCharacter(const Tschar a_cCharacter);
  //! Initialize character with a given Unicode one.
  /*!
      \param a_cCharacter - Unicode character.
  */
  CCharacter(const Twchar a_cCharacter);
  //! Initialize character with a given one in general form.
  /*!
      \param a_cCharacter - Character in general form.
  */
  CCharacter(const Tuint a_cCharacter);
  //! Initialize character with a coordinates in the Unicode plane.
  /*!
      \param a_cCell - Cell position of the character in the Unicode plane.
      \param a_cRow - Row position of the character in the Unicode plane.
  */
  CCharacter(const Tuint08 a_cCell, const Tuint08 a_cRow);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCharacter class.
  */
  CCharacter(const CCharacter& a_crInstance);
  //! Class destructor.
 ~CCharacter();

  //! Operator: Equal to another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return true  - if CCharacter class instance is equal to another one. \n
              false - if CCharacter class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);
  //! Operator: Not equal to another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return true  - if CCharacter class instance is not equal to another one. \n
              false - if CCharacter class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);

  //! Operator: Less than another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return true  - if CCharacter class instance is less than another one. \n
              false - if CCharacter class instance is not less than another one. \n
  */
  friend BASE_API Tbool operator < (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);
  //! Operator: More than another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return true  - if CCharacter class instance is more than another one. \n
              false - if CCharacter class instance is not more than another one. \n
  */
  friend BASE_API Tbool operator > (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);
  //! Operator: Less or equal than another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return true  - if CCharacter class instance is less or equal than another one. \n
              false - if CCharacter class instance is not less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);
  //! Operator: More or equal than another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return true  - if CCharacter class instance is more or equal than another one. \n
              false - if CCharacter class instance is not more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);

  //! Operator: Add another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return Integer value which contains result of addition of the two characters instances.
  */
  friend BASE_API Tsint operator + (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);
  //! Operator: Sub another CCharacter class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacter class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacter class.
      \return Integer value which contains result of subtraction of the two characters instances.
  */
  friend BASE_API Tsint operator - (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2);

  //! Operator: Assign ASCII character.
  /*!
      \param a_cCharacter - ASCII character.
      \return Reference to the current class instance.
  */
  CCharacter& operator = (const Tschar a_cCharacter);
  //! Operator: Assign Unicode character.
  /*!
      \param a_cCharacter - Unicode character.
      \return Reference to the current class instance.
  */
  CCharacter& operator = (const Twchar a_cCharacter);
  //! Operator: Assign character in general form.
  /*!
      \param a_cCharacter - Character in general form.
      \return Reference to the current class instance.
  */
  CCharacter& operator = (const Tuint a_cCharacter);
  //! Operator: Assign another CCharacter class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCharacter class.
      \return Reference to the current class instance.
  */
  CCharacter& operator = (const CCharacter& a_crInstance);

  //! Operator: Get ASCII character based on the current character in general form.
  /*!
      \return ASCII character based on the current character in general form.
  */
  operator Tschar () const;
  //! Operator: Get Unicode character based on the current character in general form.
  /*!
      \return Unicode character based on the current character in general form.
  */
  operator Twchar () const;

  //! Set ASCII character.
  /*!
      \param a_cCharacter - ASCII character.
  */
  void set(const Tschar a_cCharacter);
  //! Set Unicode character.
  /*!
      \param a_cCharacter - Unicode character.
  */
  void set(const Twchar a_cCharacter);
  //! Set character in general form.
  /*!
      \param a_cCharacter - Character in general form.
  */
  void set(const Tuint a_cCharacter);
  //! Set character with a coordinates in the Unicode plane.
  /*!
      \param a_cCell - Cell position of the character in the Unicode plane.
      \param a_cRow - Row position of the character in the Unicode plane.
  */
  void set(const Tuint08 a_cCell, const Tuint08 a_cRow);
  //! Set another CCharacter class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCharacter class.
  */
  void set(const CCharacter& a_crInstance);

  //! Set character cell in the Unicode plane.
  /*!
      \param a_cCell - Cell position of the character in the Unicode plane.
  */
  void setCell(const Tuint08 a_cCell);
  //! Set character row in the Unicode plane.
  /*!
      \param a_cRow - Row position of the character in the Unicode plane.
  */
  void setRow(const Tuint08 a_cRow);

  //! Get current character cell position in the Unicode plane.
  /*!
      \return Cell position of the current character in the Unicode plane.
  */
  Tuint08 getCell() const;
  //! Get current character row position in the Unicode plane.
  /*!
      \return Row position of the current character in the Unicode plane.
  */
  Tuint08 getRow() const;

  //! Check if the current character is a valid system character.
  /*!
      \return true  - if the current character is a valid system character. \n
              false - if the current character is not a valid system character. \n
  */
  Tbool isValidSystem() const;
  //! Check if the current character is a valid ASCII one.
  /*!
      \return true  - if the current character is a valid ASCII one. \n
              false - if the current character is not a valid ASCII one. \n
  */
  Tbool isValidASCII() const;
  //! Check if the current character is a valid Unicode one.
  /*!
      \return true  - if the current character is a valid Unicode one. \n
              false - if the current character is not a valid Unicode one. \n
  */
  Tbool isValidUnicode() const;

  //! Check if the current character is an alphabetical or decimal digit one.
  /*!
      \return true  - if the current character is an alphabetical or decimal digit one. \n
              false - if the current character is not an alphabetical or decimal digit one. \n
  */
  Tbool isAlnum() const;
  //! Check if the current character is an alphabetical one.
  /*!
      \return true  - if the current character is an alphabetical one. \n
              false - if the current character is not an alphabetical one. \n
  */
  Tbool isAlpha() const;
  //! Check if the current character is a blank one.
  /*!
      \return true  - if the current character is a blank one. \n
              false - if the current character is not a blank one. \n
  */
  Tbool isBlank() const;
  //! Check if the current character is a control one.
  /*!
      \return true  - if the current character is a control one. \n
              false - if the current character is not a control one. \n
  */
  Tbool isCntrl() const;
  //! Check if the current character is a digit one.
  /*!
      \return true  - if the current character is a digit one. \n
              false - if the current character is not a digit one. \n
  */
  Tbool isDigit() const;
  //! Check if the current character is a decimal digit one.
  /*!
      \return true  - if the current character is a decimal digit one. \n
              false - if the current character is not a decimal digit one. \n
  */
  Tbool isDecimalDigit() const;
  //! Check if the current character is an alphabetical, decimal digit or punctuation one.
  /*!
      \return true  - if the current character is an alphabetical, decimal digit or punctuation one. \n
              false - if the current character is not an alphabetical, decimal digit or punctuation one. \n
  */
  Tbool isGraph() const;
  //! Check if the current character is a printing one.
  /*!
      \return true  - if the current character is a printing one. \n
              false - if the current character is not a printing one. \n
  */
  Tbool isPrint() const;
  //! Check if the current character is a punctuation one.
  /*!
      \return true  - if the current character is a punctuation one. \n
              false - if the current character is not a punctuation one. \n
  */
  Tbool isPunct() const;
  //! Check if the current character is a space one.
  /*!
      \return true  - if the current character is a space one. \n
              false - if the current character is not a space one. \n
  */
  Tbool isSpace() const;
  //! Check if the current character is a hexidecimal digit one.
  /*!
      \return true  - if the current character is a hexidecimal digit one. \n
              false - if the current character is not a hexidecimal digit one. \n
  */
  Tbool isXDigit() const;
  //! Check if the current character is '\0' one.
  /*!
      \return true  - if the current character is a zero one. \n
              false - if the current character is not a zero one. \n
  */
  Tbool isZero() const;

  //! Check if the current character is a letter one.
  /*!
      \return true  - if the current character is a letter one. \n
              false - if the current character is not a letter one. \n
  */
  Tbool isLetter() const;
  //! Check if the current character is a mark one.
  /*!
      \return true  - if the current character is a mark one. \n
              false - if the current character is not a mark one. \n
  */
  Tbool isMark() const;
  //! Check if the current character is a number one.
  /*!
      \return true  - if the current character is a number one. \n
              false - if the current character is not a number one. \n
  */
  Tbool isNumber() const;
  //! Check if the current character is a punctuation one.
  /*!
      \return true  - if the current character is a punctuation one. \n
              false - if the current character is not a punctuation one. \n
  */
  Tbool isPunctuation() const;
  //! Check if the current character is a symbol one.
  /*!
      \return true  - if the current character is a symbol one. \n
              false - if the current character is not a symbol one. \n
  */
  Tbool isSymbol() const;
  //! Check if the current character is a separator one.
  /*!
      \return true  - if the current character is a separator one. \n
              false - if the current character is not a separator one. \n
  */
  Tbool isSeparator() const;
  //! Check if the current character is an other one.
  /*!
      \return true  - if the current character is an other one. \n
              false - if the current character is not an other one. \n
  */
  Tbool isOther() const;

  //! Check if the current character is a lower case one.
  /*!
      \return true  - if the current character is a lower case one. \n
              false - if the current character is not a lower case one. \n
  */
  Tbool isLower() const;
  //! Check if the current character is a upper case one.
  /*!
      \return true  - if the current character is a upper case one. \n
              false - if the current character is not a upper case one. \n
  */
  Tbool isUpper() const;
  //! Check if the current character is a title case one.
  /*!
      \return true  - if the current character is a title case one. \n
              false - if the current character is not a title case one. \n
  */
  Tbool isTitle() const;

  //! Convert current character to the lower case form.
  /*!
      \return Character in the lower case form.
  */
  CCharacter toLowerCase() const;
  //! Convert current character to the upper case form.
  /*!
      \return Character in the upper case form.
  */
  CCharacter toUpperCase() const;
  //! Convert current character to the title case form.
  /*!
      \return Character in the title case form.
  */
  CCharacter toTitleCase() const;
  //! Convert current character to the toggle case form.
  /*!
      \return Character in the toggle case form.
  */
  CCharacter toToggleCase() const;

  //! Get system character based on the current character in general form.
  /*!
      \return System character based on the current character in general form.
  */
  Tchar getSystem() const;
  //! Get ASCII character based on the current character in general form.
  /*!
      \return ASCII character based on the current character in general form.
  */
  Tschar getASCII() const;
  //! Get Unicode character based on the current character in general form.
  /*!
      \return Unicode character based on the current character in general form.
  */
  Twchar getUnicode() const;
  //! Get unsigned integer value based on the current character in general form.
  /*!
      \return Unsigned integer value based on the current character in general form.
  */
  Tuint getUnsigned() const;

  //! Set current character value to zero.
  void clear();

  //! Is system character encoding ASCII?
  /*!
      \return true  - if the system character encoding is ASCII. \n
              false - if the system character encoding is Unicode. \n
  */
  static Tbool isSystemASCII();
  //! Is system character encoding Unicode?
  /*!
      \return true  - if the system character encoding is Unicode. \n
              false - if the system character encoding is ASCII. \n
  */
  static Tbool isSystemUnicode();

  //! Get minimal possible system character value.
  /*!
      \return Minimal possible system character value.
  */
  static Tchar getSystemMin();
  //! Get maximal possible system character value.
  /*!
      \return Maximal possible system character value.
  */
  static Tchar getSystemMax();
  //! Get minimal absolute possible system character value.
  /*!
      \return Minimal absolute possible system character value.
  */
  static Tcharu getSystemAbsMin();
  //! Get maximal absolute possible system character value.
  /*!
      \return Maximal absolute possible system character value.
  */
  static Tcharu getSystemAbsMax();

  //! Get minimal possible ASCII character value.
  /*!
      \return Minimal possible ASCII character value.
  */
  static Tschar getASCIIMin();
  //! Get maximal possible ASCII character value.
  /*!
      \return Maximal possible ASCII character value.
  */
  static Tschar getASCIIMax();
  //! Get minimal absolute possible ASCII character value.
  /*!
      \return Minimal absolute possible ASCII character value.
  */
  static Tscharu getASCIIAbsMin();
  //! Get maximal absolute possible ASCII character value.
  /*!
      \return Maximal absolute possible ASCII character value.
  */
  static Tscharu getASCIIAbsMax();

  //! Get minimal possible Unicode character value.
  /*!
      \return Minimal possible Unicode character value.
  */
  static Twchar getUnicodeMin();
  //! Get maximal possible Unicode character value.
  /*!
      \return Maximal possible Unicode character value.
  */
  static Twchar getUnicodeMax();
  //! Get minimal absolute possible Unicode character value.
  /*!
      \return Minimal absolute possible Unicode character value.
  */
  static Twcharu getUnicodeAbsMin();
  //! Get maximal absolute possible Unicode character value.
  /*!
      \return Maximal absolute possible Unicode character value.
  */
  static Twcharu getUnicodeAbsMax();

  //! Serialize CCharacter class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CCharacter class instances.
  /*!
      \param a_rInstance - Reference to another CCharacter class instance.
  */
  void swap(CCharacter& a_rInstance);

private:
  Tuint m_Value;                        //!< Character value in general form.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/CCharacter.inl>
/*==========================================================================*/
//! \example example-string-CCharacter.cpp
/*--------------------------------------------------------------------------*/
//! \test test-string-CCharacter.cpp
/*==========================================================================*/
#endif
