/*-----------------------------------------------------------------------------*\
| Matpack X windows API - class Mp3dView                             mp3dview.h |
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

#ifndef _MP3DVIEW_H_
#define _MP3DVIEW_H_

#include "mphandle.h"
#include "mpbutton.h"
#include "scene.h"
#include "mpspinbox.h"
#include "mphelpwin.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class Mp3dView: 3-dimensional interactive viewpoint selection window
//-----------------------------------------------------------------------------//

class Mp3dViewDisplay;
class FOVselector;
class Mp3dView : public MpCanvas 
{
  friend class Mp3dViewDisplay;
  friend class FOVselector;
  private:
    bool  blocked;
    int   x_start, y_start;
    int   BX, shifterS, shifterO, borderO, frameD, 
          displayW, displayH, displayX, displayY, 
          v_shifterW, v_shifterH, v_shifterX, v_shifterY,
          h_shifterW, h_shifterH, h_shifterX, h_shifterY,
          helpY,orthoY,defltY;

    Mp3dViewDisplay *display;
    MpHandle<Mp3dView> *v_shifter, *h_shifter;
    MpHelpPopupButton *help_button;
    MpButton *ortho_button, *deflt_button; 
    MpSpinBox *fov_selector;

    Vector3D axisX, axisY;
    char axtext[32], aytext[32], aztext[32];
    Scene scene;
    Trafo ROT, TRANS;
    float alpha, beta, last_alpha, last_beta, dist, fov, alpha0, beta0, 
          dx, dy, dx0, dy0, ax, ay, az;
    int   last_dist_x;

    void Scaling (int w, int h);
    void DisplayHook (MpHandle<Mp3dView> *shifter); 
    void ShowCube (const Trafo& ROT, const Trafo& TRANS, float fov);

  public:
    bool  *ExitFlag, Accepted;

    // constructor
    Mp3dView (MpWindow &parent, bool &exit_flag,
              int w, int h, int x = 0, int y = 0);

    // virtual functions
    virtual void SetDefaults (void);
    virtual void ShowDefault (void);
    virtual void SetParallel (void);
    virtual void ShowParallel (void);
    virtual void Cancel (void); 
    virtual void Accept (void);
    virtual void Resize (int w, int h);
    virtual void Redraw (void);

    // user interface functions
    void SetTrafo (const Trafo& t, float f);
    void GetTrafo (Trafo& t, float& f) const;
    void SetBoxRatios (float ax, float ay, float az);
    void SetAxisTitles (const char* xtitle, const char* ytitle, const char* ztitle);
    virtual bool GUIColorChange_CB (void);
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
