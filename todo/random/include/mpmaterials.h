/*-----------------------------------------------------------------------------*\
| include file for Matpack default materials (textures)           mpmaterials.h |
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

// check for multiple inclusion
#ifndef _MPMATERIAL_H_
#define _MPMATERIAL_H_

//-----------------------------------------------------------------------------//
// include basic definitions 
//-----------------------------------------------------------------------------//

#include "scene.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class WoodMaterial:
// Derived from class Material. The color texture function is overloaded
// to create a wood-like surface structure
//-----------------------------------------------------------------------------//

class WoodMaterial : public Material {
  public:
    float  scale, boardsize;
    ColorF base, ring;

    void color_texture (Vector3D&); // overload virtual function

    WoodMaterial (float ambient = 0.5F,
		  const ColorF &base = ColorF(0.770F,0.568F,0.405F),
		  const ColorF &ring = ColorF(0.468F,0.296F,0.156F),
		  float specular = 0.1F, float exponent = 2.5F,
		  float scale = 10, float boardsize = 80)
      : Material(ambient,base,specular,exponent), 
	scale(scale), boardsize(boardsize), 
	base(base), ring(ring) { use_color_texture = true; }
};
 
//-----------------------------------------------------------------------------//
// class MarbleMaterial:
// Derived from class Material. The color texture function is overloaded
// to create a marble-like surface structure
//-----------------------------------------------------------------------------//

class MarbleMaterial : public Material {
  public:
    float scale;
    ColorF strip, base;

    void color_texture (Vector3D&); // overload virtual function

    MarbleMaterial (float ambient = 0.4f, 
		    const ColorF &base  = ColorF(0.90f, 0.80f, 0.65f),
		    const ColorF &strip = ColorF(0.30f, 0.08f, 0.08f),
		    float specular = 0.3f, float exponent = 1.5f,
		    float scale = 1.0f)  
      : Material(ambient,base,specular,exponent), 
	scale(scale), strip(strip), base(base)  { use_color_texture = true; }
};

//-----------------------------------------------------------------------------//
// class GraniteMaterial:
// Derived from class Material. The color texture function is overloaded
// to create a granite-like surface structure
//-----------------------------------------------------------------------------//

class GraniteMaterial : public Material {
  public:
    float scale;
    ColorF col1, col2;

    void color_texture (Vector3D&); // overload virtual function

    GraniteMaterial (float ambient = 0.6F, 
		     const ColorF &col1 = ColorF(0.647F, 0.565F, 0.5F),
		     const ColorF &col2 = ColorF(0.15F, 0.12F, 0.10F),
		     float specular = 0.1F, float exponent = 3,
		     float scale = 8)
      : Material(ambient,col1,specular,exponent),
	scale(scale), col1(col1), col2(col2) { use_color_texture = true;  }
};

//-----------------------------------------------------------------------------//
// class CheckerboardMaterial:
// Derived from class Material. The color texture function is overloaded
// to create a checkerboard-like surface structure
//-----------------------------------------------------------------------------//

class CheckerboardMaterial : public Material {
  public:
    float scale;
    ColorF col1, col2;

    void color_texture (Vector3D&); // overload virtual function

    CheckerboardMaterial (float ambient = 0.5F,
			  const ColorF &col1 = ColorF(0,0,0),
			  const ColorF &col2 = ColorF(1,1,1),
			  float specular = 0.3F, float exponent = 2,
			  float scale = 2)
      : Material(ambient,col1,specular,exponent),
	scale(scale), col1(col1), col2(col2) { use_color_texture = true;  }
};

//-----------------------------------------------------------------------------//
// class BumpMaterial:
// Derived from class Material. The normal texture function is overloaded 
// to create a surface with irregular bumps.
//-----------------------------------------------------------------------------//

class BumpMaterial : public Material 
{
  public:
    float frequency, intensity;

    void normal_texture (Vector3D& v); // overload virtual function

    BumpMaterial (float ambient = 0.4F, ColorF color = ColorF(.7F,.7F,.7F),
		  float specular = 0.3F, float exponent = 1.5F,
		  float frequency = 20, float intensity = 1.5F)
      : Material(ambient,color,specular,exponent),
        frequency(frequency), intensity(intensity)
    { use_normal_texture = true; }
};

//-----------------------------------------------------------------------------//
// class BrickMaterial:
// Derived from class Material. The color texture function is overloaded
// to create a wall built of bricks with joints and spots of moss.
// Also the normal texture function is overloaded to add a wet gloss.
// Arguments:
//   scale        - overal scale
//   ratio        - width to height ratio of a brick (default 2.3)
//   joint_width  - width of joint relativ to with of brick
//   moss_limit   - moss coverage (the smaller the more)
//-----------------------------------------------------------------------------//

class BrickMaterial : public Material {
  public:
    float scale,ratio,joint_width,moss_limit;
    ColorF brick1_color,brick2_color,joint_color,moss_color;

    void color_texture (Vector3D&);  // overload virtual function
    void normal_texture (Vector3D&); // overload virtual function

    BrickMaterial (float scale = 1, float ratio = 2.3F, float joint_width = 0.08F, 
		   float moss_limit = 1.06F,
		   float ambient = 0.6F, float specular = 0.2F, float exponent = 1,
		   const ColorF &brick1_color = ColorF(0.698F,0.133F,0.133F),
		   const ColorF &brick2_color = ColorF(0.12F, 0.08F, 0.05F),
		   const ColorF &joint_color = ColorF(0.28F,0.12F,0.11F),
		   const ColorF &moss_color = ColorF(0.14F,0.18F,0.09F))
      : Material(ambient,brick1_color,specular,exponent),
	scale(scale), ratio(ratio), 
	joint_width(joint_width), moss_limit(moss_limit),
	brick1_color(brick1_color), brick2_color(brick2_color), 
	joint_color(joint_color), moss_color(moss_color)
	{ use_color_texture = true; 
	  use_normal_texture = true; }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
