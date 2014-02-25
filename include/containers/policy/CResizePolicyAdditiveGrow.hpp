/*!
 *  \file    CResizePolicyAdditiveGrow.hpp Growing additive resize policy
 *           class. It uses additive resize factor allocation strategy.
 *  \brief   Growing additive resize policy class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Growing additive resize policy class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   15.03.2006 23:36:31

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
#ifndef __CRESIZEPOLICYADDITIVEGROW_HPP__
#define __CRESIZEPOLICYADDITIVEGROW_HPP__
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
//! Growing additive resize policy class.
/*!
    Additive resize strategy uses allocation range sizes which  are  divisible
    by resize factor. For example, if we have resize factor value 3 and try to
    allocate 7 container items, then we have to allocate  block  with  size  9
    which is more than 7 and is divisible by 3.

    Formula: size = (n / factor) * factor + (n % factor)

    Growing policy declares that buffer will  not  be  reallocated  under  the
    lower capacity bound, which is always equals to 0.
*/
class BASE_API CResizePolicyAdditiveGrow :
  public IResizePolicy
{
  //! Type for MConceptIResizePolicy constraint checking.
  typedef CResizePolicyAdditiveGrow TResizePolicyCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CResizePolicyAdditiveGrow TDepthCheckType;

  // Check CResizePolicyAdditiveGrow class constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check CResizePolicyAdditiveGrow class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Initialize resize policy with resize factor.
  /*!
      Note that if resize factor is 0, constructor will initialize policy with
      resize factor value 1, which is default.

      \param a_cResizeFactor - Resize factor (default is NDepth::NContainers::NPolicy::CResizePolicyAdditiveGrow::getDefaultResizeFactor()).
  */
  CResizePolicyAdditiveGrow(const Tuint a_cResizeFactor = CResizePolicyAdditiveGrow::getDefaultResizeFactor());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicyAdditiveGrow class.
  */
  CResizePolicyAdditiveGrow(const CResizePolicyAdditiveGrow& a_crInstance);
  //! Class virtual destructor.
  virtual ~CResizePolicyAdditiveGrow();

  //! Operator: Assign another CResizePolicyAdditiveGrow class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicyAdditiveGrow class.
      \return Reference to the current class instance.
  */
  CResizePolicyAdditiveGrow& operator = (const CResizePolicyAdditiveGrow& a_crInstance);

  //! Set another CResizePolicyAdditiveGrow class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicyAdditiveGrow class.
  */
  void set(const CResizePolicyAdditiveGrow& a_crInstance);

  // IResizePolicy interface overriding methods.
  virtual Tbool setResizeFactor(const Tuint a_cResizeFactor);
  virtual Tuint resize(const Tuint a_cSize);

  //! Get default resize factor.
  /*!
      For current type of resize policy this value is 1.

      \return Default resize factor for current resize policy.
  */
  static Tuint getDefaultResizeFactor();

  //! Serialize CResizePolicyAdditiveGrow class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CResizePolicyAdditiveGrow class instances.
  /*!
      \param a_rInstance - Reference to another CResizePolicyAdditiveGrow class instance.
  */
  void swap(CResizePolicyAdditiveGrow& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/policy/CResizePolicyAdditiveGrow.inl>
/*==========================================================================*/
#endif
