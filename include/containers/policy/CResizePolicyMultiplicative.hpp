/*!
 *  \file    CResizePolicyMultiplicative.hpp Multiplicative resize policy
 *           interface. It use multiplicative resize factor allocation
 *           strategy.
 *  \brief   Multiplicative resize policy class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Multiplicative resize policy class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   16.03.2006 20:20:31

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
#ifndef __CRESIZEPOLICYMULTIPLICATIVE_HPP__
#define __CRESIZEPOLICYMULTIPLICATIVE_HPP__
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
//! Multiplicative resize policy class.
/*!
    Multiplicative resize strategy  uses  allocation  range  sizes  which  are
    growing according their resize factor. For  example,  if  we  have  resize
    factor value 3, old container size is 6 and try to  allocate  7  container
    items, then we have to allocate block with size 18 which is euqal  to  old
    container size multiplied by resize factor.

    Formula: size = ((n / (factor * size)) + (n % (factor * size))) * factor * size
*/
class BASE_API CResizePolicyMultiplicative :
  public IResizePolicy
{
  //! Type for MConceptIResizePolicy constraint checking.
  typedef CResizePolicyMultiplicative TResizePolicyCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CResizePolicyMultiplicative TDepthCheckType;

  // Check CResizePolicyMultiplicative class constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check CResizePolicyMultiplicative class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Initialize resize policy with resize factor.
  /*!
      Note that if resize factor is less than 2, constructor  will  initialize
      policy with resize factor value 2, which is default.

      \param a_cResizeFactor - Resize factor (default is NDepth::NContainers::NPolicy::CResizePolicyMultiplicative::getDefaultResizeFactor()).
  */
  CResizePolicyMultiplicative(const Tuint a_cResizeFactor = CResizePolicyMultiplicative::getDefaultResizeFactor());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicyMultiplicative class.
  */
  CResizePolicyMultiplicative(const CResizePolicyMultiplicative& a_crInstance);
  //! Class virtual destructor.
  virtual ~CResizePolicyMultiplicative();

  //! Operator: Assign another CResizePolicyMultiplicative class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicyMultiplicative class.
      \return Reference to the current class instance.
  */
  CResizePolicyMultiplicative& operator = (const CResizePolicyMultiplicative& a_crInstance);

  //! Set another CResizePolicyMultiplicative class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CResizePolicyMultiplicative class.
  */
  void set(const CResizePolicyMultiplicative& a_crInstance);

  // IResizePolicy interface overriding methods.
  virtual Tbool setResizeFactor(const Tuint a_cResizeFactor);
  virtual Tuint resize(const Tuint a_cSize);

  //! Get default resize factor.
  /*!
      For current type of resize policy this value is 2.

      \return Default resize factor for current resize policy.
  */
  static Tuint getDefaultResizeFactor();

  //! Serialize CResizePolicyMultiplicative class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CResizePolicyMultiplicative class instances.
  /*!
      \param a_rInstance - Reference to another CResizePolicyMultiplicative class instance.
  */
  void swap(CResizePolicyMultiplicative& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/policy/CResizePolicyMultiplicative.inl>
/*==========================================================================*/
//! \example example-containers-CResizePolicyMultiplicative.cpp
/*==========================================================================*/
#endif
