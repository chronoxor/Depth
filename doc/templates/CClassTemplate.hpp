/*!
 *  \file    CClassTemplate.hpp Example of class header.
 *  \brief   This is just an appearance example of class header.
 *  \author  unknown
 *  \version 1.0
 *  \date    30.11.2005
 *  \bug     Note here if class has some bugs.
 *  \warning Note here about any warning.
 *  \todo    Todo notes.
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template

    AUTHOR:    unknown
    GROUP:     The NULL workgroup
    PROJECT:   The project
    PART:      Main
    VERSION:   1.0
    CREATED:   30.11.2005 21:41:53

    EMAIL:     some@mail.net
    WWW:       http://some.net

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#ifndef __CCLASSTEMPLATE_HPP__
#define __CCLASSTEMPLATE_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NTemplate {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template class small brief.
/*!
    A more elaborate class description.
*/
class SOME_API CClassTemplate
{
public:
  //! Default class constructor.
  /*!
      A more elaborate description of the default class constructor.
  */
  CClassTemplate();
  //! Class initializing constructor.
  /*!
      A more elaborate description of the class constructor.

      \param a_cValue - CClassTemplate initial value.
  */
  CClassTemplate(const int a_cValue);
  //! Class copy constructor.
  /*!
      A more elaborate description of the class copy constructor.

      \param a_cInstance - Another instance of the CClassTemplate class.
  */
  CClassTemplate(const CClassTemplate& a_cInstance);
  //! Class destructor.
  /*!
      A more elaborate description of the class destructor.
  */
  virtual ~CClassTemplate();

  //! Operator: Equal to integer number.
  /*!
      A more elaborate description of the operator.

      \param a_cValue - Integer value.
      \return Equality state.
  */
  bool operator == (const int a_cValue) const;
  //! Operator: Equal to another class instance.
  /*!
      A more elaborate description of the operator.

      \param a_cInstance - Another instance of the CClassTemplate class.
      \return Equality state.
  */
  bool operator == (const CClassTemplate& a_cInstance) const;
  //! Operator: Not equal to integer number.
  /*!
      A more elaborate description of the operator.

      \param a_cValue - Integer value.
      \return Equality state.
  */
  bool operator != (const int a_cValue) const;
  //! Operator: Not equal to another class instance.
  /*!
      A more elaborate description of the operator.

      \param a_cInstance - Another instance of the CClassTemplate class.
      \return Equality state.
  */
  bool operator != (const CClassTemplate& a_cInstance) const;

  //! Operator: Equal to integer number.
  /*!
      A more elaborate description of the operator.

      \param a_cValue - Integer value.
      \param a_cInstance - Another instance of the CClassTemplate class.
      \return Equality state.
  */
  friend SOME_API bool operator == (const int a_cValue,const CClassTemplate& a_cInstance);
  //! Operator: Not equal to integer number.
  /*!
      A more elaborate description of the operator.

      \param a_cValue - Integer value.
      \param a_cInstance - Another instance of the CClassTemplate class.
      \return Equality state.
  */
  friend SOME_API bool operator != (const int a_cValue,const CClassTemplate& a_cInstance);

  //! Operator: Assign new integer number.
  /*!
      A more elaborate description of the operator.

      \param a_cValue - Integer value.
      \return Reference to the current class instance.
  */
  CClassTemplate& operator = (const int a_cValue);
  //! Operator: Assign new another class instance.
  /*!
      A more elaborate description of the operator.

      \param a_cInstance - Another instance of the CClassTemplate class.
      \return Reference to the current class instance.
  */
  CClassTemplate& operator = (const CClassTemplate& a_cInstance);

  //! Operator: Cast current class to integer number.
  /*!
      A more elaborate description of the operator.

      \return Integer number.
  */
  operator int ();
  //! Operator: Cast current class to constant integer number.
  /*!
      A more elaborate description of the operator.

      \return Constant integer number.
  */
  operator const int () const;
  //! Operator: Cast current class to pointer to the integer number.
  /*!
      A more elaborate description of the operator.

      \return Pointer to the integer number.
  */
  operator int* ();
  //! Operator: Cast current class to constant pointer to the integer number.
  /*!
      A more elaborate description of the operator.

      \return Constant pointer to the integer number.
  */
  operator const int* () const;

  //! Set integer value.
  /*!
      A more elaborate description of the method.

      \param a_cValue - New class integer value.
      \see CClassTemplate(), getValue().
  */
  void set(const int a_cValue);
  //! Set another class instance.
  /*!
      A more elaborate description of the method.

      \param a_cInstance - Another instance of the CClassTemplate class.
      \see CClassTemplate(), getValue().
  */
  void set(const CClassTemplate& a_cInstance);

  //! Get integer value.
  /*!
      A more elaborate description of the method.

      \return Class integer value.
      \see CClassTemplate(), set().
  */
  int getValue() const;

private:
  int m_Value;                          //!< Class member description
};
/*==========================================================================*/
}
/*==========================================================================*/
#include "CClassTemplate.inl"
/*==========================================================================*/
#endif
