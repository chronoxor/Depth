/*!
 *  \file    IDistribution.hpp Interface for all statistical distributions.
 *  \brief   Statistical distribution interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Statistical distribution interface.

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
#ifndef __IDISTRIBUTION_HPP__
#define __IDISTRIBUTION_HPP__
/*==========================================================================*/
#include <Depth/include/statistic.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/random/IRandomGenerator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Statistical distribution interface.
/*!
    Statistical distribution interface is used as a  base  interface  for  all
    distribution implementations.
*/
class STATISTIC_API IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef IDistribution TDepthCheckType;

  // Check IDistribution interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  /*!
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  IDistribution(NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IDistribution interface.
  */
  IDistribution(const IDistribution & a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IDistribution();

  //! Operator: Assign another IDistribution interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IDistribution interface.
      \return Reference to the current interface instance.
  */
  IDistribution& operator = (const IDistribution& a_crInstance);

  //! Set another IDistribution interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IDistribution interface.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const IDistribution& a_crInstance);

  //! Statistical distribution valid checking method.
  /*!
      Method checks  if  statistical  distribution  has  valid  random  number
      generator.

      \return true  - if statistical distribution is valid. \n
              false - if statistical distribution is not valid. \n
  */
  Tbool isValidGenerator() const;

  //! Get reference to the current random generator instance.
  /*!
      Method returns reference to the current random generator instance.  Note
      that result may be broken if random number generator is not initialized.
      So use 'isValidGenerator()' method before to check its valid state.

      \return Reference to the current random generator instance.
  */
  NRandom::IRandomGenerator& getRandomGeneratorRef();
  //! Get pointer to the current random generator instance.
  /*!
      Method returns pointer to the current random  generator  instance.  Note
      that result may be NULL if random number generator is  not  initialized.
      So use 'isValidGenerator()' method before to check its  valid  state  or
      use NULL checking strategy to define  random  number  generator  is  not
      initialized state alternatively.

      \return Pointer to the current random generator instance.
  */
  NRandom::IRandomGenerator* getRandomGeneratorPtr();

  //! Get constant reference to the current random generator instance.
  /*!
      Method returns  constant  reference  to  the  current  random  generator
      instance. Note that result may be broken if random number  generator  is
      not initialized. So use 'isValidGenerator()' method before to check  its
      valid state.

      \return Constant reference to the current random generator instance.
  */
  const NRandom::IRandomGenerator& getRandomGeneratorRef() const;
  //! Get constant pointer to the current random generator instance.
  /*!
      Method  returns  constant  pointer  to  the  current  random   generator
      instance. Note that result may be NULL if random number generator is not
      initialized. So use 'isValidGenerator()'  method  before  to  check  its
      valid state or use  NULL  checking  strategy  to  define  random  number
      generator is not initialized state alternatively.

      \return Constant pointer to the current random generator instance.
  */
  const NRandom::IRandomGenerator* getRandomGeneratorPtr() const;

  //! Set new random number generator instance.
  /*!
      If the pointer to the new random number generator instance is NULL, then
      an instance of the default random number generator will be created.

      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
      \return true  - if new random number generator instance was successfully set. \n
              false - if new random number generator instance was not successfully set. \n
  */
  Tbool setRandomGenerator(NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);

  //! Get new generated real random number.
  /*!
      The method generates new random value  which  is  distributed  with  the
      given distribution. Default implementation of the method returns uniform
      distributed random value in the [0.0, 1.0] interval.

      \return Distributed real random value.
  */
  virtual Treal randomReal();

  //! Serialization load IDistribution interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save IDistribution interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize IDistribution interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IDistribution interface instances.
  /*!
      \param a_rInstance - Reference to another IDistribution interface instance.
  */
  void swap(IDistribution& a_rInstance);

private:
  Tbool m_IsLocalGenerator;                      //!< Is random number generator is local and need to be deleted in destructor?
  NRandom::IRandomGenerator* m_pRandomGenerator; //!< Pointer to the current random number generator.

  //! Clear the current random number generator.
  void clear();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/IDistribution.inl>
/*==========================================================================*/
#endif
