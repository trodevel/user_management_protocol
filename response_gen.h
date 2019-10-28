/*

Protocol response generator.

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

// $Revision: 12277 $ $Date::2019-05-08 #$ $Author: serge $

#ifndef LIB_USER_MANAGEMENT_PROTOCOL_RESPONSE_GEN_H
#define LIB_USER_MANAGEMENT_PROTOCOL_RESPONSE_GEN_H

#include "user_management_protocol.h"        // GetPersonalUserInfoResponse

namespace user_management_protocol {

inline SetPersonalUserInfoResponse * create_SetPersonalUserInfoResponse()
{
    auto * res = new SetPersonalUserInfoResponse;

    return res;
}

inline GetPersonalUserInfoResponse * create_GetPersonalUserInfoResponse(
        uint32_t            user_id,
        gender_e            gender,
        const std::string   & name,
        const std::string   & first_name,
        const std::string   & company_name,
        const std::string   & email,
        const std::string   & email_2,
        const std::string   & phone,
        const std::string   & phone_2,
        const std::string   & timezone )
{
    auto * res = new GetPersonalUserInfoResponse;

    res->user_id    = user_id;
    res->gender     = gender;
    res->last_name       = name;
    res->first_name = first_name;
    res->company_name = company_name;
    res->email      = email;
    res->email_2    = email_2;
    res->phone      = phone;
    res->phone_2    = phone_2;
    res->timezone   = timezone;

    return res;
}

} // namespace user_management_protocol

#endif // LIB_USER_MANAGEMENT_PROTOCOL_RESPONSE_GEN_H
