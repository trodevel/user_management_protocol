/*

CSV response encoder.

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

// $Revision: 12293 $ $Date::2019-05-08 #$ $Author: serge $

#ifndef LIB_USER_MANAGEMENT_PROTOCOL_CSV_RESPONSE_ENCODER_H
#define LIB_USER_MANAGEMENT_PROTOCOL_CSV_RESPONSE_ENCODER_H

#include "user_management_protocol.h"        // GetUserInfoResponse, ...
#include <sstream>                  // std::ostream

namespace user_management_protocol {

class CsvResponseEncoder
{
public:
    static std::string to_csv( const generic_protocol::BackwardMessage & r );
    static std::string to_csv( const SetUserInfoResponse & r );
    static std::string to_csv( const GetUserInfoResponse & r );
};

} // namespace user_management_protocol

#endif // LIB_USER_MANAGEMENT_PROTOCOL_CSV_RESPONSE_ENCODER_H
