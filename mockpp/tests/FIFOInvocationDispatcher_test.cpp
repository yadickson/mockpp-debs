/***************************************************************************
FIFOInvocationDispatcher_test.cpp  -  unit tests for FIFOInvocationDispatcher class
                             -------------------
    begin                : Wed Sep 4 2004
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

   $Id: FIFOInvocationDispatcher_test.cpp 1491 2010-01-02 22:21:45Z ewald-arnold $

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

#include <mockpp/chaining/ChainingMockObjectSupport.h>
#include <mockpp/chaining/FIFOInvocationDispatcher.h>
#include <mockpp/chaining/Invokable.h>
#include <mockpp/chaining/Invocation.h>
#include <mockpp/chaining/mockpp_pti.h>

#include <mockpp/stub/ReturnStub.h>
#include <mockpp/stub/VoidStub.h>



typedef MOCKPP_NS::Invocation0 GetterInvocation;
typedef MOCKPP_NS::Invocation0 VoidInvocation;


MOCKPP_TYPELESSSTUBADAPTER_PTI_IMPL(VoidInvocation)
MOCKPP_FIFOINVOCATIONDISPATCHER_PTI_IMPL(VoidInvocation)


MOCKPP_ANON_NS_START


class FIFOInvocationDispatcher_test MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
{
 public:

#if defined (MOCKPP_USE_CXXTEST)

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE( FIFOInvocationDispatcher_test );

  CPPUNIT_TEST(test_void_dispatch);
  CPPUNIT_TEST(test_dispatch);

CPPUNIT_TEST_SUITE_END();

#endif

 public:

  MOCKPP_TESTMETHOD_DECL void test_void_dispatch();
  MOCKPP_TESTMETHOD_DECL void test_dispatch();
};


#if defined (MOCKPP_USE_CXXTEST)

MOCKPP_CXXTEST_SUITE_REGISTRATION( FIFOInvocationDispatcher_test );
MOCKPP_CXXTEST(FIFOInvocationDispatcher_test, test_void_dispatch);
MOCKPP_CXXTEST(FIFOInvocationDispatcher_test, test_dispatch);

#elif defined(MOCKPP_USE_BOOSTTEST)

MOCKPP_BOOST_TEST(FIFOInvocationDispatcher_test, test_void_dispatch);
MOCKPP_BOOST_TEST(FIFOInvocationDispatcher_test, test_dispatch);

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE_REGISTRATION (FIFOInvocationDispatcher_test);

#endif // frameworks



template <typename R, typename I>
class TestInvokable : public MOCKPP_NS::Invokable<R,I>
{
  public:

    bool match_result;
    R    invoke_return;

    virtual bool matches( const I &/*invocation*/ )
    {
      return match_result;
    }

    virtual void reset()
    {}

    virtual R invoke( const I &/*invocation*/ )
    {
      return invoke_return;
    }

    virtual bool hasDescription()
    {
      return false;
    }

    virtual MOCKPP_NS::String describeTo( MOCKPP_NS::String &/*buffer*/ ) const
    {
      return MOCKPP_PCHAR("") ;
    }

    virtual void verify()
    {
    }
};


template <typename I>
class TestVoidInvokable : public MOCKPP_NS::Invokable<void,I>
{
  public:

    bool match_result;
    bool invoked;

    virtual bool matches( const I &/*invocation*/ )
    {
      return match_result;
    }

    virtual void invoke( const I &/*invocation*/ )
    {
      invoked = true;
    }

    virtual void reset()
    {}

    virtual bool hasDescription()
    {
      return false;
    }

    virtual MOCKPP_NS::String describeTo( MOCKPP_NS::String &/*buffer*/ ) const
    {
      return MOCKPP_PCHAR("") ;
    }

    virtual void verify()
    {
    }
};


template <typename R, typename I>
class FIFO : public MOCKPP_NS::FIFOInvocationDispatcher<R,I>
{
  public:

    virtual R doDispatch( const I &invocation )
    {
       return dispatch(invocation);
    }
};


template <typename I>
class VoidFIFO : public MOCKPP_NS::FIFOInvocationDispatcher<void, I>
{
  public:

    virtual void doVoidDispatch( const I &invocation )
    {
       dispatch(invocation);
    }
};


void FIFOInvocationDispatcher_test::test_dispatch()
{
  GetterInvocation ginv(MOCKPP_PCHAR("TestClass::getProp"));

  FIFO<int,GetterInvocation> id;
  typedef TestInvokable<int, GetterInvocation> TInvok;

  TInvok *ti1 = new TInvok();
  TInvok *ti2 = new TInvok();
  id.add(ti1);
  id.add(ti2);

  ti1->match_result = true;
  ti2->match_result = true;

  ti1->invoke_return = 1;
  ti2->invoke_return = 2;
  id.setDefaultStub(MOCKPP_NS::returnValue<int>(3));
  MOCKPP_ASSERT_TRUE(1 == id.doDispatch(ginv));

  ti1->match_result = false;
  MOCKPP_ASSERT_TRUE(2 == id.doDispatch(ginv));

  ti2->match_result = false;
  MOCKPP_ASSERT_TRUE(3 == id.doDispatch(ginv));
}


void FIFOInvocationDispatcher_test::test_void_dispatch()
{
  VoidInvocation ginv(MOCKPP_PCHAR("TestClass::voidProp"));

  VoidFIFO<VoidInvocation> id;
  typedef TestVoidInvokable<VoidInvocation> TInvok;

  TInvok *ti1 = new TInvok();
  TInvok *ti2 = new TInvok();
  id.add(ti1);
  id.add(ti2);

  ti1->match_result = true;
  ti2->match_result = true;

  ti1->invoked = false;
  ti2->invoked = false;
  id.setDefaultStub(new MOCKPP_NS::VoidStub);
  id.doVoidDispatch(ginv);
  MOCKPP_ASSERT_TRUE(ti1->invoked == true );
  MOCKPP_ASSERT_TRUE(ti2->invoked == false );

  ti1->invoked = false;
  ti2->invoked = false;
  ti1->match_result = false;
  id.doVoidDispatch(ginv);
  MOCKPP_ASSERT_TRUE(ti1->invoked == false );
  MOCKPP_ASSERT_TRUE(ti2->invoked == true );

  ti1->invoked = false;
  ti2->invoked = false;
  ti2->match_result = false;
  id.doVoidDispatch(ginv);
  MOCKPP_ASSERT_TRUE(ti1->invoked == false );
  MOCKPP_ASSERT_TRUE(ti2->invoked == false );
}


MOCKPP_NS_END



