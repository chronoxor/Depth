/*!
 *  \file    FMapComparator.hpp Map comparator function class.
 *  \brief   Map comparator function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Map comparator function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   27.09.2006 20:51:42

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
#ifndef __FMAPCOMPARATOR_HPP__
#define __FMAPCOMPARATOR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/utility/CPair.hpp>
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
//! Map comparator function class.
/*!
    This class  implements  function  object  which  performs  'LessThan'  map
    compare operation with first pair values.
*/
template <typename T_Key, typename T_Value, typename T_LessThanBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Key&> >
class FMapComparator
{
  //! Type for the MConceptPredicate2 constraint checking.
  typedef T_LessThanBinaryPredicate TPredicate2CheckType;
  //! Type for the MConceptPredicate2 constraint checking arguments.
  typedef const T_Key& TPredicate2ArgumentCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate> TDepthCheckType;

  // Check T_LessThanBinaryPredicate template argument constraint to be a suitable binary predicate type.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check FMapComparator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Function return type.
  typedef Tbool TReturn;
  //! Function first argument type.
  typedef const NUtility::CPair<T_Key, T_Value>& TArgument1;
  //! Function second argument type.
  typedef const NUtility::CPair<T_Key, T_Value>& TArgument2;

  //! Default class constructor.
  /*!
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_LessThanBinaryPredicate()).
  */
  FMapComparator(T_LessThanBinaryPredicate a_fLessThan = T_LessThanBinaryPredicate());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the FMapComparator class.
  */
  FMapComparator(const FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>& a_crInstance);

  //! Operator: Call function.
  /*!
      \param a_crArgument1 - Constant reference to the first function argument.
      \param a_crArgument2 - Constant reference to the second function argument.
      \return Function return value.
  */
  Tbool operator () (const NUtility::CPair<T_Key, T_Value>& a_crArgument1, const NUtility::CPair<T_Key, T_Value>& a_crArgument2) const;

  //! Serialize FMapComparator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two FMapComparator class instances.
  /*!
      \param a_rInstance - Reference to another FMapComparator class instance.
  */
  void swap(FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>& a_rInstance);

private:
  T_LessThanBinaryPredicate m_fLessThan; //!< Current 'LessThan' binary predicate.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FMapComparator.inl>
/*==========================================================================*/
#endif
