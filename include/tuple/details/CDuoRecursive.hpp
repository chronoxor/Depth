/*!
 *  \file    CDuoRecursive.hpp Duo template class represents data structure
 *           which contains two fields (v1, v2) with different data types.
 *           Recursive duo specialization.
 *  \brief   Duo template class (recursive duo specialization).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Duo template class (recursive duo specialization).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple details
    VERSION:   1.0
    CREATED:   07.03.2006 03:39:22

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
#ifndef __CDUORECURSIVE_HPP__
#define __CDUORECURSIVE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/details/CDuoSingle.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Duo template class (recursive duo specialization).
/*!
    Duo with another duo in the second value of the current duo.
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class CDuo<T_Type1, CDuo<T_Type2, T_Type3> >
{
  //! Type for the MConceptConstructible constraint checking for T_Type1.
  typedef T_Type1 TType1ConstructibleCheckType;
  //! Type for the MConceptDepthType constraint checking.
  typedef CDuo<T_Type1, CDuo<T_Type2, T_Type3> > TDepthCheckType;

  // Check T_Type1 template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TType1ConstructibleCheckType);
  // Check CDuo class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  enum
  {
    N = CDuo<T_Type2, T_Type3>::N + 1   //!< Number of fields in duo.
  };

  //! Duo first template type.
  typedef T_Type1 TType1;
  //! Duo second template type.
  typedef CDuo<T_Type2, T_Type3> TType2;

  //! Default class constructor.
  CDuo();
  //! Initialize duo with given value and another duo.
  /*!
      \param a_crValue1 - Constant reference to the first duo value.
      \param a_crValue2 - Constant reference to the second duo recursive value.
  */
  CDuo(const T_Type1& a_crValue1, const CDuo<T_Type2, T_Type3>& a_crValue2);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDuo class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
  CDuo(const CDuo<T_OtherType1, CDuo<T_OtherType2, T_OtherType3> >& a_crInstance);
  //! Class destructor.
 ~CDuo();

  //! Operator: Assign another CDuo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDuo class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
  CDuo<T_Type1, CDuo<T_Type2, T_Type3> >& operator = (const CDuo<T_OtherType1, CDuo<T_OtherType2, T_OtherType3> >& a_crInstance);

  //! Set duo values.
  /*!
      \param a_crValue1 - Constant reference to the first duo value.
      \param a_crValue2 - Constant reference to the second duo recursive value.
  */
  void set(const T_Type1& a_crValue1, const CDuo<T_Type2, T_Type3>& a_crValue2);
  //! Set another CDuo class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDuo class.
  */
  template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
  void set(const CDuo<T_OtherType1, CDuo<T_OtherType2, T_OtherType3> >& a_crInstance);

  //! Get first duo value.
  /*!
      \return Reference to the first duo value.
  */
  T_Type1& getValue1();
  //! Get first duo value (constant version).
  /*!
      \return Constant reference to the first duo value.
  */
  const T_Type1& getValue1() const;

  //! Get second duo recursive value.
  /*!
      \return Reference to the second duo recursive value.
  */
  CDuo<T_Type2, T_Type3>& getValue2();
  //! Get second duo recursive value (constant version).
  /*!
      \return Constant reference to the second duo recursive value.
  */
  const CDuo<T_Type2, T_Type3>& getValue2() const;

  //! Serialize CDuo class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDuo class instances.
  /*!
      \param a_rInstance - Reference to another CDuo class instance.
  */
  void swap(CDuo<T_Type1, CDuo<T_Type2, T_Type3> >& a_rInstance);

private:
  T_Type1 m_Value1;                     //!< Duo first value.
  CDuo<T_Type2, T_Type3> m_Value2;      //!< Duo second recursive value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/details/CDuoRecursive.inl>
/*==========================================================================*/
#endif
