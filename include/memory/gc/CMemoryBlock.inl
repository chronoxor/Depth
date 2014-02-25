/*!
 *  \file    CMemoryBlock.inl GC memory block class. It describes one memory
 *           block and contains a pointer, an allocated size, and a place of
 *           allocation.
 *  \brief   GC memory block class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC memory block class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   20.06.2007 02:34:53

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
#ifndef __CMEMORYBLOCK_INL__
#define __CMEMORYBLOCK_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CMemoryBlock::CMemoryBlock() :
  m_pPointer(NULL),
  m_Size(0),
  m_cpFunctionName(ASC("")),
  m_cpFileName(STR("")),
  m_Line(0),
  m_IsMarked(false),
  m_pObjectPointer(NULL),
  m_fObjectDestructor(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CMemoryBlock::CMemoryBlock(Tptr a_pPointer, const Tuint a_cSize, Tcsstr a_cpFunctionName, Tcstr a_cpFileName, const Tuint a_cLine, const Tbool a_cIsMarked/* = false */) :
  m_pPointer(a_pPointer),
  m_Size(a_cSize),
  m_cpFunctionName(a_cpFunctionName),
  m_cpFileName(a_cpFileName),
  m_Line(a_cLine),
  m_IsMarked(a_cIsMarked),
  m_pObjectPointer(NULL),
  m_fObjectDestructor(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CMemoryBlock::CMemoryBlock(const CMemoryBlock& a_crInstance) :
  m_pPointer(a_crInstance.m_pPointer),
  m_Size(a_crInstance.m_Size),
  m_cpFunctionName(a_crInstance.m_cpFunctionName),
  m_cpFileName(a_crInstance.m_cpFileName),
  m_Line(a_crInstance.m_Line),
  m_IsMarked(a_crInstance.m_IsMarked),
  m_pObjectPointer(a_crInstance.m_pObjectPointer),
  m_fObjectDestructor(a_crInstance.m_fObjectDestructor)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CMemoryBlock::~CMemoryBlock()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer == a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer != a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer < a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer > a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer <= a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CMemoryBlock& a_crInstance1, const CMemoryBlock& a_crInstance2)
{ CALL
  return (a_crInstance1.m_pPointer >= a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlock& CMemoryBlock::operator = (const CMemoryBlock& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CMemoryBlock::set(const CMemoryBlock& a_crInstance)
{ CALL
  m_pPointer = a_crInstance.m_pPointer;
  m_Size = a_crInstance.m_Size;
  m_cpFunctionName = a_crInstance.m_cpFunctionName;
  m_cpFileName = a_crInstance.m_cpFileName;
  m_Line = a_crInstance.m_Line;
}
/*--------------------------------------------------------------------------*/
inline Tbool CMemoryBlock::isValid() const
{ CALL
  return (m_pPointer != NULL);
}
/*--------------------------------------------------------------------------*/
inline Tptr CMemoryBlock::getPointer() const
{ CALL
  return m_pPointer;
}
/*--------------------------------------------------------------------------*/
inline Tuint CMemoryBlock::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
inline Tcsstr CMemoryBlock::getFunctionName() const
{ CALL
  return m_cpFunctionName;
}
/*--------------------------------------------------------------------------*/
inline Tcstr CMemoryBlock::getFileName() const
{ CALL
  return m_cpFileName;
}
/*--------------------------------------------------------------------------*/
inline Tuint CMemoryBlock::getLine() const
{ CALL
  return m_Line;
}
/*--------------------------------------------------------------------------*/
inline Tbool CMemoryBlock::update(Tptr a_pObjectPointer, void (*a_fObjectDestructor)(Tptr))
{ CALL
  if ((m_pObjectPointer == NULL) && (m_fObjectDestructor == NULL))
  {
    m_pObjectPointer = a_pObjectPointer;
    m_fObjectDestructor = a_fObjectDestructor;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
inline Tbool CMemoryBlock::release()
{ CALL
  if ((m_pObjectPointer != NULL) && (m_fObjectDestructor != NULL))
  {
    m_fObjectDestructor(m_pObjectPointer);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlock::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("GC memory block cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlock::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the GC memory block is in the valid state.
  ASSERT(isValid(), STR("To serialize the GC memory block it should be in the valid state."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMemory::NGC::CMemoryBlock")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_pPointer, STR("m_pPointer")));
    CHECK(a_rArchive.doValue(m_Size, STR("m_Size")));
    CHECK(a_rArchive.doValue(m_cpFunctionName, STR("m_cpFunctionName")));
    CHECK(a_rArchive.doValue(m_cpFileName, STR("m_cpFileName")));
    CHECK(a_rArchive.doValue(m_Line, STR("m_Line")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlock::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CMemoryBlock::swap(CMemoryBlock& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pPointer, a_rInstance.m_pPointer);
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_cpFunctionName, a_rInstance.m_cpFunctionName);
  NAlgorithms::NCommon::swap(m_cpFileName, a_rInstance.m_cpFileName);
  NAlgorithms::NCommon::swap(m_Line, a_rInstance.m_Line);
  NAlgorithms::NCommon::swap(m_IsMarked, a_rInstance.m_IsMarked);
  NAlgorithms::NCommon::swap(m_pObjectPointer, a_rInstance.m_pObjectPointer);
  NAlgorithms::NCommon::swap(m_fObjectDestructor, a_rInstance.m_fObjectDestructor);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
