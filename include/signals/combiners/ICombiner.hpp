/*!
 *  \file    ICombiner.hpp Interface for all signal combiner classes. While
 *           creating a new signal combiner type, you should implement base
 *           ICombiner's methods.
 *  \brief   Signal combiner interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Signal combiner interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Signal containers
    VERSION:   1.0
    CREATED:   01.06.2006 20:13:31

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
#ifndef __ICOMBINER_HPP__
#define __ICOMBINER_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSignals {
/*--------------------------------------------------------------------------*/
namespace NCombiners {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Signal combiner interface.
/*!
    All signal combiner classes should implement  this  interface  to  correct
    work with signals.

    This interface contains following abstract methods:
    \li <b>ICombiner::onStart()</b> - method is called  by  signal  when  this
        signal is emitted.
    \li <b>ICombiner::onNext(a)</b> - method is called  by  signal  when  next
        signal slot is emitted. Argument 'a' provides next slot result value.
    \li <b>ICombiner::onEnd()</b> - method is called by signal  when  all  its
        slots were emitted and signal needs the result value.
*/
template <typename T_SlotReturn, typename T_SignalResult = T_SlotReturn>
class ICombiner
{
public:
  //! ICombiner slot result template type.
  typedef T_SlotReturn TSlotReturn;
  //! ICombiner signal result template type.
  typedef T_SignalResult TSignalResult;

protected:
  //! Default interface protected constructor.
  ICombiner();

public:
  //! Interface virtual destructor.
  virtual ~ICombiner();

  //! Start of the signal emitting handling.
  /*!
      This method is called by a signal when the signal is  emitted.  If  this
      method fails, signal emitting will be finished and  signal  returns  the
      default result value. Otherwise signal emitting will  be  continued  and
      all the signal's slots will be emitted.

      \return true  - if signal combiner is ready for emitting. \n
              false - if signal combiner isn't ready for emitting. \n
  */
  virtual Tbool onStart() = 0;

  //! Combine the next signal slot.
  /*!
      This method is called by a signal when next slot is  emitting.  If  this
      method fails, slot emitting  will  be  finished  and  signal  will  call
      'onEnd()' method to get the result of emitting.

      \param a_crSlotReturn - Stot result value.
      \return true  - if next slot was emitted successfully. \n
              false - if next slot was not emitted successfully. \n
  */
  virtual Tbool onNext(const T_SlotReturn& a_crSlotReturn) = 0;

  //! End of the signal emitting handling.
  /*!
      This method is called by a signal  when  all  its  slots  were  emitted.
      Method should return the result of a signal emitting.

      \return Result of a signal emitting.
  */
  virtual T_SignalResult onEnd() = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/signals/combiners/ICombiner.inl>
/*==========================================================================*/
#endif
