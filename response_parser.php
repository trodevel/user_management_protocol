<?php

/*

Response Parser.

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

// $Revision: 12210 $ $Date::2019-05-08 #$ $Author: serge $

namespace user_management_protocol;

require_once __DIR__.'/../php_snippets/convert_csv_to_array.php';   // convert_csv_to_array()
require_once __DIR__.'/../php_snippets/nonascii_hex_codec.php';     // \utils\nonascii_hex_codec\decode()
require_once __DIR__.'/../generic_protocol/response_parser.php';    // generic_protocol\create_parse_error()
require_once __DIR__.'/../basic_objects/parser.php';                // \basic_objects\parse_TimePoint24
require_once __DIR__.'/../basic_parser/parser.php';                 // \basic_parser\parse_VectorInt
require_once 'user_management_protocol.php';


function parse_GetPersonalUserInfoResponse( & $resp )
{
    // GetPersonalUserInfoResponse;123;1;Doe;John;Yoyodine Corp.;john.doe@yoyodine.com;;+491234567890;;Europe/Berlin;

    $res = new GetPersonalUserInfoResponse;

    $res->user_id      = intval( $resp[1] );
    $res->gender       = intval( $resp[2] );
    $res->name         = $resp[3];
    $res->first_name   = $resp[4];
    $res->company_name = $resp[5];
    $res->email        = $resp[6];
    $res->email_2      = $resp[7];
    $res->phone        = $resp[8];
    $res->phone_2      = $resp[9];
    $res->timezone     = $resp[10];

    return $res;
}


class ResponseParser extends \generic_protocol\ResponseParser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $type = $csv_arr[0][0];

    $func_map_2 = array(
        'GetPersonalUserInfoResponse'   => 'parse_GetPersonalUserInfoResponse',
        );

    if( array_key_exists( $type, $func_map_2 ) )
    {
        $func = '\\user_management_protocol\\' . $func_map_2[ $type ];
        return $func( $csv_arr[0] );
    }

    return \generic_protocol\ResponseParser::parse_csv_array( $csv_arr );
}
}

?>
