/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpListBox                            mplistbox.h |
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

#ifndef _MPLISTBOX_H_
#define _MPLISTBOX_H_

#include <vector>
#include <string>

#include "mpscrollwin.h"

namespace MATPACK {

class MpListBoxImpl;
class MpListBox;

//-----------------------------------------------------------------------------//
// class MpListBoxItem;
// The base class for all kinds of items in a list box.
//-----------------------------------------------------------------------------//

class MpListBoxItem  
{
  friend class MpListBox;
  friend class MpListBoxImpl;
  public:
    MpListBoxItem (MpListBox *listbox = 0, int position = -1);
    // negative positions count from back, i.e. -1 appends at back

    virtual ~MpListBoxItem () = 0;
    virtual int GetWidth (void) const = 0;
    virtual int GetHeight (void) const = 0;
    virtual void Draw (MpWindow*, int x, int y) = 0;
    bool IsSelected (void) const { return selected; }
    bool IsManaged (void)  const { return managed; }
    void SetManaged (bool val) { managed = val; }
  private:
    MpListBox *listbox;  // points to controlling listbox
    bool selected,       // set if item is selected
         managed;        // set if item is managed by listbox (default: true)
};

//-----------------------------------------------------------------------------//
// class MpListBoxString:
// A special list box item containing a string. 
//-----------------------------------------------------------------------------//

class MpListBoxString: public MpListBoxItem
{
  friend class MpListBox;
  private:
    int lw,lh;
    string label;
  public:
    MpListBoxString (MpListBox *listbox, const string &text, int position = -1);
    // negative positions count from back, i.e. -1 appends at back

    virtual ~MpListBoxString () { };
    virtual int GetWidth (void) const { return lw; } 
    virtual int GetHeight (void) const { return lh; }
    virtual void Draw (MpWindow *w, int x, int y);
    const string& GetLabel (void) const { return label; }
    void SetLabel (const string& label);
};

//-----------------------------------------------------------------------------//

class MpListBox: public MpScrollWindow
{
  friend class MpListBoxItem;
  friend class MpListBoxImpl;

  private:
    vector< MpListBoxItem* > list;                                  // STL vector
    MpListBoxImpl* pimpl;                            // pointer to implementation
    void SetCurrent  (MpListBoxItem *item);

  public:
    virtual void BPress_CB     (XButtonEvent ev);
    virtual void BDoubleClick_CB (XButtonEvent ev);
    virtual void KeyPress_CB     (XKeyEvent ev);
    virtual void Motion_CB       (XMotionEvent ev);
    virtual void MouseWheel_CB   (XButtonEvent ev, int delta);
    virtual bool GUIColorChange_CB (void);

    MpListBox (MpWindow& parent, int w, int h, int x = 0, int y = 0);
    virtual ~MpListBox ();

    vector<MpListBoxItem*>  GetItemListCopy(void) const { return list; }
    vector<MpListBoxItem*> *GetItemListRef(void) { return &list; }

    MpListBoxItem* GetItem (int position);                    // return i-th item
                 // negative positions count from back, i.e. -1 returns last item

    // list modification
    void InsertItem (MpListBoxItem *item, int position = -1);      // insert item
                    // negative positions count from back, i.e. -1 appends at end

    void RemoveItem (int position);     // unlink item from list and destroy item
                 // negative positions count from back, i.e. -1 removes last item

    MpListBoxItem* UnlinkItem (int position);            // unlink item from list
                 // negative positions count from back, i.e. -1 removes last item

    void ClearList (void);                       // destroy all items in the list

    // layout modification
    void SetRowOrder (bool);                 // row order, column order otherwise
    bool GetRowOrder (void) const;
    void SetFixedColumnWidth (bool);               // all columns have same width
    bool GetFixedColumnWidth (void) const;
    void SetFixedRowHeight (bool);                   // all rows have same height
    bool GetFixedRowHeight (void) const;
    
    void SetFixedRowNumber (int);       // row number fixed, columns as necessary
    int  GetFixedRowNumber (void) const;
    void SetFixedColumnNumber (int);    // column number fixed, rows as necessary
    int  GetFixedColumnNumber (void) const;
    void SetRowNumberFitToWidth (bool);             // fit row number to viewport
    bool GetRowNumberFitToWidth (void) const;
    void SetColumnNumberFitToWidth (bool);       // fit column number to viewport
    bool GetColumnNumberFitToWidth (void) const;

    int  GetCurrentRowNumber (void) const;           // get the current row number
    int  GetCurrentColumnNumber (void) const;     // get the current column number
    
    void SetItemPadWidth (int);                                 // pad item width
    int  GetItemPadWidth (void) const;
    void SetItemPadHeight (int);                               // pad item height
    int  GetItemPadHeight (void) const;
    
    void SetSelected (MpListBoxItem *item, bool val = true);       // select item
    void SetSelected (int position, bool val = true);

    MpListBoxItem* GetCurrentItem (void);                     // get current item
    int GetCurrentItemPos (void) const;

    void SetSingleClickMode (bool);                          // single click mode
    bool GetSingleClickMode (void) const;

    // drawing
    virtual void Redraw (void); 
    virtual void Resize (int w, int h); 

    virtual void UpdateItem (MpListBoxItem *item);   // redraw this item after it
                                                             // has been modified

    virtual void UpdateView (void);                      // necessary after every 
                                       // structure change, e.g. adding new items

    // signals (virtual callbacks)
    virtual void ItemMarked   (MpListBoxItem *item) { }           // when clicked
    virtual void ItemSelected (MpListBoxItem *item) { }    // when double-clicked
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif

