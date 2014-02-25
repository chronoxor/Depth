/*-----------------------------------------------------------------------------*\
| Matpack class MpGetopt: command line option parser                 mpgetopt.h |
|                                                                               |
| Last change: Nov 25, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel. All rights reserved.             |
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

#ifndef _MPGETOPT_H_
#define _MPGETOPT_H_

// include STL definitions
#include <string>
#include <vector>
#include <list>
#include <ostream>

namespace MATPACK {
using std::string;
using std::vector;
using std::list;
using std::ostream;

//-----------------------------------------------------------------------------//
// Description of class MpGetopt 
//-----------------------------------------------------------------------------//
//
// Class MpGetopt is a flexible command line option class. Command line options
// in the standard Posix format are parsed and argument values are assigned 
// to variables. Furthermore it allows to automatize printing of help texts
// for the command line options.
//
//  Short options are options that start with '-' and are followed by one
//  option character. Examples for valid short options are 
//
//      '-h', '-1', '-?', '-o par', '-i arg1 arg2'. 
//
//  The first three options have no arguments.
//  The last two options have one or more arguments.
//  Short options must be unique. If an option is defined twice a warning
//  to "cerr" is printed and the option is ignored.
//
//  Long options are options that start with '--' and are followed by an
//  arbitrary string not containing white space or the '=' sign.
//  Examples for valid options are 
//
//      '--help', '--version', '--in=arg', '--geom 1 2 3 4'. 
//
//  Note that options with one argument can be written in two ways:
//
//      '--in arg' or '--in=arg'. 
//
//  Options with more than one argument always have to be written like 
//
//      '--geom 1 2 3 4'.
//
//  Long options must be unique. If an option is defined twice 
//  a warning to "cerr" is printed and the option is ignored.
//
//  The usual way to use class MpGetopt is to inherit it.  
//
//   - Inherit this class.
//   - In the inherited class, add all command line parameters with
//     the AddOpt() function.
//   - Set all variables to the default value.
//   - Call ParseOpt() to assign all variables the values given on the 
//     command line.
//
//
// Notes:
//
//  1. A command line option must have defined at least a short or a long option.
//     That means, in the definition with AddOpt() you can either leave either 
//     the short format or the long format undefined, but not both. If you do so,
//     a warning to "cerr" is printed and the option is ignored.
//
//  2. Options with integer arguments:
//     If an option takes one or more integer arguments the integer can be given
//     in decimal, hexadecimal, or octal base. The string may include a '0x' prefix, 
//     and the number will be read in base 16 (hexadecimal); otherwise, the base is 
//     taken as 10 (decimal) unless the next character is '0', in which case it 
//     is taken as 8 (octal). This behavior corresponds to the standard strtol()
//     conversion function. Note, if the option argument is an unsigned integer
//     and the given argument has a leading minus sign, the negation of the result
//     of the conversion is returned. This behavior corresponds to the standard 
//     strtoul() conversion function .
//
//-----------------------------------------------------------------------------//
// bool MpGetopt::ParseOpt (const char *argv[], string &error);
//-----------------------------------------------------------------------------//
//
//        After calling ParseOpt() all command line options are done.
//        If there is an error during parsing (e.g. invalid option or argument 
//        formats) then ParseOpt() returns 'false' and the error message is returned
//        in 'error'. Otherwise, if there is no error ParseOpt() returns 'true'.
//
//-----------------------------------------------------------------------------//
// bool MpGetopt::AddOpt (char, const string&, bool*, const char *comment="");
//-----------------------------------------------------------------------------//
//
//        A boolean (flag) argument. The default value of the 
//        flag is negated if the option is found. 
//        Optionally a description can be given.
//
//-----------------------------------------------------------------------------//
// bool MpGetopt::AddOpt (char, const string&, TYPE*, const char *comment="");
//-----------------------------------------------------------------------------//
//
//        TYPE is either of
//        'char',   'unsigned char', 
//        'int',    'unsigned int', 
//        'long',   'unsigned long', 
//        'short',  'unsigned short', 
//        'float',  'double',
//        'string'
//
//-----------------------------------------------------------------------------//
// bool MpGetopt::AddOpt (char, const string&, OptFcn0, const char *comment="");
// bool MpGetopt::AddOpt (char, const string&, OptFcn1, const char *comment=""); 
// bool MpGetopt::AddOpt (char, const string&, OptFcn2, const char *comment="");
//-----------------------------------------------------------------------------//
//
//        The void function with no, one, or two arguments is called, where
//        the the arguments of the function are taken from the next arguments
//        of the command line arguments. Optionally a description can be given.
//        The functions must be defined according to the
//        following prototypes:
//
//          typedef void (*OptFcn0)(void);
//          typedef void (*OptFcn1)(const string &opt);
//          typedef void (*OptFcn2)(const string &opt1, const string &opt2);
//
//-----------------------------------------------------------------------------//
// bool MpGetopt::AddOpt (char shortop, const string &longop, 
//                        const type_t type, unsigned arg_count, ...);
//-----------------------------------------------------------------------------//
//
//        Add a command line option that takes a list of arguments of the same 
//        type. 'arg_count' pointers  to arguments of the same type are 
//        expected after the option. 
//        Valid option types for 'type_t' are:
//        
//        t_int      Convert the option argument(s) to an integer.
//        t_uint     Convert the option argument(s) to an unsigned integer.
//        t_char     Convert the option argument(s) to a char.
//        t_uchar    Convert the option argument(s) to a unsigned char.
//        t_long     Convert the option argument(s) to a long integer.
//        t_ulong    Convert the option argument(s) to an unsigned long integer.
//        t_short    Convert the option argument(s) to a short integer.
//        t_ushort   Convert the option argument(s) to an unsigned short integer.
//        t_double   Convert the option argument(s) to a double.
//        t_float    Convert the option argument(s) to a float.
//        t_string   Convert the option argument(s) to a string.
//        
//        Note, that in this function the comment string is mandatory, 
//        i.e. at least the empty string "" must be given as the last parameter
//        in the varable length argument list..
//
//-----------------------------------------------------------------------------//
// void MpGetopt::AddCmt (const char *comment);
//-----------------------------------------------------------------------------//
//
//       This method allows to add comment lines to print out additional help texts.
//
//-----------------------------------------------------------------------------//
// bool MpGetopt::IllegalEntry (char shortop, const string &longop);
//-----------------------------------------------------------------------------//
//
//       Check for multiple or illegal option entry.
//       This method scans the options added so far and tests whether 
//       the given option names are already in the list. If the option is already
//       in the list "true" is returned. Also if both arguments are empty
//       true is returned.
//
//-----------------------------------------------------------------------------//
// bool MpGetopt::ParseOpt (const char *argv[], string &error);
//-----------------------------------------------------------------------------//
//
//       Parse the command line options given the argv[] of command line options.
//       If an undefined option is encountered the method returns false and the error
//       rsituation is described in the returned error message string.
//
//-----------------------------------------------------------------------------//
// virtual void MpGetopt::NonOptArg (const char *arg);
//-----------------------------------------------------------------------------//
//
//       This method is called for every non option argument, 
//       i.e. and argument not starting with  "-" or "--".
//       It should be overloaded to handle these arguments.
//
//-----------------------------------------------------------------------------//
// void MpGetopt::PrintOptions (ostream &os, 
//	                        unsigned LeftMargin = 2, 
//		                unsigned CommentMaxIndent = 32, 
//		                bool PrintValues = false);
//-----------------------------------------------------------------------------//
//
//       Print the command line options to the given output stream. 
//       Optionally a left margin and a maximum indent value for the 
//       comment column (default 32) can be given.
//       For debugging purposes a the argument PrintValues can be set to "true". 
//       In this case the current values of the option values are printed.
//
//-----------------------------------------------------------------------------//

class MpGetopt
{
  public:
    
    // supported argument types for options with multiple arguments
    enum type_t { t_int = 0, t_uint, 
                  t_long,    t_ulong, 
                  t_short,   t_ushort, 
                  t_char,    t_uchar, 
                  t_double,  t_float, 
                  t_string,  t_comment };

    // function argument types
    typedef void (*OptFcn0)(void);
    typedef void (*OptFcn1)(const string &opt);
    typedef void (*OptFcn2)(const string &opt1, const string &opt2);

    // constructor and destructor
    MpGetopt (void) { }
    virtual ~MpGetopt (void) { }

    // add a command line option
    bool AddOpt (char, const string&, bool*,           const char *comment=""); // boolean flag argument
    bool AddOpt (char, const string&, int*,            const char *comment=""); // int argument
    bool AddOpt (char, const string&, unsigned int*,   const char *comment=""); // unsigned argument
    bool AddOpt (char, const string&, long*,           const char *comment=""); // long argument
    bool AddOpt (char, const string&, unsigned long*,  const char *comment=""); // unsigned long argument
    bool AddOpt (char, const string&, short*,          const char *comment=""); // short argument
    bool AddOpt (char, const string&, unsigned short*, const char *comment=""); // unsigned short argument
    bool AddOpt (char, const string&, char*,           const char *comment=""); // char argument
    bool AddOpt (char, const string&, unsigned char*,  const char *comment=""); // unsigned char argument
    bool AddOpt (char, const string&, float*,          const char *comment=""); // float argument
    bool AddOpt (char, const string&, double*,         const char *comment=""); // double argument
    bool AddOpt (char, const string&, string*,         const char *comment=""); // string argument
    bool AddOpt (char, const string&, OptFcn0,         const char *comment=""); // function(void)
    bool AddOpt (char, const string&, OptFcn1,         const char *comment=""); // function(arg1)
    bool AddOpt (char, const string&, OptFcn2,         const char *comment=""); // function(arg1,arg2)

    // Add a command line entry node with list of arguments of the same type
    // Note, that in this function the comment string is mandatory, i.e. at least the empty string "".
    bool AddOpt (char shortop, const string &longop, 
                 const type_t type, unsigned arg_count, ... /* mandatory comment string at end */);
    
    // This method allows to add comment lines to print out additional help texts.
    void AddCmt (const char *comment);

    // Check for multiple or illegal option entry.
    // This method scans the options added so far and tests whether 
    // the given option names are already in the list. If the option is already
    // in the list "true" is returned. Also if both arguments are empty
    // true is returned.
    bool IllegalEntry (char shortop, const string &longop);

    // Parse the command line options given the argv[] of command line options.
    // If an undefined option is encountered the method returns false and the error
    // situation is described in the returned error message string.
    bool ParseOpt (const char *argv[], string &error);

    // This method is called for every non option argument, 
    // i.e. and argument not starting with  "-" or "--".
    virtual void NonOptArg (const char *) { };

    // Print the command line options to the given output stream. 
    // Optionally a left margin and a maximum indent value for the 
    // comment column (default 32) can be given.
    // For debugging purposes a the argument PrintValues can be set to "true". In this
    // case the current values of the option values are printed
    void PrintOptions (ostream &os, 
		       unsigned LeftMargin = 2, 
		       unsigned CommentMaxIndent = 32, 
		       bool PrintValues = false);
  private:

    class OptNode { 
      public:
        char     shortop_;
        string   longop_;
        int      type_;
        unsigned arg_count_;
	string   comment_; 
        vector<void*> data_;
	unsigned print_width_;

        OptNode (void) {}
        OptNode (char shortop, const string &longop, 
		 int type, unsigned arg_count, const string &comment)
          : shortop_(shortop), longop_(longop), 
	    type_(type), arg_count_(arg_count), 
	    comment_(comment) { }
     };

    typedef list<OptNode> OptVector;

    void PrintOptionLine (ostream &os, OptVector::iterator i,
			  int mode, int left_margin, int offset_comment, 
			  int CommentMaxIndent);

    OptNode *FindOpt (char letter)
    {
      for (OptVector::iterator i = OptVec.begin(); i != OptVec.end(); ++i)
        if ( i->shortop_ == letter ) return &(*i);
      return 0;
    }

    OptNode *FindOpt (const string &str)
    {
      for (OptVector::iterator i = OptVec.begin(); i != OptVec.end(); ++i)
        if ( i->longop_ == str ) return &(*i);
      return 0;
    }

    bool assign (OptNode *node, const char *op[], string &error);
    OptVector OptVec;  // vector of the command line options
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
