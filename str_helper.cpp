/*

String Helper. Provides to_string() function.

Copyright (C) 2019 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 12210 $ $Date::2019-05-08 #$ $Author: serge $

#include "str_helper.h"             // self

#include <sstream>                  // std::ostringstream
#include <map>

namespace user_management_protocol {

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

const std::string & StrHelper::to_string( const gender_e s )
{
    typedef gender_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( MALE ) },
        { Type:: TUPLE_VAL_STR( FEMALE ) },
    };

    auto it = m.find( s );

    static const std::string undef( "undef" );

    if( it == m.end() )
        return undef;

    return it->second;
}

} // namespace user_management_protocol
