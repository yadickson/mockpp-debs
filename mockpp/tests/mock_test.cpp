	/***************************************************************************
    mock_test.cpp  -  run unit tests to prove correctness of mockpp lib
                             -------------------
    begin                : Fri Dez 27 2002
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: mock_test.cpp 1492 2010-01-03 10:47:55Z ewald-arnold $

 ***************************************************************************/

/**************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 ***************************************************************************/

// Expected number of tests:
//   8 cppunit specific
//   9 unicode specific
//   mock_test : 511
//   jmock_test: 199

#include <mockpp/mockpp.h> // always first

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdio>

#if defined(MOCKPP_USE_BOOSTTEST)
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
//#define BOOST_TEST_MAIN
// #define BOOST_TEST_DYN_LINK
#endif

#include "SelectFramework.h"

#if defined(MOCKPP_USE_BOOSTTEST)
//#undef BOOST_TEST_NO_MAIN
#endif

#if defined(MOCKPP_USE_CXXTEST)

#include <cxxtest/TestRunner.h>

#include <mockpp/framework/CxxTestRunner.h>

#if defined(GUI_QT)
# include <cxxtest/StdioPrinter.h>
# include <cxxtest/QtGui.h>
#elif defined(GUI_X11)
# include <cxxtest/StdioPrinter.h>
# include <cxxtest/X11Gui.h>
#elif defined(GUI_WIN32)
# include <cxxtest/StdioPrinter.h>
# include <cxxtest/Win32Gui.h>
#endif

#include <cxxtest/ErrorPrinter.h>

#elif defined(MOCKPP_USE_BOOSTTEST)

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>

#elif defined(MOCKPP_USE_CPPUNIT)

# include <cppunit/extensions/TestFactoryRegistry.h>
# include <cppunit/ui/text/TestRunner.h>
# include <cppunit/extensions/HelperMacros.h>
# include <cppunit/TextTestProgressListener.h>
# include <cppunit/TestResult.h>
# include <cppunit/TestFailure.h>
# include <cppunit/CompilerOutputter.h>

#endif

#ifndef _MSC_VER
using MOCKPP_STD_NS::time;
using MOCKPP_STD_NS::time_t;
#endif


/////////////////////////////////////////////////////


#ifndef MOCKPP_NS
# define MOCKPP_NS n/a
#endif

#ifndef MINISTL_NS
# define MINISTL_NS n/a
#endif

#ifndef CXXTEST_NS
# define CXXTEST_NS n/a
#endif

#define STRINGIZE(text) STRINGIZE_I(text)
#define STRINGIZE_I(text) #text

#define PRINT_NS \
  MOCKPP_STD_NS::cout << "  - namespace mockpp : " << STRINGIZE(MOCKPP_NS) << MOCKPP_STD_NS::endl \
            << "  - namespace stl    : " << STRINGIZE(MOCKPP_STL) << MOCKPP_STD_NS::endl \
            << "  - namespace std    : " << STRINGIZE(MOCKPP_STD_NS) << MOCKPP_STD_NS::endl \
            << "  - namespace ministl: " << STRINGIZE(MINISTL_NS) << MOCKPP_STD_NS::endl \
            << "  - namespace CxxTest: " << STRINGIZE(CXXTEST_NS) << MOCKPP_STD_NS::endl


/////////////////////////////////////////////////////


#if defined(MOCKPP_USE_CXXTEST)

class MyErrorPrinter : public CXXTEST_NS::ErrorPrinter
{
  public:

    MyErrorPrinter(bool showit)
     : show(showit)
    {}

    void enterTest( const CXXTEST_NS::TestDescription &td )
    {
      if (show)
        MOCKPP_STD_NS::cout << td.suiteName() << "::" << td.testName() << MOCKPP_STD_NS::endl;

      CXXTEST_NS::ErrorPrinter::enterTest(td);
    }

  private:

   bool show;
};


