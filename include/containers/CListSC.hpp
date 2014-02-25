/*!
 *  \file    CListSC.hpp Template single circled list container class. Single
 *           circled list represents one-directed ring container.
 *  \brief   Template single circled list container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template single circled list container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   17.02.2006 21:20:28

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __CLISTSC_HPP__
#define __CLISTSC_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/ICircleSingleLinked.hpp>
#include <Depth/include/common/containers/ICircleSingleLinkedConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/memory/allocators/CAllocatorMemory.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CListSCIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CListSCIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template single circled list container class.
/*!
    Single circled list represents one-directed ring  container.  It  has  one
    current item. You can change it with stepping forward. And  also  you  can
    insert/remove items  in/from  current  or  in/from  next  to  the  current
    position.

    \code
                    +-----+            +-----+
                    |     |       Next |     |
    Current-------->|  1  |----------->|  2  |
                    |     |            |     |
                    +-----+            +-----+
                      /|\                 |
                       | N              N |
                       | e              e |
                       | x              x |
                       | t              t |
                       |                 \|/
                    +-----+            +-----+
                    |     | Next       |     |
                    |  4  |<-----------|  3  |
                    |     |            |     |
                    +-----+            +-----+
    \endcode

    <b>Overview.</b>\n
    In computer science,  a  linked  list  is  one  of  the  fundamental  data
    structures used in computer programming. It  consists  of  a  sequence  of
    nodes, each containing arbitrary data fields and  one  or  two  references
    ("links") pointing to the next and/or previous nodes. A linked list  is  a
    self-referential datatype because it contains a pointer or link to another
    data of the same type. Linked lists permit insertion and removal of  nodes
    at any point in the list in constant time, but do not allow random access.
    Several  different  types  of  linked  list  exist:  singly-linked  lists,
    doubly-linked lists, and circularly- linked lists.

    Linked lists can be implemented in most languages. Languages such as  Lisp
    and Scheme have the data structure built  in,  along  with  operations  to
    access the linked list. Procedural languages such  as  C,  C++,  and  Java
    typically rely on mutable references to create linked lists.

    <b>Circularly-linked list.</b>\n
    In a  circularly-linked  list,  the  first  and  final  nodes  are  linked
    together. This can be done for both singly and  doubly  linked  lists.  To
    traverse a circular linked list, you begin at any node and follow the list
    in either direction until you return to the original node. Viewed  another
    way, circularly-linked lists can be seen as having no  beginning  or  end.
    This type of list is most useful for managing buffers for data ingest, and
    in cases where you have one object in a list and wish  to  see  all  other
    objects in the list.

    The pointer pointing to the whole list is usually called the end pointer.

    <b>Singly-circularly-linked list.</b>\n
    In a singly-circularly-linked list, each node has one link,  similarly  to
    an ordinary singly-linked list, except that the next link of the last node
    points back to the first node. As in a singly-linked list, new  nodes  can
    only be efficiently inserted after a node we already have a reference  to.
    For this reason, it's usual to retain a reference to only the last element
    in a singly-circularly-linked list, as this allows quick insertion at  the
    beginning, and also allows access to  the  first  node  through  the  last
    node's next pointer.

    <b>Applications of linked lists.</b>\n
    Linked lists are used as a building block for many other data  structures,
    such as stacks, queues and their variations.

    The "data" field of a node can be another linked list. By this device, one
    can construct many  linked  data  structures  with  lists;  this  practice
    originated in the Lisp programming language,  where  linked  lists  are  a
    primary (though by no means the only) data structure, and is now a  common
    feature of the functional programming style.

    Sometimes, linked lists are used to implement associative arrays, and  are
    in this context called association lists. There is very little good to  be
    said about this use of linked lists; they are easily outperformed by other
    data structures such as self-balancing binary search trees even  on  small
    data sets (see the discussion in associative array). However, sometimes  a
    linked list is dynamically created out of a subset  of  nodes  in  such  a
    tree, and used to more efficiently traverse that set.

    <b>Speeding up search.</b>\n
    Finding a specific element in  a  linked  list,  even  if  it  is  sorted,
    normally requires O(n) time (linear search). This is one  of  the  primary
    disadvantages of linked lists over other data structures. In  addition  to
    some of the variants discussed in the above section, there are  number  of
    simple ways of improving search time.

    In an unordered list, one simple heuristic for decreasing  average  search
    time is the move-to-front heuristic, which simply moves an element to  the
    beginning of the list once it is found. This scheme,  handy  for  creating
    simple caches, ensures that the most recently  used  items  are  also  the
    quickest to find again.

    Another common approach is to "index" a linked list using a more efficient
    external data structure. For example, one can build a  red-black  tree  or
    hash table whose  elements  are  references  to  the  linked  list  nodes.
    Multiple such indexes can be built on a single list. The  disadvantage  is
    that these indexes may need to be updated each time a  node  is  added  or
    removed (or at least, before that index is used again).

    <b>References.</b>\n
    \li National Institute of Standards  and  Technology  (August  16,  2004).
        Definition of a linked list. Retrieved December 14, 2004.
    \li Antonakos, James L. and Mansfield,  Kenneth  C.,  Jr.  Practical  Data
        Structures Using C/C++ (1999). Prentice-Hall. ISBN 0-13-280843-9,  pp.
        165-190
    \li Collins, William J. Data Structures and the Java Collections Framework
        (2002,2005) New York, NY: McGraw Hill. ISBN 0-07-282379-8, pp. 239-303
    \li Cormen, Thomas H.; Leiserson, Charles E.; Rivest,  Ronald  L.;  Stein,
        Clifford  Introductions  to  Algorithms  (2003).   MIT   Press.   ISBN
        0-262-03293-7, pp. 205-213, 501-505
    \li Green, Bert F. Jr. (1961). Computer Languages for Symbol Manipulation.
        IRE Transactions on Human Factors in Electronics. 2 pp. 3-8.
    \li McCarthy, John (1960). Recursive Functions of Symbolic Expressions and
        Their Computation by Machine, Part I. Communications of the ACM.  HTML
        DVI PDF PostScript
    \li Donald Knuth. Fundamental Algorithms, Third  Edition.  Addison-Wesley,
        1997. ISBN 0-201-89683-4. Sections 2.2.3-2.2.5, pp.254-298.
    \li Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford
        Stein. Introduction to  Algorithms,  Second  Edition.  MIT  Press  and
        McGraw-Hill, 2001. ISBN 0-262-03293-7.  Section  10.2:  Linked  lists,
        pp.204-209.
    \li Newell, Allen and Shaw, F. C. (1957).  Programming  the  Logic  Theory
        Machine. Proceedings of the Western  Joint  Computer  Conference.  pp.
        230-240.
    \li Parlante, Nick (2001). Linked list basics. Stanford University. PDF
    \li Sedgewick,  Robert  Algorithms  in  C  (1998).  Addison  Wesley.  ISBN
        0-201-31452-5, pp. 90-109
    \li Shaffer, Clifford A. A Practical Introduction to Data  Structures  and
        Algorithm Analysis (1998). NJ: Prentice Hall. ISBN 0-13-660911-2,  pp.
        77-102
    \li Wilkes, Maurice Vincent (1964). An Experiment  with  a  Self-compiling
        Compiler for a  Simple  List-Processing  Language.  Annual  Review  in
        Automatic Programming 4, 1. Published by Pergamon Press.
    \li Wilkes, Maurice  Vincent  (1964).  Lists  and  Why  They  are  Useful.
        Proceeds of  the  ACM  National  Conference,  Philadelphia  1964  (ACM
        Publication P-64 page F1-1); Also Computer Journal 7, 278 (1965).
    \li Kulesh Shanmugasundaram (April 4,  2005).  Linux  Kernel  Linked  List
        Explained.

    <b>Taken from:</b>\n
    Linked list from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Linked_list
*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CListSC :
  public NCommon::NContainers::ICircleSingleLinked<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >,
  public NCommon::NContainers::ICircleSingleLinkedConst<CListSC<T_Type, T_Allocator>, T_Type, CListSCIterator<T_Type, T_Allocator>, CListSCIteratorConst<T_Type, T_Allocator> >
{
  // Friend class: Single circled list iterator class (CListSCIterator).
  friend class CListSCIterator<T_Type, T_Allocator>;
  // Friend class: Constant single circled list iterator class (CListSCIteratorConst).
  friend class CListSCIteratorConst<T_Type, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CListSC<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CListSC class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CListSC<T_Type, T_Allocator> TContainer;
  //! Non constant single circled list iterator type.
  typedef CListSCIterator<T_Type, T_Allocator> TIterator;
  //! Constant single circled list iterator type.
  typedef CListSCIteratorConst<T_Type, T_Allocator> TIteratorConst;

  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty single circled list.

      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CListSC(const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize single circled list with one item.
  /*!
      Create an empty single circled list, then insert item into it.

      \param a_crItem - Constant reference to the item to insert.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CListSC(const T_Type& a_crItem, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CListSC class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CListSC(const CListSC<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CListSC();

  //! Operator: Assign another CListSC class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CListSC class.
      \return Reference to the current class instance.
  */
  CListSC<T_Type, T_Allocator>& operator = (const CListSC<T_Type, T_Allocator>& a_crInstance);

  //! Set another CListSC class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CListSC class.
      \return true  - if another single circled list was successfully set. \n
              false - if another single circled list was not successfully set. \n
  */
  Tbool set(const CListSC<T_Type, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // ICircleSingleLinked interface overriding methods.
  virtual Tbool insertCurrent(const T_Type& a_crItem);
  virtual Tbool insertNext(const T_Type& a_crItem);
  virtual Tbool removeCurrent();
  virtual Tbool removeCurrent(T_Type& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(T_Type& a_rItem);

  // ICircleSingleLinkedConst interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual TIterator      getItCurrent();
  virtual TIteratorConst getItCurrent() const;
  virtual TIterator      getItNext();
  virtual TIteratorConst getItNext() const;

  //! Reverse single circled list.
  /*!
      Reverse single circled list items order.
  */
  void reverse();

  //! Serialization load CListSC class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CListSC class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CListSC class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CListSC class instances.
  /*!
      \param a_rInstance - Reference to another CListSC class instance.
  */
  void swap(CListSC<T_Type, T_Allocator>& a_rInstance);

protected:
  struct SListSCNode                    //! Single circled list node structure.
  {
  public:
    T_Type       m_Item;                //!< Single circled list item value.
    SListSCNode* m_pNext;               //!< Pointer to the next single circled list node.

    //! Initialize single circled list node with the given item.
    /*!
        \param a_crItem - Initialized item.
    */
    SListSCNode(const T_Type& a_crItem);
  };

private:
  Tuint        m_Size;                  //!< Number of items in single circled list.
  SListSCNode* m_pCurrent;              //!< Pointer to the current single circled list node.
  T_Allocator  m_Allocator;             //!< Memory allocator.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: single circled list container traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsContainer<NContainers::CListSC<T_Type, T_Allocator> > :
  public MType<NContainers::CListSC<T_Type, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CListSC<T_Type, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CListSC<T_Type, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CListSC<T_Type, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CListSC<T_Type, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = true;  //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = true;  //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = false; //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = false; //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = false; //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CListSCIterator.hpp>
#include <Depth/include/containers/iterators/CListSCIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CListSC.inl>
/*==========================================================================*/
//! \example example-containers-CListSC.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CListSC.cpp
/*==========================================================================*/
#endif
