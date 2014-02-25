/*-----------------------------------------------------------------------------*\
| Matpack viewer - include file with class definitions                 mpview.h |
|                                                                               |
| Last change: Jul 9, 2005                                                      |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel                                   |
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

#ifndef _MPVIEW_H_
#define _MPVIEW_H_

// uncomment to get debug output
//#define DEBUG

//-----------------------------------------------------------------------------//
// common includes
//-----------------------------------------------------------------------------//

// STL includes
#include <string>
#include <vector>
#include <map>

// matpack includes
#include "matpack.h"
#include "mpcontourplot.h"

// context save/restore class
#include "mpcontextsave.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpViewExportData:
// Hold data about export (formats, etc ...)
//-----------------------------------------------------------------------------//

class MpViewExportData 
{
  public:
 
   enum {
      Export_None,
      Export_Image,
      Export_Postscript
    };
    int ExportFormat;

    enum {
      Export_Tiff,
      Export_Gif,
      Export_Ppm,
      Export_Jpeg,
      Export_Png
    };
    int ImageFormat;

    enum {                              // export device selection
      Export_File,
      Export_Printer,
      Export_Viewer,
      Export_PSViewer
    };
    int Device;

    bool    grayscale;                  // monochrome 

    // Postscript
    bool    ps_eps,                     // export as EPS
            ps_image,                   // export as raster image
            ps_rle_compress,            // RLE compression for image
            ps_landscape;               // use landscape format

    Pixel2D ps_pos,                     // left/top and right/bottom frame
                                        // width of PS page [mm]
            ps_size,                    // size of the PS page [mm]
            ps_pix_size;                // size of the PS page [pixel]

    // Images
    Pixel2D image_size;                 // size of the exported raster image 
                                        // in units of pixel

    double  image_gamma;                // image gamma

    // JPEG
    int    jpeg_quality,                // quality factor (1..100)
           jpeg_smoothing;              // smoothing factor (0..100)
    bool   jpeg_optimize,               // optimization toggle
           jpeg_progressive,            // progressive JPEG toggle
           jpeg_grayscale;              // grayscale JPEG toggle

    // TIFF
    int    tiff_compression;            // 0,1,2 for none/LZW/packbits

    // PNG
    double png_gamma;                   // write gamma value
    bool   png_interlace;               // interlace
    int    png_compression_level;       // compression leve (1..9)
    
    // PBM/PPM
    int    pbm_raw;                     // write raw format (true/false)
  
    // GIF
    int    gif_interlace;               // interlace

    // files and print commands
    string TempDirectory,               // directory for temporary files
           TempFileName,                // temporary filename
           ExportFileName,              // export file name
           PrinterCommand,              // control string for printer
           ExternalImageViewer,         // external image viewer calls
           ExternalPSViewer;            // external PS viewer calls   

    MpViewExportData (void);
};

//-----------------------------------------------------------------------------//
// class MpViewDataSet:
// hold data to visualize
//-----------------------------------------------------------------------------//

class MpViewDataSet
{
  friend class MpView;
  private:
    string Import_Filename;             // data set name
    string TimeStamp;                   // time stamp

    int theDataType;                    // data type 
    Matrix             Z;               // 2D array of real valued data 
    ComplexMatrix      C;               // 2D array of complex valued data
    MpMatrix3d<double> V;               // 3D array of real valued data
    Scene              S;               // Scene data (i.e. network of polygons)
    MpImage            I;               // RGB image (NOT YET IMPLEMENTED)
  
  public:
    Vector             x,y,z;           // 1D array of real valued 3D vector
    int scene_coloring;                 // Scene::PerFacet/Scene::Global/Scene::PerVertex

    enum {                              // possible values for data type
      a_EmptySet      = 0,      
      a_Matrix        = 1,
      a_Matrix3d      = 2,
      a_ComplexMatrix = 3,
      a_Scene         = 4,
      a_XYZSet        = 5,
      a_Image         = 6               // not yet used
    };

    int GetDataType(void) const { return theDataType; }

    // verify data type
    bool isEmpty        (void) const;
    bool isMatrix       (void) const;
    bool isMatrix3d     (void) const;
    bool isComplexMatrix(void) const;
    bool isScene        (void) const;
    bool isXYZSet       (void) const;
    bool isImage        (void) const;
  
    void SetName(const string &name);        // Set data set name
    string GetName (void) const;             // Get data set name

    void SetModified (const string &name = ""); // Set modified marker (optional name)
    bool isModified (void) const;               // return true if modified

    void SetTimeStamp(const string &stamp);  // Set time stamp string
    void SetTimeStamp(void);                 // Set time stamp to 'now'
    string GetTimeStamp (void) const;        // Get time stamp

    // Return reference to data array. The data type is automatically set according
    // to the referenced data type. If dimensions are given the array is allocated.
    ComplexMatrix& ComplexMatrixData(int rlo,int rhi,int clo,int chi);
    ComplexMatrix& ComplexMatrixData(void);

    Matrix& MatrixData(int rlo,int rhi,int clo,int chi);
    Matrix& MatrixData(void);

    MpMatrix3d<double>& Matrix3dData(int slo,int shi,int rlo,int rhi,int clo,int chi);
    MpMatrix3d<double>& Matrix3dData(void);

    Scene& SceneData(void);
    void XYZSetData(void);

    MpImage& ImageData(void);

    // constructors
    MpViewDataSet (void);
    MpViewDataSet (const MpViewDataSet &src);

    // assignment
    MpViewDataSet& operator = (const MpViewDataSet &src);

    // destructor
   ~MpViewDataSet (void);
    void RemoveDataSet (void);
};

//-----------------------------------------------------------------------------//
// inline functions
//-----------------------------------------------------------------------------//

inline Matrix& MpViewDataSet::MatrixData(void)
{
  theDataType = a_Matrix;
  return Z;
}

inline ComplexMatrix& MpViewDataSet::ComplexMatrixData(void)
{
  theDataType = a_ComplexMatrix;
  return C;
}

inline MpMatrix3d<double>& MpViewDataSet::Matrix3dData(void)
{
  theDataType = a_Matrix3d;
  return V;
}

inline Scene& MpViewDataSet::SceneData(void)
{
  theDataType = a_Scene;
  return S;
}

inline MpImage& MpViewDataSet::ImageData(void)
{
  theDataType = a_Matrix; // CURRENTLY IMMEDIATELY CONVERTED TO MATRIX
  return I;
}

inline void MpViewDataSet::XYZSetData(void)
{
  theDataType = a_XYZSet;
}

inline bool MpViewDataSet::isEmpty (void) const 
{ 
  return (theDataType == a_EmptySet); 
}

inline bool MpViewDataSet::isMatrix (void) const 
{ 
  return (theDataType == a_Matrix);   
}

inline bool MpViewDataSet::isMatrix3d (void) const 
{ 
  return (theDataType == a_Matrix3d); 
}

inline bool MpViewDataSet::isComplexMatrix (void) const 
{ 
  return (theDataType == a_ComplexMatrix); 
}

inline bool MpViewDataSet::isScene (void) const 
{ 
  return (theDataType == a_Scene); 
}

inline bool MpViewDataSet::isXYZSet (void) const 
{ 
  return (theDataType == a_XYZSet); 
}

inline bool MpViewDataSet::isImage (void) const 
{ 
  return (theDataType == a_Image); 
}

inline void MpViewDataSet::SetName (const string &name)
{
  Import_Filename = name;
}

inline string MpViewDataSet::GetName (void) const
{
  return Import_Filename;
}

inline void MpViewDataSet::SetTimeStamp (const string &stamp)
{
  TimeStamp = stamp;
}

inline string MpViewDataSet::GetTimeStamp (void) const
{
  return TimeStamp;
}

//-----------------------------------------------------------------------------//
// class MpViewImportData:
// Hold data about data import specification (formats, etc ...)
// and supply a data set import function
//-----------------------------------------------------------------------------//

class MpViewImportData 
{
  public:
    enum { MaxDim = 2*3 };      // lower and upper index for three dimensions
    int Import_Array_Dimension, // 1,2,3
        Import_Array_Order,     // MpRowMajor, MpColumnMajor
        Import_Element_Type,    // 1,2,3
        Import_Number_Type,     // MpRealValued, MpComplexValued
        Import_Number_Format,   // MpTextFormat, MpBinaryFormat
        Import_Number_Precision,// MpSingle, MpDouble
        Import_Byte_Order,      // MpNativeByteOrder, MpSwapByteOrder
        Import_Byte_Offset,     // offset from begin of file
        Import_Dim[MaxDim],     // dimensions (lo1,hi1,lo2,hi2,lo3,hi3)
        Import_Format,          // either of (FmtNative,FmtGenArray,FmtImage)
        Import_Image_Function;  // image pixel to scalar conversion function

    // values for Import_Format
    enum { FmtNative,
           FmtGenArray,
           FmtImage };          

    // values for Import_Image_Function conversion
    enum { ImgBright709,        // brightness according to ITU-R BT 709   (1990)
           ImgBright601,        // brightness according to ITU-R BT 601-2 "NTSC"
           ImgRed,
           ImgGreen, 
           ImgBlue };

    MpViewImportData (void);

    // import a data set from a file
    bool ImportDataSet (const string &FileName, 
                        MpViewDataSet &dset, string &error);

    // image to matrix conversion (conversion function is given by the
    // enumeration type: ImgBright709,...,ImgBlue
    bool MpViewConvertImageToMatrix (const MpImage &image, 
                                     Matrix &matrix, int conversion_function);
};

//-----------------------------------------------------------------------------//
// class MpViewLabelData:
// class for storing a text label and its layout settings
//-----------------------------------------------------------------------------//

class MpViewLabelData 
{                          
  public:                             
    string text;                        // text contents
    int    font,                        // font 
           width,                       // font line width
           frame_width;                 // frame line width
    bool   opaque_flag,                 // flag, set if text has color underlay
           shadow_flag;                 // flag, set if shadowed text frame 
    ColorF color,                       // RGB color for text
           frame_color,                 // RGB color for frame
           back_color;                  // RGB color for background filling
    double size,                        // size of of font
           angle,                       // angle of text (degree)
           line_spacing,                // spacing between lines
           xpos, ypos;                  // position in 2d coordinates

    MpViewLabelData (const string &t = "");  // constructor
    void Write (Scene&);                // write text

   // stream i/o functions
   int read  (istream& is);
   int write (ostream& os) const;
};

//-----------------------------------------------------------------------------//

class MpViewLabelList
{
  public:
    vector<MpViewLabelData> list;

   // stream i/o functions
   int read  (istream& is);
   int write (ostream& os) const;
};

//-----------------------------------------------------------------------------//
// class MpViewKrigingData:
// class for storing parameters for kriging (see mpview.cpp)
//-----------------------------------------------------------------------------//

class MpViewKrigingData 
{                          
  public:  
    int    krig_neighbours, 
           krig_stationarity;
    double krig_co,
           krig_sill,
           krig_angle,  // not changable upto now
           krig_horiz,  // not changable upto now
           krig_radius,
           krig_range;

    MpViewKrigingData (void);
};

//-----------------------------------------------------------------------------//
// class MpViewShepard2Data:
// class for storing parameters for Shepard 2D algorithm (see mpview.cpp)
//-----------------------------------------------------------------------------//

class MpViewShepard2Data 
{                          
  public: 
    int shepard2d_nq,
        shepard2d_nw;

    MpViewShepard2Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewShepard3Data:
// class for storing parameters for Shepard 3D algorithm (see mpview.cpp)
//-----------------------------------------------------------------------------//

class MpViewShepard3Data 
{                          
  public: 
    int shepard3d_nq,
        shepard3d_nw;
    MpViewShepard3Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewProject3Data:
// class for storing parameters of 3D projection plots
//-----------------------------------------------------------------------------//

class MpViewProject3Data
{
  public: 
    double proj3d_radius,                  // radius of sphere
           proj3d_h_south, proj3d_h_north, // height at south/north pole
           proj3d_lon0, proj3d_lon1,       // longitude range
           proj3d_lat0, proj3d_lat1;       // latitude range
    bool   proj3d_periodic,                // close periodically in azimuthal direction
           proj3d_south_pole_cap,          // add flat cap at south/north pole
           proj3d_north_pole_cap,
           proj3d_autoview;     
    int    Three_Dim_Project_StridePol,
           Three_Dim_Project_StrideAzm;

    MpViewProject3Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewLambert2Data:
// class for storing parameters for Lambert 2D shading (see mpview.cpp)
//-----------------------------------------------------------------------------//

class MpViewLambert2Data 
{                          
  public: 
    double lambert2d_azimuth,
           lambert2d_elevation,
           lambert2d_enhance;

    MpViewLambert2Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewBackgroundData:
// background of whole image, uniformly painted, an image or an image tile
//-----------------------------------------------------------------------------//

class MpViewBackgroundData 
{
  public:
    ColorF   BackgroundColor; 
    MpImage  BackgroundTile;     
    string   BackgroundTileFile; // name of tile file
    bool     do_background_tiling;
    double   BackgroundTileX,BackgroundTileY;
    void     RemoveBackground (void);
    MpViewBackgroundData (void) { RemoveBackground(); }
   ~MpViewBackgroundData (void) { RemoveBackground(); }
    bool     LoadBackgroundImage (const string &name);
};

//-----------------------------------------------------------------------------//
// class MpViewColormapLegendData
// hold information about how the colormap legend is represented
//-----------------------------------------------------------------------------//

class MpViewColormapLegendData
{
  public:
    // colormap legends
    bool   colormap_draw_legend,
           colormap_legend_horizontal;
    int    colormap_legend_frame_width,         // frame legend
           colormap_legend_framecell_width;     // frame cells
    ColorF colormap_legend_frame_color,
           colormap_legend_framecell_color;
    MpAxis colormap_legend_axis;                // the colormap axis
    double colormap_legend_x,                   // position (in 0..1 unit coords)
           colormap_legend_y,
           colormap_legend_width,               // size (in 0..1 unit coords)
           colormap_legend_length,
           colormap_legend_cell_spacing;

    void DrawColormapLegend (Scene &scene, ColorMap &cmap);
    MpViewColormapLegendData (void);
};


//-----------------------------------------------------------------------------//
// class MpViewAxisData
// hold information about all axes
//-----------------------------------------------------------------------------//

class MpViewAxisData
{
  public:
    MpAxis Axis[3];             // axis definitions [0,1,2] = [X,Y,Z] axis !
    bool    log_z;              // draw logarithmic z-axis

  MpViewAxisData (void);
};

//-----------------------------------------------------------------------------//
// class MpViewLight
// definition of a light, in "mpviewappear.cpp"
//-----------------------------------------------------------------------------//

class MpViewLight
{
  public:
    bool     active;
    Vector3D position;
    ColorF   color;
    float    intensity;

    MpViewLight (int act = 0, const Vector3D &pos = Vector3D(0,0,0), 
                 const ColorF &col = ColorF(1,1,1), float intens = 1);
};

//-----------------------------------------------------------------------------//
// class MpViewAppearanceData
// hold information about facet appearance
//-----------------------------------------------------------------------------//

class MpViewAppearanceData
{
  public:            
    int    facet_rendering,        // Off,Flat,Gouraud,Phong,Constant,Wireframe
           facet_edges,            // facet edges (Off,On,Individual)
           facet_edge_width,       // facet edge line thickness
           facet_edge_style;       // facet edge line pattern
    ColorF facet_edge_color,       // facet edge color
           facet_diffuse_color;    // diffuse color
    float  facet_ambient_reflectance,
           facet_specular_reflectance,
           facet_specular_exponent;

    enum { MaxLights = 5 };        // maximal number of lights (5, must be >= 3 and <= 10)

    MpViewLight light[MaxLights];  // lights in each graph
    float  fog_opacity, 
           fog_distance;
    ColorF fog_color;
    MpViewAppearanceData (void);
};

//-----------------------------------------------------------------------------//
// class MpViewPortData
// definition of a the viewport of a graph
//-----------------------------------------------------------------------------//

class MpViewPortData 
{
  public:
    MpRectangle<double> viewport;  // coordinates of viewport rectangle 
                                   // given in units coordinates [0,1][0,1]
    int    viewport_frame_width,   // point size
           viewport_frame_style;   // solid,dotted,dashed,...
    bool   draw_viewport_frame,    // flag for fram drawing
           fill_viewport,          // flag for color filling
           viewport_shadow;        // flag for drawing a shadow 

    ColorF viewport_fill_color,    // colors
           viewport_frame_color,
           viewport_shadow_color;
    float  viewport_shadow_offset;

    MpViewPortData  (void);
};

//-----------------------------------------------------------------------------//
// class MpViewPort2Data
// information about 2D coordinate frame data
//-----------------------------------------------------------------------------//

class MpViewPort2Data 
{
  public:

    // 2D coordinate frame data
    double shrink2d;               // 2D shrink of plot rel. to viewport
  
    ColorF frame2d_color,          // 2D viewport frame layout
           frame2d_fill_color;
    int    frame2d_width,               
           frame2d_style;
    bool   frame2d_use_fill_color; // use background color in 2d plot

    ColorF draw2d_color;           // 2D global drawing color (e.g. image plot)
    int    draw2d_width;
    MpViewPort2Data  (void);
};

//-----------------------------------------------------------------------------//
// class MpViewMesh2Data
// hold layout data for 2D mesh, implemetation in "mpviewport2d.cpp"
//-----------------------------------------------------------------------------//

class MpViewMesh2Data
{
  public:

    enum {                              // mesh types
      Two_Dim_Mesh_None = 0,
      Two_Dim_Mesh_Dots = 1,
      Two_Dim_Mesh_Crosses = 2,
      Two_Dim_Mesh_Lines = 3
    };

    bool Two_Dim_Mesh_Afterwards;       // draw mesh after the 2d plot 
    int  Two_Dim_Mesh_Type,             // none/dots/crosses/lines
         Two_Dim_Mesh_Style,            // pattern  of lines
         Two_Dim_Mesh_Width;            // width of lines
    ColorF Two_Dim_Mesh_Color;          // color of mesh lines
    float  Two_Dim_Mesh_Crosses_Length; // rel. length of crosses

    void Draw_2D_Mesh (Scene& scene, int rlo, int rhi, int clo, int chi,
                       int do_projection, float stack_height, 
                       const Trafo& T, int center);

    MpViewMesh2Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewContour2Data
// hold level data for 2D contour plot
//-----------------------------------------------------------------------------//

class MpViewContour2Data 
{
  public:
    int num_contour_level_2D;
    MpContourLevel *contour_level_2D;

    MpViewContour2Data (void);
    MpViewContour2Data (const MpViewContour2Data &src);
   ~MpViewContour2Data (void);

   // stream i/o functions
   int read  (istream& is);
   int write (ostream& os) const;

   static int ParseContourLevelEntry (const char *text, MpContourLevel &level);
};

//-----------------------------------------------------------------------------//
// class MpViewPort3Data
// hold all information about 3D viewport, clipping, and frame
//-----------------------------------------------------------------------------//

class MpViewPort3Data 
{
  public:
    bool   clipping;                    // switch on/off clipping at box

    float  fov;                         // 3D field of view angle
    Trafo  viewtrafo;                   // 3D view transformation matrix

    Trafo  viewcenter;                  // hold center of 3d view
                                        // the center of all data except of type
                                        // scene is (0,0,0). For scenes this value
                                        // may be different. This value is not 
                                        // saved. (set in file mpviewinit.cpp)

    float  vby,vbz,vbx,                 // 3D view box ratios
           cx1,cx2,cy1,cy2,cz1,cz2;     // clip box volume

    ColorF frame3d_color;               // 3D viewport frame layout
    int    frame3d_width,       
           frame3d_style;

    int    base_block_line_width,
           base_block_line_style;
    double base_block_depth;            // the base block depth (thickness)
    ColorF base_block_color,            // color of the base block
           base_block_line_color;       // color of its outlines

    bool   draw_back_walls,             // back side walls in 3D plots
           back_wall_const_shade,       // use const shade, no lighting
           base_block_const_shade,      // use const shade, no lighting  
           draw_base_block;             // set if 3D base block is drawn
    ColorF back_wall_color;             // color of the backside walls

    MpViewPort3Data  (void);
};

//-----------------------------------------------------------------------------//
// class MpViewDots3Data 
// hold information about scatter plots (dots, poles)
//-----------------------------------------------------------------------------//

class MpViewDots3Data 
{
  public:
    ColorF Three_Dim_Poles_Color,
           Three_Dim_Poles_Head_Color;
    int    Three_Dim_Poles_Width,
           Three_Dim_Poles_Head_Radius;
    double Three_Dim_Poles_Base;

    MpViewDots3Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewScatter3Data 
// data for plot of (x,y,z) scattered data
//-----------------------------------------------------------------------------//

class MpViewScatter3Data 
{
  public:
    double Three_Dim_Scatter_Width,
           Three_Dim_Scatter_Riser_Width;
    MpViewScatter3Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewScatter4Data 
// data for scatter plot of 3D volume data
//-----------------------------------------------------------------------------//

class MpViewScatter4Data 
{
  public:
    double Four_Dim_Scatter_Lower, // minimum and maximum of data drawn
           Four_Dim_Scatter_Upper;

    MpViewScatter4Data (void);
};

//-----------------------------------------------------------------------------//
// class MpViewIsoSurfaceDef
// definition of  isosurface of a 3-dimensional skalar field
//-----------------------------------------------------------------------------//

class MpViewIsoSurfaceDef 
{
  public:
    int    Four_Dim_Isosurface_Active;
    double Four_Dim_Isosurface_Level,
           Four_Dim_Isosurface_Quantile;
    int    Four_Dim_XLines,
           Four_Dim_YLines,
           Four_Dim_ZLines;
    ColorF Four_Dim_Isosurface_Color;

    MpViewIsoSurfaceDef (void);

   // stream i/o functions
   int read  (istream& is);
   int write (ostream& os) const;
};

//-----------------------------------------------------------------------------//
// class MpViewIsosurfaceData
// hold data for all isosurfaces
//-----------------------------------------------------------------------------//

class MpViewIsosurfaceData
{
  public:
    enum { MaxIsosurf = 10 };       // maximal number of isosurfaces in one plot
    MpViewIsoSurfaceDef IsoSurface[MaxIsosurf];
};

//-----------------------------------------------------------------------------//
// class MpViewSlicePlotData
// hold data for 4D slice plots
//-----------------------------------------------------------------------------//

class MpViewSlicePlotData
{
  public:
    IntVector SliceDirX, 
              SliceDirY, 
              SliceDirZ;
    bool      SlicePlotOutline;
    MpViewSlicePlotData (void);
};

//-----------------------------------------------------------------------------//
// class MpViewMarkerData: marker layout
//-----------------------------------------------------------------------------//

class MpViewMarkerData
{
  public:

  enum {                        // values for mark_type
      MarkNone, 
      MarkPoints, 
      MarkLines, 
      MarkSymbol1,
      MarkSymbol2,
      MarkSymbol3,
      MarkSymbol4,
      MarkSymbol5,
      MarkSymbol6,
      MarkSymbol7,
      MarkSymbol8,
      MarkSymbol9,
      MarkSymbol10,
      MarkSymbol11,
      MarkSymbol12,
      MarkSymbol13,
      MarkSymbol14,
      MarkSymbol15,
      MarkSymbol16
    };

    int    mark_type,           // how to interprete the markers
           mark_width;
    float  mark_symbol_size;    // size of the marker symbols
    ColorF mark_color;

    MpViewMarkerData (void);
};

//-----------------------------------------------------------------------------//
// class MpViewStackingData: stacking of e.g. 3d over 2d plots
//-----------------------------------------------------------------------------//

class MpViewStackingData
{
  public:
    int   stack_type_2D;
    bool  draw_stacked_after;
    float rel_stack_height;

    MpViewStackingData (void);
};

//-----------------------------------------------------------------------------//
// class MpViewSurface3Data: layout data for 3d surface plots
//-----------------------------------------------------------------------------//

class MpViewSurface3Data
{
  public:
    enum { // 3d surface facet shapes
      Triangles_Left = 0,  
      Triangles_Right,  
      Triangles_Alter,
      Quads,  
      Quads_Triangles,
      Quads_Diagonal,
      Waterfall_X,
      Waterfall_Y,
      Waterfall_Diag1,
      Waterfall_Diag2,
      Bands_X,
      Bands_Y,
      Bands_Mesh_X,
      Bands_Mesh_Y,
      Patches,
      Horizon_X,
      Horizon_Y,
      Chessboard,
      Contours,
      Histogram_1,
      Histogram_2,
      Scatter_Boxes,
      Scatter_Boxes_Riser,
      Scatter_Spheres,
      Scatter_Spheres_Riser,
      Scatter_Prism4,
      Scatter_Prism8,
      Scatter_Prism16,
      Scatter_Triangles,
      Scatter_Quads,
      Scatter_Cone4,
      Scatter_Cone4D,
      Scatter_Cone8,
      Scatter_Cone16
    };

    int Three_Dim_Surface_Shape,
        Three_Dim_Scatter_Shape,
        Three_Dim_CplxSurface_Shape,
        Three_Dim_Surface_StrideX,
        Three_Dim_Surface_StrideY,
        Three_Dim_CplxSurface_StrideX,
        Three_Dim_CplxSurface_StrideY;

    MpViewSurface3Data (void);
};


//-----------------------------------------------------------------------------//
// class declarations
//-----------------------------------------------------------------------------//

class MpView;                   // hold all data
class MpViewDisplay;            // display frame and graphical user interface

//-----------------------------------------------------------------------------//
// class MpViewGraphData
// hold all information about data and layout of one graph
//-----------------------------------------------------------------------------//

class MpViewGraphData: public MpViewColormapLegendData,
                       public MpViewAxisData,
                       public MpViewAppearanceData,
                       public MpViewPortData,
                       public MpViewPort2Data, 
                       public MpViewContour2Data,
                       public MpViewMesh2Data,
                       public MpViewPort3Data,
                       public MpViewDots3Data,
                       public MpViewScatter3Data,
                       public MpViewScatter4Data,
                       public MpViewSlicePlotData,
                       public MpViewIsosurfaceData,
                       public MpViewMarkerData,
                       public MpViewStackingData,
                       public MpViewLambert2Data,
                       public MpViewSurface3Data,
                       public MpViewProject3Data
{
  public:

    MpView *view;                       // pointer to parent class
    int    iset;                        // index of represented data set 
    MpViewDataSet& DS (void);           // return reference to linked dataset
    bool  show;                         // true if graph is drawn

    int plotdim;                        // dimension of representation 
    enum {                              // enums for plotdim
      No_Plot = 0,                      // means don't draw this graph
      One_Dim_Plot = 1,                 // 1D is NOT IMPLEMENTED
      Two_Dim_Plot = 2, 
      Three_Dim_Plot = 3,
      Four_Dim_Plot = 4
    };

    int plotype2d,                      // 2D plot types   
        plotype3d,                      // 3D plot types
        plotype4d;                      // 4D plot types
    enum {                              // enums for plot types
      Two_Dim_Contour_Bezier_Plot   = 200,
      Two_Dim_Contour_BSpline_Plot,
      Two_Dim_Contour_Linear_Plot,
      Two_Dim_Contour_Cubic_Fill_Plot,
      Two_Dim_Contour_Cubic_Fill_Line_Plot,
      Two_Dim_Density_Plot,
      Two_Dim_Image_Linear_Plot,
      Two_Dim_Image_Linear_Diffusive_Plot,
      Two_Dim_Image_Linear_Ordered_Plot,
      Two_Dim_Image_Linear_Coarse_Plot,
      Two_Dim_Image_Bezier_Plot,
      Two_Dim_Image_Bezier_Diffusive_Plot,
      Two_Dim_Image_Bezier_Ordered_Plot,
      Two_Dim_Image_Bezier_Coarse_Plot,
      Two_Dim_Field_Abs_Plot,
      Two_Dim_Field_Phase_Plot,
      Two_Dim_Field_Thick_Plot,
      Two_Dim_Lambert_Plot,
      Two_Dim_Box_Plot_Squares,
      Two_Dim_Box_Plot_Circles,
      Two_Dim_Density_Checkerboard,
      Three_Dim_Surface_Plot       = 300, 
      Three_Dim_Complex_Surface_Plot, 
      Three_Dim_Contour_Plot, 
      Three_Dim_Dots_Plot, 
      Three_Dim_Poles_Plot, 
      Three_Dim_Scatter_Plot, 
      Three_Dim_Project_Plot,  
      Four_Dim_Contour_Plot        = 400, 
      Four_Dim_Scatter_Plot,
      Four_Dim_Slice_Plot
    };

    int Three_Dim_Contour_Shape;
    enum {                              // enums for 3d contour shapes
      Contour_Bezier,
      Contour_BSpline,
      Contour_Linear
    };
    int Three_Dim_Contour_Number;

  
    int Three_Dim_CplxSurf_Mapping;
    int complex_representation; 
    enum {                              // enums for cplx representation
      Cplx_Norm,
      Cplx_Modulus, 
      Cplx_RealPart, 
      Cplx_ImaginaryPart, 
      Cplx_Phase_2PI
    };

    // additional layout data
    ColorMap           theColorMap;     // the colormap    
    double             ColorMapMin, ColorMapMax; // mapping range
    bool               ColorAutoMap;

    Vector             mx,my,mz;        // the marker (points in 3D)

    float patch_rel_size;               // size of surface patches/cone/...

    bool fixed_lights,                  // fixed lights (in camera coord. system)
         UseTopologicalSort,            // toggle for topological sort
         FlipOrientation;               // toggle for reversal of orientation

    MpViewLabelList LabelList;          // annotations of graph

    //-------------------------------------------------------------------//
    // member functions
    //-------------------------------------------------------------------//

    // in "mpview2draw.cpp"
    void Draw_2D_Aux (Scene& scene, Matrix& Z, int type, 
                      float X1, float X2, float Y1, float Y2,
                      const char* xtitle, const char* ytitle,
                      int flags_2D, float stack_height, 
                      MpAxis* AX, const Trafo& P);

    // in "mpviewscatter.cpp"
    int ScatterBoxPlot4D (Scene& scene, const MpMatrix3d<double> &M3d, 
                          const ColorMap& cmap, const ColorB &defcol);
  
    // in "mpviewdrawaxis.cpp"
    void AxisFrame3D (Scene& scene,
                      float X1,float X2,float Y1,float Y2,float z1,float z2,
                      float xlo,float xhi,float ylo,float yhi,float zlo,float zhi);
    void AxisFrame2D (Scene& scene,
                      double xlo, double xhi, double ylo, double yhi,
                      double x1, double x2, const char* xtitle,
                      double y1, double y2, const char* ytitle,
                      MpAxis* A);

    void DrawBox (Scene& scene, int front,        // draw 3D frame and walls
                  float X1, float X2, float Y1, 
                  float Y2, float z1, float z2, 
                  ColorMap &theColorMap);

    void DrawPedestal (Scene& scene, int front, 
                       Matrix& Z, const Trafo& P, float z1, ColorMap &theColorMap);

    void Draw_Markers (Scene& scene, int mode_3D,
                       Vector& x, Vector& y, Vector& z,
                       float X1, float X2, float Y1, float Y2,
                       const Trafo& P, Matrix& Z);

    void DrawPolesPlot (Scene& scene, const Matrix& Z, const Trafo& P);

    // main drawing functions
    void Draw_Graph (Scene &scene);    
    void Draw_2D (Scene &scene);
    void Draw_3D (Scene &scene);
    void Draw_3D_Projected (Scene &scene);
    void Draw_3D_XYZ (Scene &scene);
    void Draw_4D (Scene &scene);
    void Draw_Scene (Scene &scene);

    // constructor and destructor
    MpViewGraphData (void);
   ~MpViewGraphData (void);
    void RemoveGraph (void);
};

//-----------------------------------------------------------------------------//
// class MpViewPackData: overall graph layout data
//-----------------------------------------------------------------------------//

class MpViewPackData
{
   private:
    int    PackColNum,        // num of colums for auto arrangement
           PackRowNum,        // num of rows for auto arrangement
           PackVertSpace,     // vert/horiz space between graphs (0-100%)
           PackHorizSpace,
           PackLeftMargin,    // top/left margin of graphs (0-100%)
           PackTopMargin,
           PackMode;          // arrangement mode 
  protected:
    // for internal use only
    void SetGraphPackingModeRowsCols (int mode, int rows, int cols) {
      PackMode = mode;
      PackRowNum = rows;
      PackColNum = cols;
    }

  public:
    // packing modes: can be combined by or-ing, e.g. "PackAuto | PackVert"
    enum { PackHoriz = 0x0,   // row order
           PackVert  = 0x1,   // colum order
           PackAuto  = 0x2 }; // guess automatic col/row number
 
    MpViewPackData (void);

    // Get packing mode, rows, and columns.
    int GetGraphPackingMode (void) const { return PackMode; }
    int GetGraphPackingRows (void) const { return PackRowNum; }
    int GetGraphPackingCols (void) const { return PackColNum; }

    // Setting of packing mode, rows, and columns is done by 
    // the member function MpView::SetGraphPacking(). This function sets
    // the values and immediately arranges all graphs.

    // Set/get top and left margins of graphs for auto-arangement.
    // The values are given as a percentage of the total size (0-100).
    void SetGraphPackingMargins (int top, int left) {
      PackTopMargin = top;
      PackLeftMargin = left;
    }
    int GetGraphPackingLeftMargin (void) const { return PackLeftMargin; }
    int GetGraphPackingTopMargin (void) const { return PackTopMargin; }

    // Set/get vertival and horizontal space between graphs for auto-arangement
    // The values are given as a percentage of the total size (0-100).
    void SetGraphPackingSpaces (int vert, int horiz) {
      PackVertSpace = vert;
      PackHorizSpace = horiz;
    }
    int GetGraphPackingVertSpace (void) const { return PackVertSpace; }
    int GetGraphPackingHorizSpace (void) const { return PackHorizSpace; }
};

//-----------------------------------------------------------------------------//
// class MpViewOptionData: various options
//-----------------------------------------------------------------------------//

class MpViewOptionData
{
  friend class MpViewOptions;
  public:
    int  LastTip;               // index of last tip  
    static int  CheckboxStyle;  // (MpToggleButton::RoundLED,CheckBox,...)
  protected:
    enum { default_screen_size = 640 };
    static bool MessageBell;    // ring bell if message window pups up
    bool CheckboxLED;           // LED checkbox style
    bool ShowTips;              // show the tooltips
    bool ShowTipsAnimation;     // show the tooltips animation
    bool SplashImages;          // show the startup splash images
    int  super_sampling;        // super sammpling level
    Pixel2D  screen_size;       // the size of the window on the screen
    bool SingleClickMode;       // fast single click mode for list boxes
    bool QuitConfirm;           // confirmation of quit button press
    bool AcceptClose;           // always close panel when accept button is pressed
    bool AcceptDraw;            // always redraw when accept button is pressed
    int  Language;              // language selection (english-german)
    int  GUIcolor;              // GUI color code
    bool ButtonHighlighting;    // highlight buttons if pointer is over
    string ImportDir,           // default paths for browsing       
           SaveDir,
           ExportDir,
           ContourDir,
           BackgroundsDir,
           ColormapsDir;        // -- not yet used --
    string BrowserCommand;      // browser call string

 public:   
    // constructor
    MpViewOptionData (void); 

    void SaveSession (void);
    void LoadSession (void);
    bool ParseSession (string &error);
    void SetGuiColors (int col);

    // If argument is true show tool tips on startup
    void SetShowTips (bool x) { ShowTips = x; }
    bool GetShowTips (void) const { return ShowTips; }

    // If argument is true activate animation of tool tips
    void SetShowTipsAnimation (bool x) { ShowTipsAnimation = x; }
    bool GetShowTipsAnimation (void) const { return ShowTipsAnimation; }

    // If argument is true show the startup splash images
    void SetShowSplashImages (bool x) { SplashImages = x; }
    bool GetShowSplashImages (void) const { return SplashImages; }

    // Improve the qualitiy of the preview and exported raster images 
    // by using anti-aliasing. If the argument is greater 1 super-sampling 
    // is performed (removing zig-zaged contours of the objects. Usually 
    // a value of 2 or 3 is good. Set to 1 to switch off anti-aliasing.
    void SetAntiAliasingLevel (int x) { super_sampling = x; }
    int GetAntiAliasingLevel  (void) const { return super_sampling; }

    // If argument is true switch to fast single click mode,
    // e.g. for list boxes (no tedious double click)
    void SetSingleClickMode (bool x) { SingleClickMode = x; }
    bool GetSingleClickMode (void) const { return SingleClickMode; }

    // If argument is true get confirmation for quit button press
    void SetQuitConfirm (bool x) { QuitConfirm = x; }
    bool GetQuitConfirm (void) const { return QuitConfirm; }

    // If argument is true close panel when accept button is pressed
    void SetAcceptClose (bool x) { AcceptClose = x; }
    bool GetAcceptClose (void) const { return AcceptClose; }

    // If argument is true redraw when accept button is pressed
    void SetAcceptDraw (bool x) { AcceptDraw  = x; }
    bool GetAcceptDraw (void) const { return AcceptDraw; }
    
    // Set GUI color palette (currently available = 0,1,...,15)
    void SetGUIcolor (int x) { GUIcolor = x; }
    int GetGUIcolor (void) const { return GUIcolor ; }

    // Set language of help texts: 0=English, 1=German
    void SetLanguage (int x) { Language = x; }
    int GetLanguage (void) const { return Language; }

    // Set the pixel resolution of the tool window
    void SetWindowSize (const Pixel2D &pix) { screen_size = pix; }
    Pixel2D GetWindowSize (void) const { return screen_size; }

    // If argument is true highlight buttons if the pointer is over the button
    void SetButtonHighlighting (bool x) { ButtonHighlighting = x; }
    bool GetButtonHighlighting  (void) const { return ButtonHighlighting; }
    
    // If argument is true an acoustic signal is given if a message dialog pops up
    void SetMessageBell (bool x) { MessageBell = x; }
    bool GetMessageBell (void) const  { return MessageBell; }

    void SetCheckboxLED (bool x) { CheckboxLED = x; }
    bool GetCheckboxLED  (void) const { return CheckboxStyle; }

    // set default directory paths for import,export,save,contours,
    // backgrounds,color maps
    void SetImportDirPath (const string &dir) { ImportDir = dir; }
    string GetImportDirPath (void) const { return ImportDir; }
    void SetSaveDirPath (const string &dir) { SaveDir = dir; }
    string GetSaveDirPath (void) const { return SaveDir; }
    void SetExportDirPath (const string &dir) { ExportDir = dir; }
    string GetExportDirPath (void) const { return ExportDir; }
    void SetContourDirPath (const string &dir) { ContourDir = dir; }
    string GetContourDirPath (void) const { return ContourDir; }
    void SetBackgroundDirPath (const string &dir) { BackgroundsDir = dir; }
    string GetBackgroundDirPath (void) const { return BackgroundsDir; }
    void SetColormapDirPath (const string &dir) { ColormapsDir = dir; }
    string GetColormapDirPath (void) const { return ColormapsDir; }

    // set HTML browser call string for online help
    void SetBrowserCommand (const string &cmd) { BrowserCommand = cmd; }
    string GetBrowserCommand (void) const { return BrowserCommand; }
};


//-----------------------------------------------------------------------------//
// class MpView:
// the top level viewer class
//-----------------------------------------------------------------------------//

// map of graph data with positive integer valued index
typedef map<int,MpViewGraphData> MpViewGraphMap;

// map of data sets with positive integer valued index
typedef map<int,MpViewDataSet> MpViewDataSetMap;

class MpView: public MpViewExportData,
              public MpViewImportData,
              public MpViewBackgroundData,
              public MpViewKrigingData,  // tbd. remove!
              public MpViewShepard2Data, // tbd. remove!
              public MpViewShepard3Data, // tbd. remove!
              public MpViewOptionData,
              public MpViewPackData,
              public MpContextSave
{
  friend class MpViewDisplay;
  friend class MpViewDataSet;
  friend class MpViewSelectGraph;  // in Viewer/mpviewdisplay.cpp
  friend class MpViewSelectSet;    // in Viewer/mpviewdisplay.cpp
  friend class GraphList;          // in Viewer/mpviewgraphpanel.cpp
  friend class MpViewImport;
  friend class MpViewExport;

  private:

    MpViewDataSetMap DataSets;  // map containing all data sets
                                // the index is an integer >= 1
    MpViewGraphMap   Graphs;    // map containing all graphs
                                // the index is an integer >= 1

    int agi;                    // index of active graph
    MpViewGraphData *agp;       // pointer to active graph
    void DefineGraphContext (int i);
    void DefineViewContext (void);    
    void DefineDataSetContext (int i);

    bool image_is_dirty;    
    MpImage  super_image;       // internal image for super-sampling
    Scene*   scene;             // pointer to current scene (mapped to image)
    MpImage* image;             // pointer to current image
    string   xmv_version;       // version of read xmv file

  public:

    MpViewDisplay *display;     // don't touch! pointer to image display panel
    bool raster_image;          // don't touch! is true if pixel based rendering is selected

    static const char *Version;     // version string in the form "2.7.2"
    static const char *MatpackHome; // environment variable for home directory    
                                    // value = "MATPACK"
    // constructor and destructor
    MpView (void);
   ~MpView (void);

    // Check if graph with index i exists
    bool GraphExists (int i) const { return  (Graphs.find(i) != Graphs.end()); }
   
    // Check if data set with index i exists
    bool DataSetExists (int i) const { return (DataSets.find(i) != DataSets.end()); }

    // Check if data set linked to active graph exists
    bool ActiveDataSetExists (void) const { return (DataSets.find(agp->iset) != DataSets.end()); }

    // Add a new graph and make this graph the active graph.
    // Returns the index of the newly added graph.
    int AddNewGraph (void);

    // Add a new graph with index "grf", make this graph the active
    // graph, and return the index of the newly added graph.
    // If the graph exists already just the index is returned. If the 
    // argument is not positive the next free positive graph index is used.
    int AddNewGraph (int grf);

    // Return reference to graph with index "grf". If the graph doesn't exist
    // it is created. If the argument is not positive the next free positive
    // graph index is used and "grf" is changed correspondingly.
    // The active graph setting is not changed.
    MpViewGraphData& GD (int &grf);

    // If graph i exists makes it the active graph and returns true.
    // Returns false if the graphs does not exist.
    bool SetActiveGraph (int grf);

    // Return the index of the active graph.
    int GetActiveGraph (void) const { return agi; }
  
    // Return a pointer to the active graph.
    MpViewGraphData* GetActiveGraphPtr (void) const { return agp; }

    bool MoveUpActiveGraph (void);
    bool MoveDownActiveGraph (void);

    // Add a new data set and return the index of the new data set
    int AddNewDataSet (void);

    // Return reference to data set with index "set". If the data set doesn't exist
    // it is created. If the set argument is not positive the next free positive
    // index is used and "set" is changed correspondingly.  
    MpViewDataSet& DS (int &set);

    // Link data set to graph. If the set or the graph does not exist
    // false is returned.
    bool LinkDataSetToGraph (int set, int graph);

    // Return true if graph with index "graph" is not empty and will be drawn
    bool IsDrawableGraph (int graph); 

    // Return reference to dataset linked to k-th graph. Make sure that graph and data set exist!
    MpViewDataSet& GDS (int k); 

    // Return reference to dataset linked to current graph. Make sure that graph and data set exist!
    MpViewDataSet& GDS (void);
   
    // Remove all graphs
    void RemoveAllGraphs (void);

    // Remove the active graph
    void RemoveActiveGraph (void);

    // Pass a command to the system shell (/bin/sh)
    // Unix usually returns:
    //    127 shell cannot be executed
    //    -1  error in command
    //     0  success
    int SystemCall (const string &command);

    // Decompress a file if a valid extension indicating a compression is 
    // recognized. The input file name is given by 'FileName'.
    // The original file is not modified, but a temporary file with decompressed 
    // data is created in the directory 'TempDirectory'.
    // Returns true if a decompressed file has been created, false otherwise. 
    // The path to the temporary file is returned in 'DecompressedTempFileName'. 
    // If no decompression is performed then the file name returned in 
    // 'DecompressedTempFileName' is identical to 'FileName'.
    bool AutoDecompressFile (const string &FileName, 
                             const string &TempDirectory,
                             string &DecompressedTempFileName);

    // Parse configuration file "$HOME/.xmatrix"
    bool ParseOptions (string &error);

    void SetAntiAliasing (int supersamp, Pixel2D size);  // set AA method

    // Arrange all visible graphs in rows and columns.
    // If the flag MpViewPackData::PackAuto is set in the mode field the number
    // of rows and columns is determined automaticlly (the rows and columns 
    // aruments are both ignored). If the mode flag MpViewPackData::PackVert
    // is set then the graphs are arranged in column order, otherwise 
    // they are arranged in row order (default, or use MpViewPackData::PackHoriz).
    // If the flag MpViewPackData::PackAuto is not set set then either the row 
    // or the column number is used depending on whether column or row order is
    // selected in the mode field.
    void SetGraphPacking (int mode, int rows=2, int cols=2);

    // Initialization routines for 3d viewport
    void DefaultViewForMatrix   (MpViewGraphData *G);
    void DefaultViewForMatrix3d (MpViewGraphData *G);
    void DefaultViewForXYZSet   (MpViewGraphData *G);
    void DefaultViewForScene    (MpViewGraphData *G);

    // Initialization for a newly loaded data set
    void NewMatrix (MpViewGraphData *G);
    void NewComplexMatrix (MpViewGraphData *G, const ComplexMatrix &C);
    void NewXYZSet (MpViewGraphData *G);
    void NewVolume (MpViewGraphData *G);
    void NewScene (MpViewGraphData *G);
    void NewDataSet (int dataset_index, int graph_index = -1);

    // Draw the visualization
    void Render (void);

    // Setup interactive display. The option files ".xmatrix", ".xmatrix-session"
    // are read if ReadOptions = true
    void CreateViewer (bool ReadOptions = true);

    // Destroy interactive display
    void DestroyViewer (void);

    // Call the window event handler
    void EventLoop (void);

    // context save/restore
    bool SaveVisualization (ostream &os);
    bool LoadVisualization (istream &is);
    bool SaveGraph (ostream &os, int i);
    bool SaveDataSet (ostream &os, int i);
    int FindModifiedDataSet (void);

    // check if file exists
    static bool FileExists (const string &name);
};

//-----------------------------------------------------------------------------//
// class declarations for panels
//-----------------------------------------------------------------------------//

class MpScrollImageWindow;
class MpPulldownMenu;
class MpButton;
class MpPushButton;

class MpViewStatusDisplay;
class MpViewImport;
class MpViewExport;
class MpViewSave;
class MpViewOptions;
class MpViewLinkageSelector;
class MpViewTips;
class MpViewLabel;

class MpViewColormap;

class MpViewArray2dTrafo;
class MpViewArray2dRegrid;
class MpViewArray2dEval;

class MpViewArray3dTrafo;
class MpViewArray3dRegrid;
class MpViewArray3dEval;
class MpViewArray3dSlice;
class MpViewParametricSurface;
class MpViewComplexTrafo;
class MpViewXYZTrafo;
class MpViewPort2D;    
class MpView2DPlots;

class MpViewAxis;
class MpViewPort3D;
class MpView3DPlots;
class MpView4DPlots;
class MpViewXYZMarker;
class MpViewScatterPlots;
class MpViewInfo;
class MpViewGraphPanel;
class MpViewAppearance;
class MpViewCalculator;
class MpViewFont;
class MpViewFundamentalConstants;
class MpProgressMeter;

class MpViewDataPeeker;
class MpNumex;

//----------------------------------------------------------------------------//
// class MpViewConst:
// defines constants for button sizes, etc...
//----------------------------------------------------------------------------//

class MpViewConst 
{
  public:
    int BW,BH,BO,HO,VO,MBW,MBW2,MBH;
    MpViewConst (void);
};

//----------------------------------------------------------------------------//
// class MpViewDisplay:
// the main window with image display and menu bars
//----------------------------------------------------------------------------//


class MpViewDisplay: public MpFrame, public MpViewConst 
{
  friend class MpView;

  private:
    static char buf[256];

    MpButton *info_button, *save_button, *import_button, *export_button;
    bool startup;
    // overload the polling handler, called if polling is active
    virtual void PollingHandler (void);

    void PopupXaxisPanel (void);
    void PopupYaxisPanel (void);
    void PopupZaxisPanel (void);
  public:
    // hook functions for picking and dragging
    typedef void (BPressHookFunction) (MpViewDisplay *disp, void *hookwin, 
                                       XButtonEvent ev);
    typedef void (BMotionHookFunction) (MpViewDisplay *disp, void *hookwin, 
                                       XMotionEvent ev);
  private:
    void *BHookWindow, *PreviousBHookWindow;
    BPressHookFunction  *BPressHook, *PreviousBPressHook;
    BMotionHookFunction *BMotionHook, *PreviousBMotionHook;

  public:
    void Hook_Button (void *BHookWindow, BPressHookFunction *BPressHook,
                      BMotionHookFunction *BMotionHook);
    void Unhook_Button (void);

    int disp_w,disp_h,disp_x,disp_y,disp_bw,disp_sw, 
        mbar_w,mbar_h,mbar_x,mbar_y,ibar_x,ibar_y,
        sbar_w,sbar_h,sbar_x,sbar_y, bh;

    MpView *view;                       // holds all data

    MpScrollImageWindow  *Display;      // the image display area

    MpCanvas             *MenuBar;      // top menu bar
    MpCanvas             *SideBar;      // side icon bar
    MpCanvas             *InfoBar;      // bottom info bar

    MpPulldownMenu       *LocalMenu,    // local pulldown menu
                         *FileSubMenu,  // and submenus
                         *ToolSubMenu,
                         *Plot2DSubMenu,
                         *Plot3DSubMenu,
                         *LayoutSubMenu,
                         *Volume3DSubMenu,
                         *TrafoSubMenu,
                         *ResolutionSubMenu;

    MpPulldownMenu* MakeResolutionMenu (void); // resolution submenu

    MpViewStatusDisplay  *StatusDisplay;
    MpViewImport         *Import;
    MpViewExport         *Export;
    MpViewSave           *Save;
    MpViewTips           *Tip;
    MpViewLinkageSelector*SelectGraphSet;
    MpViewOptions        *OptionPanel;
    MpViewLabel          *LabelPanel;
    MpViewColormap       *ColormapPanel;

    MpViewArray2dTrafo   *Array2dTrafoPanel;    // 2d data arrays
    MpViewArray2dRegrid  *Array2dRegridPanel;
    MpViewArray2dEval    *Array2dEvalPanel;

    MpViewArray3dTrafo   *Array3dTrafoPanel;    // 3d data arrays
    MpViewArray3dRegrid  *Array3dRegridPanel;
    MpViewArray3dEval    *Array3dEvalPanel;
    MpViewArray3dSlice   *Array3dSlicePanel;

    MpViewParametricSurface *ParametricSurfacePanel;
    MpViewComplexTrafo   *ComplexPanel;
    MpViewPort2D         *Viewport2DPanel;
    MpViewPort3D         *Viewport3DPanel;
    MpViewXYZTrafo       *XYZPanel;
    MpViewAxis           *AxisPanel;

    MpView2DPlots        *Plots2D;
    MpView3DPlots        *Plots3D;
    MpView4DPlots        *Plots4D;
    MpViewXYZMarker      *MarkerXYZ;
    MpViewScatterPlots   *PlotsScatter;
    MpViewGraphPanel     *GraphPanel;
    MpViewAppearance     *Appearance;
    MpViewCalculator     *CalculatorFrame;

    MpViewInfo           *Info;
    MpViewFont           *FontPreview;
    MpViewFundamentalConstants *FundamentalConstants;

    MpProgressMeter      *Gauge;        // a progress meter
    MpViewDataPeeker     *DataPeeker;
    MpPushButton         *data_peeker_button;

    MpNumex              *Numex; // numerical expression parser

  protected:
    virtual void BPress_CB    (XButtonEvent ev); 
    virtual void BRelease_CB  (XButtonEvent ev); 
    virtual void Motion_CB    (XMotionEvent ev); 
    virtual void ClientMsg_CB (XClientMessageEvent ev);

  public:
    MpViewDisplay (MpView* view, MpImage& image, int w, int h);
    virtual ~MpViewDisplay (void);
    
    virtual void Resize (int w, int h);

    void SetWaitCursor   (void);
    void UnsetWaitCursor (void);

    void EnglishGermanHelp (void);       // toggle English or German help texts
    void SetResolution (Pixel2D resol);  // set screen image resolution
    void Update (void);                  // update panels if graph changed
    void UpdateLinkageSelector (void);   // update graph-set-linkage selector

    // utilities
    static void Message (const string &message);
    static bool ConfirmDialog (const string &title, const string &question);
    static bool ConfirmOverwriteFile (const string &name);
    static const string ToString (int val);
    static const string ToString (double val, int prec = 15);
    static const string ToString (float val, int prec = 6);

    // low-level auxilliary methods
    int FindGraphAtPosition(int x, int y) const;
    int ScrollWindowShiftX(void) const;
    int ScrollWindowShiftY(void) const;
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
