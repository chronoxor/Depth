/*!
 *  \file    IPtr.hpp Interface for all smart pointer implementations.
 *  \brief   Smart pointer interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Smart pointer interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   19.05.2006 21:33:47

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
#ifndef __IPTR_HPP__
#define __IPTR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Smart pointer interface.
/*!
    This interface contains base smart pointer functionality such as  indirect
    member access and dereferencing operators.
*/
template <typename T_Type>
class IPtr
{
  //! Type for MConceptDepthType constraint checking.
  typedef IPtr<T_Type> TDepthCheckType;

  // Check IPtr interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! IPtr value type.
  typedef T_Type TType;
  //! IPtr constant reference type.
  typedef const T_Type& TConstReference;
  //! IPtr reference type.
  typedef T_Type& TReference;
  //! IPtr pointer type.
  typedef T_Type* TPointer;

  //! Operator: Equal to another pointer.
  /*!
      \param a_crInstance - Constant reference to the current instance of the IPtr class.
      \param a_cpPointer - Pointer to real object.
      \return true  - if IPtr class instance is equal to the given pointer. \n
              false - if IPtr class instance is not equal to the given pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const IPtr<T_OtherType>& a_crInstance, const T_OtherType* a_cpPointer);
  //! Operator: Equal to another IPtr class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the IPtr class.
      \param a_crInstance2 - Constant reference to another instance of the IPtr class.
      \return true  - if IPtr class instance is equal to another one. \n
              false - if IPtr class instance is not equal to another one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const IPtr<T_OtherType>& a_crInstance1, const IPtr<T_OtherType>& a_crInstance2);
  //! Operator: Equal to another pointer.
  /*!
      \param a_cpPointer - Pointer to real object.
      \param a_crInstance - Constant reference to the current instance of the IPtr class.
      \return true  - if IPtr class instance is equal to the given pointer. \n
              false - if IPtr class instance is not equal to the given pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const T_OtherType* a_cpPointer, const IPtr<T_OtherType>& a_crInstance);

  //! Operator: Not equal to another pointer.
  /*!
      \param a_crInstance - Constant reference to the current instance of the IPtr class.
      \param a_cpPointer - Pointer to real object.
      \return true  - if IPtr class instance is not equal to the given pointer. \n
              false - if IPtr class instance is equal to the given pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const IPtr<T_OtherType>& a_crInstance, const T_OtherType* a_cpPointer);
  //! Operator: Not equal to another IPtr class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the IPtr class.
      \param a_crInstance2 - Constant reference to another instance of the IPtr class.
      \return true  - if IPtr class instance is not equal to another one. \n
              false - if IPtr class instance is equal to another one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const IPtr<T_OtherType>& a_crInstance1, const IPtr<T_OtherType>& a_crInstance2);
  //! Operator: Not equal to another pointer.
  /*!
      \param a_cpPointer - Pointer to real object.
      \param a_crInstance - Constant reference to the current instance of the IPtr class.
      \return true  - if IPtr class instance is not equal to the given pointer. \n
              false - if IPtr class instance is equal to the given pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const T_OtherType* a_cpPointer, const IPtr<T_OtherType>& a_crInstance);

  //! Operator: Less than pointer value.
  /*!
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \param a_cpPointer - Pointer to real object.
      \return true  - if IPtr class is less than pointer. \n
              false - if IPtr class is not less than pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const IPtr<T_OtherType>& a_crInstance, const T_OtherType* a_cpPointer);
  //! Operator: Less than another IPtr class instance.
  /*!
      \param a_crInstance1 - Constant pointer to the current instance of the IPtr class.
      \param a_crInstance2 - Constant pointer to another instance of the IPtr class.
      \return true  - if IPtr class instance is less than another one. \n
              false - if IPtr class instance is not less than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator < (const IPtr<T_OtherType>& a_crInstance1, const IPtr<T_OtherOtherType>& a_crInstance2);
  //! Operator: Less than pointer type.
  /*!
      \param a_cpPointer - Pointer to real object.
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \return true  - if pointer is less than IPtr class. \n
              false - if pointer is not less than IPtr class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const T_OtherType* a_cpPointer, const IPtr<T_OtherType>& a_crInstance);
  //! Operator: More than pointer value.
  /*!
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \param a_cpPointer - Pointer to real object.
      \return true  - if IPtr class is more than pointer. \n
              false - if IPtr class is not more than pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const IPtr<T_OtherType>& a_crInstance, const T_OtherType* a_cpPointer);
  //! Operator: More than another IPtr class instance.
  /*!
      \param a_crInstance1 - Constant pointer to the current instance of the IPtr class.
      \param a_crInstance2 - Constant pointer to another instance of the IPtr class.
      \return true  - if IPtr class instance is more than another one. \n
              false - if IPtr class instance is not more than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator > (const IPtr<T_OtherType>& a_crInstance1, const IPtr<T_OtherOtherType>& a_crInstance2);
  //! Operator: More than pointer type.
  /*!
      \param a_cpPointer - Pointer to real object.
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \return true  - if pointer is more than IPtr class. \n
              false - if pointer is not more than IPtr class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const T_OtherType* a_cpPointer, const IPtr<T_OtherType>& a_crInstance);
  //! Operator: Less or equal than pointer value.
  /*!
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \param a_cpPointer - Pointer to real object.
      \return true  - if IPtr class is less or equal than pointer. \n
              false - if IPtr class is not less or equal than pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const IPtr<T_OtherType>& a_crInstance, const T_OtherType* a_cpPointer);
  //! Operator: Less or equal than another IPtr class instance.
  /*!
      \param a_crInstance1 - Constant pointer to the current instance of the IPtr class.
      \param a_crInstance2 - Constant pointer to another instance of the IPtr class.
      \return true  - if IPtr class instance is less or equal than another one. \n
              false - if IPtr class instance is not less or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator <= (const IPtr<T_OtherType>& a_crInstance1, const IPtr<T_OtherOtherType>& a_crInstance2);
  //! Operator: Less or equal than pointer type.
  /*!
      \param a_cpPointer - Pointer to real object.
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \return true  - if pointer is less or equal than IPtr class. \n
              false - if pointer is not less or equal than IPtr class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const T_OtherType* a_cpPointer, const IPtr<T_OtherType>& a_crInstance);
  //! Operator: More or equal than pointer value.
  /*!
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \param a_cpPointer - Pointer to real object.
      \return true  - if IPtr class is more or equal than pointer. \n
              false - if IPtr class is not more or equal than pointer. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const IPtr<T_OtherType>& a_crInstance, const T_OtherType* a_cpPointer);
  //! Operator: More or equal than another IPtr class instance.
  /*!
      \param a_crInstance1 - Constant pointer to the current instance of the IPtr class.
      \param a_crInstance2 - Constant pointer to another instance of the IPtr class.
      \return true  - if IPtr class instance is more or equal than another one. \n
              false - if IPtr class instance is not more or equal than another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator >= (const IPtr<T_OtherType>& a_crInstance1, const IPtr<T_OtherOtherType>& a_crInstance2);
  //! Operator: More or equal than pointer type.
  /*!
      \param a_cpPointer - Pointer to real object.
      \param a_crInstance - Constant pointer to the current instance of the IPtr class.
      \return true  - if pointer is more or equal than IPtr class. \n
              false - if pointer is not more or equal than IPtr class. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const T_OtherType* a_cpPointer, const IPtr<T_OtherType>& a_crInstance);

  //! Operator: Get pointer to the current value.
  /*!
      \return Pointer to the current value.
  */
  operator T_Type* ();
  //! Operator: Get constant pointer to the current value.
  /*!
      \return Constant pointer to the current value.
  */
  operator const T_Type* () const;

