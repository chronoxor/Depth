/*!
 *  \file    ISeekable.inl Interface for all seekable classes. If some class
 *           contains data with random indexing access, it should implements
 *           this interface.
 *  \brief   Seekable interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Seekable interface (inline).

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
#ifndef __ISEEKABLE_INL__
#define __ISEEKABLE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline ISeekable::ISeekable()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline ISeekable::~ISeekable()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool load(T_Archive& a_rArchive, NCommon::ISeekable::ESeekType& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NCommon::ISeekable::ESeekType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set type of the seek method.
  switch (value)
  {
    case 0:
      a_rInstance = NCommon::ISeekable::e_SEEK_BEGIN;
      break;
    case 1:
      a_rInstance = NCommon::ISeekable::e_SEEK_CURRENT_FORWARD;
      break;
    case 2:
      a_rInstance = NCommon::ISeekable::e_SEEK_CURRENT_BACKWARD;
      break;
    case 3:
      a_rInstance = NCommon::ISeekable::e_SEEK_END;
      break;
    default:
      WARNING(STR("Cannot load invalid type of the seek method from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool save(T_Archive& a_rArchive, const NCommon::ISeekable::ESeekType& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get type of the seek method.
  switch (a_crInstance)
  {
    case NCommon::ISeekable::e_SEEK_BEGIN:
      value = 0;
      break;
    case NCommon::ISeekable::e_SEEK_CURRENT_FORWARD:
      value = 1;
      break;
    case NCommon::ISeekable::e_SEEK_CURRENT_BACKWARD:
      value = 2;
      break;
    case NCommon::ISeekable::e_SEEK_END:
      value = 3;
      break;
    default:
      WARNING(STR("Cannot save invalid type of the seek method into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NCommon::ISeekable::ESeekType")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool serialize(T_Archive& a_rArchive, NCommon::ISeekable::ESeekType& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
