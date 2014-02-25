/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface               mppalette.h |
|                                                                               |
| Include file for color selection window classes:                              |
|                                                                               |
|   class MpPalette                                                             |
|   class MpPaletteButton                                                       |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
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

#ifndef _MPPALETTE_H_
#define _MPPALETTE_H_

#include "mpimagwin.h"
#include "mpbutton.h"
#include "mphelpwin.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// The user interface classes are:
//
//  class MpPalette
//  class MpPaletteButton
//
//-----------------------------------------------------------------------------//

//-----------------------------------------------------------------------------//
// class MpPalette: user interface for color selection (window)
//-----------------------------------------------------------------------------//

class RGBEditWindow;
class HSVEditWindow;
class MpHueSaturationWindow;

class MpPalette: public MpCanvas 
{
  friend class MpHueSaturationWindow;
  friend class RGBEditWindow;
  friend class HSVEditWindow;
  friend void MpPaletteTextHook (void*);
  friend void MpPaletteImageHook (void*);
  friend void MpPaletteSetBrightness (void*);
  friend void MpPaletteRGBSliderHook (MpPalette&);
  friend void MpPaletteSetRed   (void* vptr);
  friend void MpPaletteSetGreen (void* vptr);
  friend void MpPaletteSetBlue  (void* vptr);

  protected :
    // window elements sizes and positions
    int HOff,VOff,              // horiz/vert offset
        PalSize,                // vert and horiz size of palette
        SliderW,SliderH,        // width/height of all sliders
        SliderDY,               // vert distance between sliders
        ColorSampleW,           // size of color sample
        ButtonW,ButtonH,        // width/height of all buttons
        HueSatX,HueSatY,        // hue-saturation color wheel           
        ColorSampleH,           // color sample
        ColorSampleX,ColorSampleY,
        BriSliderX,BriSliderY,  // HSV brightness slider
        RSliderX,RSliderY,      // RGB sliders
        GSliderX,GSliderY, 
        BSliderX,BSliderY,
        Rule1Y,Rule2Y,          // rules
        HsvEditX,HsvEditY,      // HSV numerical input
        HsvEditW,HsvEditH, 
        RgbEditX,RgbEditY,      // RGB numerical input
        RgbEditW,RgbEditH,
        OkX,OkY,                // user confirmation buttons
        HelpX,HelpY,
        CancelX,CancelY;
                
    ColorF **colorpp;
    MpImage color;
    MpHueSaturationWindow *HueSatWin;
    HSVEditWindow *hsv;
    RGBEditWindow *rgb;
    MpImageWindow *ColorSample;
    MpButton *accept_button, *cancel_button, *reset_button;
    MpHelpPopupButton *help_button;
    MpScrollbar *BriSlider, *RSlider, *GSlider, *BSlider; 

    // flags which are neccessary to avoid loops in callbacks
    int block_Bri, block_RGB; 
    void Scaling (int w, int h);

  public:
    virtual void Redraw (void);
    virtual void Resize (int,int) { }

    // virtual functions tied to Accept/Cancel functions can be overloaded
    virtual void Accept (void);
    virtual void Cancel (void);

    // constructor
    MpPalette (MpWindow &parent, ColorF **color,
               int w, int h, int x = 0, int y = 0);

    // setting new color
    void Set (ColorF **color);
    void Set (ColorF color);
};



//-----------------------------------------------------------------------------//

class MpAuxPalettePanel;
class MpPaletteButton: public MpButton 
{
  private: 
    MpAuxPalettePanel *popup;
    ColorF **color;
  protected:
    virtual void BClick_CB (XButtonEvent ev);

  public: 
    MpPaletteButton (MpWindow& parent, const char* label, ColorF **color,
                     int w, int h, int x = 0, int y = 0) 
      : MpButton(parent,label,w,h,x,y), popup(NULL), color(color) { }  

    virtual ~MpPaletteButton (void);
    
    void Set (ColorF **color);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
