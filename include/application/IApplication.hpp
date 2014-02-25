/*!
 *  \file    IApplication.hpp Application interface provides OS independent
 *           functionality to handle application startup.
 *  \brief   Application interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Application interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Application
    VERSION:   1.0
    CREATED:   10.01.2009 03:53:49

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
#ifndef __IAPPLICATION_HPP__
#define __IAPPLICATION_HPP__
/*==========================================================================*/
#include <Depth/include/application/details/CApplicationHelper.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS IN OTHER NAMESPACE                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*--------------------------------------------------------------------------*/
class CUnitTestLauncher;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NApplication {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Application interface.
/*!
    Application interface provides common application  startup  functionality,
    which is OS independent.

    To define application instance in user code simple inherit your class from
    the IApplication interface, overload main() method and use it as a program
    entry point.

    Example:
    \code
    // Define application class in user code.
    class CMyApplication :
      public NApplication::IApplication
    {
      // Entry point of the application.
      Tsint main(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
      {
        ...
      }
    };
    \endcode

    Finally you should create and instance of your class in system entry point
    (usually 'main()' function), provide startup arguments  and  call  'run()'
    method:

    \code
    int main(int argc, char *argv[])
    {
      CMyApplication app;
      app.run(argc, argv);
    }

    int main(int argc, char *argv[], char *envp[])
    {
      CMyApplication app;
      app.run(argc, argv, envp);
    }
    \endcode

    Another approach is to  use  DepthApplicationMain  static  library,  which
    embeds system entry point, to have a system independent abstraction  of  a
    program entry point. In this case you have to create an instance  of  your
    class just after its the definition:

    Example:
    \code
    // Define application class in user code.
    class CMyApplication :
      public NApplication::IApplication
    {
      ...
    } the_Application; // Create an instance of the application class.
    \endcode
*/
class APPLICATION_API IApplication
{
  // Friend class: Unit test launcher class (CUnitTestLauncher).
  friend class NUnitTest::CUnitTestLauncher;
  // Friend function: Depth application system entry point function.
  friend Tsint systemApplicationEntryPoint(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment);

  //! Type for the MConceptDepthType constraint checking.
  typedef IApplication TDepthCheckType;

  // Check IApplication interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  // Application return values constants.
  static const Tsint EXIT_WITH_SUCCESS; //!< Execution of the application has been successfully finished.
  static const Tsint EXIT_WITH_WARNING; //!< Execution of the application has been successfully finished with some warning.
  static const Tsint EXIT_WITH_ERROR;   //!< Execution of the application has been failed with some error.

protected:
  //! Default interface protected constructor.
  IApplication();
  //! Initialize application interface with ANSI C/C++ program arguments in ASCII encoding.
  /*!
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \param envp - String buffer of environment variables (default is NULL).
  */
  IApplication(Tsint argc, Tschar *argv[], Tschar *envp[] = NULL);
  //! Initialize application interface with ANSI C/C++ program arguments in Unicode encoding.
  /*!
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \param envp - String buffer of environment variables (default is NULL).
  */
  IApplication(Tsint argc, Twchar *argv[], Twchar *envp[] = NULL);
  //! Initialize application interface with string buffers of program arguments and environment variables.
  /*!
      \param a_crArguments - Constant reference to the string buffer with program arguments.
      \param a_crEnvironment - Constant reference to the string buffer with environment variables.
  */
  IApplication(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment);

public:
  //! Interface virtual destructor.
  virtual ~IApplication();

  //! Get constant reference to the program arguments string buffer.
  /*!
      \return Constant reference to the program arguments string buffer.
  */
  const NContainers::CStringBuffer<NString::CString>& getArguments() const;
  //! Get constant reference to the environment variables string buffer.
  /*!
      \return Constant reference to the environment variables string buffer.
  */
  const NContainers::CStringBuffer<NString::CString>& getEnvironment() const;

