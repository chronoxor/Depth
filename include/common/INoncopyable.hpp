/*!
 *  \file    INoncopyable.hpp Interface for all classes that could not by
 *           copied.
 *  \brief   Noncopyable interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Noncopyable interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   31.01.2006 00:25:42

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
#ifndef __INONCOPYABLE_HPP__
#define __INONCOPYABLE_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Noncopyable interface.
/*!
    This interface should be used for all classes that cannot  copy themselves
    from one instance into another.
*/
class BASE_API INoncopyable
{
protected:
  //! Default interface protected constructor.
  INoncopyable();

private:
  //! Copy constructor.
  /*!
      To prevent coping of class instances we force  copy  constructor  to  be
      private.

      \param a_crInstance - Constant reference to the another instance of the INoncopyable class.
  */
  INoncopyable(const INoncopyable& a_crInstance);

  //! Operator: Assign another INoncopyable class instance.
  /*!
      To prevent coping of class instances we  force  assign  operator  to  be
      private.

      \param a_crInstance - Constant reference to the another instance of INoncopyable class.
      \return Reference to the current INoncopyable class instance.
  */
  INoncopyable& operator = (const INoncopyable& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/INoncopyable.inl>
/*==========================================================================*/
#endif
