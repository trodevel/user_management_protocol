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

// $Revision: 12288 $ $Date::2019-05-08 #$ $Author: serge $

#include "generic_request/request.h"        // generic_request::Request
#include "basic_parser/malformed_request.h" // MalformedRequest
#include "enums.h"                          // request_type_e
#include "user_management_protocol.h"       // Request...

namespace user_management_protocol {

class RequestParser
{
public:
    typedef basic_parser::MalformedRequest      MalformedRequest;
    typedef generic_protocol::ForwardMessage    ForwardMessage;

public:

    static generic_protocol::ForwardMessage*    to_forward_message( const generic_request::Request & r );

private:

    static request_type_e   detect_request_type( const generic_request::Request & r );

    static ForwardMessage *             to_SetPersonalUserInfoRequest( const generic_request::Request & r );
    static ForwardMessage *             to_GetPersonalUserInfoRequest( const generic_request::Request & r );

    static void                         to_UserInfo( UserInfo * res, const generic_request::Request & r );
};

} // namespace user_management_protocol

