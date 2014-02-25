/*-----------------------------------------------------------------------------*\
| Editor panel for colormaps					   mpcolscale.h |
|                                                                               |
| Last change: Jul 9, 2005                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its  entirety and its |
| documentation for  non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies. This software is provided 'as is'  without  express or implied |
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

#ifndef _MPCOLSCALE_H_
#define _MPCOLSCALE_H_

#include "mpbutton.h"
#include "mplineedit.h"
#include "mpimagwin.h"
#include "matpack.h"
#include "mphelpwin.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// The following user interface classes are defined here:
//
//  class MpColorScalePanel
//  class MpColorScaleButton
//
//-----------------------------------------------------------------------------//

//-----------------------------------------------------------------------------//
// Panel for parametric colorscale definition
//-----------------------------------------------------------------------------//

class MpNumex;
class ColorscaleDisplay;

class MpColorScalePanel: public MpFrame 
{
  friend class ColorscaleDisplay;
  private:
    int BO,imW,imH;
    MpLineEdit *rhsv_win,*ghsv_win,*bhsv_win, 
               *h0_win,*h1_win,*s0_win,*s1_win,*v0_win,*v1_win,
               *cmapsize_win;
    MpHelpPopupButton *Help;
    ColorMap *cmap;                     // pointer to colormap (external, not kept in class)
    MpImage *image;                     // instance of preview image
    MpNumex *Numex;                     // instance of expression parser
    float H0,H1,S0,S1,V0,V1;
    ColorscaleDisplay *display;         // image window with preview
    void Resize (int w, int h);         // currently panel has fixed dimension
    void Evaluate (void);               // callback for "Evaluate" button pressed
    void Reverse (void);                // reverse colormap
    void EditCmap (int pick_x, int x);  // callback for picking color in preview
    void Load (void);                   // call file dialog for loading
    void Save (void);                   // call file dialog for saving
    void Close (void);                  // unmap panel

  public:
    MpColorScalePanel (const char *title, ColorMap *cmap);
    virtual ~MpColorScalePanel();

    // Set the panel string entries for hue, saturation, and value
    // as well as the floating point entries for the ranges for the
    // hue (h0,h1), satuation (s0,s1), and value (v0,v1) variables.
    // The size of the colormap is given by ncolors.
    // Then evaluate the formulas to generate the new colormap.
    void Set (const string &hue, const string &sat, const string &val,
	      float h0, float h1, float s0, float s1, float v0, float v1,
	      int ncolors);

    void Get (string &hue, string &sat, string &val,
	      float &h0, float &h1, float &s0, float &s1, float &v0, float &v1,
	      int &ncolors);

    // return a reference to the colormap pointer
    ColorMap* &Colormap (void) { return cmap; }
    
    // redraw preview (after colormap change)
    void Draw (void);

    // virtual callback for overloading:
    // It is called whenever the colormap is changed by user interaction,
    // e.g. when pressing the evaluate button, loading a new colormap, or 
    // interactively modifying the colormap in the preview.
    virtual void ColormapChange_CB (void) { }

    virtual void SetLanguage (const char **language); // change language
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
