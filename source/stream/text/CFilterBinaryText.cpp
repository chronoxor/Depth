/*!
 *  \file    CFilterBinaryText.cpp Binary/Text filter class converts ASCII
 *           and Unicode strings into binary byte stream and vice-versa.
 *  \brief   Binary/Text converter filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binary/Text converter filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   03.11.2009 21:16:04

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/text/CFilterBinaryText.hpp>
/*==========================================================================*/
#ifndef __CFILTERBINARYTEXT_CPP__
#define __CFILTERBINARYTEXT_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CFilterBinaryText::set(const CFilterBinaryText& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterBinaryText class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  if (!IFilter::set(a_crInstance))
    return false;

  // Initialize ASCII/Unicode flags.
  m_IsReadASCII = a_crInstance.m_IsReadASCII;
  m_IsWriteASCII = a_crInstance.m_IsWriteASCII;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBinaryText::onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  if (m_IsReadASCII)
    return a_rReader.readBuffer((Tsstr)a_pBuffer, a_cSize / sizeof(Tschar)) * sizeof(Tschar);
  else
    return a_rReader.readBuffer((Twstr)a_pBuffer, a_cSize / sizeof(Twchar)) * sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBinaryText::onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_rReader.readBuffer((Tptr)a_pBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBinaryText::onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  return a_rReader.readBuffer((Tptr)a_pBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBinaryText::onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  if (m_IsWriteASCII)
    return a_rWriter.writeBuffer((Tcsstr)a_cpBuffer, a_cSize / sizeof(Tschar)) * sizeof(Tschar);
  else
    return a_rWriter.writeBuffer((Tcwstr)a_cpBuffer, a_cSize / sizeof(Twchar)) * sizeof(Twchar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBinaryText::onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rWriter.writeBuffer((Tcptr)a_cpBuffer, a_cSize * sizeof(Tschar)) / sizeof(Tschar);
}
/*--------------------------------------------------------------------------*/
Tuint CFilterBinaryText::onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  return a_rWriter.writeBuffer((Tcptr)a_cpBuffer, a_cSize * sizeof(Twchar)) / sizeof(Twchar);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
