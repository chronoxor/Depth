/*!
 *  \file    IResizePolicy.hpp Resize policy interface. Resize policy is an
 *           allocation strategy which is used with arrays for determine when
 *           memory reallocation is need.
 *  \brief   Resize policy interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Resize policy interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   15.03.2006 22:08:24

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
#ifndef __IRESIZEPOLICY_HPP__
#define __IRESIZEPOLICY_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Resize policy interface.
/*!
    Resize policy represents memory allocation strategy. It contains  capacity
    bounds, current used size and resize factor. When you need for  next  free
    memory piece, you have to call  'resize'  method.  It  returns  new  block
    capacity. So if this value is not equal to  the  current  higher  capacity
    bound, you have to reallocate memory for your container.

    Note that memory size is calculated not in bytes, but in  elements  count.
    So if you want to know how much memory do you need for 5 integer items you
    have to use following constuction 'resize(5) * sizeof(int)'.
*/
class BASE_API IResizePolicy
{
  //! Type for MConceptDepthType constraint checking.
  typedef IResizePolicy TDepthCheckType;

  // Check IResizePolicy interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  IResizePolicy();
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IResizePolicy class.
  */
  IResizePolicy(const IResizePolicy& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IResizePolicy();

public:
  //! Operator: Assign another IResizePolicy class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IResizePolicy class.
      \return Reference to the current class instance.
  */
  IResizePolicy& operator = (const IResizePolicy& a_crInstance);

  //! Set another IResizePolicy class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IResizePolicy class.
  */
  void set(const IResizePolicy& a_crInstance);

  //! Get resize factor value.
  /*!
      \return Current policy resize factor value.
  */
  Tuint getResizeFactor() const;

  //! Get current lower capacity bound value.
  /*!
      \return Current lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get current higher capacity bound value.
  /*!
      \return Current higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Set resize factor.
  /*!
      Method sets new policy resize factor. If given resize factor is invalid,
      then policy will use the default value as current resize factor.

      \param a_cResizeFactor - Resize factor.
      \return true  - if resize factor successfully set. \n
              false - if resize factor is invalid. \n
  */
  virtual Tbool setResizeFactor(const Tuint a_cResizeFactor) = 0;

  //! Ask resize policy for a new size.
  /*!
      Method checks if given size bounds into the current allocated  capacity.
      If  it  does,  then  method  returns  current  higher  capacity   bound.
      Otherwise, it does capacity bounds recalculation and returns new  higher
      capacity bound.

      \param a_cSize - New allocated size.
      \return Value of the resize policy higher capacity bound.
  */
  virtual Tuint resize(const Tuint a_cSize) = 0;

  //! Serialize IResizePolicy class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IResizePolicy class instances.
  /*!
      \param a_rInstance - Reference to another IResizePolicy class instance.
  */
  void swap(IResizePolicy& a_rInstance);

protected:
  Tuint m_ResizeFactor;                 //!< Resize factor.
  Tuint m_LoCapacity;                   //!< Lower capacity bound.
  Tuint m_HiCapacity;                   //!< Higher capacity bound.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/policy/IResizePolicy.inl>
/*==========================================================================*/
#endif
