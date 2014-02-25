/*!
 *  \file    CCopyPolicyMemory.hpp Memory copy policy class. This class uses
 *           direct memory coping methods to copy items from one memory block
 *           to another.
 *  \brief   Memory copy policy class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory copy policy class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   16.03.2006 22:43:31

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
#ifndef __CCOPYPOLICYMEMORY_HPP__
#define __CCOPYPOLICYMEMORY_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptICopyPolicy.hpp>
#include <Depth/include/memory/CMemory.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Memory copy policy class.
/*!
    Copy policy can be used to copy memory blocks of the same types. To do it,
    just call 'copy' or 'move' method.

    Memory copy policy uses direct memory coping methods to  copy  items  from
    one memory block to another.
*/
class BASE_API CCopyPolicyMemory :
  public NDepth::NCommon::IStatic
{
  //! Type for MConceptICopyPolicy constraint checking.
  typedef CCopyPolicyMemory TCopyPolicyCheckType;

  // Check CCopyPolicyMemory class constraint to be a copy policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptICopyPolicy, TCopyPolicyCheckType);

public:
  //! Copy items from one block of memory to another.
  /*!
      Method copy items from one memory block to another one. It copies  items
      from the begin to the  end  of  block.  Note  that  if  two  blocks  are
      overlapped, then this overlapped region could be overwritten.  To  avoid
      it use 'move' method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cCount - Count of copied items.
  */
  template <typename T_Type>
  static void copy(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount);
  //! Reverse copy items from one block of memory to another.
  /*!
      Method copy items from one memory block to another one. It copies  items
      from the end to the  begin  of  block.  Note  that  if  two  blocks  are
      overlapped, then this overlapped region could be overwritten.  To  avoid
      it use 'moveReverse' method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cCount - Count of copied items.
  */
  template <typename T_Type>
  static void copyReverse(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount);

  //! Move items from one block of memory to another.
  /*!
      Method copy items from one memory block to another one. It copies  items
      from the begin to the  end  of  block.  Note  that  if  two  blocks  are
      overlapped, then this overlapped region could not be  overwritten.  This
      is safe method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cCount - Size of moved blocks in bytes.
  */
  template <typename T_Type>
  static void move(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount);
  //! Reverse move items from one block of memory to another.
  /*!
      Method copy items from one memory block to another one. It copies  items
      from the end to the  begin  of  block.  Note  that  if  two  blocks  are
      overlapped, then this overlapped region could not be  overwritten.  This
      is safe method.

      \param a_pDestination - Pointer to destination memory block.
      \param a_cpSource - Constant pointer to source memory block.
      \param a_cCount - Size of moved blocks in bytes.
  */
  template <typename T_Type>
  static void moveReverse(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/policy/CCopyPolicyMemory.inl>
/*==========================================================================*/
#endif
