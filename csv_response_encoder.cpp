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

// $Revision: 12288 $ $Date::2019-03-13 #$ $Author: serge $

#include "csv_response_encoder.h"       // self

#include <typeinfo>                     // typeid

#include "utils/nonascii_hex_codec.h"   // nonascii_hex_codec
#include "utils/csv_helper.h"           // CsvHelper

#include "generic_protocol/csv_helper.h"     // generic_protocol::CsvHelper::to_csv()

#include "str_helper.h"

#define MODULENAME      "user_management_protocol::CsvResponseEncoder"

namespace user_management_protocol {

std::string CsvResponseEncoder::to_csv( const generic_protocol::BackwardMessage & r )
{
    if( typeid( r ) == typeid( SetPersonalUserInfoResponse ) )
    {
        return to_csv( static_cast<const SetPersonalUserInfoResponse&>( r ) );
    }
    else if( typeid( r ) == typeid( GetPersonalUserInfoResponse ) )
    {
        return to_csv( static_cast<const GetPersonalUserInfoResponse&>( r ) );
    }
    else
    {
        return generic_protocol::CsvHelper::to_csv( r );
    }
}

std::string CsvResponseEncoder::to_csv( const SetPersonalUserInfoResponse & r )
{
    return utils::CsvHelper::to_csv(
            "user_management/SetPersonalUserInfoResponse" );
}

std::string CsvResponseEncoder::to_csv( const GetPersonalUserInfoResponse & r )
{
    return utils::CsvHelper::to_csv(
            "user_management/GetPersonalUserInfoResponse",
            r.user_id,
            static_cast<uint32_t>( r.gender ),
            utils::nonascii_hex_codec::encode( r.last_name ),
            utils::nonascii_hex_codec::encode( r.first_name ),
            utils::nonascii_hex_codec::encode( r.company_name ),
            utils::nonascii_hex_codec::encode( r.email ),
            utils::nonascii_hex_codec::encode( r.email_2 ),
            utils::nonascii_hex_codec::encode( r.phone ),
            utils::nonascii_hex_codec::encode( r.phone_2 ),
            utils::nonascii_hex_codec::encode( r.timezone ) );
}

} // namespace user_management_protocol
