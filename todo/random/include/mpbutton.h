/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpButton and other buttons            mpbutton.h |
|                                                                               |
| Last change: Feb 6, 2005                                                      |
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

#ifndef _MPBUTTON_H_
#define _MPBUTTON_H_

#include "mplabel.h"
#include "mptimer.h"


namespace MATPACK {

//-----------------------------------------------------------------------------//
// class MpButton:
//
// Purpose:
//   base class for all buttons
//
// Inherits:
//   class MpLabel
//
// Description:
//   see below
//
//-----------------------------------------------------------------------------//

class MpButtonGroup;
class MpButton: public MpLabel
{   
  friend class MpGlobal;
  friend class MpButtonGroup;

  private:
    // definition of button state bits
    enum { autorepeat       =  0x01,  
	   first_expired    =  0x02, 
	   in_pulldown      =  0x04, 
           entered          =  0x08,        
	   pressed          =  0x10,   
	   highlight        =  0x20, 
           toggle_button    =  0x40, 
	   toggle_true      =  0x80,
           icon_align_left  = 0x100, 
	   icon_align_right = 0x200 };
    // button state
    unsigned short state;
    short icon_width, icon_height;
    // pointers to dynamically allocated bitmaps and pixmaps
    const char *bitmap;
    Pixmap pixmap, mask;
    // event state
    XButtonEvent bev;
    // timer necessary for auto-repeat function
    MpTimer timer;   
    // pointer to background color of button
    const MpColor *saveBackground;
    // button group management
    MpButtonGroup *group;
    void SetGroup (MpButtonGroup *group);
    // default initialization of button
    void Initialize (MpWindow *parent);

  protected: 
    virtual void Draw (void);           // inherited from MpCanvas: draw label and/or icon
    virtual void LeaveFrame (void);     // restore frame when left
    virtual void EnterFrame (void);     // half-pressed when entered
    virtual void PressFrame (void);     // fully pressed button
    virtual void Enter_CB (XCrossingEvent);
    virtual void Leave_CB (XCrossingEvent);
    virtual void BPress_CB (XButtonEvent ev);
    virtual void BRelease_CB (XButtonEvent ev);
    virtual bool GUIColorChange_CB (void);            // GUI colors changed
    virtual void TimerExpired_CB (MpTimerInfo *info); // for auto-repeat
    virtual void SetToggleButton (bool val);  // make this button a toggle button

    //-------------------------------------------------------------------------//
    // Member Function:
    //   virtual void BClick_CB (XButtonEvent)
    //
    // Description:
    //   This is the user callback you have to overload. It is called whenever
    //   the left mouse button is released and the cursor is still inside 
    //   the buttons real estate.
    //-------------------------------------------------------------------------//
    virtual void BClick_CB (XButtonEvent) { } 

  public:

    //-------------------------------------------------------------------------//
    // Member Function:
    //   void AddIcon (const char *bitmap, int bitmap_width, int bitmap_height, 
    //                 int align = MpBase::AlignHCenter, bool mask = true);
    //
    // Description:
    //   Add a monochrome bitmap as icon. The bitmap argument
    //   is a standard X11 bitmap array. If mask is set true a mask is generated
    //   from the bitmap and only nonzero (foreground) pixmap values are drawn.
    //   The icon is aligned either left (align = MpBase::AlignLeft),
    //   right (align = MpBase::AlignLeft), or centered 
    //   (align = MpBase::AlignHCenter). In the latter case the label text is
    //   is not drawn.
    //   Note: The bitmap must be allocated statically, because upon a GUI color 
    //   change event it is read again and the icon is reallocated 
    //   with different colors.
    //-------------------------------------------------------------------------//
    void AddIcon (const char *bitmap, int bitmap_width, int bitmap_height,
		  int align = MpBase::AlignHCenter, bool mask = true);

