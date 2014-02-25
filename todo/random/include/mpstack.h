/*-----------------------------------------------------------------------------*\
| class MpStack - simple and fast stack template class                mpstack.h |
|                                                                               |
| ***************************************************************************** |
| *********  Deprecated class. You should prefer STL stack templates ********** |
| ***************************************************************************** |
|                                                                               |
| Last change: Dec 17, 2005                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2005 by Berndt M. Gammel. All rights reserved.             |
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

//-----------------------------------------------------------------------------//
// class MpStack: general and fast stack template class
//-----------------------------------------------------------------------------//

#ifndef _MPSTACK_H_
#define _MPSTACK_H_

//#define DEBUG_MPSTACK

template <class T> 
class MpStack 
{
  private:
    T *base, *top, *end;

  public:

    int Empty (void) { return (top == base); }	// check if stack is emptied
    int Full (void) { return (top == end); } 	// check if stack reached limit
    operator int () { return (end > base); }	// check if stack is allocated
    int operator !() { return (end == base); }	// check if stack is not allocated
    int Elements (void) { return int(top-base); }  // current number of elements
    int MaxElements (void) { return int(end-base); }  // maximum number of elements
    int Size (void) { return int(end-base)*sizeof(T); }  // stack size in bytes

    ~MpStack (void)	// remove stack from memory
    {
#ifdef DEBUG_MPSTACK
        cerr << "MpStack::~MpStack" << endl;
#endif
	delete [] base;
	base = top = end = (T *)0;
    }
 
    void Resize (int n)	// initialize stack to hold a maximum of n entries
    {
	if (base) this->MpStack<T>::~MpStack(); // remove if already allocated

	if ((n > 0) && (base = new T[n])) {  // allocate
	    top = base;
	    end = base+n;
	} else 
	    base = top = end = (T *)0;
    }

    MpStack (int n)	// allocate stack to hold a maximum of n entries
    {
        base = (T *)0;
	Resize(n);
    }

    MpStack (void)			// define non-allocated stack
    {
	base = top = end = (T *)0;
    }

    MpStack (const MpStack& src)	// complete copy of stack
    {
#ifdef DEBUG_MPSTACK
        cerr << "MpStack::MpStack(const MpStack& src)" << endl;
#endif
        int n = src.end - src.base;
        base = new T[n];
	memcpy((void*)base,(void*)src.base,n*sizeof(T));
	end = base+n;
	top = base + (src.top-src.base);
    }

    MpStack& operator = (const MpStack& src)	// complete copy of stack
    {
#ifdef DEBUG_MPSTACK
        cerr << "MpStack::operator=(const MpStack& src)" << endl;
#endif
	if (base) this->MpStack::~MpStack();
        int n = src.end - src.base;
        base = new T[n];
	memcpy((void*)base,(void*)src.base,n*sizeof(T));
	end = base+n;
	top = base + (src.top-src.base);
	return *this;
    }


    void Push (T x)			// push object
    {
	if (top < end) *top++ = x;
    }

    void Pop (T& x)	// pop object - return in argument
    {
	if (top > base) x = *--top;
    }

    T Pop (void)	// pop object - return as function
    {
        if (top > base) return *--top; 
        // !!!! what if empty ??????
	return *base;
    }
   
};

//-----------------------------------------------------------------------------//

#endif

