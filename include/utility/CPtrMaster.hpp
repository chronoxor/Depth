/*!
 *  \file    CPtrMaster.hpp Master smart pointer class. Creating the smart
 *           pointer creates object instance, copying smart pointer cloning
 *           the object, deleting smart pointer deletes the object.
 *  \brief   Master smart pointer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Master smart pointer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   23.05.2006 02:07:52

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
#ifndef __CPTRMASTER_HPP__
#define __CPTRMASTER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IPtr.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Master smart pointer class.
/*!
    Master smart pointer create and hold new object instance.

    Master smart pointer use the following rules:
    1) Creating empty smart pointer leads to creating an object  with  default
       constructor.
    2) Creating new smart pointer from existing object leads to  cloning  this
       object and hold its clone.
    3) Creating new smart pointer from another smart pointer of the same  type
       leads to colne object under given smart pointer and hold this clone.
    4) Setting non empty smart pointer with  another  object  deletes  current
       controlling object, clone the given one and hold this clone.
    5) Setting non empty smart pointer  with  another  smart  pointer  deletes
       current controlling object, colne object under given smart pointer  and
       hold this clone.
    6) Deleting non empty smart pointer also deletes a holding object.

    Serialization: Master smart pointer cannot be serialized.
*/
template <typename T_Type>
class CPtrMaster :
  public NCommon::IPtr<T_Type>
{
  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CPtrMaster<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check CPtrMaster class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! CPtrMaster value type.
  typedef typename NCommon::IPtr<T_Type>::TType TType;
  //! CPtrMaster constant reference type.
  typedef typename NCommon::IPtr<T_Type>::TConstReference TConstReference;
  //! CPtrMaster reference type.
  typedef typename NCommon::IPtr<T_Type>::TReference TReference;
  //! CPtrMaster pointer type.
  typedef typename NCommon::IPtr<T_Type>::TPointer TPointer;

  //! Default class constructor.
  /*!
      Create new object instance with default constructor  and  hold  it  with
      current smart pointer.
  */
  CPtrMaster();
  //! Initialize smart pointer with a clone of a given object.
  /*!
      Method clones given object  and  hold  this  clone  with  current  smart
      pointer.

      \param a_crObject - Constant reference to cloning object.
  */
  CPtrMaster(const T_Type& a_crObject);
  //! Class copy constructor.
  /*!
      Method clones object (if exist) from given smart pointer and  hold  this
      clone with current smart pointer. If given smart pointer is empty,  then
      object will be created with its default constructor.

      \param a_crInstance - Constant reference to another instance of the CPtrMaster class.
  */
  CPtrMaster(const CPtrMaster<T_Type>& a_crInstance);
  //! Class virtual destructor.
  /*!
      If current smart pointer holds an object, then delete  this  controlling
      object.
  */
  virtual ~CPtrMaster();

  //! Operator: Assign new real object.
  /*!
      Method deletes current holding object and clones given object  and  hold
      this clone with current smart pointer.

      \param a_crObject - Constant reference to cloning object.
      \return Reference to the current class instance.
  */
  CPtrMaster<T_Type>& operator = (const T_Type& a_crObject);
  //! Operator: Assign another CPtrMaster class instance.
  /*!
      Method deletes current holding object and clones object (if exist)  from
      given smart pointer and hold this clone with current smart  pointer.  If
      given smart pointer is empty, then  object  will  be  created  with  its
      default constructor.

      \param a_crInstance - Constant reference to another instance of the CPtrMaster class.
      \return Reference to the current class instance.
  */
  CPtrMaster<T_Type>& operator = (const CPtrMaster<T_Type>& a_crInstance);

  //! Set new real object.
  /*!
      Method deletes current holding object and clones given object  and  hold
      this clone with current smart pointer.

      \param a_crObject - Constant reference to cloning object.
      \return true  - if pointer was successfully set. \n
              false - if pointer was not successfully set. \n
  */
  Tbool set(const T_Type& a_crObject);
  //! Set another CPtrMaster class instance.
  /*!
      Method deletes current holding object and clones object (if exist)  from
      given smart pointer and hold this clone with current smart  pointer.  If
      given smart pointer is empty, then  object  will  be  created  with  its
      default constructor.

      \param a_crInstance - Constant reference to another instance of the CPtrMaster class.
      \return true  - if another smart pointer was successfully set. \n
              false - if another smart pointer was not successfully set. \n
  */
  Tbool set(const CPtrMaster<T_Type>& a_crInstance);

  //! Release current smart pointer.
  /*!
      Releasing smart pointer deletes the holding object under this pointer.

      \return Pointer value before smart pointer releasing.
      \return true  - if current smart pointer was successfully released. \n
              false - if current smart pointer was not successfully released. \n
  */
  Tbool release();

  //! Serialize CPtrMaster class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPtrMaster class instances.
  /*!
      \param a_rInstance - Reference to another CPtrMaster class instance.
  */
  void swap(CPtrMaster<T_Type>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CPtrMaster.inl>
/*==========================================================================*/
//! \example example-utility-CPtrMaster.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-CPtrMaster.cpp
/*==========================================================================*/
#endif
