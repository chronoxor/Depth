/*-----------------------------------------------------------------------------*\
| class MpBitArray include file                                    mpbitarray.h |
|                                                                               |
| Last change: Oct 8, 2006                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2006 by Berndt M. Gammel. All rights reserved.             |
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

// avoid multiple inclusion
#ifndef _MPBITARR_H_
#define _MPBITARR_H_

#include "common.h"     // common definitions and machine dependencies

// include STL definitions
#include <iostream>

namespace MATPACK {

//----------------------------------------------------------------------------//
// class MpBitArray
// The class 'BitArray' supplies one-dimensional, two-dimensional and
// three-dimensional arrays of the element type bit. That means each element
// can either be '0' or '1'. This class is designed for optimal storage
// efficiency and speed. One bit per element is used. Index range checking
// for debugging purposes can be switched on optionally.
//----------------------------------------------------------------------------//

class MpBitArray 
{
  private:
    static const unsigned char MpBitArray_bits[8], MpBitArray_notbits[8];
    unsigned char *arr;
    int dim,d1,d2,d3,elem,size,form;

  public:

    //------------------------------------------------------------------------//
    //  CONSTRUCTORS: 
    //  Define an array of bits which is organized either as a
    //  one-dimensional or two-dimensional or three-dimensional array. The
    //  index range in each dimension is 0 to dimN-1 (the usual C convention).
    //  Initially all bits are set to 0. If a bit array is defined without
    //  argument then the array is empty. It can be allocated later in an
    //  assignment or input operation.
    //------------------------------------------------------------------------//
    MpBitArray (void);
    MpBitArray (int dim1);
    MpBitArray (int dim1, int dim2);
    MpBitArray (int dim1, int dim2, int dim3);

    //------------------------------------------------------------------------//
    //  COPY CONSTRUCTOR: 
    //  Creates an exact copy of the given bit array.
    //------------------------------------------------------------------------//
    MpBitArray (const MpBitArray& src);

    //------------------------------------------------------------------------//
    //  DESTRUCTOR: 
    //  Removes the dynamic memory parts of the bit arrary.
    //  Usually the destructor isn't called explicitly.
    //------------------------------------------------------------------------//
    ~MpBitArray (void);
 
    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Assigns the contents of the given bit array to
    //  this bit array. If the arrays are not conformant, i.e. if not all
    //  dimensions are matching, then the error handler function
    //  'void Matpack::Error(...)' is called.
    //------------------------------------------------------------------------//
    MpBitArray& operator =  (const MpBitArray& src); // assign conformant array

    
    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //   Assigns the contents of the given bit array to
    //  this bit array. If the arrays are conformant the operation is equal
    //  to the assignment operation '=' described above. If the arrays are
    //  not conformant the bit array on the left hand side is resized
    //  correspondingly.
    //------------------------------------------------------------------------//
    MpBitArray& operator << (const MpBitArray& src); // assign with automatic resizing

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  ANDs, ORs, XORs the given bit array 'src' on the
    //  right hand side of the expression with the bit array on the left hand
    //  side and assigns the result to this array.
    //------------------------------------------------------------------------//
    MpBitArray& operator &= (const MpBitArray& src); // assign and-ing
    MpBitArray& operator |= (const MpBitArray& src); // assign or-ing
    MpBitArray& operator ^= (const MpBitArray& src); // assign xor-ing

    //------------------------------------------------------------------------//
    //  FRIEND FUNCTIONS:
    //  Compare all elements of two bit arrays. The
    //  equivalence operator '==' ('!=') returns true (false) if all
    //  elements of the arrays are equal, otherwise false (true).
    //------------------------------------------------------------------------//
    friend bool operator == (const MpBitArray& arr1, const MpBitArray& arr2);
    friend bool operator != (const MpBitArray& arr1, const MpBitArray& arr2);

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  De-allocates the bitarray. Then the bit array 
    //  is empty as if it was initialized using "BitArray (void);"
    //------------------------------------------------------------------------//
    void Remove (void) { this->MpBitArray::~MpBitArray(); }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Returns the dimension of the bit array which is
    //  either 0, 1, 2 or 3. If an empty bit array (without dimension) is
    //  defined, then 0 is returned.
    //------------------------------------------------------------------------//
    int Dim  (void) const { return dim; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Returns the size of the first, second or third
    //  dimension of the bit array respectively. Zero is returned for the
    //  dimension size of an array which is of lower dimension than the
    //  requested dimension (e.g. Dim2 and Dim3 for a one-dimensional array).
    //------------------------------------------------------------------------//
    int Dim1 (void) const { return d1; } 
    int Dim2 (void) const { return d2; }
    int Dim3 (void) const { return d3; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION:  
    //  If the bit array is empty (dimension = 0) 
    //  then true is returned, false otherwise.
    //------------------------------------------------------------------------//
    bool Empty (void) const { return dim == 0; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION:  
    //  Return the number of elements (bits) in the array
    //------------------------------------------------------------------------//
    int Elements (void) const { return elem; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION:  
    //  Returns the current I/O format of the BitArray.
    //------------------------------------------------------------------------//
    int Format (void) const { return form; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Defines the I/O format of the bit array. Initially it is set 
    //  to 'MpTextFormat'. Possible values are the predefined enums:
    //
    //    MpTextFormat      readable text format with dimension information
    //    MpBinaryFormat    binary format with dimension information
    // 
    //  which can be combined with the flag
    // 
    //    MpNoHeaderFormat  don't print header (descriptor) of arrays
    //
    //  e.g.
    //    'MpTextFormat|MpNoHeaderFormat' suppresses the printing of the
    //    format information (which is needed e.g. for reading a bit array
    //    using the stream input operator '>>'.
    //
    //  Note: The binary format is more compact (by a factor of 8) and writing
    //  is performed much faster en block (upto a factor of 20 to 40).
    //------------------------------------------------------------------------//
    MpBitArray& Format (int format) { form = format; return *this; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Returns a pointer to the data field which is an
    //  array of 'unsigned char'. This direct access method to the data
    //  field should only be used in exception cases, for instance when
    //  index access to the elements would be highly inappropriate or
    //  inefficient. Be aware that the way the elements are stored may
    //  be implementation dependent and that the result on different
    //  architectures or in future implementations may change! 
    //  A NULL-pointer is returned if the dimension Dim() is zero.
    //------------------------------------------------------------------------//
    const unsigned char* Store (void) const { return arr; }
    unsigned char* Store (void) { return arr; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Returns the memory size of the allocated data field
    //  neccessary to hold the bit array in units of bytes.
    //------------------------------------------------------------------------//
    int Size (void) const { return size; }

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Set whole array to ones (1111...1)
    //------------------------------------------------------------------------//
    void Set(void);

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Clear whole array to zeros (0000...0)
    //------------------------------------------------------------------------//
    void Clear(void);

    //------------------------------------------------------------------------//
    //  FRIEND FUNCTION:
    //  Read a bit array from a stream. If the destination bit  array is 
    //  not empty, i.e. has its dimensions defined, 
    //  then the bit array read from the stream must be conformant. 
    //  Otherwise an error will occur.
    //  If the destination bit array is empty it will get the dimensions of
    //  the bit array read. Thus you have to call 
    //  'Bitarray::Remove()' before you want to read an array with
    //  different dimensions into the destination bit array.  
    //------------------------------------------------------------------------//
    friend std::istream& operator >> (std::istream& os, MpBitArray& dst);

    //------------------------------------------------------------------------//
    //  FRIEND FUNCTION:
    //  Write a bit array to a stream using the selected
    //  format, see 'BitArray& Format (int format)' for a description.
    //------------------------------------------------------------------------//
    friend std::ostream& operator << (std::ostream& os, const MpBitArray& src);


// define index range checking macros
#if defined(DEBUG) || defined (IndexRangeChecking) || defined (MpBitArrayIndexRangeChecking)
#define _INDEX_CHECK_1D_(FCN) \
        if (dim!=1 || i1<0 || i1>=d1) \
          Matpack.Error("MpBitArray::"FCN": index out of range ");
#define _INDEX_CHECK_2D_(FCN) \
        if (dim!=2 || i1<0 || i1>=d1 || i2<0 || i2>=d2) \
            Matpack.Error("MpBitArray::"FCN": index out of range");
#define _INDEX_CHECK_3D_(FCN) \
        if (dim!=3 || i1<0 || i1>=d1 || i2<0 || i2>=d2 || i3<0 || i3>=d3) \
            Matpack.Error("MpBitArray::"FCN": index out of range ");
#else
#define _INDEX_CHECK_1D_(FCN)
#define _INDEX_CHECK_2D_(FCN)
#define _INDEX_CHECK_3D_(FCN)
#endif

    //------------------------------------------------------------------------//
    //  MEMBER FUNCTION: 
    //  Set, clear or get individual bits which are
    //  addressed by their index. Depending on the dimension of the array
    //  either a single index, an index doublet or an index triplet is
    //  expected. 'Set' means setting to 1, 'clear' means setting to 0.
    //
    //  To get the value of of a bit use either te member function Get() or
    //  just the parenthesis index operator, e.g.
    // 
    //      'if ( B(i,j,k) ) ...'  
    //
    //  is synonymous to  
    //
    //       'if ( B.Get(i,j,k) ) ...'
    //
    //  Zero is returned if the bit is not set. One is returned if the
    //  bit is set. Remember that you cannot write 'B(i,i,k) = 1' or 
    //  'B(i,j,k) = 0'. Instead you have to write 'B.Set(i,j,k)' or 
    //  'B.Clear(i,j,k)'.
    //
    //  If you put 
    //       '#define IndexRangeChecking' 
    //   or
    //       '#define MpBitArrayIndexRangeChecking' 
    //   before the line
    //       '#include "bitarr.h"' 
    //   which includes the definitions for the class 'MpBitArray' then 
    //   index range checking will be switched on.
    //   Index range checking is also performed if "DEBUG" is defined.
    //   In the case of an index out of range the error handler function
    //   'void Matpack::Error(...)' is called. 
    //   Typically this function should exit the program and print 
    //   the error message.
    //------------------------------------------------------------------------//
    void Set (int i1) {
        _INDEX_CHECK_1D_("Set")
        arr[i1 >> 3] |= MpBitArray_bits[i1 & 0x07];
    }

    void Clear (int i1) {
        _INDEX_CHECK_1D_("Clear")
        arr[i1 >> 3] &= MpBitArray_notbits[i1 & 0x07];
    }

    int Get (int i1) const {
        _INDEX_CHECK_1D_("Get")
        return (arr[i1 >> 3] & MpBitArray_bits[i1 & 0x07]) != 0;
    }
    
    int operator () (int i1) const {
        _INDEX_CHECK_1D_("operator()")
        return (arr[i1 >> 3] & MpBitArray_bits[i1 & 0x07]) != 0;
    }

    void Set (int i1, int i2) {
        _INDEX_CHECK_2D_("Set")
        int h = i1*d2+i2; 
        arr[h >> 3] |= MpBitArray_bits[h & 0x07];
    }

    void Clear (int i1, int i2) {
        _INDEX_CHECK_2D_("Clear")
        int h = i1*d2+i2; 
        arr[h >> 3] &= MpBitArray_notbits[h & 0x07];
    }

    int Get (int i1, int i2) const {
        _INDEX_CHECK_2D_("Get")
        int h = i1*d2+i2; 
        return (arr[h >> 3] & MpBitArray_bits[h & 0x07]) != 0;
    }

    int operator () (int i1, int i2) const {
        _INDEX_CHECK_2D_("operator ()")
        int h = i1*d2+i2; 
        return (arr[h >> 3] & MpBitArray_bits[h & 0x07]) != 0;
    }

    void Set (int i1, int i2, int i3) {
        _INDEX_CHECK_3D_("Set")
        int h = (i1*d2+i2)*d3+i3; 
        arr[h >> 3] |= MpBitArray_bits[h & 0x07];
    }

    void Clear (int i1, int i2, int i3) {
        _INDEX_CHECK_3D_("Clear")
        int h = (i1*d2+i2)*d3+i3; 
        arr[h >> 3] &= MpBitArray_notbits[h & 0x07];
    }

    int Get (int i1, int i2, int i3) const {
        _INDEX_CHECK_3D_("Get")
        int h = (i1*d2+i2)*d3+i3; 
        return (arr[h >> 3] & MpBitArray_bits[h & 0x07]) != 0;
    }

    int operator () (int i1, int i2, int i3) const {
        _INDEX_CHECK_3D_("operator ()")
        int h = (i1*d2+i2)*d3+i3; 
        return (arr[h >> 3] & MpBitArray_bits[h & 0x07]) != 0;
    }

// undefine local definitions
#undef _INDEX_CHECK_1D_
#undef _INDEX_CHECK_2D_
#undef _INDEX_CHECK_3D_
};

} // namespace MATPACK

#endif

//----------------------------------------------------------------------------//
