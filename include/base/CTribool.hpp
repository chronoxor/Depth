/*!
 *  \file    CTribool.hpp Three state boolean logic class. It represents all
 *           operations with 3-state boolean logic values.
 *  \brief   Three state boolean logic class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Three state boolean logic class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   01.02.2006 02:42:24

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
#ifndef __CTRIBOOL_HPP__
#define __CTRIBOOL_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Three state boolean logic class.
/*!
    Three state boolean value can have one of the following states:
    - false - signals that boolean value is in passive state.
    - true  - signals that boolean value is in active state.
    - null  - signals that boolean value is unknown.

    All calculations with three state boolean value are  performing  according
    to following truth tables:

    Logical negation (operator !):
      !false -> true
      !true  -> false
      !null  -> null

    Logical conjuction (operator &&):
      false && true   -> false
      false && false  -> false
      false && null   -> false
      true  && true   -> true
      true  && false  -> false
      true  && null   -> null
      null  && true   -> null
      null  && false  -> false
      null  && null   -> null

    Logical disjunction (operator ||):
      false || true   -> true
      false || false  -> false
      false || null   -> null
      true  || true   -> true
      true  || false  -> true
      true  || null   -> true
      null  || true   -> true
      null  || false  -> null
      null  || null   -> null

    Three state boolean values equality comparison (operator ==):
      false == true   -> false
      false == false  -> true
      false == null   -> null
      true  == true   -> true
      true  == false  -> false
      true  == null   -> null
      null  == true   -> null
      null  == false  -> null
      null  == null   -> null

    Three state boolean values not equality comparison (operator !=):
      false != true   -> true
      false != false  -> false
      false != null   -> null
      true  != true   -> false
      true  != false  -> true
      true  != null   -> null
      null  != true   -> null
      null  != false  -> null
      null  != null   -> null
*/
class BASE_API CTribool
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTribool TDepthCheckType;

  // Check CTribool class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  enum ETriboolState                    //! Three state boolean value state.
  {
    e_FALSE,                            //!< 'false' value.
    e_TRUE,                             //!< 'true' value.
    e_NULL                              //!< 'null' value.
  };

  //! Default class constructor.
  /*!
      \param a_cValue - Two state boolean value (default is false).
  */
  CTribool(const Tbool a_cValue = false);
  //! Initialize three state boolean value with the one of the valid states.
  /*!
      \param a_cValue - Three state boolean value.
  */
  CTribool(const ETriboolState a_cValue);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTribool class.
  */
  CTribool(const CTribool& a_crInstance);
  //! Class destructor.
 ~CTribool();

  //! Operator: Equal to two state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Two state boolean value.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator == (const CTribool& a_crInstance, const Tbool a_cValue);
  //! Operator: Equal to three state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Three state boolean value.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator == (const CTribool& a_crInstance, const ETriboolState a_cValue);
  //! Operator: Equal to another CTribool class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTribool class.
      \param a_crInstance2 - Constant reference to another instance of the CTribool class.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator == (const CTribool& a_crInstance1, const CTribool& a_crInstance2);
  //! Operator: Equal to two state boolean value.
  /*!
      \param a_cValue - Two state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator == (const Tbool a_cValue, const CTribool& a_crInstance);
  //! Operator: Equal to three state boolean value.
  /*!
      \param a_cValue - Three state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator == (const ETriboolState a_cValue, const CTribool& a_crInstance);

  //! Operator: Not equal to two state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Two state boolean value.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator != (const CTribool& a_crInstance, const Tbool a_cValue);
  //! Operator: Not equal to three state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Three state boolean value.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator != (const CTribool& a_crInstance, const ETriboolState a_cValue);
  //! Operator: Not equal to another CTribool class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTribool class.
      \param a_crInstance2 - Constant reference to another instance of the CTribool class.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator != (const CTribool& a_crInstance1, const CTribool& a_crInstance2);
  //! Operator: Not equal to two state boolean value.
  /*!
      \param a_cValue - Two state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator != (const Tbool a_cValue, const CTribool& a_crInstance);
  //! Operator: Not equal to three state boolean value.
  /*!
      \param a_cValue - Three state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Equality three state boolean value.
  */
  friend BASE_API CTribool operator != (const ETriboolState a_cValue, const CTribool& a_crInstance);

  //! Operator: Logic conjuction with two state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Two state boolean value.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator && (const CTribool& a_crInstance, const Tbool a_cValue);
  //! Operator: Logic conjuction with three state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Three state boolean value.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator && (const CTribool& a_crInstance, const ETriboolState a_cValue);
  //! Operator: Logic conjuction with another CTribool class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTribool class.
      \param a_crInstance2 - Constant reference to another instance of the CTribool class.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator && (const CTribool& a_crInstance1, const CTribool& a_crInstance2);
  //! Operator: Logic conjuction with two state boolean value.
  /*!
      \param a_cValue - Two state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator && (const Tbool a_cValue, const CTribool& a_crInstance);
  //! Operator: Logic conjuction with three state boolean value.
  /*!
      \param a_cValue - Three state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator && (const ETriboolState a_cValue, const CTribool& a_crInstance);

  //! Operator: Logic disjunction with two state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Two state boolean value.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator || (const CTribool& a_crInstance, const Tbool a_cValue);
  //! Operator: Logic disjunction with three state boolean value.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \param a_cValue - Three state boolean value.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator || (const CTribool& a_crInstance, const ETriboolState a_cValue);
  //! Operator: Logic disjunction with another CTribool class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CTribool class.
      \param a_crInstance2 - Constant reference to another instance of the CTribool class.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator || (const CTribool& a_crInstance1, const CTribool& a_crInstance2);
  //! Operator: Logic disjunction with two state boolean value.
  /*!
      \param a_cValue - Two state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator || (const Tbool a_cValue, const CTribool& a_crInstance);
  //! Operator: Logic disjunction with three state boolean value.
  /*!
      \param a_cValue - Three state boolean value.
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return Result three state boolean value.
  */
  friend BASE_API CTribool operator || (const ETriboolState a_cValue, const CTribool& a_crInstance);

  //! Operator: Unary not.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CTribool class.
      \return New instance of CTribool class with applied not operator.
  */
  friend BASE_API CTribool operator ! (const CTribool& a_crInstance);

  //! Operator: Assign two state boolean value.
  /*!
      \param a_cValue - Two state boolean value.
      \return Reference to the current class instance.
  */
  CTribool& operator = (const Tbool a_cValue);
  //! Operator: Assign three state boolean value.
  /*!
      \param a_cValue - Three state boolean value.
      \return Reference to the current class instance.
  */
  CTribool& operator = (const ETriboolState a_cValue);
  //! Operator: Assign another CTribool class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTribool class.
      \return Reference to the current class instance.
  */
  CTribool& operator = (const CTribool& a_crInstance);

  //! Operator: Get reference to the current three state boolean value.
  /*!
      \return Reference to the current three state boolean value.
  */
  operator ETriboolState& ();
  //! Operator: Get constant reference to the current three state boolean value.
  /*!
      \return Constant reference to the current three state boolean value.
  */
  operator const ETriboolState& () const;

  //! Operator: Get pointer to the current three state boolean value.
  /*!
      \return Pointer to the current three state boolean value.
  */
  operator ETriboolState* ();
  //! Operator: Get constant pointer to the current three state boolean value.
  /*!
      \return Constant pointer to the current three state boolean value.
  */
  operator const ETriboolState* () const;

  //! Set two state boolean value.
  /*!
      \param a_cValue - Two state boolean value.
  */
  void set(const Tbool a_cValue);
  //! Set three state boolean value.
  /*!
      \param a_cValue - Three state boolean value.
  */
  void set(const ETriboolState a_cValue);
  //! Set another CTribool class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTribool class.
  */
  void set(const CTribool& a_crInstance);

  //! Get three state boolean value.
  /*!
      \return Three state boolean value.
  */
  ETriboolState getValue() const;

  //! Is current boolean value 'true'?
  /*!
      \return true  - if current boolean value is 'true'. \n
              false - if current boolean value is not 'true'. \n
  */
  Tbool isTrue() const;
  //! Is current boolean value 'false'?
  /*!
      \return true  - if current boolean value is 'false'. \n
              false - if current boolean value is not 'false'. \n
  */
  Tbool isFalse() const;
  //! Is current boolean value 'null'?
  /*!
      \return true  - if current boolean value is 'null'. \n
              false - if current boolean value is not 'null'. \n
  */
  Tbool isNull() const;

  //! Set current boolean value to 'true'.
  void setTrue();
  //! Set current boolean value to 'false'.
  void setFalse();
  //! Set current boolean value to 'null'.
  void setNull();

  //! Get 'true' constant value.
  /*!
      \return 'true' constant value.
  */
  static ETriboolState getTrue();
  //! Get 'false' constant value.
  /*!
      \return 'false' constant value.
  */
  static ETriboolState getFalse();
  //! Get 'null' constant value.
  /*!
      \return 'null' constant value.
  */
  static ETriboolState getNull();

  //! Get three state boolean value from two state boolean value.
  /*!
      \param a_cValue - Two state boolean value.
      \return Three state boolean value.
  */
  static ETriboolState getTribool(const Tbool a_cValue);

  //! Get equality of two three state boolean values as a three state boolean value.
  /*!
      \param a_cValue1 - Three state boolean value 1.
      \param a_cValue2 - Three state boolean value 2.
      \return Equality three state boolean value.
  */
  static ETriboolState getEqual(const ETriboolState a_cValue1, const ETriboolState a_cValue2);
  //! Get not equality of two three state boolean values as a three state boolean value.
  /*!
      \param a_cValue1 - Three state boolean value 1.
      \param a_cValue2 - Three state boolean value 2.
      \return Equality three state boolean value.
  */
  static ETriboolState getNotEqual(const ETriboolState a_cValue1, const ETriboolState a_cValue2);

  //! Get logical not of three state boolean value.
  /*!
      \param a_cValue - Three state boolean value.
      \return Result of logical operation.
  */
  static ETriboolState getNot(const ETriboolState a_cValue);
  //! Get logical conjuction of two three state boolean values.
  /*!
      \param a_cValue1 - Three state boolean value 1.
      \param a_cValue2 - Three state boolean value 2.
      \return Result of logical operation.
  */
  static ETriboolState getConjuction(const ETriboolState a_cValue1, const ETriboolState a_cValue2);
  //! Get logical disjunction of two three state boolean values.
  /*!
      \param a_cValue1 - Three state boolean value 1.
      \param a_cValue2 - Three state boolean value 2.
      \return Result of logical operation.
  */
  static ETriboolState getDisjunction(const ETriboolState a_cValue1, const ETriboolState a_cValue2);

  //! Serialize CTribool class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTribool class instances.
  /*!
      \param a_rInstance - Reference to another CTribool class instance.
  */
  void swap(CTribool& a_rInstance);

private:
  ETriboolState m_Value;                //!< Three state boolean value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SERIALIZATION FUNCTION DECLARATIONS                                      */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
//! Serialization load three state boolean value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized three state boolean value instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NBase::CTribool::ETriboolState& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save three state boolean value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized three state boolean value instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NBase::CTribool::ETriboolState& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize three state boolean value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized three state boolean value instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NBase::CTribool::ETriboolState& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CTribool.inl>
/*==========================================================================*/
//! \example example-base-CTribool.cpp
/*--------------------------------------------------------------------------*/
//! \test test-base-CTribool.cpp
/*==========================================================================*/
#endif
