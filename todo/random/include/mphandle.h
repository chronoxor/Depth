/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpHandle and others                   mphandle.h |
|                                                                               |
| Last change: Nov 24, 2004                                                     |
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

#ifndef _MPHANDLE_H_
#define _MPHANDLE_H_

#include "mpwindow.h"

namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpSlider: slider class for scrollbars and shifters
//-----------------------------------------------------------------------------//

class MpSlider : public MpCanvas
{
  public:
    int Corrugation; // MpGlobal::none/vertical/horizontal
    MpSlider (MpWindow &parent, int w, int h, int x, int y, 
	      int corrugation = MpGlobal::none)
      : MpCanvas(parent,w,h,x,y,Panel|Raised|Enhanced), 
	Corrugation(corrugation) { }
    virtual void RedrawFrame (void);    
};    

//-----------------------------------------------------------------------------//
// class MpScrollBarBase: base class (internal use only) for class MpScrollBar
//-----------------------------------------------------------------------------//

// scrollbar without value display which is for internal use only. If the 
// 1. constructor (without xanf) is used, the slider must explicitely be set.

class MpScrollbarBase : public MpCanvas 
{
  private:
    MpSlider *bar;

  protected:
    int sw, sh, sy, xoff, xmax, xspan, xact;

  public:
    int nticks; // the number of tick lines (def = 0)
    void SetSlider(int x); // initially set slider to x
    void init (void); // set all elements

    // 1. constructor: without initial value
    MpScrollbarBase (MpWindow &parent, int w, int h, int x, int y) :
	MpCanvas (parent,w,h,x,y,Panel|Sunken|Enhanced) 
    { init(); }

    // 2. constructor : with initial value 
    MpScrollbarBase(MpWindow &parent, int w, int h, int x, int y, int xanf) 
	: MpCanvas (parent,w,h,x,y,Panel|Sunken|Enhanced) 
    { 
	init(); 
	SetSlider(xanf);
    }
    
  protected:
    // virtual function "callbck" is called from move
    virtual void callbck(int x) { printf(" %d",x); fflush(stdout); } 
    
    void move (int x);    // move the slider
    void move_cb (int x); // move the slider and evaluate the callback
  public:    
    virtual void Redraw();    
  protected:
    virtual void BPress_CB (XButtonEvent ev);  // jump to button 1 press position
    virtual void KeyPress_CB (XKeyEvent ev);   // slide with arrow keys
    virtual void Motion_CB (XMotionEvent ev);  // slide when button 1 is pressed
    virtual void Resize(int, int);
};

//-----------------------------------------------------------------------------//
// class MpScrollbarDisplay:  displays the slider value (mainly for private use)
//-----------------------------------------------------------------------------//

class MpScrollbarDisplay : public MpCanvas 
{ 
  private:
    char* val; 

  public: 
    MpScrollbarDisplay(MpWindow &parent, char *def, 
		       int w, int h, int x, int y, int mode) 
	: MpCanvas(parent,w,h,x,y,mode) { val = def; }
    void draw_val() { PlaceText(val); }
    virtual void Redraw() { MpCanvas::Redraw(); draw_val(); }
};


//-----------------------------------------------------------------------------//
// class MpScrollbar: the user interface for a scrollbar
//-----------------------------------------------------------------------------//

// callback inf(void *), gets the (void*) argument "to_inf" 
//         with this form member functions of other classes can be called 
// "minp, maxp" are the limit values of the scrollbar, which are mapped to
//          [0..xspan] pixels
//          if maxp == 0 (default) the width of the slider is adopted
// "format" serves as transformation value
// "inf"    is an callback, which is called upon each move of the slider 
//          (without arguments), the actual value can be querried from
//          "MpScrollbar.value" 
// "xstart" is the starting value of the slider

class MpScrollbar : public MpScrollbarBase 
{
  private:
    MpScrollbarDisplay * disp_win;
    MpScrollbarBase * ps;
    char str[80];
    void *to_inform; // pointer for 2nd form
    void (*vptr)(void*);
    char* format; // the format string for display, like in printf

  protected:
    float factor;   // the conversion factor x into pixels = 0..w -> min..max 

  public:
    float min, max, value;

  private:
    void setval (float x)	// update string and value 
    { 
	value = x; sprintf(str,format,x); 
    }

    int pwidth(int w)		// the eff. width of MpScrollbarBase
    { 
	return (w-60); 
    }

