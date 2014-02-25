/*!
 *  \file    CKernel.hpp Definitions of the mathematical kernel methods.
 *  \brief   Static class for mathematical kernel methods.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for mathematical kernel methods.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   26.01.2006 02:52:45

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
#ifndef __CKERNEL_HPP__
#define __CKERNEL_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class for mathematical kernel methods.
/*!
    Class represents mathematical kernel calculations.
*/
class BASE_API CKernel :
  public NDepth::NCommon::IStatic
{
public:
  //! Returns the value of the Biweight kernel at the point X.
  /*!
      \param a_cX - Value X.
      \return Biweight kernel value at the point X.
  */
  static Treal biweight(const Treal a_cX);

  //! Returns the value of the Cosine kernel at the point X.
  /*!
      \param a_cX - Value X.
      \return Cosine kernel value at the point X.
  */
  static Treal cosine(const Treal a_cX);

  //! Returns the value of the Epanechnikov kernel at the point X.
  /*!
      \param a_cX - Value X.
      \return Epanechnikov kernel value at the point X.
  */
  static Treal epanech(const Treal a_cX);

  //! Returns the value of the Gaussian kernel at the point X.
  /*!
      \param a_cX - Value X.
      \return Gaussian kernel value at the point X.
  */
  static Treal gaussian(const Treal a_cX);

  //! Returns the value of the Rectangular kernel at the point X.
  /*!
      \param a_cX - Value X.
      \return Rectangular kernel value at the point X.
  */
  static Treal rectangular(const Treal a_cX);

  //! Returns the value of the Triangular kernel at the point X.
  /*!
      \param a_cX - Value X.
      \return Triangular kernel value at the point X.
  */
  static Treal triangular(const Treal a_cX);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
