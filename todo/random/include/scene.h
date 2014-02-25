/*-----------------------------------------------------------------------------*\
| include file for Matpack graphics kernel routines                     scene.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel. All rights reserved.             |
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


// check for multiple inclusion
#ifndef _SCENE_H_
#define _SCENE_H_

#include "common.h"         // compatibility information and common definitions
#include "vector3d.h"   // 3d coordinate vectors
#include "color.h"
#include "mprectangle.h"
#include "pixel2d.h"
#include "mpbase.h"


#if defined( WIN32 )

namespace MATPACK {

class MpWindow { 
  /* dummy */
  public:
          int Width (void)  { return 0; }
          int Height (void) { return 0; }
};

} // namespace MATPACK

#else

// include the matpack X window application pragramming interface
// which in turn includes several others
#include "mpwindow.h"

#endif

// include STL definitions
#include <iostream>
#include <fstream>

#include <time.h>
#include <string.h>

//----------------------------------------------------------------------------//
// class Trafo - coordinate transformation by matrix
//----------------------------------------------------------------------------//

#include "mptrafo.h"

namespace MATPACK {

// Max number of vertices in a facet. Several static arrays of this size are 
// declared - don't increase it to unreasonably high values.
#ifndef MaxVertices
#define MaxVertices 512
#endif

// Size of the color table. On a 8-plane station you cannot have more than 255
// distinct colors, also if you increase the table size to infinity. 
// But if colors are allocated multiple its good to have a bigger value (say 1024).
// Don't decrease it below the number of fill pattern (21). (see also compat.h)
#ifndef MaxColor
#define MaxColor 1024
#endif

// define the color model
#define BEST_COLORS

//----------------------------------------------------------------------------//
// classes defined here
//----------------------------------------------------------------------------//

class Normal3D;
class Light;
class ListOfLights;
class Trafo;
class Vertex;
class Facet;
class Scene;
class Menu;
class MpImage;
class VHeap;

//----------------------------------------------------------------------------//
// basic definitions
//----------------------------------------------------------------------------//

//#define GRAY75 49151U                 // 75% gray in 16 bit (65535*0.75)
#define GRAY75 191      

// errors returned from member and friend functions
enum SceneErrors {
  SceneNoError = 0,
  SceneUnknownColor = -1,
  SceneFullColorMap = -2,
  SceneRGBOutOfRange = -3,
  SceneFileOpenError = -4,
  SceneFileWriteError = -5,
  SceneFileReadError = -6 
};


// file IO
enum { Append=1 };

// text alignment parameters
/*
enum { 
    LeftBottom   = 0,  LeftCenter,   LeftTop,   LeftBase,
    CenterBottom = 10, CenterCenter, CenterTop, CenterBase,
    RightBottom  = 20, RightCenter,  RightTop,  RightBase
};
*/

//-----------------------------------------------------------------------------//
// font selectors - don't change values - some programs depend on it  !!!!
//-----------------------------------------------------------------------------//

enum { 
  Standard      = 0,
  SansSerife    = 1,
  Roman         = 2,
  RomanBold     = 3,
  RomanSimplex  = 4,  
  RomanSmall    = 5, 
  Italics       = 6, 
  ItalicsBold   = 7,
  ItalicsSmall  = 8,  
  Script        = 9,
  ScriptSimplex = 10,   
  Greek         = 11,
  GreekSimplex  = 12,
  GreekSmall    = 13,    
  GothicItalian = 14,
  GothicEnglish = 15,  
  GothicGerman  = 16, 
  Cyrillic      = 17,     
  Japanese      = 18,
  Symbol        = 19, 
  MathUpper     = 20,
  MathLower     = 21,
  Meteorology   = 22,    
  Astrology     = 23,
  Marker        = 24,
  Music         = 25        
};

//-----------------------------------------------------------------------------//
// available device types. The ordering is crucial (see file scnfunc.cpp) !
//-----------------------------------------------------------------------------//

enum DeviceTypeEnum { 
    PostScriptPortrait            = 0,
    PostScriptLandscape           = 1,
    PostScriptPortraitMonochrome  = 2,
    PostScriptLandscapeMonochrome = 3, 
    PostScriptColorImage          = 4,
    TiffImage                     = 5,
    GifImage                      = 6,
    PbmImage                      = 7,
    JpegImage                     = 8,
    ClassMpWindow                 = 9,
    ClassImage                    = 10
};

// style setting flags 
enum {
    BackGroundColor,    // window setting
    LineColor,          // line drawing
    LineThickness,
    LinePattern,
    DisplayMonochrome,
    ColorDitherize,
    TextFont,           // text layout
    TextFontFirst,
    TextFontLast,
    TextFontName,                       
    TextHeight,
    TextWidth,
    TextThickness,
    TextAngle,
    TextSlant,
    TextColor,
    TextXShear,
    TextYShear,
    TextJustify,
    TitleScale,
    TitleFont,
    TitleThickness,
    TitleColor,
    CurveResolution,    // curve drawing
    CurveInterpolation,
    CurveSmoothing,
    CurveMarking,
    CurveShrink,
    WindowXOrigin,     // inquiries
    WindowYOrigin,
    WindowWidth,
    WindowHeight,
    ScreenWidth,
    ScreenHeight,
    ScreenAspectRatio,
    Error, // is redeclared somewhere !!!!!!!!!!!!!!!
    BadViewPoint,
    HasKeyboard,
    HasColorDisplay,
    HasLocator,
    RGB,
    HSV
};
//----------------------------------------------------------------------------//
// class Normal3D - surface normal vector in 3D space
//----------------------------------------------------------------------------//

class Normal3D {
  public:
    float nx,ny,nz;
    Normal3D (void) {}
    Normal3D (float x, float y, float z) : nx(x), ny(y), nz(z) {}
   ~Normal3D (void) {}

