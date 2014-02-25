/*!
 *  \file    OFormatFlags.hpp Format flags stream control operators. They are
 *           used to manipulate stream format flags through stream operators.
 *  \brief   Format flags stream control operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Format flags stream control operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   02.10.2008 01:48:42

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
#ifndef __OFORMATFLAGS_HPP__
#define __OFORMATFLAGS_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/stream/IWriter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* OPERATOR DECLARATIONS                                                    */
/*==========================================================================*/
//! Format flags stream control operator.
/*!
    Format flags stream control operator is used to set  stream  format  flags
    through stream operators.
*/
class BASE_API flags
{
public:
  //! Set stream format flags through stream operators.
  /*!
      \param a_cFormatFlags - Combination of format flags.
  */
  flags(const Tuint a_cFormatFlags);
  //! Remove one set of stream format flags and add another one through stream operators.
  /*!
      \param a_cRemoveFormatFlags - Combination of format flags to remove.
      \param a_cAddFormatFlags - Combination of format flags to add.
  */
  flags(const Tuint a_cRemoveFormatFlags, const Tuint a_cAddFormatFlags);

  //! Operator: Read format flags stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFormatFlags - Constant reference to the format flags stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentFormatFlags()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const flags& a_crFormatFlags);
  //! Operator: Peek format flags stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFormatFlags - Constant reference to the format flags stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentFormatFlags()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const flags& a_crFormatFlags);
  //! Operator: Push format flags stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFormatFlags - Constant reference to the format flags stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentFormatFlags()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const flags& a_crFormatFlags);
  //! Operator: Write format flags stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crFormatFlags - Constant reference to the format flags stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IStream::setCurrentFormatFlags()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const flags& a_crFormatFlags);

private:
  Tuint m_RemoveFormatFlags;            //!< Combination of format flags to remove.
  Tuint m_AddFormatFlags;               //!< Combination of format flags to add.
};
extern BASE_API flags defaults;         //!< Global instance of the set IStream::FORMAT_DEFAULT format flag stream control operator.
extern BASE_API flags plus;             //!< Global instance of the add IStream::FORMAT_PLUS format flag stream control operator.
extern BASE_API flags space;            //!< Global instance of the add IStream::FORMAT_SPACE format flag stream control operator.
extern BASE_API flags binary;           //!< Global instance of the add IStream::FORMAT_binary format flag stream control operator.
extern BASE_API flags BINARY;           //!< Global instance of the add IStream::FORMAT_BINARY format flag stream control operator.
extern BASE_API flags octal;            //!< Global instance of the add IStream::FORMAT_octal format flag stream control operator.
extern BASE_API flags OCTAL;            //!< Global instance of the add IStream::FORMAT_OCTAL format flag stream control operator.
extern BASE_API flags decimal;          //!< Global instance of the add IStream::FORMAT_DECIMAL format flag stream control operator.
extern BASE_API flags hex;              //!< Global instance of the add IStream::FORMAT_hex format flag stream control operator.
extern BASE_API flags HEX;              //!< Global instance of the add IStream::FORMAT_HEX format flag stream control operator.
extern BASE_API flags lower;            //!< Global instance of the add IStream::FORMAT_LOWER format flag stream control operator.
extern BASE_API flags upper;            //!< Global instance of the add IStream::FORMAT_UPPER format flag stream control operator.
extern BASE_API flags lalign;           //!< Global instance of the add IStream::FORMAT_LALIGN format flag stream control operator.
extern BASE_API flags ralign;           //!< Global instance of the add IStream::FORMAT_RALIGN format flag stream control operator.
extern BASE_API flags fill_0;           //!< Global instance of the add IStream::FORMAT_FILL_0 format flag stream control operator.
extern BASE_API flags groups;           //!< Global instance of the add IStream::FORMAT_GROUPS format flag stream control operator.
extern BASE_API flags dot;              //!< Global instance of the add IStream::FORMAT_DOT format flag stream control operator.
extern BASE_API flags exp;              //!< Global instance of the add IStream::FORMAT_exp format flag stream control operator.
extern BASE_API flags EXP;              //!< Global instance of the add IStream::FORMAT_EXP format flag stream control operator.
extern BASE_API flags ascii;            //!< Global instance of the add IStream::FORMAT_ASCII format flag stream control operator.
extern BASE_API flags unicode;          //!< Global instance of the add IStream::FORMAT_UNICODE format flag stream control operator.
extern BASE_API flags noplus;           //!< Global instance of the remove IStream::FORMAT_PLUS format flag stream control operator.
extern BASE_API flags nospace;          //!< Global instance of the remove IStream::FORMAT_SPACE format flag stream control operator.
extern BASE_API flags nogroups;         //!< Global instance of the remove IStream::FORMAT_GROUPS format flag stream control operator.
/*--------------------------------------------------------------------------*/
//! Precision stream control operator.
/*!
    Precision stream control operator  is  used  to  set  count  of  precision
    numbers after the decimal point through stream operators.
*/
class BASE_API prec
{
public:
  //! Set count of precision numbers after the decimal point through stream operators.
  /*!
      \param a_cPrecision - Count of precision numbers after the decimal point.
  */
  prec(const Tuint a_cPrecision);

