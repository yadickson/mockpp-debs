/***************************************************************************
             IsGreaterThan_test.cpp  -  unit tests for IsGreaterThan class
                             -------------------
    begin                : Sat Aug 21 2004
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: IsGreaterThan_test.cpp 1491 2010-01-02 22:21:45Z ewald-arnold $

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

#include <mockpp/constraint/IsGreaterThan.h>

#include <mockpp/compat/Asserter.h>


class IsGreaterThan_test MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
{
 public:

#if defined (MOCKPP_USE_CXXTEST)

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE( IsGreaterThan_test );

  CPPUNIT_TEST(test_describe);
  CPPUNIT_TEST(test_invoke);

CPPUNIT_TEST_SUITE_END();

#endif

 public:

  MOCKPP_TESTMETHOD_DECL void test_describe();
  MOCKPP_TESTMETHOD_DECL void test_invoke();
};


#if defined (MOCKPP_USE_CXXTEST)

MOCKPP_CXXTEST_SUITE_REGISTRATION( IsGreaterThan_test );
MOCKPP_CXXTEST(IsGreaterThan_test, test_describe);
MOCKPP_CXXTEST(IsGreaterThan_test, test_invoke);

#elif defined(MOCKPP_USE_BOOSTTEST)

MOCKPP_BOOST_TEST(IsGreaterThan_test, test_describe);
MOCKPP_BOOST_TEST(IsGreaterThan_test, test_invoke);

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE_REGISTRATION (IsGreaterThan_test);

#endif // frameworks



void IsGreaterThan_test::test_describe()
{
   MOCKPP_NS::IsGreaterThan<int> greater (12);
   MOCKPP_NS::String s = MOCKPP_PCHAR("IsGreaterOrEqual?");
   MOCKPP_ASSERT_TRUE(greater.describeTo(s) == MOCKPP_PCHAR("IsGreaterOrEqual?greaterThan 12"));
   MOCKPP_ASSERT_TRUE(s == MOCKPP_PCHAR("IsGreaterOrEqual?greaterThan 12"));
}


void IsGreaterThan_test::test_invoke()
{
   MOCKPP_NS::IsGreaterThan<int> greater (10);
   MOCKPP_ASSERT_TRUE(greater.eval(11) == true);
   MOCKPP_ASSERT_TRUE(greater.eval(10) == false);
   MOCKPP_ASSERT_TRUE(greater.eval(9) == false);
}