    friend ostream& operator << (ostream& os, const Normal3D& v)
        { return os << "Normal3D(" << v.nx << "," << v.ny << "," << v.nz << ")"; }
};

//----------------------------------------------------------------------------//
// class Light, class ListOfLights - define light sources
//----------------------------------------------------------------------------//
//
//  class Light:
//  ------------
//
//    Light (void);
//    Light (const Light& l);
//    Light (const Vector3D& v, const ColorF& c, float i);
//
//      Constructors:
//      Defines a structure to hold the  definition for a light source.
//      The following members are publically accessible:
//
//      Vector3D:: float x,y,z;          // position in 3d space
//        ColorF:: float red,green,blue; // rgb color components [0.0...1.0]
//                 float intensity;      // intensity factor [0.0...1.0]
//
//      The first constructor initializes color and intensity to 1.0 and
//      the position is set to the origin. The second one copies the settings
//      from the given light and the last constructor sets the
//      light position, color and intensity to the given values.
//
//    Light& operator = (const Light& s);
//
//       Assignment:
//       Copy the contents from the left hand light to the right hand argument.
//
//    friend Light* NextLight (Light*& l);
//
//      Friend function:
//      Increments pointer to the next light. Used for looping through
//      a list of lights.
//
//    friend ostream& operator << (ostream& os, const Light& l);
//
//      Friend function:
//      Writes the definition of the light to the output stream.
//
//
//  class ListOfLights:
//  -------------------
//
//    ListOfLights (void);
//
//      Constructor:
//      Define a structure to maintain a dynamic list of lights.
//
//    ListOfLights (const ListOfLights& src);
//    ListOfLights& operator = (const ListOfLights& src);
//
//      Copy constructor and Assignment:
//      Make a copy of list of lights given as the source argument.
//      In the case of an assignment the list of the left hand side
//      is removed and the list of the right hand side is copied.
//
//    Light* AddLight (const Vector3D& v, const ColorF& c, float i);
//    Light* AddLight (const Light& l);
//
//      Member function:
//      Add a light to the list of lights with the specified position
//      and the specified color and intensity. See "class Light"  for
//      a description of the arguments.  A pointer to the added light
//      is returned.  Null is returned if a new light can't be added.
//
//    Light* GetLight (int n);
//
//      Member function:
//      Returns a pointer to the n-th light in the list. If n is less
//      than 1 or larger than the current number of lights then a Null
//      pointer is returned.
//
//    Light* FirstLight (void);
//
//      Member function:
//      Returns a pointer to the first light in the list. Used for
//      looping through the list.
//
//    void DeleteLight (int n);
//
//      Member function:
//      Deletes the n-th light from the list of lights. If n is out of
//      range nothing is done.
//
//    void   DeleteAllLights (void);
//
//      Member function:
//      Deletes all lights form the list.
//
//    int NumberOfLights (void);
//
//      Member function:
//      Returns the current number of lights in the list.
//
//    friend ostream& operator << (ostream& os, const ListOfLights& l);
//
//      Friend function:
//      Writes the current list of lights to the output stream. Mainly
//      intended for debugging purposes.
//
//----------------------------------------------------------------------------//

class Light : public Vector3D, public ColorF 
{
  private:
    Light* next;                // pointer to next light
  public:
    float intensity;            // intensity factor 0.0 ... 1.0
    Light (void)
        : Vector3D(0,0,0), ColorF(1,1,1), next(0), intensity(1) {}
    Light (const Vector3D& v, const ColorF& c, float i)
        : Vector3D(v), ColorF(c), next(0),intensity(i) {}
    Light (const Light& l)
        : Vector3D(l), ColorF(l), next(0), intensity(l.intensity) {}
   ~Light (void) {};
    Light& operator = (const Light& s);
    friend ostream& operator << (ostream& os, const Light& l);
    friend ostream& operator << (ostream& os, const ListOfLights& l);
    friend Light* NextLight (Light*& l) { return l = l->next; }
    friend class ListOfLights;
};

class ListOfLights {
  private:
    Light *light;
    int number;
  public:
    ListOfLights (void) { light = 0; number = 0; }
    ListOfLights (const ListOfLights&);
   ~ListOfLights (void);
    ListOfLights& operator = (const ListOfLights&);
    Light* AddLight (const Light& l);
    Light* AddLight (const Vector3D& v, const ColorF& c, float i);
    Light* GetLight (int n);
    Light* FirstLight (void) { return light; }
    void   DeleteLight (int n);
    void   DeleteAllLights (void) { this->ListOfLights::~ListOfLights(); } 
    int    NumberOfLights (void) const { return number; }
    friend ostream& operator << (ostream& os, const ListOfLights& l);
};

inline Light& Light::operator = (const Light& s) 
{ 
    x = s.x; y = s.y; z = s.z; 
    red = s.red; green = s.green; blue = s.blue;
    intensity = s.intensity;
    // don't copy next pointer !!!
    return *this; 
} 

//----------------------------------------------------------------------------//
// class Material - surface properties (ambient, color, specular, textures) 
//----------------------------------------------------------------------------//

class Material {
  protected:
    short shade,                // internal for color table lookup
          use_normal_texture,   // checked by the renderer
          use_color_texture,    // checked by the renderer
          use_image_texture;    // checked by the renderer
  public:
    float  ambient;             // ambient light fraction
    ColorF color;               // diffusive color
    float  specular, exponent;  // specular fraction and exponent
    float  opacity;             // not yet supported
    MpImage* image_texture;     // not yet supported

