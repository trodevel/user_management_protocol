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

#include "user_management_protocol.h"    // Request...

namespace user_management_protocol {

class RequestValidator
{
public:
    static bool validate( const UserInfo & r );
    static bool validate( const SetUserInfoRequest & r );
    static bool validate( const GetUserInfoRequest & r );
};

} // namespace user_management_protocol

