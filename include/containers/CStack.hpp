/*!
 *  \file    CStack.hpp Template stack container class. Stack represents
 *           container that can implement LIFO (last in - first out)
 *           algorithm.
 *  \brief   Template stack container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template stack container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   05.02.2006 22:53:45

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
#ifndef __CSTACK_HPP__
#define __CSTACK_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IStack.hpp>
#include <Depth/include/common/containers/IStackConst.hpp>
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
class CStackIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CStackIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template stack container class.
/*!
    Stack  represents  container  with  LIFO  (last  in  -  first  out)  stock
    algorithm. For example, you insert item A into stack. Then you insert item
    B into stack. There is an item B on the top of the stack.  After  removing
    item B, there will be an item A on the top of the stack.

    \code
      Top-<--- Insert here
       |
    +-----+         +-----+         +-----+         +-----+
    |     |    Next |     |    Next |     |    Next |     |    Next
    |  1  |-------->|  2  |-------->|  3  |-------->|  4  |--------> NULL
    |     |         |     |         |     |         |     |
    +-----+         +-----+         +-----+         +-----+
       |
       +-->--- Remove from here
    \endcode

    <b>Overview.</b>\n
    \image html Stack.png "Stack."
    In computer science, a stack is a temporary abstract data  type  and  data
    structure based on the principle of Last In First Out (LIFO).  Stacks  are
    used extensively at every level of a modern computer system. For  example,
    a modern PC uses stacks at the architecture level, which are used  to  run
    an operating system. The operating system also uses stacks, which are used
    to run a Java Virtual Machine, which  is  stack  oriented,  and  the  Java
    language itself has a class called "Stack",  which  can  be  used  by  the
    programmer. The stack is ubiquitous.

    A stack-based computer system is one  that  stores  temporary  information
    primarily in stacks, rather than hardware CPU registers (a  register-based
    computer system).

    <b>Abstract data type.</b>\n
    As an abstract data type, the stack is a  container  (data  structure)  of
    nodes and has two basic operations: push and pop. Push adds a  given  node
    to the top of the stack leaving previous  nodes  below.  Pop  removes  and
    returns the current top node of the stack. A frequently used  metaphor  is
    the idea of a stack of plates in a spring loaded cafeteria stack. In  such
    a stack, only the top plate is visible and accessible  to  the  user,  all
    other plates remain hidden. As new plates are  added  (pushed),  each  new
    plate becomes the top of the stack, and hides each plate below. As  plates
    are removed (popped) from the stack, they can be used,  and  second  plate
    becomes the top of the stack. Two important principles are illustrated  by
    this metaphor, the Last In First Out principle is one. The second is  that
    the contents of the stack are hidden. Only the top plate is visible, so to
    see what is on the third plate, the first and second plates will  have  to
    be removed.

    <b>Other Operations.</b>\n
    In modern computer languages, the stack is usually implemented  with  more
    operations than just "push" and "pop". The length of a stack can often  be
    returned as a parameter. Another helper  operation  peek  can  return  the
    current top node of the stack without removing it from the stack.

    <b>Implementation.</b>\n
    A typical storage requirement for a stack  of  n  elements  is  O(n).  The
    typical time requirement of O(1) operations is also easy to  satisfy  with
    an dynamic array or (singly) linked list implementation.

    <b>History.</b>\n
    The stack method of expression evaluation  was  first  proposed  by  early
    German computer scientist F.L.  Bauer,  who  received  the  IEEE  Computer
    Society Pioneer Award in 1988 for his work on Computer Stacks.

    <b>References.</b>\n
    \li Donald Knuth. The Art of Computer Programming, Volume  1:  Fundamental
        Algorithms, Third Edition. Addison-Wesley, 1997.  ISBN  0-201-89683-4.
        Section 2.2.1: Stacks, Queues, and Deques, pp. 238-243.
    \li Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford
        Stein. Introduction to  Algorithms,  Second  Edition.  MIT  Press  and
        McGraw-Hill,  2001.  ISBN  0-262-03293-7.  Section  10.1:  Stacks  and
        queues, pp.200-204.

    <b>Taken from:</b>\n
    Stack (data structure) from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Stack_%28data_structure%29
*/
template <typename T_Type, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CStack :
  public NCommon::NContainers::IStack<CStack<T_Type, T_Allocator>, T_Type, CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >,
  public NCommon::NContainers::IStackConst<CStack<T_Type, T_Allocator>, T_Type, CStackIterator<T_Type, T_Allocator>, CStackIteratorConst<T_Type, T_Allocator> >
{
  // Friend class: Stack iterator class (CStackIterator).
  friend class CStackIterator<T_Type, T_Allocator>;
  // Friend class: Constant stack iterator class (CStackIteratorConst).
  friend class CStackIteratorConst<T_Type, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CStack<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CStack class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef T_Type TType;
  //! Container type.
  typedef CStack<T_Type, T_Allocator> TContainer;
  //! Non constant stack iterator type.
  typedef CStackIterator<T_Type, T_Allocator> TIterator;
  //! Constant stack iterator type.
  typedef CStackIteratorConst<T_Type, T_Allocator> TIteratorConst;

  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty stack.

      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CStack(const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize stack with one item.
  /*!
      Create an empty stack, then insert item into it.

      \param a_crItem - Constant reference to the item to insert.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CStack(const T_Type& a_crItem, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStack class.
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CStack(const CStack<T_Type, T_Allocator>& a_crInstance, const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CStack();

  //! Operator: Assign another CStack class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStack class.
      \return Reference to the current class instance.
  */
  CStack<T_Type, T_Allocator>& operator = (const CStack<T_Type, T_Allocator>& a_crInstance);

  //! Set another CStack class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStack class.
      \return true  - if another stack was successfully set. \n
              false - if another stack was not successfully set. \n
  */
  Tbool set(const CStack<T_Type, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IStack interface overriding methods.
  virtual Tbool insertTop(const T_Type& a_crItem);
  virtual Tbool removeTop();
  virtual Tbool removeTop(T_Type& a_rItem);

  // IStackConst interface overriding methods.
  virtual TIterator      getItTop();
  virtual TIteratorConst getItTop() const;

  //! Reverse stack.
  /*!
      Reverse stack items order.
  */
  void reverse();

  //! Serialization load CStack class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStack class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStack class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStack class instances.
  /*!
      \param a_rInstance - Reference to another CStack class instance.
  */
  void swap(CStack<T_Type, T_Allocator>& a_rInstance);

protected:
  struct SStackNode                     //! Stack node structure.
  {
  public:
    T_Type      m_Item;                 //!< Stack item value.
    SStackNode* m_pNext;                //!< Pointer to the next stack node.

    //! Initialize stack node with the given item.
    /*!
        \param a_crItem - Initialized item.
    */
    SStackNode(const T_Type& a_crItem);
  };

private:
  Tuint       m_Size;                   //!< Number of items in stack.
  SStackNode* m_pTop;                   //!< Pointer to the top stack node.
  T_Allocator m_Allocator;              //!< Memory allocator.
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
//! Traits meta-class: stack container traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsContainer<NContainers::CStack<T_Type, T_Allocator> > :
  public MType<NContainers::CStack<T_Type, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CStack<T_Type, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CStack<T_Type, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CStack<T_Type, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CStack<T_Type, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = true;  //!< Is container non constant stack?
  static const Tbool isStackConst       = true;  //!< Is container constant stack?
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
#include <Depth/include/containers/iterators/CStackIterator.hpp>
#include <Depth/include/containers/iterators/CStackIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CStack.inl>
/*==========================================================================*/
//! \example example-containers-CStack.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CStack.cpp
/*==========================================================================*/
#endif
