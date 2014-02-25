/*!
 *  \file    ILocal.inl Interface for all local defined variables. If class
 *           does not want to be created dynamically.
 *  \brief   Local interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Local interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   18.01.2006 22:58:34

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
#ifndef __ILOCAL_INL__
#define __ILOCAL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline ILocal::ILocal()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline Tptr ILocal::operator new (const Tuint a_cSize, Tptr a_pPointer)
{ CALL
  return ::operator new (a_cSize, a_pPointer);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocal::operator new[] (const Tuint a_cSize, Tptr a_pPointer)
{ CALL
  return ::operator new[] (a_cSize, a_pPointer);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocal::operator new (const Tuint a_cSize)
{ CALL
  return ::operator new (a_cSize, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocal::operator new[] (const Tuint a_cSize)
{ CALL
  return ::operator new[] (a_cSize, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocal::operator new (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine)
{ CALL
  return ::operator new (a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocal::operator new[] (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine)
{ CALL
  return ::operator new[] (a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline void ILocal::operator delete (Tptr a_pPointer1, Tptr a_pPointer2)
{ CALL
  return ::operator delete (a_pPointer1, a_pPointer2);
}
/*--------------------------------------------------------------------------*/
inline void ILocal::operator delete[] (Tptr a_pPointer1, Tptr a_pPointer2)
{ CALL
  return ::operator delete[] (a_pPointer1, a_pPointer2);
}
/*--------------------------------------------------------------------------*/
inline void ILocal::operator delete (Tptr a_pPointer)
{ CALL
  return ::operator delete (a_pPointer, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline void ILocal::operator delete[] (Tptr a_pPointer)
{ CALL
  return ::operator delete[] (a_pPointer, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline void ILocal::operator delete (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_pFileName, const Tuint a_cLine)
{ CALL
  return ::operator delete (a_pPointer, a_cpFunctionSignature, a_pFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline void ILocal::operator delete[] (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_pFileName, const Tuint a_cLine)
{ CALL
  return ::operator delete[] (a_pPointer, a_cpFunctionSignature, a_pFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline ILocalBase::ILocalBase()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline Tptr ILocalBase::operator new (const Tuint a_cSize, Tptr a_pPointer)
{ CALL
  return ::operator new (a_cSize, a_pPointer);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocalBase::operator new[] (const Tuint a_cSize, Tptr a_pPointer)
{ CALL
  return ::operator new[] (a_cSize, a_pPointer);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocalBase::operator new (const Tuint a_cSize)
{ CALL
  return ::operator new (a_cSize, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocalBase::operator new[] (const Tuint a_cSize)
{ CALL
  return ::operator new[] (a_cSize, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocalBase::operator new (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine)
{ CALL
  return ::operator new (a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline Tptr ILocalBase::operator new[] (const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine)
{ CALL
  return ::operator new[] (a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline void ILocalBase::operator delete (Tptr a_pPointer1, Tptr a_pPointer2)
{ CALL
  return ::operator delete (a_pPointer1, a_pPointer2);
}
/*--------------------------------------------------------------------------*/
inline void ILocalBase::operator delete[] (Tptr a_pPointer1, Tptr a_pPointer2)
{ CALL
  return ::operator delete[] (a_pPointer1, a_pPointer2);
}
/*--------------------------------------------------------------------------*/
inline void ILocalBase::operator delete (Tptr a_pPointer)
{ CALL
  return ::operator delete (a_pPointer, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline void ILocalBase::operator delete[] (Tptr a_pPointer)
{ CALL
  return ::operator delete[] (a_pPointer, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline void ILocalBase::operator delete (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_pFileName, const Tuint a_cLine)
{ CALL
  return ::operator delete (a_pPointer, a_cpFunctionSignature, a_pFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline void ILocalBase::operator delete[] (Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_pFileName, const Tuint a_cLine)
{ CALL
  return ::operator delete[] (a_pPointer, a_cpFunctionSignature, a_pFileName, a_cLine);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
