/*-----------------------------------------------------------------------------*\
| Matpack class MpContextSave - save/restore contexts to file   mpcontextsave.h |
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

#ifndef _MPCONTEXTSAVE_H_
#define _MPCONTEXTSAVE_H_

//-----------------------------------------------------------------------------//

// include STL definitions
#include <map>
#include <string>
#include <vector>
#include <iostream>

namespace MATPACK {
using std::map;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

//-----------------------------------------------------------------------------//
// class MpContextSave:
//
// General purpose class to save a context to a stream and to restore a context 
// from a stream. This way the state of a class can be stored in non volatile 
// memory, i.e. a file.
// 
// Example for the file format:
//
// [                              <--- contexts are delimeted by square brackets
//  contextname1,                 <--- context name follows
//  (variable1, value1),          <--- variable-value pairs follow
//  (variable2, value2),          <--- these a delimeted by parentheses and
//  ...                           <--- separated by commas
//  (variableN, valueN)
// ]                              <--- closing square bracket of context
//
// [contextname2,                 <--- next context in the file
//  (variable1, value1),
//  (variable2, value2),
//  ...
//  (variableK, valueK)
// ]
//
// Hints:
// If you want to write comments in a context file use an unknown context name.
// Such a context is ignored when the file is restored. Example:
//
// [ 
//   *** My comment in the form of a context.
//   *** Multiline comments are possible, because everything is skipped
//   *** until a closing square bracket is found.
// ]
//
// Here the unknown context name is "***", i.e. the first string after the 
// opening square bracket.
//
//-----------------------------------------------------------------------------//

class MpContextSave
{
  public:
    typedef const string& name_t; // context and variable names

    // constructor: usually your application class inherits this class
    MpContextSave (void);
    
    // Return true if the named context is already defined, 
    // otherwise return false.
    bool FindContext (name_t name);
    
    //-------------------------------------------------------------------------//
    // bool SelectContext (name_t name);
    //
    // The named context becomes the current context. 
    // If the context doesn't yet exist a new context is registered.
    // All following variables are added to this context.
    // If the context exists already "true" is returned, otherwise,
    // if a new context had been created "false" is returned.
    //-------------------------------------------------------------------------//
    bool SelectContext (name_t name);

    //-------------------------------------------------------------------------//
    // bool EraseContext (name_t name);
    //
    // The named context with all its variables is erased.
    //-------------------------------------------------------------------------//
    bool EraseContext (name_t name);

    //-------------------------------------------------------------------------//
    // void EraseAllContexts (const string& group = "");
    //
    // All context are erased
    //-------------------------------------------------------------------------//
    void EraseAllContexts (name_t group = "");

    //-------------------------------------------------------------------------//
    // bool ContextAdd (name_t var, const <TYPE> *ref, unsigned count = 1);
    //
    // Add a built-in variable type to the currently selected context
    // For count > 1 an array of values can be added to the context
    //-------------------------------------------------------------------------//
    bool ContextAdd (name_t var, const int *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const unsigned *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const long *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const unsigned long *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const short *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const unsigned short *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const char *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const unsigned char *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const float *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const double *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const string *ref, unsigned count = 1);
    bool ContextAdd (name_t var, const bool *ref, unsigned count = 1);


    //-------------------------------------------------------------------------//
    // bool SaveContext (ostream& os, name_t name) const;
    //
    // Save named context to output stream.
    // As usual formating options can be given for the stream. 
    // E.g. set the precision for floating point numbers.
    //-------------------------------------------------------------------------//
    bool SaveContext (ostream& os, name_t name) const;

    //-------------------------------------------------------------------------//
    // bool SaveAllContexts (ostream& os, const string& group = "") const;
    //
    // If an empty group string is given all contexts are saved, otherwise
    // all contexts are saved for which the first characters of the name
    // match the given group string. 
    //-------------------------------------------------------------------------//
    bool SaveAllContexts (ostream& os, const string& group = "") const;
    
    //-------------------------------------------------------------------------//
    // bool RestoreContext (istream& is, name_t name);
    //
    // Restore named context from input stream
    //-------------------------------------------------------------------------//
    bool RestoreContext (istream& is, name_t name);

    //-------------------------------------------------------------------------//
    // int  RestoreAllContexts (istream& is, const string& group = "");
    //
    // Restore context groups from input stream.
    // If an empty group string is given all contexts are restored, otherwise
    // all contexts are restored for which the first characters of the name
    // match the given group string. 
    //-------------------------------------------------------------------------//
    int  RestoreAllContexts (istream& is, const string& group = "");

    //-------------------------------------------------------------------------//
    // Define output format (0 = dense, default: 1 = one variable per line)
    //-------------------------------------------------------------------------//
    void SetContextFormat (int f);
    int  GetContextFormat (void) const;

    // low level functions:

    //-------------------------------------------------------------------------//
    // bool ReadContextHead (istream& is, string &name);
    //
    // Read the list head, i.e. the name of the context and stop parsing.
    // This method starts reading at the current stream position.
    // 1. Skips white space. 
    // 2. Reads and checks for an open square bracket '['.
    // 3. Skips white space. 
    // 4. Reads a name until a delimiter is found (one of "()[]," or white space)
    // Upon success 'true' and the name of the context is returned. Otherwise
    // false is returned and the stream is left at the erroneous position.
    //-------------------------------------------------------------------------//
    bool ReadContextHead (istream& is, string &name);

    //-------------------------------------------------------------------------//
    // void SkipContextTail (istream& is);
    //
    // This method starts reading at the current stream position.
    // Skip stream to end of context, i.e. until a closing square 
    // bracket ']' is found. Pairs of intermediate opening and closing 
    // square brackets are taken into account.
    //-------------------------------------------------------------------------//
    void SkipContextTail (istream& is);

    //-------------------------------------------------------------------------//
    // bool ReadContextTail (istream& is, string &name);
    //
    // This method starts reading at the current stream position.
    // It restores all context variables read from the stream and defined
    // in the named context.
    // It is intended to be called after the context head has been read
    // and it proceeds th read the tail of the list.
    // 1. Skips white space.
    // 2. Reads and checks for a comma ','
    // 3. reads all comma-separated variable-value pairs in parenthesis 
    // 4. until a closing square bracket ']' is found.
    // Upon any error false is returned and the stream is left at the 
    // erroneous position.
    //-------------------------------------------------------------------------//
    bool ReadContextTail (istream& is, string &name);

    //-------------------------------------------------------------------------//
    // void SetStrictContextReadPolicy (bool strict);
    // bool GetStrictContextReadPolicy (void) const;
    //
    // Set strict or lazy policy when restoring contexts from a (file) stream.
    // When variable names within a context are found which are not defined
    // in the context then RestoreAllContexts() and ReadContextTail()  
    // return false immediately (i.e. error).
    // This is the default "strict bahavior". Call SetStrict(false) to set
    // lazy behavior. In this case unknown variables are simply ignored.
    // and restoring proceeds with the next variable.
    //-------------------------------------------------------------------------//
    void SetStrictContextReadPolicy (bool strict);
    bool GetStrictContextReadPolicy (void) const;

  private:    

    typedef struct { 
          int (MpContextSave::*isread)(istream &is); 
          int (MpContextSave::*oswrite)(ostream &os) const; 
          MpContextSave *inst;
          unsigned size;
    } obj_t;

    typedef struct {
          unsigned type, cnt;
          const void* data;
          obj_t obj;
    } data_t;

        typedef map<string,data_t> varmap_t;
        typedef varmap_t::iterator varmap_it;
    typedef varmap_t::const_iterator varmap_cit;

    typedef struct{
          varmap_t varmap;
    } context_t;

        typedef map<string,context_t> ctxmap_t;
        typedef ctxmap_t::iterator ctxmap_it;
    typedef ctxmap_t::const_iterator ctxmap_cit;

        data_t    Data;
        context_t Context;

    int format;
    bool strict;
    ctxmap_t ctxmap;
    context_t *current_context;

    void AddName (name_t name,  data_t **d, bool &status);
    bool GetListHead (istream& is, char bra, string &name);
    bool GetListTail (istream& is, context_t *ctx);

  public:

    //-------------------------------------------------------------------------//
    // template <class T> bool ContextAdd (name_t name, 
    //                                     int (T::*isread)(istream &is), 
    //                                     int (T::*oswrite)(ostream &os) const, 
    //                                     const T *instance, 
    //                                     unsigned count = 1);
    //
    // Add a class with it's own read and write functions to the 
    // currently selected context. The stream read and write functions must match
    // the given template arguments.
    //-------------------------------------------------------------------------//

    template <class T> 
    bool ContextAdd (name_t name, 
                     int (T::*isread)(istream &is), 
                     int (T::*oswrite)(ostream &os) const, 
                     const T *instance, 
                     unsigned count = 1)
    {   
        typedef int (MpContextSave::*readp)(istream &is);
        typedef int (MpContextSave::*writep)(ostream &os) const;
        typedef MpContextSave *instp;

        bool status;
        data_t *d;
        AddName(name,&d,status);
        d->type = 0;
        d->cnt = count;
        d->obj.isread  = reinterpret_cast< readp >(isread);
        d->obj.oswrite = reinterpret_cast< writep >(oswrite);
        d->obj.inst    = reinterpret_cast< instp >( const_cast<T*>(instance));
        d->obj.size    = sizeof(*instance);
        return status;
    }

};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
