/*-----------------------------------------------------------------------------*\
| Matpack X windows application programming interface include        mpwindow.h |
|                                                                               |
| Last change: Nov 12, 2005                                                     |
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

#ifndef _MPWINDOW_H_
#define _MPWINDOW_H_

//-----------------------------------------------------------------------------//

// undefine for debugging output
//#define DEBUG
//#define DEBUG_DESTRUCTORS
//#define DEBUG_CONSTRUCTORS
//#define DEBUG_EVENTS

//-----------------------------------------------------------------------------//
// Matpack includes 
//-----------------------------------------------------------------------------//

#include "mpbase.h"
#include "mpimage.h"       // image manipulation class
#include "mpcolor.h"       // color management 
#include "mpcursor.h"      // curser management class
#include "mpstack.h"       // simple stack template class
#include "mprectangle.h"   // rectangle math
#include "mptimerqueue.h"  // interval timer management

//-----------------------------------------------------------------------------//
// the X11 and other neccessary includes 
//-----------------------------------------------------------------------------//

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

// undefine True and False from X11 - use bool values: true, false
#undef True     
#undef False

//-----------------------------------------------------------------------------//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>

// include STL definitions
#include <list>
#include <map>
#include <string>

//-----------------------------------------------------------------------------//
// byte type used
//-----------------------------------------------------------------------------//

namespace MATPACK {
using std::map;
using std::string;
using std::list;

typedef unsigned char byte;

//-----------------------------------------------------------------------------//
// class definitions
//-----------------------------------------------------------------------------//

class MpGlobal;
class MpWindow;                         // base class for all window types
class MpButton;
class MpFrame;                          // main window with event loop
class MpPulldownButton;                 // button with menu attached

//-----------------------------------------------------------------------------//
// struct MpWindowList: child list of all windows
//-----------------------------------------------------------------------------//

struct MpWindowList 
{ 
  MpWindow *child; 
  int x,y;
  struct MpWindowList *next; 
};

//-----------------------------------------------------------------------------//
// class MpWindow
//-----------------------------------------------------------------------------//

class MpWindow : public MpBase,          // inherit the basic definitions
                 public MpTimerInterface // inherit the interval timer interface
{
  friend class MpGlobal;
  friend class MpFrame;

  private:
    MpWindow (const MpWindow&) { }              // no copying allowed
    MpWindow& operator = (const MpWindow&) { return *this; }  // no assignment allowed
    int width_, height_;        // width and height of this window

    const MpColor *background_color;

    Window xwin;                // identifier of the X window structure
    MpCursor cursor;            // cursor for this window
    bool hidden;                // if true do not map the window 
    long EventMask;             // mask for XSelectInput
    int border_width;           // border width of window

    virtual void TimerEvent (MpTimerInfo *info);  // timer is expired

  protected:
    MpWindow (void) { }         // constructor for root window

    virtual string Tr(const char* text); // translator - NOT YET

    virtual void AddChild (MpWindow *) {}                // fit the parent geometry

    virtual void EventDispatcher (XEvent &event);        // event dispatcher

    // define windows event filter: If filter returns true then the event is not
    // passed to the windows event dispatcher. Otherwise, if the filter returns false
    // the event is processed as usual.
    virtual bool EventFilter     (MpWindow* target, XEvent &event); 

    // callback functions for events
    virtual void BPress_CB       (XButtonEvent) {}       // any button press
    virtual void BRelease_CB     (XButtonEvent) {}       // any button release
    virtual void BDoubleClick_CB (XButtonEvent) {}       // double click
    virtual void MouseWheel_CB   (XButtonEvent,int) {}   // wheel rotation
    virtual void Enter_CB        (XCrossingEvent) {}     // enter a window
    virtual void Leave_CB        (XCrossingEvent) {}     // leave a window
    virtual void Motion_CB       (XMotionEvent) {}       // pointer movements
    virtual void Expose_CB       (XExposeEvent);         // window expose
    virtual void KeyPress_CB     (XKeyEvent) {}          // key press
    virtual void Configure_CB    (XConfigureEvent) {}    // only MpFrames
    virtual void ClientMsg_CB    (XClientMessageEvent) {}// message from winmanager
    virtual void Selection_CB    (XSelectionEvent) {}    // selection 
    virtual void SelectionClear_CB   (XSelectionClearEvent) {}
    virtual void SelectionRequest_CB (XSelectionRequestEvent) {}
    virtual bool GUIColorChange_CB (void) { return false; } // GUI colors changed
    virtual void TimerExpired_CB (MpTimerInfo*) {}

  public:

    Window Win (void) const { return xwin; }   // return identifier of X window structure

    GC DrawGC,                  // current GC for drawing
       TextGC;                  // current GC for text writing

    MpWindow *parentw;          // pointer to the parent
    MpFrame* MainWindow;        // main window of this window, direct child of root 
    MpWindowList* children;     // list of children
    int type;                   // to distinguish simple <-> pulldown window

    // constructor for general window
    MpWindow (MpWindow& parent,
              int w = 0, int h = 0, int x = 0, int y = 0, int border_width = 0);
    virtual ~MpWindow (void);

    // return width and height of window in units of pixel
    int Width  (void) const { return width_; }
    int Height (void) const { return height_; }    

    //-------------------------------------------------------------------------//
    // Member functions:
    //   void AddEventMask (long event_mask)
    //   void RemoveEventMask (long event_mask)
    //   long GetEventMask (void) const
    //
    // Description:
    //   Add/remove mask for events the window will be able to receive.
    //   All X11 event masks can be used. The change is not immediately 
    //   effective. You have to call either MpWindow::Realize() to activate 
    //   the new event setting (the window is also mapped by this method)
    //   or to call XSelectInput(Mp.theDisplay, Win(), GetEventMask())
    //   to activate the events without mapping the window.
    //   But usually you will set the event mask in the constructor of your
    //   derived class before mapping. Hence, you don't have to activate
    //   the changed events explicitely, because Realize() is called 
    //   automatically when your window is displayed the first time.
    //-------------------------------------------------------------------------//
    void AddEventMask    (long event_mask) { EventMask |=  event_mask; }
    void RemoveEventMask (long event_mask) { EventMask &= ~event_mask; }

    // returns current event mask setting
    long GetEventMask (void) const { return EventMask; }

    // for internal use only : set width and height. Sets variables only, but doesn't
    // realy resize window. Use Configure() and Resize() methods instead.
    int SetWidth  (int w) { width_  = w; return w; }
    int SetHeight (int h) { height_ = h; return h; }
    void SetSize (int w, int h) { width_ = w; height_ = h; }

    // virtual functions that can be overloaded
    virtual void DrawWhenMapped (void) { }                // called by Map()
    virtual void Clear (void);                            // clear window
    virtual int  EffectiveWidth (void) { return Width(); }// width without pictures
    virtual void DrawLine (int x0, int y0, int x1, int y1, GC gc);// draw line
    virtual void DrawPoint (int x, int y);                // draw point
    virtual void Move (int, int);                         // move this
    virtual void Configure (int w, int h);                // resize this
    virtual void Configure (int w, int h, int x, int y);  // resize and move this
    virtual void Redraw (void) { }                        // redraw the window
    virtual void ResizeChildren (int,int);
    virtual void Resize (int, int);                       // resize this+all children
    virtual void SetLanguage (const char **) { }          // language change 

    // action for windows, that are managed from MpRadioButton callbacks
    virtual void Action (const char*, const char*, void* = 0) { }    
    
    // non-virtual functions
    void SetBackingStore (bool);// set backing store to "WhenMapped"
    bool GetBackingStore (void) const;

    void SetSaveUnder (bool);   // save covered region when mapped
    bool GetSaveUnder (void) const;

    void SetDecoration (bool);  // window manager decoration
    bool GetDecoration (void) const;

    void SetMinMaxWindowSize (int wmin, int hmin, int wmax, int hmax); 

    void Realize (void);        // realize window
    void RealizeAll (void);     // realize window and child tree 

    void Map (void);            // map the window, also called by Realize()
    void Unmap (void);          // unmap the window

    void Hide (void) { hidden = true; } // don't appear if mapped, first unmap!
    void Unhide (void) { hidden = false; } // unlock the hiding
    bool IsHidden (void) { return hidden; }
    bool IsVisible (void);      // return true if visible

    // set/get windows cursor
    void SetCursor (const MpCursor &cursor);
    MpCursor GetCursor (void) const;
   
    //-------------------------------------------------------------------------//
    //  void MpWindow::PlaceText (const char* string, 
    //                                const MpRectangle<short>& rect, 
    //                                const XFontStruct* fn, 
    //                                int mode) 
    //
    // Place simple text string in a window. The text string can consist of 
    // more than one line separated by the '\n' character.
    // This function is used for button labels and other comparably 
    // simple purposes. 
    //
    // The text is drawn within the given rectangle according to the 
    // alignment settings given by the mode parameter.
    //
    // Optionally a font can be given. 
    // It defaults to Mp.theFont if omitted or set to NULL.
    //
    // The mode parameter can be composed of the text mode flags 
    //   
    //       MpLabel::(Plain, Etched, Embossed) 
    //
    // and the alignment flags defined in class MpBase
    //
    //       MpBase::(AlignHCenter, AlignLeft, AlignRight, 
    //                AlignVCenter, AlignTop,  AlignBottom, AlignBase).
    //
    //-------------------------------------------------------------------------//
    
    void PlaceText (const char* string, const MpRectangle<short>& rect, 
                    const XFontStruct* fn = 0, int mode = 0);


    //-------------------------------------------------------------------------//
    // void MpWindow::PlaceText (const char* string, 
    //                           int x = 0, int y = 0, 
    //                           const XFontStruct* fn = 0, 
    //                           int mode = 0)
    //
    // Place simple text string in a window. The text string can consist of 
    // more than one line separated by the '\n' character.
    // This function is used for button labels and other comparably 
    // simple purposes. 
    //
    // Optionally a horizontal (x) and a vertical (y) adjustment 
    // can be given . Positive or negative values for x or y, respectively,
    // are interpreted as a pixel offset from the window border. 
    //
    // Optionally a font can be given. 
    // It defaults to Mp.theFont if omitted or set to NULL.
    //
    // The mode parameter can be composed of the text mode flags 
    //   
    //       MpLabel::(Plain, Etched, Embossed) 
    //
    // and the alignment flags defined in class MpBase
    //
    //       MpBase::(AlignHCenter, AlignLeft, AlignRight, 
    //                AlignVCenter, AlignTop,  AlignBottom, AlignBase).
    //
    //-------------------------------------------------------------------------//
    void PlaceText (const char *string, int x = 0, int y = 0, 
                    const XFontStruct* fn = 0, int mode = 0);

    // set color of window background (or refresh if argument is 0)
    void SetBackground (const MpColor *color = 0);


    // get background color
    const MpColor* GetBackground (void) const { return background_color; }
};



// version, copyright, registration, and address string
extern const char *MpVersionString,
                  *MpCopyrightString,
                  *MpAddressString,
                  *MpRegistrationString;

// the matpack logo bitmap and the size control string
extern const unsigned char *MpLogoBitmapString;
extern const char          *MpLogoBitmapSizeString;

// external language tables
extern const char *MpEnglish[], 
                  *MpGerman[];


//-----------------------------------------------------------------------------//
// class MpCanvas: 
// This is a window with a frame
// practically all windows are derived from this class
//-----------------------------------------------------------------------------//

class MpCanvas : public MpWindow 
{     
  private: 
    int   FrameStyle;                   // frame style as given by enums below
    short FrameWidth,                   // width of frame
          FrameMidWidth;                // width of frame mid in box style

  protected: 
    MpCanvas (void) { }  // constructor for root window

    virtual void DrawFrame (int mode);  // canvas frame (virtual)

    virtual void RedrawFrame (void)     // frame redrawing (virtual,inline)
    {
      DrawFrame (FrameStyle);
    }

    virtual void RedrawPanel (void)     // panel redrawing (virtual,inline)
    { 
      Clear();
    }

  public:
    enum { NoFrame   = 0x0000,          // no frame
           Panel     = 0x0001,          // panel style
           Box       = 0x0002,          // box style
           BoxButton = 0x0003,          // button with box frame
           TypeMask  = 0x000f,          // mask for type field

           Flat      = 0x0010,          // flat frame (background color)
           Solid     = 0x0020,          // solid frame (darker color)
           Raised    = 0x0030,          // frame with raised shadow effect
           Sunken    = 0x0040,          // frame with sunken shadow effect
           ShadowMask= 0x00f0,          // mask for shadow field

           Enhanced  = 0x0100,          // shadow/highlight to enhance 3d effect
           Framed    = 0x0200,          // frame box or panel completely
           WinFramed = 0x0400,          // outline window (e.g. pulldown menus)
           OutlineMask=0x0f00 };        // mask for outline field

    MpCanvas (MpWindow& parent, int w, int h, int x = 0, int y = 0,
              int framestyle = Panel|Raised|Enhanced);

    int GetFrameWidth()    const { return FrameWidth; }
    int GetFrameMidWidth() const { return FrameMidWidth; }
    int GetFrameTotalWidth() const;
    int GetFrameStyle ()   const { return FrameStyle; }
    int GetFrameType ()    const { return FrameStyle & TypeMask; }
    int GetFrameShadow ()  const { return FrameStyle & ShadowMask; }
    int GetFrameOutline()  const { return FrameStyle & OutlineMask; }

    void SetFrameWidth (int width)    { FrameWidth = (short)width; }
    void SetFrameMidWidth (int width) { FrameMidWidth = (short)width; }
    void SetFrameStyle (int style)    { FrameStyle = style; }

    virtual void Redraw (void);         // redraw for callbacks (virtual)
};

//-----------------------------------------------------------------------------//
// class MpFrame:
// This is a window that can have an event loop
//-----------------------------------------------------------------------------//

class MpFrame : public MpCanvas
{
  friend class MpGlobal;
  friend class MpWindow;

  private:
    static int EventLoopLevel;            // counts nesting level of event loops

    bool polling_mode;  // some applications use polling in the EventLoop 
                        // calling the  virtual function PollingHandler()
                        // instead of XNextEvent.

    MpWindow *CallingWindow; // optional backlink stored here - unused upto now
    
  public: 
    bool ExitEventLoop,  // set to exit the main event loop
         ExitLocalLoop;  // set to exit a local event loop

    // constructor for root window
    MpFrame (void) { MainWindow = this; }

    // regular constructor
    MpFrame (const char *title, int w, int h, 
             int fix_pos = 0, int x = 0, int y = 0,
             int framestyle = MpCanvas::Flat);

    virtual ~MpFrame (void);

    virtual void Resize (int, int);     // overload Resize

    // start global or local event loop, respectively
    virtual void EventLoop();
    virtual void LocalLoop();

    // configure and client message event callbacks
    virtual void Configure_CB (XConfigureEvent ev);
    virtual void ClientMsg_CB (XClientMessageEvent ev);

    // polling mode - (default is false)
    virtual void PollingHandler (void) { }
    void SetPolling (bool mode) { polling_mode = mode; }
    bool GetPolling (void) const { return polling_mode; }

    int  GetEventLoopLevel (void) const { return EventLoopLevel; }

    void Popup (int x = -9999, int y = -9999);

    int  SetBitmapIcon (const char* icon_name, const unsigned char *ibits, 
                        int iwidth, int iheight);

    int  SetPixmapIcon (const char* icon_name, char **icon_pixmap);

    void SetTitle (const char *title);
};

//-----------------------------------------------------------------------------//
// class MpGlobal: isolates all global variables
//-----------------------------------------------------------------------------//

class MpGlobal 
{
  friend class MpFrame;
  friend class MpWindow;
  friend class MpButton;

  private:

    // table for mapping events with add and remove method
    map <unsigned long, MpWindow*> wtab; 
    void addWindow (unsigned long xwin, MpWindow* win) { wtab[xwin] = win; }
    void removeWindow (unsigned long xwin) { wtab.erase(xwin); }

    list < MpWindow* > EventFilters;        // list of event filters

    void MakeDefaultIconPixmaps (void);     // create the default pixmaps

    GC CreateGC (unsigned long mask, XGCValues * gcv);

    int theXSocket;                         // the X network socket

  public:

    MpPulldownButton *PulldownButtonGrab;       // used to redraw active pulldown button

    enum { str_max = 256,               // deprecated - don't use
           pulldown_stack_size = 128 }; // currently max pulldown menus pulled
 
    enum { Left         = 1,            // directions, e.g. for triangles
           Right        = 2, 
           Up           = 3, 
           Down         = 4 };

    enum { none = 0, vertical, horizontal }; // e.g. for slider corrugation

    enum { NormalType = 0,              // normal window
           PulldownMenuType = 1 };      // pulldown window type

    enum { FreePosition   = 0,          // window position
           FixedPosition  = 1,
           CenterPosition = 2 };


    // find MpWindow associated wih X11 Window ID xwin
    MpWindow* findWindow (unsigned long xwin) 
    {
      map<unsigned long,MpWindow*>::iterator i = wtab.find(xwin);
      return (i == wtab.end()) ? 0 : (*i).second;
    }
    
    // invoke the event dispatcher of the window
    void EventHandler (XEvent &event)
    {
      MpWindow* tW = findWindow(event.xany.window); // find window from table
      if (tW) tW->EventDispatcher(event); 
      else {                            // the window is deleted, but some events will
      }                                 // occur nevertheless, e.g. LeaveNotify, etc.
    }

    MpFrame* TopMainWindow;             // used to handle client messages 

    MpStack<MpFrame*> PulldownWindowsMapped; // list used to unmap pulldown 
                                             // window with next button release

    MpFrame       theRootWindow;        // here the constructor for the root
                                        // window is called

    MpWindow*     SelectionWindow;      // pointer to window that has selection


    // variables
    Display*      theDisplay;
    char          theDisplayName[str_max];
    unsigned      theDisplayWidth;
    unsigned      theDisplayHeight;

    Visual*       theVisual;
    unsigned      theDepth;
    int           theScreen;
    double        theXYRatio;    

    int           useColors;            // set if color visual
    int           useTrueColors;        // set if true color or direct color
    
    Window        theFocus;             // the X window 

    // basic pixmaps
    char          theIconName[str_max];
    Pixmap        theIconPixmap;
    Pixmap        theIconMaskPixmap;
    Pixmap        theWarnPixmap;        // pixmaps for dialog windows
    Pixmap        theAskPixmap;
    Pixmap        theErrorPixmap;
    Pixmap        theInfoPixmap;
    int           theDefaultIconSize;
    Pixmap        theBackPixmap;
    Colormap      theColormap;
    
    // basic colors
    static const MpColor 
                  &BlackColor,          // GUI: always black
                  &WhiteColor,          // GUI: always white
                  &CanvasColor,         // GUI: canvas background
                  &LightColor,          // GUI: canvas shade upper frame
                  &DarkColor,           // GUI: canvas shade lower frame
                  &MediumColor,         // GUI: between dark and canvas
                  &HighlightColor,      // GUI: embossed text
                  &PageColor,           // GUI: light page back color (edit field)
                  &WarningColor,        // GUI: warning color (usually yellow)
                  &TextColor;           // GUI: default text color

    void InitializeBasicColors (void);

    GC            theCanvasGC,          // GUI: standard background
                  theLightGC,           // GUI: shade upper frame
                  theDarkGC,            // GUI: shade lower frame 
                  theMediumGC,          // GUI: frame shadows
                  theBlackGC,           // GUI: frame shadows
                  thePageGC,            // GUI: light background 
                  theTextGC,            // GUI: label texts
                  theDrawGC,            // GUI: general drawing purposes
                  theCursorGC,          // GUI: cursors in edit fields
                  theRubberbandGC;      // GUI: rubber band selections

    int           usePrivateColormap;
    int           installPrivateColormap;
    Colormap      thePrivateColormap;

    byte          theRedMap[256],       // map of available colors
                  theGreenMap[256], 
                  theBlueMap[256];

    unsigned long thePixValMap[256];    // map for X pixel transformation

    int           theDirectMap[256];    // map for direct color conversion

    int           theNumberOfColors;    // number of allocated color cells
                                        // (is zero on a true color display)
    // the fonts
    XFontStruct   *theFont,             // 12pt normal text
                  *theBigFont,          // 16pt big bold for titles
                  *theFixedFont,        // 12pt fixed spacing (program lists etc.)
                  *theItFont,           // 12pt italic
                  *theBoldFont,         // 12pt bold
                  *theBoldItFont,       // 12pt bold italic
                  *theButtonFont;       // font used by buttons (usu. theBoldFont)

    // constructor and destructor
    MpGlobal (void);
   ~MpGlobal (void);
  
    // event filter installation
    void InsertEventFilter (MpWindow *win); // windows eventfilter is registered (activated)
    void EraseEventFilter (MpWindow *win);  // windows eventfilter is removed (deactivated)

    // set colors for the GUI
    void SetGUIColors (const MpColor &CanvasColor,    // widget background   
                       const MpColor &DarkColor,      // widget lower dark border 
                       const MpColor &MediumColor,    // widget frame 
                       const MpColor &LightColor,     // widget upper light border 
                       const MpColor &PageColor,      // page background     
                       const MpColor &TextColor,      // text                
                       const MpColor &HighlightColor, // text highlight/shadow
                       const MpColor &WarningColor);  // warnings            

    // functions
    void Initialize (char* disp);               // initialize and connect to X server
    void Fail (const char *message, ...);       // exit on failure
    void Warn (const char *message, ...);       // warning on failure

    // pseudo-3d frame drawing
    void Rectangle     (Window xwin,int mode, int framedepth,
                        int x,int y,int w,int h,GC gc=0);
    void Triangle      (Window xwin,int mode,int dir, int framedepth,
                        int x,int y,int w,int h,GC gc=0);

    // short forms
    void TriangleLeft  (Window xwin,int mode,int framedepth,
                        int x,int y,int w,int h,GC gc=0)
    { Triangle(xwin,mode,MpGlobal::Left,framedepth,x,y,w,h,gc); }

    void TriangleRight (Window xwin,int mode,int framedepth,
                        int x,int y,int w,int h,GC gc=0)
    { Triangle(xwin,mode,MpGlobal::Right,framedepth,x,y,w,h,gc); }

    void TriangleUp    (Window xwin,int mode,int framedepth,
                        int x,int y,int w,int h,GC gc=0)
    { Triangle(xwin,mode,MpGlobal::Up,framedepth,x,y,w,h,gc); }

    void TriangleDown  (Window xwin,int mode,int framedepth,
                        int x,int y,int w,int h,GC gc=0)
    { Triangle(xwin,mode,MpGlobal::Down,framedepth,x,y,w,h,gc); }

    
    // horizontal pseudo-3d rule
    void HRule     (Window xwin, int y, int x = 0, int w = 0);

    // pseudo-3d frame for grouping panel elements
    void GroupingFrame (Window xwin, int w, int h, int x, int y);
    void GroupingFrame (Window xwin, const char* name, int w, int h, int x, int y);

    // get text extent for given font for multi-line string
    void GetTextExtent (const char text[], const XFontStruct* font, 
                        int& width, int& height);

    // get text extent for given font for array of multi-line string
    void GetTextExtent (const char* text[], const XFontStruct* font, 
                        int& cols, int& lines, int& width, int& height, int& length);

    // auxilliaries (some C libraries crash with NULL arguments in string functions)
   
    int strlen (const char* str) 
        { return str ? ::strlen(str) : 0; } 

    int strcmp (const char* str1, const char* str2) 
        { return (str1 && str2) ? ::strcmp(str1,str2) : 0; } 
    
    char* strcpy (char *str1, const char *str2)
        { return str2 ? ::strcpy(str1,str2) : (*str1 = 0, str1); }

    char* strncpy (char *str1, const char *str2, int n)
        { return str2 ? ::strncpy(str1,str2,n) : (*str1 = 0, str1); }

    // global style definitions which can be set via X resources
    const char** Language;      // international language table (def: MpEnglish)

    short FrameWidth,           // pseudo 3d frame thickness (def: 2)
          FrameMidWidth;        // width of frame mid in box style (def: 2)
    int   FrameStyle;           // frame outline style (def: MpCanvas::Panel)

    int   BorderOffset,         // offset of panel elements form border (def: 15)
          ButtonHeight,         // height of standard button (def: 25)
          ButtonWidth,          // width of standard button (def: 80)
          ShifterWidth,         // width of shifters, scrollbar, sliders (def: 15)
          ToggleImageSize,      // size of toggle state image (def: 9)
          PulldownImageSize,    // size of pulldown arrow image (def: 9)
          RadioImageSize;       // size of radio button image (def: 9)

    char  DefaultPrinter[str_max],      // default printer command
          DefaultViewer[str_max],       // default image viewer command
          DefaultPSViewer[str_max];     // default Postscript viewer

    string Tr(const char *context, const char *text);

    // language indices and accelerator codes (order must be absolutely preserved !)
    //          !!! Deprecated feature - will be removed soon !!!
    enum {
        T_2dview, T_3dview, T_4dview,
        T_about, T_accept, T_action, T_auto,
        T_axis, T_add, T_background, T_button, T_cancel, 
        T_cell, T_clear, T_clone, T_close, T_color, T_colormap, T_confirm, 
        T_contents, T_contours, T_copy, T_cut, T_defaults, T_delete, 
        T_density, T_depth, T_device,
        T_directory, T_display, T_exitconfirm, T_drive, T_duplicate, T_edit, 
        T_exit, T_export, T_file, T_overwrite_confirm, T_filter, T_find, 
        T_flip, T_flip_horizontal,T_flip_vertical,
        T_foreground, T_format, T_frame, T_frequency, T_function,
        T_get, T_goto, T_grayscale,T_height, T_help,
        T_horizontal, T_image, T_import, T_info, T_insert, T_install, T_layout,
        T_landscape, T_legend, T_link, T_load, 
        T_mark, T_markall, T_maximum, T_minimum, T_mirror, T_monochrome, T_move, 
        T_new, T_no, T_none, T_noise, T_number, T_offset,
        T_ok, T_open, T_options, T_overwrite, 
        T_parallel, T_paste, T_pick,
        T_portrait, T_position, T_quality, T_print, T_read, T_redo, T_remove,
        T_rename, T_replace, T_resize, T_run, 
        T_save, T_saveas, T_selection, T_set, 
        T_size, T_smoothing, T_start, T_step, T_surface, T_tile, T_tools, T_undo, 
        T_undoall, 
        T_vertical, T_view, T_viewport, T_width, T_window, T_write, T_yes, T_zoom
    };

    const char* operator [] (int i) const { return Language[i]; } // language

    int  MatchOption (const char* a, const char* b, int len);
    void ParseOptions (int argc, const char *argv[], 
                       const char *application = 0);
    void ParseResources (const char *application);

    void Bell (int duration = 10);      // ring the bell
    
    // some member functions mostly for debugging purposes
    int GetNumberOfColors (void);       // number of color cells
    int GetNumberOfWindows (void);      // number of X windows

    // flush all output buffers
    void FlushDisplay (void) { XFlush(theDisplay); }

  private:

    // support double clicks
    Window LastButtonWindow;            // last window the mouse was
    Time   LastButtonPressTime;         // last button press time of mouse button
    unsigned int  LastButtonPressed;    // last button pressed
    short  LastButtonXPos,              // last pointer position
           LastButtonYPos;
    Time   DoubleClickTime;             // max click time difference [400 millisec]
    short  DoubleClickRange;            // max area for double click [5 pixel]

    // support button auto-repeat
    Time   AutoRepeatDelay;             // button auto-repeat delay    [400 millisec]
    Time   AutoRepeatInterval;          // button auto-repeat interval [100 millisec]

    // support mouse wheel
    short  MWheelResol;                 // mouse wheel resolution (default 120)

    // highlight buttons when cursor is over them
    bool   highlight_buttons;

  public:
  
    // methods for double-click control
    void  SetDoubleClickTime (Time t) { DoubleClickTime = t; };
    Time  GetDoubleClickTime (void) const { return DoubleClickTime; }
    void  SetDoubleClickRange (short r) { DoubleClickRange = r; }
    short GetDoubleClickRange (void) const { return DoubleClickRange; }

    // methods for auto-repeat control 
    void SetAutoRepeatDelay (Time t) { AutoRepeatDelay = t; }
    Time GetAutoRepeatDelay (void) const { return AutoRepeatDelay; }
    void SetAutoRepeatInterval (Time t) { AutoRepeatInterval = t; }
    Time GetAutoRepeatInterval (void) const { return AutoRepeatInterval; }

    // methods for mouse wheel control
    int  GetMouseWheelResolution (void) const { return MWheelResol; }
    void SetMouseWheelResolution (int resol) { MWheelResol = (short)resol; }

    void SetButtonHighlighting (bool val) { highlight_buttons = val; }
    bool GetButtonHighlighting (void) const { return highlight_buttons; }

  private:
     void (*CleanupFunction) (void);

  public:

    // public method to add a cleanup function called by the destructor
    void SetCleanupFunction ( void (*Cleanup) (void) );


    static void AllocateColors (Display* theDisplay, Visual* theVisual,
                                Window theWindow, 
                                int usePrivateColormap,
                                Colormap& thePrivateColormap, 
                                Colormap& theColormap,
                                byte* RedMap, byte* GreenMap, byte* BlueMap, 
                                unsigned long *PixValMap, int* theDirectMap,
                                int& theNumberOfColors);
    
    static XImage* MapImageToX (const MpImage& theImage, 
                                Display* theDisplay, Visual* theVisual, int theDepth,
                                int theNumberOfColors,
                                byte* RedMap, byte* GreenMap, byte* BlueMap, 
                                unsigned long* PixValMap,
                                unsigned long theBlackPixel, 
                                unsigned long theWhitePixel,
                                int* DirectMap);
};

//-----------------------------------------------------------------------------//
// externals
//-----------------------------------------------------------------------------//

// instance holding all global parameters for public access
extern MpGlobal Mp;

//-----------------------------------------------------------------------------//
// class MpWindowHorizontalRule:
// a class for horizontal rules in pulldown menus
//-----------------------------------------------------------------------------//

class MpWindowHorizontalRule: public MpWindow 
{
  public:
    MpWindowHorizontalRule (MpWindow &parent, int w, int x = 0, int y = 0)
        : MpWindow(parent,w,2,x,y,0) {}
    virtual void Redraw (void) 
    {
      Mp.HRule(Win(),0,0,Width());      // draw the rule
    }
    virtual void Resize (int w, int) 
    {
      MpWindow::Configure(w,Height()); // don't increase height !
    }
};

//-----------------------------------------------------------------------------//
// More prototypes
//-----------------------------------------------------------------------------//

char* MpXResource   (const char *Application, const char *Name,
                     const char *Class = "");

int MpXResourceFlag (const char *Application, const char *name, int deflt);

int MpXResourceFlag (const char *Application, const char *name, 
                     const char* value);
int MpXResourceInt  (const char *Application, const char *name, int deflt);

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