  //! Operator: Get reference to the real object.
  /*!
      \return Reference to real object, which pointer current interface has.
      \see NDepth::NCommon::IPtr::getValueRef()
  */
  T_Type& operator * ();
  //! Operator: Get constant reference to the real object.
  /*!
      \return Constant reference to real object, which pointer current interface has.
      \see NDepth::NCommon::IPtr::getValueRef()
  */
  const T_Type& operator * () const;

  //! Operator: Get pointer to the real object.
  /*!
      \return Pointer to the real object, which pointer current interface has.
      \see NDepth::NCommon::IPtr::getValuePtr()
  */
  T_Type* operator -> ();
  //! Operator: Get constant pointer to the real object.
  /*!
      \return Constant pointer to the real object, which pointer current interface has.
      \see NDepth::NCommon::IPtr::getValuePtr()
  */
  const T_Type* operator -> () const;

  //! Operator: Check if current smart pointer is not an empty one.
  /*!
      \return true  - if current smart pointer is not empty. \n
              false - if current smart pointer is empty. \n
  */
  operator Tbool () const;
  //! Operator: Check if current smart pointer is an empty one.
  /*!
      \return true  - if current smart pointer is empty. \n
              false - if current smart pointer is not empty. \n
  */
  Tbool operator ! () const;

