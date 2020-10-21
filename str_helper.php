<?php

namespace user_management_protocol;


// base include
require_once __DIR__.'/../generic_protocol/str_helper.php';
// includes
require_once __DIR__.'/../basic_objects/str_helper.php';
require_once __DIR__.'/../basic_parser/str_helper.php';

// enums

function to_string__gender_e( $r )
{
    $map = array
    (
        gender_e__UNDEF => 'UNDEF',
        gender_e__MALE => 'MALE',
        gender_e__FEMALE => 'FEMALE',
    );

    if( array_key_exists( $r, $map ) )
    {
        return $map[ $r ];
    }

    return '?';
}

// objects

function to_string__UserInfo( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " gender=" . to_string__gender_e( $r->gender );
    $res .= " last_name=" . \basic_parser\to_string__string( $r->last_name );
    $res .= " first_name=" . \basic_parser\to_string__string( $r->first_name );
    $res .= " company_name=" . \basic_parser\to_string__string( $r->company_name );
    $res .= " email=" . \basic_parser\to_string__string( $r->email );
    $res .= " email_2=" . \basic_parser\to_string__string( $r->email_2 );
    $res .= " phone=" . \basic_parser\to_string__string( $r->phone );
    $res .= " phone_2=" . \basic_parser\to_string__string( $r->phone_2 );
    $res .= " timezone=" . \basic_parser\to_string__string( $r->timezone );

    $res .= ")";

    return $res;
}

// base messages

function to_string__Request( & $r )
{
    $res = "";

    $res .= "(";

    // no base class

    $res .= ")";

    return $res;
}

function to_string__BackwardMessage( & $r )
{
    $res = "";

    $res .= "(";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    $res .= ")";

    return $res;
}

// messages

function to_string__SetUserInfoRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " user_info=" . to_string__UserInfo( $r->user_info );

    return $res;
}

function to_string__SetUserInfoResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__GetUserInfoRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );

    return $res;
}

function to_string__GetUserInfoResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );

    $res .= " user_id=" . \basic_parser\to_string__int( $r->user_id );
    $res .= " gender=" . to_string__gender_e( $r->gender );
    $res .= " last_name=" . \basic_parser\to_string__string( $r->last_name );
    $res .= " first_name=" . \basic_parser\to_string__string( $r->first_name );
    $res .= " company_name=" . \basic_parser\to_string__string( $r->company_name );
    $res .= " email=" . \basic_parser\to_string__string( $r->email );
    $res .= " email_2=" . \basic_parser\to_string__string( $r->email_2 );
    $res .= " phone=" . \basic_parser\to_string__string( $r->phone );
    $res .= " phone_2=" . \basic_parser\to_string__string( $r->phone_2 );
    $res .= " timezone=" . \basic_parser\to_string__string( $r->timezone );

    return $res;
}

// generic

function to_string( $obj )
{
    $handler_map = array(
        // objects
        'user_management_protocol\UserInfo'         => 'to_string__UserInfo',
        // messages
        'user_management_protocol\SetUserInfoRequest'         => 'to_string__SetUserInfoRequest',
        'user_management_protocol\SetUserInfoResponse'         => 'to_string__SetUserInfoResponse',
        'user_management_protocol\GetUserInfoRequest'         => 'to_string__GetUserInfoRequest',
        'user_management_protocol\GetUserInfoResponse'         => 'to_string__GetUserInfoResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_management_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_string( $obj );
}

// namespace_end user_management_protocol


?>