    float pix_to_val (int pix) 
    { 
	return pix*factor + min; 
    }

    int val_to_pix (float x) 
    { 
	return (Nint((x-min)/factor)); 
    }

  public:
    void Initialize (MpWindow &parent, int w, int h, int x, int y,
		     float minp, float maxp, float xstart);

    MpScrollbar(MpWindow &parent, void (*inf)(void*), void *to_inf,
		int w, int h, int x, int y, 
		float minp = 0, float maxp = 0, float xstart = 0, 
		char *format = "%g");
    
    void Set (float x)		// set slider and display
    { 
	move( val_to_pix(x) ); 
	callbck_val(x);
    } 

  protected:

    virtual void callbck (int pix) // called from move_cb (mouse events)
    {  
	callbck_val( pix_to_val(pix) );
    }

    virtual void callbck_val (float x);    // called from change
    virtual void Resize(int, int);
};


//-----------------------------------------------------------------------------//
//  class MpVerticalScrollbar: vertical scrollbar with redefinable behaviour.
//                             defines virtual functions for move (button 2) 
//                             and jump (button 1 and 3)
//-----------------------------------------------------------------------------//

class MpVerticalScrollbar : public MpCanvas 
{
  protected:
    MpSlider *bar;
    int sw,sh,sx,sy,yspan; // span width for movement y = [0..yspan]
  public:
    int yact; 		   // actual position (0..yspan)
    void set_vars();
    MpVerticalScrollbar(MpWindow &parent, int w, int h, int x, int y, int sh);
  protected:
    virtual void move_callback (int y);		// called on drag
    virtual void jmp_callback (int up);		// called on jump
    virtual void BPress_CB (XButtonEvent ev);	// jump with button 1/2/3
    virtual void Motion_CB (XMotionEvent ev);	// drag with button 2
  public: 
    void SetSlider (int y); 			// set slider absolute
    void SetSliderRelative (float z);		// set slider in [0.0 .. 1.0]
    void AdaptSlider(int shp); 			// adapt to new slider height
    void AdaptScrollbar(int h, int shp);	// adapt scrollbar, slider height
    virtual void Resize(int w, int h);		// resize callback
};

//-----------------------------------------------------------------------------//
// class MpHandle:  2-dimensional mouse pointer driven slider
//
// Constructor:
//   MpHandle (MpWindow &parent, 
//             void (T::*member)(MpHandle<T>*), T *instance, 
//	       int w, int h, int x, int y, 
//	       int slider_width = 0, int slider_height = 0)
//
// A zero value for slider_width or slider_height indicates that the
// slider is confined in the horizonal or vertical direction. If either
// value is negative then the slider is not drawn.
//
//-----------------------------------------------------------------------------//

template <class T> 
class MpHandle: public MpCanvas 
{
  private:
    void (T::*member)(MpHandle<T>*);
    T *instance;
    int x_picked, y_picked;
    int sw,sh;       // slider width and height
    int sx,sy;       // slider offset to borders
    int xact,yact;   // actual position (0..span)
    int xspan,yspan; // span width for movement: {xact,yact} in [0..span]
    MpSlider *bar;   // pointer to slider
    bool HideBar;

    void Initialize (void) 
    {      
      HideBar = false;
      sx = sy = GetFrameWidth(); 
      x_picked = y_picked = 0;
      
      // a negative value indicates that the bar is not drawn
      if (sh < 0 || sw < 0) {
	HideBar = true;
	sh = sw = 0;    
      } else {
	// a zero value indicates that the shifter is confined in one direction
	if (sh == 0) sh = Height() - 2*sy; // horizontal shifter : yspan = 0
	if (sw == 0) sw = Width()  - 2*sx; // vertical shifter : xspan = 0
      }
      
      // the span
      yspan = Height() - 2*sy - sh; 
      xspan = Width() - 2*sx - sw;
    }

  protected:

    virtual void BPress_CB (XButtonEvent ev) // any button press
    {
      if (MpRectangle<int>(xact,yact,sw,sh).Contains(MpPoint2<int>(ev.x,ev.y))) {
	// clicked inside slider: move relative to picked position
	x_picked = ev.x - xact;
	y_picked = ev.y - yact;
      } else {
        // clicked outside slider: move center of slider to picked position
        x_picked = sx + sw/2;
	y_picked = sy + sh/2;
      }
      SetSlider(ev.x - x_picked, ev.y - y_picked); 
    }
    
