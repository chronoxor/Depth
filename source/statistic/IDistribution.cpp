/*!
 *  \file    IDistribution.cpp Interface for all statistical distributions.
 *  \brief   Statistical distribution interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Statistical distribution interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   04.03.2009 02:13:10

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
#include <Depth/include/statistic.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/statistic/IDistribution.hpp>
/*==========================================================================*/
#ifndef __IDISTRIBUTION_CPP__
#define __IDISTRIBUTION_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tbool IDistribution::set(const IDistribution& a_crInstance)
{ CALL
  // Check if the given interface instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same IDistribution interface instance."))
  {
    return false;
  }

  return setRandomGenerator(a_crInstance.m_IsLocalGenerator ? NULL : a_crInstance.m_pRandomGenerator);
}
/*--------------------------------------------------------------------------*/
Tbool IDistribution::setRandomGenerator(NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */)
{ CALL
  // Clear the current random number generator.
  clear();

  m_IsLocalGenerator = false;
  if (a_pIRandomGenerator != NULL)
  {
    // Copy pointer of the random number generator instance.
    m_pRandomGenerator = a_pIRandomGenerator;
    return true;
  }
  else
  {
    // Create instance of the default random number generator.
    m_pRandomGenerator = newex NRandom::CRandomGenerator();
    if (m_pRandomGenerator == NULL)
    {
      WARNING(STR("Cannot create new default random number generator instance (requested size is %u bytes).") COMMA sizeof(NRandom::CRandomGenerator));
      return false;
    }
    m_IsLocalGenerator = true;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
Treal IDistribution::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  return getRandomGeneratorRef().randomReal();
}
/*--------------------------------------------------------------------------*/
void IDistribution::clear()
{ CALL
  // If current random number generator is local, then delete it.
  if (isValidGenerator() && m_IsLocalGenerator)
  {
    delete m_pRandomGenerator;
    m_pRandomGenerator = NULL;
    m_IsLocalGenerator = false;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
