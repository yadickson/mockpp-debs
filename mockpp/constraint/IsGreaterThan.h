/** @file
    @brief  Checks if the argument is greater

  $Id: IsGreaterThan.h 1491 2010-01-02 22:21:45Z ewald-arnold $

 ***************************************************************************/

/**************************************************************************

   begin                : Sat Aug 21 2004
   copyright            : (C) 2002-2010 by Ewald Arnold
   email                : mockpp at ewald-arnold dot de

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
    by the Free Software Foundation; either version 2 of the License,
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

#ifndef MOCKPP_ISGREATER_H
#define MOCKPP_ISGREATER_H

#include <mockpp/mockpp.h> // always first

#include <mockpp/constraint/Constraint.h>
#include <mockpp/compat/Formatter.h>


MOCKPP_NS_START


/** Is the value greater than another value?
  * @ingroup grp_constraint
  * @see mockpp::gt
  */
template <typename T>
class IsGreaterThan : public Constraint<T>
{
  public:

  /** Constructs the object
    * @param greater the value for the comparison
    */
    IsGreaterThan( const T&greater )
      : greaterLimit(greater)
    {
    }

  /** Evaluates the constraint
    * @param arg the object against which the constraint is evaluated.
    * @return true:  arg meets the constraint,
    * @return false if it does not.
    */
    virtual bool eval( const T &arg ) const
    {
      return greaterLimit < arg;
    }

  /** Appends the description of this object to the buffer.
    * @param buffer The buffer that the description is appended to.
    * @return The current content of the buffer data
    */
    virtual String describeTo( String &buffer ) const
    {
       String fmt = MOCKPP_PCHAR("greaterThan %1");
       fmt << greaterLimit;
       buffer += fmt;
       return buffer;
    }

  private:

    const T greaterLimit;
};


MOCKPP_NS_END


#endif // MOCKPP_ISGREATER_H