    virtual void Motion_CB (XMotionEvent ev) 
    {
      // react only on moves with pressed button
      if (ev.state & (Button1Mask | Button2Mask | Button3Mask)) 
	  SetSlider(ev.x - x_picked, ev.y - y_picked);
    }

    virtual void Slider_CB (void) { (instance->*member)(this); }

  public:
    
    int GetPosX  (void) const { return xact;  }
    int GetPosY  (void) const { return yact;  }
    int GetSpanX (void) const { return xspan; }
    int GetSpanY (void) const { return yspan; }
    MpSlider* GetSlider (void) { return bar; }

    // swp, shp : width/height of slider; if = 0 : confined in this direction 
    MpHandle (MpWindow &parent, void (T::*member)(MpHandle<T>*), T *instance, 
	      int w, int h, int x, int y, 
	      int swp = 0, int shp = 0)
      : MpCanvas(parent,w,h,x,y,Panel|Sunken|Enhanced), 
	member(member), instance(instance), sw(swp), sh(shp) 
    { 
      SetBackground(&Mp.DarkColor);
      SetBackingStore(true); // this is crucial for a smooth scrolling!
      AddEventMask(ButtonMotionMask | ButtonPressMask); 
      Initialize();        
      yact = sy;
      xact = sx;
      
      // create a slider
      bar = (HideBar) ? (MpSlider*)0 : new MpSlider(*this,sw,sh,sx,sy);
    }  
    
    //-------------------------------------------------------------------------//
    // Set slider to new position. If centered = true then the center 
    // position is given, otherwise top-left corner (default).
    //-------------------------------------------------------------------------//

    void SetSlider (int x, int y, bool centered = false) 
    {
      if (centered) {
        x -= sx+sw/2;
	y -= sy+sh/2;
      }
      
      // check for boundaries
      MpForceRange(x,0,xspan);
      MpForceRange(y,0,yspan);
      
      // move window only if there is a change
      if (x != xact || y != yact) {
        xact = x; 
	yact = y;
	if (! HideBar) bar->Move(x + sx , y + sy); 
      }	
      
      Slider_CB();
    }

    //-------------------------------------------------------------------------//
    // adapt slider size after a resize
    //-------------------------------------------------------------------------//

    void AdaptSlider (int swp,int shp) 
    {
      sw = swp; 
      sh = shp;
      Initialize();
      if (HideBar) {
	if (bar) { delete bar; bar = NULL; }
      } else {
	if (! bar) bar = new MpSlider(*this,sw,sh,sx,sy);
	else bar->Resize(sw,sh); 
      }
    }

    void Resize (int w, int h) 
    {
      MpCanvas::Configure(w,h);
      AdaptSlider(sw,sh);
      SetSlider(xact,yact);
    }

    void Configure (int w, int h, int swp, int shp, int x, int y) 
    {
      MpCanvas::Configure(w,h,x,y);
      AdaptSlider(swp,shp);
      SetSlider(xact,yact);
    }
};

//-----------------------------------------------------------------------------//
// class MpHorizontalShifter and class MpVerticalShifter:
//
// Description:
//   Horizontal and vertical shifters derived from MpHandle
//   Slider cursors are defined.
//-----------------------------------------------------------------------------//

template <class T> 
class MpHorizontalShifter : public MpHandle<T>
{
  public:
    MpHorizontalShifter(MpWindow &parent, void (T::*member)(MpHandle<T>*), T *instance, 
			int w, int h, int x, int y, int slider_width)
      : MpHandle<T>(parent,member,instance,w,h,x,y,slider_width,0) 
    { 
      MpWindow::SetCursor( MpCursor::SlideHorizontal );
    }

    // resize only in horizontal direction, fixed vertical size
    void Resize(int w, int h) {	MpHandle<T>::Resize(w,MpWindow::Height()); }
};

template <class T> 
class MpVerticalShifter : public MpHandle<T>
{
  public:
    MpVerticalShifter(MpWindow &parent, void (T::*member)(MpHandle<T>*), T *instance,
		      int w, int h, int x, int y, int slider_height)
      : MpHandle<T>(parent,member,instance,w,h,x,y,0,slider_height)
    { 
      MpWindow::SetCursor( MpCursor::SlideVertical );
    }

    // resize only in vertical direction, fixed horizontal size
    void Resize(int w, int h) {	MpHandle<T>::Resize(MpWindow::Width(),h); }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