  //! Is current pointer value NULL?
  /*!
      \return true  - if current pointer value is NULL. \n
              false - if current pointer value is not NULL. \n
  */
  Tbool isNULL() const;

  //! Get reference to the real object.
  /*!
      Method returns reference to the real object  inside  current  interface.
      Node that this method is unsafe in case of current  interface  has  NULL
      pointer. So use 'isNULL()' method before to check its invalid state.

      \return Reference to real object, which pointer current interface has.
  */
  T_Type& getValueRef();
  //! Get constant reference to the real object.
  /*!
      Method returns constant reference to  the  real  object  inside  current
      interface. Node that this method is unsafe in case of current  interface
      has NULL pointer. So use 'isNULL()' method before to check  its  invalid
      state.

      \return Constant reference to real object, which pointer current interface has.
  */
  const T_Type& getValueRef() const;

  //! Get pointer to the real object.
  /*!
      Method returns pointer to the real object inside current interface. Note
      that result may be NULL if smart pointer  is  not  initialized.  So  use
      'isNULL()' method before to check its invalid state or use NULL checking
      strategy to define smart pointer is not initialized state alternatively.

      \return Pointer to the real object, which pointer current interface has.
  */
  T_Type* getValuePtr();
  //! Get constant pointer to the real object.
  /*!
      Method returns constant  pointer  to  the  real  object  inside  current
      interface. Note that  result  may  be  NULL  if  smart  pointer  is  not
      initialized. So use 'isNULL()' method before to check its invalid  state
      or use NULL checking strategy to define smart pointer is not initialized
      state alternatively.

      \return Constant pointer to the real object, which pointer current interface has.
  */
  const T_Type* getValuePtr() const;

  //! Serialize IPtr class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IPtr class instances.
  /*!
      \param a_rInstance - Reference to another IPtr class instance.
  */
  void swap(IPtr<T_Type>& a_rInstance);

protected:
  T_Type* m_pPointer;                   //!< Pointer to real object.

  //! Initialize smart pointer with a valid pointer to real object.
  /*!
      Smart pointer interface is initialized with pointer to  real  object  or
      with NULL.

      \param a_pPointer - Pointer to real object (default is NULL).
  */
  IPtr(T_Type* a_pPointer = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IPtr class.
  */
  IPtr(const IPtr<T_Type>& a_crInstance);
  //! Interface destructor.
 ~IPtr();

  //! Operator: Assign new valid pointer to real object.
  /*!
      \param a_pPointer - Pointer to real object.
      \return Reference to the current class instance.
  */
  IPtr<T_Type>& operator = (T_Type* a_pPointer);
  //! Operator: Assign another IPtr class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IPtr class.
      \return Reference to the current class instance.
  */
  IPtr<T_Type>& operator = (const IPtr<T_Type>& a_crInstance);

  //! Set new valid pointer to real object.
  /*!
      \param a_pPointer - Pointer to real object.
  */
  void set(T_Type* a_pPointer);
  //! Set another IPtr class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IPtr class.
  */
  void set(const IPtr<T_Type>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/IPtr.inl>
/*==========================================================================*/
#endif