    virtual void normal_texture (Vector3D&) { } // overload with texture
    virtual void color_texture  (Vector3D&) { } // overload with texture

    Material (float = 0.4, const ColorF& = ColorF(0.8F,0.8F,0.8F),
              float = 0.3, float = 2.5);
    virtual ~Material (void);

    friend class Scene;
};

//----------------------------------------------------------------------------//
// class Vertex - vertex of a surface facet
//----------------------------------------------------------------------------//

class Vertex 
  : public Vector3D,    // position vector
    public Normal3D,    // normal vector
    public ColorB       // vertex color
{
  private:
    Vertex *next;
  public: 
    float  rx,ry;       // projection
    Pixel2D  p;         // pixel

    Vertex (void) {}
    Vertex (const Vertex&);
    Vertex (const float*);
    Vertex (float,float,float);
   ~Vertex (void) {}

    Vertex*     NextVertex      (void) const { return next; } 
    Vertex&     operator =      (const Vertex&);
    Vertex&     operator *=     (const Trafo&);
    void        SetColor        (const ColorB& c) { *(ColorB*)this = c; }
    ColorB      GetColor        (void) const { return *(ColorB*)this; }
    
    friend Vertex operator * (const Trafo&, const Vertex&);
    
    friend int operator == (const Vertex& v1, const Vertex& v2)
        { return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z); }
    
    friend int operator != (const Vertex& v1, const Vertex& v2)
        { return (v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z); }

    friend ostream& operator << (ostream& os, const Vertex& c);
    friend int cmp (const Vertex& v1, const Vertex& v2);
    friend void MoveHead (Vertex*&,Vertex*&); 

    friend class Scene;
    friend class VHeap;
};

inline Vertex::Vertex (const Vertex &v)
{
    x = v.x; y = v.y; z = v.z; 
    nx = v.nx; ny = v.ny; nz = v.nz;
    red = v.red; green = v.green; blue = v.blue;
    rx = v.rx; ry = v.ry; 
    p = v.p;
    next = v.next;  // shouldn't copy ?  set to 0 !
}

inline Vertex::Vertex (float xx, float yy, float zz)
{
    x = xx; y = yy; z = zz; nx = ny = nz = rx = ry = 0; 
    next = (Vertex*) 0;
}

inline Vertex::Vertex (const float *v)
{
    x = v[0]; y = v[1]; z = v[2]; nx = ny = nz = rx = ry = 0; 
    next = (Vertex*) 0;
}

inline Vertex& Vertex::operator = (const Vertex& v)
{
    x = v.x; y = v.y; z = v.z; 
    nx = v.nx; ny = v.ny; nz = v.nz;
    red = v.red; green = v.green; blue = v.blue;
    rx = v.rx; ry = v.ry;
    p = v.p;
    // don't assign next-ptr !
    return *this;
}

//----------------------------------------------------------------------------//
// class Facet - surface facet structure
//----------------------------------------------------------------------------//

class Facet 
{
  protected:
    Facet*  next;               // pointer to next facet
    short nvert;                // number of vertices
    Vertex** v;                 // pointer to vector of vertex pointers

    short pxmin,pxmax,          // bounds of projected facet (pixel units)
          pymin,pymax;
    byte clipped;               // flag for clipping state

    ColorB front;               // front side color
    ColorB back;                // back side color

    byte shading;               // shading flag:   false/Flat/Gouraud/Phong/Constant

    byte edgelines;             // edge line flag: false/true/Individual
    union {
        unsigned int mask;      // edge line mask if nvert <= n bits
        unsigned int *maske;    // extended edge line mask if nvert > n bits
    } edge;

    Material* material;         // pointer to material

    void CheckEdgeLineRange (int) const;
    void DeleteEdgeLineMask (void);
    void NewEdgeLineMask    (unsigned int);

  public:

    enum {               // shading modes (false or 0 means "off")
      Flat       = 1, 
      Gouraud    = 2,      
      Phong      = 3, 
      Wireframe  = 4,   
      Constant   = 5,
      Individual = 64   // edge visibility and shading
    };

    // construction
    Facet (int, Material* = 0);
   ~Facet (void);

    Vertex*& operator () (int n) { return v[n]; }
    //  const Vertex* const & operator () (int n) const { return (const Vertex*)(v[n]); } // worked until gcc 3.2
    Vertex*& operator () (int n) const { return v[n]; }

    Vertex&     operator []     (int n) { return *v[n];}
    const Vertex& operator [] (int n) const { return *v[n];}

    int         GetNumVertices  (void)  const { return nvert; } 
    Facet*      NextFacet       (void)  const { return next; }   

    // shading and colors
    void        SetShading      (int shade) { shading = (byte)shade; }
    int         GetShading      (void) const { return shading; }
    void        SetFrontColor   (const ColorB& color) { front = color; }
    ColorB      GetFrontColor   (void) const { return front; }
    void        SetBackColor    (const ColorB& color) { back = color; }
    void        SetColor        (const ColorB& color) { front = back = color; }
    ColorB      GetBackColor    (void) const { return back; }
    void        SetMaterial     (Material* mat) { material = mat; }
    Material*   GetMaterial     (void) const { return material; }

    // edge lines
    void        SetEdgeLineVisibility (int, unsigned int = 0);
    void        SetEdgeLine     (int);
    int         GetEdgeLine     (int) const;
    void        UnsetEdgeLine   (int);

    // geometric properties
    void        Normal          (float&,float&,float&,float&) const;
    void        Center          (float&,float&,float&) const; 
    int         Orientation     (void) const;
    void        FlipOrientation (void);

