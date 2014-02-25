/*!
 *  \file    MConstraint.hpp Base constraint meta-class which gives utility
 *           methods for template arguments checking.
 *  \brief   Base constraint meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base constraint meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template arguments checking conception
    VERSION:   1.0
    CREATED:   15.01.2006 02:31:43

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
#ifndef __MCONSTRAINT_HPP__
#define __MCONSTRAINT_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Base constraint meta-class.
/*!
    This meta-class is the base constraint concept  meta-class.  It  has  some
    utilities methods which help to disable compiler warnings during  template
    arguments checking. Other methods check if template  arguments  belong  to
    fixed types.

    To use template arguments checking in function (method) you should  simple
    call   the    NConcept::MConstraint::requiresConcept<NConcept::MConcept>()
    method with fixed conception in template argument.

    Example:
    \code
    template <typename T_Number>
    T_Number min(T_Number a_X, T_Number a_Y)
    {
      NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptNumber<T_Number> >();
      return ((a_X < a_Y) ? a_X : a_Y);
    }
    \endcode

    To use template arguments checking in  class  you  should  simple  inherit
    class from the MRequiresConcept  template  class  with  needed  types  and
    MConcept constraint conception in it template argument. Another way is  to
    use REQUIRES_CONCEPTx() macro. Macro  method  is  faster,  generates  less
    code, but not so universal  as  inheriting  from  MRequiresConcept  class,
    because you also  need  to  replace  'x'  with  the  number  of  templates
    arguments for checking.

    Example with MRequiresConcept:
    \code
    template <typename T_Number>
    class CNumber :
      NConcept::MRequiresConcept<NConcept::CConseptNumber<T_Number>, T_Number>
    {
    public:
      CNumber();
      ~CNumber();

    private:
      T_Number m_X;
    };
    \endcode

    Example with REQUIRES_CONCEPTx():
    \code
    template <class T_Number>
    class CNumber
    {
      REQUIRES_CONCEPT(NConcept, CConseptNumber, T_Number);
    public:
      CNumber();
      ~CNumber();

    private:
      T_Number m_X;
    };
    \endcode
*/
class BASE_API MConstraint :
  public NDepth::NCommon::IStatic
{
public:
  //! Method for checking that fixed type is convertible to boolean number.
  /*!
      This method gives ability to check if fixed type  can  be  converted  to
      boolean value.

      \param a_crExpression - Constant reference to expression result.
  */
  template <typename T_Type>
  static void requiresConvertibleToBoolean(const T_Type& a_crExpression);

  //! Method for include fixed concept in other concept.
  /*!
      To include one concept into another one we  need  to  call  this  method
      inside the constraints() method of the template check concept.
  */
  template <typename T_Concept>
  static void requiresConcept();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/MConstraint.inl>
/*==========================================================================*/
#endif
