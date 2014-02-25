/*!
 *  \file    CClassTemplate.inl Example of class inline methods.
 *  \brief   This is just an appearance example of class inline methods.
 *  \author  unknown
 *  \version 1.0
 *  \date    30.11.2005
 *  \bug     Note here if class has some bugs.
 *  \warning Note here about any warning.
 *  \todo    Todo notes.
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template

    AUTHOR:    unknown
    GROUP:     The NULL workgroup
    PROJECT:   The project
    PART:      Main
    VERSION:   1.0
    CREATED:   30.11.2005 21:41:53

    EMAIL:     some@mail.net
    WWW:       http://some.net

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
#ifndef __CCLASSTEMPLATE_INL__
#define __CCLASSTEMPLATE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NTemplate {
/*==========================================================================*/
/* INLINE IMPLEMENTATIONS                                                   */
/*==========================================================================*/
inline bool CClassTemplate::operator == (const int a_value) const
{ CALL
  return (m_Value == a_value);
}
/*--------------------------------------------------------------------------*/
inline bool CClassTemplate::operator == (const CClassTemplate& a_instance) const
{ CALL
  return (m_Value == a_instance.m_Value);
}
/*--------------------------------------------------------------------------*/
inline bool CClassTemplate::operator != (const int a_value) const
{ CALL
  return (m_Value != a_value);
}
/*--------------------------------------------------------------------------*/
inline bool CClassTemplate::operator != (const CClassTemplate& a_instance) const
{ CALL
  return (m_Value == a_instance.m_Value);
}
/*--------------------------------------------------------------------------*/
inline SOME_API bool CClassTemplate::operator == (const int a_value,const CClassTemplate& a_instance)
{ CALL
  return (a_value == a_instance.m_Value);
}
/*--------------------------------------------------------------------------*/
inline SOME_API bool CClassTemplate::operator != (const int a_value,const CClassTemplate& a_instance)
{ CALL
  return (a_value != a_instance.m_Value);
}
/*--------------------------------------------------------------------------*/
inline CClassTemplate& CClassTemplate::operator = (const int a_value)
{ CALL
  m_Value = a_value;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CClassTemplate& CClassTemplate::operator = (const CClassTemplate& a_instance)
{ CALL
  m_Value = a_instance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CClassTemplate::operator int ()
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
inline CClassTemplate::operator const int () const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
inline CClassTemplate::operator int* ()
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
inline CClassTemplate::operator const int* () const
{ CALL
  return &m_Value;
}
/*==========================================================================*/
}
/*==========================================================================*/
#endif