    friend class Scene;
};

//----------------------------------------------------------------------------//
// class Driver - device driver interface
//----------------------------------------------------------------------------//

class Driver 
{
   public:
    // character reference height: 14 pixel high character on a 800 pixel high canvas
    enum { char_height = 14, char_width = 14, def_canvas_size = 800 };

   char* name;
    void  (*DrvOpen)            (Scene&,const char*,int,int,int,int,int&);
    void  (*DrvClose)           (Scene&);
    void  (*DrvLine)            (Scene&,Pixel2D,Pixel2D); 
    void  (*DrvDot)             (Scene&,Pixel2D);
    void  (*DrvArc)             (Scene&,Pixel2D,int,int,int,int,int);
    void  (*DrvLineStyle)       (Scene&,short,short);
    void  (*DrvColor)           (Scene&,long,short);
    void  (*DrvPolygon)         (Scene&,short,Pixel2D*,long,short);
    void  (*DrvFlush)           (Scene&);
    void  (*DrvClear)           (Scene&);
    void  (*DrvColorMap)        (Scene&,short,short,short,short,short&);
    void  (*DrvPutImage)        (Scene&,MpImage&,int tile);
};

//----------------------------------------------------------------------------//
// font structure definition
//----------------------------------------------------------------------------//

typedef struct
{
  int     selector;      // unique font selection index
  char*   name[MaxFontName]; // name of the vector font
  short   first,         // first ASCII code in font
          last,          // last ASCII code in font
          smear,         // map code not in font to smear character
          basis,         // basis line offset
          height,        // height (e.g. capital A height)
          depth,         // depth  (e.g. small g lowest line)
          excess;        // excess (e.g. slash is higher than capital)
  char    *table;        // code table
  short   *index;        // index table addresses code table

} fontdef;

//----------------------------------------------------------------------------//
// text layout
//----------------------------------------------------------------------------//

typedef struct 
{
  fontdef *font;        // the vector font
  int     selector;     // the font selector 
  float   xx,xy,yx,yy;  // shear matrix elements
  int     thickness,    // line thickness
          justify;      // text justify (LeftBottom/CenterTop,...)
  long    color;        // text color
} textdef;

//----------------------------------------------------------------------------//
// plot and curve layout 
//----------------------------------------------------------------------------//

typedef struct {
    double  smoothing;
    float   shrink, 
            titlescale;
    int     resolution,
            interpolation,
            marking,
            titlefont,
            titlethickness;
    long    titlecolor;
} curvedef;


//----------------------------------------------------------------------------//
// the progress meter hook
//----------------------------------------------------------------------------//

typedef void (*ProgressMeterType)(int min, int max, int cnt, void *vptr);
void DefaultProgressMeter (int min, int max, int cnt, void *vptr);

//----------------------------------------------------------------------------//
// class Scene - description of a scene
//----------------------------------------------------------------------------//

