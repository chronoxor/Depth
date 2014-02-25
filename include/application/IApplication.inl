/*!
 *  \file    IApplication.inl Application interface provides OS independent
 *           functionality to handle application startup.
 *  \brief   Application interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Application interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Application
    VERSION:   1.0
    CREATED:   10.01.2009 03:53:49

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
#ifndef __IAPPLICATION_INL__
#define __IAPPLICATION_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NApplication {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IApplication::IApplication()
{ CALL
  // Verify that application is not created.
  VERIFY(!IApplication::isCreated(), STR("Application has been already created somewhere else."));

  IApplication::ms_pInstance = this;
}
/*--------------------------------------------------------------------------*/
inline IApplication::IApplication(const Tbool a_cUnitTestFlag)
{ CALL
  // Verify that application is not created.
  VERIFY(a_cUnitTestFlag || !IApplication::isCreated(), STR("Application has been already created somewhere else."));

  IApplication::ms_pInstance = this;
}
/*--------------------------------------------------------------------------*/
inline IApplication::IApplication(Tsint argc, Tschar *argv[], Tschar *envp[]/* = NULL */)
{ CALL
  // Verify that application is not created.
  VERIFY(!IApplication::isCreated(), STR("Application has been already created somewhere else."));

  IApplication::ms_pInstance = this;
  // Parse ANSI C/C++ program arguments.
  parse(argc, argv, envp);
}
/*--------------------------------------------------------------------------*/
inline IApplication::IApplication(Tsint argc, Twchar *argv[], Twchar *envp[]/* = NULL */)
{ CALL
  // Verify that application is not created.
  VERIFY(!IApplication::isCreated(), STR("Application has been already created somewhere else."));

  IApplication::ms_pInstance = this;
  // Parse ANSI C/C++ program arguments.
  parse(argc, argv, envp);
}
/*--------------------------------------------------------------------------*/
inline IApplication::IApplication(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
{ CALL
  // Verify that application is not created.
  VERIFY(!IApplication::isCreated(), STR("Application has been already created somewhere else."));

  IApplication::ms_pInstance = this;
  IApplication::ms_Arguments = a_crArguments;
  IApplication::ms_Environment = a_crEnvironment;
}
/*--------------------------------------------------------------------------*/
inline IApplication::~IApplication()
{ CALL
  IApplication::ms_pInstance = NULL;
  IApplication::ms_Arguments.clear();
  IApplication::ms_Environment.clear();
}
/*--------------------------------------------------------------------------*/
inline const NContainers::CStringBuffer<NString::CString>& IApplication::getArguments() const
{ CALL
  return IApplication::ms_Arguments;
}
/*--------------------------------------------------------------------------*/
inline const NContainers::CStringBuffer<NString::CString>& IApplication::getEnvironment() const
{ CALL
  return IApplication::ms_Environment;
}
/*--------------------------------------------------------------------------*/
inline Tbool IApplication::isCreated()
{ CALL
  return (IApplication::ms_pInstance != NULL);
}
/*--------------------------------------------------------------------------*/
inline Tbool IApplication::isRunning()
{ CALL
  return IApplication::ms_IsRunning;
}
/*--------------------------------------------------------------------------*/
inline IApplication& IApplication::getCurrentRef()
{ CALL
  // Verify that the current application instance is created.
  VERIFY(IApplication::isCreated(), STR("Taking reference to the application instance which is not created leads to the error."));

  return *IApplication::ms_pInstance;
}
/*--------------------------------------------------------------------------*/
inline IApplication* IApplication::getCurrentPtr()
{ CALL
  return IApplication::ms_pInstance;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IApplication::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the current application is not already running.
  ASSERT(!IApplication::isRunning(), STR("Cannot load program arguments and environment variables for running application."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NApplication::IApplication")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(IApplication::ms_Arguments, STR("IApplication::ms_Arguments")));
    CHECK(a_rArchive.doValue(IApplication::ms_Environment, STR("IApplication::ms_Environment")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IApplication::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NApplication::IApplication")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(IApplication::ms_Arguments, STR("IApplication::ms_Arguments")));
    CHECK(a_rArchive.doValue(IApplication::ms_Environment, STR("IApplication::ms_Environment")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IApplication::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void IApplication::swap(IApplication& a_rInstance)
{ CALL
  IGNORE_UNUSED(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
