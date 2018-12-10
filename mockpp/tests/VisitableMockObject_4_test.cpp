/***************************************************************************
                     VisitableMockObject_4_test.cpp
                                 -
  unit tests for VisitableMockObject class and 4 parameter methods
                             -------------------
    begin                : Mit Feb 19 2003
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: VisitableMockObject_4_test.cpp 1491 2010-01-02 22:21:45Z ewald-arnold $

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

#include <mockpp/constraint/IsEqual.h>
#include <mockpp/constraint/IsNot.h>

#include <mockpp/ExpectationValue.h>
#include <mockpp/visiting/VisitableMockObject.h>
#include <mockpp/util/AssertMo.h>


class VisitableMockObject_4_test MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
{
 public:

#if defined (MOCKPP_USE_CXXTEST)

#elif defined(MOCKPP_USE_BOOSTTEST)

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE( VisitableMockObject_4_test );

  CPPUNIT_TEST(test_controller);
  CPPUNIT_TEST(test_thrower);
  CPPUNIT_TEST(test_parameter);
  CPPUNIT_TEST(test_parameter_ex);
  CPPUNIT_TEST(test_response);
  CPPUNIT_TEST(test_return);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST(test_default_throw);
  CPPUNIT_TEST(test_inline_pre_1_2);
  CPPUNIT_TEST(test_inline_post_1_2);
  CPPUNIT_TEST(test_constraint);
  CPPUNIT_TEST(test_controller_constraint);

  CPPUNIT_TEST(fail_add_throw_after_active);
  CPPUNIT_TEST(fail_add_throw_val_after_active);
  CPPUNIT_TEST(fail_set_throw_after_active);
  CPPUNIT_TEST(fail_add_method_after_active);
  CPPUNIT_TEST(fail_add_return_after_active);
  CPPUNIT_TEST(fail_set_return_after_active);
  CPPUNIT_TEST(fail_parameter);
  CPPUNIT_TEST(fail_return);
  CPPUNIT_TEST(fail_unused_throwable);
  CPPUNIT_TEST(fail_unused_value);

CPPUNIT_TEST_SUITE_END();

#endif

 public:

  MOCKPP_TESTMETHOD_DECL void test_controller();
  MOCKPP_TESTMETHOD_DECL void test_thrower();
  MOCKPP_TESTMETHOD_DECL void test_parameter();
  MOCKPP_TESTMETHOD_DECL void test_parameter_ex();
  MOCKPP_TESTMETHOD_DECL void test_response();
  MOCKPP_TESTMETHOD_DECL void test_return();
  MOCKPP_TESTMETHOD_DECL void test_clear();
  MOCKPP_TESTMETHOD_DECL void test_default_throw();
  MOCKPP_TESTMETHOD_DECL void test_inline_pre_1_2();
  MOCKPP_TESTMETHOD_DECL void test_inline_post_1_2();
  MOCKPP_TESTMETHOD_DECL void test_constraint();
  MOCKPP_TESTMETHOD_DECL void test_controller_constraint();

  MOCKPP_TESTMETHOD_DECL void fail_unused_value();
  MOCKPP_TESTMETHOD_DECL void fail_unused_throwable();
  MOCKPP_TESTMETHOD_DECL void fail_parameter();
  MOCKPP_TESTMETHOD_DECL void fail_return();
  MOCKPP_TESTMETHOD_DECL void fail_add_method_after_active();
  MOCKPP_TESTMETHOD_DECL void fail_add_throw_val_after_active();
  MOCKPP_TESTMETHOD_DECL void fail_add_throw_after_active();
  MOCKPP_TESTMETHOD_DECL void fail_set_throw_after_active();
  MOCKPP_TESTMETHOD_DECL void fail_add_return_after_active();
  MOCKPP_TESTMETHOD_DECL void fail_set_return_after_active();
};


#if defined (MOCKPP_USE_CXXTEST)

MOCKPP_CXXTEST_SUITE_REGISTRATION( VisitableMockObject_4_test );

MOCKPP_CXXTEST(VisitableMockObject_4_test, test_controller);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_thrower);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_parameter);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_parameter_ex);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_response);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_return);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_clear);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_default_throw);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_inline_pre_1_2);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_inline_post_1_2);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_constraint);
MOCKPP_CXXTEST(VisitableMockObject_4_test, test_controller_constraint);

MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_add_throw_after_active);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_add_throw_val_after_active);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_set_throw_after_active);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_add_method_after_active);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_add_return_after_active);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_set_return_after_active);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_parameter);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_return);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_unused_throwable);
MOCKPP_CXXTEST(VisitableMockObject_4_test, fail_unused_value);

#elif defined(MOCKPP_USE_BOOSTTEST)

MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_controller);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_thrower);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_parameter);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_parameter_ex);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_response);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_return);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_clear);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_default_throw);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_inline_pre_1_2);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_inline_post_1_2);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_constraint);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, test_controller_constraint);

MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_add_throw_after_active);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_add_throw_val_after_active);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_set_throw_after_active);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_add_method_after_active);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_add_return_after_active);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_set_return_after_active);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_parameter);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_return);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_unused_throwable);
MOCKPP_BOOST_TEST(VisitableMockObject_4_test, fail_unused_value);

#elif defined(MOCKPP_USE_CPPUNIT)

CPPUNIT_TEST_SUITE_REGISTRATION (VisitableMockObject_4_test);

#endif // frameworks



class MyVisitableMockObject_4 : public MOCKPP_NS::VisitableMockObject
{
  public:

    MyVisitableMockObject_4(const MOCKPP_NS::String &name)
      : MOCKPP_NS::VisitableMockObject(name, 0),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VISITABLE4(visitable)
    {}

    MOCKPP_VISITABLE4(MyVisitableMockObject_4, int, visitable, unsigned, unsigned, unsigned, unsigned);

    bool isClear()
    {
      return    visitableDefaultThrowable.get() == 0  // check preprocessed doc-template.h for the actual members
             && visitableThrowables.size() == 0

             && visitableResponseValues.size() == 0
             && visitableParameter1.size() == 0
             && visitableParameter2.size() == 0
             && visitableParameter3.size() == 0
             && visitableParameter4.size() == 0

             && visitablehaveDefaultReturnValue == false
             && visitableDefaultReturnValueUsed == false
             && visitableReturnValues.hasMoreObjects() == false;
    }
};



class MyVisitableMockObject_4ex : public MOCKPP_NS::VisitableMockObject
{
  public:

    MyVisitableMockObject_4ex(const MOCKPP_NS::String &name)
      : MOCKPP_NS::VisitableMockObject(name, 0),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VISITABLE_EXT4(visitable4, Ext),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VISITABLE_EXT3(visitable3, Ext),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VISITABLE_EXT2(visitable2, Ext),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VISITABLE_EXT1(visitable1, Ext),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VISITABLE_EXT0(visitable0, Ext)
    {}

    MOCKPP_VISITABLE_EXT4(MyVisitableMockObject_4ex, const MOCKPP_STL::string, visitable4, const MOCKPP_STL::string &, const MOCKPP_STL::string &, const MOCKPP_STL::string &, const MOCKPP_STL::string &,
                                                     MOCKPP_STL::string,       Ext,        MOCKPP_STL::string,         MOCKPP_STL::string,         MOCKPP_STL::string,         MOCKPP_STL::string);

    MOCKPP_VISITABLE_EXT3(MyVisitableMockObject_4ex, const MOCKPP_STL::string, visitable3, const MOCKPP_STL::string &, const MOCKPP_STL::string &, const MOCKPP_STL::string &,
                                                     MOCKPP_STL::string,       Ext,        MOCKPP_STL::string,         MOCKPP_STL::string,         MOCKPP_STL::string);

    MOCKPP_VISITABLE_EXT2(MyVisitableMockObject_4ex, const MOCKPP_STL::string, visitable2, const MOCKPP_STL::string &, const MOCKPP_STL::string &,
                                                     MOCKPP_STL::string,       Ext,        MOCKPP_STL::string,         MOCKPP_STL::string);

    MOCKPP_VISITABLE_EXT1(MyVisitableMockObject_4ex, const MOCKPP_STL::string, visitable1, const MOCKPP_STL::string &,
                                                     MOCKPP_STL::string,       Ext,        MOCKPP_STL::string);

    MOCKPP_VISITABLE_EXT0(MyVisitableMockObject_4ex, const MOCKPP_STL::string, visitable0,
                                                     MOCKPP_STL::string,       Ext);

    bool isClear()
    {
      return    visitable4ExtDefaultThrowable.get() == 0  // check preprocessed doc-template.h for the actual members
             && visitable4ExtThrowables.size() == 0

             && visitable4ExtResponseValues.size() == 0
             && visitable4ExtParameter1.size() == 0
             && visitable4ExtParameter2.size() == 0
             && visitable4ExtParameter3.size() == 0
             && visitable4ExtParameter4.size() == 0

             && visitable4ExthaveDefaultReturnValue == false
             && visitable4ExtDefaultReturnValueUsed == false
             && visitable4ExtReturnValues.hasMoreObjects() == false;
    }
};


void VisitableMockObject_4_test::test_controller()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.addThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("exceptional string")));
  ctr.addThrowable(MOCKPP_STL::string("exceptional string"), 3);
  ctr.setDefaultThrowable(MOCKPP_NS::make_throwable(int(123)));
  ctr.addReturnValue(1);
  ctr.addReturnValue(11);
  ctr.setDefaultReturnValue(123);
  ctr.addResponseValue(0, 1, 2, 3, 4);
  ctr.addResponseValue(1, 0, 2, 3, 4);
  ctr.addResponseThrowable(MOCKPP_NS::make_throwable(int(1)), 0, 2, 3, 4);
  ctr.addResponseThrowable(MOCKPP_NS::make_throwable(int(0)), 1, 2, 3, 4);
}


void VisitableMockObject_4_test::test_thrower()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.addThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("exceptional string 1")));
  ctr.addThrowable(MOCKPP_STL::string("exceptional string 2"), 2);
  ctr.setDefaultThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("exceptional string 3")));

  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(1, 2, 3, 4);

  mvo.activate();

#ifndef MOCKPP_NO_EXCEPTIONS
  MOCKPP_ASSERT_THROWING(mvo.visitable(1, 2, 3, 4), MOCKPP_PCSTRING("1"),
                         MOCKPP_STL::string, "exceptional string 1");

  MOCKPP_ASSERT_THROWING(mvo.visitable(1, 2, 3, 4), MOCKPP_PCSTRING("2"),
                         MOCKPP_STL::string, "exceptional string 2");

  MOCKPP_ASSERT_THROWING(mvo.visitable(1, 2, 3, 4), MOCKPP_PCSTRING("3"),
                         MOCKPP_STL::string, "exceptional string 2");

  MOCKPP_ASSERT_THROWING(mvo.visitable(1, 2, 3, 4), MOCKPP_PCSTRING("4"),
                         MOCKPP_STL::string, "exceptional string 3");
#endif
}


void VisitableMockObject_4_test::fail_add_method_after_active()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  mvo.visitable(1, 2, 3, 4);
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    mvo.visitable(1, 2, 3, 4);
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_add_throw_after_active()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    ctr.addThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("exceptional string")));
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_add_throw_val_after_active()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    ctr.addThrowable(MOCKPP_STL::string("exceptional string"), 1);
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_set_throw_after_active()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    ctr.setDefaultThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("exceptional string")));
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_parameter()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.setDefaultReturnValue(1);
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(11, 2, 3, 4);
  mvo.visitable(111, 2, 3, 4);
  mvo.activate();
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(11, 2, 3, 4);
  bool thrown = false;
  MOCKPP_TRY
  {
    mvo.visitable(222, 2, 3, 4);
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_add_return_after_active()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    ctr.addReturnValue(1);
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_set_return_after_active()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    ctr.setDefaultReturnValue(1);
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_return()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);

  ctr.addReturnValue(1);
  ctr.addReturnValue(11);

  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(2, 2, 3, 4);
  mvo.visitable(3, 2, 3, 4);

  mvo.activate();

  MOCKPP_ASSERT_TRUE(1 == mvo.visitable(1, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(11 == mvo.visitable(2, 2, 3, 4));
  bool thrown = false;
  MOCKPP_TRY
  {
    mvo.visitable(3, 2, 3, 4);
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::test_return()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);

  ctr.setDefaultReturnValue(123);
  ctr.addReturnValue(1,2);
  ctr.addReturnValue(11, 2);

  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(2, 2, 3, 4);
  mvo.visitable(2, 2, 3, 4);
  mvo.visitable(3, 2, 3, 4);
  mvo.visitable(4, 2, 3, 4);

  mvo.activate();

  MOCKPP_ASSERT_TRUE(1 == mvo.visitable(1, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(1 == mvo.visitable(1, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(11 == mvo.visitable(2, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(11 == mvo.visitable(2, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(123 == mvo.visitable(3, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(123 == mvo.visitable(4, 2, 3, 4));
  mvo.verify();
}


void VisitableMockObject_4_test::test_parameter_ex()
{
  MyVisitableMockObject_4ex mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_ASSERT_TRUE(mvo.isClear() == true);

  MOCKPP_CONTROLLER_FOR_EXT(MyVisitableMockObject_4ex, visitable4, Ext) ctr4 (&mvo);
  ctr4.setDefaultReturnValue("4");

  MOCKPP_CONTROLLER_FOR_EXT(MyVisitableMockObject_4ex, visitable3, Ext) ctr3 (&mvo);
  ctr3.setDefaultReturnValue("3");

  MOCKPP_CONTROLLER_FOR_EXT(MyVisitableMockObject_4ex, visitable2, Ext) ctr2 (&mvo);
  ctr2.setDefaultReturnValue("2");

  MOCKPP_CONTROLLER_FOR_EXT(MyVisitableMockObject_4ex, visitable1, Ext) ctr1 (&mvo);
  ctr1.setDefaultReturnValue("1");

  MOCKPP_CONTROLLER_FOR_EXT(MyVisitableMockObject_4ex, visitable0, Ext) ctr0 (&mvo);
  ctr0.setDefaultReturnValue("0");

  mvo.visitable4("1", "2", "3", "4");
  mvo.visitable3("2", "3", "4");
  mvo.visitable2("3", "4");
  mvo.visitable1("4");
  mvo.visitable0();

  mvo.activate();

  MOCKPP_ASSERT_TRUE(MOCKPP_STL::string("4") == mvo.visitable4("1", "2", "3", "4"));
  MOCKPP_ASSERT_TRUE(MOCKPP_STL::string("3") == mvo.visitable3("2", "3", "4"));
  MOCKPP_ASSERT_TRUE(MOCKPP_STL::string("2") == mvo.visitable2("3", "4"));
  MOCKPP_ASSERT_TRUE(MOCKPP_STL::string("1") == mvo.visitable1("4"));
  MOCKPP_ASSERT_TRUE(MOCKPP_STL::string("0") == mvo.visitable0());

  mvo.verify();
}


void VisitableMockObject_4_test::test_parameter()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.setDefaultReturnValue(1);
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(11, 2, 3, 4);
  mvo.visitable(111, 2, 3, 4);
  mvo.activate();
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(11, 2, 3, 4);
  mvo.visitable(111, 2, 3, 4);
  mvo.verify();
}


void VisitableMockObject_4_test::test_default_throw()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.addResponseThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw me 2")), 922, 2, 3, 4);
  ctr.addResponseThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw me 1")), 911, 2, 3, 4);
  ctr.setDefaultThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw default")));

  mvo.visitable(922, 2, 3, 4);
  mvo.visitable(911, 2, 3, 4);
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(2, 2, 3, 4);
  mvo.visitable(3, 2, 3, 4);

  mvo.activate();

#ifndef MOCKPP_NO_EXCEPTIONS
  MOCKPP_ASSERT_THROWING(mvo.visitable(922, 2, 3, 4), MOCKPP_PCHAR("response 1"),
                         MOCKPP_STL::string, MOCKPP_STL::string("throw me 2"));

  MOCKPP_ASSERT_THROWING(mvo.visitable(911, 2, 3, 4), MOCKPP_PCHAR("response 2"),
                         MOCKPP_STL::string, MOCKPP_STL::string("throw me 1"));

  MOCKPP_ASSERT_THROWING(mvo.visitable(1, 2, 3, 4), MOCKPP_PCHAR("default response"),
                         MOCKPP_STL::string, MOCKPP_STL::string("throw default"));

  MOCKPP_ASSERT_THROWING(mvo.visitable(2, 2, 3, 4), MOCKPP_PCHAR("default response"),
                         MOCKPP_STL::string, MOCKPP_STL::string("throw default"));
#endif
}


void VisitableMockObject_4_test::test_response()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);

  ctr.setDefaultReturnValue(111);
  ctr.addResponseValue(123, 456, 2, 3, 4);
  ctr.addResponseValue(321, 654, 2, 3, 4);

  ctr.addResponseThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw me 2")), 922, 2, 3, 4);
  ctr.addResponseThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw me 1")), 911, 2, 3, 4);

  mvo.visitable(456, 2, 3, 4);
  mvo.visitable(654, 2, 3, 4);
  mvo.visitable(1, 2, 3, 4);
  mvo.visitable(922, 2, 3, 4);
  mvo.visitable(911, 2, 3, 4);
  mvo.visitable(2, 2, 3, 4);
  mvo.visitable(3, 2, 3, 4);

  mvo.activate();

  MOCKPP_ASSERT_TRUE(123 == mvo.visitable(456, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(321 == mvo.visitable(654, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(111 == mvo.visitable(1, 2, 3, 4));

#ifndef MOCKPP_NO_EXCEPTIONS
  MOCKPP_ASSERT_THROWING(mvo.visitable(922, 2, 3, 4), MOCKPP_PCHAR("response 1"),
                         MOCKPP_STL::string, MOCKPP_STL::string("throw me 2"));

  MOCKPP_ASSERT_THROWING(mvo.visitable(911, 2, 3, 4), MOCKPP_PCHAR("response 2"),
                         MOCKPP_STL::string, MOCKPP_STL::string("throw me 1"));
#endif

  MOCKPP_ASSERT_TRUE(111 == mvo.visitable(2, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(111 == mvo.visitable(3, 2, 3, 4));

  mvo.verify();
}



void VisitableMockObject_4_test::test_clear()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_ASSERT_TRUE(mvo.isClear() == true);

  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.addThrowable(MOCKPP_STL::string("exceptional string"), 3);
  ctr.setDefaultThrowable(MOCKPP_NS::make_throwable(int(123)));

  ctr.addReturnValue(1);
  ctr.setDefaultReturnValue(123);

  ctr.addResponseValue(1, 0, 2, 3, 4);
  ctr.addResponseThrowable(MOCKPP_NS::make_throwable(int(1)), 0, 2, 3, 4);
  mvo.visitable(3, 2, 3, 4);
  mvo.activate();

  mvo.reset();
  MOCKPP_ASSERT_TRUE(mvo.isClear() == true);
}


void VisitableMockObject_4_test::fail_unused_throwable()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.setDefaultThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw default")));
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    mvo.verify();
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::fail_unused_value()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.setDefaultReturnValue(111);
  mvo.activate();
  bool thrown = false;
  MOCKPP_TRY
  {
    mvo.verify();
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_NS::AssertionFailedError &)
  {
    thrown = true;
  }
#endif
  MOCKPP_ASSERT_TRUE(thrown == true);
}


void VisitableMockObject_4_test::test_inline_pre_1_2()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.addReturnValue(111);
  ctr.addThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw 1")));
  ctr.addReturnValue(222);
  ctr.addThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw 2")));

  mvo.unsetThrowablesInline(); // old pre-1.2 mode
  mvo.activate();

  MOCKPP_TRY
  {
    mvo.visitable(1, 2, 3, 4);
    MOCKPP_FAIL(MOCKPP_PCHAR("should have thrown here"));
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_STL::string &ex)
  {
    MOCKPP_ASSERT_EQUALS(ex, MOCKPP_STL::string("throw 1"));
  }
#endif

  MOCKPP_TRY
  {
    mvo.visitable(1, 2, 3, 4);
    MOCKPP_FAIL(MOCKPP_PCHAR("should have thrown here"));
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_STL::string &ex)
  {
    MOCKPP_ASSERT_EQUALS(ex, MOCKPP_STL::string("throw 2"));
  }
#endif

  MOCKPP_ASSERT_TRUE(111 == mvo.visitable(1, 2, 3, 4));
  MOCKPP_ASSERT_TRUE(222 == mvo.visitable(1, 2, 3, 4));

  mvo.verify();
}


void VisitableMockObject_4_test::test_inline_post_1_2()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.addReturnValue(111);
  ctr.addThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw 1")));
  ctr.addReturnValue(222);
  ctr.addThrowable(MOCKPP_NS::make_throwable(MOCKPP_STL::string("throw 2")));
  mvo.activate();

  MOCKPP_ASSERT_TRUE(111 == mvo.visitable(1, 2, 3, 4));

  MOCKPP_TRY
  {
    mvo.visitable(1, 2, 3, 4);
    MOCKPP_FAIL(MOCKPP_PCHAR("should have thrown here"));
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_STL::string &ex)
  {
    MOCKPP_ASSERT_EQUALS(ex, MOCKPP_STL::string("throw 1"));
  }
#endif
  MOCKPP_ASSERT_TRUE(222 == mvo.visitable(1, 2, 3, 4));

  MOCKPP_TRY
  {
    mvo.visitable(1, 2, 3, 4);
    MOCKPP_FAIL(MOCKPP_PCHAR("should have thrown here"));
  }
#ifndef MOCKPP_NO_EXCEPTIONS
  catch(MOCKPP_STL::string &ex)
  {
    MOCKPP_ASSERT_EQUALS(ex, MOCKPP_STL::string("throw 2"));
  }
#endif
  mvo.verify();
}


void VisitableMockObject_4_test::test_constraint()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.setDefaultReturnValue(123);

  mvo.visitable(new MOCKPP_NS::IsEqual<unsigned>(12),
                new MOCKPP_NS::IsEqual<unsigned>(34),
                new MOCKPP_NS::IsEqual<unsigned>(56),
                new MOCKPP_NS::IsEqual<unsigned>(90));

  mvo.activate();
  mvo.visitable(12, 34, 56, 90);
  mvo.verify();
}


void VisitableMockObject_4_test::test_controller_constraint()
{
  MyVisitableMockObject_4 mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject_4, visitable) ctr (&mvo);
  ctr.setDefaultReturnValue(123);

  mvo.visitable(MOCKPP_NS::eq<unsigned>(10, 5),
                MOCKPP_NS::eq<unsigned>(20, 5),
                MOCKPP_NS::eq<unsigned>(30, 5),
                MOCKPP_NS::eq<unsigned>(50, 5));

  mvo.visitable(MOCKPP_NS::eq<unsigned>(10, 5),
                MOCKPP_NS::eq<unsigned>(20, 5),
                MOCKPP_NS::eq<unsigned>(30, 5),
                MOCKPP_NS::eq<unsigned>(50, 5));

  mvo.visitable(MOCKPP_NS::eq<unsigned>(10, 5),
                MOCKPP_NS::eq<unsigned>(20, 5),
                MOCKPP_NS::eq<unsigned>(30, 5),
                MOCKPP_NS::eq<unsigned>(50, 5));

  mvo.visitable(MOCKPP_NS::eq<unsigned>(10, 5),
                MOCKPP_NS::eq<unsigned>(20, 5),
                MOCKPP_NS::eq<unsigned>(30, 5),
                MOCKPP_NS::eq<unsigned>(50, 5));

  mvo.visitable(1, 1, 1, 1);

  ctr.addResponseThrowable(MOCKPP_NS::make_throwable((int)2),
                           MOCKPP_NS::eq<unsigned>(8),
                           MOCKPP_NS::eq<unsigned>(18),
                           MOCKPP_NS::eq<unsigned>(28),
                           MOCKPP_NS::eq<unsigned>(48));

  ctr.addResponseThrowable(MOCKPP_NS::make_throwable((int)1),
                           MOCKPP_NS::eq<unsigned>(12),
                           MOCKPP_NS::eq<unsigned>(22),
                           MOCKPP_NS::eq<unsigned>(32),
                           MOCKPP_NS::eq<unsigned>(52));

  ctr.addResponseValue(2, MOCKPP_NS::eq<unsigned>(9),
                          MOCKPP_NS::eq<unsigned>(19),
                          MOCKPP_NS::eq<unsigned>(29),
                          MOCKPP_NS::eq<unsigned>(49));

  ctr.addResponseValue(1, MOCKPP_NS::eq<unsigned>(11),
                          MOCKPP_NS::eq<unsigned>(21),
                          MOCKPP_NS::eq<unsigned>(31),
                          MOCKPP_NS::eq<unsigned>(51));

  mvo.activate();
  MOCKPP_ASSERT_TRUE(1 == mvo.visitable(11, 21, 31, 51));
  MOCKPP_ASSERT_TRUE(2 == mvo.visitable(9, 19, 29, 49));

#ifndef MOCKPP_NO_EXCEPTIONS
  MOCKPP_ASSERT_THROWING(mvo.visitable(8, 18, 28, 48),
                         MOCKPP_PCHAR("mvo.visitable(8, 18, 28, 48)"),
                         int,
                         2);

  MOCKPP_ASSERT_THROWING(mvo.visitable(12, 22, 32, 52),
                         MOCKPP_PCHAR("mvo.visitable(12, 22, 32, 52)"),
                         int,
                         1);
#endif

  MOCKPP_ASSERT_TRUE(123 == mvo.visitable(1, 1, 1, 1));
  mvo.verify();
}



