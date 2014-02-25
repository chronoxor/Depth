/*!
 *  \file    CPtrAuto.hpp Auto smart pointer class. It holds pointer to the
 *           fixed object until it stays inside the visibility scope (until
 *           its destructor is not called).
 *  \brief   Auto smart pointer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Auto smart pointer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   22.05.2006 20:30:42

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
#ifndef __CPTRAUTO_HPP__
#define __CPTRAUTO_HPP__
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
//! Auto smart pointer class.
/*!
    Auto smart pointer can hold pointer to real object until it is inside  the
    visible scope (until its destructor is not called).

    Auto smart pointer use the following rules:
    1) Creating new smart pointer from NULL pointer leads to creating an empty
       smart pointer instance.
    2) Creating new smart pointer from pointer leads to taking controlling  an
       object under given pointer.
    3) Creating new smart pointer from another smart pointer of the same  type
       leads to take away controlling from it, but no object is deleted. Given
       smart pointer becomes an empty one.
    4) Setting non empty smart  pointer  with  NULL  pointer  deletes  current
       controlling object and leaves smart pointer empty.
    5) Setting non empty smart pointer  with  another  valid  pointer  deletes
       current controlling object and take controlling an object  under  given
       pointer.
    6) Setting non empty smart pointer  with  another  smart  pointer  deletes
       current controlling object and take away controlling from  given  smart
       pointer. Given smart pointer becomes an empty one.
    7) Deleting non empty smart pointer also deletes a controlling object.

    Serialization: Auto smart pointer cannot be serialized.
*/
template <typename T_Type>
class CPtrAuto :
  public NCommon::IPtr<T_Type>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CPtrAuto<T_Type> TDepthCheckType;

  // Check CPtrAuto class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! CPtrAuto value type.
  typedef typename NCommon::IPtr<T_Type>::TType TType;
  //! CPtrAuto constant reference type.
  typedef typename NCommon::IPtr<T_Type>::TConstReference TConstReference;
  //! CPtrAuto reference type.
  typedef typename NCommon::IPtr<T_Type>::TReference TReference;
  //! CPtrAuto pointer type.
  typedef typename NCommon::IPtr<T_Type>::TPointer TPointer;

  //! Initialize smart pointer with a valid pointer to real object or array.
  /*!
      Smart pointer interface is initialized with pointer to  real  object  or
      array.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an object or array under this pointer. This object or  array
      will be deleted in smart pointer destructor.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pPointer - Pointer to real object (default is NULL).
      \param a_cIsArrayPointer - Pointer to an array flag (default is false).
  */
  CPtrAuto(T_Type* a_pPointer = NULL, const Tbool a_cIsArrayPointer = false);
  //! Initialize smart pointer with a valid pointer to real array.
  /*!
      Smart pointer interface is initialized with pointer to array.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an array under this pointer. This array will be  deleted  in
      smart pointer destructor.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pArray - Pointer to real array.
  */
  template <Tuint t_Size>
  CPtrAuto(T_Type (&a_pArray)[t_Size]);
  //! Class copy constructor.
  /*!
      Method takes pointer ownership from given smart pointer. After it  given
      smart pointer becomes an empty one.

      \param a_rInstance - Reference to another instance of the CPtrAuto class.
  */
  CPtrAuto(CPtrAuto<T_Type>& a_rInstance);
  //! Class virtual destructor.
  /*!
      If current smart pointer is not empty, then  delete  controlling  object
      with current smart pointer.
  */
  virtual ~CPtrAuto();

  //! Operator: Assign new valid pointer to real object.
  /*!
      This operator deletes current controlling  object  or  array  and  takes
      controlling a new object under given pointer.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an object under this pointer. This object will be deleted in
      smart pointer destructor.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pPointer - Pointer to real object.
      \return Reference to the current class instance.
  */
  CPtrAuto<T_Type>& operator = (T_Type* a_pPointer);
  //! Operator: Assign new valid pointer to real array.
  /*!
      This operator deletes current controlling  object  or  array  and  takes
      controlling a new array under given pointer.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an array under this pointer. This object will be deleted  in
      smart pointer destructor.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pArray - Pointer to real array.
      \return Reference to the current class instance.
  */
  template <Tuint t_Size>
  CPtrAuto<T_Type>& operator = (T_Type (&a_pArray)[t_Size]);
  //! Operator: Assign another CPtrAuto class instance.
  /*!
      This operator deletes current controlling  object  or  array  and  takes
      pointer ownership from given smart pointer. After it given smart pointer
      becomes an empty one.

      \param a_rInstance - Reference to another instance of the CPtrAuto class.
      \return Reference to the current class instance.
  */
  CPtrAuto<T_Type>& operator = (CPtrAuto<T_Type>& a_rInstance);

  //! Set new valid pointer to real object or array.
  /*!
      This method deletes  current  controlling  object  or  array  and  takes
      controlling a new object or array under given pointer.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an object or array under this pointer. This object  will  be
      deleted in smart pointer destructor.

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
      This method deletes  current  controlling  object  or  array  and  takes
      controlling a new array under given pointer.

      If given pointer is not NULL, then current smart pointer instance  takes
      controlling an array under this pointer. This object will be deleted  in
      smart pointer destructor.

      If given pointer is NULL, then current smart pointer  instance  will  be
      initialized as an empty one.

      \param a_pArray - Pointer to real array.
      \return true  - if pointer was successfully set. \n
              false - if pointer was not successfully set. \n
  */
  template <Tuint t_Size>
  Tbool set(T_Type (&a_pArray)[t_Size]);
  //! Set another CPtrAuto class instance.
  /*!
      This method deletes  current  controlling  object  or  array  and  takes
      pointer ownership from given smart pointer. After it given smart pointer
      becomes an empty one.

      \param a_rInstance - Reference to another instance of the CPtrAuto class.
      \return true  - if another smart pointer was successfully set. \n
              false - if another smart pointer was not successfully set. \n
  */
  Tbool set(CPtrAuto<T_Type>& a_rInstance);

  //! Is current smart pointer is an array pointer.
  /*!
      \return true  - if current smart pointer is an array pointer. \n
              false - if current smart pointer is not an array pointer. \n
  */
  Tbool isArrayPointer() const;

  //! Release current smart pointer.
  /*!
      Releasing smart pointer is forcing it inner pointer to be  NULL  without
      deleting an object under the corresponding pointer. Method  returns  old
      pointer value.

      \return Pointer value before smart pointer releasing.
  */
  T_Type* release();

  //! Serialize CPtrAuto class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPtrAuto class instances.
  /*!
      \param a_rInstance - Reference to another CPtrAuto class instance.
  */
  void swap(CPtrAuto<T_Type>& a_rInstance);

private:
  Tbool m_IsArrayPointer;               //<! Pointer to an array flag.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CPtrAuto.inl>
/*==========================================================================*/
//! \example example-utility-CPtrAuto.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-CPtrAuto.cpp
/*==========================================================================*/
#endif
