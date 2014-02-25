/*!
 *  \file    CClassFunctorMaker.hpp Utility class that helps to create
 *           CClassFunctor instances from specific values.
 *  \brief   Class functor maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Class functor maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors
    VERSION:   1.0
    CREATED:   17.05.2006 03:03:13

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
#ifndef __CCLASSFUNCTORMAKER_HPP__
#define __CCLASSFUNCTORMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/functors/CClassFunctorX.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Class functor maker class.
/*!
    With this utility class template CClassFunctor instances  can  be  created
    without specifying template arguments.
*/
class CClassFunctorMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CClassFunctor instance from specified functor class method.
  /*!
      \param a_fMethod - Pointer to the class method.
      \return CClassFunctor class instance.
  */
  template <typename T_Method>
  static CClassFunctor<T_Method> make(T_Method a_fMethod);

  //! Make CClassFunctor instance from specified CClassFunctor class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CClassFunctor class.
      \return CClassFunctor class instance.
  */
  template <typename T_Method>
  static CClassFunctor<T_Method> make(const CClassFunctor<T_Method>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/CClassFunctorMaker.inl>
/*==========================================================================*/
#endif