    //-------------------------------------------------------------------------//
    // Member Function:
    //  void AddIcon (const char *pxmap[],
    //                int align = MpBase::AlignHCenter, bool mask = true);
    //
    // Description:
    //   Add a solid pixmap icon. The pxmap argument is a standard XPM pixmap.
    //   If mask is set true a mask is generated
    //   from the pixmap and only nonzero (foreground) bitmap values are drawn.
    //   The icon is aligned either left (align = MpBase::AlignLeft),
    //   right (align = MpBase::AlignLeft), or centered 
    //   (align = MpBase::AlignHCenter). In the latter case the label text is
    //   is not drawn.
    //-------------------------------------------------------------------------//
    void AddIcon (const char *pxmap[],
		  int align = MpBase::AlignHCenter, bool mask = true);

    
    //-------------------------------------------------------------------------//
    // Member Function:
    //   int GetIconWidth  (void) const;
    //   int GetIconHeight (void) const;
    //
    // Description:
    //   Return the width or the height, respectively, of the icon.
    //   If no icon is defined width and height are zero.
    //-------------------------------------------------------------------------//
    int GetIconWidth  (void) const { return icon_width; }
    int GetIconHeight (void) const { return icon_height; }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   void DeleteIcon (void);
    //
    // Description:
    //   Remove and deallocate icon. Also the alignment information is reset.
    //-------------------------------------------------------------------------//
    void DeleteIcon (void);

    //-------------------------------------------------------------------------//
    // Member Function:
    //   void SetAutoRepeat (bool val);
    //   bool GetAutoRepeat (void) const;
    //
    // Description:
    //   The set-method enable/disables the auto-repeat function for the button.
    //   The get-method returns true if auto-repeat is activated.
    //   Default: auto-repeat is inactive.
    //-------------------------------------------------------------------------//
    void SetAutoRepeat (bool val);
    bool GetAutoRepeat (void) const { return (state & autorepeat); }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   void SetHighlighting (bool val);
    //   bool GetHighlighting (void) const;
    //
    // Description:
    //   The set-method enable/disables highlighting of buttons if the pointer
    //   is over the button.
    //   The get-method returns true if highlighting is activated.
    //   Default: highlighting is inactive.
    //-------------------------------------------------------------------------//
    void SetHighlighting (bool val);
    bool GetHighlighting (void) const { return (state & highlight); }
    
    //-------------------------------------------------------------------------//
    // Member Function:
    //   void MpButton::SetPulldownStyle (bool val)
    //
    // Description:
    //   If the argument is 'true' the pulldown drawing style is enabled.
    //   In this case the label is left aligned. In the default case
    //   the label is centered.
    //-------------------------------------------------------------------------//
    void SetPulldownStyle (bool val);
    bool GetPulldownStyle (void) const { return (state & in_pulldown); }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   MpButtonGroup* GetGroup (void) const;
    //
    // Description:
    //   Return pointer to the button group or NULL if not a group member.
    //-------------------------------------------------------------------------//
    MpButtonGroup* GetGroup (void) const { return group; }

    //-------------------------------------------------------------------------//
    // Member Function:
    //   bool GetToggleButton (void) const;
    //
    // Description:
    //   return true if this button is a toggle button
    //-------------------------------------------------------------------------//
    bool GetToggleButton (void) const { return (state & toggle_button); }
    
    //-------------------------------------------------------------------------//
    // Member Function:
    //   virtual void SetToggleState  (bool val);
    //
    // Description:
    //   Set the toggle value to either true or false. This method
    //   is only useful in the class MpToggleButton which inherits class MpButton.
    //-------------------------------------------------------------------------//
    virtual void SetToggleState  (bool val);

    //-------------------------------------------------------------------------//
    // Member Function:
    //   virtual bool GetToggleState  (void) const;
    //
    // Description:
    //   Get the toggle value. This method
    //   is only useful in the class MpToggleButton which inherits class MpButton.
    //-------------------------------------------------------------------------//
    virtual bool GetToggleState  (void) const; 

    //-------------------------------------------------------------------------//
    // Member Function:
    //    virtual void Redraw();
    //
    // Description:
    //   redraw button upon a redraw event.
    //-------------------------------------------------------------------------//

    virtual void Redraw(); 

    //-------------------------------------------------------------------------//
    // Constructor and Destructor:
    //-------------------------------------------------------------------------//

    MpButton (MpWindow& parent, const string &label, int w, int h, 
              int x = 0, int y = 0);

