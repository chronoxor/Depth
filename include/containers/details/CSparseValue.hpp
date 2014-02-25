/*!
 *  \file    CSparseValue.hpp Template single sparse array value class. Sparse
 *           value represents close interval of array values, which is kept
 *           inside CSparseArray container.
 *  \brief   Sparse array value class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sparse array value class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   26.09.2007 03:21:19

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
#ifndef __CSPARSEVALUE_HPP__
#define __CSPARSEVALUE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
//! Sparse array value class.
/*!
    Sparse array value represents single close array interval, which  is  kept
    inside CSparseArray container.

    Serialization: Sparse array value cannot be serialized.
*/
template <typename T_Type>
class CSparseValue
{
  //! Type for the MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CSparseValue<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check CSparseValue class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Sparse array value template type.
  typedef T_Type TType;

  //! Default class constructor.
  CSparseValue();
  //! Initialize sparse array value with an index interval and a pointer to the data.
  /*!
      \param a_cFirstIndex - Sparse array first index.
      \param a_cSecondIndex - Sparse array second index.
      \param a_pBuffer - Pointer to the sparse array buffer.
  */
  CSparseValue(const Tuint a_cFirstIndex, const Tuint a_cSecondIndex, T_Type* a_pBuffer);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseValue class.
  */
  template <typename T_OtherType>
  CSparseValue(const CSparseValue<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CSparseValue();

  //! Operator: Assign another CSparseValue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseValue class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CSparseValue<T_Type>& operator = (const CSparseValue<T_OtherType>& a_crInstance);

  //! Operator: Indexing into the sparse array's buffer.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Reference to sparse array's item under the given index.
  */
  T_Type& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the sparse array's buffer.
  /*!
      \param a_cIndex - Indexed sparse array position to return.
      \return Constant reference to sparse array's item under the given index.
  */
  const T_Type& operator [] (const Tuint a_cIndex) const;

  //! Set sparse array value.
  /*!
      \param a_cFirstIndex - Sparse array first index.
      \param a_cSecondIndex - Sparse array second index.
      \param a_pBuffer - Pointer to the sparse array buffer.
  */
  void set(const Tuint a_cFirstIndex, const Tuint a_cSecondIndex, T_Type* a_pBuffer);
  //! Set another CSparseValue class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSparseValue class.
  */
  template <typename T_OtherType>
  void set(const CSparseValue<T_OtherType>& a_crInstance);

  //! Is sparse array value valid?
  /*!
      \return true  - if sparse array value is valid. \n
              false - if sparse array value is not valid. \n
  */
  Tbool isValid() const;

  //! Get first sparse array value index.
  /*!
      \return First index of the sparse array value.
  */
  Tuint getFirstIndex() const;
  //! Get second sparse array value index.
  /*!
      \return Second index of the sparse array value.
  */
  Tuint getSecondIndex() const;

  //! Get length of the sparse array value.
  /*!
      \return Length of the sparse array value.
  */
  Tuint getLength() const;

  //! Get pointer to the sparse array value buffer.
  /*!
      \return Pointer to the sparse array value buffer.
  */
  T_Type* getBuffer();
  //! Get pointer to the sparse array value buffer (constant version).
  /*!
      \return Constant pointer to the sparse array value buffer.
  */
  const T_Type* getBuffer() const;

  //! Serialize CSparseValue class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSparseValue class instances.
  /*!
      \param a_rInstance - Reference to another CSparseValue class instance.
  */
  void swap(CSparseValue<T_Type>& a_rInstance);

private:
  Tuint m_FirstIndex;                   //!< Sparse array first index (begin of the interval).
  Tuint m_SecondIndex;                  //!< Sparse array second index (end of the interval).
  T_Type* m_pBuffer;                    //!< Sparse array buffer.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/details/CSparseValue.inl>
/*==========================================================================*/
#endif
