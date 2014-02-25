/*!
 *  \file    MConceptHashFunction.inl Template checking conception. Checks if
 *           template argument is a hash function.
 *  \brief   Hash function template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash function template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functions conception checking
    VERSION:   1.0
    CREATED:   06.05.2008 22:11:35

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
#ifndef __MCONCEPTHASHFUNCTION_INL__
#define __MCONCEPTHASHFUNCTION_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <typename T_HashFunction, typename T_Argument>
inline MConceptHashFunction<T_HashFunction, T_Argument>::MConceptHashFunction() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_HashFunction, typename T_Argument>
inline MConceptHashFunction<T_HashFunction, T_Argument>::~MConceptHashFunction()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_HashFunction, typename T_Argument>
inline void MConceptHashFunction<T_HashFunction, T_Argument>::constraints()
{ CALL
  // Check for ability to get hash value from the argument.
  Tuint hash = m_fHashFunction(m_Argument);

  IGNORE_UNUSED(hash);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