class Scene : private Driver,      // inherit the device drivers
              public MpBase,       // inherit basic definitions
              public ListOfLights // inherit lights
{
  public:

     // coloring model
    enum { Global = 0, PerVertex= 1, PerFacet = 2 };

    // hidden surface algorithms
    enum { DepthSort = 0, TopoSort = 1 };

    // facet culling mode: false=0, Front, Back
    enum { Front = 1, Back = 2 };

  private:

    Facet* facets;              // facets list
    Vertex* vertices;           // vertices list

    int nfacets,                // counters
        nvertices,
        nvertptr;
    
    Facet* clipfacets;          // pointer to facets and 
    Vertex* clipvertices;       // vertices added when clipping

    int p1,p2,q1,q2;            // canvas boundaries: horiz. p1..p2, vert. q1..q2
    float xyratio;              // aspect ratio width/height of a device pixel
    
    float dist;                 // 3d projection, distance of proj. plane
    Trafo Q, Qinv;              // 3d observer trafo matrix and inverse

    Vector3D camera;            // position of the camera

    double ux,uy,vx,vy;         // 2d scaling (double !)

    float sx,sy,tx,ty;          // 3d canonical window scaling (float !)
   
    ColorF background_color,    // the background color
           foreground_color,    // current foreground drawing color
           fog_color;           // color of fog
    float  fog_opacity,         // decay length of absorption 
           fog_distance;        // distance of fog from observer
                                        
    Material mat;               // global material definition
        
    int shading;                // constants: see class Facet
    int coloring;               // coloring model
    int hidden;                 // hidden surface algorithms

    bool facetculling;          // true/false (default: false)
    int visible_facet_orientation; // 1/-1 (default: 1, i.e. counterclockwise)

    bool viewbacktransform;     // backtrafo from observer to original (default: true)

    int edgelines,              // false,true,Individual (facet edge lines)
        fixedlights,            // false,true (lights in the observer system)
        viewclip,               // false,true (viewport clipping flag)
        isopen,                 // false,true (scene is open)
        boxclip,boxclip2,       // false,true (box clipping flag)
        error;                  // <number> (last error condition)

    short linethickness,        // line thickness and pattern
          linepattern;
                 
    float cbx[6];               // clip box volume 3D 
    double cb2[4];              // clip box volume 2D

    int ds;                     // RGB resolution of colortable

    float text_line_spacing;    // spacing factor between text lines

    ProgressMeterType ProgressMeter; // the progress meter hook
    void *ProgressMeterArgs;    // argument pointer

    // internal primitives
    void        SetDefaults    (void);
    void        ClipBoxFacet    (Facet&); 
    void        ClipBoxScene    (void);  
    int         InBox           (int,Vertex*);
    int         InBox           (int,float,float,float);
    void        ClipViewFacet   (Facet&); 
    void        ClipViewScene   (void);  
    int         InView          (int,Vertex*,float);
    void        CutPlaneFacet   (float,float,float,float, Facet&,Facet**,Facet**);
    void        ClipSave        (void); 
    void        ClipRestore     (void);
    int         FacetOverlap    (Facet&, Facet&); 
    void        PhongColor      (float,float,float,float,float,float,
                                 Material*,short&,short&,short&);
    void        ObserveFacets   (void);
    void        BacktransObserve(void);
    void        ProjectFacets   (void); 
    void        MeanNormals     (void);
    void        TopoShadeFacets (void);
    void        DepthShadeFacets(void); 
    void        BoundsOfFacets  (void);

    void        WireFrame       (void);    
    long        LookupColor     (short,short,short,Material*);
    void        Warn            (const char*);
    Pixel2D     Map3d           (float,float) const;
    void        VectorString    (const char*,int,int&,int&,int&,int&);
    void        SetFont         (short);
    void        SetText         (float,float,float,float,int,int);

    void        PhongFacetPerVertexColor (Facet&);   
    void        PhongFacetPerFacetColor (Facet&);   

  public:  // the following variables will become private - don't use them

    Pixel2D     curpix;         // current pixel position
    double      cur_x,cur_y;            // UNUSED CURRENLY
    float       cur_x3,cur_y3,cur_z3;   // UNUSED CURRENLY

    int         vp1,vp2,vq1,vq2;// viewport boundaries (Pixel2D)
  
    long        backcolor,      // the current colors
                linecolor;

    char        *name;          // file name or title of window 
    FILE        *file;          // graphics output file for PostScript,Tiff,...
    int         PathCount,      // counts PostScript path length 
                PageCount;      // counts PostScript pages
  
    int         xmax,ymax;      // maximal horizontal/vertical device coordinates 
  
    int         vchar,hchar;    // default vertical/horizontal character size
  

    int         colordisp,      // set if color display
                haslocator,     // set if locator (mouse)
                keyboard,       // set if keyboard available
                truecolor,      // set if 24-bit colors e.g. PostScript
                displaymono,    // set if monochrome instead of colors
                colordither;
  
    textdef     text;           // text/font layout
    curvedef    curve;          // curve layout

    MpImage     *image;         // pointer to matpack image class
    MpWindow    *mpwindow;      // pointer to matpack window class
  
    Pixel2D     pscurpix;       // PostScript current pixel marker

  public:

    // constructors and destructor
    Scene       (void);
    Scene       (int, const char* =0,int=40,int=40,int=0,int=0);
    Scene       (MpImage& img); 
    Scene       (MpWindow& mpw);
   ~Scene       (void);

    // copy constructor and assigmnent operator
    Scene       (const Scene& src);
    Scene&      operator = (const Scene& src);
  
    // scene building 
    Facet&      AddFacet        (int n, Material *material = 0);
    Facet&      AddFacet        (int n, const Facet &src);
    Facet&      AddFacet        (int n, const Vertex *v1, ...);
  
    Vertex&     AddVertex       (const Vertex&);
    Vertex&     AddVertex       (const float*);
    Vertex&     AddVertex       (float,float,float);

    void        CopySettingsFrom(const Scene&);
    void        AddScene        (const Scene&, const Trafo& P = Identity); 
    void        AddBackFacets   (void);

    void        Transform       (const Trafo&);
    void        Project         (float);
    void        Remove          (void);
    void        RemoveUnlinkedVertices (void);

    // perspective settings (low level routines)
    void        SetMatrix       (const Trafo& T) { Q = T; } 
    Trafo       GetMatrix       (void) const { return Q; } 

    float       GetDistance     (void) const { return dist; }
    void        SetDistance     (float d) { dist = d; }

    float       GetFieldOfView  (void) const { return float(atan(1.0/dist)*360.0/M_PI); }
    void        SetFieldOfView  (float fov) { dist = float(1.0/tan(fov*M_PI/360.0)); }

    // allocation inquiries
    int         GetNumVertices  (void) const { return nvertices; }
    int         GetNumFacets    (void) const { return nfacets; }
    long        GetMemoryUsage  (void); 
  
    // direct access of vertex and facet lists
    Vertex      *TheVertices    (void) { return vertices; } 
    Facet       *TheFacets      (void) { return facets; }

    // same but with const access
    const Vertex*TheVertices    (void) const { return vertices; } 
    const Facet *TheFacets      (void) const { return facets; }

    void        Extent          (float&,float&,float&,float&,float&,float&) const;
    int         IsOpen          (void) const { return isopen; }

    // rendering
    void        SetHiddenSurface      (int);  // DepthSort/TopoSort
    int         GetHiddenSurface      (void) const { return hidden; }
  
    void        SetViewBackTransform  (bool); // true/false (default: false)
    int         GetViewBackTransform  (void) const { return viewbacktransform;} 
  
    void        SetFacetCulling       (bool); // true/false (default: false)
    bool        GetFacetCulling       (void) const { return facetculling; } 

    void        SetVisibleFacetOrientation (int);
    int         GetVisibleFacetOrientation (void) const { return visible_facet_orientation; }

    void        SetGlobalShading      (int); // false/Fl./Ph./Go./Co./Wir./Indiv.
    int         GetGlobalShading      (void) const { return shading; }
  
    void        SetGlobalEdgeLines    (int); // false/true/Individual
    int         GetGlobalEdgeLines    (void) const { return edgelines; }
  
    void        SetColoring           (int); // PerVertex/PerFacet/Global
    int         GetColoring           (void) const { return coloring; }

    void        SetGlobalMaterial     (const Material&); // material
    Material    GetGlobalMaterial     (void) const { return mat; }

    void        SetFixedLights        (int); // false/true
    int         GetFixedLights        (void) const { return fixedlights; } 
  
    // changes that apply for all facets individually 
    void        SetFacetShading       (int); // false/Flat/Phong/Gouraud/Constant
    void        SetFacetEdgeLines     (int); // false/true
    void        SetFacetColor         (const ColorB&); 
    void        SetFacetMaterial      (const Material&); 
    void        FlipFacetOrientation  (void);
  
    void        SetFog                (float fo, float fd, const ColorF &c) 
                {fog_opacity = fo; fog_distance = fd; fog_color = c;} 
    void        GetFog                (float &fo, float &fd, ColorF &c) const 
                {fo = fog_opacity; fd = fog_distance; c = fog_color;} 
  
    void        ColorResolution       (int);
    void        Resolution            (int);
  
    // reconstruction
    void        ClipAtPlane     (float vx, float vy, float vz, float vk, 
                                 int outline = true);
    void        Reconstruct     (void);
    void        ClipIntersections(void);  // NOT YET !!!!!!!!!!

    // define absolute canvas (device) coordinates
    void        SetCanvas       (const MpRectangle<int> &rectangle, 
                                 float aspectratio);    
    MpRectangle<int> GetCanvas  (void) const;
    float       GetAspectRatio  (void) const;

    // define viewport
    void        SetViewPort     (bool clip=true); 
    void        SetViewPort     (const MpRectangle<int> &rectangle, bool clip=true); 
    MpRectangle<int> GetViewPort (void) const;

    // define clipping at box
    void        ClipBox         (bool clip=true);
    void        ClipBox         (float,float,float,float,float,float,bool clip=true);
 
    // 3d coordinate system
    void        Look            (const Vector3D& cam, const Vector3D& dir,
                                 float dist, float twist=0);
    void        LookFrom        (const Vector3D& cam, float twist=0);
    void        LookAtBox       (float,float,float,float,float,float,
                                 const Vector3D& cam,float twist=0);
    void        BoxRatios       (float,float,float);
  
    // simple drawing
    Pixel2D     Map             (float,float,float) const;
    Pixel2D     Map             (const Vector3D&) const;
    Pixel2D     Map             (const Vertex&) const;
  
    void        MoveTo          (float,float,float); 
    void        MoveTo          (const Vector3D&); 
    void        MoveTo          (const Vertex&); 
  
    void        LineTo          (float,float,float); 
    void        LineTo          (const Vector3D&); 
    void        LineTo          (const Vertex&); 
  
    void        Line            (float,float,float,float,float,float);
    void        Line            (const Vector3D&,const Vector3D&);
    void        Line            (const Vertex&,const Vertex&);

    void        Dot             (float,float,float);  
    void        Dot             (const Vector3D&);  
    void        Dot             (const Vertex&);  

    void        Polygon         (short,float*,float*,float*,long,
                                 short=Fill|Outline);
    void        Arrow           (float,float,float,float,float,float,
                                 float,float,float);     

    // displaying
    int         Open            (int device, const char *name=0,
                                 int x=40,int y=40,int w=0,int h=0);
    int         Open            (MpImage& image); 
    int         Open            (MpWindow& window); 
    void        Close           (void); 
    void        Show            (void);

    // the Facet drawing functions (void DrawFacet(Facet&) points to them)
    void        FlatFacet       (Facet& f);
    void        ConstantFacet   (Facet& f);
    void        PhongFacet      (Facet& f);   
    void        GouraudFacet    (Facet& f);   
    void        WireFacet       (Facet& f);   
                   
    // 3d solid body creation
    void        Revolve         (int,float*,float*,int,
                                 const Trafo& P=Identity,const ColorB* col=NULL);
    void        Extrude         (int,float*,float*,float,const 
                                 Trafo& P=Identity,const ColorB* col=NULL);
    void        Sweep           (int,float*,float*,int,float,float,
                                 void (*f)(float,float&,float&,float&),
                                 const Trafo& P=Identity,const ColorB* col=NULL);
  
    // drawing primitives for 2d coordinate system
    void        Scale           (double x1, double x2, double y1, double y2);

    void GetScale (double &ux, double &vx, double &uy, double &vy) const
    {
      ux = Scene::ux; vx = Scene::vx; uy = Scene::uy; vy = Scene::vy; 
    }

    void        ClipBox         (double x1, double x2, double y1, double y2, bool clip = true);

    Pixel2D     Map             (double x, double y) const;

    void        MoveTo          (Pixel2D p);
    void        MoveTo          (double x, double y);
  
    void        LineTo          (Pixel2D p);
    void        LineTo          (double x, double y);
  
    void        Line            (Pixel2D p1,Pixel2D p2);
    void        Line            (double x1, double y1, double x2, double y2);
  
    void        Dot             (Pixel2D p); 
    void        Dot             (Pixel2D p, long color); 
    void        Dot             (double x, double y);
  
    void        Polygon         (short n, Pixel2D* p, long color, 
                                 short mode=Fill|Outline);
    void        Polygon         (short n, double* x, double* y, long color, 
                                 short mode=Fill|Outline);

    void        Arc             (Pixel2D p,int,int,int,int,int=0);
    void        Arc             (double x, double y, double ra, double rb, 
                                 double a, double b, int mode=0);
    void        Circle          (double x, double y, double r, int mode=0);
  
    void        Arrow           (Pixel2D ,Pixel2D,float,float,float); 
    void        Arrow           (double tx, double ty, double hx, double hy, 
                                 double thick, double headthick, 
                                 double headlength); 
  
    // Hershey stroke fonts
    void        Write           (double x, double y, const char* textstring, 
                                 int justify = AlignLeft|AlignBase); 
    void        Write           (double x1, double y1, double x2, double y2, 
                                 const char* textstring);

    void        SetTextStyle    (int font, 
                                 float xx, float xy, float yx, float yy,
                                 int thickness = 1, int justify = AlignLeft|AlignBase,
                                 float spacing = 1.2);
    void        SetTextStyle    (int font, 
                                 float size = 1, float angle = 0);
    void        GetTextExtent   (const char* textstring,
                                 int& width, int& height, int& depth, 
                                 int& lines, float& spacing);
    void        Write           (const char* textstring, 
                                 int justify = AlignLeft|AlignBase); 
    void        Write           (float x, float y, float z, const char* textstring,
                                 int justify = AlignLeft|AlignBase); 
    void        Write           (Vector3D& v, const char* textstring,
                                 int justify = AlignLeft|AlignBase); 
  
    // colors
    long        NewColor        (float r, float g, float b, int m = RGB);
    long        NewColor        (const ColorF& col); 
    long        NewColor        (const char* col);
  
    void        SetColor        (long col) 
                                { (*DrvColor)(*this,linecolor=col,true); }
    void        SetColor        (const ColorF& col) 
                                { foreground_color = col; 
                                  SetColor(NewColor(col)); }
    void        SetColor        (char* col)   
                                { SetColor(NewColor(col)); }
    void        SetColor        (float r, float g, float b)
                                { foreground_color = ColorF(r,g,b); 
                                  SetColor(NewColor(r,g,b)); }
  
    void        SetBackground (long c)
                                { (*DrvColor)(*this,backcolor=c,false); }
  
    void        SetBackground (void)
                                { (*DrvColor)(*this,backcolor,false); }
  
    void        SetBackground   (const ColorF& col) 
                                { background_color=col;
                                  SetBackground(NewColor(col)); }
    void        SetBackground   (char* col)   // MISSING !!! background_color=col;
                                { SetBackground(NewColor(col)); }

    // line style
    int         GetLinePattern  (void) const { return linepattern; }
    int         GetLineThickness(void) const { return linethickness; }
    long        GetLineColor    (void) const { return linecolor; }

    void        Style           (int,long);
    void        Style           (int,float);
    void        LineStyle       (short,short=1);
    long        GetInfo         (int);
    void        Flush           (void);

    void        Clear           (void);
        
    // restore settings
    void        Restore         (Scene&);  

    // Image drawing
    void        PutImage        (const MpImage&,int tile=0);

    // stream input and output
    int read  (istream& is);
    int write (ostream& os) const;
    friend ostream& operator << (ostream &os, const Scene& scene);
    friend istream& operator >> (istream &is, Scene &scene);

    // progress meter function
    void HookProgressMeter   (ProgressMeterType user_prog_meter,void *vptr);
    void UnhookProgressMeter (void);
};

