/*!
 *  \file    IClassFunctorConstVolatile.hpp.tpl Constant volatile class
 *           functor with DEF_FUNCTOR_ARITY arguments interface declares
 *           objects with 'operator()'. To call such functor a constant
 *           volatile class instance should be used.
 *  \brief   Constant volatile class functor with DEF_FUNCTOR_ARITY arguments interfaces (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant volatile class functor with DEF_FUNCTOR_ARITY arguments interfaces (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   22.01.2006 23:56:25

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
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Constant volatile class functor interface for class methods with DEF_FUNCTOR_ARITY arguments.
/*!
    This  interface  specialize   constant   volatile   class   functor   with
    DEF_FUNCTOR_ARITY method arguments. It has 'operator()'  so  you  can  use
    this interface in corresponding class functor hierarchy.
*/
template <class T_Class, DEF_TEMPLATE_DECLARATION>
class IClassFunctorConstVolatile<T_Class, DEF_TEMPLATE_PARAMETERS> :
  public NCommon::IClonable<IClassFunctorConstVolatile<T_Class, DEF_TEMPLATE_PARAMETERS> >,
  public NCommon::IEquatable<IClassFunctorConstVolatile<T_Class, DEF_TEMPLATE_PARAMETERS> >
{
protected:
  //! Default interface protected constructor.
  IClassFunctorConstVolatile();

public:
  //! Interface virtual destructor.
  virtual ~IClassFunctorConstVolatile();

  //! Check functor valid state.
  /*!
      Method checks if current functor instance is ready for work. Unless  the
      result of this method is 'true' calling functor is not safe.

      \return true  - if functor is valid. \n
              false - if functor is not valid. \n
  */
  virtual Tbool isValid() const = 0;

  //! Operator: Call functor with the constant volatile class instance and DEF_FUNCTOR_ARITY method arguments.
  /*!
      \param a_cvrInstance - Constant volatile reference to the class instance.
      \param a_Argument1 - Functor argument 1 (optional argument).
      \param a_Argument2 - Functor argument 2 (optional argument).
      \param a_Argument3 - Functor argument 3 (optional argument).
      \param a_Argument4 - Functor argument 4 (optional argument).
      \param a_Argument5 - Functor argument 5 (optional argument).
      \param a_Argument6 - Functor argument 6 (optional argument).
      \param a_Argument7 - Functor argument 7 (optional argument).
      \param a_Argument8 - Functor argument 8 (optional argument).
      \param a_Argument9 - Functor argument 9 (optional argument).
      \param a_Argument10 - Functor argument 10 (optional argument).
      \return Value with 'T_Result' type.
  */
  virtual T_Result operator () (const volatile T_Class& a_cvrInstance DEF_CALL_COMMA DEF_CALL_DECLARATION) const = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/details/templates/IClassFunctorConstVolatile.inl.tpl>
/*==========================================================================*/
