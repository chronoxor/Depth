/*!
 *  \file    CMethodLoadChooser.hpp Serialization helper class that wraps
 *           'load()' class method call during the serialization splitting
 *           operation for the 'serialize()' method.
 *  \brief   Serialization 'load()' method chooser helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Serialization 'load()' method chooser helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Serialization details
    VERSION:   1.0
    CREATED:   05.01.2007 23:50:38

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
#ifndef __CMETHODLOADCHOOSER_HPP__
#define __CMETHODLOADCHOOSER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/class/MConceptSerializable.hpp>
#include <Depth/include/concept/types/MConceptIArchive.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Serialization 'load()' method chooser helper class.
/*!
    Serialization 'load()' method chooser helper class  wraps  'load()'  class
    method  call  during  the  serialization  splitting  operation   for   the
    'serialize()' method.
*/
template <class T_Archive, class T_Class>
class CMethodLoadChooser :
  public NDepth::NCommon::IStatic
{
public:
  //! Invoke wrapped 'load()' class method.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \param a_rInstance - Reference to the serialized class instance.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  static Tbool invoke(T_Archive& a_rArchive, T_Class& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/serialization/details/CMethodLoadChooser.inl>
/*==========================================================================*/
#endif
