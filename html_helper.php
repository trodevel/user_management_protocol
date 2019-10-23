<?php

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

// $Revision: 12233 $ $Date::2019-05-08 #$ $Author: serge $

namespace user_management_protocol;

require_once 'user_management_protocol.php';
require_once __DIR__.'/../generic_protocol/str_helper.php';
require_once __DIR__.'/../basic_objects/str_helper.php';        // to_string_TimeWindow
require_once __DIR__.'/../php_snippets/epoch_to_date.php';      // epoch_to_date

function to_html_not_impl( & $obj )
{
    return get_html_table_header_elems( array( 'not implemented yet' ) );
}

/**************************************************
 * OBJECTS
 **************************************************/


/**************************************************
 * RESPONSES
 **************************************************/

function to_html_GetPersonalUserInfoResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
            get_html_table_row_header( array( 'USER_ID', 'GENDER', 'LAST NAME', 'FIRST_NAME',
                    'COMPANY', 'EMAIL', 'EMAIL_2', 'PHONE', 'PHONE_2', 'TIMEZONE' ) ) .
            get_html_table_row_data( array( $obj->user_id, $obj->gender, $obj->last_name, $obj->first_name, $obj->company_name,
                    $obj->email, $obj->email_2, $obj->phone, $obj->phone_2, $obj->timezone ) ) );
}
// *********************************************************

function to_html( $obj )
{
    $handler_map = array(
        'user_management_protocol\GetPersonalUserInfoResponse'   => 'to_html_GetPersonalUserInfoResponse',
    );

    $type = get_class ( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_management_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_html( $obj );
}

?>
