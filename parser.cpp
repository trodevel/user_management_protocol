/*

Parser.

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

// $Revision: 12293 $ $Date::2019-11-10 #$ $Author: serge $

#include "parser.h"                 // self

#include <map>
#include <stdexcept>                // std::invalid_argument

namespace user_management_protocol {

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_
#define TUPLE_VAL_STR_PREF(_x_,_p_)  _x_,_p_+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

gender_e Parser::to_gender( const std::string & s )
{
    typedef gender_e Type;
    typedef std::map< std::string, Type > Map;
    static const Map m =
    {
        make_inverse_pair( Type:: TUPLE_VAL_STR( UNDEF ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( MALE ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( FEMALE ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        throw std::invalid_argument( ( "to_gender: cannot parse " + s ).c_str() );

    return it->second;
}

request_type_e Parser::to_request_type( const std::string & s )
{
    typedef std::map< std::string, request_type_e > Map;
    static const Map m =
    {
        make_inverse_pair( request_type_e:: TUPLE_VAL_STR_PREF( SetUserInfoRequest, "user_management/" ) ),
        make_inverse_pair( request_type_e:: TUPLE_VAL_STR_PREF( GetUserInfoRequest, "user_management/" ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}

} // namespace user_management_protocol
