/*

Core enums.

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

// $Revision: 12276 $ $Date::2019-11-10 #$ $Author: serge $

#ifndef USER_MANAGEMENT_PROTOCOL_ENUMS_H
#define USER_MANAGEMENT_PROTOCOL_ENUMS_H

namespace user_management_protocol {

enum class request_type_e
{
    UNDEF,
    SetPersonalUserInfoRequest,
    GetPersonalUserInfoRequest,
};

} // namespace user_management_protocol

#endif // USER_MANAGEMENT_PROTOCOL_ENUMS_H