int run_cxxtest(int argc, char **argv)
{
#if defined(GUI_QT)
  return CXXTEST_NS::GuiTuiRunner<CXXTEST_NS::QtGui, CXXTEST_NS::StdioPrinter>( argc, argv ).run();
#elif defined(GUI_X11)
  return CXXTEST_NS::GuiTuiRunner<CXXTEST_NS::X11Gui, CXXTEST_NS::StdioPrinter>( argc, argv ).run();
#elif defined(GUI_WIN32)
  return CXXTEST_NS::GuiTuiRunner<CXXTEST_NS::Win32Gui, CXXTEST_NS::StdioPrinter>( argc, argv ).run();
#else
  bool show = false;
  for (int i1 = 1; i1 < argc; ++i1)
    if (strcmp (argv[1], "--show-name") == 0)
      show = true;

  MyErrorPrinter ep(show);
  MOCKPP_NS::CxxTestRunner::runAllTests(ep);
  return CXXTEST_NS::tracker().failedTests();
  //return CXXTEST_NS::ErrorPrinter().run();
#endif
}

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

class MyListener : public CppUnit::TextTestProgressListener
{
    time_t starttime;

  public:

 MOCKPP_TESTMETHOD_DECL void startTest( CppUnit::Test *test )
  {
    starttime = time(0);
    MOCKPP_STD_NS::cerr << ">>>>>>>>>>>>>>>> " << test->getName() << " : "
              << starttime
              << MOCKPP_STD_NS::endl;
    MOCKPP_STD_NS::cerr.flush();
  }

 MOCKPP_TESTMETHOD_DECL void addFailure( const CppUnit::TestFailure &failure )
  {
    MOCKPP_STD_NS::cerr << ( failure.isError() ? "E" : "F" ) << MOCKPP_STD_NS::endl;
    MOCKPP_STD_NS::cerr.flush();
  }

 MOCKPP_TESTMETHOD_DECL void endTest(CppUnit::Test *test)
  {
    MOCKPP_STD_NS::cerr << MOCKPP_STD_NS::endl;
    time_t endtime = time(0);
    time_t difftime = starttime - endtime;
    unsigned m = difftime / 60;
    unsigned s = difftime % 60;
    MOCKPP_STD_NS::cerr << "<<<<<<<<<<<<<<<< "  << test->getName()
              << " : " << endtime
              << " : " << m << ":" << s
              << MOCKPP_STD_NS::endl;
  }

 MOCKPP_TESTMETHOD_DECL void done()
  {
    MOCKPP_STD_NS::cerr  <<  MOCKPP_STD_NS::endl;
    MOCKPP_STD_NS::cerr.flush();
  }
};


int run_cppunit(int argc, char **argv)
{
  int ret = 1;
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactory &registry = CppUnit::TestFactoryRegistry::getRegistry();

  runner.addTest(registry.makeTest());

  MyListener *listener = 0;
  for (int i1 = 1; i1 < argc; ++i1)
    if (strcmp (argv[1], "--show-name") == 0)
      runner.eventManager().addListener(listener = new MyListener());

#ifndef __BORLANDC__ // @todo
  for (int i2 = 1; i2 < argc; ++i2)
    if (strcmp (argv[i2], "--compiler-output") == 0)
      runner.setOutputter( CppUnit::CompilerOutputter::defaultOutputter(&runner.result(), MOCKPP_STD_NS::cerr ) );
#endif

  ret = runner.run() ? 0 : 1;
  delete listener;
  return ret;
}

#endif


#if defined(MOCKPP_USE_BOOSTTEST)

  /*
    log_successful_tests     = 0,
    log_test_units           = 1,
    log_messages             = 2,
    log_warnings             = 3,
    log_all_errors           = 4, // reported by unit test macros
    log_cpp_exception_errors = 5, // uncaught C++ exceptions
    log_system_errors        = 6, // including timeouts, signals, traps
    log_fatal_errors         = 7, // including unit test macros or
                                  // fatal system errors
    log_nothing              = 8
  */

