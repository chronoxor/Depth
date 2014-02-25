/*!
 *  \file    example-algorithms-AHash.cpp Example of using the hash 
 *           algorithms.
 *  \brief   Example of using the hash algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the hash algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   10.03.2007 20:54:27

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

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
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/hash/CHashBOB.hpp>
#include <Depth/include/algorithms/hash/CHashDJB2.hpp>
#include <Depth/include/algorithms/hash/CHashDJB2Ex.hpp>
#include <Depth/include/algorithms/hash/CHashELF.hpp>
#include <Depth/include/algorithms/hash/CHashETH.hpp>
#include <Depth/include/algorithms/hash/CHashGCCcc1.hpp>
#include <Depth/include/algorithms/hash/CHashGCCcpp.hpp>
#include <Depth/include/algorithms/hash/CHashKR.hpp>
#include <Depth/include/algorithms/hash/CHashONEAT.hpp>
#include <Depth/include/algorithms/hash/CHashPCC.hpp>
#include <Depth/include/algorithms/hash/CHashPhong.hpp>
#include <Depth/include/algorithms/hash/CHashSDBM.hpp>
#include <Depth/include/algorithms/hash/CHashTorek.hpp>
#include <Depth/include/algorithms/hash/CHashTorekEx.hpp>
#include <Depth/include/algorithms/hash/CHashWAIS.hpp>
#include <Depth/include/algorithms/hash/CHashWeinberger.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NHash;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    Tschar string[] = ASC("Hello world!");

    CHashBOB hashBOB;
    stdoutput << STR("CHashBOB(\"Hello world!\") = ") << hex << upper << hash(hashBOB, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashDJB2 hashDJB2;
    stdoutput << STR("CHashDJB2(\"Hello world!\") = ") << hex << upper << hash(hashDJB2, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashDJB2Ex hashDJB2Ex;
    stdoutput << STR("CHashDJB2Ex(\"Hello world!\") = ") << hex << upper << hash(hashDJB2Ex, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashELF hashELF;
    stdoutput << STR("CHashELF(\"Hello world!\") = ") << hex << upper << hash(hashELF, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashETH hashETH;
    stdoutput << STR("CHashETH(\"Hello world!\") = ") << hex << upper << hash(hashETH, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashGCCcc1 hashGCCcc1;
    stdoutput << STR("CHashGCCcc1(\"Hello world!\") = ") << hex << upper << hash(hashGCCcc1, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashGCCcpp hashGCCcpp;
    stdoutput << STR("CHashGCCcpp(\"Hello world!\") = ") << hex << upper << hash(hashGCCcpp, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashKR hashKR;
    stdoutput << STR("CHashKR(\"Hello world!\") = ") << hex << upper << hash(hashKR, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashONEAT hashONEAT;
    stdoutput << STR("CHashONEAT(\"Hello world!\") = ") << hex << upper << hash(hashONEAT, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashPCC hashPCC;
    stdoutput << STR("CHashPCC(\"Hello world!\") = ") << hex << upper << hash(hashPCC, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashPhong hashPhong;
    stdoutput << STR("CHashPhong(\"Hello world!\") = ") << hex << upper << hash(hashPhong, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashSDBM hashSDBM;
    stdoutput << STR("CHashSDBM(\"Hello world!\") = ") << hex << upper << hash(hashSDBM, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashTorek hashTorek;
    stdoutput << STR("CHashTorek(\"Hello world!\") = ") << hex << upper << hash(hashTorek, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashTorekEx hashTorekEx;
    stdoutput << STR("CHashTorekEx(\"Hello world!\") = ") << hex << upper << hash(hashTorekEx, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashWAIS hashWAIS;
    stdoutput << STR("CHashWAIS(\"Hello world!\") = ") << hex << upper << hash(hashWAIS, (Tcbuffer)string, (sizeof(string) - 1)) << ln;
    CHashWeinberger hashWeinberger;
    stdoutput << STR("CHashWeinberger(\"Hello world!\") = ") << hex << upper << hash(hashWeinberger, (Tcbuffer)string, (sizeof(string) - 1)) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Method hashes string buffer using the given hash algorithm and returns the hash value.
  Tuint hash(IHash& a_rHash, Tcbuffer a_cpBuffer, const Tuint a_cSize)
  { CALL
    a_rHash.initialize();
    a_rHash.hash(a_cpBuffer, a_cSize);
    a_rHash.close();
    return a_rHash.getHash();
  }
} the_Application;
/*==========================================================================*/
