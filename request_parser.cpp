/*

Request Parser.

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

// $Revision: 12213 $ $Date::2019-05-03 #$ $Author: serge $

#include "request_parser.h"         // self

#include "basic_parser/get_value.h" // basic_parser::get_value_or_throw
#include "basic_objects/parser.h"   // basic_objects::Parser

#include "parser.h"                 // Parser
#include "generic_protocol/request_parser.h" // generic_protocol::RequestParser::to_request()
#include "request_validator.h"      // RequestValidator

namespace user_management_protocol {

using basic_parser::get_value_or_throw;
using basic_parser::get_value_or_throw_uint32;

generic_protocol::ForwardMessage* RequestParser::to_forward_message( const generic_request::Request & r )
{
    auto type = RequestParser::detect_request_type( r );

    typedef request_type_e KeyType;
    typedef RequestParser Type;

    typedef ForwardMessage* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & Type::to_##_v }

    static const std::map<KeyType, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( GetPersonalUserInfoRequest ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return nullptr;
}

request_type_e  RequestParser::detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return Parser::to_request_type( cmd );
}

RequestParser::ForwardMessage * RequestParser::to_GetPersonalUserInfoRequest( const generic_request::Request & r )
{
    auto * res = new GetPersonalUserInfoRequest;

    get_value_or_throw_uint32( res->user_id,       "USER_ID", r );

    generic_protocol::RequestParser::to_request( res, r );

    RequestValidator::validate( * res );

    return res;
}

} // namespace user_management_protocol
