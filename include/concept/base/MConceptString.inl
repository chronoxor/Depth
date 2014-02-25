/*!
 *  \file    MConceptString.inl Template checking conception. Checks if
 *           template argument is a mutable string type.
 *  \brief   Mutable string value template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Mutable string value template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   27.03.2008 00:53:10

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
#ifndef __MCONCEPTSTRING_INL__
#define __MCONCEPTSTRING_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <typename T_Type>
inline MConceptString<T_Type>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline MConceptString<T_Type>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptString<T_Type>::constraints()
{ CALL
  // Check T_Type template argument constraint to be a constant string type.
  MConstraint::requiresConcept<NBase::MConceptStringConst<T_Type> >();
  // Check T_Type template argument constraint to be a constructible type.
  MConstraint::requiresConcept<NClass::MConceptConstructible<T_Type> >();

  Tuint index;

  // Check for assign operators.
  m_X = m_Y;
  // Check for string alteration.
  m_X[index] = 0;
}
/*--------------------------------------------------------------------------*/
inline MConceptString<Tschar*>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<Tschar*>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<Tschar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Tschar*>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Tschar*>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<volatile Tschar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<Tschar[]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<Tschar[]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<Tschar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Tschar[]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Tschar[]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<volatile Tschar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<Tschar[t_N]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<Tschar[t_N]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptString<Tschar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<volatile Tschar[t_N]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<volatile Tschar[t_N]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptString<volatile Tschar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<Twchar*>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<Twchar*>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<Twchar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Twchar*>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Twchar*>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<volatile Twchar*>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<Twchar[]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<Twchar[]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<Twchar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Twchar[]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptString<volatile Twchar[]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptString<volatile Twchar[]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<Twchar[t_N]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<Twchar[t_N]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptString<Twchar[t_N]>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<volatile Twchar[t_N]>::MConceptString() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline MConceptString<volatile Twchar[t_N]>::~MConceptString()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <Tuint t_N>
inline void MConceptString<volatile Twchar[t_N]>::constraints()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
