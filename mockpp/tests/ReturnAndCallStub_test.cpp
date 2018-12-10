/***************************************************************************
           ReturnAndCallStub_test.cpp  -  unit tests for ReturnAndCallStub class
                             -------------------
    begin                : Thu Nov 14 2008
    copyright            : (C) 2008 by Mathieu Champlon
    email                : mockpp at ewald-arnold dot de

  $Id: ReturnAndCallStub_test.cpp 1499 2010-01-03 17:05:29Z ewald-arnold $

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

//#include <iostream>

#include "SelectFramework.h"

#include <mockpp/stub/ReturnAndCallStub.h>

#include <mockpp/compat/Asserter.h>


class ReturnAndCallStub_test MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
{
 public:

#if defined (MOCKPP_USE_CXXTEST)

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE( ReturnAndCallStub_test );

  CPPUNIT_TEST(test_invoke);
  CPPUNIT_TEST(test_describe);

CPPUNIT_TEST_SUITE_END();

#endif

 public:

  MOCKPP_TESTMETHOD_DECL void test_describe();
  MOCKPP_TESTMETHOD_DECL void test_invoke();
};


#if defined (MOCKPP_USE_CXXTEST)

MOCKPP_CXXTEST_SUITE_REGISTRATION( ReturnAndCallStub_test );
MOCKPP_CXXTEST(ReturnAndCallStub_test, test_describe);
MOCKPP_CXXTEST(ReturnAndCallStub_test, test_invoke);

#elif defined(MOCKPP_USE_BOOSTTEST)

MOCKPP_BOOST_TEST(ReturnAndCallStub_test, test_describe);
MOCKPP_BOOST_TEST(ReturnAndCallStub_test, test_invoke);

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE_REGISTRATION (ReturnAndCallStub_test);

#endif // frameworks


class MyFunctor
{
  public:

    bool called;

    MyFunctor()
      : called(false)
    {}

    void operator()()
    {
      called = true;
    }
};


void ReturnAndCallStub_test::test_describe()
{
  MyFunctor f;
  MOCKPP_NS::ReturnAndCallStub<int, MyFunctor&> ds (1234, f);
  MOCKPP_NS::String b = MOCKPP_GET_STRING("abcd");
  MOCKPP_NS::String s = ds.describeTo(b);

//  MOCKPP_STD_NS::wcout << s << MOCKPP_STD_NS::endl;

  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("abcd")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("1234")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("calls functor")) != MOCKPP_NS::String::npos);

  MOCKPP_ASSERT_TRUE(b.find(MOCKPP_PCHAR("abcd")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(b.find(MOCKPP_PCHAR("1234")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(b.find(MOCKPP_PCHAR("calls functor")) != MOCKPP_NS::String::npos);
}


void ReturnAndCallStub_test::test_invoke()
{
  MyFunctor f;
  MOCKPP_NS::ReturnAndCallStub<int, MyFunctor&> ds (1234, f);
  int val = ds.typelessInvoke();
  MOCKPP_ASSERT_TRUE(val == 1234);
  MOCKPP_ASSERT_TRUE(true == f.called);
}



