/*!
 *  \file    IHash.hpp Interface for all hash functions.
 *  \brief   Hash function interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash function interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   09.03.2007 00:56:35

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
#ifndef __IHASH_HPP__
#define __IHASH_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Hash function interface.
/*!
    Hash function interface is used as a base interface for all hash  function
    implementations.

    A hash function is a reproducible method of turning some kind of data into
    a (relatively) small number that may serve as a digital  "fingerprint"  of
    data. The algorithm "chops and mixes" (i.e.,  substitutes  or  transposes)
    data to create such fingerprints, called hash values. These  are  commonly
    as indices into hash tables or hash files.  Cryptographic  hash  functions
    are used for various purposes in information security applications.

    Example:
    \code
    Tuint   size = getBufferSize();
    Tbuffer buffer = getBuffer();
    IHash&  hash_function = getHashFunction();

    // Initialize current hash function context.
    hash_function.initialize();
    // Feed hash function with some data.
    hash_function.hash(buffer, size);
    // Close current hash function context.
    hash_function.close();
    // Get current hash value.
    Tuint hash = hash_function.getHash();
    \endcode

    <b>Taken from:</b>\n
    Hash function from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Hash_function
*/
class BASE_API IHash
{
protected:
  //! Default interface protected constructor.
  IHash();

public:
  //! Interface virtual destructor.
  virtual ~IHash();

  //! Get current hash function value.
  /*!
      The method returns current hash function value. It is recommended to get
      hash function value only after hash operations were  performed  and  the
      hash function context is closed.

      \return Current hash function value.
  */
  virtual Tuint getHash() const = 0;

  //! Initialize hash function context with the given seed.
  /*!
      The method initializes hash function context with  the  given  seed.  It
      should be called before performing hash operations. Default  seed  value
      depends on corresponding hash function.

      \param a_cSeed - Hash function seed value (default is 0).
      \return true  - if the hash function context was successfully initialized. \n
              false - if the hash function context was not successfully initialized. \n
  */
  virtual Tbool initialize(const Tuint a_cSeed = 0) = 0;
  //! Hash given buffer with the current hash function context.
  /*!
      The method feeds given buffer to the current hash function  and  updates
      hash value. It should be called during performing hash operations.

      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Buffer size.
      \return Count of fed buffer bytes. If everything is ok, it should be equal to the buffer size.
  */
  virtual Tuint hash(Tcbuffer a_cpBuffer, const Tuint a_cSize) = 0;
  //! Close hash function context.
  /*!
      The method closes hash function  context.  It  should  be  called  after
      performing hash operations.

      \return true  - if the hash function context was successfully closed. \n
              false - if the hash function context was not successfully closed. \n
  */
  virtual Tbool close() = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/hash/IHash.inl>
/*==========================================================================*/
//! \example example-algorithms-AHash.cpp
/*--------------------------------------------------------------------------*/
//! \test test-algorithms-AHash.cpp
/*==========================================================================*/
#endif