    virtual ~MpButton (void);
};
 
//-----------------------------------------------------------------------------//
// Member Function:
//    void MpButton::SetHighlighting (bool val)
//
// Description:
//   The set-method enable/disables highlighting of buttons if the pointer
//   is over the button.
//   
//-----------------------------------------------------------------------------//

inline void MpButton::SetHighlighting (bool val)
{
  if (val)
    state |= highlight;
  else
    state &= ~highlight;
}
  
//-----------------------------------------------------------------------------//
// Member Function:
//    void MpButton::SetToggleButton (bool val)
//
// Description:
//   Make this button a toggle button. Method is virtual and protected.
//   
//-----------------------------------------------------------------------------//

inline void MpButton::SetToggleButton (bool val) 
{ 
  if (val) 
    state |= toggle_button; 
  else 
    state &= ~toggle_button;
}

//-----------------------------------------------------------------------------//
// Member Function:
//    void MpButton::SetToggleState (bool val)
//
// Description:
//   Set the toggle value - useful only if this is a toggle button
//   
//-----------------------------------------------------------------------------//

inline void MpButton::SetToggleState (bool val)
{ 
  if (val) 
    state |= toggle_true; 
  else 
    state &= ~toggle_true;
}

//-----------------------------------------------------------------------------//
// Member Function:
//    void bool MpButton::GetToggleState (void) const
//
// Description:
//    Get the toggle value - useful only if this is a toggle button
//   
//-----------------------------------------------------------------------------//

inline bool MpButton::GetToggleState (void) const
{
  return (state & toggle_true);
}


//-----------------------------------------------------------------------------//
// class MpToggleButton : button with on/off display of state
//                        different layouts are possible
//-----------------------------------------------------------------------------//

class MpToggleButton : public MpButton 
{
  private:
    unsigned char style;
    MpColor LEDcolor;

  protected:
    bool *state;                        // the pointer to the toggle value
    virtual void Toggle_CB (bool) { }   // executed on button release    
    virtual void BClick_CB (XButtonEvent ev);    
    int padright;                       // offset of toggle indicator
    virtual int EffectiveWidth()        // for PlaceText
    { 
      return (Width() - padright); 
    }
    virtual void PutImage(void);        // place toggle state image
    virtual void DrawRoundLED(void);

  public:
    // define the style of the button
    enum { CheckButton = 0x00,    // check box right, label left
           CheckBox    = 0x01,    // check box left,  label right
           RoundLED    = 0x02     // round LED left,  label right
           //PushButton  = 0x04,  // TODO: button stays pressed if active (NOT YET)
         };

    MpToggleButton (MpWindow& parent, const string &label, bool* ref, 
                    int w, int h, int x = 0, int y = 0); 

    // set toggle state to true (on,checked) or false (off,unchecked)
    virtual void SetToggleState (bool val);

    // return the toggle state: true (on,checked) or false (off,unchecked)
    virtual bool GetToggleState(void) const;

 protected:
    // draw label and checkbox
    virtual void Draw (void); 

 public:
    // set the style of the button: CheckButton, CheckBox, RoundLED, ...
    void SetStyle (int sty);
    int  GetStyle (void) const { return style; }

    // LED color (for LED style and CheckButton)
    void    SetLEDColor (const MpColor &color) { LEDcolor = color; };
    MpColor GetLEDColor (void) const { return LEDcolor; }

    // change linkage to another state variable, return pointer to previous one
    bool* ChangeRef (bool *ref);

    virtual ~MpToggleButton() { }
};

inline void MpToggleButton::SetToggleState (bool val)
{ 
  MpButton::SetToggleState(val); 
  *state = val;
  Redraw();
}

inline bool MpToggleButton::GetToggleState(void) const 
{ 
  return MpButton::GetToggleState(); 
}



//-----------------------------------------------------------------------------//
// class MpQuitButton: exit the EventLoop of a main window 
//                     (by setting the ExitEventLoop)
//-----------------------------------------------------------------------------//

class MpQuitButton : public MpButton 
{ 
  private:
    virtual void BClick_CB (XButtonEvent)
    { 
        MainWindow->ExitEventLoop = true; 
    }

  public: 
    MpQuitButton(MpWindow &parent, const string &label, int w,int h,int x = 0,int y = 0) 
        : MpButton(parent, label, w, h, x, y) { }
};

//-----------------------------------------------------------------------------//
// class MpDeleteButton: ordered deleting of a window and all of its children.
//-----------------------------------------------------------------------------//

class MpDeleteButton : public MpButton 
{ 
  private:
    MpWindow *to_del;

