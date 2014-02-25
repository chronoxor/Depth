/*-----------------------------------------------------------------------------*\
| Fast Hartley Transform prototypes (FHT)                                 fht.h |
|                                                                               |
| Last change: Nov 29, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel. All rights reserved.             |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
| warranty.  In no event will the author be held liable for any damages arising |
| from the use of this software.                                                |
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.                                                    |
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.                       |
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration |
| and installation of Matpack.                                                  |
|                                                                               |
\*-----------------------------------------------------------------------------*/

#ifndef _FHT_H_
#define _FHT_H_

#include "common.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// Prototypes for 1-dimensional Fast Hartley Transform (FHT) and FFT routines 
// based upon the FHT.
//-----------------------------------------------------------------------------//

void fht          (double* fz, int n);
void fht_fft      (int n, double* real, double* imag);
void fht_ifft     (int n, double* real, double* imag);
void fht_realfft  (int n, double* real);
void fht_realifft (int n, double* real);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
