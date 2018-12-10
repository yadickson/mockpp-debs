/** @file
    @internal
    @brief  A set of argument constrains

 $Id: ConstraintSet.cpp 1491 2010-01-02 22:21:45Z ewald-arnold $

***************************************************************************/

/**************************************************************************

   begin                : Sat Aug 21 2004
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

#define MOCKPP_NEED_EXPORTS
#include <mockpp/mockpp.h> // always first

#include <mockpp/constraint/ConstraintSet.h>


MOCKPP_NS_START


MOCKPP_API_IMPL(String) ConstraintSet0::describeTo( String &buffer ) const
{
  return buffer;
}


MOCKPP_API_IMPL0 ConstraintSet0::~ConstraintSet0()
{
}


MOCKPP_NS_END

