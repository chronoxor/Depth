/*!
 *  \file    CFunctorHelperX.hpp.tpl Functor helper class emulates an object
 *           that can be called as a function with 'operator()'.
 *  \brief   Functor helper class: functor with DEF_FUNCTOR_ARITY arguments (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor helper class: functor with DEF_FUNCTOR_ARITY arguments (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors details (templates)
    VERSION:   1.0
    CREATED:   04.05.2006 20:43:32

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
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NFunctors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Functor helper with DEF_FUNCTOR_ARITY arguments.
/*!
    This class specialize functor helper with DEF_FUNCTOR_ARITY arguments.

    Note that before using functor helper it must  be  initialized.  To  check
    initialize state you can use 'CFunctorHelper::isValid()'  method.  If  you
    use uninitialized functor helper it leads to the error.
*/
template <DEF_TEMPLATE_DECLARATION>
class DEF_FUNCTOR_DECLARATION(CFunctorHelper) :
  public NUtility::NObserver::IObserver,
  public IFunctor<DEF_TEMPLATE_PARAMETERS>
{
  //! Type for MConceptSwappable constraint checking.
  typedef DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS> TSwappableCheckType;

  // Check DEF_FUNCTOR_DECLARATION(CFunctorHelper) class constraint to be a swappable class.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptSwappable, TSwappableCheckType);

public:
  enum EFunctorType                     //! Type of the functor.
  {
    e_EMPTY,                            //!< Empty functor.
    e_FUNCTION,                         //!< Functor initialized with the pointer to function.
    e_METHOD,                           //!< Functor initialized with the class instance and class method.
    e_METHOD_CONST,                     //!< Functor initialized with the class instance and class constant method.
    e_METHOD_VOLATILE,                  //!< Functor initialized with the class instance and class volatile method.
    e_METHOD_CONST_VOLATILE,            //!< Functor initialized with the class instance and class constant volatile method.
    e_CONNECTOR_METHOD,                 //!< Functor initialized with the connector instance and connector method.
    e_CONNECTOR_METHOD_CONST,           //!< Functor initialized with the connector instance and connector constant method.
    e_CONNECTOR_METHOD_VOLATILE,        //!< Functor initialized with the connector instance and connector volatile method.
    e_CONNECTOR_METHOD_CONST_VOLATILE   //!< Functor initialized with the connector instance and connector constant volatile method.
  };

  // IFunctor interface overriding methods.
  virtual Tbool isValid() const;
  virtual T_Result operator () (DEF_CALL_DECLARATION) const;

  // IEquatable interface overriding methods.
  virtual Tbool isEqual(const IFunctor<DEF_TEMPLATE_PARAMETERS>& a_crFunctor) const;

  // IClonable interface overriding methods.
  virtual IFunctor<DEF_TEMPLATE_PARAMETERS>* clone() const;

  //! Swap two DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instances.
  /*!
      \param a_rInstance - Reference to another DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance.
  */
  void swap(DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_rInstance);

protected:
  //! Default class constructor.
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)();
  //! Class constructor with setting functor function.
  /*!
      Initialize current functor with suitable pointer to function. After this
      initializing you can safely call 'operator()'.

      \param a_fFunction - Pointer to function.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction a_fFunction);
  //! Class constructor with setting functor class instance and class method.
  /*!
      Initialize current functor with suitable pointer  to  class  method  and
      reference to the class instance. After this initializing you can  safely
      call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class method.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor class instance and class constant method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      method and reference to the class instance. After this initializing  you
      can safely call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class constant method.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor class instance and class volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  volatile
      method and reference to the class instance. After this initializing  you
      can safely call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class volatile method.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile  method  and  reference  to  the  class  instance.  After  this
      initializing you can safely call 'operator()'.

      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Class constructor with setting functor constant class instance and class constant method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      method  and  constant  reference  to  the  class  instance.  After  this
      initializing you can safely call 'operator()'.

      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class constant method.
      \param a_cConstFlag - Constant version additional parameter.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag);
  //! Class constructor with setting functor constant class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile method and constant reference to the class instance. After this
      initializing you can safely call 'operator()'.

      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag);
  //! Class constructor with setting functor volatile class instance and class volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  volatile
      method  and  volatile  reference  to  the  class  instance.  After  this
      initializing you can safely call 'operator()'.

      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag);
  //! Class constructor with setting functor volatile class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile method and volatile reference to the class instance. After this
      initializing you can safely call 'operator()'.

      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag);
  //! Class constructor with setting functor constant volatile class instance and class constant volatile method.
  /*!
      Initialize current functor  with  suitable  pointer  to  class  constant
      volatile method and constant volatile reference to the  class  instance.
      After this initializing you can safely call 'operator()'.

      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
      \param a_cConstVolatileFlag - Constant volatile version additional parameter.
  */
  template <class T_Class>
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const volatile T_Class& a_cvrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag, const Tbool a_cConstVolatileFlag);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelper) class.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)(const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance);
  //! Class virtual destructor.
  virtual ~DEF_FUNCTOR_DECLARATION(CFunctorHelper)();

  //! Operator: Equal to another DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelper) class.
      \param a_crInstance2 - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelper) class.
      \return true  - if DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance is equal to another one. \n
              false - if DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance is not equal to another one. \n
  */
  template <DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator == (const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance2);
  //! Operator: Not equal to another DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelper) class.
      \param a_crInstance2 - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelper) class.
      \return true  - if DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance is not equal to another one. \n
              false - if DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance is equal to another one. \n
  */
  template <DEF_TEMPLATE_OTHER_DECLARATION>
  friend Tbool operator != (const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance1, const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_OTHER_PARAMETERS>& a_crInstance2);

  //! Operator: Assign with pointer to function.
  /*!
      \param a_fFunction - Pointer to function.
      \return Reference to the current class instance.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& operator = (typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction a_fFunction);
  //! Operator: Assign another DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelper) class.
      \return Reference to the current class instance.
  */
  DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& operator = (const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance);

  //! Set pointer to function.
  /*!
      \param a_fFunction - Pointer to function.
      \return true  - if functor was successfully initialized with pointer to function. \n
              false - if functor was not successfully initialized with pointer to function. \n
  */
  Tbool set(typename DEF_FUNCTOR_DECLARATION(CFunctorHelperFunction)<DEF_TEMPLATE_PARAMETERS>::TFunction a_fFunction);
  //! Set functor class instance and class method.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class method.
      \return true  - if functor was successfully initialized with class instance and class method. \n
              false - if functor was not successfully initialized with class instance and class method. \n
  */
  template <class T_Class>
  Tbool set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethod)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Set functor class instance and class constant method.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class constant method.
      \return true  - if functor was successfully initialized with class instance and class constant method. \n
              false - if functor was not successfully initialized with class instance and class constant method. \n
  */
  template <class T_Class>
  Tbool set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Set functor class instance and class volatile method.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class volatile method.
      \return true  - if functor was successfully initialized with class instance and class volatile method. \n
              false - if functor was not successfully initialized with class instance and class volatile method. \n
  */
  template <class T_Class>
  Tbool set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Set functor class instance and class constant volatile method.
  /*!
      \param a_rClassInstance - Reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \return true  - if functor was successfully initialized with class instance and class constant volatile method. \n
              false - if functor was not successfully initialized with class instance and class constant volatile method. \n
  */
  template <class T_Class>
  Tbool set(T_Class& a_rClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod);
  //! Set functor constant class instance and class constant method.
  /*!
      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class constant method.
      \param a_cConstFlag - Constant version additional parameter.
      \return true  - if functor was successfully initialized with constant class instance and class constant method. \n
              false - if functor was not successfully initialized with constant class instance and class constant method. \n
  */
  template <class T_Class>
  Tbool set(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConst)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag);
  //! Set functor constant class instance and class constant volatile method.
  /*!
      \param a_crClassInstance - Constant reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \return true  - if functor was successfully initialized with constant class instance and class constant volatile method. \n
              false - if functor was not successfully initialized with constant class instance and class constant volatile method. \n
  */
  template <class T_Class>
  Tbool set(const T_Class& a_crClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag);
  //! Set functor volatile class instance and class volatile method.
  /*!
      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
      \return true  - if functor was successfully initialized with volatile class instance and class volatile method. \n
              false - if functor was not successfully initialized with volatile class instance and class volatile method. \n
  */
  template <class T_Class>
  Tbool set(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag);
  //! Set functor volatile class instance and class volatile volatile method.
  /*!
      \param a_vrClassInstance - Volatile reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
      \return true  - if functor was successfully initialized with volatile class instance and class constant volatile method. \n
              false - if functor was not successfully initialized with volatile class instance and class constant volatile method. \n
  */
  template <class T_Class>
  Tbool set(volatile T_Class& a_vrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag);
  //! Set functor constant volatile class instance and class volatile volatile method.
  /*!
      \param a_cvrClassInstance - Constant volatile reference to the class instance.
      \param a_fMethod - Pointer to the class constant volatile method.
      \param a_cConstFlag - Constant version additional parameter.
      \param a_cVolatileFlag - Volatile version additional parameter.
      \param a_cConstVolatileFlag - Constant volatile version additional parameter.
      \return true  - if functor was successfully initialized with constant volatile class instance and class constant volatile method. \n
              false - if functor was not successfully initialized with constant volatile class instance and class constant volatile method. \n
  */
  template <class T_Class>
  Tbool set(const volatile T_Class& a_cvrClassInstance, typename DEF_FUNCTOR_DECLARATION(CFunctorHelperMethodConstVolatile)<T_Class, DEF_TEMPLATE_PARAMETERS>::TMethod a_fMethod, const Tbool a_cConstFlag, const Tbool a_cVolatileFlag, const Tbool a_cConstVolatileFlag);
  //! Set another DEF_FUNCTOR_DECLARATION(CFunctorHelper) class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the DEF_FUNCTOR_DECLARATION(CFunctorHelper) class.
      \return true  - if functor was successfully initialized with another functor. \n
              false - if functor was not successfully initialized with another functor. \n
  */
  Tbool set(const DEF_FUNCTOR_DECLARATION(CFunctorHelper)<DEF_TEMPLATE_PARAMETERS>& a_crInstance);

  //! Get type of the current functor.
  /*!
      \return Type of the current functor.
  */
  EFunctorType getType() const;

  //! Clean current functor instance.
  /*!
      \return true  - if functor was successfully cleaned. \n
              false - if functor was not successfully cleaned. \n
  */
  Tbool clean();

private:
  EFunctorType m_Type;                           //!< Current functor type.
  IFunctor<DEF_TEMPLATE_PARAMETERS>* m_pFunctor; //!< Pointer to functor's implementation.
  const NUtility::NObserver::IConnector* m_cpCaller; //!< Pointer to call connector.

  // IObserver interface overriding methods.
  virtual Tbool onConnect(const NUtility::NObserver::IConnector& a_crIConnector);
  virtual Tbool onDisconnect(const NUtility::NObserver::IConnector& a_crIConnector);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/functors/details/templates/CFunctorHelperX.inl.tpl>
/*==========================================================================*/
