/** @file
    @brief    Time dependent objects

  $Id: TimeServer.cpp 1501 2010-01-03 18:04:32Z ewald-arnold $

 **************************************************************************/

/**************************************************************************

   begin                : Sat Apr 30 2005
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

#include <mockpp/production/TimeServer.h>


MOCKPP_NS_START


MOCKPP_API_IMPL(MOCKPP_STD_NS::time_t) RealTimeServer::getUnixTime()
{
   return MOCKPP_STD_NS::time(NULL);
}


MOCKPP_NS_END












