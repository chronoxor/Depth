/*-----------------------------------------------------------------------------*\
| Matpack - template class for binary tree representation        mpbinarytree.h |
|                                                                               |
| Last change: Aug 25, 2006                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2006 by Berndt M. Gammel                                   |
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

#ifndef _MPBINARYTREE_H_
#define _MPBINARYTREE_H_

#include <iostream>
#include <set>
#include "common.h"

namespace MATPACK {
using std::ostream;
using std::set;

//----------------------------------------------------------------------------//
//
//  Template <class T, class V> class MpBinaryTree
//
//  is an object representing a node in a binary tree.
//  All objects of this class are expected to be allocated by operator new.
//  The value type V must be a concrete type with a copy constructor
//  and an assignment operator.
//  The node type T is used to assign a type to a node.
//  Type V must be comparable with 'LessThan', i.e. it supports the 
//  operators '<' and '=='.
//
//----------------------------------------------------------------------------//

template <class T, class V> class MpBinaryTree
{
  public:

    //------------------------------------------------------------------------//
    //  Constructor:
    //  Creates a leaf node with the given initial value 'init' of base type V. 
    //  Type V must have a constructor that requires no arguments.
    //  If the print() method is called, there must be a method
    //  of the form operator << (ostream &, const V &).
    //
    //  Arguments:
    //  ----------
    //	  T t             type of the node
    //    const V &init   initial value, which defaults to the value generated
    //                    by the empty constructor V().
    //                    The node type as well as the left and right subtree 
    //                    pointers are initialized to zero. 
    //------------------------------------------------------------------------//
    MpBinaryTree (T t, const V &init = V());

    //------------------------------------------------------------------------//
    //  Constructor:
    //	Creates a node of the given type 't' of base type T and assigns the
    //  the given subtrees to the left and the right branch, respectively.
    //  It is expected that the subtrees have been allocated by calling the
    //  'new' operator as the destructor will call the 'delete' operator for
    //  the left and right subtrees of this node.
    // 
    //  Arguments:
    //  ----------
    //	  T             t    type of the node
    //	  MpBinaryTree *l    subtree attached to the left-hand side (may be 0)
    //	  MpBinaryTree *r    subtree attached to the right-hand side (may be 0)
    //
    //	Examples:
    //  ---------
    //   enum Token { VALUE = 0, PLUS = 1, TIMES = 2 };
    //	 MpBinaryTree<int,float> 
    //          *left  = new MpBinaryTree<int,float>(3.141),
    //	        *right = new MpBinaryTree<int,float>(2.718),
    //          *root  = new MpBinaryTree<int,float>(PLUS,left,right);
    //   delete root;
    //------------------------------------------------------------------------//
    MpBinaryTree (T t, MpBinaryTree<T,V> *l, MpBinaryTree<T,V> *r);

    //------------------------------------------------------------------------//
    //  Destructor:
    //  Calls the 'delete' operator for the left and right subtrees of this node.
    //  Hence the complete tree is deleted recursively.
    //------------------------------------------------------------------------//

    virtual ~MpBinaryTree() 
    {
      delete left;
      delete right;
    }

    //------------------------------------------------------------------------//
    //  Returns the type of this node.
    //------------------------------------------------------------------------//
    T GetType (void) const;

    //------------------------------------------------------------------------//
    //  Changes the type of this node.
    // 
    //  Arguments:
    //  ----------
    //    T t    The type assigned to this node
    //------------------------------------------------------------------------//
    void SetType (T t);

    //------------------------------------------------------------------------//
    //  Checks type of this node.
    // 
    //  Arguments:
    //  ----------
    //    T t                    The type to compare with the node type
    //
    //  Returns:
    //  --------
    //    bool                   true, if the the node is of type t
    //------------------------------------------------------------------------//
    bool IsType (T t) const;

    //------------------------------------------------------------------------//
    //  Returns a reference to the value of this node.
    //  GetValue() should only be called on a node for which GetType()
    //  returns a type indicating that it is a node containing a valid value.
    //------------------------------------------------------------------------//
    const V& GetValue (void) const;

    //------------------------------------------------------------------------//
    //  Returns a reference to the value of this node.
    //  GetValue() should only be called on a node for which GetType()
    //  returns a type indicating that it is a node containing a valid value.
    //------------------------------------------------------------------------//
    V& GetValue (void);

    //------------------------------------------------------------------------//
    //  Changes the value of this node.
    //  This method should only be called on a node for which GetType()
    //  returns a type indicating that it is a node containing a value.
    //  The given value is copied into this node's value field.
    // 
    //  Arguments:
    //  ----------
    //    const V &v    value to copy to this node
    //------------------------------------------------------------------------//
    void SetValue (const V &v);


    //------------------------------------------------------------------------//
    //  Returns the left-hand branch of this node.
    //------------------------------------------------------------------------//
    const MpBinaryTree* GetLeft (void) const;

    //------------------------------------------------------------------------//
    //  Returns the left-hand branch of this node.
    //  Operator 'delete' should not be called on the subtree returned
    //  by GetLeft().  Only the root of a tree should
    //  be the target of a destructor.
    //------------------------------------------------------------------------//
    MpBinaryTree*& GetLeft (void);

    //------------------------------------------------------------------------//
    //  Attaches a subtree as this node's left-hand branch.
    //  If this node already had a non-null left-hand branch, it is
    //  not destroyed before attaching the new branch.
    // 
    //  Arguments:
    //  ----------
    //    MpBinaryTree *subtree	   the subtree to attach (may be 0)
    //------------------------------------------------------------------------//
    void SetLeft (MpBinaryTree *subtree);

    //------------------------------------------------------------------------//
    //  Returns the right-hand branch of this node.
    //------------------------------------------------------------------------//
    const MpBinaryTree* GetRight (void) const;

    //------------------------------------------------------------------------//
    //  Returns the right-hand branch of this node.
    //  Operator 'delete' should not be called on the subtree returned
    //  by GetRight().  Only the root of a tree should
    //  be the target of a destructor.
    //------------------------------------------------------------------------//
    MpBinaryTree*& GetRight (void);

    //------------------------------------------------------------------------//
    //  Attaches a subtree as this node's right-hand branch.
    //  If this node already had a non-null right-hand branch, it is
    //  not destroyed before attaching the new branch.
    // 
    //  Arguments:
    //  ----------
    //    MpBinaryTree *subtree	   the subtree to attach (may be 0)
    //------------------------------------------------------------------------//
    void SetRight (MpBinaryTree *subtree);

    //------------------------------------------------------------------------//
    // Swap the left and the right subtrees
    //------------------------------------------------------------------------//
    void SwapLeftRight (void);
    
    //------------------------------------------------------------------------//
    // Clone the given tree
    //------------------------------------------------------------------------//
    MpBinaryTree *CloneTree (void) const;

    //------------------------------------------------------------------------//
    // Returns the values that are used in the tree. This method 
    // recursively walks down non-NULL left and non-NULL right subtrees and adds
    // the values of all nodes matching the type 'valuetype' to the set 'vars'.
    // 
    //  Arguments:
    //  ----------
    //    T valuetyp     type indicating a node containing a value
    //    set<V> &vars   set to which all values in the tree are added to
    //------------------------------------------------------------------------//
    void GetValues (T valuetype, set<V> &vars) const;

    //------------------------------------------------------------------------//
    //  Prints the binary subtree starting with this node to a stream.
    //  There must be a method of the form
    //
    //            operator << (ostream &os, const V &).
    //
    //  Typically the method will be overloaded to produce an appropriate 
    //  representation, e.g. for a syntax parse-tree.
    //
    //  The default Print() method recognizes a node which has neither left-and
    //  nor right-hand branches as a value node and prints the value. All other
    //  nodes are printed as a list (type left-branch right-branch). 
    //  A non-existing branch is printed as 'NIL'.
    //
    //  Arguments:
    //  ----------
    //    ostream &os	           stream to which the subtree representation is written
    //    MpBinaryTree<T,V> *tree  subtree to print
    //    unsigned format = 0      NOT YET IMPLEMENTED
    //------------------------------------------------------------------------//
    static void Print (ostream &os, MpBinaryTree<T,V> *tree, unsigned format = 0);

  private:
    T type;
    V value;
    MpBinaryTree *left;
    MpBinaryTree *right;
};

//----------------------------------------------------------------------------//
// inline implementation
//----------------------------------------------------------------------------//

template <class T, class V> 
MpBinaryTree<T,V>::MpBinaryTree (T t, const V &init)
  : type(t), value(init), left(0), right(0)
{
}

template <class T, class V>
MpBinaryTree<T,V>::MpBinaryTree (T t, MpBinaryTree *l, MpBinaryTree *r)
  : type(t), value(), left(l), right(r)
{
}

//----------------------------------------------------------------------------//

template <class T, class V>
inline const MpBinaryTree<T,V>* MpBinaryTree<T,V>::GetLeft (void) const
{
  return left;
}


template <class T, class V>
inline MpBinaryTree<T,V>*& MpBinaryTree<T,V>::GetLeft (void)
{
  return left;
}


template <class T, class V>
inline void MpBinaryTree<T,V>::SetLeft (MpBinaryTree *subtree)
{
  left = subtree;
}
//----------------------------------------------------------------------------//


template <class T, class V>
inline const MpBinaryTree<T,V>* MpBinaryTree<T,V>::GetRight (void) const
{
  return right;
}


template <class T, class V>
inline MpBinaryTree<T,V>*& MpBinaryTree<T,V>::GetRight (void)
{
  return right;
}

template <class T, class V>
inline void MpBinaryTree<T,V>::SetRight (MpBinaryTree *subtree)
{
  right = subtree;
}

//----------------------------------------------------------------------------//
   
template <class T, class V> 
inline void MpBinaryTree<T,V>::SwapLeftRight (void)
{
  MpBinaryTree<T,V> *tmp = left;
  left = right;
  right = tmp;
}

//----------------------------------------------------------------------------//

template <class T, class V> 
inline MpBinaryTree<T,V>* MpBinaryTree<T,V>::CloneTree (void) const
{
  MpBinaryTree<T,V> *clone = new MpBinaryTree<T,V>(type,
						   left ? left->CloneTree() : 0,
						   right ? right->CloneTree() : 0);
  clone->value = value;
  return clone;
}

//----------------------------------------------------------------------------//

template <class T, class V> 
inline const V& MpBinaryTree<T,V>::GetValue (void) const
{
  return value;
}

template <class T, class V>
inline V& MpBinaryTree<T,V>::GetValue (void)
{
  return value;
}

template <class T, class V>
inline void MpBinaryTree<T,V>::SetValue (const V &v)
{
  value = v;
}

//----------------------------------------------------------------------------//

template <class T, class V>
inline T MpBinaryTree<T,V>::GetType (void) const
{
  return type;
}

template <class T, class V>
inline void MpBinaryTree<T,V>::SetType(T t)
{
  type = t;
}

template <class T, class V>
inline bool MpBinaryTree<T,V>::IsType (T t) const
{
  return (type == t);
}

//----------------------------------------------------------------------------//

template <class T, class V>
void MpBinaryTree<T,V>::GetValues (T valuetype, set<V> &vars) const
{
  if (type == valuetype)
    vars.insert(value);                            // insert value into set

  if (left)  left->GetValues(valuetype, vars);     // follow left subtree
  if (right) right->GetValues(valuetype, vars);    // follow right subtree
}

//----------------------------------------------------------------------------//

template <class T, class V>
inline ostream& operator << (ostream &os, const MpBinaryTree<T,V> *subtree)
{
  if (subtree) Print(os,subtree);
  return os;
}

//----------------------------------------------------------------------------//

template <class T, class V>
void MpBinaryTree<T,V>::Print (ostream &os, MpBinaryTree<T,V> *tree, unsigned format)
{
  if (!tree)
    os << "NIL";
  else if (!tree->left && !tree->right) { 
    // leaf node: print value
    os << tree->value;
  } else {               
    // otherwise print list (type, left-branch, right-branch)
    os << "(";
    os << tree->type;
    os << ", ";
    if (tree->left) 
      Print(os,tree->left);
    else
      os << "NIL";
    os << ", ";
    if (tree->right)
      Print(os,tree->right);
    else
    os << "NIL";
    os << ")";
  }
}

} // namespace MATPACK

#endif

//----------------------------------------------------------------------------//
