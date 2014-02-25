/*!
 *  \file    CPtrRefCounter.hpp Reference counter smart pointer class.
 *           Reference counter smart pointer holds object and reference
 *           count to this object.
 *  \brief   Reference counter smart pointer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reference counter smart pointer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   26.05.2006 03:59:24

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
#ifndef __CPTRREFCOUNTER_HPP__
#define __CPTRREFCOUNTER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IPtr.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Reference counter smart pointer class.
/*!
    Reference counter smart pointer holds object and reference count  to  this
    object.

    Reference counter smart pointer use the following rules:
    1) Creating new smart pointer from NULL pointer leads to creating an empty
       smart pointer instance.
    2) Creating new smart pointer from pointer leads to taking controlling  an
       object under given pointer and set reference counter value to 1.
    3) Creating new smart pointer from another smart pointer of the same  type
       leads to share object under given smart pointer and increase  reference
       counter.
    4) Setting non empty smart pointer with NULL pointer  decreases  reference
       counter. If reference counter  value  is  0  than  current  controlling
       object will be deleted. Anyway current smart pointer becomes empty.
    5) Setting non empty smart pointer with another  valid  pointer  decreases
       reference counter.  If  reference  counter  value  is  0  than  current
       controlling object will be deleted.  After  it  current  smart  pointer
       takes controlling an object  under  given  pointer  and  set  reference
       counter value to 1.
    6) Setting non empty smart pointer with another  smart  pointer  decreases
       reference counter.  If  reference  counter  value  is  0  than  current
       controlling object will be deleted.  After  it  current  smart  pointer
       shares object under given smart  pointer  and  increase  its  reference
       counter.
    7) Deleting non empty smart pointer also decreases reference  counter.  If
       reference counter value is 0 than current controlling  object  will  be
       deleted.

    Serialization: Reference counter smart pointer cannot be serialized.
*/
template <typename T_Type>
class CPtrRefCounter :
  public NCommon::IPtr<T_Type>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CPtrRefCounter<T_Type> TDepthCheckType;

  // Check CPtrRefCounter class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! CPtrRefCounter value type.
  typedef typename NCommon::IPtr<T_Type>::TType TType;
  //! CPtrRefCounter constant reference type.
  typedef typename NCommon::IPtr<T_Type>::TConstReference TConstReference;
  //! CPtrRefCounter reference type.
  typedef typename NCommon::IPtr<T_Type>::TReference TReference;
  //! CPtrRefCounter pointer type.
  typedef typename NCommon::IPtr<T_Type>::TPointer TPointer;

  //! Initialize smart pointer with a valid pointer to real object or array.
  /*!
      Smart pointer interface is initialized with pointer to  real  object  or
      array.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an object or array under this pointer and sets its reference
      counter value to 1.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one. Reference counter value stays 0.

      \param a_pPointer - Pointer to real object (default is NULL).
      \param a_cIsArrayPointer - Pointer to an array flag (default is false).
  */
  CPtrRefCounter(T_Type* a_pPointer = NULL, const Tbool a_cIsArrayPointer = false);
  //! Initialize smart pointer with a valid pointer to real array.
  /*!
      Smart pointer interface is initialized with pointer to real array.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an array under this pointer and sets its  reference  counter
      value to 1.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one. Reference counter value stays 0.

      \param a_pArray - Pointer to real array.
  */
  template <Tuint t_Size>
  CPtrRefCounter(T_Type (&a_pArray)[t_Size]);
  //! Class copy constructor.
  /*!
      Method shares pointer with given smart pointer. It also increases  their
      reference counter value.

      \param a_crInstance - Constant reference to another instance of the CPtrRefCounter class.
  */
  CPtrRefCounter(const CPtrRefCounter<T_Type>& a_crInstance);
  //! Class virtual destructor.
  /*!
      If current smart pointer is not empty, then method  decreases  reference
      counter value. If this value becomes 0,  then  controlling  object  also
      deletes.
  */
  virtual ~CPtrRefCounter();

  //! Operator: Assign new valid pointer to real object.
  /*!
      This operator decreases current reference counter value. If it is 0 then
      current controlling object or array will be deleted.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an object under this pointer and sets its reference  counter
      value to 1.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pPointer - Pointer to real object.
      \return Reference to the current class instance.
  */
  CPtrRefCounter<T_Type>& operator = (T_Type* a_pPointer);
  //! Operator: Assign new valid pointer to real array.
  /*!
      This operator decreases current reference counter value. If it is 0 then
      current controlling object or array will be deleted.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an array under this pointer and sets its  reference  counter
      value to 1.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pArray - Pointer to real array.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CPtrRefCounter<T_Type>& operator = (T_Type (&a_pArray)[t_Size]);
  //! Operator: Assign another CPtrRefCounter class instance.
  /*!
      This operator decreases current reference counter value. If it is 0 then
      current controlling object or array will be deleted.

      Then operator shares pointer with given smart pointer. It also increases
      their reference counter value.

      \param a_crInstance - Constant reference to another instance of the CPtrRefCounter class.
      \return Reference to the current class instance.
  */
  CPtrRefCounter<T_Type>& operator = (const CPtrRefCounter<T_Type>& a_crInstance);

  //! Set new valid pointer to real object or array.
  /*!
      This method decreases current reference counter value. If it is  0  then
      current controlling object or array will be deleted.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an object or array under this pointer and sets its reference
      counter value to 1.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pPointer - Pointer to real object.
      \param a_cIsArrayPointer - Pointer to an array flag (default is false).
      \return true  - if pointer was successfully set. \n
              false - if pointer was not successfully set. \n
  */
  Tbool set(T_Type* a_pPointer, const Tbool a_cIsArrayPointer = false);
  //! Set new valid pointer to real array.
  /*!
      This method decreases current reference counter value. If it is  0  then
      current controlling object or array will be deleted.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an array under this pointer and sets its  reference  counter
      value to 1.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pArray - Pointer to real array.
      \return true  - if pointer was successfully set. \n
              false - if pointer was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(T_Type (&a_pArray)[t_Size]);
  //! Set another CPtrRefCounter class instance.
  /*!
      This method decreases current reference counter value. If it is  0  then
      current controlling object or array will be deleted.

      Then method shares pointer with given smart pointer. It  also  increases
      their reference counter value.

      \param a_crInstance - Constant reference to another instance of the CPtrRefCounter class.
      \return true  - if another smart pointer was successfully set. \n
              false - if another smart pointer was not successfully set. \n
  */
  Tbool set(const CPtrRefCounter<T_Type>& a_crInstance);

  //! Is current smart pointer is an array pointer.
  /*!
      \return true  - if current smart pointer is an array pointer. \n
              false - if current smart pointer is not an array pointer. \n
  */
  Tbool isArrayPointer() const;

  //! Get count of reference in current smart pointer.
  /*!
      Method returns reference counter value of the current smart pointer.  If
      the smart pointer is empty, then return value will be 0.

      \return Reference counter value.
  */
  Tuint getRefCount() const;

  //! Release current smart pointer.
  /*!
      Releasing smart pointer is forcing it inner pointer  to  be  NULL.  This
      method also decreases reference counter value. If this value becomes  0,
      then controlling object also deletes.

      \return true  - if current smart pointer was successfully released. \n
              false - if current smart pointer was not successfully released. \n
  */
  Tbool release();

  //! Serialize CPtrRefCounter class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPtrRefCounter class instances.
  /*!
      \param a_rInstance - Reference to another CPtrRefCounter class instance.
  */
  void swap(CPtrRefCounter<T_Type>& a_rInstance);

private:
  Tbool m_IsArrayPointer;               //!< Pointer to an array flag.
  Tuint* m_pRefCounter;                 //!< Pointer the reference counter.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CPtrRefCounter.inl>
/*==========================================================================*/
//! \example example-utility-CPtrRefCounter.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-CPtrRefCounter.cpp
/*==========================================================================*/
#endif