  public: 
    MpDeleteButton(MpWindow &parent, MpWindow *to_del, 
                   int w, int h, int x = 0, int y = 0)
        : MpButton(parent, Mp[Mp.T_delete], w, h, x, y), to_del(to_del) {}

  protected:
    virtual void BClick_CB (XButtonEvent)
    { 
        to_del->Unmap(); 
        delete to_del; 
    }
};

//-----------------------------------------------------------------------------//
// class MpUnmapButton: button to Unmap the parent on BPress, 
//                      usefull for popup menus
//-----------------------------------------------------------------------------//

class MpUnmapButton : public MpButton 
{ 
  private:
    MpWindow* to_unmap;

  public: 

    MpUnmapButton(MpWindow &parent, const string &name, MpWindow *unmap,
                  int w, int h, int x = 0, int y = 0) 
        : MpButton(parent,name, w, h, x, y) 
    { 
        to_unmap = unmap;
    }  

  protected:
    virtual void BClick_CB (XButtonEvent)
    { 
        to_unmap->Unmap(); 
    }
};

//-----------------------------------------------------------------------------//
// class MpPopupButton: popup a window on BPress - make invisible on second press
//-----------------------------------------------------------------------------//

class MpPopupButton: public MpButton 
{
  public: 
    MpFrame* popup_menu; 
    MpPopupButton(MpWindow& parent, MpFrame* menu, const string &label, 
                  int w, int h, int x = 0, int y = 0) 
      : MpButton(parent, label, w, h, x, y) { popup_menu = menu; }  
  
  protected:
    virtual void BClick_CB (XButtonEvent ev);
};

//-----------------------------------------------------------------------------//
// class MpPushButton: 
// A button that stays pressed if clicked, i.e. state = true
//-----------------------------------------------------------------------------//

class MpPushButton : public MpButton 
{
  private:
    bool *state;                        // the pointer to the toggle value

  protected:
    virtual void Push_CB (bool) { }     // executed on button release    

    virtual void BClick_CB (XButtonEvent ev) { 
      Push_CB(*state = !(*state)); 
    }

    virtual void EnterFrame (void) { }  // (virtual,inline)

    virtual void LeaveFrame (void)      // (virtual,inline)
    {  
      DrawFrame( ((*state) ? Sunken : Raised) | GetFrameOutline() );
    }

    virtual void PressFrame (void)      // (virtual,inline)
    {
      DrawFrame( ((*state) ? Raised : Sunken) | GetFrameOutline() );
    }

   virtual ~MpPushButton (void) { }

  public:
    MpPushButton (MpWindow& parent, const string &label, bool* ref, 
                  int w, int h, int x = 0, int y = 0) 
        : MpButton(parent,label,w,h,x,y), state(ref) { }
    
      bool GetState (void) const { return *state; }
      void SetState (bool st) { Push_CB(*state = st); Redraw(); }
};

//-----------------------------------------------------------------------------//
// class MpValueButton:
// assigns a stored value to a variable at a given location.
//-----------------------------------------------------------------------------//

template <class T> class MpValueButton : public MpButton 
{
  private:
    T value, *location;

  public:
    MpValueButton (MpWindow &parent, const string &label, T value, T &location,
                   int w, int h, int x = 0, int y = 0) 
        : MpButton (parent, label, w, h, x, y), 
          value(value), location(&location) {} 
    
  protected:
    virtual void BClick_CB (XButtonEvent ev)  { *location = value; }
};

//-----------------------------------------------------------------------------//
// class MpFunctionButton:
//     A button button with attached callback function on BRelease events.
//     The callback function gets all arguments of the ellipses (...) which are
//     of type (void*), minimally one argument must be given, maximally 10.
//     default arguments are posible
//-----------------------------------------------------------------------------//

// callback function hook type
typedef void (*MpFunctionButtonHook)(void*, ...);

class MpFunctionButton : public MpButton 
{
  private:
    MpFunctionButtonHook callback;
    void *values[10]; // the passed values (max 10)
  public:
    MpFunctionButton (MpWindow &parent, const string &label,  
                      int w, int h, int x, int y, MpFunctionButtonHook cb, ...);

