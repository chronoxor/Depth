/*!
 *  \file    FStringComparator.hpp String comparator function class.
 *  \brief   String comparator function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String comparator function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   24.06.2010 21:32:44

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
#ifndef __FSTRINGCOMPARATOR_HPP__
#define __FSTRINGCOMPARATOR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringCompare.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
//! String comparator function class.
/*!
    This class implements function object which  performs  string  comparation
    (taken into account their cases) to check if two strings are equal.
*/
template <typename T_Argument1, typename T_Argument2 = T_Argument1>
class FStringComparator
{
  //! First argument type for the MConceptStringConst constraint checking.
  typedef T_Argument1 TArgument1StringConstCheckType;
  //! Second argument type for the MConceptStringConst constraint checking.
  typedef T_Argument2 TArgument2StringConstCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FStringComparator<T_Argument1, T_Argument2> TDepthCheckType;

  // Check T_Argument1 template argument constraint to be a constant string type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptStringConst, TArgument1StringConstCheckType);
  // Check T_Argument2 template argument constraint to be a constant string type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptStringConst, TArgument2StringConstCheckType);
  // Check FStringComparator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef Tbool TReturn;
  //! Function first argument type.
  typedef T_Argument1 TArgument1;
  //! Function second argument type.
  typedef T_Argument2 TArgument2;

  //! Operator: Call function.
  /*!
      \param a_crArgument1 - First function argument.
      \param a_crArgument2 - Second function argument.
      \return Function return value.
  */
  Tbool operator () (const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2) const;

  //! Serialize FStringComparator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FStringComparator class instances.
  /*!
      \param a_rInstance - Reference to another FStringComparator class instance.
  */
  void swap(FStringComparator<T_Argument1, T_Argument2>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FStringComparator.inl>
/*==========================================================================*/
#endif
