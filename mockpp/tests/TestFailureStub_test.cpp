/***************************************************************************
             TestFailureStub_test.cpp  -  unit tests for  class
                             -------------------
    begin                : Sun Aug 22 2004
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: TestFailureStub_test.cpp 1491 2010-01-02 22:21:45Z ewald-arnold $

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

#include <mockpp/mockpp.h> // always first

#include "SelectFramework.h"

#include <mockpp/compat/Asserter.h>
#include <mockpp/stub/TestFailureStub.h>



class TestFailureStub_test MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
{
 public:

#if defined (MOCKPP_USE_CXXTEST)

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE( TestFailureStub_test );

  CPPUNIT_TEST(test_describe);
  CPPUNIT_TEST(test_invoke);

CPPUNIT_TEST_SUITE_END();

#endif

 public:

  MOCKPP_TESTMETHOD_DECL void test_describe();
  MOCKPP_TESTMETHOD_DECL void test_invoke();
};


#if defined (MOCKPP_USE_CXXTEST)

MOCKPP_CXXTEST_SUITE_REGISTRATION( TestFailureStub_test );
MOCKPP_CXXTEST(TestFailureStub_test, test_describe);
MOCKPP_CXXTEST(TestFailureStub_test, test_invoke);

#elif defined(MOCKPP_USE_BOOSTTEST)

MOCKPP_BOOST_TEST(TestFailureStub_test, test_describe);
MOCKPP_BOOST_TEST(TestFailureStub_test, test_invoke);

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE_REGISTRATION (TestFailureStub_test);

#endif // frameworks



void TestFailureStub_test::test_describe()
{
  MOCKPP_NS::TestFailureStub<int, int> ts(MOCKPP_PCHAR("my-description"));
  MOCKPP_NS::String s = MOCKPP_PCHAR("string");
  MOCKPP_NS::String s2 = ts.describeTo(s);
  MOCKPP_ASSERT_TRUE(s2.find(MOCKPP_PCHAR("my-description")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s2.find(MOCKPP_PCHAR("string")) != MOCKPP_NS::String::npos);
}


void TestFailureStub_test::test_invoke()
{
  MOCKPP_NS::TestFailureStub<int, int> ts(MOCKPP_PCHAR("my-description"));
  MOCKPP_TRY
  {
    ts.invoke((int)1);
    MOCKPP_FAIL(MOCKPP_PCHAR("Did not throw the exception"));
  }

#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &x)
  {
    MOCKPP_ASSERT_TRUE(x.getMessage().find(MOCKPP_PCHAR("my-description"))
                       != MOCKPP_NS::String::npos);
  }

  catch(...)
  {
    MOCKPP_FAIL(MOCKPP_PCHAR("Caught unexpected exception"));
  }
#endif
}



