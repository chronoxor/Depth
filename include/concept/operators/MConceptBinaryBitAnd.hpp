/*!
 *  \file    MConceptBinaryBitAnd.hpp Template checking conception. Checks
 *           if template arguments types can be used with binary '&' operator.
 *  \brief   Template checking conception for using with binary '&' operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template checking conception for using with binary '&' operator.

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
#ifndef __MCONCEPTBINARYBITAND_HPP__
#define __MCONCEPTBINARYBITAND_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept3.hpp>
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
//! Template checking conception class for using with binary '&' operator.
/*!
    This conception checks if template argument types can be used with  binary
    '&' operator.
*/
template <typename T_ResultType, typename T_FirstType = T_ResultType, typename T_SecondType = T_FirstType>
class MConceptBinaryBitAnd :
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
  MConceptBinaryBitAnd();
  //! Meta-class protected destructor.
  virtual ~MConceptBinaryBitAnd();

private:
  typename NTraits::MTraitsConcept<T_FirstType>::attribute  m_X; //!< First operator value.
  typename NTraits::MTraitsConcept<T_SecondType>::attribute m_Y; //!< Second operator value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/operators/MConceptBinaryBitAnd.inl>
/*==========================================================================*/
#endif
