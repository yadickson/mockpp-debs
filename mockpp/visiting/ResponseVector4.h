/** @file
    @internal NOT INTENDED FOR PUBLIC INCLUSION
    @brief    Generated with gen_responsevector_N.pl.

  $Id: ResponseVector4.h 1506 2010-01-04 19:28:05Z ewald-arnold $

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

#ifndef MOCKPP_ResponseVector4_H
#define MOCKPP_ResponseVector4_H

#include <mockpp/mockpp.h> // always first

#include <mockpp/constraint/ConstraintHolder.h>
#include <mockpp/constraint/IsEqual.h>
#include <mockpp/visiting/VisitableMockObject_template.h>


MOCKPP_NS_START


/** Class returning a throwable depending on the parameters
  * passed to a method.
  */
template <typename P1, typename P2, typename P3, typename P4>
class ResponseThrowableVector4 : public ResponseVectorBase
{
  public:

  /**
    * Construct a new empty vector
    * @param aName Label used to identify vector
    * @param parent  parent verifiable
    */
    ResponseThrowableVector4(const String &aName, VerifiableList *parent)
      : ResponseVectorBase(aName, parent)
    {}

  /** Destroys the vector
    */
    virtual ~ResponseThrowableVector4()
    {
      reset();
    }

  /** Adds a throwable.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, unsigned count)
    {
      const ConstraintHolder<P1> h1 = new IsEqual<P1>(p1);
      const ConstraintHolder<P2> h2 = new IsEqual<P2>(p2);
      const ConstraintHolder<P3> h3 = new IsEqual<P3>(p3);
      const ConstraintHolder<P4> h4 = new IsEqual<P4>(p4);
      add(throwable, h1, h2, h3, h4, count);
    }

  /** Adds a throwable.
    * @param throwable      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable,
             const ConstraintHolder<P1> &p1,
             const ConstraintHolder<P2> &p2,
             const ConstraintHolder<P3> &p3,
             const ConstraintHolder<P4> &p4,
             unsigned count)
    {
      counter.push_back(count);
      tvec.push_back(throwable);
      typename MOCKPP_NS::Constraint<P1>::AP cons1 (p1);
      typename MOCKPP_NS::Constraint<P2>::AP cons2 (p2);
      typename MOCKPP_NS::Constraint<P3>::AP cons3 (p3);
      typename MOCKPP_NS::Constraint<P4>::AP cons4 (p4);
      t1vec.push_back(cons1.release());
      t2vec.push_back(cons2.release());
      t3vec.push_back(cons3.release());
      t4vec.push_back(cons4.release());
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

      for (unsigned i2 = 0; i2 < t2vec.size(); ++i2)
        delete t2vec[i2];
      t2vec.clear();

      for (unsigned i3 = 0; i3 < t3vec.size(); ++i3)
        delete t3vec[i3];
      t3vec.clear();

      for (unsigned i4 = 0; i4 < t4vec.size(); ++i4)
        delete t4vec[i4];
      t4vec.clear();
    }

  /** Finds a throwable for a set of parameters.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @return true: throwable found for parameters
    */
    bool find(Throwable * &throwable, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
    {
       for (unsigned i = 0; i < t1vec.size(); ++i)
         if (   counter[i] > 0
             && t1vec[i]->eval(p1)
             && t2vec[i]->eval(p2)
             && t3vec[i]->eval(p3)
             && t4vec[i]->eval(p4)
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
    MOCKPP_STL::vector<Constraint<P2>*>       t2vec; //!< shared internal member
    MOCKPP_STL::vector<Constraint<P3>*>       t3vec; //!< shared internal member
    MOCKPP_STL::vector<Constraint<P4>*>       t4vec; //!< shared internal member
};


/** Class returning a throwable depending on the parameters
  * passed to a method.
  */
template <typename R, typename P1, typename P2, typename P3, typename P4>
class ResponseVector4  : public ResponseThrowableVector4<P1, P2, P3, P4>
{
  public:

  /** Construct a new empty vector
    * @param aName Label used to identify vector
    * @param parent  parent verifiable
    */
    ResponseVector4(const String &aName, VerifiableList *parent)
      : ResponseThrowableVector4<P1, P2, P3, P4>(aName, parent)
    {}

  /** Adds a throwable.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, unsigned count)
    {
      MOCKPP_ASSERT_TRUE(throwable != 0);
      ResponseThrowableVector4<P1, P2, P3, P4>::add(throwable, p1, p2, p3, p4, count);
      R r;
      rvec.push_back(r);
    }

  /** Adds a throwable.
    * @param t      the throwable
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(Throwable *throwable,
             const ConstraintHolder<P1> &p1,
             const ConstraintHolder<P2> &p2,
             const ConstraintHolder<P3> &p3,
             const ConstraintHolder<P4> &p4,
             unsigned count)
    {
      MOCKPP_ASSERT_TRUE(throwable != 0);
      ResponseThrowableVector4<P1, P2, P3, P4>::add (throwable, p1, p2, p3, p4, count);
      R r;
      rvec.push_back(r);
    }

  /** Adds a return value.
    * @param r      the return value
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(const R &r, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, unsigned count)
    {
      ResponseThrowableVector4<P1, P2, P3, P4>::add((Throwable*)0, p1, p2, p3, p4, count);
      rvec.push_back(r);
    }

  /** Adds a return value.
    * @param r      the return value
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @param count  the number of times the object may be used
    */
    void add(const R &r,
             const ConstraintHolder<P1> &p1,
             const ConstraintHolder<P2> &p2,
             const ConstraintHolder<P3> &p3,
             const ConstraintHolder<P4> &p4,
             unsigned count)
    {
      ResponseThrowableVector4<P1, P2, P3, P4>::add((Throwable*)0, p1, p2, p3, p4, count);
      rvec.push_back(r);
    }

  /** Removes all the objects from the list.
    */
    void reset()
    {
      ResponseThrowableVector4<P1, P2, P3, P4>::reset();
      rvec.clear();
    }

#if defined(__BORLANDC__) || (__GNUC__ < 3)   // ==> BCB5.5.1 ?? F1004 Internal compiler error at 0x12548c1 with base 0x1200000
    bool find(Throwable * &throwable, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
    {
      return ResponseThrowableVector4<P1, P2, P3, P4>::find(throwable, p1, p2, p3, p4);
    }
#else
    using ResponseThrowableVector4<P1, P2, P3, P4>::find;
#endif

  /** Finds a return value for a set of parameters.
    * @param r      the value
    * @param p1     the parameter 1 upon which to return
    * @param p2     the parameter 2 upon which to return
    * @param p3     the parameter 3 upon which to return
    * @param p4     the parameter 4 upon which to return
    * @return true: return value found for parameters
    */
    bool find(R &r, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4)
    {
       for (unsigned i = 0; i < this->t1vec.size(); ++i)
         if (   this->counter[i] > 0
             && this->t1vec[i]->eval(p1)
             && this->t2vec[i]->eval(p2)
             && this->t3vec[i]->eval(p3)
             && this->t4vec[i]->eval(p4)
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


#endif // MOCKPP_ResponseVector4_H

