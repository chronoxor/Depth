/*!
 *  \file    CHashWeinberger.hpp P. J. Weinberger's hash function algorithm.
 *  \brief   P. J. Weinberger's hash function algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: P. J. Weinberger's hash function algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   11.03.2007 00:36:28

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
#ifndef __CHASHWEINBERGER_HPP__
#define __CHASHWEINBERGER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/hash/IHash.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! P. J. Weinberger's hash function algorithm.
/*!
    P. J. Weinberger's hash function.

    <b>References.</b>\n
    \li A.V. Aho  and  R.  Sethi  and  J.D.  Ullman,   Compilers:  Principles,
        Techniques, and Tools, Addison-Wesley, Reading, Massachusetts, 1986.
    \li An unfortunate  typo  in  the  implementation  of  HashString0  in the
        previous release caused an extremely poor  behavior  (for  details see
        source code). Thanks  to  Josh  Bloch  (jbloch@eng.sun.com)  who  also
        informed me about another  fault  that  is  found  in  Aho,  Sethi and
        Ullman's book: The line with h ^= (g >> 28) now replaces the  original
        h ^= (g >> 24). According  to  a  correspondence  of  Josh  Bloch with
        Ravi  Sethi  this correction will be made in the next  edition  of the
        book. Including   these   two  changes  this  hash  function   is  now
        comparable  to  Vo's, Torek's and WAIS's hash functions.

    \see NDepth::NAlgorithms::NHash::CHashELF
*/
class BASE_API CHashWeinberger :
  public IHash
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CHashWeinberger TDepthCheckType;

  // Check CHashWeinberger class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CHashWeinberger();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashWeinberger class.
  */
  CHashWeinberger(const CHashWeinberger& a_crInstance);
  //! Class virtual destructor.
  virtual ~CHashWeinberger();

  //! Operator: Assign another CHashWeinberger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashWeinberger class.
      \return Reference to the current class instance.
  */
  CHashWeinberger& operator = (const CHashWeinberger& a_crInstance);

  //! Set another CHashWeinberger class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashWeinberger class.
  */
  void set(const CHashWeinberger& a_crInstance);

  // IHash interface overriding methods.
  virtual Tuint getHash() const;
  virtual Tbool initialize(const Tuint a_cSeed = 0);
  virtual Tuint hash(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  virtual Tbool close();

  //! Serialize CHashWeinberger class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashWeinberger class instances.
  /*!
      \param a_rInstance - Reference to another CHashWeinberger class instance.
  */
  void swap(CHashWeinberger& a_rInstance);

private:
  Tuint m_Hash;                         //!< Current hash value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/hash/CHashWeinberger.inl>
/*==========================================================================*/
#endif
