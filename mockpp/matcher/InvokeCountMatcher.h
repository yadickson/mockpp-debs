/** @file
    @brief  Matches a defined invocation count

  $Id: InvokeCountMatcher.h 1491 2010-01-02 22:21:45Z ewald-arnold $

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

#ifndef MOCKPP_INVOKECOUNTMATCHER_H
#define MOCKPP_INVOKECOUNTMATCHER_H

#include <mockpp/mockpp.h> // always first

#include <mockpp/matcher/InvokedRecorder.h>


MOCKPP_NS_START


/** Has the object been invoked a given number?
  * @ingroup grp_matcher
  * @see mockpp::exactly
  */
class MOCKPP_API_DECL0 InvokeCountMatcher : public InvokedRecorder
{
  public:

  /** Creates the object
    * @param count  the required invocation count
    */
    InvokeCountMatcher( int count );

  /** Destroys the object
    */
    virtual ~InvokeCountMatcher();

  /** Checks if an invocation matches the expectaton
    * @return true: the invocation matches
    */
    virtual bool matches( );

  /** Verify that the expected value is within the allowed bounds.
    * If it fails, an AssertionFailedError is thrown
    */
    virtual void verify();

  /** Does the object provide meaningful description via describeTo() ?.
    * @return true: description is available
    */
    virtual bool hasDescription();

  /** Appends the description of this object to the buffer.
    * @param buffer The buffer that the description is appended to.
    * @return The current content of the buffer data
    */
    virtual String describeTo( String &buffer ) const;

  private:

    int expectedCount;
};


MOCKPP_NS_END


#endif // MOCKPP_INVOKECOUNTMATCHER_H

