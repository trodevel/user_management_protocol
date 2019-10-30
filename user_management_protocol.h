/*

User Management Protocol messages.

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

// $Revision: 12293 $ $Date::2019-05-15 #$ $Author: serge $

#ifndef LIB_USER_MANAGEMENT_PROTOCOL_USER_MANAGEMENT_PROTOCOL_H
#define LIB_USER_MANAGEMENT_PROTOCOL_USER_MANAGEMENT_PROTOCOL_H

#include <stdint.h>             // uint32_t

#include "generic_protocol/generic_protocol.h"   // generic_protocol::Request

namespace user_management_protocol {

struct Request: public generic_protocol::Request
{
    virtual ~Request() {};
};

enum class gender_e
{
    UNDEF   = 0,
    MALE    = 1,
    FEMALE  = 2,
};

struct UserInfo: public Request
{
    gender_e        gender;
    std::string     last_name;
    std::string     first_name;
    std::string     company_name;
    std::string     email;
    std::string     email_2;
    std::string     phone;
    std::string     phone_2;
    std::string     timezone;
};

struct SetUserInfoRequest: public Request
{
    uint32_t        user_id;
    UserInfo        user_info;
};

struct SetUserInfoResponse: public generic_protocol::BackwardMessage
{
};

struct GetUserInfoRequest: public Request
{
    uint32_t        user_id;
};

struct GetUserInfoResponse: public generic_protocol::BackwardMessage
{
    uint32_t        user_id;
    gender_e        gender;
    std::string     last_name;
    std::string     first_name;
    std::string     company_name;
    std::string     email;
    std::string     email_2;
    std::string     phone;
    std::string     phone_2;
    std::string     timezone;
};

} // namespace user_management_protocol

#endif // LIB_USER_MANAGEMENT_PROTOCOL_USER_MANAGEMENT_PROTOCOL_H