  //! Manually run the current application instance from system entry point.
  /*!
      Method is used to manually run the  current  application  instance  from
      some system entry point ('main()' function, 'WinMain()' function, etc).

      \return Result of the execution which is provided to the system.
  */
  Tsint run();
  //! Manually run the current application instance from system entry point with new program arguments in ASCII encoding.
  /*!
      Method is used to manually run the  current  application  instance  from
      some system entry point ('main()' function, 'WinMain()' function, etc).

      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \param envp - String buffer of environment variables (default is NULL).
      \return Result of the execution which is provided to the system.
  */
  Tsint run(Tsint argc, Tschar *argv[], Tschar *envp[] = NULL);
  //! Manually run the current application instance from system entry point with new program arguments in Unicode encoding.
  /*!
      Method is used to manually run the  current  application  instance  from
      some system entry point ('main()' function, 'WinMain()' function, etc).

      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \param envp - String buffer of environment variables (default is NULL).
      \return Result of the execution which is provided to the system.
  */
  Tsint run(Tsint argc, Twchar *argv[], Twchar *envp[] = NULL);
  //! Manually run the current application instance from system entry point with string buffers of program arguments and environment variables.
  /*!
      Method is used to manually run the  current  application  instance  from
      some system entry point ('main()' function, 'WinMain()' function, etc).

      \param a_crArguments - Constant reference to the string buffer with program arguments.
      \param a_crEnvironment - Constant reference to the string buffer with environment variables.
      \return Result of the execution which is provided to the system.
  */
  Tsint run(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment);

  //! Is instance of the application created?
  /*!
      \return true  - if the application instance was created. \n
              false - if the application instance was not created. \n
  */
  static Tbool isCreated();
  //! Is application running?
  /*!
      \return true  - if the application instance is running. \n
              false - if the application instance is not running. \n
  */
  static Tbool isRunning();

  //! Get reference to the current application instance.
  /*!
      Method returns reference to the current application instance. Note  that
      result may be broken if the current application instance is not created.
      So use 'isCreated()' method before to check its valid state.

      \return Reference to the current application instance.
  */
  static IApplication& getCurrentRef();
  //! Get pointer to the current application instance.
  /*!
      Method returns pointer to the current application  instance.  Note  that
      result may be NULL if the current application instance is  not  created.
      So use 'isCreated()' method before to check its valid state or use  NULL
      checking strategy to define application instance is  not  created  state
      alternatively.

      \return Pointer to the current application instance.
  */
  static IApplication* getCurrentPtr();

  //! Serialization load IApplication interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save IApplication interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize IApplication interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IApplication interface instances.
  /*!
      \param a_rInstance - Reference to another IApplication interface instance.
  */
  void swap(IApplication& a_rInstance);

protected:
  //! Entry point of the application.
  /*!
      Method is called from the system entry point manually/automatically when
      the current application is starts. Overloaded method should contain  all
      application functionality and result of execution which will be provided
      to the system. Additionally method has  a  string  buffer  with  program
      arguments and a one with environment variables.

      \param a_crArguments - Constant reference to the string buffer with program arguments.
      \param a_crEnvironment - Constant reference to the string buffer with environment variables.
      \return Result of the execution which is provided to the system.
  */
  virtual Tsint main(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment) = 0;

private:
  static Tbool ms_IsRunning;                                          //!< Is application running?
  static IApplication* ms_pInstance;                                  //!< Pointer to the current instance of the application.
  static NContainers::CStringBuffer<NString::CString> ms_Arguments;   //!< String buffer to the current application program arguments.
  static NContainers::CStringBuffer<NString::CString> ms_Environment; //!< String buffer to the current application environment variables.

  //! Initialize unit test application instance.
  /*!
      \param a_cUnitTestFlag - Unit test dummy flag.
  */
  IApplication(const Tbool a_cUnitTestFlag);

  //! Parse ANSI C/C++ program arguments in ASCII encoding and set the current application string buffers.
  /*!
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \param envp - String buffer of environment variables (default is NULL).
      \return true  - if the program arguments were successfully parsed & filled. \n
              false - if the program arguments were not successfully parsed & filled. \n
  */
  Tbool parse(Tsint argc, Tschar *argv[], Tschar *envp[] = NULL);
  //! Parse ANSI C/C++ program arguments in Unicode encoding and set the current application string buffers.
  /*!
      \param argc - Count of program arguments.
      \param argv - String buffer of program arguments.
      \param envp - String buffer of environment variables (default is NULL).
      \return true  - if the program arguments were successfully parsed & filled. \n
              false - if the program arguments were not successfully parsed & filled. \n
  */
  Tbool parse(Tsint argc, Twchar *argv[], Twchar *envp[] = NULL);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/application/IApplication.inl>
/*==========================================================================*/
//! \example example-application-native.cpp
//! \example example-application-IApplication.cpp
/*--------------------------------------------------------------------------*/
//! \test test-application-native.cpp
//! \test test-application-IApplication.cpp
/*==========================================================================*/
#endif
