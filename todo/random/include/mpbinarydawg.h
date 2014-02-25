/*-----------------------------------------------------------------------------*\
| Matpack - Directed Acyclic Word Graphs (DAWG)                  mpbinarydawg.h |
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

#ifndef _MPDAWG_
#define _MPDAWG_

#include <iostream>

namespace MATPACK {
using std::ostream;

//---------------------------------------------------------------------------//
// Structure of a node in a Directed Acyclic Word Graph (DAWG)
//---------------------------------------------------------------------------//

struct MpBinaryDawgNode 
{
  MpBinaryDawgNode   *edge1,  // edge 1
                     *edge2,  // edge 2
                     *suffix; // suffix node pointer
  
  int depth;            // depth of node

  unsigned char state;  // state coding:
                        // bit 0: set if edge 1 is a valid edge
                        // bit 1: set if edge 1 is a primary edge (else secondary)
                        // bit 2: set if edge 2 is a valid edge
                        // bit 3: set if edge 2 is a primary edge (else secondary)
                        // bit 4: symbol (bit) of edge 1
                        // bit 5: symbol (bit) of edge 2
};

//---------------------------------------------------------------------------//
// class MpBinaryDawg: Directed Acyclic Word Graph (DAWG)
//---------------------------------------------------------------------------//

class MpBinaryDawg
{
  private:
    int branchnode_depth;
    int node_number;
    MpBinaryDawgNode *source, *currentsink;

    MpBinaryDawgNode* AppendSymbol (MpBinaryDawgNode *source,
                                    MpBinaryDawgNode *activenode, 
                                    unsigned char a);
    MpBinaryDawgNode* Split (MpBinaryDawgNode *originnode, 
                             MpBinaryDawgNode *targetnode);

  public:
    //-----------------------------------------------------------------------//
    // Constructor
    //-----------------------------------------------------------------------//
    MpBinaryDawg (void);

    //-----------------------------------------------------------------------//
    // Destructor
    // Note, that the nodes of all instances of class MpBinaryDawg, generated
    // by calls to Build() or Addbit(), are allocated on a common heap. For efficiency 
    // resons nodes are allocated in blocks of 1000. The destructor
    // does not free the nodes of one instance of class MpBinaryDawg if there is
    // still another active instance of class MpBinaryDawg in the same scope. 
    // Only if the destructor of the last instance is called the whole 
    // heap of nodes is freed.
    //
    // Example 1:
    //    { MpBinaryDawg A,B; ...
    //    } <--- the nodes of A and B are freed here
    //
    // Example 2:
    //    { MpBinaryDawg A; ...
    //       { MpBinaryDawg B; ... 
    //       } <--- the nodes of B are not freed here
    //       ...
    //    } <--- the nodes of A and B are freed here
    //
    //-----------------------------------------------------------------------//
    ~MpBinaryDawg (void);

    //-----------------------------------------------------------------------//
    // Build a Directed Acyclic Word Graph (DAWG) for a binary sequence w
    // of length n. The argument string w must contain only the ASCII
    // characters '0' or '1', which are interpreted as the binary values 0 or 1, 
    // respectively. 
    // A pointer to the source node of the DAWG is returned.
    //-----------------------------------------------------------------------//
    MpBinaryDawgNode* Build (unsigned n, const char w[]);

    //-----------------------------------------------------------------------//
    // Add one bit to the DAWG. This function is used for building
    // the DAWG sequentially. It can also be called after Build(...) to 
    // add additional bits. In contrast to Build(...) bit values 0 or 1
    // are expected as argument, not the ASCII characters '0' or '1'.
    //-----------------------------------------------------------------------//
    void AddBit (unsigned char b);

    //-----------------------------------------------------------------------//
    // Return the branch node depth D(w) of the DAWG of the string w.
    // D(w) is the maximum depth the set of equivalence classes that  
    // have more than one outgoing edge. If the DAWG has not been built
    // by a call to Build(...) the value -1 is returned.
    //-----------------------------------------------------------------------//
    int BranchNodeDepth (void) const { return branchnode_depth; }

    //-----------------------------------------------------------------------//
    // Return the maximum order complexity MOC(w) of the string w. 
    // The maximum order complexity is defined as the length of the shortest
    // feedback shift register (FSR) for which there exists a memoryless
    // feedback mapping, such that the FSR can generate the sequence w.
    // It holds: MOC(w) is equal to D(w)+1. If the DAWG has not been built
    // by a call to Build(...) the value 0 is returned.
    //-----------------------------------------------------------------------//
    int MaxOrderComplexity (void) const { return branchnode_depth+1; }

    //-----------------------------------------------------------------------//
    // Return number of nodes of DAWG after a call to Build(...) or
    // several calls to AddBit(...).
    // If the DAWG has not been built the value 0 is returned.
    //-----------------------------------------------------------------------//
    int NodeNumber (void) const { return node_number; }

    //-----------------------------------------------------------------------//
    // Return a pointer to the source node.
    // If the DAWG has not been built the value 0 is returned.
    //-----------------------------------------------------------------------//
    MpBinaryDawgNode* Source (void) const { return source; }

    //-----------------------------------------------------------------------//
    // Dump the DAWG to the stream os for debugging purposes
    //-----------------------------------------------------------------------//
    void Dump (ostream &os, const MpBinaryDawgNode *source);

    //-----------------------------------------------------------------------//
    // Free the nodes of all instances of class MpBinaryDawg created so far
    //-----------------------------------------------------------------------//
    static void FreeAllDAWGs (void);
};

} // namespace MATPACK

//---------------------------------------------------------------------------//

#endif
