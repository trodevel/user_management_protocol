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

// $Revision: 12234 $ $Date::2019-05-08 #$ $Author: serge $

namespace user_management_protocol;

require_once __DIR__.'/../php_snippets/convert_csv_to_array.php';   // convert_csv_to_array()
require_once __DIR__.'/../generic_protocol/response_parser.php';    // generic_protocol\create_parse_error()
require_once __DIR__.'/../basic_parser/parser.php';                 // \basic_parser\parse_VectorInt
require_once 'user_management_protocol.php';


function parse_GetPersonalUserInfoResponse( & $csv_arr )
{
    // user_management/GetPersonalUserInfoResponse;123;1;Doe;John;Yoyodine=20Corp.;john.doe@yoyodine.com;=;+491234567890;=;Europe/Berlin;

    $offset = 1;

    $res = new GetPersonalUserInfoResponse;

    $res->user_id      = \basic_parser\parse_int( $csv_arr, $offset );
    $res->gender       = \basic_parser\parse_int( $csv_arr, $offset );
    $res->last_name    = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->first_name   = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->company_name = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->email        = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->email_2      = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->phone        = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->phone_2      = \basic_parser\parse_enc_string( $csv_arr, $offset );
    $res->timezone     = \basic_parser\parse_enc_string( $csv_arr, $offset );

    return $res;
}

class ResponseParser extends \generic_protocol\ResponseParser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $type = $csv_arr[0][0];

    $func_map = array(
        'user_management/GetPersonalUserInfoResponse'   => 'parse_GetPersonalUserInfoResponse',
        );

    if( array_key_exists( $type, $func_map ) )
    {
        $func = '\\user_management_protocol\\' . $func_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \generic_protocol\ResponseParser::parse_csv_array( $csv_arr );
}

}

?>
