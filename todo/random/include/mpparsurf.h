/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface               mpparsurf.h |
| Include file for 3d parametric surface creation panel                         |
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

#ifndef _MPPARSURF_H_
#define _MPPARSURF_H_

#include "mplineedit.h"
#include "scene.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// Definitions for parametric surface
//-----------------------------------------------------------------------------//

class MpParametricSurfaceDef
{
  public:
    string xuv, yuv, zuv;
    double u0,u1,v0,v1;
    int    nu,su,nv,sv;
    bool   pu,pv;

    MpParametricSurfaceDef(const string &xuv, const string &yuv, const string &zuv, 
			   double u0, double u1, int nu, int su, bool pu, 
			   double v0, double v1, int nv, int sv, bool pv)
      : xuv(xuv), yuv(yuv), zuv(zuv),
        u0(u0), u1(u1), v0(v0), v1(v1), 
        nu(nu), su(su), nv(nv), sv(sv), 
        pu(pu), pv(pv) { }
};

//-----------------------------------------------------------------------------//
// Panel for parametric surface calculation
//-----------------------------------------------------------------------------//

typedef void (*MpParametricSurfaceHook) (MpParametricSurfaceDef &def,
					 Scene &scene, void *ptr);

class MpNumex;

class MpParametricSurfacePanel : public MpFrame 
{
  protected:
    enum { W = 410, H = 270, LEN = 255 };
    MpLineEdit *xuv_win,*yuv_win,*zuv_win, 
               *u0_win,*u1_win,*v0_win,*v1_win,
               *nu_win,*su_win,*nv_win,*sv_win;
    bool pu,pv;
    MpParametricSurfaceDef *defp;
    Scene *scnp;    
    MpParametricSurfaceHook hook;
    void *ptr;
    virtual void start (void);
    virtual void close (void);
    virtual void evaluate (const MpParametricSurfaceDef &def, Scene &scene, int hold);
  public:
    MpNumex *Numex;
    MpParametricSurfacePanel (const char *title, 
			      MpParametricSurfaceDef &def, Scene &scene,
			      MpParametricSurfaceHook hook, void *ptr);
    virtual ~MpParametricSurfacePanel();
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
