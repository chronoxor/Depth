/*!
 *  \file    CSystemStringIteratorConst.hpp System string constant iterator
 *           definitions. It gives ability to get system string characters
 *           and to do random moving through the system string characters.
 *  \brief   System string constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.08.2008 20:01:12

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
#ifndef __CSYSTEMSTRINGITERATORCONST_HPP__
#define __CSYSTEMSTRINGITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/string/CSystemString.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! System string constant iterator class.
/*!
    System  string  constant  iterator  represents  system  string  iterations
    method. With this iterator you can perform random system string moving and
    looking into system string characters. Note that you cannot modify  system
    string characters with constant iterator. In this case  use  non  constant
    system string iterator.

    Serialization: System string constant iterator cannot be loaded.
*/
class BASE_API CSystemStringIteratorConst :
  public NCommon::NIterators::IIteratorConst<CSystemStringIteratorConst, Tbyte, Tbyte, CSystemString>,
  public NCommon::NIterators::IIteratorMoveRandom<CSystemStringIteratorConst, Tbyte, Tbyte, CSystemString>,
  public NCommon::ISeekable
{
  // Friend class: System string class (CSystemString).
  friend class NDepth::NString::CSystemString;

  //! Type for MConceptDepthType constraint checking.
  typedef CSystemStringIteratorConst TDepthCheckType;

  // Check CSystemStringIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef Tbyte TType;
  //! Iterator return type.
  typedef const Tbyte TReturn;
  //! Iterator container type.
  typedef const CSystemString TContainer;
  //! Iterator base type.
  typedef CSystemStringIteratorConst TIterator;

  //! Default class constructor.
  CSystemStringIteratorConst();
  //! Initialize with non constant system string iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CSystemStringIterator class.
  */
  CSystemStringIteratorConst(const CSystemStringIterator& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemStringIteratorConst class.
  */
  CSystemStringIteratorConst(const CSystemStringIteratorConst& a_crInstance);
  //! Class virtual destructor.
  virtual ~CSystemStringIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CSystemStringIterator& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIterator& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend BASE_API Tbool operator == (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CSystemStringIterator& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend BASE_API Tbool operator != (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);

  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CSystemStringIterator& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: Less than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIterator& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  friend BASE_API Tbool operator < (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CSystemStringIterator& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: More than another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIterator& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  friend BASE_API Tbool operator > (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CSystemStringIterator& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIterator& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  friend BASE_API Tbool operator <= (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CSystemStringIterator& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not more or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIterator& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  friend BASE_API Tbool operator >= (const CSystemStringIteratorConst& a_crInstance1, const CSystemStringIteratorConst& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CSystemStringIteratorConst& operator = (const CSystemStringIterator& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CSystemStringIteratorConst& operator = (const CSystemStringIteratorConst& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSystemStringIteratorConst& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSystemStringIteratorConst& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSystemStringIteratorConst& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSystemStringIteratorConst& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSystemStringIteratorConst operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSystemStringIteratorConst operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CSystemStringIteratorConst operator + (const CSystemStringIteratorConst& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend BASE_API CSystemStringIteratorConst operator - (const CSystemStringIteratorConst& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new system string constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed system string position to return.
      \return System string constant iterator under the given index.
  */
  CSystemStringIteratorConst operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new system string constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed system string position to return.
      \return System string constant iterator under the given index.
  */
  CSystemStringIteratorConst operator [] (const Tuint a_cIndex) const;

  //! Set CSystemStringIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CSystemStringIterator class.
  */
  void set(const CSystemStringIterator& a_crInstance);
  //! Set another CSystemStringIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemStringIteratorConst class.
  */
  void set(const CSystemStringIteratorConst& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CSystemStringIteratorConst getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CSystemStringIteratorConst getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CSystemStringIteratorConst getIndex(const Tuint a_cIndex) const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CSystemString& getContainerRef() const;
  virtual const CSystemString* getContainerPtr() const;
  virtual const Tbyte& getValueRef() const;
  virtual const Tbyte* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialization load CSystemStringIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSystemStringIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSystemStringIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSystemStringIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CSystemStringIteratorConst class instance.
  */
  void swap(CSystemStringIteratorConst& a_rInstance);

private:
  const CSystemString* m_cpContainer;   //!< Constant pointer to the iterator container.
  Tuint m_Index;                        //!< Index of the current system character.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CSystemStringIteratorConst(const CSystemString* a_cpContainer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* ITERATOR TRAITS SPECIALIZATION DECLARATIONS                              */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: System string constant iterator's traits specialization.
template <>
class MTraitsIterator<NString::NIterators::CSystemStringIteratorConst> :
  public MType<NString::NIterators::CSystemStringIteratorConst>
{
public:
  //! Iterator value type.
  typedef NString::NIterators::CSystemStringIteratorConst::TType value;
  //! Iterator return type.
  typedef NString::NIterators::CSystemStringIteratorConst::TReturn result;
  //! Iterator container type.
  typedef NString::NIterators::CSystemStringIteratorConst::TContainer container;
  //! Iterator base type.
  typedef NString::NIterators::CSystemStringIteratorConst::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = true;  //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/iterators/CSystemStringIteratorConst.inl>
/*==========================================================================*/
#endif