//----------------------------------------------------------------------------//
// font path to the font directory
//----------------------------------------------------------------------------//

extern char fontpath[256];

//----------------------------------------------------------------------------//
// class Scene inlines
//----------------------------------------------------------------------------//

inline void Scene::Line (Pixel2D p1, Pixel2D p2) 
{
  (*DrvLine)(*this,p1,p2); curpix = p2;
}

inline void Scene::LineTo (Pixel2D p)
{
  (*DrvLine)(*this,curpix,p); curpix = p;
}

inline void Scene::MoveTo (Pixel2D p) 
{
  curpix = p;
}

inline void Scene::Dot (Pixel2D p)
{
  (*DrvDot)(*this,curpix=p);
}

inline void Scene::Dot (Pixel2D p, long c) 
{
  (*DrvColor)(*this,linecolor=c,true);
  (*DrvDot)(*this,curpix=p);
}

inline void Scene::Arc (Pixel2D p,int a,int b,int c,int d,int f)
{
  (*DrvArc)(*this,curpix=p,a,b,c,d,f);
}

inline void Scene::LineStyle (short p, short t)
{
  (*DrvLineStyle)(*this, linepattern=p, linethickness=t);
}

inline void Scene::Polygon (short n, Pixel2D *p, long c, short f)
{
  (*DrvPolygon)(*this,n,p,c,f); curpix = p[0];
}

