/*!
 *  \file    CFilterFork.cpp Fork duplicate filter class simple duplicate
 *           data from another stream/filter and write it into the given
 *           stream.
 *  \brief   Fork duplicate filter class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fork duplicate filter class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   19.03.2009 21:19:17

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
#include <Depth/include/stream/CFilterFork.hpp>
/*==========================================================================*/
#ifndef __CFILTERFORK_CPP__
#define __CFILTERFORK_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CFilterFork::set(const CFilterFork& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CFilterFork class instance."))
  {
    return false;
  }

  // Initialize base filter class.
  if (!IFilter::set(a_crInstance))
    return false;

  // Set fork.
  return setFork(a_crInstance.m_pFork);
}
/*--------------------------------------------------------------------------*/
Tbool CFilterFork::onOpen(const EOpenType a_cOpenType)
{ CALL
  // Try to open base filter.
  if (!IFilter::onOpen(a_cOpenType))
    return false;

  // Try to open fork stream.
  if ((m_pFork != NULL) && !m_pFork->isOpened())
    return m_pFork->open();
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterFork::onReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Read data from the base filter.
  Tuint result = IFilter::onReadBinary(a_pBuffer, a_cSize);

  // Fork data into the fork writer.
  if (m_pFork != NULL)
  {
    // Check if the current fork writer is opened.
    ASSERT(m_pFork->isOpened(), STR("Cannot fork the buffer into the closed writer."))
    {
      return result;
    }

    m_pFork->writeBuffer(a_pBuffer, result);
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterFork::onReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Read data from the base filter.
  Tuint result = IFilter::onReadText(a_pBuffer, a_cSize);

  // Fork data into the fork writer.
  if (m_pFork != NULL)
  {
    // Check if the current fork writer is opened.
    ASSERT(m_pFork->isOpened(), STR("Cannot fork the buffer into the closed writer."))
    {
      return result;
    }

    m_pFork->writeBuffer(a_pBuffer, result);
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterFork::onReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  // Read data from the base filter.
  Tuint result = IFilter::onReadText(a_pBuffer, a_cSize);

  // Fork data into the fork writer.
  if (m_pFork != NULL)
  {
    // Check if the current fork writer is opened.
    ASSERT(m_pFork->isOpened(), STR("Cannot fork the buffer into the closed writer."))
    {
      return result;
    }

    m_pFork->writeBuffer(a_pBuffer, result);
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterFork::onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Write data into the base filter.
  Tuint result = IFilter::onWriteBinary(a_cpBuffer, a_cSize);

  // Fork data into the fork writer.
  if (m_pFork != NULL)
  {
    // Check if the current fork writer is opened.
    ASSERT(m_pFork->isOpened(), STR("Cannot fork the buffer into the closed writer."))
    {
      return result;
    }

    m_pFork->writeBuffer(a_cpBuffer, result);
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterFork::onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Write data into the base filter.
  Tuint result = IFilter::onWriteText(a_cpBuffer, a_cSize);

  // Fork data into the fork writer.
  if (m_pFork != NULL)
  {
    // Check if the current fork writer is opened.
    ASSERT(m_pFork->isOpened(), STR("Cannot fork the buffer into the closed writer."))
    {
      return result;
    }

    m_pFork->writeBuffer(a_cpBuffer, result);
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tuint CFilterFork::onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  // Write data into the base filter.
  Tuint result = IFilter::onWriteText(a_cpBuffer, a_cSize);

  // Fork data into the fork writer.
  if (m_pFork != NULL)
  {
    // Check if the current fork writer is opened.
    ASSERT(m_pFork->isOpened(), STR("Cannot fork the buffer into the closed writer."))
    {
      return result;
    }

    m_pFork->writeBuffer(a_cpBuffer, result);
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterFork::onFlush()
{ CALL
  // Try to flush base filter.
  if (!IFilter::onFlush())
    return false;

  // Try to flush fork stream.
  if ((m_pFork != NULL) && (m_pFork->isOpened()))
    return m_pFork->flush();
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CFilterFork::onClose()
{ CALL
  // Try to close base filter.
  if (!IFilter::onClose())
    return false;

  // Try to close fork stream.
  if ((m_pFork != NULL) && (m_pFork->isOpened()))
    return m_pFork->close();
  else
    return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
