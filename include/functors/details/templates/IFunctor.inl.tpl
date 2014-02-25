/*!
 *  \file    IFunctor.inl.tpl Functor with DEF_FUNCTOR_ARITY arguments
 *           interface declares objects with 'operator()' method.
 *  \brief   Functor with DEF_FUNCTOR_ARITY arguments interfaces (template inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor with DEF_FUNCTOR_ARITY arguments interfaces (template inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   22.01.2006 22:47:36

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
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <DEF_TEMPLATE_DECLARATION>
inline IFunctor<DEF_TEMPLATE_PARAMETERS>::IFunctor() :
  NCommon::IClonable<IFunctor<DEF_TEMPLATE_PARAMETERS> >(),
  NCommon::IEquatable<IFunctor<DEF_TEMPLATE_PARAMETERS> >()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <DEF_TEMPLATE_DECLARATION>
inline IFunctor<DEF_TEMPLATE_PARAMETERS>::~IFunctor()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