inline void Scene::Flush (void)
{
  (*DrvFlush)(*this);
}

inline void Scene::Clear (void)
{
  (*DrvClear)(*this);
}

inline void Scene::PutImage (const MpImage& image, int tile)
{
  (*DrvPutImage)(*this,(MpImage&)image, tile);
}

//----------------------------------------------------------------------------//
// 2D drawing
//----------------------------------------------------------------------------//

inline void Scene::LineTo (double x, double y) 
{
  Line(cur_x,cur_y,x,y);
}

inline void Scene::MoveTo (double x, double y) 
{
  cur_x = x; cur_y = y;
  curpix = Pixel2D((short)(ux*x+vx+0.5),(short)(uy*y+vy+0.5));
}

inline void Scene::Dot (double x, double y) 
{
  cur_x = x; cur_y = y;  
  Dot(Pixel2D((short)(ux*x+vx+0.5),(short)(uy*y+vy+0.5)) );
}
 
inline Pixel2D Scene::Map (double x, double y) const
{
  return Pixel2D((short)(ux*x+vx+0.5),(short)(uy*y+vy+0.5));
}

inline void Scene::Circle (double x, double y, double r, int mode)
{
  Arc(x,y, r,r, 0.0, 360.0, mode);
}

// 3D drawing using Vector3D

