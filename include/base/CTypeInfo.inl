/*!
 *  \file    CTypeInfo.inl Type information wrapper class provides common
 *           operations with 'C++' types.
 *  \brief   Type information wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Type information wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   16.02.2007 02:30:27

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
#ifndef __CTYPEINFO_INL__
#define __CTYPEINFO_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTypeInfo::CTypeInfo() :
  m_cpTypeInfo(NULL)
{ CALL
  // Define local dummy class.
  class CEmpty
  {

  };
  // Get type information of the local dummy class.
  m_cpTypeInfo = &typeid(CEmpty);

  // Verify that type information wrapper class is valid.
  VERIFY((m_cpTypeInfo != NULL), STR("Type information class is not initialized properly."));
}
/*--------------------------------------------------------------------------*/
inline CTypeInfo::CTypeInfo(const std::type_info& a_crTypeInfo) :
  m_cpTypeInfo(&a_crTypeInfo)
{ CALL
  // Verify that type information wrapper class is valid.
  VERIFY((m_cpTypeInfo != NULL), STR("Type information class is not initialized properly."));
}
/*--------------------------------------------------------------------------*/
inline CTypeInfo::CTypeInfo(const CTypeInfo& a_crInstance) :
  m_cpTypeInfo(a_crInstance.m_cpTypeInfo)
{ CALL
  // Verify that type information wrapper class is valid.
  VERIFY((m_cpTypeInfo != NULL), STR("Type information class is not initialized properly."));
}
/*--------------------------------------------------------------------------*/
inline CTypeInfo::~CTypeInfo()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2)
{ CALL
  return ((*a_crInstance1.m_cpTypeInfo) == (*a_crInstance2.m_cpTypeInfo));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2)
{ CALL
  return ((*a_crInstance1.m_cpTypeInfo) != (*a_crInstance2.m_cpTypeInfo));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2)
{ CALL
  return a_crInstance1.m_cpTypeInfo->before(*a_crInstance2.m_cpTypeInfo);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2)
{ CALL
  return a_crInstance2.m_cpTypeInfo->before(*a_crInstance1.m_cpTypeInfo);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2)
{ CALL
  return (((*a_crInstance1.m_cpTypeInfo) == (*a_crInstance2.m_cpTypeInfo)) || a_crInstance1.m_cpTypeInfo->before(*a_crInstance2.m_cpTypeInfo));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CTypeInfo& a_crInstance1, const CTypeInfo& a_crInstance2)
{ CALL
  return (((*a_crInstance1.m_cpTypeInfo) != (*a_crInstance2.m_cpTypeInfo)) || a_crInstance2.m_cpTypeInfo->before(*a_crInstance1.m_cpTypeInfo));
}
/*--------------------------------------------------------------------------*/
inline Tcsstr CTypeInfo::getName() const
{ CALL
  return m_cpTypeInfo->name();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
