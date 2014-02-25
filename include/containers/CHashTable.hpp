/*!
 *  \file    CHashTable.hpp Template hash table container base class.
 *  \brief   Template hash table container base class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template hash table container base class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   11.06.2008 02:11:16

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
#ifndef __CHASHTABLE_HPP__
#define __CHASHTABLE_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FHashString.hpp>
#include <Depth/include/algorithms/functions/FHashStringComparator.hpp>
#include <Depth/include/algorithms/functions/FHashStringComparatorIgnoreCase.hpp>
#include <Depth/include/common/containers/IAssociative.hpp>
#include <Depth/include/common/containers/IAssociativeConst.hpp>
#include <Depth/include/common/containers/IDequeConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/functions/MConceptHashFunction.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/types/MConceptIResizePolicy.hpp>
#include <Depth/include/containers/policy/CResizePolicySquareGrow.hpp>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/memory/allocators/CAllocatorMemory.hpp>
#include <Depth/include/utility/CPair.hpp>
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
template <typename T_Key, typename T_Value, class T_KeyHashFunction = NAlgorithms::NFunctions::FHashString<T_Key>, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FHashStringComparator<T_Key>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CHashTableIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction = NAlgorithms::NFunctions::FHashString<T_Key>, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FHashStringComparator<T_Key>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CHashTableIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction = NAlgorithms::NFunctions::FHashString<T_Key>, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FHashStringComparator<T_Key>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CHashTableChain;
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction = NAlgorithms::NFunctions::FHashString<T_Key>, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FHashStringComparator<T_Key>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CHashTableOpenAddress;
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template hash table container class.
/*!
    Hash tables are efficient structures for  associative  keys/value  storing
    and accessing. They use hash function  to  convert  string  key  into  the
    integer and use the index to quick access value data.

    <b>Overview.</b>\n
    In computer science, a hash table, or a hash map, is a data structure that
    associates keys with values. The primary operation it supports efficiently
    is a lookup: given a key (e.g. a person's name),  find  the  corresponding
    value (e.g. that person's telephone number). It works by transforming  the
    key using a hash function into a hash, a number that is used as  an  index
    in an array to locate the desired location  ("bucket")  where  the  values
    should be.

    Hash tables support the efficient insertion of new  entries,  in  expected
    O(1) time. The time spent in searching depends on the  hash  function  and
    the load of the hash table; both insertion and search approach  O(1)  time
    with well chosen values and hashes.

    \image html HashTable.png "A small phone book as a hash table."

    <b>Basic operation.</b>\n
    A hash table works by transforming the key using a hash  function  into  a
    hash, a number that is used as an index in an array to locate the  desired
    location ("bucket") where the values should be.  The  number  is  normally
    converted into the index by taking a modulo, or sometimes bit  masking  is
    used where the array size is a power of two. The optimal hash function for
    any given use of a hash table can vary widely, however, depending  on  the
    nature of the key.

    Typical operations on a hash table include insertion, deletion and  lookup
    (although some hash tables are precalculated  so  that  no  insertions  or
    deletions, only lookups are done on a live system). These  operations  are
    all performed in amortized constant  time,  which  makes  maintaining  and
    accessing a huge hash table very efficient.

    <b>Collision resolution.</b>\n
    If two keys hash to the same index, the corresponding  records  cannot  be
    stored in the same location. So, if it's already occupied,  we  must  find
    another location to store the new record, and do it so that we can find it
    when we look it up later on.

    To give an idea of the importance of a good collision resolution strategy,
    consider the following result, derived using the birthday paradox. Even if
    we  assume  that  our  hash  function  outputs  random  indices  uniformly
    distributed over the array, and even for  a  hash  table  with  1  million
    indices, there is a 95% chance of at least one collision occurring  before
    it contains 2500 records.

    There are a number  of  collision  resolution  techniques,  but  the  most
    popular are open addressing and chaining.

    <b>Separate chaining.</b>\n
    \image html HashTable-Chain.png "Hash collision resolved by chaining."

    Sometimes called simply chaining or direct chaining, this technique in its
    simplest form has a linked list of inserted records at each  slot  in  the
    array references. Each linked list has each element that collides  to  the
    same slot. Insertion requires finding the correct slot, and  appending  to
    either end of the list in that slot; deletion requires searching the  list
    and removal.

    Chained hash tables have advantages over open  addressed  hash  tables  in
    that the removal operation  is  simple  and  resizing  the  table  can  be
    postponed for  a  much  longer  time  because  performance  degrades  more
    gracefully even when every slot is used. Indeed, many chaining hash tables
    may not require resizing at all since performance degradation is linear as
    the table fills. For example, a chaining hash table containing  twice  its
    recommended capacity of data would only be about twice as slow on  average
    as the same table at its recommended capacity.

    Chained hash tables  inherit  the  disadvantages  of  linked  lists.  When
    storing small records, the overhead of the linked list can be significant.
    An additional disadvantage is that traversing a linked list has poor cache
    performance.

    Alternative data structures can be  used  for  chains  instead  of  linked
    lists. By using  a  self-balancing  tree,  for  example,  the  theoretical
    worst-case time of a hash table can be brought down  to  O(log  n)  rather
    than O(n). However, since each list is intended to be short, this approach
    is usually inefficient unless the hash table is designed to  run  at  full
    capacity or there are unusually high collision rates, as  might  occur  in
    input designed to cause collisions. Dynamic arrays can  also  be  used  to
    decrease space overhead and improve cache  performance  when  records  are
    small.

    Some chaining implementations use an optimization where the  first  record
    of each chain is stored in the table. The purpose  is  to  increase  cache
    efficiency of hash table access. In order to avoid wasting  large  amounts
    of space, such hash tables would maintain a load factor of 1.0 or greater.
    The term direct chaining is sometimes  used  to  describe  implementations
    that do not use this optimization.

    <b>Open addressing.</b>\n
    \image html HashTable-Chain.png "Hash collision resolved by linear probing (interval=1)."

    Open addressing hash tables store the records directly within  the  array.
    This approach is also called closed hashing. A hash collision is  resolved
    by probing, or searching through alternate locations  in  the  array  (the
    probe sequence) until either the target record  is  found,  or  an  unused
    array slot is found, which indicates that there is  no  such  key  in  the
    table. Well known probe sequences include:

    \li <b>linear probing</b> - in which the interval between probes is  fixed
        - often at 1.

    \li <b>quadratic probing</b>  -  in  which  the  interval  between  probes
        increases proportional to the hash value (the interval thus increasing
        linearly and the indices are described by a quadratic function).

    \li <b>double hashing</b> -  in  which  the  interval  between  probes  is
        computed by another hash function.

    <b>Table resizing.</b>\n
    With a good hash function,  a  hash  table  can  typically  contain  about
    70%-80% as many elements as it does table slots and  still  perform  well.
    Depending on the collision resolution mechanism, performance can begin  to
    suffer either gradually or dramatically as more  elements  are  added.  To
    deal with this, when  the  load  factor  exceeds  some  threshold,  it  is
    necessary to allocate a new, larger table, and add all the contents of the
    original table to this new table. In Java's HashMap  class,  for  example,
    the default load factor threshold is 0.75.

    This can be a very expensive operation, and the necessity for it is one of
    the hash table's disadvantages. In fact,  some  naive  methods  for  doing
    this, such as enlarging the table by one each time you add a new  element,
    reduce performance so drastically as  to  make  the  hash  table  useless.
    However, if the table is enlarged by some fixed percent, such  as  10%  or
    100%, it can be shown using amortized analysis that these resizings are so
    infrequent that the average time per insertion remains  constant-time.  To
    see why this is true, suppose a hash table using chaining  begins  at  the
    minimum size of 1 and is doubled each time it fills above 100%. If in  the
    end it contains n elements, then the total add  operations  performed  for
    all the resizings is:

    1 + 2 + 4 + 8 + ... + n = 2n - 1.

    Because the costs of the resizings form a geometric series, the total cost
    is O(n). But it is necessary also to perform n operations  to  add  the  n
    elements in the first place, so the total time  to  add  n  elements  with
    resizing is O(n), an amortized time of O(1) per element.

    On the other hand, some hash table implementations, notably  in  real-time
    systems, cannot pay the price of enlarging the hash  table  all  at  once,
    because it may interrupt time-critical operations. One simple approach  is
    to initially allocate the table with enough space for the expected  number
    of elements and forbid the addition of too many elements.  Another  useful
    but more memory-intensive technique is to perform the resizing gradually:

    \li Allocate the new hash table, but leave the old hash  table  and  check
        both tables during lookups.
    \li Each time an insertion is performed, add that element to the new table
        and also move k elements from the old table to the new table.
    \li When all elements are removed from the old table, deallocate it.

    To ensure that the old table will be completely copied over before the new
    table itself needs to be enlarged, it's necessary to increase the size  of
    the table by a factor of at least (k + 1)/k during the resizing.

    Linear hashing is a hash table algorithm  that  permits  incremental  hash
    table expansion. It is implemented using a single hash table, but with two
    possible look-up functions.

    Another way to decrease the cost of table resizing is  to  choose  a  hash
    function in such a way that the hashes of most values do not  change  when
    the table  is  resized.  This  approach,  called  consistent  hashing,  is
    prevalent  in  disk-based  and  distributed  hashes,  where  resizing   is
    prohibitively costly.

    <b>Time complexity and common uses of hash tables.</b>\n
    Hash tables are often used  to  implement  associative  arrays,  sets  and
    caches. Like arrays, hash tables  provide  constant-time  O(1)  lookup  on
    average,  regardless  of  the  number  of  items  in  the   table.   While
    theoretically the worst-case lookup time can be as bad as O(n),  this  is,
    for practical purposes, statistically unlikely unless the hash function is
    poorly designed or unless the set of keys is maliciously chosen  with  the
    given  hash  function  in  mind.  These  corner  cases  are  addressed  in
    mathematical analysis with the Simple Uniform  Hashing  Assumption,  which
    puts basic assumed conditions on the hash function.

    Compared to other associative array data structures, hash tables are  most
    useful when large numbers of records are to be stored, especially  if  the
    size of the data set can be predicted.

    Hash tables may be used as in-memory data structures. Hash tables may also
    be adopted for use  with  persistent  data  structures;  database  indices
    sometimes use disk-based data structures based on  hash  tables,  although
    balanced trees are more popular.

    <b>Choosing a good hash function.</b>\n
    A good hash function is essential for good hash table performance. A  poor
    choice of a hash function is  likely  to  lead  to  clustering,  in  which
    probability of keys mapping to the same hash bucket (i.e. a collision)  is
    significantly greater than would be expected from  a  random  function.  A
    nonzero collision probability is inevitable in  any  hash  implementation,
    but usually the number of  operations  required  to  resolve  a  collision
    scales linearly with the number of keys mapping to  the  same  bucket,  so
    excess collisions will degrade  performance  significantly.  In  addition,
    some hash functions are computationally expensive, so the amount  of  time
    (and, in some cases, memory) taken to compute the hash may be burdensome.

    Choosing a good hash function is tricky. The literature  is  replete  with
    poor choices, at least when measured by modern standards. For example, the
    very popular multiplicative hash advocated by Donald Knuth in The  Art  of
    Computer  Programming  (see  reference  below)   has   particularly   poor
    clustering behavior. However, since  poor  hashing  merely  degrades  hash
    table performance for particular input key  distributions,  such  problems
    commonly go undetected.

    The literature is similarly sparse on the criteria  for  choosing  a  hash
    function. Unlike most other fundamental algorithms  and  data  structures,
    there is no universal consensus on what makes a "good" hash function.  The
    remainder of this section is  organized  by  three  criteria:  simplicity,
    speed, and strength. In addition, it surveys algorithms known  to  perform
    well by these criteria.

    Simplicity and speed are readily measured objectively (by number of  lines
    of code and CPU benchmarks, for example), but strength is a more  slippery
    concept. Obviously, a cryptographic hash  function  such  as  SHA-1  would
    satisfy the relatively lax strength requirements needed for  hash  tables,
    but their slowness and complexity makes them unappealing.  However,  using
    cryptographic hash functions can protect against  collision  attacks  when
    the hash table modulus and its factors can not be  kept  secret  from  the
    attacker, or alternatively, by applying a secret salt. However, for  these
    specialized cases, a universal hash function can be used  instead  of  one
    static hash.

    In the absence of a standard  measure  for  hash  function  strength,  the
    current state of the art is to employ a battery of  statistical  tests  to
    measure whether the hash function can  be  readily  distinguished  from  a
    random function. Arguably the most important test is to determine  whether
    the hash function displays the avalanche effect, which essentially  states
    that any single-bit change in the input key  should  affect,  on  average,
    half the bits in the output. Bret  Mulvey  advocates  testing  the  strict
    avalanche condition in particular, which states that, for  any  single-bit
    change, each of the output bits should change with  probability  one-half,
    independent of the other bits in the key. Purely additive  hash  functions
    such as CRC fail this stronger condition miserably.

    Clearly, a strong hash function should have a uniform distribution of hash
    values. Bret Mulvey proposes the use of a chi-squared test for uniformity,
    based on power of two hash table sizes ranging from 21 to 216.  This  test
    is considerably more sensitive than many  others  proposed  for  measuring
    hash functions, and finds problems in many popular hash functions.

    Fortunately,  there  are  good  hash  functions  that  satisfy  all  these
    criteria. The simplest class all consume one byte of  the  input  key  per
    iteration of the inner loop. Within this class, simplicity and  speed  are
    closely related, as fast algorithms simply  don't  have  time  to  perform
    complex calculations.

    <b>Ordered retrieval issue.</b>\n
    Hash tables store data in pseudo-random locations, so accessing  the  data
    in a sorted  manner  is  a  very  time  consuming  operation.  Other  data
    structures such as self-balancing binary search  trees  generally  operate
    more slowly (since their lookup time is O(log  n))  and  are  rather  more
    complex to implement than hash tables but maintain a sorted data structure
    at all times. See a comparison of hash tables  and  self-balancing  binary
    search trees.

    <b>Problems with hash tables.</b>\n
    Although hash table lookups use constant time on average, the  time  spent
    can be significant.  Evaluating  a  good  hash  function  can  be  a  slow
    operation. In particular, if simple array indexing can  be  used  instead,
    this is usually faster.

    Hash tables in general exhibit poor locality  of  reference-that  is,  the
    data to be accessed is distributed seemingly at random in memory.  Because
    hash tables cause access patterns  that  jump  around,  this  can  trigger
    microprocessor  cache  misses  that  cause  long  delays.   Compact   data
    structures such as arrays, searched with linear search, may be  faster  if
    the table is relatively small and keys are cheap to compare, such as  with
    simple integer keys. According to Moore's Law,  cache  sizes  are  growing
    exponentially and so what is considered "small"  may  be  increasing.  The
    optimal performance point varies from system to system.

    More significantly, hash tables are  more  difficult  and  error-prone  to
    write and use. Hash  tables  require  the  design  of  an  effective  hash
    function for each key type, which in some situations is more difficult and
    time-consuming to design and debug than  the  simple  comparison  function
    required for a self-balancing binary search tree. In  open-addressed  hash
    tables it is fairly easy to create a poor hash function.

    Additionally, in some applications, a black hat with knowledge of the hash
    function may be able  to  supply  information  to  a  hash  which  creates
    worst-case behavior by causing excessive  collisions,  resulting  in  very
    poor  performance  (i.e.,  a  denial  of  service  attack).  In   critical
    applications, either universal hashing can be used  or  a  data  structure
    with better worst-case guarantees may  be  preferable.  For  details,  see
    Crosby and Wallach's Denial of Service via Algorithmic Complexity Attacks.

    <b>References.</b>\n
    \li Cormen, Thomas H.; Leiserson, Charles E.; Rivest,  Ronald  L.;  Stein,
        Clifford (2001). Introduction to Algorithms, second edition, MIT Press
        and McGraw-Hill, pp. 222. ISBN 978-0-262-53196-2.
    \li Tenenbaum, Aaron M.; Langsam, Yedidyah & Augenstein, Moshe J.  (1990),
        Data Structures Using C, Prentice Hall, pp. pp. 456-461, pp. 472, ISBN
        0-13-199746-7
    \li Celis, Pedro (1986). Robin Hood  hashing.  Technical  Report  Computer
        Science Department, University of Waterloo CS-86-14.
    \li Litwin, Witold (1980). "Linear hashing: A new tool for file and  table
        addressing". Proc. 6th Conference on Very Large Databases: 212-223.

    <b>Taken from:</b>\n
    Hash table from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Hash_table
*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction = NAlgorithms::NFunctions::FHashString<T_Key>, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FHashStringComparator<T_Key>, class T_ResizePolicy = NPolicy::CResizePolicySquareGrow, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CHashTable :
  public NCommon::NContainers::IAssociative<CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >,
  public NCommon::NContainers::IAssociativeConst<CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >,
  public NCommon::NContainers::IDequeConst<CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >
{
  // Friend class: Hash table iterator class (CHashTableIterator).
  friend class CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>;
  // Friend class: Constant hash table iterator class (CHashTableIteratorConst).
  friend class CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Key TKeyConstructibleCheckType;
  //! Type for MConceptConstructible constraint checking.
  typedef T_Value TValueConstructibleCheckType;
  //! Type for MConceptHashFunction argument constraint checking.
  typedef const T_Key& TKeyHashFunctionArgumentCheckType;
  //! Type for MConceptHashFunction constraint checking.
  typedef T_KeyHashFunction TKeyHashFunctionCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Key& TKeyPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_KeyBinaryPredicate TKeyPredicate2CheckType;
  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TDepthCheckType;

  // Check T_Key template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TKeyConstructibleCheckType);
  // Check T_Value template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TValueConstructibleCheckType);
  // Check T_KeyHashFunction template argument constraint to be a suitable hash function.
  REQUIRES_CONCEPT2(NConcept::NFunctions, MConceptHashFunction, TKeyHashFunctionCheckType, TKeyHashFunctionArgumentCheckType);
  // Check T_KeyBinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TKeyPredicate2CheckType, TKeyPredicate2ArgumentCheckType, TKeyPredicate2ArgumentCheckType);
  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CMap class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef T_Key TKey;
  //! Container associative value type.
  typedef T_Value TValue;

  //! Container key/value pair type.
  typedef NUtility::CPair<T_Key, T_Value> TType;
  //! Container type.
  typedef CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TContainer;
  //! Non constant hash table iterator type.
  typedef CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TIterator;
  //! Constant hash table iterator type.
  typedef CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TIteratorConst;

  //! Container's key hash function type.
  typedef T_KeyHashFunction TKeyHashFunction;
  //! Container's key binary predicate type.
  typedef T_KeyBinaryPredicate TKeyLessThanPredicate;
  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      \param a_cGrowFactor - Hash table grow factor threshold (default is 0.75).
      \param a_fHashFunction - Hash function (default is T_KeyHashFunction()).
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_cResizeFactor - Hash table resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CHashTable(const Treal a_cGrowFactor = CONSTR(0.75), T_KeyHashFunction a_fHashFunction = T_KeyHashFunction(), T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CHashTable();

  //! Operator: Assign another CHashTable class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTable class.
      \return Reference to the current class instance.
  */
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator = (const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Operator: Insert key/value pair into hash table.
  /*!
      \param a_crKeyValuePair - Constant reference to the key/value pair to insert.
      \return Reference to the current class instance.
  */
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator += (const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair);
  //! Operator: Insert another map into hash table.
  /*!
      \param a_crHashTable - Constant reference to the hash table to insert.
      \return Reference to the current class instance.
  */
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator += (const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable);
  //! Operator: Remove key from hash table.
  /*!
      \param a_crKey - Constant reference to the key to remove.
      \return Reference to the current class instance.
  */
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator -= (const T_Key& a_crKey);
  //! Operator: Remove another map from hash table.
  /*!
      \param a_crHashTable - Constant reference to the hash table to remove.
      \return Reference to the current class instance.
  */
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator -= (const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable);

  //! Operator: Return non constant iterator to the hash table value with given key.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Non constant iterator with given key or invalid empty iterator.
  */
  TIterator operator [] (const T_Key& a_crKey);
  //! Operator: Return constant iterator to the hash table value with given key.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Constant iterator with given key or invalid empty iterator.
  */
  TIteratorConst operator [] (const T_Key& a_crKey) const;

  //! Set another CHashTable class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTable class.
      \return true  - if another hash table was successfully set. \n
              false - if another hash table was not successfully set. \n
  */
  Tbool set(const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Get hash value.
  /*!
      Method returns hash value of the given key.

      \param a_crKey - Constant reference to the key.
      \return Hash value of the given key.
  */
  Tuint getHash(const T_Key& a_crKey) const;
  //! Get hash index.
  /*!
      Method returns hash index of the given key for the current hash table.

      \param a_crKey - Constant reference to the key.
      \return Hash index of the given key for the current hash table.
  */
  Tuint getHashIndex(const T_Key& a_crKey) const;

  //! Get hash table free size.
  /*!
      Method returns count of free elements  in  the  hash  table,  which  are
      available for probing.

      \return Count of free elements in the hash table.
  */
  Tuint getFreeSize() const;
  //! Get hash table full size.
  /*!
      Method returns count of elements in the hash table, which are  available
      for probing. In other words it is a size of the buffer for keeping keys.

      \return Count of available elements in the hash table.
  */
  Tuint getFullSize() const;

  //! Get hash table grow factor value.
  /*!
      \return Current hash table grow factor value.
  */
  Treal getGrowFactor() const;
  //! Get hash table resize factor value.
  /*!
      \return Current hash table policy resize factor value.
  */
  Tuint getResizeFactor() const;

  //! Set hash table grow factor.
  /*!
      Method sets new hash table grow factor.  The  factor  defines  how  full
      should be the hash table to perform  a  reallocation  and  copying.  The
      value should be great than 0.0 and less than 1.0.

      \param a_cGrowFactor - Hash table grow factor.
      \return true  - if hash table grow factor successfully set. \n
              false - if hash table grow factor is invalid. \n
  */
  Tbool setGrowFactor(const Treal a_cGrowFactor);
  //! Set hash table resize factor.
  /*!
      Method sets new policy resize factor. If given resize factor is invalid,
      then policy will use the default value as current resize factor.

      \param a_cResizeFactor - Resize factor.
      \return true  - if resize factor successfully set. \n
              false - if resize factor is invalid. \n
  */
  Tbool setResizeFactor(const Tuint a_cResizeFactor);

  // IContainer interface overriding methods.
  virtual Tbool clear() = 0;

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociative interface overriding methods.
  virtual Tbool insert(const T_Key& a_crKey, const T_Value& a_crValue);
  virtual Tbool insert(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair);
  virtual Tbool insert(const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable);
  virtual Tbool remove(const T_Key& a_crKey, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crHashTable, const Tbool a_cRemoveSame = false);

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const T_Key& a_crKey1, const T_Key& a_crKey2) const;
  virtual TIterator      find(const T_Key& a_crKey) = 0;
  virtual TIteratorConst find(const T_Key& a_crKey) const = 0;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst() = 0;
  virtual TIteratorConst getItFirst() const = 0;
  virtual TIterator      getItLast() = 0;
  virtual TIteratorConst getItLast() const = 0;

  //! Resize hash table to the given size.
  /*!
      Method updates hash table to the given size.

      \param a_cSize - New hash table size.
      \return true  - if hash table was successfully resized. \n
              false - if hash table was not successfully resized. \n
  */
  virtual Tbool resize(const Tuint a_cSize) = 0;
  //! Resize hash table by given size.
  /*!
      Method updates hash table by adding/removing given size.

      \param a_cSize - Additional hash table size (may be less than 0).
      \return true  - if hash table was successfully resized. \n
              false - if hash table was not successfully resized. \n
  */
  virtual Tbool resizeBy(const Tsint a_cSize);

  //! Serialization load CHashTable class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CHashTable class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CHashTable class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashTable class instances.
  /*!
      \param a_rInstance - Reference to another CHashTable class instance.
  */
  void swap(CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_rInstance);

protected:
  struct SHashTableNode                 //! Hash table node structure.
  {
  public:
    NUtility::CPair<T_Key, T_Value> m_KeyValuePair; //! Key/value pair.

    //! Initialize hash table node with given key and value.
    /*!
        \param a_crKey - Constant reference to the key.
        \param a_crValue - Constant reference to the value.
    */
    SHashTableNode(const T_Key& a_crKey, const T_Value& a_crValue);
    //! Initialize hash table node with the given key/value pair.
    /*!
        \param a_crKeyValuePair - Constant reference to the key/value pair.
    */
    SHashTableNode(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair);
  };

  Tuint                m_Size;          //!< Hash table size (count of key/value pairs).
  Tuint                m_FreeSize;      //!< Hash table free size.
  Tuint                m_FullSize;      //!< Hash table full size.
  Treal                m_GrowFactor;    //!< Hash table grow factor.
  T_KeyHashFunction    m_fHashFunction; //!< Hash function.
  T_KeyBinaryPredicate m_fLessThan;     //!< Hash key 'LessThan' binary predicate.
  T_ResizePolicy       m_ResizePolicy;  //!< Hash table resize policy.
  T_Allocator          m_Allocator;     //!< Memory allocator.

  //! Do some forward iterations for non constant hash table iterator.
  /*!
      This method makes some forward iterations with given non  constant  hash
      table iterator instance and returns  number  of  steps  that  have  been
      successfully done.

      \param a_rIterator - Reference to the hash table iterator.
      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that given iterator have gone.
  */
  virtual Tuint stepForward(TIterator& a_rIterator, const Tuint a_cStepCount = 1) const = 0;
  //! Do some forward iterations for constant hash table iterator.
  /*!
      This method makes some forward iterations with given constant hash table
      iterator  instance  and  returns  number  of  steps   that   have   been
      successfully done.

      \param a_rIterator - Reference to the hash table iterator.
      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that given iterator have gone.
  */
  virtual Tuint stepForward(TIteratorConst& a_rIterator, const Tuint a_cStepCount = 1) const = 0;

  //! Do some backward iterations for non constant hash table iterator.
  /*!
      This method makes some backward iterations with given non constant  hash
      table iterator instance and returns  number  of  steps  that  have  been
      successfully done.

      \param a_rIterator - Reference to the hash table iterator.
      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that given iterator have gone.
  */
  virtual Tuint stepBackward(TIterator& a_rIterator, const Tuint a_cStepCount = 1) const = 0;
  //! Do some backward iterations for constant hash table iterator.
  /*!
      This method makes some backward  iterations  with  given  constant  hash
      table iterator instance and returns  number  of  steps  that  have  been
      successfully done.

      \param a_rIterator - Reference to the hash table iterator.
      \param a_cStepCount - Steps count to iteration (default is 1).
      \return Number of iteration steps that given iterator have gone.
  */
  virtual Tuint stepBackward(TIteratorConst& a_rIterator, const Tuint a_cStepCount = 1) const = 0;

  //! Internal insert engine.
  /*!
      \param a_crKeyValuePair - Constant reference to the key/value pair to insert.
      \param a_pIterator - Pointer to the returning inserted hash table value iterator (default is NULL).
      \return true  - if inserting was successful. \n
              false - if inserting was not successful. \n
  */
  virtual Tbool insertInternal(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, TIterator* a_pIterator = NULL) = 0;
  //! Internal remove engine.
  /*!
      \param a_rIterator - Reference to the removing hash table value iterator.
      \param a_cRemoveSame - Remove all same items flag (default is false).
      \return true  - if removing was successful. \n
              false - if removing was not successful. \n
  */
  virtual Tbool removeInternal(TIterator& a_rIterator, const Tbool a_cRemoveSame = false) = 0;
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
//! Traits meta-class: hash table container traits specialization.
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
class MTraitsContainer<NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> > :
  public MType<NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = true;  //!< Is container non constant associative?
  static const Tbool isAssociativeConst = true;  //!< Is container constant associative?
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
#include <Depth/include/containers/iterators/CHashTableIterator.hpp>
#include <Depth/include/containers/iterators/CHashTableIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CHashTable.inl>
/*==========================================================================*/
#endif
