/*!
 *  \file    example-traits-MTraitsFunction.cpp Example of using the
 *           MTraitsFunction meta-class.
 *  \brief   Example of using the MTraitsFunction meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the MTraitsFunction meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth traits examples
    VERSION:   1.0
    CREATED:   02.01.2007 01:47:34

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/traits/MIsMemberPointer.hpp>
#include <Depth/include/traits/MTraitsRoutine.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTraits;
using namespace NDepth::NTraits::NFunctions;
/*==========================================================================*/
class CExampleClass
{
public:
  Tsint m_Field;

  Tsint operator() ()
  { CALL
    return 0;
  }

  Tsint method(const Tschar a_cCharValue)
  { CALL
    return (Tsint)((Tsint)a_cCharValue);
  }

  Tsint method_const(const Tschar a_cCharValue, const Tfloat a_cFloatValue) const
  { CALL
    return (Tsint)((Tsint)a_cCharValue + (Tsint)a_cFloatValue);
  }

  static Tsint method_static(const Tschar a_cCharValue, const Tfloat a_cFloatValue, const Tdouble a_cDoubleValue)
  { CALL
    return (Tsint)((Tsint)a_cCharValue + (Tsint)a_cFloatValue + (Tsint)a_cDoubleValue);
  }
};
/*--------------------------------------------------------------------------*/
Tsint function(const Tschar a_cCharValue, const Tfloat a_cFloatValue)
{ CALL
  return (Tsint)((Tsint)a_cCharValue + (Tsint)a_cFloatValue);
}
/*==========================================================================*/
template <typename T>
void checkFunctionArity(T)
{ CALL
  CStreamStdOutput stdoutput(true);
  stdoutput << STR("Traits: MTraitsFunction<T>::arity = ") << MTraitsFunction<T>::arity << ln;
}
/*--------------------------------------------------------------------------*/
template <typename T>
void checkMethodArity(T)
{ CALL
  CStreamStdOutput stdoutput(true);
  stdoutput << STR("Traits: MTraitsMethod<T>::arity = ") << MTraitsFunction<T>::arity << ln;
}
/*--------------------------------------------------------------------------*/
template <typename T>
void checkMemberPointer(T)
{ CALL
  CStreamStdOutput stdoutput(true);
  Tbool value = MIsMemberPointer<T>::yes;
  if (value)
    stdoutput << STR("Traits: MIsMemberPointer<T>::yes") << ln;
  else
    stdoutput << STR("Traits: MIsMemberPointer<T>::no") << ln;
}
/*--------------------------------------------------------------------------*/
template <typename T>
void checkMemberPointerToObject(T)
{ CALL
  CStreamStdOutput stdoutput(true);
  Tbool value = MIsMemberPointerToObject<T>::yes;
  if (value)
    stdoutput << STR("Traits: MIsMemberPointerToObject<T>::yes") << ln;
  else
    stdoutput << STR("Traits: MIsMemberPointerToObject<T>::no") << ln;
}
/*--------------------------------------------------------------------------*/
template <typename T>
void checkMemberPointerToMethod(T)
{ CALL
  CStreamStdOutput stdoutput(true);
  Tbool value = MIsMemberPointerToMethod<T>::yes;
  if (value)
    stdoutput << STR("Traits: MIsMemberPointerToMethod<T>::yes") << ln;
  else
    stdoutput << STR("Traits: MIsMemberPointerToMethod<T>::no") << ln;
}
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    stdoutput << STR("Function arity example") << ln;
    stdoutput << STR("Type: Tsint function(const Tschar a_cCharValue, const Tfloat a_cFloatValue)") << ln;
    checkFunctionArity(function);
    stdoutput << STR("Type: Tsint CExampleClass::operator()") << ln;
    checkMethodArity(&CExampleClass::operator());
    stdoutput << STR("Type: Tsint CExampleClass::method(const Tschar a_cCharValue)") << ln;
    checkMethodArity(&CExampleClass::method);
    stdoutput << STR("Type: Tsint CExampleClass::method_const(const Tschar a_cCharValue, const Tfloat a_cFloatValue)") << ln;
    checkMethodArity(&CExampleClass::method_const);
    stdoutput << STR("Type: Tsint CExampleClass::method_static(const Tschar a_cCharValue, const Tfloat a_cFloatValue, const Tdouble a_cDoubleValue)") << ln;
    checkFunctionArity(&CExampleClass::method_static);

    stdoutput << ln;
    stdoutput << STR("Class member pointer example") << ln;
    stdoutput << STR("Type: Tsint CExampleClass::m_Field") << ln;
    checkMemberPointer(&CExampleClass::m_Field);
    stdoutput << STR("Type: Tsint CExampleClass::method(const Tschar a_cCharValue)") << ln;
    checkMemberPointer(&CExampleClass::method);
    stdoutput << STR("Type: Tsint CExampleClass::method_const(const Tschar a_cCharValue, const Tfloat a_cFloatValue)") << ln;
    checkMemberPointer(&CExampleClass::method_const);
    stdoutput << STR("Type: Tsint CExampleClass::method_static(const Tschar a_cCharValue, const Tfloat a_cFloatValue, const Tdouble a_cDoubleValue)") << ln;
    checkMemberPointer(&CExampleClass::method_static);

    stdoutput << ln;
    stdoutput << STR("Class member pointer to object example") << ln;
    stdoutput << STR("Type: Tsint CExampleClass::m_Field") << ln;
    checkMemberPointerToObject(&CExampleClass::m_Field);
    stdoutput << STR("Type: Tsint CExampleClass::method(const Tschar a_cCharValue)") << ln;
    checkMemberPointerToObject(&CExampleClass::method);
    stdoutput << STR("Type: Tsint CExampleClass::method_const(const Tschar a_cCharValue, const Tfloat a_cFloatValue)") << ln;
    checkMemberPointerToObject(&CExampleClass::method_const);
    stdoutput << STR("Type: Tsint CExampleClass::method_static(const Tschar a_cCharValue, const Tfloat a_cFloatValue, const Tdouble a_cDoubleValue)") << ln;
    checkMemberPointerToObject(&CExampleClass::method_static);

    stdoutput << ln;
    stdoutput << STR("Class member pointer to method example") << ln;
    stdoutput << STR("Type: Tsint CExampleClass::m_Field") << ln;
    checkMemberPointerToMethod(&CExampleClass::m_Field);
    stdoutput << STR("Type: Tsint CExampleClass::method(const Tschar a_cCharValue)") << ln;
    checkMemberPointerToMethod(&CExampleClass::method);
    stdoutput << STR("Type: Tsint CExampleClass::method_const(const Tschar a_cCharValue, const Tfloat a_cFloatValue)") << ln;
    checkMemberPointerToMethod(&CExampleClass::method_const);
    stdoutput << STR("Type: Tsint CExampleClass::method_static(const Tschar a_cCharValue, const Tfloat a_cFloatValue, const Tdouble a_cDoubleValue)") << ln;
    checkMemberPointerToMethod(&CExampleClass::method_static);

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
