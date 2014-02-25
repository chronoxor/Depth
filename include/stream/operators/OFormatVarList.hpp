/*!
 *  \file    OFormatVarList.hpp Format using variable arguments list stream
 *           control operator. It is used to format output or unformat input
 *           through stream operators using variable arguments list.
 *  \brief   Format using variable arguments list stream control operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Format using variable arguments list stream control operator.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 23:08:59

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
#ifndef __OFORMATVARLIST_HPP__
#define __OFORMATVARLIST_HPP__
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
//! Format using variable arguments list stream control operator.
/*!
    Format using variable arguments list stream control operator  is  used  to
    format output or unformat input through stream  operators  using  variable
    arguments list.
*/
class BASE_API formatVarList
{
public:
  //! Format with ASCII C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \param a_VariableList - Variable arguments list.
  */
  formatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList);
  //! Format with Unicode C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \param a_VariableList - Variable arguments list.
  */
  formatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList);
  //! Format with ASCII string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringASCII class.
      \param a_VariableList - Variable arguments list.
  */
  formatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList);
  //! Format with Unicode string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringUnicode class.
      \param a_VariableList - Variable arguments list.
  */
  formatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList);

  //! Class destructor.
  ~formatVarList();

  //! Operator: Read format stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFormat - Constant reference to the format stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::readFormat()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const formatVarList& a_crFormat);
  //! Operator: Peek format stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFormat - Constant reference to the format stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::peekFormat()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const formatVarList& a_crFormat);
  //! Operator: Push format stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFormat - Constant reference to the format stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::pushFormat()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const formatVarList& a_crFormat);
  //! Operator: Write format stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crFormat - Constant reference to the format stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IWriter::writeFormat()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const formatVarList& a_crFormat);

private:
  Tuint                   m_Type;                //!< Type of the format operation.
  Tcsstr                  m_FormatBufferASCII;   //!< ASCII format string buffer.
  Tcwstr                  m_FormatBufferUnicode; //!< Unicode format string buffer.
  NString::CStringASCII   m_FormatStringASCII;   //!< ASCII format string.
  NString::CStringUnicode m_FormatStringUnicode; //!< Unicode format string.
  va_list                 m_VariableList;        //!< Variable arguments list.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OFormatVarList.inl>
/*==========================================================================*/
#endif
