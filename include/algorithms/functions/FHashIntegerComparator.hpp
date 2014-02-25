/*!
 *  \file    FHashIntegerComparator.hpp Hash integer comparator function class.
 *  \brief   Hash integer comparator function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash integer comparator function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   17.02.2010 02:15:44

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
#ifndef __FHASHINTEGERCOMPARATOR_HPP__
#define __FHASHINTEGERCOMPARATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptInteger.hpp>
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
//! Hash string comparator function class.
/*!
    This class implements function object which  performs  string  comparation
    (taken into account their cases) for hash table container.
*/
template <typename T_Argument1, typename T_Argument2 = T_Argument1>
class FHashIntegerComparator
{
  //! First argument type for the MConceptInteger constraint checking.
  typedef T_Argument1 TArgument1IntegerCheckType;
  //! Second argument type for the MConceptInteger constraint checking.
  typedef T_Argument2 TArgument2IntegerCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FHashIntegerComparator<T_Argument1, T_Argument2> TDepthCheckType;

  // Check T_Argument1 template argument constraint to be an integer type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptInteger, TArgument1IntegerCheckType);
  // Check T_Argument2 template argument constraint to be an integer type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptInteger, TArgument2IntegerCheckType);
  // Check FHashIntegerComparator class constraint to be a real Depth type.
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

  //! Serialize FHashIntegerComparator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FHashIntegerComparator class instances.
  /*!
      \param a_rInstance - Reference to another FHashIntegerComparator class instance.
  */
  void swap(FHashIntegerComparator<T_Argument1, T_Argument2>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FHashIntegerComparator.inl>
/*==========================================================================*/
#endif
