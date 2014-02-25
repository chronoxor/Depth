/*!
 *  \file    CBinaryProperties.cpp Character binary properties constants.
 *  \brief   Character binary properties constants (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character binary properties constants (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 20:48:08

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/UCD/CBinaryProperties.hpp>
/*==========================================================================*/
#ifndef __CBINARYPROPERTIES_CPP__
#define __CBINARYPROPERTIES_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NUCD {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API const Tuint64 CBinaryProperties::None          = CONSTU64(0x0000000000000000);
BASE_API const Tuint64 CBinaryProperties::AHex          = CONSTU64(0x0000000000000001);
BASE_API const Tuint64 CBinaryProperties::Alpha         = CONSTU64(0x0000000000000002);
BASE_API const Tuint64 CBinaryProperties::Bidi_C        = CONSTU64(0x0000000000000004);
BASE_API const Tuint64 CBinaryProperties::Bidi_M        = CONSTU64(0x0000000000000008);
BASE_API const Tuint64 CBinaryProperties::Cased         = CONSTU64(0x0000000000000010);
BASE_API const Tuint64 CBinaryProperties::CaseIgnorable = CONSTU64(0x0000000000000020);
BASE_API const Tuint64 CBinaryProperties::CWLower       = CONSTU64(0x0000000000000040);
BASE_API const Tuint64 CBinaryProperties::CWUpper       = CONSTU64(0x0000000000000080);
BASE_API const Tuint64 CBinaryProperties::CWTitle       = CONSTU64(0x0000000000000100);
BASE_API const Tuint64 CBinaryProperties::CWCasefold    = CONSTU64(0x0000000000000200);
BASE_API const Tuint64 CBinaryProperties::CWCasemap     = CONSTU64(0x0000000000000400);
BASE_API const Tuint64 CBinaryProperties::Dash          = CONSTU64(0x0000000000000800);
BASE_API const Tuint64 CBinaryProperties::Dep           = CONSTU64(0x0000000000001000);
BASE_API const Tuint64 CBinaryProperties::DI            = CONSTU64(0x0000000000002000);
BASE_API const Tuint64 CBinaryProperties::Dia           = CONSTU64(0x0000000000004000);
BASE_API const Tuint64 CBinaryProperties::Ext           = CONSTU64(0x0000000000008000);
BASE_API const Tuint64 CBinaryProperties::Hex           = CONSTU64(0x0000000000010000);
BASE_API const Tuint64 CBinaryProperties::Hyphen        = CONSTU64(0x0000000000020000);
BASE_API const Tuint64 CBinaryProperties::Ideo          = CONSTU64(0x0000000000040000);
BASE_API const Tuint64 CBinaryProperties::IDSB          = CONSTU64(0x0000000000080000);
BASE_API const Tuint64 CBinaryProperties::IDST          = CONSTU64(0x0000000000100000);
BASE_API const Tuint64 CBinaryProperties::Join_C        = CONSTU64(0x0000000000200000);
BASE_API const Tuint64 CBinaryProperties::LOE           = CONSTU64(0x0000000000400000);
BASE_API const Tuint64 CBinaryProperties::Lower         = CONSTU64(0x0000000000800000);
BASE_API const Tuint64 CBinaryProperties::Math          = CONSTU64(0x0000000001000000);
BASE_API const Tuint64 CBinaryProperties::NChar         = CONSTU64(0x0000000002000000);
BASE_API const Tuint64 CBinaryProperties::OAlpha        = CONSTU64(0x0000000004000000);
BASE_API const Tuint64 CBinaryProperties::ODI           = CONSTU64(0x0000000008000000);
BASE_API const Tuint64 CBinaryProperties::OGr_Ext       = CONSTU64(0x0000000010000000);
BASE_API const Tuint64 CBinaryProperties::OIDC          = CONSTU64(0x0000000020000000);
BASE_API const Tuint64 CBinaryProperties::OIDS          = CONSTU64(0x0000000040000000);
BASE_API const Tuint64 CBinaryProperties::OLower        = CONSTU64(0x0000000080000000);
BASE_API const Tuint64 CBinaryProperties::OMath         = CONSTU64(0x0000000100000000);
BASE_API const Tuint64 CBinaryProperties::OUpper        = CONSTU64(0x0000000200000000);
BASE_API const Tuint64 CBinaryProperties::QMark         = CONSTU64(0x0000000400000000);
BASE_API const Tuint64 CBinaryProperties::Radical       = CONSTU64(0x0000000800000000);
BASE_API const Tuint64 CBinaryProperties::SD            = CONSTU64(0x0000001000000000);
BASE_API const Tuint64 CBinaryProperties::Term          = CONSTU64(0x0000002000000000);
BASE_API const Tuint64 CBinaryProperties::UIdeo         = CONSTU64(0x0000004000000000);
BASE_API const Tuint64 CBinaryProperties::Upper         = CONSTU64(0x0000008000000000);
BASE_API const Tuint64 CBinaryProperties::VS            = CONSTU64(0x0000010000000000);
BASE_API const Tuint64 CBinaryProperties::WSpace        = CONSTU64(0x0000020000000000);
BASE_API const Tuint64 CBinaryProperties::STerm         = CONSTU64(0x0000040000000000);
BASE_API const Tuint64 CBinaryProperties::Gr_Base       = CONSTU64(0x0000080000000000);
BASE_API const Tuint64 CBinaryProperties::Gr_Ext        = CONSTU64(0x0000100000000000);
BASE_API const Tuint64 CBinaryProperties::Gr_Link       = CONSTU64(0x0000200000000000);
BASE_API const Tuint64 CBinaryProperties::Pat_Syn       = CONSTU64(0x0000400000000000);
BASE_API const Tuint64 CBinaryProperties::Pat_WS        = CONSTU64(0x0000800000000000);
BASE_API const Tuint64 CBinaryProperties::IDC           = CONSTU64(0x0001000000000000);
BASE_API const Tuint64 CBinaryProperties::IDS           = CONSTU64(0x0002000000000000);
BASE_API const Tuint64 CBinaryProperties::XIDC          = CONSTU64(0x0004000000000000);
BASE_API const Tuint64 CBinaryProperties::XIDS          = CONSTU64(0x0008000000000000);
BASE_API const Tuint64 CBinaryProperties::CE            = CONSTU64(0x0010000000000000);
BASE_API const Tuint64 CBinaryProperties::Comp_Ex       = CONSTU64(0x0020000000000000);
BASE_API const Tuint64 CBinaryProperties::XO_NFC        = CONSTU64(0x0040000000000000);
BASE_API const Tuint64 CBinaryProperties::XO_NFD        = CONSTU64(0x0080000000000000);
BASE_API const Tuint64 CBinaryProperties::XO_NFKC       = CONSTU64(0x0100000000000000);
BASE_API const Tuint64 CBinaryProperties::XO_NFKD       = CONSTU64(0x0200000000000000);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