  protected:
    virtual void BClick_CB (XButtonEvent ev);   // calls function
};

//-----------------------------------------------------------------------------//
// class MpVoidFunctionButton:
//     a button attached with a callback function on BRelease event.
//     The callback function has no arguments.
//-----------------------------------------------------------------------------//

// callback function hook type
typedef void (*MpVoidFunctionButtonHook)(void);

class MpVoidFunctionButton : public MpButton 
{
  private:
    void (*callback) (void);
  public:
    MpVoidFunctionButton (MpWindow &parent, const string &label, 
                          MpVoidFunctionButtonHook cb, 
                     int w, int h, int x = 0, int y = 0) 
        : MpButton (parent, label, w,h, x,y), callback(cb) { }
    
  protected:
    virtual void BClick_CB (XButtonEvent)  { callback(); } 
};

//-----------------------------------------------------------------------------//
// class MpTemplateButton:
//     Call a member function (void) of an instance of a class T or any other
//     simple function of type "void fcn(T)"
//     Example:  void f(double x) {...} 
//               MpTemplateButton <double> (menubar,"Function f", f, 2.0);
//-----------------------------------------------------------------------------//

template <class T> 
class MpTemplateButton : public MpButton 
{
  private:
    void (*callback) (T);
    T value;

  public:
    MpTemplateButton (MpWindow &parent, const string &label, void (*cb)(T), T val,
                     int w, int h, int x = 0, int y = 0) 
        : MpButton (parent, label, w, h, x, y), callback(cb), value(val) {} 
    
  protected:
    virtual void BClick_CB (XButtonEvent /* ev */)  
      { (*callback)(value); }
};

//-----------------------------------------------------------------------------//
// class MpClassButton: 
// Template button for member functions of a class with parameter
//-----------------------------------------------------------------------------//

template <class T, class P> 
class MpClassButton : public MpButton 
{
  private:
    void (T::*Member)(P);
    T *Instance;
    P Parameter;
  public:
    MpClassButton(MpWindow &parent, const string &label, 
                  void (T::*Member)(P), T *Instance, P Parameter,
                  int w, int h, int x = 0, int y = 0) 
      : MpButton(parent,label,w,h,x,y), 
        Member(Member), Instance(Instance), Parameter(Parameter) { }
  
  protected:
    virtual void BClick_CB (XButtonEvent) 
      { (Instance->*Member)(Parameter); } 
};

//-----------------------------------------------------------------------------//
// class MpVoidClassButton: 
// template button for member functions of a class
//-----------------------------------------------------------------------------//

template <class T> 
class MpVoidClassButton : public MpButton 
{
  private:
    void (T::*Member)(void);
    T *Instance;
  public:
    MpVoidClassButton(MpWindow &parent, const string &label, 
                      void (T::*Member)(void), T *Instance, int w, int h, 
                      int x = 0, int y = 0) 
      : MpButton(parent,label,w,h,x,y), Member(Member), Instance(Instance) { }
    
  protected:
    virtual void BClick_CB (XButtonEvent) 
      { (Instance->*Member)(); } 
};


//-----------------------------------------------------------------------------//
// class MpPulldownWindow: child window of root window, that is not yet visible.
//                         Not managed from window manager.
//-----------------------------------------------------------------------------//

class MpPulldownWindow : public MpFrame 
{
  public:
    MpPulldownWindow (int w, int h);
};

//-----------------------------------------------------------------------------//
// pulldowm menu entry type: name string, callback function
//-----------------------------------------------------------------------------//

typedef struct { const char *Name; void (*callback)(void); } MpMenuButtonTable;


//-----------------------------------------------------------------------------//
// class MpPulldownMenu: define a pulldown menu - usually pulled by 
//                       MpPulldownButton
//-----------------------------------------------------------------------------//

class MpPulldownMenu : public MpPulldownWindow 
{
  protected:

    int Columns;        // number of columns in the pulldown window 
    MpWindow *Link;     // sometimes really needed

  public:

    MpPulldownMenu (int nbuttons, MpMenuButtonTable list[], MpWindow *Link=0);

    MpPulldownMenu (MpWindow *Link=0) 
      : MpPulldownWindow(10,10), Link(Link) { Columns = 1;  }

