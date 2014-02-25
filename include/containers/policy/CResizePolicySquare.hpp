/*!
 *  \file    CResizePolicySquare.hpp Square resize policy class. It uses
 *           square resize factor allocation strategy.
 *  \brief   Square resize policy class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Square resize policy class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   16.03.2006 21:12:42

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
#ifndef __CRESIZEPOLICYSQUARE_HPP__
#define __CRESIZEPOLICYSQUARE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptIResizePolicy.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Square resize policy class.
/*!
    Square resize strategy uses allocation range sizes which are close to 2^x.
    For example, if we try to allocate 7 container  items,  then  we  have  to
    allocate block with size 8 which is more than 7 and equals to 2^3.

    Formula: size = 2^n
*/
class BASE_API CResizePolicySquare :
  public IResizePolicy
{
  //! Type for MConceptIResizePolicy constraint checking.
  typedef CResizePolicySquare TResizePolicyCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CResizePolicySquare TDepthCheckType;

  // Check CResizePolicySquare class constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check CResizePolicySquare class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Resize factor in this resize policy is an unused attribute, but  we  add
      initialization of this attribute for compatibility with IResizePolicy.

      \param a_cResizeFactor - Resize factor (default is NDepth::NContainers::NPolicy::CResizePolicySquare::getDefaultResizeFactor()).
  */
  CResizePolicySquare(const Tuint a_cResizeFactor = CResizePolicySquare::getDefaultResizeFactor());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicySquare class.
  */
  CResizePolicySquare(const CResizePolicySquare& a_crInstance);
  //! Class virtual destructor.
  virtual ~CResizePolicySquare();

  //! Operator: Assign another CResizePolicySquare class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicySquare class.
      \return Reference to the current class instance.
  */
  CResizePolicySquare& operator = (const CResizePolicySquare& a_crInstance);

  //! Set another CResizePolicySquare class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicySquare class.
  */
  void set(const CResizePolicySquare& a_crInstance);

  // IResizePolicy interface overriding methods.
  virtual Tbool setResizeFactor(const Tuint a_cResizeFactor);
  virtual Tuint resize(const Tuint a_cSize);

  //! Get default resize factor.
  /*!
      For current type of resize policy this value is 0.

      \return Default resize factor for current resize policy.
  */
  static Tuint getDefaultResizeFactor();

  //! Serialize CResizePolicySquare class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CResizePolicySquare class instances.
  /*!
      \param a_rInstance - Reference to another CResizePolicySquare class instance.
  */
  void swap(CResizePolicySquare& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/policy/CResizePolicySquare.inl>
/*==========================================================================*/
//! \example example-containers-CResizePolicySquare.cpp
/*==========================================================================*/
#endif
