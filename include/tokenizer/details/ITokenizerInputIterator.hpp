/*!
 *  \file    ITokenizerInputIterator.hpp Tokenizer input iterator interface.
 *           It gives ability to check for valid state and input characters
 *           for the tokenizer.
 *  \brief   Tokenizer input iterator interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer input iterator interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer details
    VERSION:   1.0
    CREATED:   17.04.2009 02:38:24

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
#ifndef __ITOKENIZERINPUTITERATOR_HPP__
#define __ITOKENIZERINPUTITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/tokenizer.hpp>
#include <Depth/include/common/IClonable.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Tokenizer input iterator interface.
/*!
    Tokenizer input iterator is the base tokenizer input interface.  It  gives
    ability to check for valid state of iterator  and  also  input  characters
    for the tokenizer.
*/
class TOKENIZER_API ITokenizerInputIterator :
  public NCommon::IClonable<ITokenizerInputIterator>
{
protected:
  //! Default interface protected constructor.
  ITokenizerInputIterator();

public:
  //! Interface virtual destructor.
  virtual ~ITokenizerInputIterator();

  //! Operator: Get constant reference to the character in general form from the current iterator.
  /*!
      \return Constant reference to the character in general form.
      \see NDepth::NTokenizer::NDetails::ITokenizerInputIterator::getValueRef()
  */
  const Tuint& operator * () const;
  //! Operator: Get constant pointer to the character in general form from the current iterator.
  /*!
      \return Constant pointer to the character in general form.
      \see NDepth::NTokenizer::NDetails::ITokenizerInputIterator::getValuePtr()
  */
  const Tuint* operator -> () const;

  //! Tokenizer input iterator valid checking method.
  /*!
      Method checks if tokenizer input iterator is initialized and can be used
      to get characters from it.

      \return true  - if tokenizer input iterator is valid. \n
              false - if tokenizer input iterator is not valid. \n
  */
  virtual Tbool isValid() const = 0;

  //! Get constant reference to the character in general form from the current iterator.
  /*!
      Method returns constant reference to  the  current  character  from  the
      current input iterator. Note that result may be broken  if  iterator  is
      not initialized. So use 'isValid()' method before  to  check  its  valid
      state.

      \return Constant reference to the character in general form.
  */
  virtual const Tuint& getValueRef() const = 0;
  //! Get constant pointer to the character in general form from the current iterator.
  /*!
      Method returns constant  pointer  to  the  current  character  from  the
      current input iterator. Note that result may be NULL if iterator is  not
      initialized. So use 'isValid()' method before to check its  valid  state
      or use NULL checking strategy to  define  iterator  is  not  initialized
      state alternatively.

      \return Constant pointer to the character in general form.
  */
  virtual const Tuint* getValuePtr() const = 0;

  //! Do some forward iterations.
  /*!
      This method makes some forward iterations with current iterator instance
      and returns number of steps that have been successfully done.

      Each forward iteration will input a  new  character  for  the  tokenizer
      using current input iterator.

      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that current iterator have gone.
  */
  virtual Tuint stepForward(const Tuint a_cStepCount = 1) = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/details/ITokenizerInputIterator.inl>
/*==========================================================================*/
#endif
