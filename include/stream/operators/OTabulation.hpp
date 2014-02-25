/*!
 *  \file    OTabulation.hpp Tabulation stream control operator. It is used to
 *           manipulate (read, peek, push, write) with tab characters through
 *           stream operators.
 *  \brief   Tabulation stream control operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tabulation stream control operator.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   21.01.2009 00:23:26

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
#ifndef __OTABULATION_HPP__
#define __OTABULATION_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/stream/IWriter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* OPERATOR DECLARATIONS                                                    */
/*==========================================================================*/
//! Tabulation stream control operator.
/*!
    Tabulation stream control operator is  used  to  manipulate  (read,  peek,
    push, write) with tab characters through stream operators.
*/
class BASE_API tabulation
{
public:
  //! //! Default class constructor.
  tabulation();
  //! //! Initialize with ASCII/Unicode flag.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
  */
  tabulation(const Tbool a_cIsASCII);

  //! Operator: Get new tabulation stream control operator with the given encoding.
  /*!
      \return New instance of the tabulation stream control operator with the given encoding.
  */
  tabulation operator () () const;
  //! Operator: Get new tabulation stream control operator with the given encoding.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return New instance of the tabulation stream control operator with the given encoding.
  */
  tabulation operator () (const Tbool a_cIsASCII) const;

  //! Operator: Read tabulation stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crTab - Constant reference to the tabulation stream control operator.
      \return Reference to the instance of the IReader interface.
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const tabulation& a_crTab);
  //! Operator: Peek tabulation stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crTab - Constant reference to the tabulation stream control operator.
      \return Reference to the instance of the IReader interface.
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const tabulation& a_crTab);
  //! Operator: Push tabulation stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crTab - Constant reference to the tabulation stream control operator.
      \return Reference to the instance of the IReader interface.
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const tabulation& a_crTab);
  //! Operator: Write tabulation stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crTab - Constant reference to the tabulation stream control operator.
      \return Reference to the instance of the IWriter interface.
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const tabulation& a_crTab);

  Tuint m_IsASCII;                      //!< ASCII encoding flag.
};
extern BASE_API tabulation tab;         //!< Global instance of the tabulation stream control operator.
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OTabulation.inl>
/*==========================================================================*/
#endif
