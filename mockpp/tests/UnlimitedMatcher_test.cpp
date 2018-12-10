/***************************************************************************
    UnlimitedMatcher_test.cpp  -  unit tests for UnlimitedMatcher class
                             -------------------
    begin                : Sat Aug 27 2004
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: UnlimitedMatcher_test.cpp 1491 2010-01-02 22:21:45Z ewald-arnold $

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

#include <mockpp/matcher/UnlimitedMatcher.h>

class UnlimitedMatcher_test MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
{
 public:

#if defined (MOCKPP_USE_CXXTEST)

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE( UnlimitedMatcher_test );
  CPPUNIT_TEST(test_invoke);
CPPUNIT_TEST_SUITE_END();

#endif

 public:

  MOCKPP_TESTMETHOD_DECL void test_invoke();
};


#if defined (MOCKPP_USE_CXXTEST)

MOCKPP_CXXTEST_SUITE_REGISTRATION( UnlimitedMatcher_test );
MOCKPP_CXXTEST(UnlimitedMatcher_test, test_invoke);

#elif defined(MOCKPP_USE_BOOSTTEST)

MOCKPP_BOOST_TEST(UnlimitedMatcher_test, test_invoke);

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE_REGISTRATION(UnlimitedMatcher_test);

#endif


void UnlimitedMatcher_test::test_invoke()
{
  MOCKPP_NS::UnlimitedMatcher ir;
  MOCKPP_ASSERT_TRUE(ir.matches() == true);
  MOCKPP_ASSERT_TRUE(ir.hasBeenInvoked() == false);
  MOCKPP_ASSERT_TRUE(ir.getInvocationCount() == 0);

  MOCKPP_NS::String s = MOCKPP_PCHAR("hallo");
  MOCKPP_ASSERT_TRUE(ir.describeTo(s).find(MOCKPP_PCHAR("unlimited invocations")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("unlimited invocations")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("has been")) == MOCKPP_NS::String::npos);

  ir.incInvoked();

  MOCKPP_ASSERT_TRUE(ir.hasBeenInvoked() == true);
  MOCKPP_ASSERT_TRUE(ir.getInvocationCount() == 1);
  MOCKPP_ASSERT_TRUE(ir.matches() == true);

  s = MOCKPP_PCHAR("hallo");
  MOCKPP_ASSERT_TRUE(ir.describeTo(s).find(MOCKPP_PCHAR("unlimited invocations")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("unlimited invocations")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("hallo")) != MOCKPP_NS::String::npos);
  MOCKPP_ASSERT_TRUE(s.find(MOCKPP_PCHAR("has been")) != MOCKPP_NS::String::npos);
}


