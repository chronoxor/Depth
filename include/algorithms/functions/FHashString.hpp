/*!
 *  \file    FHashString.hpp Hash string function class.
 *  \brief   Hash string function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash string function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   06.05.2008 22:20:37

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
#ifndef __FHASHSTRING_HPP__
#define __FHASHSTRING_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/hash/CHashWAIS.hpp>
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIHash.hpp>
#include <Depth/include/traits/MTraitsString.hpp>
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
//! Hash string function class.
/*!
    This class implements hash string  function  object  which  performs  hash
    operation for the given string and returns hash value. Hash algorithm type
    is provided by template argument.  Default  hash  algorithm  is  'Thinking
    Machines WAIS project hash function'.

    \see NDepth::NAlgorithms::NHash::CHashWAIS
*/
template <typename T_Argument, class T_HashAlgorithm = NHash::CHashWAIS>
class FHashString
{
  //! Argument type for the MConceptStringConst constraint checking.
  typedef T_Argument TStringConstCheckType;
  //! Hash algorithm type for the MConceptIHash constraint checking.
  typedef T_HashAlgorithm TIHashCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FHashString<T_Argument, T_HashAlgorithm> TDepthCheckType;

  // Check T_Argument template argument constraint to be a constant string type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptStringConst, TStringConstCheckType);
  // Check T_HashAlgorithm template argument constraint to be a hash algorithm type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIHash, TIHashCheckType);
  // Check FHashString class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef Tuint TReturn;
  //! Function argument type.
  typedef T_Argument TArgument;
  //! Function hash algorithm type.
  typedef T_HashAlgorithm THashAlgorithm;

  //! Default class constructor.
  /*!
      \param a_fHashAlgorithm - Instance of the hash algorithm (default is T_HashAlgorithm()).
      \param a_cSeed - Initial seed value of the hash algorithm (default is 0).
  */
  FHashString(T_HashAlgorithm a_fHashAlgorithm = T_HashAlgorithm(), const Tuint a_cSeed = 0);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the FHashString class.
  */
  FHashString(const FHashString<T_Argument, T_HashAlgorithm>& a_crInstance);

  //! Operator: Call function.
  /*!
      \param a_crArgument - Function argument.
      \return Function return value.
  */
  Tuint operator () (const T_Argument& a_crArgument) const;

  //! Serialize FHashString class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FHashString class instances.
  /*!
      \param a_rInstance - Reference to another FHashString class instance.
  */
  void swap(FHashString<T_Argument, T_HashAlgorithm>& a_rInstance);

private:
  mutable T_HashAlgorithm m_fHashAlgorithm; //!< Current hash algorithm.
  Tuint m_Seed;                             //!< Seed value for the hash algorithm.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FHashString.inl>
/*==========================================================================*/
#endif
