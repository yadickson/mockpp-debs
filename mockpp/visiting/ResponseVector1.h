/** @file
    @internal NOT INTENDED FOR PUBLIC INCLUSION
    @brief    Generated with gen_responsevector_N.pl.

  $Id: ResponseVector1.h 1506 2010-01-04 19:28:05Z ewald-arnold $

 ***************************************************************************/

/**************************************************************************

   begin                : Sat Feb 15 2003
   copyright            : (C) 2002-2010 by Ewald Arnold
   email                : mockpp at ewald-arnold dot de

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2 of the License,
   or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 **/

#ifndef MOCKPP_ResponseVector1_H
#define MOCKPP_ResponseVector1_H

#include <mockpp/mockpp.h> // always first

#include <mockpp/constraint/ConstraintHolder.h>
#include <mockpp/constraint/IsEqual.h>
#include <mockpp/visiting/VisitableMockObject_template.h>


MOCKPP_NS_START


/** Class returning a throwable depending on the parameters
  * passed to a method.
  */
template <typename P1>
class ResponseThrowableVector1 : public ResponseVectorBase
{
  public:

  /**
    * Construct a new empty vector
    * @param aName Label used to identify vector
    * @param parent  parent verifiable
    */
    ResponseThrowableVector1(const String &aName, VerifiableList *parent)
      : ResponseVectorBase(aName, parent)
    {}

  /** Destroys the vector
    */
    virtual ~ResponseThrowableVector1()
    {
      reset();
    }

  /** Adds a throwable.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable, const P1 &p1, unsigned count)
    {
      const ConstraintHolder<P1> h1 = new IsEqual<P1>(p1);
      add(throwable, h1, count);
    }

  /** Adds a throwable.
    * @param throwable      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable,
             const ConstraintHolder<P1> &p1,
             unsigned count)
    {
      counter.push_back(count);
      tvec.push_back(throwable);
      typename MOCKPP_NS::Constraint<P1>::AP cons1 (p1);
      t1vec.push_back(cons1.release());
    }

  /** Removes all the objects from the list.
    */
    void reset()
    {
      counter.clear();
      tvec.reset();

      for (unsigned i1 = 0; i1 < t1vec.size(); ++i1)
        delete t1vec[i1];
      t1vec.clear();
    }

  /** Finds a throwable for a set of parameters.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @return true: throwable found for parameters
    */
    bool find(Throwable * &throwable, const P1 &p1)
    {
       for (unsigned i = 0; i < t1vec.size(); ++i)
         if (   counter[i] > 0
             && t1vec[i]->eval(p1)
            )
         {
           if (tvec.at(i) == 0)
             return false;

           if (counter[i] != MOCKPP_UNLIMITED)
             --counter[i];

           throwable = tvec.at(i);
           return true;
         }
       return false;
    }

  protected:

    MOCKPP_STL::vector<Constraint<P1>*>       t1vec; //!< shared internal member
};


/** Class returning a throwable depending on the parameters
  * passed to a method.
  */
template <typename R, typename P1>
class ResponseVector1  : public ResponseThrowableVector1<P1>
{
  public:

  /** Construct a new empty vector
    * @param aName Label used to identify vector
    * @param parent  parent verifiable
    */
    ResponseVector1(const String &aName, VerifiableList *parent)
      : ResponseThrowableVector1<P1>(aName, parent)
    {}

  /** Adds a throwable.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable, const P1 &p1, unsigned count)
    {
      MOCKPP_ASSERT_TRUE(throwable != 0);
      ResponseThrowableVector1<P1>::add(throwable, p1, count);
      R r;
      rvec.push_back(r);
    }

  /** Adds a throwable.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable,
             const ConstraintHolder<P1> &p1,
             unsigned count)
    {
      MOCKPP_ASSERT_TRUE(throwable != 0);
      ResponseThrowableVector1<P1>::add (throwable, p1, count);
      R r;
      rvec.push_back(r);
    }

  /** Adds a return value.
    * @param r      the return value
    * @param p1     the parameter 1 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(const R &r, const P1 &p1, unsigned count)
    {
      ResponseThrowableVector1<P1>::add((Throwable*)0, p1, count);
      rvec.push_back(r);
    }

  /** Adds a return value.
    * @param r      the return value
    * @param p1     the parameter 1 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(const R &r,
             const ConstraintHolder<P1> &p1,
             unsigned count)
    {
      ResponseThrowableVector1<P1>::add((Throwable*)0, p1, count);
      rvec.push_back(r);
    }

  /** Removes all the objects from the list.
    */
    void reset()
    {
      ResponseThrowableVector1<P1>::reset();
      rvec.clear();
    }

#if defined(__BORLANDC__) || (__GNUC__ < 3)   // ==> BCB5.5.1 ?? F1004 Internal compiler error at 0x12548c1 with base 0x1200000
    bool find(Throwable * &throwable, const P1 &p1)
    {
      return ResponseThrowableVector1<P1>::find(throwable, p1);
    }
#else
    using ResponseThrowableVector1<P1>::find;
#endif

  /** Finds a return value for a set of parameters.
    * @param r      the value
    * @param p1     the parameter 1 upon which to return
    * @return true: return value found for parameters
    */
    bool find(R &r, const P1 &p1)
    {
       for (unsigned i = 0; i < this->t1vec.size(); ++i)
         if (   this->counter[i] > 0
             && this->t1vec[i]->eval(p1)
            )
         {
           if (this->tvec.at(i) != 0)
             return false;

           if (this->counter[i] != MOCKPP_UNLIMITED)
             --this->counter[i];

           r = rvec[i];
           return true;
         }
       return false;
    }

  private:

    MOCKPP_STL::vector<R>        rvec;
};

MOCKPP_NS_END


#endif // MOCKPP_ResponseVector1_H