#ifdef BOOST_TEST_ALTERNATIVE_INIT_API

bool init_unit_test()
{
  MOCKPP_STD_NS::cout << "starting tests..\n";
  MOCKPP_STD_NS::cout << "  - using Boost.Test alternative framework\n";
#ifdef MOCKPP_PTI_WEAKNESS
  MOCKPP_STD_NS::cout << "  - support pti-weakness enabled\n";
#else
  MOCKPP_STD_NS::cout << "  - support pti-weakness disabled\n";
#endif

  PRINT_NS;

  MOCKPP_STD_NS::cout << "  - size of <char> is " << sizeof(MOCKPP_CHAR('x')) << MOCKPP_STD_NS::endl;
  MOCKPP_STD_NS::cout << "\n";

  boost::unit_test::unit_test_log_t::instance().set_threshold_level( boost::unit_test::log_warnings );
  return true;
}

#else

::boost::unit_test::test_suite*
init_unit_test_suite( int, char* [] )
{
  MOCKPP_STD_NS::cout << "starting tests..\n";
  MOCKPP_STD_NS::cout << "  - using Boost.Test legacy framework\n";
#ifdef MOCKPP_PTI_WEAKNESS
  MOCKPP_STD_NS::cout << "  - support pti-weakness enabled\n";
#else
  MOCKPP_STD_NS::cout << "  - support pti-weakness disabled\n";
#endif

  PRINT_NS;

  MOCKPP_STD_NS::cout << "  - size of <char> is " << sizeof(MOCKPP_CHAR('x')) << MOCKPP_STD_NS::endl;
  MOCKPP_STD_NS::cout << "\n";

  boost::unit_test::unit_test_log_t::instance().set_threshold_level( boost::unit_test::log_warnings );
  return 0;
}

#endif

int BOOST_TEST_CALL_DECL
main( int argc, char* argv[] )
{
     // prototype for user's unit test init function
#ifdef BOOST_TEST_ALTERNATIVE_INIT_API
    extern bool init_unit_test();

    boost::unit_test::init_unit_test_func init_func = &init_unit_test;
#else
    extern ::boost::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] );

    boost::unit_test::init_unit_test_func init_func = &init_unit_test_suite;
#endif

    return ::boost::unit_test::unit_test_main( init_func, argc, argv );
}

#else

int main(int argc, char **argv)
{
  int ret = 1;
  MOCKPP_STD_NS::cout << "starting tests..\n";

#if defined(MOCKPP_USE_CXXTEST)
  MOCKPP_STD_NS::cout << "  - using cxxtest framework\n";
#elif defined(MOCKPP_USE_CPPUNIT)
  MOCKPP_STD_NS::cout << "  - using cppunit framework\n";
#endif

  PRINT_NS;

#ifdef MOCKPP_PTI_WEAKNESS
  MOCKPP_STD_NS::cout << "  - support pti-weakness enabled\n";
#else
  MOCKPP_STD_NS::cout << "  - support pti-weakness disabled\n";
#endif

  MOCKPP_STD_NS::cout << "  - size of <char> is " << sizeof(MOCKPP_CHAR('x')) << MOCKPP_STD_NS::endl;
  MOCKPP_STD_NS::cout << "\n";

#if defined(MOCKPP_USE_CXXTEST)

  ret = run_cxxtest(argc, argv);

#elif defined(MOCKPP_USE_CPPUNIT)

  MOCKPP_STD_NS::cout << "Options\n";
  MOCKPP_STD_NS::cout << "  --show-name        show method names before calling\n";
  MOCKPP_STD_NS::cout << "  --compiler-output  output similar to compilers\n";

  ret = run_cppunit(argc, argv);

  MOCKPP_STD_NS::cout << "\n";

#endif

  MOCKPP_STD_NS::cout << "Result: " << ret << MOCKPP_STD_NS::endl << MOCKPP_STD_NS::endl;
  return ret;
}


#endif // frameworks

