/*-----------------------------------------------------------------------------*\
| Matpack random generator class                               ranlognormal.cpp |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its  entirety and its | 
| documentation for  non-commercial purpose and  without fee is hereby granted, | 
| provided that this license information and copyright notice appear unmodified | 
| in all copies. This software is provided 'as is'  without  express or implied | 
| warranty.  In no event will the author be held liable for any damages arising | 
| from the use of this software.						|
| Note that distributing Matpack 'bundled' in with any product is considered to | 
| be a 'commercial purpose'.							|
| The software may be modified for your own purposes, but modified versions may | 
| not be distributed without prior consent of the author.			|
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration	|
| and installation of Matpack.							|
|                                                                               |
\*-----------------------------------------------------------------------------*/

#include "mprandom.h"

namespace MATPACK {

//----------------------------------------------------------------------------//
// class LogNormalDistribution						      //
//----------------------------------------------------------------------------//
//								       	      //
// Return log-normal distributed random deviates			      //
// with given mean and standard deviation stdev				      //
// according to the density function:					      //
//                                                2			      //
//                     1                (ln x - m)			      //
// p   (x) dx =  -------------- exp( - ------------ ) dx  for x > 0	      //
//  m,s          sqrt(2 pi x) s               2				      //
//                                         2 s				      //
//			 						      //
//            = 0   otherwise						      //
//									      //
// where  m  and  s  are related to the arguments mean and stdev by:	      //
// 								       	      //
//                        2						      //
//                    mean						      //
// m = ln ( --------------------- )					      //
//                     2      2						      //
//          sqrt( stdev + mean  )					      //
// 									      //
//                     2      2						      //
//                stdev + mean						      //
// s = sqrt( ln( -------------- ) )					      //
//                        2						      //
//                    mean 						      // 
//								       	      //
//----------------------------------------------------------------------------//

void LogNormalDistribution :: Initialize (double mean, double stddev)
{
    // set mean and standard deviation of the log-normal distribution
    m_log = mean; 
    s_log = stddev; 
    
    // mean "m" and standard deviation "s" of the corresponding 
    // normal distribution wich is a base class of this class
    double m2 = m_log * m_log, 
	   s2 = s_log * s_log,
           sm2 = s2+m2;
    m = log( m2 / sqrt(sm2) );
    s = sqrt( log(sm2/m2) );
}

} // namespace MATPACK

//----------------------------------------------------------------------------//
