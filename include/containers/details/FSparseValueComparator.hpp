/*!
 *  \file    FSparseValueComparator.hpp Sparse array value comparator function
 *           class.
 *  \brief   Sparse array value comparator function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sparse array value comparator function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   26.09.2007 02:17:58

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
#ifndef __FSPARSEVALUECOMPARATOR_HPP__
#define __FSPARSEVALUECOMPARATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/details/CSparseValue.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Sparse array value comparator function class.
/*!
    This class implements function object which  performs  'LessThan'  compare
    operation with sparse array values (CSparseValue).
*/
template <typename T_Type>
class FSparseValueComparator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef FSparseValueComparator<T_Type> TDepthCheckType;

  // Check FSparseValueComparator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef Tbool TReturn;
  //! Function first argument type.
  typedef const CSparseValue<T_Type>& TArgument1;
  //! Function second argument type.
  typedef const CSparseValue<T_Type>& TArgument2;

  //! Operator: Call function.
  /*!
      \param a_crArgument1 - Constant reference to the first function argument.
      \param a_crArgument2 - Constant reference to the second function argument.
      \return Function return value.
  */
  Tbool operator () (const CSparseValue<T_Type>& a_crArgument1, const CSparseValue<T_Type>& a_crArgument2) const;

  //! Serialize FSparseValueComparator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FSparseValueComparator class instances.
  /*!
      \param a_rInstance - Reference to another FSparseValueComparator class instance.
  */
  void swap(FSparseValueComparator<T_Type>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/details/FSparseValueComparator.inl>
/*==========================================================================*/
#endif