inline Pixel2D Scene::Map (const Vector3D& P) const
{
  return Map(P.x,P.y,P.z);   
}   

inline void Scene::MoveTo (const Vector3D& P)
{
  MoveTo(P.x,P.y,P.z);
}   

inline void Scene::LineTo (const Vector3D& P)
{
  LineTo(P.x,P.y,P.z);    
}   

inline void Scene::Line (const Vector3D& P1, const Vector3D& P2)   
{
  Line(P1.x,P1.y,P1.z,P2.x,P2.y,P2.z);
}

inline void Scene::Dot (const Vector3D& P)
{
  Dot(P.x,P.y,P.z);
}   

// 3D drawing using Vertex

inline Pixel2D Scene::Map (const Vertex& v) const
{
  return Map(v.x,v.y,v.z);   
}   

inline void Scene::MoveTo (const Vertex& v)
{
  MoveTo(v.x,v.y,v.z);
}   

inline void Scene::LineTo (const Vertex& v)
{
  LineTo(v.x,v.y,v.z);    
}   

inline void Scene::Line (const Vertex& v1, const Vertex& v2)   
{
  Line(v1.x,v1.y,v1.z,v2.x,v2.y,v2.z);
}

inline void Scene::Dot (const Vertex& v)
{
  Dot(v.x,v.y,v.z);
}   

// etc

inline Pixel2D Scene::Map3d (float x, float y) const
{
  return Pixel2D((short)(sx*x+tx+0.5),(short)(sy*y+ty+0.5));
}

// other inlines
// -------------

inline float RGBintensity (short r, short g, short b)
{
  return 0.9999F/255.0F*(0.30F*r+0.59F*g+0.11F*b);        
}

inline float RGBintensity (float r, float g, float b)
{
  return 0.9999F/255.0F*(0.30F*r+0.59F*g+0.11F*b);        
}

//----------------------------------------------------------------------------//
// defines for function arguments
//----------------------------------------------------------------------------//

#define PhaseOnly 1
#define CloseDim1 1
#define CloseDim2 2
#define ThicknessScale 2
#define Closed 3
#define Smoothing 0
#define Exact 4
#define LinearFit 1
#define RobustFit 3
#define LinLin 0
#define LinLog 1
#define Project3D 1
#define Points 2
#define LogLin 2
#define LogLog 3
#define Base 4
//#define Lines 4
#define NoAxis 8
#define Linear 8
#define Scatter 8
#define Regress1 8

//#define Bezier 16

//#define Squares 16
#define Monotone 32
#define SeaLevel 32
#define CenterAxis 32
#define Histogram 64
//#define    Smoothed 64
#define MarkData 64
#define Boxed 128
#define Spline 128
#define Wireframe1 256
// #define BSpline 256
#define Wireframe2 512
#define Draw3D 512
#define Greyscale  1024
//#define    ErrorDiffusion 1024
#define Colored 2048
//#define    OrderedDither 2048
#define NoAutoScale 4096
#define NoPolyOutline 8192
#define Lighting 16384

//----------------------------------------------------------------------------//
// prototypes
//----------------------------------------------------------------------------//

void    readln          (char*);
float   hypot           (float,float,float);
double  hypot           (double,double,double);
float   FieldOfView     (float);

//----------------------------------------------------------------------------//
// Platonic body creation
//----------------------------------------------------------------------------//

void    MpTetrahedron   (Scene&,const Trafo& P=Identity, const ColorB* col=NULL);
void    MpHexahedron    (Scene&,const Trafo& P=Identity, const ColorB* col=NULL);
void    MpOctahedron    (Scene&,const Trafo& P=Identity, const ColorB* col=NULL);
void    MpDodecahedron  (Scene&,const Trafo& P=Identity, const ColorB* col=NULL);
void    MpIcosahedron   (Scene&,const Trafo& P=Identity, const ColorB* col=NULL);

//----------------------------------------------------------------------------//
// Other basic bodies
//----------------------------------------------------------------------------//

void    MpCube          (Scene&,const Trafo& P=Identity, const ColorB* col=NULL);

void    MpSphere        (Scene& scene, int nu, int su, int nv, int sv, 
                         const Trafo& P=Identity, const ColorB* col=NULL);

void    tube            (Scene&,int,const Trafo& P=Identity,
                                const ColorB* col=NULL);
void    cone            (Scene&,int,const Trafo& P=Identity,
                                const ColorB* col=NULL);
void    torus           (Scene&,float,int,int,const Trafo& P=Identity,
                                const ColorB* col=NULL); 
void    cylinder        (Scene&,int,const Trafo& P=Identity,
                                const ColorB* col=NULL);
//----------------------------------------------------------------------------//
// Etc
//----------------------------------------------------------------------------//

void    stellate        (Scene&,float);

void    Box             (Scene&,float,float,float,float,float,float);
void    Box             (Scene& scene, double x1, double x2, double y1, double y2);

void    Hatch           (Scene& scene,
                         int n, double* x, double* y, double dist,
                         double dx=1, double dy=1, int mode=Outline);

void    PieSlice        (Scene&,float,float,float,float,float,float,
                         float=1,float=1,int=Outline);

void    ProgressMeter   (Scene& scene, int min, int max, int cnt, void *);

void    InitNoise       (long seed);
float   Noise           (float,float,float);
void    DNoise          (float&,float&,float&);
float   Turbulence      (float,float,float,float);

// istream& scan           (istream& s, char const *fmt, ...);

} // namespace MATPACK

//----------------------------------------------------------------------------//

#endif
