/** @file
    @brief  Always matches and throws an exception

  $Id: TestFailureMatcher.h 1491 2010-01-02 22:21:45Z ewald-arnold $

 ***************************************************************************/

/**************************************************************************

   begin                : Thu Aug 26 2004
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

   *
   *  Original Java Sources:  Copyright (c) 2000-2004, jMock.org
   *

 **/

#ifndef MOCKPP_TESTFAILUREMATCHER_H
#define MOCKPP_TESTFAILUREMATCHER_H


#include <mockpp/mockpp.h> // always first

#include <mockpp/matcher/TypelessMatcher.h>


MOCKPP_NS_START


/** An invocation count matcher that always fails upon invocation
  * @ingroup grp_matcher
  * @see mockpp::never
  */
class MOCKPP_API_DECL0 TestFailureMatcher : public TypelessMatcher
{
  public:

  /** Creates the object
    * @param msg string to describe the failure
    */
    TestFailureMatcher( const String &msg );

  /** Checks if an invocation matches the expectaton
    * @return true: the invocation matches
    */
    virtual bool matches( );

  /** Does the object provide meaningful description via describeTo() ?.
    * @return true: description is available
    */
    virtual bool hasDescription();

  /** Increments the invocation count.
    * Actually the invocation always fails.
    */
    virtual void incInvoked( );

  /** Appends the description of this object to the buffer.
    * @param buffer The buffer that the description is appended to.
    * @return The current content of the buffer data
    */
    virtual String describeTo( String &buffer ) const;

  /** Verify that the expected value is within the allowed bounds.
    * If it fails, an AssertionFailedError is thrown
    */
    virtual void verify();

  private:

    String errorMessage;
};


MOCKPP_NS_END


#endif // MOCKPP_TESTFAILUREMATCHER_H

