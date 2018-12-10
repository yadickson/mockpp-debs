/***************************************************************************
        compilecheck.cpp  -  compile, try and instatiate all classes
                             -------------------
    begin                : Son Dez 22 2002
    copyright            : (C) 2002-2004 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: compilecheck.cpp 1513 2010-01-05 11:46:18Z ewald-arnold $

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

#define MOCKPP_ENABLE_DEFAULT_FORMATTER

#include <mockpp/mockpp.h> // always first

#include <iostream>
#include <cstdio>

#include <mockpp/Verifiable.h>
#include <mockpp/Expectation.h>
#include <mockpp/AbstractExpectation.h>
#include <mockpp/ExpectationValue.h>
#include <mockpp/ExpectationSegment.h>
#include <mockpp/ExpectationBoundary.h>
#include <mockpp/AbstractExpectationCollection.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ExpectationSet.h>
#include <mockpp/ExpectationMap.h>
#include <mockpp/ExpectationCounter.h>
#include <mockpp/MockObject.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/Throwable.h>
#include <mockpp/visiting/VisitableMockObject.h>

#include <mockpp/chaining/ChainableMockObject.h>
#include <mockpp/chaining/CountedChainableMethod.h>
#include <mockpp/chaining/ChainingMockObjectSupport.h>
#include <mockpp/chaining/ChainableMockMethod0.h>
#include <mockpp/chaining/ChainableMockMethod1.h>
#include <mockpp/chaining/ChainableMockMethod2.h>

#include <mockpp/compat/Formatter.h>

////////////////////////////////////////////////////


class MyVerifiable : public MOCKPP_NS::Verifiable
{
  public:
    MyVerifiable()
      : MOCKPP_NS::Verifiable(MOCKPP_PCHAR("name"), 0)
    {}

    virtual void verify()
    {
      // forwardException(AssertionFailedError());
    }

    virtual void reset()
    {
      // forwardException(AssertionFailedError());
    }
};


////////////////////////////////////////////////////


class MyExpectation : public MOCKPP_NS::Expectation
{
  public:
    MyExpectation()
      : MOCKPP_NS::Expectation(MOCKPP_PCHAR("name"), 0)
    {}

    virtual bool hasExpectations() const
    {
       return true;
    }


    virtual void setExpectNothing()
    {

    }


    virtual void setFailOnVerify()
    {

    }


    virtual void verify()
    {
      // forwardException(AssertionFailedException());
    }

    virtual void reset()
    {
      // forwardException(AssertionFailedException());
    }
};


////////////////////////////////////////////////////


class MyAbstractExpectation : public MOCKPP_NS::AbstractExpectation<int>
{
  public:

    MyAbstractExpectation(const MOCKPP_NS::String &name)
      : MOCKPP_NS::AbstractExpectation<int>(name, 0)
    {
    }


    virtual void clearActual()
    {
    }


    virtual bool hasExpectations()
    {
       return true;
    }


    virtual void setExpectNothing()
    {

    }


    virtual void setFailOnVerify()
    {

    }


    virtual void verify()
    {
      // forwardException(AssertionFailedException());
    }
};


////////////////////////////////////////////////////


class MyExpectationValue : public MOCKPP_NS::ExpectationValue<int>
{
  public:

    MyExpectationValue(const MOCKPP_NS::String &name)
      : MOCKPP_NS::ExpectationValue<int>(name, 0)
    {
    }
};


////////////////////////////////////////////////////


class MyExpectationBoundary : public MOCKPP_NS::ExpectationBoundary<float>
{
  public:

    MyExpectationBoundary(const MOCKPP_NS::String &name)
      : MOCKPP_NS::ExpectationBoundary<float>(name, 0)
    {
    }
};


////////////////////////////////////////////////////

#if 0
class MyType1 {};
class MyType2 {};
class MyType3 {};
class MyType4 {};
class MyType5 {};
class MyType6 {};

class MyVisitableMockObject : public MOCKPP_NS::VisitableMockObject
{
  public:

    MyVisitableMockObject(const MOCKPP_NS::String &name)
      : MOCKPP_NS::VisitableMockObject(name, 0),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_METHOD0(visitable0),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_METHOD1(visitable1),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_METHOD2(visitable2),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_METHOD3(visitable3),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_METHOD4(visitable4),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_METHOD5(visitable5),

        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_METHOD0(void_visitable0),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_METHOD1(void_visitable1),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_METHOD2(void_visitable2),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_METHOD3(void_visitable3),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_METHOD4(void_visitable4),
        MOCKPP_CONSTRUCT_MEMBERS_FOR_VOID_METHOD5(void_visitable5)
    {
    }

    MOCKPP_VISITABLE0(MyVisitableMockObject, unsigned, visitable0);
    MOCKPP_VISITABLE1(MyVisitableMockObject, unsigned, visitable1, int);
    MOCKPP_VISITABLE2(MyVisitableMockObject, unsigned, visitable2, int, wchar_t);
    MOCKPP_VISITABLE3(MyVisitableMockObject, unsigned, visitable3, int, wchar_t, float);
    MOCKPP_VISITABLE4(MyVisitableMockObject, unsigned, visitable4, int, wchar_t, float, MOCKPP_STL::string);
    MOCKPP_VISITABLE5(MyVisitableMockObject, unsigned, visitable5, int, wchar_t, float, MOCKPP_STL::string, long);

    MOCKPP_VOID_VISITABLE0(MyVisitableMockObject, void_visitable0);
    MOCKPP_VOID_VISITABLE1(MyVisitableMockObject, void_visitable1, int);
    MOCKPP_VOID_VISITABLE2(MyVisitableMockObject, void_visitable2, int, wchar_t);
    MOCKPP_VOID_VISITABLE3(MyVisitableMockObject, void_visitable3, int, wchar_t, float);
    MOCKPP_VOID_VISITABLE4(MyVisitableMockObject, void_visitable4, int, wchar_t, float, MOCKPP_STL::string);
    MOCKPP_VOID_VISITABLE5(MyVisitableMockObject, void_visitable5, int, wchar_t, float, MOCKPP_STL::string, long);
};
#endif

////////////////////////////////////////////////////


void string_taker (MOCKPP_NS::String &s)
{

}

template <class T>
MOCKPP_NS::ExpectationValue<T>* asdf(const T& t)
{
  return new MOCKPP_NS::ExpectationValue<T> ("name", 0);
}


class Output
{
};

class node {};

class HPAClusterAbstraction
{
  public:

    virtual void addParent(node*, HPAClusterAbstraction*) = 0;
};

class HPACluster : public HPAClusterAbstraction
{
  public:

   HPACluster(int startx, int starty, int width, int height)
   {}

   virtual void addParent(node*, HPAClusterAbstraction*)
   {}
 };


class HPAClusterMock : public HPACluster,
                       public MOCKPP_NS::ChainableMockObject
{
  public:

    HPAClusterMock(int startx, int starty, int width, int height)
      : HPACluster(startx, starty, width, height)
      , MOCKPP_NS::ChainableMockObject(MOCKPP_PCHAR("HPAClusterMock"), 0)
      , addParentMocker(MOCKPP_PCHAR("addParent"), this)
    { }

    virtual void addParent(node* n, HPAClusterAbstraction *hpacaMap)
    {
      this->addParentMocker.forward(n, hpacaMap);
    }

    MOCKPP_NS::ChainableMockMethod2<void, node*, HPAClusterAbstraction*> addParentMocker;
};


void dummy1()
{
  node *startClone = 0;
  HPAClusterMock* startCluster = new HPAClusterMock(0,0,1,2);
  HPACluster hpacaMap(1,2,3,4);
  startCluster->addParentMocker.expects(MOCKPP_NS::once())
                                .with(MOCKPP_NS::same<node*>(startClone),
                                      MOCKPP_NS::same<HPAClusterAbstraction*>(&hpacaMap));

  startCluster->addParent(startClone, &hpacaMap);
}


int main(int /* argc */, char ** /* argv */)
{
  return 0;

  MOCKPP_STD_NS::cout << "before dummy1\n";
  MOCKPP_TRY
  {
    dummy1();
  }
  MOCKPP_CATCH(MOCKPP_NS::AssertionFailedError &ae)
  {
#ifndef MOCKPP_NO_EXCEPTIONS
    MOCKPP_STD_NS::cout << "file: "
                        << MOCKPP_NS::getLatin1(ae.getSrcFile()).c_str() << MOCKPP_STD_NS::endl
                        << "line: "
                        << ae.getSrcLine() << MOCKPP_STD_NS::endl
                        << "msg : "
                        << MOCKPP_NS::getLatin1(ae.getMessage()).c_str() << MOCKPP_STD_NS::endl;
#endif
  }
  MOCKPP_CATCH(MOCKPP_STD_NS::exception *exp)
  {
#ifndef MOCKPP_NO_EXCEPTIONS
#ifndef MOCKPP_NO_RTTI
    MOCKPP_STD_NS::cout << "typeid * " << typeid(*exp).name() << MOCKPP_STD_NS::endl;
#endif
#endif
  }
  MOCKPP_CATCH(MOCKPP_STD_NS::exception &exr)
  {
#ifndef MOCKPP_NO_EXCEPTIONS
#ifndef MOCKPP_NO_RTTI
    MOCKPP_STD_NS::cout << "typeid & " << typeid(exr).name() << MOCKPP_STD_NS::endl;
#endif
#endif
  }
  MOCKPP_STD_NS::cout << "after dummy1\n";
  return 0;

  MOCKPP_NS::String fmt = MOCKPP_PCHAR("abc %1 %2 xyz");
  fmt << Output() << 1;
#if MOCKPP_UNICODE == 1
  MOCKPP_STD_NS::wcout << fmt.c_str() << MOCKPP_STD_NS::endl;
#else
  MOCKPP_STD_NS::cout << fmt.c_str() << MOCKPP_STD_NS::endl;
#endif

  return 0;

  MyVerifiable verifiable;
  MyExpectation expectation;
  MyExpectationValue expectationValue(MOCKPP_PCHAR("exval"));

  MOCKPP_NS::ExpectationSegment<MOCKPP_STL::string> expectationSegment(MOCKPP_PCHAR("exseg"), 0);
  MOCKPP_NS::ExpectationList<double> expectationList(MOCKPP_PCHAR("exlist"), 0);
  MOCKPP_NS::ExpectationSet<char> expectationSet(MOCKPP_PCHAR("exset"), 0);
  MOCKPP_NS::ExpectationMap<int, MOCKPP_NS::String> expectationMap(MOCKPP_PCHAR("exmap"), 0);
  MOCKPP_NS::ExpectationCounter expectationCounter (MOCKPP_PCHAR("excnt"), 0);
  MOCKPP_NS::ReturnObjectList<int>  returnObjectList (MOCKPP_PCHAR("rol"), 0);
  MOCKPP_NS::MockObject mockObject(MOCKPP_PCHAR("mo"));

  fmt = MOCKPP_PCHAR("abc %1 def");
  MOCKPP_STL::string s8;
  MOCKPP_STL::basic_string<wchar_t> s16;

  fmt << s8;
  fmt << s16;
  fmt << (int)123;
  fmt << (unsigned int)123;
  fmt << (long)123;
  fmt << (unsigned long)123;
  fmt << (float)1.23;
  fmt << (double)1.23;
  fmt << MOCKPP_CHAR('1');
  fmt << MOCKPP_PCHAR("123456");
  fmt << fmt;

  MOCKPP_NS::String s = MOCKPP_PCHAR("abc %1 def");
  s << 123;
#if MOCKPP_UNICODE == 1
  MOCKPP_STD_NS::wcout << s.c_str() << MOCKPP_STD_NS::endl;
#else
  MOCKPP_STD_NS::cout << s.c_str() << MOCKPP_STD_NS::endl;
#endif

  fmt = MOCKPP_PCHAR("abc %1 def");
  MOCKPP_NS::String s2 = fmt << 123;

  string_taker (fmt << 321);

#if MOCKPP_UNICODE == 1
  MOCKPP_STD_NS::wcout << s2.c_str() << MOCKPP_STD_NS::endl;
#else
  MOCKPP_STD_NS::cout << s2.c_str() << MOCKPP_STD_NS::endl;
#endif

  MOCKPP_STD_NS::printf ("%f\n", 12.345678);
  MOCKPP_STD_NS::printf ("%.2f\n", 12.345678);

#ifndef MOCKPP_NO_RTTI
  MOCKPP_STD_NS::cout << "typeid int " << typeid(int).name() << MOCKPP_STD_NS::endl;
  MOCKPP_STD_NS::cout << "typeid float " << typeid(float).name() << MOCKPP_STD_NS::endl;
  MOCKPP_STD_NS::cout << "typeid long " << typeid(long).name() << MOCKPP_STD_NS::endl;
#endif

  MOCKPP_STD_NS::exception *ex = new MOCKPP_NS::AssertionFailedError(__LINE__, __FILE__, MOCKPP_PCHAR("abc %1 def"));
  delete ex;
  MOCKPP_TRY
  {
    MOCKPP_STD_NS::cout << "throw?\n";
//    forwardException(ex);
  }
  MOCKPP_CATCH(MOCKPP_STD_NS::exception *exp)
  {
#ifndef MOCKPP_NO_EXCEPTIONS
#ifndef MOCKPP_NO_RTTI
    MOCKPP_STD_NS::cout << "typeid * " << typeid(*exp).name() << MOCKPP_STD_NS::endl;
#endif
#endif
  }
  MOCKPP_CATCH(MOCKPP_STD_NS::exception &exr)
  {
#ifndef MOCKPP_NO_EXCEPTIONS
#ifndef MOCKPP_NO_RTTI
    MOCKPP_STD_NS::cout << "typeid & " << typeid(exr).name() << MOCKPP_STD_NS::endl;
#endif
#endif
  }
  MOCKPP_STD_NS::cout << "after catch\n";


  MOCKPP_TRY
  {
    MOCKPP_ASSERT_DELTA(1, 10, 2);
  }
  MOCKPP_CATCH(MOCKPP_NS::AssertionFailedError &ae)
  {
#ifndef MOCKPP_NO_EXCEPTIONS
    MOCKPP_STD_NS::cout << "file: "
                        << MOCKPP_NS::getLatin1(ae.getSrcFile()).c_str() << MOCKPP_STD_NS::endl
                        << "line: " << ae.getSrcLine() << MOCKPP_STD_NS::endl
                        << "msg : " << MOCKPP_NS::getLatin1(ae.getMessage()).c_str() << MOCKPP_STD_NS::endl;
#endif
  }

  MOCKPP_TRY
  {
    MOCKPP_NS::Throwable *t =
      make_throwable(MOCKPP_NS::AssertionFailedError(__LINE__, __FILE__, MOCKPP_PCHAR("abc %1 def")));
    t->throw_me();
  }
  MOCKPP_CATCH(MOCKPP_NS::AssertionFailedError &ae)
  {
#ifndef MOCKPP_NO_EXCEPTIONS
    MOCKPP_STD_NS::cout << "file: "
                        << MOCKPP_NS::getLatin1(ae.getSrcFile()).c_str() << MOCKPP_STD_NS::endl
                        << "line: " << ae.getSrcLine() << MOCKPP_STD_NS::endl
                        << "msg : " << MOCKPP_NS::getLatin1(ae.getMessage()).c_str() << MOCKPP_STD_NS::endl;
#endif
  }
#if 0
  MyVisitableMockObject mvo(MOCKPP_PCHAR("mvo"));
  MOCKPP_CONTROLLER_FOR(MyVisitableMockObject, visitable1) visit1_ctr (&mvo);

  visit1_ctr.addThrowable(MOCKPP_STL::string("throw"), 2);
  visit1_ctr.addThrowable(MOCKPP_NS::make_throwable(int(123)));
  visit1_ctr.setDefaultThrowable(MOCKPP_NS::make_throwable(float(123.456)));
  visit1_ctr.addReturnValue(0);
  visit1_ctr.addReturnValue(1, 2);
  visit1_ctr.setDefaultReturnValue(0);
  visit1_ctr.addResponseValue(0, 1);
  visit1_ctr.addResponseValue(1, 2, 3);

  unsigned u;
  u = mvo.visitable0();
  u = mvo.visitable1(1);
  u = mvo.visitable2(1, L'a');
  u = mvo.visitable3(1, L'a', 1.23);
  u = mvo.visitable4(1, L'a', 1.23, MOCKPP_STL::string("abc"));
  u = mvo.visitable5(1, L'a', 1.23, MOCKPP_STL::string("abc"), -12345678);

  mvo.void_visitable0();
  mvo.void_visitable1(1);
  mvo.void_visitable2(1, L'a');
  mvo.void_visitable3(1, L'a', 1.23);
  mvo.void_visitable4(1, L'a', 1.23, MOCKPP_STL::string("abc"));
  mvo.void_visitable5(1, L'a', 1.23, MOCKPP_STL::string("abc"), -12345678);

  mvo.activate();
#endif
  return 0;
}

