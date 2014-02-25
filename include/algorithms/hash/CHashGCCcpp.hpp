/*!
 *  \file    CHashGCCcpp.hpp GCC cpp hash function algorithm.
 *  \brief   GCC cpp hash function algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GCC cpp hash function algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   10.03.2007 23:16:43

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
#ifndef __CHASHGCCCPP_HPP__
#define __CHASHGCCCPP_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/hash/IHash.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! GCC cpp hash function algorithm.
/*!
    GCC cpp hash function.
*/
class BASE_API CHashGCCcpp :
  public IHash
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CHashGCCcpp TDepthCheckType;

  // Check CHashGCCcpp class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CHashGCCcpp();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashGCCcpp class.
  */
  CHashGCCcpp(const CHashGCCcpp& a_crInstance);
  //! Class virtual destructor.
  virtual ~CHashGCCcpp();

  //! Operator: Assign another CHashGCCcpp class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashGCCcpp class.
      \return Reference to the current class instance.
  */
  CHashGCCcpp& operator = (const CHashGCCcpp& a_crInstance);

  //! Set another CHashGCCcpp class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashGCCcpp class.
  */
  void set(const CHashGCCcpp& a_crInstance);

  // IHash interface overriding methods.
  virtual Tuint getHash() const;
  virtual Tbool initialize(const Tuint a_cSeed = 0);
  virtual Tuint hash(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  virtual Tbool close();

  //! Serialize CHashGCCcpp class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashGCCcpp class instances.
  /*!
      \param a_rInstance - Reference to another CHashGCCcpp class instance.
  */
  void swap(CHashGCCcpp& a_rInstance);

private:
  Tuint m_Hash;                         //!< Current hash value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/hash/CHashGCCcpp.inl>
/*==========================================================================*/
#endif
