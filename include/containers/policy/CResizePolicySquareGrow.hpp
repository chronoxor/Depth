/*!
 *  \file    CResizePolicySquareGrow.hpp Growing square resize policy class.
 *           It uses square resize factor allocation strategy.
 *  \brief   Growing square resize policy class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Growing square resize policy class.

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
#ifndef __CRESIZEPOLICYSQUAREGROW_HPP__
#define __CRESIZEPOLICYSQUAREGROW_HPP__
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
//! Growing square resize policy class.
/*!
    Square resize strategy uses allocation range sizes which are close to 2^x.
    For example, if we try to allocate 7 container  items,  then  we  have  to
    allocate block with size 8 which is more than 7 and equals to 2^3.

    Formula: size = 2^n

    Growing policy declares that buffer will  not  be  reallocated  under  the
    lower capacity bound, which is always equals to 0.
*/
class BASE_API CResizePolicySquareGrow :
  public IResizePolicy
{
  //! Type for MConceptIResizePolicy constraint checking.
  typedef CResizePolicySquareGrow TResizePolicyCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CResizePolicySquareGrow TDepthCheckType;

  // Check CResizePolicySquareGrow class constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check CResizePolicySquareGrow class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Resize factor in this resize policy is an unused attribute, but  we  add
      initialization of this attribute for compatibility with IResizePolicy.

      \param a_cResizeFactor - Resize factor (default is NDepth::NContainers::NPolicy::CResizePolicySquareGrow::getDefaultResizeFactor()).
  */
  CResizePolicySquareGrow(const Tuint a_cResizeFactor = CResizePolicySquareGrow::getDefaultResizeFactor());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicySquareGrow class.
  */
  CResizePolicySquareGrow(const CResizePolicySquareGrow& a_crInstance);
  //! Class virtual destructor.
  virtual ~CResizePolicySquareGrow();

  //! Operator: Assign another CResizePolicySquareGrow class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicySquareGrow class.
      \return Reference to the current class instance.
  */
  CResizePolicySquareGrow& operator = (const CResizePolicySquareGrow& a_crInstance);

  //! Set another CResizePolicySquareGrow class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicySquareGrow class.
  */
  void set(const CResizePolicySquareGrow& a_crInstance);

  // IResizePolicy interface overriding methods.
  virtual Tbool setResizeFactor(const Tuint a_cResizeFactor);
  virtual Tuint resize(const Tuint a_cSize);

  //! Get default resize factor.
  /*!
      For current type of resize policy this value is 0.

      \return Default resize factor for current resize policy.
  */
  static Tuint getDefaultResizeFactor();

  //! Serialize CResizePolicySquareGrow class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CResizePolicySquareGrow class instances.
  /*!
      \param a_rInstance - Reference to another CResizePolicySquareGrow class instance.
  */
  void swap(CResizePolicySquareGrow& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/policy/CResizePolicySquareGrow.inl>
/*==========================================================================*/
#endif
