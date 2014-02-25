/*-----------------------------------------------------------------------------*\
| Matpack include file to link the standardized Fortran BLAS routines    blas.h |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1992-1995 by Berndt M. Gammel                                   |
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
| Berndt M. Gammel,                                                             |
| Physik Department                                                             |
| Technische Universitaet Muenchen                                              |
| James-Franck-Strasse                                                          |
| 85747 Garching, Germany                                                       |
|                                                                               |
\*-----------------------------------------------------------------------------*/

// avoid multiple inclusion
#ifndef _BLAS_H_
#define _BLAS_H_

// require complex template class library for complex<float> and complex <double>
#include <complex.h>

//-----------------------------------------------------------------------------//

extern "C"
{
    //-------------------------------------------------------------------------//
    // BLAS Level 1
    //-------------------------------------------------------------------------//

    // float versions
    // --------------


    // double versions 
    // ---------------

    doubleT F77NAME(dasum)(const intT *n, const doubleT *dx, const intT *incx);
    

    void F77NAME(daxpy)(const intT *n, const doubleT *da, const doubleT *dx, 
			const intT *incx, doubleT *dy, const intT *incy);
    
    void F77NAME(dcopy)(const intT *n, doubleT *dx, const intT *incx, 
			doubleT *dy, const intT *incy);

    doubleT F77NAME(ddot)(const intT *n, const doubleT *dx, const intT *incx, 
                        const doubleT *dy, const intT *incy);

    doubleT F77NAME(dnrm2)(const intT *n, const doubleT *dx, const intT *incx); 

    void F77NAME(drot)(const intT *n, doubleT *dx, const intT *incx, 
		       doubleT *dy, const intT *incy, const doubleT *c, 
		       const doubleT *s);

    void F77NAME(drotg)(doubleT *da, doubleT *db, doubleT *c, doubleT *s);

    void F77NAME(dscal)(const intT *n, doubleT *da, doubleT *dx, 
			const intT *incx);

    void F77NAME(dswap)(const intT *n, doubleT *dx, const intT *incx, 
			doubleT *dy, const intT *incy);

    intT F77NAME(idamax)(const intT *n, const doubleT *dx, 
			    const intT *incx);

    // complex

    doubleT F77NAME(zdotc)(dcomplexT *c, const intT *n, 
            const dcomplexT *cx, 
            const intT *incx, const dcomplexT *cy, const intT *incy);

    doubleT F77NAME(zdotu)(dcomplexT *c, const intT *n, 
        const dcomplexT *cx, const intT *incx, 
        const dcomplexT *cy, const intT *incy);

    void F77NAME(zaxpy)(const intT *n, const dcomplexT *da, 
            const dcomplexT *dx, 
            const intT *incx, dcomplexT *dy, 
            const intT *incy);

    void F77NAME(zcopy)(const intT *n, dcomplexT *dx, const intT *incx, 
                dcomplexT *dy, const intT *incy);

    doubleT  F77NAME(dzasum)(const intT *n, const dcomplexT *dx, const intT *incx);

    doubleT  F77NAME(dznrm2)(const intT *n, const dcomplexT *dx, const intT *incx); 

    void F77NAME(zdscal)(const intT *n, const doubleT *da, dcomplexT *dx, 
            const intT *incx);

    void F77NAME(zscal)(const intT *n, const dcomplexT *da, dcomplexT *dx, 
            const intT *incx);

    intT F77NAME(izamax)(const intT *n, const dcomplexT *dx, const intT *incx);

    void F77NAME(zswap)(const intT *n, dcomplexT *dx, const intT *incx, 
			dcomplexT *dy, intT *incy);

    // complex<float> versions
    // -----------------------
  
    // complex<double> versions
    // ------------------------
  

    //-------------------------------------------------------------------------//
    // BLAS Level 2
    //-------------------------------------------------------------------------//

    // float versions
    // --------------


    // double versions 
    // ---------------

    void F77NAME(dgemv)(charT* trans, intT* M, intT* N, doubleT* alpha, 
			const doubleT* A, intT* lda, const doubleT* dx, 
			intT* incx, doubleT* beta, doubleT* dy, intT* incy);

    void F77NAME(dgbmv)(charT* trans, intT* M, intT* N, intT* kl, 
			intT* ku, doubleT* alpha, const doubleT* A, intT* lda, 
			const doubleT* dx, intT* incx, doubleT* beta, 
			doubleT* dy, intT* incy);
    
    void F77NAME(dsymv)(charT* uplo, intT* N, doubleT* alpha, const doubleT* A, 
			intT* lda, const doubleT* dx, intT* incx, doubleT* beta,
			doubleT* dy, intT* incy);
    
    void F77NAME(dsbmv)(charT* uplo, intT* N, intT* k, doubleT* alpha, 
			const doubleT* A, intT* lda, const doubleT* dx, 
			intT* incx, doubleT* beta, doubleT* dy, intT* incy);
    
    void F77NAME(dspmv)(charT* uplo, intT* N, doubleT* alpha, doubleT* AP, 
			doubleT* dx, intT* incx, doubleT* beta, doubleT* dy, 
			intT* incy);
    
    void F77NAME(dtrmv)(charT* uplo, charT* trans, charT* diag, const intT* N, 
			const doubleT* A, intT* lda, const doubleT* dx, 
			intT* incx);
    
    // currently not implemented.
    //F77NAME(dtbmv) ( UPLO, TRANS, DIAG, N, K, A, LDA, dx, INCX )
    
    void F77NAME(dtrsv)(charT* uplo, charT* trans, charT* diag, const intT* N, 
			doubleT* A, intT* lda, doubleT* dx, intT* incx);
    
    // currently not implemented.
    //F77NAME(dtbsv) ( UPLO, TRANS, DIAG, N, K, A, LDA, X, INCX )
    
    // currently not implemented.
    //F77NAME(dtpsv) ( UPLO, TRANS, DIAG, N, AP, X, INCX )
    
    void F77NAME(dger)(intT* M, intT* N, doubleT* alpha, 
		       doubleT* dx, intT* incx, doubleT* dy, intT* incy, 
		       doubleT* A, intT* lda);
    
    void F77NAME(dsyr)(charT* uplo, intT* N, doubleT* alpha, doubleT* dx, 
		       intT* incx, doubleT* A, intT* lda);
    
    void F77NAME(dspr)(charT* uplo, intT* N, doubleT* alpha, doubleT* dx, 
		       intT* incx, doubleT* AP);
    
    void F77NAME(dsyr2)(charT* uplo, intT* N, doubleT* alpha, doubleT* dx, 
			intT* incx, doubleT* dy, intT* incy, doubleT* A, 
			intT* lda);
    
    void F77NAME(dspr2)(charT* uplo, intT* N, doubleT* alpha, doubleT* dx, 
			intT* incx, doubleT* dy, intT* incy, doubleT* AP);

    // complex<float> versions
    // -----------------------
  
    // complex<double> versions
    // ------------------------
  

    //-------------------------------------------------------------------------//
    // BLAS Level 3
    //-------------------------------------------------------------------------//

    // float versions
    // --------------

    void F77NAME(sgemm)(charT *transa, charT *transb, intT *m, intT *n, intT *k,
			floatT *alpha, const floatT *a, intT *lda, 
			const floatT *b, intT *ldb, floatT *beta, floatT *c, 
			intT *ldc);
    
    void F77NAME(strsm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, floatT *alpha, const floatT *A, 
			intT *lda, const floatT *B, intT *ldb);
    
    void F77NAME(strmm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, floatT *alpha, const floatT *A, 
			intT *lda, const floatT *B, intT *ldb);
    
    void F77NAME(ssymm)(charT *side, charT *uplo, intT *m, intT *n, 
			floatT *alpha, const floatT *A, intT *lda, 
			const floatT *B, intT *ldb, floatT *beta, 
			floatT *C, intT *ldc);
    
    void F77NAME(ssyrk)(charT *uplo, charT *transa, intT *n, intT *k, 
			floatT *alpha, floatT *A, intT *lda, floatT *beta, 
			floatT *C, intT *ldc);
    
    void F77NAME(ssyr2k)(charT *uplo, charT *transa, intT *n, intT *k, 
			 floatT *alpha, floatT *A, intT *lda, floatT *B, 
			 intT *ldb, floatT *beta, floatT *C, intT *ldc);

    // double versions
    // ---------------

    void F77NAME(dgemm)(charT *transa, charT *transb, intT *m, intT *n, intT *k,
			doubleT *alpha, const doubleT *a, intT *lda, 
			const doubleT *b, intT *ldb, doubleT *beta, doubleT *c, 
			intT *ldc);
    
    void F77NAME(dtrsm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, doubleT *alpha, const doubleT *A, 
			intT *lda, const doubleT *B, intT *ldb);
    
    void F77NAME(dtrmm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, doubleT *alpha, const doubleT *A, 
			intT *lda, const doubleT *B, intT *ldb);
    
    void F77NAME(dsymm)(charT *side, charT *uplo, intT *m, intT *n, 
			doubleT *alpha, const doubleT *A, intT *lda, 
			const doubleT *B, intT *ldb, doubleT *beta, 
			doubleT *C, intT *ldc);
    
    void F77NAME(dsyrk)(charT *uplo, charT *transa, intT *n, intT *k, 
			doubleT *alpha, doubleT *A, intT *lda, doubleT *beta, 
			doubleT *C, intT *ldc);
    
    void F77NAME(dsyr2k)(charT *uplo, charT *transa, intT *n, intT *k, 
			 doubleT *alpha, doubleT *A, intT *lda, doubleT *B, 
			 intT *ldb, doubleT *beta, doubleT *C, intT *ldc);

    // complex<float> versions
    // -----------------------
  
    void F77NAME(cgemm)(charT *transa, charT *transb, intT *m, intT *n, intT *k,
			fcomplexT *alpha, const fcomplexT *a, intT *lda, 
			const fcomplexT *b, intT *ldb, fcomplexT *beta, 
			fcomplexT *c, intT *ldc);
    
    void F77NAME(ctrsm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, fcomplexT *alpha, const fcomplexT *A, 
			intT *lda, const fcomplexT *B, intT *ldb);
    
    void F77NAME(ctrmm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, fcomplexT *alpha, const fcomplexT *A, 
			intT *lda, const fcomplexT *B, intT *ldb);
   
    void F77NAME(csymm)(charT *side, charT *uplo, intT *m, intT *n, 
			fcomplexT *alpha, const fcomplexT *A, intT *lda, 
			const fcomplexT *B, intT *ldb, fcomplexT *beta, 
			fcomplexT *C, intT *ldc);
    
    void F77NAME(chemm)(charT *side, charT *uplo, intT *m, intT *n, 
			fcomplexT *alpha, const fcomplexT *A, intT *lda, 
			const fcomplexT *B, intT *ldb, fcomplexT *beta, 
			fcomplexT *C, intT *ldc);
     
    void F77NAME(csyrk)(charT *uplo, charT *transa, intT *n, intT *k, 
			fcomplexT *alpha, fcomplexT *A, intT *lda, fcomplexT *beta, 
			fcomplexT *C, intT *ldc);
    
    void F77NAME(csyr2k)(charT *uplo, charT *transa, intT *n, intT *k, 
			 fcomplexT *alpha, fcomplexT *A, intT *lda, fcomplexT *B, 
			 intT *ldb, fcomplexT *beta, fcomplexT *C, intT *ldc);

    // complex<double> versions
    // ------------------------

    void F77NAME(zgemm)(charT *transa, charT *transb, intT *m, intT *n, intT *k,
			dcomplexT *alpha, const dcomplexT *a, intT *lda, 
			const dcomplexT *b, intT *ldb, dcomplexT *beta, 
			dcomplexT *c, intT *ldc);
    
    void F77NAME(ztrsm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, dcomplexT *alpha, const dcomplexT *A, 
			intT *lda, const dcomplexT *B, intT *ldb);
    
    void F77NAME(ztrmm)(charT *side, charT *uplo, charT *transa, charT *diag,
			intT *m, intT *n, dcomplexT *alpha, const dcomplexT *A, 
			intT *lda, const dcomplexT *B, intT *ldb);
   
    void F77NAME(zsymm)(charT *side, charT *uplo, intT *m, intT *n, 
			dcomplexT *alpha, const dcomplexT *A, intT *lda, 
			const dcomplexT *B, intT *ldb, dcomplexT *beta, 
			dcomplexT *C, intT *ldc);
    
    void F77NAME(zhemm)(charT *side, charT *uplo, intT *m, intT *n, 
			dcomplexT *alpha, const dcomplexT *A, intT *lda, 
			const dcomplexT *B, intT *ldb, dcomplexT *beta, 
			dcomplexT *C, intT *ldc);
     
    void F77NAME(zsyrk)(charT *uplo, charT *transa, intT *n, intT *k, 
			dcomplexT *alpha, dcomplexT *A, intT *lda, dcomplexT *beta, 
			dcomplexT *C, intT *ldc);
    
    void F77NAME(zsyr2k)(charT *uplo, charT *transa, intT *n, intT *k, 
			 dcomplexT *alpha, dcomplexT *A, intT *lda, dcomplexT *B, 
			 intT *ldb, dcomplexT *beta, dcomplexT *C, intT *ldc);

    // c/zherk, c/zher2k still missing
}

//-----------------------------------------------------------------------------//

#endif

