/*!
 *  \file    ISeekable.cpp Interface for all seekable classes. If some class
 *           contains data with random indexing access, it should implements
 *           this interface.
 *  \brief   Seekable interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Seekable interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   05.04.2006 20:59:42

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/common/ISeekable.hpp>
/*==========================================================================*/
#ifndef __ISEEKABLE_CPP__
#define __ISEEKABLE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool ISeekable::seek(const ESeekType a_cSeekType, const Tuint a_cOffset)
{ CALL
  switch (a_cSeekType)
  {
    case e_SEEK_BEGIN:
      return setPosition(a_cOffset);
    case e_SEEK_CURRENT_FORWARD:
      return setPosition(getPosition() + a_cOffset);
    case e_SEEK_CURRENT_BACKWARD:
      return ((a_cOffset > getPosition()) ? false : setPosition(getPosition() - a_cOffset));
    case e_SEEK_END:
      return ((a_cOffset < getSize()) ? setPosition(getSize() - a_cOffset - 1) : false);
  }
  return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
