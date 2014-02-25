/*!
 *  \file    CBitArrayReference.hpp Template bit array reference class. Bit
 *           array reference class emulates operations with a single bit of
 *           a bit array
 *  \brief   Bit array reference class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bit array reference class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   07.06.2006 23:25:27

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
#ifndef __CBITARRAYREFERENCE_HPP__
#define __CBITARRAYREFERENCE_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CArray.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Bit array reference class.
/*!
    This reference class emulates operations with a single bit of a bit array.
    It contains operators that can get particular bit value 'true' or 'false'
    and assign method to change it.
*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
class CBitArrayReference
{
  // Friend class: Bit array class.
  friend class CArray<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
  // Friend class: Bit array non constant iterator class.
  friend class CArrayIterator<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;
  // Friend class: Bit array constant iterator class.
  friend class CArrayIteratorConst<Tbool, T_ResizePolicy, T_CopyPolicy, T_Allocator>;

public:
  //! Bit array reference resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Bit array reference copy policy type.
  typedef T_CopyPolicy TCopyPolicy;
  //! Bit array reference allocator type.
  typedef T_Allocator TAllocator;

  //! Class destructor.
 ~CBitArrayReference();

  //! Operator: Equal to another bit array reference instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the bit array reference class.
      \param a_crInstance2 - Another instance of the bit array reference class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator == (const CBitArrayReference<T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CBitArrayReference<T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another bit array reference instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the bit array reference class.
      \param a_crInstance2 - Another instance of the bit array reference class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <class T_OtherResizePolicy, class T_OtherCopyPolicy, class T_OtherAllocator>
  friend Tbool operator != (const CBitArrayReference<T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance1, const CBitArrayReference<T_OtherResizePolicy, T_OtherCopyPolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign boolean value.
  /*!
      \param a_cValue - Bit array reference boolean value.
      \return Reference to the current class instance.
  */
  CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const Tbool a_cValue);
  //! Operator: Assign another CBitArrayReference class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBitArrayReference class.
      \return Reference to the current class instance.
  */
  CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& operator = (const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Operator: Get current boolean value.
  /*!
      \return true  - if current boolean value is 'true'. \n
              false - if current boolean value is 'false'. \n
  */
  operator Tbool () const;
  //! Operator: Get current boolean inverse value.
  /*!
      \return true  - if current boolean value is 'false'. \n
              false - if current boolean value is 'true'. \n
  */
  Tbool operator ! () const;

  //! Set new bit array reference boolean value.
  /*!
      \param a_cValue - Bit array reference boolean value.
  */
  void set(const Tbool a_cValue);
  //! Set another CBitArrayReference class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBitArrayReference class.
  */
  void set(const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance);

  //! Get bit array reference value.
  /*!
      \return Bit array reference value.
  */
  Tbool getValue() const;

  //! Flip current bit array reference value to opposite.
  void flip();

  //! Serialization load CBitArrayReference class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CBitArrayReference class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CBitArrayReference class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBitArrayReference class instances.
  /*!
      \param a_rInstance - Reference to another CBitArrayReference class instance.
  */
  void swap(CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance);

private:
  Tuint   m_BitMask;                    //!< Bit mask for updating one bit inside given byte.
  Tbuffer m_pBytePtr;                   //!< Pointer to a single byte from bit array.

  //! Initialize bit array reference with a pointer to a single byte and a bit mask.
  /*!
      \param a_pBytePtr - Pointer to a single byte from bit array.
      \param a_cBitMask - Bit mask for updating one bit inside given byte.
  */
  CBitArrayReference(Tbuffer a_pBytePtr, const Tuint a_cBitMask);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/details/CBitArrayReference.inl>
/*==========================================================================*/
#endif