    MpPulldownMenu (int w, int h, MpWindow *Link=0) 
      : MpPulldownWindow(w,h), Link(Link) { Columns = 1; }

    virtual void Pulldown (int x, int y, MpPulldownButton* pd_button = NULL);
  
    void SetColumns (int col) { Columns = col; }
    int  GetColumns (void) const { return Columns; }

    void SetLink (MpWindow *l) { Link = l; };
    MpWindow* GetLink (void) { return Link; }
};

//-----------------------------------------------------------------------------//
// class MpPulldownButton: 
// map the window (usually a pulldown menu) on root when the button is pressed 
// using absolute coordinates for the window just below the button.
//-----------------------------------------------------------------------------//

class MpPulldownButton : public MpButton 
{ 
  protected:
    int padright; 
    MpPulldownMenu* pulldown_menu; 
    //virtual int  EffectiveWidth() { return (Width()-padright); }
    virtual void PulldownAction (int x, int y);
    virtual void BPress_CB (XButtonEvent ev);  
    virtual void BRelease_CB (XButtonEvent ev); 
    virtual void Enter_CB (XCrossingEvent ev);

  public:
    MpPulldownMenu* GetMenu() { return pulldown_menu; }
    virtual ~MpPulldownButton (void);
    
    MpPulldownButton (MpWindow& parent, const string &label, MpPulldownMenu* menu, 
                      int w, int h, int x = 0, int y = 0);

    MpPulldownButton (MpWindow&  parent, const string &label,
                      int nbuttons, MpMenuButtonTable list[], 
                      int w, int h, int x = 0, int y = 0, int Columns = 1);
};

//-----------------------------------------------------------------------------//
// Radio menus
//-----------------------------------------------------------------------------//

//-----------------------------------------------------------------------------//
// class MpRadioButton: button with text in a radio menu
//-----------------------------------------------------------------------------//

class MpRadioButton : public MpButton 
{
  private:
    string menu_name;   // name of the button which pulled this radio_menu
    MpWindow   *action_win;
  public:    
    MpRadioButton (MpPulldownMenu &parent, const string &menu_name, 
                   int w, int h, int x, int y, const string &text, 
                   MpWindow *action_win) 
        : MpButton(parent,text,w,h,x,y), 
          menu_name(menu_name),action_win(action_win) { }
  protected:
    virtual void BClick_CB (XButtonEvent) 
    { 
      if (action_win) action_win->Action(menu_name.c_str(),Get().c_str()); 
    }
};

//-----------------------------------------------------------------------------//
// Function  MakeRadioMenu() returns a pulldown button with a menu of
// radio buttons. The menu is initialized from a list of strings **list
// of the form:  { "value1", "value2", ... , NULL }. Note, that the list must
// be closed by a NULL entry. The method "action" of the action_window is called
// with the argments (button_name,value)
//-----------------------------------------------------------------------------//

MpPulldownButton *MakeRadioMenu (MpWindow &parent, const string &button_name,
                                 const char **list,  MpWindow *action_win,
                                 int w, int h, int x = 0, int y = 0, 
                                 int bH = 0, int Columns = 1);

//-----------------------------------------------------------------------------//
// The next one is a more general template interface for buttons that can 
// also hold a value of arbitrary type. A templated table is used to 
// initialize the radio menu. Note, that the list must
// be closed by an entry with a NULL text. The method "action" of the 
// action_window is called with the argments (button_name,text,&value)
//-----------------------------------------------------------------------------//

template <class T> 
class MpRadioValueItem 
{ 
  public: const char *text; T value; 
};

//-----------------------------------------------------------------------------//
// class MpRadioValueButton: button with text and value in a radio_menu
//-----------------------------------------------------------------------------//

template <class T> 
class MpRadioValueButton : public MpButton 
{
  private:
    string menu_name;   // name of the button which pulled this radio_menu
    T value;                    // hold arbitrary value
    MpWindow *action_win;       // window that performs action

  protected:
    virtual void BClick_CB (XButtonEvent /* ev */) 
    { 
      if (action_win) action_win->Action(menu_name.c_str(), Get().c_str(), &value); 
    }

