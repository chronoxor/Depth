/*!
 *  \file    MConceptUnaryPrefixDec.hpp Template checking conception. Checks
 *           if template arguments types can be used with unary prefix '--'
 *           operator.
 *  \brief   Template checking conception for using with unary prefix '--' operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template checking conception for using with unary prefix '--' operator.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Operators conception checking
    VERSION:   1.0
    CREATED:   16.01.2006 22:37:48

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
    with this program; if not, write to the Free Software Foundation, Dec., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __MCONCEPTUNARYPREFIXDEC_HPP__
#define __MCONCEPTUNARYPREFIXDEC_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept2.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Template checking conception class for using with unary prefix '--' operator.
/*!
    This conception checks if template argument types can be used  with  unary
    prefix '--' operator.
*/
template <typename T_ResultType, typename T_FirstType = T_ResultType>
class MConceptUnaryPrefixDec :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

  //! Method for checking of using operator.
  /*!
      \return Result value.
  */
  T_ResultType constraintsOperator();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptUnaryPrefixDec();
  //! Meta-class protected destructor.
  virtual ~MConceptUnaryPrefixDec();

private:
  typename NTraits::MTraitsConcept<T_FirstType>::attribute m_X; //!< First operator value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/operators/MConceptUnaryPrefixDec.inl>
/*==========================================================================*/
#endif
