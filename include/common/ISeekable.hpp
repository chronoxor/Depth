/*!
 *  \file    ISeekable.hpp Interface for all seekable classes. If some class
 *           contains data with random indexing access, it should implements
 *           this interface.
 *  \brief   Seekable interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Seekable interface.

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
#ifndef __ISEEKABLE_HPP__
#define __ISEEKABLE_HPP__
/*==========================================================================*/
#include <Depth/include/serialization.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Seekable interface.
/*!
    This interface useful for all classes that  have  random  access  to  some
    information. With seekable interface you can seek get  size  of  the  data
    buffer and seek to any position of it.
*/
class BASE_API ISeekable
{
public:
  enum ESeekType                         //! Type of the seek method.
  {
    e_SEEK_BEGIN,                        //!< Seek forward from begin of data buffer.
    e_SEEK_CURRENT_FORWARD,              //!< Seek forward from current position of data buffer.
    e_SEEK_CURRENT_BACKWARD,             //!< Seek backward from current position of data buffer.
    e_SEEK_END                           //!< Seek backward from end of data buffer.
  };

protected:
  //! Default interface protected constructor.
  ISeekable();

public:
  //! Interface virtual destructor.
  virtual ~ISeekable();

  //! Get data buffer size.
  /*!
      \return Size of seekable data buffer.
  */
  virtual Tuint getSize() const = 0;

  //! Set new current position in data buffer.
  /*!
      \param a_cPosition - New current position in data buffer.
      \return true  - if new position was successfully set. \n
              false - if new position was not successfully set. \n
  */
  virtual Tbool setPosition(const Tuint a_cPosition) = 0;
  //! Get new current position in data buffer.
  /*!
      \return Current position in data buffer.
  */
  virtual Tuint getPosition() const = 0;

  //! Perform a seek through data buffer.
  /*!
      \param a_cSeekType - Type of seek method.
      \param a_cOffset - Offset.
      \return true  - if seek process was successful. \n
              false - if seek process was not successful. \n
  */
  virtual Tbool seek(const ESeekType a_cSeekType, const Tuint a_cOffset);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SERIALIZATION FUNCTION DECLARATIONS                                      */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
//! Serialization load type of the seek method.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized type of the seek method instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NCommon::ISeekable::ESeekType& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save type of the seek method.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized type of the seek method instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NCommon::ISeekable::ESeekType& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize type of the seek method.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized type of the seek method instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NCommon::ISeekable::ESeekType& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/ISeekable.inl>
/*==========================================================================*/
#endif
