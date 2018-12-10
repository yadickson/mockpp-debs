/***************************************************************************
                     ChainableMockObject_3_test.cpp
                                 -
  unit tests for ChainableMockObject class and 3 parameter methods
                             -------------------
    begin                : Mit Feb 19 2003
    copyright            : (C) 2003 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: ChainableMockObject_3_test.cpp 1487 2010-01-02 18:11:57Z ewald-arnold $

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

#include <mockpp/chaining/ChainableMockObject.h>


#include <mockpp/chaining/ChainingMockObjectSupport.h>
#include <mockpp/chaining/Invocation.h>

#include <mockpp/constraint/OutBound.h>


class ChainableMockObject_3_test MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
{
 public:

#if defined (MOCKPP_USE_CXXTEST)

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE( ChainableMockObject_3_test );

  CPPUNIT_TEST(test_outbound);
  CPPUNIT_TEST( test_parameter_3 );

CPPUNIT_TEST_SUITE_END();

#endif

 public:

  MOCKPP_TESTMETHOD_DECL void test_outbound();
  MOCKPP_TESTMETHOD_DECL void test_parameter_3();
};


#if defined (MOCKPP_USE_CXXTEST)

MOCKPP_CXXTEST_SUITE_REGISTRATION( ChainableMockObject_3_test );
MOCKPP_CXXTEST(ChainableMockObject_3_test, test_outbound);
MOCKPP_CXXTEST(ChainableMockObject_3_test,  test_parameter_3 );

#elif defined(MOCKPP_USE_BOOSTTEST)

MOCKPP_BOOST_TEST(ChainableMockObject_3_test, test_outbound);
MOCKPP_BOOST_TEST(ChainableMockObject_3_test,  test_parameter_3 );

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE_REGISTRATION (ChainableMockObject_3_test);

#endif // frameworks



class MyChainableMockObject_3 : public MOCKPP_NS::ChainableMockObject
{
  public:

    MyChainableMockObject_3(const MOCKPP_NS::String &name)
      : MOCKPP_NS::ChainableMockObject(name, 0)
      , MOCKPP_CONSTRUCT_MEMBERS_FOR_CHAINABLE3(chainable)
    {}

    MOCKPP_CHAINABLE3(MyChainableMockObject_3, int, chainable, unsigned, unsigned, unsigned);
};


class MyChainableMockObject_3ex : public MOCKPP_NS::ChainableMockObject
{
  public:

    MyChainableMockObject_3ex(const MOCKPP_NS::String &name)
      : MOCKPP_NS::ChainableMockObject(name, 0)
      , MOCKPP_CONSTRUCT_MEMBERS_FOR_CHAINABLE_EXT3(chainable3, Ext)
      , MOCKPP_CONSTRUCT_MEMBERS_FOR_CHAINABLE_EXT3(outbound, Ext)
    {}

    MOCKPP_CHAINABLE_EXT3(MyChainableMockObject_3ex, MOCKPP_STL::string, chainable3, const MOCKPP_STL::string &, const MOCKPP_STL::string &, const MOCKPP_STL::string &,
                                                     MOCKPP_STL::string, Ext,        MOCKPP_STL::string,         MOCKPP_STL::string,         MOCKPP_STL::string);

    MOCKPP_CHAINABLE_EXT3(MyChainableMockObject_3ex, int, outbound, unsigned &, unsigned &, unsigned &,
                                                     int, Ext,      unsigned,   unsigned,   unsigned);
};


void ChainableMockObject_3_test::test_parameter_3()
{
  MyChainableMockObject_3 mcm(MOCKPP_PCHAR("chainable-object"));

  MOCKPP_CHAINER_FOR(MyChainableMockObject_3, chainable) chain(&mcm);

  chain.stubs(MOCKPP_NS::once())
       .with(MOCKPP_NS::eq( (unsigned int) 12),
             MOCKPP_NS::eq( (unsigned int) 34),
             MOCKPP_NS::eq( (unsigned int) 56))
       .will(MOCKPP_NS::returnValue<int>(123456));

  chain.stubs(MOCKPP_NS::once())
       .with(MOCKPP_NS::eq( (unsigned int) 65),
             MOCKPP_NS::eq( (unsigned int) 43),
             MOCKPP_NS::eq( (unsigned int) 21))
       .will(MOCKPP_NS::returnValue<int>(654321));

  MOCKPP_ASSERT_TRUE(mcm.chainable(12, 34, 56) == 123456);
  MOCKPP_ASSERT_TRUE(mcm.chainable(65, 43, 21) == 654321);

  MOCKPP_TRY
  {
    mcm.chainable(1, 2, 3);
    MOCKPP_ASSERT_TRUE_MESSAGE(MOCKPP_PCHAR("should have thrown"), false);
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &ex)
  {
    MOCKPP_ASSERT_TRUE(ex.getMessage().find(MOCKPP_PCHAR("unexpected invocation")) != MOCKPP_NS::String::npos);
  }
#endif

  mcm.verify();
}


void ChainableMockObject_3_test::test_outbound()
{
  MyChainableMockObject_3ex mcm(MOCKPP_PCHAR("chainable-object"));

  MOCKPP_CHAINER_FOR_EXT(MyChainableMockObject_3ex, outbound, Ext) chain(&mcm);

  chain.stubs(MOCKPP_NS::once())
       .with(MOCKPP_NS::outBound( (unsigned int) 1123),
             MOCKPP_NS::outBound( (unsigned int) 2123),
             MOCKPP_NS::outBound( (unsigned int) 3123));

  unsigned val1 = 0;
  unsigned val2 = 0;
  unsigned val3 = 0;
  mcm.outbound(val1,val2, val3);
  MOCKPP_ASSERT_EQUALS((unsigned)1123, val1);
  MOCKPP_ASSERT_EQUALS((unsigned)2123, val2);
  MOCKPP_ASSERT_EQUALS((unsigned)3123, val3);
}



