/*

Request Validator.

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

// $Revision: 12293 $ $Date::2019-05-03 #$ $Author: serge $


#include "request_validator.h"      // self

#include "request_parser.h"         // MalformedRequest

#include "generic_protocol/request_validator.h" // generic_protocol::RequestValidator::validate
#include "basic_objects/validator.h"            // basic_objects::Validator::validate

namespace user_management_protocol {

bool RequestValidator::validate( const UserInfo & r )
{
    return true;
}

bool RequestValidator::validate( const SetUserInfoRequest & r )
{
    if( r.user_id == 0 )
        throw RequestParser::MalformedRequest( "USER_ID is 0" );

    return generic_protocol::RequestValidator::validate( r );
}

bool RequestValidator::validate( const GetUserInfoRequest & r )
{
    if( r.user_id == 0 )
        throw RequestParser::MalformedRequest( "USER_ID is 0" );

    return generic_protocol::RequestValidator::validate( r );
}

} // namespace user_management_protocol
