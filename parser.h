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

// $Revision: 12210 $ $Date::2019-03-31 #$ $Author: serge $

#ifndef LIB_USER_MANAGEMENT_PROTOCOL_PARSER_H
#define LIB_USER_MANAGEMENT_PROTOCOL_PARSER_H

#include "enums.h"              // request_type_e

#include "user_management_protocol.h"    // SayFeedbackRequest

namespace user_management_protocol {

class Parser
{
public:

    static SayFeedbackRequest::action_type_e to_sfr_action_type( const std::string & s );
    static gender_e    to_gender( const std::string & s );
    static request_type_e   to_request_type( const std::string & s );
    static voice_e          to_voice( const std::string & s );
    static urgency_e        to_urgency( const std::string & s );
};

} // namespace user_management_protocol

#endif // LIB_USER_MANAGEMENT_PROTOCOL_PARSER_H
