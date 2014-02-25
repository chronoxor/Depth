/*!
 *  \file    CSystemGeometry.hpp Geometry system class contains system
 *           dependant geometry functionality.
 *  \brief   Geometry system class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Geometry system class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   29.08.2008 20:49:41

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
#ifndef __CSYSTEMGEOMETRY_HPP__
#define __CSYSTEMGEOMETRY_HPP__
/*==========================================================================*/
#include <Depth/include/geometry.hpp>
#include <Depth/include/process/CRWLock.hpp>
#include <Depth/include/process/CScopeReader.hpp>
#include <Depth/include/process/CScopeWriter.hpp>
#include <Depth/include/shared/ISharedLibrary.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Geometry system class.
/*!
    Geometry system class contains system dependant geometry functionality.
*/
class GEOMETRY_API CSystemGeometry :
  public NDepth::NShared::ISharedLibrary
{
public:
  //! Is system installed?
  /*!
      \return true  - if system was installed. \n
              false - if system was not installed. \n
  */
  static Tbool isInstalled();

  /*------------------------------------------------------------------------*/
  /* INSLALL/UNINSTALL METHODS                                              */
  /*------------------------------------------------------------------------*/
  //! Install system.
  /*!
      \return true  - if system was successfully installed. \n
              false - if system was not successfully installed. \n
  */
  static Tbool install();
  //! Uninstall system.
  /*!
      \return true  - if system was successfully uninstalled. \n
              false - if system was not successfully uninstalled. \n
  */
  static Tbool uninstall();

private:
  static Tbool ms_InstallFlag;          //!< Is system installed?
  static NProcess::CRWLock ms_Locker;   //!< Shared library reader/writer locker.

  // ISharedLibrary interface overriding methods.
  virtual Tbool onLoad();
  virtual Tbool onUnload();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/system/CSystemGeometry.inl>
/*==========================================================================*/
#endif