  //! Operator: Read precision stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crPrecision - Constant reference to the precision stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentPrecision()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const prec& a_crPrecision);
  //! Operator: Peek precision stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crPrecision - Constant reference to the precision stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentPrecision()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const prec& a_crPrecision);
  //! Operator: Push precision stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crPrecision - Constant reference to the precision stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentPrecision()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const prec& a_crPrecision);
  //! Operator: Write precision stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crPrecision - Constant reference to the precision stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IStream::setCurrentPrecision()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const prec& a_crPrecision);

private:
  Tuint m_Precision;                    //!< Count of precision numbers after the decimal point.
};
/*--------------------------------------------------------------------------*/
//! Width stream control operator.
/*!
    Width stream control operator is used to set  width  of  the  align  place
    through stream operators.
*/
class BASE_API width
{
public:
  //! Set width of the align place through stream operators.
  /*!
      \param a_cWidth - Width of the align place.
  */
  width(const Tuint a_cWidth);

  //! Operator: Read width stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crWidth - Constant reference to the width stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentWidth()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const width& a_crWidth);
  //! Operator: Peek width stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crWidth - Constant reference to the width stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentWidth()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const width& a_crWidth);
  //! Operator: Push width stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crWidth - Constant reference to the width stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentWidth()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const width& a_crWidth);
  //! Operator: Write width stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crWidth - Constant reference to the width stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IStream::setCurrentWidth()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const width& a_crWidth);

private:
  Tuint m_Width;                        //!< Width of the align place.
};
/*--------------------------------------------------------------------------*/
//! Radix stream control operator.
/*!
    Radix stream control operator is used to set radix of the  output  integer
    value through stream operators.
*/
class BASE_API radix
{
public:
  //! Set radix of the output integer value through stream operators.
  /*!
      \param a_cRadix - Radix of the output integer value.
  */
  radix(const Tuint a_cRadix);

  //! Operator: Read radix stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crRadix - Constant reference to the radix stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentRadix()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const radix& a_crRadix);
  //! Operator: Peek radix stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crRadix - Constant reference to the radix stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentRadix()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const radix& a_crRadix);
  //! Operator: Push radix stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crRadix - Constant reference to the radix stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setCurrentRadix()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const radix& a_crRadix);
  //! Operator: Write radix stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crRadix - Constant reference to the radix stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IStream::setCurrentRadix()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const radix& a_crRadix);

private:
  Tuint m_Radix;                        //!< Radix of the output integer value.
};
/*--------------------------------------------------------------------------*/
//! Reset stream control operator.
/*!
    Reset stream control operator is  used  to  reset  stream  through  stream
    operators.
*/
class BASE_API resetStream
{
public:
  //! Operator: Read reset stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crReset - Constant reference to the reset stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setDefaultFormat()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const resetStream& a_crReset);
  //! Operator: Peek reset stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crReset - Constant reference to the reset stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setDefaultFormat()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const resetStream& a_crReset);
  //! Operator: Push reset stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crReset - Constant reference to the reset stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IStream::setDefaultFormat()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const resetStream& a_crReset);
  //! Operator: Write reset stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crReset - Constant reference to the reset stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IStream::setDefaultFormat()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const resetStream& a_crReset);
};
extern BASE_API resetStream reset;      //!< Global instance of the reset stream control operator.
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OFormatFlags.inl>
/*==========================================================================*/
#endif
