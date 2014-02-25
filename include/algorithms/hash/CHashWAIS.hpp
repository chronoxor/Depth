/*!
 *  \file    CHashWAIS.hpp Thinking Machines WAIS project hash function
 *           algorithm.
 *  \brief   Thinking Machines WAIS project hash function algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Thinking Machines WAIS project hash function algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   11.03.2007 00:54:25

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
#ifndef __CHASHWAIS_HPP__
#define __CHASHWAIS_HPP__
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
//! Thinking Machines WAIS project hash function algorithm.
/*!
    Thinking Machines WAIS project hash function.
*/
class BASE_API CHashWAIS :
  public IHash
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CHashWAIS TDepthCheckType;

  // Check CHashWAIS class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CHashWAIS();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashWAIS class.
  */
  CHashWAIS(const CHashWAIS& a_crInstance);
  //! Class virtual destructor.
  virtual ~CHashWAIS();

  //! Operator: Assign another CHashWAIS class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashWAIS class.
      \return Reference to the current class instance.
  */
  CHashWAIS& operator = (const CHashWAIS& a_crInstance);

  //! Set another CHashWAIS class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashWAIS class.
  */
  void set(const CHashWAIS& a_crInstance);

  // IHash interface overriding methods.
  virtual Tuint getHash() const;
  virtual Tbool initialize(const Tuint a_cSeed = 0);
  virtual Tuint hash(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  virtual Tbool close();

  //! Serialize CHashWAIS class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashWAIS class instances.
  /*!
      \param a_rInstance - Reference to another CHashWAIS class instance.
  */
  void swap(CHashWAIS& a_rInstance);

private:
  Tuint m_Hash;                         //!< Current hash value.
  static Tuint ms_cRandomHash[256];     //!< Random hash table.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/hash/CHashWAIS.inl>
/*==========================================================================*/
#endif
