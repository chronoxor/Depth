/*!
 *  \file    CGCPtr.hpp GC smart pointer template class contains memory
 *           allocated information and helps to manage allocated memory
 *           blocks during the GC operation.
 *  \brief   GC smart pointer template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC smart pointer template class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   24.06.2007 21:38:37

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
#ifndef __CGCPTR_HPP__
#define __CGCPTR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/common/IPtr.hpp>
#include <Depth/include/memory/CMemory.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! GC smart pointer template class.
/*!
    GC smart pointer template class keeps  memory  allocation  information  by
    registering itself in the GC engine. Registration information is  used  to
    detect which pointers to the  objects  are  non  referenced  and  must  be
    released by calling corresponding object destructor.

    If user wants to use GC functionality in its code, all dynamically created
    objects must be wrapped with the CGCPtr template class.  Otherwise  manual
    memory management must be performed.

    When GC smart pointer is created with a given pointer value, it  registers
    itself  in  the  GC  engine.  When  GC  smart  pointer  is  destroyed,  it
    unregisters itself in the GC engine.
*/
template <typename T_Type>
class CGCPtr :
  public NCommon::IPtr<T_Type>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CGCPtr<T_Type> TDepthCheckType;

  // Check CGCPtr class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! CGCPtr value type.
  typedef typename NCommon::IPtr<T_Type>::TType TType;
  //! CGCPtr constant reference type.
  typedef typename NCommon::IPtr<T_Type>::TConstReference TConstReference;
  //! CGCPtr reference type.
  typedef typename NCommon::IPtr<T_Type>::TReference TReference;
  //! CGCPtr pointer type.
  typedef typename NCommon::IPtr<T_Type>::TPointer TPointer;

  //! Default class constructor.
  /*!
      \param a_pPointer - Pointer to the wrapping object (default is NULL).
  */
  CGCPtr(T_Type* a_pPointer = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CGCPtr class.
  */
  template <typename T_OtherType>
  CGCPtr(const CGCPtr<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CGCPtr();

  //! Operator: Assign pointer.
  /*!
      \param a_pPointer - Pointer to the wrapping object.
      \return Pointer to the current class instance.
  */
  CGCPtr<T_Type>& operator = (T_Type* a_pPointer);
  //! Operator: Assign another CGCPtr class instance.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CGCPtr class.
      \return Pointer to the current class instance.
  */
  template <typename T_OtherType>
  CGCPtr<T_Type>& operator = (const CGCPtr<T_OtherType>& a_crInstance);

  //! Set pointer.
  /*!
      \param a_pPointer - Pointer to the wrapping object.
  */
  void set(T_Type* a_pPointer);
  //! Set another CGCPtr class instance.
  /*!
      \param a_crInstance - Constant pointer to another instance of the CGCPtr class.
  */
  template <typename T_OtherType>
  void set(const CGCPtr<T_OtherType>& a_crInstance);

  //! Serialize CGCPtr class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CGCPtr class instances.
  /*!
      \param a_rInstance - Reference to another CGCPtr class instance.
  */
  void swap(CGCPtr<T_Type>& a_rInstance);

private:
  template <typename T_OtherType>
  struct SDestructorWrapper             //! Destructor wrapping structure.
  {
    //! Destroy given object with operator 'delete'.
    /*!
        Method destroys  given  object  with  operator  'delete'.  The  object
        destructor is invoked.

        \param a_pObjectPointer - Pointer to the destroying object.
    */
    static void destroy(Tptr a_pObjectPointer);
  };

  //! Update GC smart pointer in the GC engine.
  void update();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/memory/gc/CGCPtr.inl>
/*==========================================================================*/
//! \example example-memory-GC.cpp
/*--------------------------------------------------------------------------*/
//! \test test-memory-GC.cpp
/*==========================================================================*/
#endif
