/*!
 *  \file    CCharacterProperties.hpp Character properties class provides
 *           special information about ASCII/Unicode character.
 *  \brief   Character properties class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.10.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character properties class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   20.10.2009 20:48:38

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
#ifndef __CCHARACTERPROPERTIES_HPP__
#define __CCHARACTERPROPERTIES_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/string/UCD/CBinaryProperties.hpp>
#include <Depth/include/string/UCD/CCanonicalCombiningClass.hpp>
#include <Depth/include/string/UCD/EBidiClass.hpp>
#include <Depth/include/string/UCD/EDecompositionMapping.hpp>
#include <Depth/include/string/UCD/EEastAsianWidth.hpp>
#include <Depth/include/string/UCD/EGeneralCategory.hpp>
#include <Depth/include/string/UCD/EHangulSyllableType.hpp>
#include <Depth/include/string/UCD/EJoiningGroup.hpp>
#include <Depth/include/string/UCD/EJoiningType.hpp>
#include <Depth/include/string/UCD/ELineBreakClass.hpp>
#include <Depth/include/string/UCD/EScriptType.hpp>
#include <Depth/include/string/UCD/EUnicodeVersion.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Character properties class.
/*!
    Character   properties   class   provides   special   information    about
    ASCII/Unicode character, which is taken from Unicode Character Database.
*/
class BASE_API CCharacterProperties
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CCharacterProperties TDepthCheckType;

  // Check CCharacterProperties class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CCharacterProperties();
  //! Initialize character properties class with a given ASCII character.
  /*!
      \param a_cCharacter - ASCII character.
  */
  CCharacterProperties(const Tschar a_cCharacter);
  //! Initialize character properties class with a given Unicode character.
  /*!
      \param a_cCharacter - Unicode character.
  */
  CCharacterProperties(const Twchar a_cCharacter);
  //! Initialize character properties class with a given character in general form.
  /*!
      \param a_cCharacter - Character in general form.
  */
  CCharacterProperties(const Tuint a_cCharacter);
  //! Initialize character properties class with a given CCharacter class instance.
  /*!
      \param a_crCharacter - Constant reference to the instance of the CCharacter class.
  */
  CCharacterProperties(const CCharacter& a_crCharacter);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCharacterProperties class.
  */
  CCharacterProperties(const CCharacterProperties& a_crInstance);
  //! Class destructor.
 ~CCharacterProperties();

  //! Operator: Equal to another CCharacterProperties class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacterProperties class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacterProperties class.
      \return true  - if CCharacterProperties class instance is equal to another one. \n
              false - if CCharacterProperties class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CCharacterProperties& a_crInstance1, const CCharacterProperties& a_crInstance2);
  //! Operator: Not equal to another CCharacterProperties class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CCharacterProperties class.
      \param a_crInstance2 - Constant reference to another instance of the CCharacterProperties class.
      \return true  - if CCharacterProperties class instance is not equal to another one. \n
              false - if CCharacterProperties class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CCharacterProperties& a_crInstance1, const CCharacterProperties& a_crInstance2);

  //! Operator: Assign ASCII character.
  /*!
      \param a_cCharacter - ASCII character.
      \return Reference to the current class instance.
  */
  CCharacterProperties& operator = (const Tschar a_cCharacter);
  //! Operator: Assign Unicode character.
  /*!
      \param a_cCharacter - Unicode character.
      \return Reference to the current class instance.
  */
  CCharacterProperties& operator = (const Twchar a_cCharacter);
  //! Operator: Assign character in general form.
  /*!
      \param a_cCharacter - Character in general form.
      \return Reference to the current class instance.
  */
  CCharacterProperties& operator = (const Tuint a_cCharacter);
  //! Operator: Assign CCharacter class instance.
  /*!
      \param a_crCharacter - Constant reference to the instance of the CCharacter class.
      \return Reference to the current class instance.
  */
  CCharacterProperties& operator = (const CCharacter& a_crCharacter);
  //! Operator: Assign another CCharacterProperties class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCharacterProperties class.
      \return Reference to the current class instance.
  */
  CCharacterProperties& operator = (const CCharacterProperties& a_crInstance);

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
  //! Set CCharacter class instance.
  /*!
      \param a_crCharacter - Constant reference to the instance of the CCharacter class.
  */
  void set(const CCharacter& a_crCharacter);
  //! Set another CCharacterProperties class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCharacterProperties class.
  */
  void set(const CCharacterProperties& a_crInstance);

  //! Check if the current character has valid properties.
  /*!
      \return true  - if the current character has valid properties. \n
              false - if the current character has not valid properties. \n
  */
  Tbool isValid() const;

  //! Get character Code property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Code property.
  */
  Tuint getCode() const;

  //! Check if the current character has valid Name property.
  /*!
      \return true  - if the current character has valid Name property. \n
              false - if the current character has not valid Name property. \n
  */
  Tbool isValidName() const;
  //! Get character Name value property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally 'isValidName()' check method should  be
      used.

      \return Character Name property.
  */
  Tcsstr getName() const;

  //! Check if the current character has valid Old Name property.
  /*!
      \return true  - if the current character has valid Old Name property. \n
              false - if the current character has not valid Old Name property. \n
  */
  Tbool isValidOldName() const;
  //! Get character Old Name property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally 'isValidOldName()' check method  should
      be used.

      \return Character Old Name property.
  */
  Tcsstr getOldName() const;

  //! Check if the current character has valid Jamo Name property.
  /*!
      \return true  - if the current character has valid Jamo Name property. \n
              false - if the current character has not valid Jamo Name property. \n
  */
  Tbool isValidJamoName() const;
  //! Get character Jamo Name property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally 'isValidJamoName()' check method should
      be used.

      \return Character Jamo Name property.
  */
  Tcsstr getJamoName() const;

  //! Get character General Category property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character General Category property.
      \see NDepth::NString::NUCD::EGeneralCategory
  */
  NUCD::EGeneralCategory getGeneralCategory() const;
  //! Get character Canonical Combining Class property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Canonical Combining Class property.
      \see NDepth::NString::NUCD::CCanonicalCombiningClass
  */
  Tuint08 getCanonicalCombiningClass() const;
  //! Get character Bidi Class property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Bidi Class property.
      \see NDepth::NString::NUCD::EBidiClass
  */
  NUCD::EBidiClass getBidiClass() const;

  //! Check if the current character has valid Decomposition Mapping property.
  /*!
      \return true  - if the current character has valid Decomposition Mapping property. \n
              false - if the current character has not valid Decomposition Mapping property. \n
  */
  Tbool isValidDecompositionMapping() const;
  //! Get character Decomposition Mapping Type property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally  'isValidDecompositionMapping()'  check
      method should be used.

      \return Character Decomposition Mapping Type property.
  */
  NUCD::EDecompositionMapping getDecompositionMappingType() const;
  //! Get character Decomposition Mapping Size property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally  'isValidDecompositionMapping()'  check
      method should be used.

      \return Character Decomposition Mapping Size property.
  */
  Tuint getDecompositionMappingSize() const;
  //! Get character Decomposition Mapping Value property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally  'isValidDecompositionMapping()'  check
      method should be used.

      \param a_cIndex - Decomposition Mapping Value index.
      \return Character Decomposition Mapping Value property.
  */
  Tsint getDecompositionMappingValue(const Tuint a_cIndex) const;

  //! Check if the current character has valid Decimal Digit property.
  /*!
      \return true  - if the current character has valid Decimal Digit property. \n
              false - if the current character has not valid Decimal Digit property. \n
  */
  Tbool isValidDecimalDigit() const;
  //! Get character Decimal Digit Name property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally  'isValidDecimalDigit()'  check  method
      should be used.

      \return Character Decimal Digit Name property.
  */
  Tcsstr getDecimalDigitName() const;
  //! Get character Decimal Digit Value property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally  'isValidDecimalDigit()'  check  method
      should be used.

      \return Character Decimal Digit Value property.
  */
  Tsint getDecimalDigitValue() const;

  //! Check if the current character has valid Digit property.
  /*!
      \return true  - if the current character has valid Digit property. \n
              false - if the current character has not valid Digit property. \n
  */
  Tbool isValidDigit() const;
  //! Get character Digit Name property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally 'isValidDigit()' check method should be
      used.

      \return Character Digit Name property.
  */
  Tcsstr getDigitName() const;
  //! Get character Digit Value property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally 'isValidDigit()' check method should be
      used.

      \return Character Digit Value property.
  */
  Tsint getDigitValue() const;

  //! Check if the current character has valid Numeric property.
  /*!
      \return true  - if the current character has valid Numeric property. \n
              false - if the current character has not valid Numeric property. \n
  */
  Tbool isValidNumeric() const;
  //! Get character Numeric Name property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally 'isValidNumeric()' check method  should
      be used.

      \return Character Numeric Name property.
  */
  Tcsstr getNumericName() const;
  //! Get character Numeric Value property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method. Additionally 'isValidNumeric()' check method  should
      be used.

      \return Character Numeric Value property.
  */
  Treal getNumericValue() const;

  //! Get character Bidi Mirrored flag property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Bidi Mirrored flag property.
  */
  Tbool getBidiMirrored() const;

  //! Get character Lowercase Mapping property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Lowercase Mapping property.
  */
  Tsint getLowercaseMapping() const;
  //! Get character Uppercase Mapping property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Uppercase Mapping property.
  */
  Tsint getUppercaseMapping() const;
  //! Get character Titlecase Mapping property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Titlecase Mapping property.
  */
  Tsint getTitlecaseMapping() const;

  //! Get character Binary properties.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Binary properties.
  */
  Tuint64 getBinaryProperties() const;

  //! Get character Joining Type property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Joining Type property.
  */
  NUCD::EJoiningType getJoiningType() const;
  //! Get character Joining Group property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Joining Group property.
  */
  NUCD::EJoiningGroup getJoiningGroup() const;

  //! Get character Bidi Mirroring Glyph property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Bidi Mirroring Glyph property.
  */
  Tsint getBidiMirroringGlyph() const;
  //! Get character Bidi Mirroring Glyph best fit flag property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Bidi Mirroring Glyph best fit flag property.
  */
  Tbool getBidiMirroringGlyphBestFit() const;

  //! Check if the current character has valid Block Name property.
  /*!
      \return true  - if the current character has valid Block Name property. \n
              false - if the current character has not valid Block Name property. \n
  */
  Tbool isValidBlockName() const;
  //! Get character Block Name value property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()'  method.  Additionally  'isValidBlockName()'  check   method
      should be used.

      \return Character Block Name property.
  */
  Tcsstr getBlockName() const;

  //! Get character Unicode Version property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Unicode Version property.
  */
  NUCD::EUnicodeVersion getUnicodeVersion() const;
  //! Get character East Asian Width property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character East Asian Width property.
  */
  NUCD::EEastAsianWidth getEastAsianWidth() const;
  //! Get character Hangul Syllable Type property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Hangul Syllable Type property.
  */
  NUCD::EHangulSyllableType getHangulSyllableType() const;
  //! Get character Line Break Class property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Line Break class property.
  */
  NUCD::ELineBreakClass getLineBreakClass() const;
  //! Get character Script Type property.
  /*!
      In order to get valid value character property should  be  checked  with
      'isValid()' method.

      \return Character Script Type property.
  */
  NUCD::EScriptType getScriptType() const;

  //! Serialize CCharacterProperties class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CCharacterProperties class instances.
  /*!
      \param a_rInstance - Reference to another CCharacterProperties class instance.
  */
  void swap(CCharacterProperties& a_rInstance);

private:
  Tuint   m_Value;                      //!< Character value in general form.
  Tsint32 m_UCDIndex;                   //!< Character index in Unicode Character Database.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/CCharacterProperties.inl>
/*==========================================================================*/
#endif
