/*-----------------------------------------------------------------------------*\
| include file for Matpack class MpImageBase                      mpimagebase.h |
|                                                                               |
| Last change: Dec 17, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel. All rights reserved.             |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
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

// check for multiple inclusion
#ifndef _MPIMAGEBASE_H_
#define _MPIMAGEBASE_H_

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpImageBase
//
// Implements the basic image allocation and deallocation methods.
// Contains basic image data.
//-----------------------------------------------------------------------------//

template <class T>
class MpImageBase
{
  public:

    typedef T    ImageChannelT;	  // basic channel value type

  protected:

    int   MaxChannelValue;        // maximal value of channel type
    int   NumChannels;            // number of channels

    int   ImageWidth,		  // image width in pixel
          ImageLength,  	  // image length in pixel
	  ImageWidthX, 		  // image width times number of channels
          ImageWidthMM,   	  // image width in units of  1/1000 millimeter
          ImageLengthMM;  	  // image length in units of 1/1000 millimeter

    ImageChannelT *ImageData;     // pointer to data block

    float dpi;	                  // default real size s 150.0 dpi
    int PixToMM (int size) const { return Nint(1000.0 * size  * 24.5 / dpi); }

  public:

    MpImageBase (int channels, int maxval);
    MpImageBase (int channels, int maxval, int width, int length); 
    MpImageBase (const MpImageBase& source); 

    virtual ~MpImageBase (void);

    virtual void Remove (void) { this->MpImageBase<T>::~MpImageBase(); }
    virtual void Resize (int w, int l);

    operator int (void)   const { return (ImageData != (ImageChannelT*) 0); } 
    int operator ! (void) const { return (ImageData == (ImageChannelT*) 0); } 

    ImageChannelT* GetData  (void) { return ImageData; }
    ImageChannelT* GetData  (void) const { return ImageData; }
   
    int GetMaxChannelValue (void) const { return MaxChannelValue; }
    int GetNumChannels     (void) const { return NumChannels; }

    // get image size in units of pixels
    int GetWidth  (void) const { return ImageWidth; }
    int GetLength (void) const { return ImageLength; }

    // get and set image size in units of 1/1000 millimeter
    int GetWidthMM  (void) const { return ImageWidthMM; }
    int GetLengthMM (void) const { return ImageLengthMM; }
    void SetSizeMM (int wMM, int lMM) 
    { 
      ImageWidthMM = wMM; ImageLengthMM = lMM; 
    }
};


//----------------------------------------------------------------------------//
// MpImageBase::MpImageBase (int channels, int maxval) 
// This constructor defines an image but doesn't allocate it.
// 
//----------------------------------------------------------------------------//

template <class T>
inline MpImageBase<T>::MpImageBase (int channels, int maxval) 
  : MaxChannelValue(maxval), NumChannels(channels), dpi(150.0)
{ 
  ImageWidth    = 
  ImageLength   =  
  ImageWidthX   =
  ImageWidthMM  = 
  ImageLengthMM = 0;
  ImageData     = (ImageChannelT*)0;
} 
  

//----------------------------------------------------------------------------//
// MpImageBase::MpImageBase (int w, int l) 
//
// The constructor allocates memory for holding an image w pixel wide  
// (horizontal) and l pixel long (vertical)
// The image contents are undefined. 
//----------------------------------------------------------------------------// 

template <class T>
inline MpImageBase<T>::MpImageBase (int channels, int maxval, int w, int l) 
  : MaxChannelValue(maxval),NumChannels(channels), dpi(150.0)
{ 
  ImageWidth  = w; 
  ImageLength = l; 
  ImageWidthX = w * NumChannels; 

  if ( (w <= 0) || (l <= 0) || 
       ( ! (ImageData = new ImageChannelT [ImageWidthX * ImageLength]) ) )
    ImageWidth = ImageLength = ImageWidthX = 0; 

  ImageWidthMM  = PixToMM(ImageWidth);  // default real size in 1/1000 mm 
  ImageLengthMM = PixToMM(ImageLength);
} 


//----------------------------------------------------------------------------//
// MpImageBase::MpImageBase (const MpImageBase &im) 
//
// The copy constructor allocates memory for holding a copy of the 
// source image. 
//----------------------------------------------------------------------------//

template <class T>
inline MpImageBase<T>::MpImageBase (const MpImageBase &im) 
  : MaxChannelValue(im.MaxChannelValue), NumChannels(im.NumChannels), dpi(im.dpi)
{ 
  unsigned size = im.ImageWidthX * im.ImageLength; 

  if (size && im.ImageData && (ImageData = new ImageChannelT[size]) ) { 
    ImageWidth    = im.ImageWidth; 
    ImageLength   = im.ImageLength; 
    ImageWidthX   = im.ImageWidthX; 
    ImageWidthMM  = im.ImageWidthMM; 
    ImageLengthMM = im.ImageLengthMM; 
    memcpy( (void*)ImageData, (void*)im.ImageData,size*sizeof(ImageChannelT) );
  } else { // allocation failed or empty image
    ImageWidth = 
    ImageLength = 
    ImageWidthX = 
    ImageWidthMM = 
    ImageLengthMM = 0;
    ImageData     = (ImageChannelT*)0;
    return; 
  } 
} 
 

//----------------------------------------------------------------------------//
// void MpImageBase::Resize (int w, int l)
//
// Resets the size of the existing image to w pixel wide  
// (horizontal) and l pixel long (vertical).
// The previous image contents are destroyed.
// The new image contents are undefined. 
//----------------------------------------------------------------------------//

template <class T>
void MpImageBase<T>::Resize (int w, int l) 
{ 
  // remove image only if size is changed
  if (w != ImageWidth  || l != ImageLength) {

    this->MpImageBase<T>::~MpImageBase();

    // re-allocate with different size
    ImageWidthX = w * NumChannels; 
    
    if ( (w <= 0) || (l <= 0) || 
	 ( !(ImageData = new ImageChannelT [ImageWidthX * l]) ) )
      ImageWidth = ImageLength = ImageWidthX = 0; 
    
    // set scale as in original image
    ImageWidthMM  = ImageWidth  ? ((w*ImageWidthMM)  / ImageWidth)  : PixToMM(w);
    ImageLengthMM = ImageLength ? ((l*ImageLengthMM) / ImageLength) : PixToMM(l);
    ImageWidth  = w; 
    ImageLength = l; 
  } 
}


//----------------------------------------------------------------------------//
// MpImageBase::~MpImageBase (void) 
//
// The destructor frees the image memory. Normally you don't have to 
// call the destructor explicitely. 
//----------------------------------------------------------------------------//
     
template <class T>
MpImageBase<T>::~MpImageBase (void) 
{ 
  if (ImageData) { 
    delete [] ImageData; 
    ImageData = 0; 
    ImageWidth = 
    ImageLength = 
    ImageWidthX = 
    ImageWidthMM = 
    ImageLengthMM = 0; 
  } 
} 

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif

