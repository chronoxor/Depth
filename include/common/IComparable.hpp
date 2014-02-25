/*!
 *  \file    IComparable.hpp Interface for all comparable classes that can be
 *           compared with 'compare()' virtual method.
 *  \brief   Comparable interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   11.10.2006 22:43:23

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
#ifndef __ICOMPARABLE_HPP__
#define __ICOMPARABLE_HPP__
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
//! Comparable interface.
/*!
    Comparable interface defines 'compare()' method to  compare  with  another
    class  instance.  This  interface  is  useful  for  classes  with  virtual
    constructor, generally for all IClonable classes.
*/
template <class T_Class>
class IComparable
{
public:
  //! IComparable value template type.
  typedef T_Class TType;

protected:
  //! Default interface protected constructor.
  IComparable();

public:
  //! Interface virtual destructor.
  virtual ~IComparable();

  //! Compare method.
  /*!
      Compare current class instance with another one.

      \param a_crInstance - Constant reference to another IComparable class instance.
      \return One of the following values: \n
              -1 - if this < a_crInstance \n
              =0 - if this = a_crInstance \n
              +1 - if this > a_crInstance \n
  */
  virtual Tsint compare(const TType& a_crInstance) const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/IComparable.inl>
/*==========================================================================*/
#endif
