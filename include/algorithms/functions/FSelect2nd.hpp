/*!
 *  \file    FSelect2nd.hpp Unary select 2'nd pair value function class.
 *  \brief   Unary select 2'nd pair value function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unary select 2'nd pair value function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   21.05.2007 20:06:53

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
#ifndef __FSELECT2ND_HPP__
#define __FSELECT2ND_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIPair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Unary select 2'nd pair value function class.
/*!
    This class implements function object which selects and returns 2'nd  pair
    value.
*/
template <class T_Pair>
class FSelect2nd
{
  //! Type for MConceptIPair constraint checking.
  typedef T_Pair TPairCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FSelect2nd<T_Pair> TDepthCheckType;

  // Check T_Pair template argument constraint to be a pair type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIPair, TPairCheckType);
  // Check FSelect2nd class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef const typename T_Pair::TSecond& TReturn;
  //! Function argument type.
  typedef const T_Pair& TArgument;

  //! Operator: Call function - select 2'nd pair value.
  /*!
      \param a_rPair - Reference to the pair instance.
      \return Reference to the 2'nd pair value.
  */
  typename T_Pair::TSecond& operator () (T_Pair& a_rPair) const;
  //! Operator: Call function - select 2'nd constant pair value.
  /*!
      \param a_crPair - Constant reference to the pair instance.
      \return Constant reference to the 2'nd pair value.
  */
  const typename T_Pair::TSecond& operator () (const T_Pair& a_crPair) const;

  //! Serialize FSelect2nd class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FSelect2nd class instances.
  /*!
      \param a_rInstance - Reference to another FSelect2nd class instance.
  */
  void swap(FSelect2nd<T_Pair>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FSelect2nd.inl>
/*==========================================================================*/
#endif