  public:    
    MpRadioValueButton (MpPulldownMenu &parent, const string &menu_name, 
                        const string &text, T value, MpWindow *action_win,
                        int w, int h, int x = 0, int y = 0 ) 
      : MpButton(parent,text,w,h,x,y),
        menu_name(menu_name), value(value), action_win(action_win) {  }
};


//-----------------------------------------------------------------------------//
// MakeRadioMenu(): 
// A template function that creates a pulldown button with a radio menu 
// attached.
//-----------------------------------------------------------------------------//

template <class T> inline
MpPulldownButton *MakeRadioMenu (MpWindow &parent, const string &button_name, 
                                 MpRadioValueItem<T> item[],
                                 MpWindow *action_win,
                                 int w, int h, int x = 0, int y = 0, 
                                 int button_height = 0, int Columns = 1) 
{
  const int hpad = 6,   // horizontal padding of button labels
            vpad = 2,   // vertical padding of button labels
            dw   = 2*(hpad+Mp.FrameWidth),
            dh   = 2*(vpad+Mp.FrameWidth);

  const bool auto_height = (button_height <= 0);

  if ( ! item ) return 0;
    
  // parse item list to determine menu size
  int text_width = 0, text_height = 0;
  const MpRadioValueItem<T> *i;
  int n = 1;
  for (i = item; i->text; i++) {
    int ww,hh;
    Mp.GetTextExtent(i->text,Mp.theButtonFont,ww,hh);
    text_width = MpMax(text_width,ww);
    text_height += hh;
    n++;
  }

  // determine menu size
  int menu_width  = text_width+dw,
      menu_height = text_height + n*dh + 2*Mp.FrameWidth;

  // make pulldown window
  MpPulldownMenu *menu 
    = new MpPulldownMenu(menu_width+2*Mp.FrameWidth,menu_height,action_win);

  menu->SetColumns(Columns);

  // make pulldown button
  MpPulldownButton *button;
  button = new MpPulldownButton(parent,button_name,menu,w,h,x,y); 

  // make buttons in pulldown window
  int yp = Mp.FrameWidth; 
  for (i = item; i->text; i++) {
    int bw, bh = button_height;
    if (auto_height) {
      Mp.GetTextExtent(i->text,Mp.theButtonFont,bw,bh);
      bh += dh;
    }
    new MpRadioValueButton<T>(*menu,button_name,
                              i->text, i->value, action_win,
                              menu_width,bh,Mp.FrameWidth,yp);
    yp += bh;
  }

  return button;    
}

//-----------------------------------------------------------------------------//
// MakeRadioDisplayMenu(): 
// A template function that creates a pulldown button with a radio menu 
// and a display window attached.
//-----------------------------------------------------------------------------//

template <class T, class C>
class MpRadioValueDisplay : public MpCanvas 
{
  public:
    const char *text;
    C *instance;
    void (C::*action_hook)(T *value);

    MpRadioValueDisplay (MpWindow &parent, char *text, 
                         C *instance,
                         void (C::*action_hook)(T *value),
                         int w, int h, int x, int y) 
      : MpCanvas (parent,w,h,x,y,Panel|Sunken|Enhanced), 
        text(text), instance(instance), action_hook(action_hook)  
    {  } 
    
    virtual void Redraw()  
    { 
      MpCanvas::Redraw();
      PlaceText(text); 
    }

    virtual void Action (const char*/* menu */, const char *newtext, void *value)
    { 
      // update display
      text = newtext;
      Redraw(); 
      // call action hook
      (instance->*action_hook)((T*)value);
    }
};

//-----------------------------------------------------------------------------//

template <class T, class C> inline
MpPulldownButton *MakeRadioDisplayMenu (MpWindow &parent, 
                                        const char *button_name, 
                                        MpRadioValueItem<T> item_table[],
                                        C *instance,
                                        void (C::*action_hook)(T *value),
                                        int initial_index,
                                        int bw, int w, 
                                        int h, int x, int y, 
                                        int bH = 0, int Columns = 1) 
{
  MpRadioValueDisplay<T,C> *action_win 
    = new MpRadioValueDisplay<T,C>(parent,(char*)item_table[initial_index].text,
                                   instance,action_hook,
                                   w-bw,h,x+bw,y);
  MpPulldownButton *menu 
    = MakeRadioMenu(parent,button_name,item_table,(MpWindow*)action_win,
                    bw,h,x,y,bH,Columns);
  
  return menu;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
