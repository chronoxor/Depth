/*-----------------------------------------------------------------------------*\
| Matpack X windows API: class MpFileDialog                      mpfiledialog.h |
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

#ifndef _MPFILEDIALOG_H_
#define _MPFILEDIALOG_H_

#include <string>
#include "mpbutton.h"

namespace MATPACK {

class DirListBox;
class FileListBox;
class FilterEditBox;
class FileEditBox;

//-----------------------------------------------------------------------------//

class MpFileDialog: public MpFrame 
{ 
  friend class DirListBox;
  friend class FileListBox;

  private:
    string directory, file; 
    FilterEditBox *FilterEdit;
    FileEditBox   *FileEdit;
    MpButton      *OkButton, *CancelButton, *FilterButton;
    DirListBox    *DirList;
    FileListBox   *FileList;
    bool          MsgPopup; 
    void filter (void);
    void accept (void);
    void cancel (void);
    void enter  (const string &text); 

  protected:
    void MakeSelection (const string &mask);
    virtual void ClientMsg_CB (XClientMessageEvent ev);

  public:
    MpFileDialog (char *title = "Open File", 
                  const string &directory = ".", const string &filter = "*");
    virtual ~MpFileDialog (void);

    virtual void Resize (int w, int h);
    virtual void Redraw (void);

    //-------------------------------------------------------------------------//
    // Member Functions:
    //   void SetMessagePopup (bool val);
    //
    // Description:
    //   If set true (default) errors when changing the directory
    //   (method SetDirectory()) or when reading directory contents are
    //   displayed in a message box. If set false the error state can only
    //   be detected from the return value of SetDirectory().
    //-------------------------------------------------------------------------//
    void SetMessagePopup (bool val) { MsgPopup = val; }

    //-------------------------------------------------------------------------//
    // Member Functions:
    //   int    SetDirectory (const string &directory);
    //   string GetDirectory (void) const;
    //   string GetFile (void) const;
    //
    // Description:
    //   The first method sets the current directory and updates the directory
    //   and file list boxes. If it is not possible to change to this directory
    //   the 'errno' error code is returned (ERANGE,EACCES,ENOENT,ENOTDIR).
    //   If the operation is sucessful zero is returned.
    //   The get methods return currently selected directory or file
    //   name string, respectively.
    //-------------------------------------------------------------------------//
    int    SetDirectory (const string &directory);
    string GetDirectory (void) const;
    string GetFile (void) const;

    //-------------------------------------------------------------------------//
    // Member Functions:
    //   void   SetFilter (const string &mask);
    //   string GetFilter (void) const;
    //
    // Description:
    //   Set (and get) filter for file names. A regular expression can be given
    //   to filter the directory contents. Only names matching the expression
    //   are shown in the file list box. For a description of valid expressions
    //   see function MpFilenamePatternMatch() in the online documentation.
    //-------------------------------------------------------------------------//
    void   SetFilter (const string &mask);
    string GetFilter (void) const;

    //-------------------------------------------------------------------------//
    // Member Functions:
    //   void SetSingleClickMode (bool);
    //   bool GetSingleClickMode (void) const;
    //
    // Description:
    //   Set and get method for single-click mode. If active a single-click
    //   is sufficient for selecting a directory or file. Moving the pointer
    //   over the directory or file list already marks an entry. 
    //   If single-click mode is deactivated the conventional double-click
    //   feeling is active.
    //-------------------------------------------------------------------------//
    void SetSingleClickMode (bool); 
    bool GetSingleClickMode (void) const;

    //-------------------------------------------------------------------------//
    // Member Functions:
    //   -- see below --
    // Description:
    //   These virtual methods serve as callbacks. You can overload these
    //   methods to create tailored dialogs. Usually you will only use
    //   the convenient modal dialog templates given below.
    //-------------------------------------------------------------------------//
    virtual void DialogCanceled (const string &directory, const string &name, 
                                 bool &ExitDialog) { ExitDialog = true; }
    virtual void FileMarked (const string &directory, const string &name, 
                             bool &ExitDialog) {  }
    virtual void FileSelected (const string &directory, const string &name, 
                               bool &ExitDialog) { ExitDialog = true; }
    virtual void DirectoryMarked (const string &directory, 
                                  bool &ExitDialog) { }
    virtual void DirectoryEntered (const string &directory, 
                                   bool &ExitDialog) { }
};

//-----------------------------------------------------------------------------//
// convenient modal dialog templates
//-----------------------------------------------------------------------------//

template <class T> 
string MpGetFile (char *title = "Open File", 
                  const string &directory = ".", 
                  const string &filter = "*")
{
  T *FileDialog = new T(title,directory,filter);
  FileDialog->LocalLoop(); // local event loop for modal dialog
  string file(FileDialog->GetFile());
  delete FileDialog;
  return file;
}

template <class T, class C> 
string MpGetFile (char *title, 
                  const string &directory, 
                  const string &filter,
                  C *cptr) // with additional class pointer
{
  T *FileDialog = new T(title,directory,filter,cptr);
  FileDialog->LocalLoop(); // local event loop for modal dialog
  string file(FileDialog->GetFile());
  delete FileDialog;
  return file;
}

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
