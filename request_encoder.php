<?php

namespace user_management_protocol;


// base include
require_once __DIR__.'/../generic_protocol/request_encoder.php';
// includes
require_once __DIR__.'/../basic_objects/request_encoder.php';
require_once __DIR__.'/../basic_parser/request_encoder.php';

// enums

function to_generic_request__gender_e( $prefix, $r )
{
    $res = \basic_parser\to_generic_request__int( $prefix, $r );

    return $res;
}

// objects

function to_generic_request__UserInfo( $prefix, & $r )
{
    $res = "";
    $res .= "&" . to_generic_request__gender_e( $prefix . ".GENDER", $r->gender );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".LAST_NAME", $r->last_name );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".FIRST_NAME", $r->first_name );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".COMPANY_NAME", $r->company_name );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".EMAIL", $r->email );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".EMAIL_2", $r->email_2 );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".PHONE", $r->phone );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".PHONE_2", $r->phone_2 );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".TIMEZONE", $r->timezone );

    return $res;
}

// base messages

function to_generic_request__Request( & $r )
{
    $res = "";
    // no base class

    return $res;
}

function to_generic_request__BackwardMessage( & $r )
{
    $res = "";
    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

// messages

function to_generic_request__SetUserInfoRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_management_protocol/SetUserInfoRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . to_generic_request__UserInfo( "USER_INFO", $r->user_info );

    return $res;
}

function to_generic_request__SetUserInfoResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_management_protocol/SetUserInfoResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__GetUserInfoRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_management_protocol/GetUserInfoRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );

    return $res;
}

function to_generic_request__GetUserInfoResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_management_protocol/GetUserInfoResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );

    $res .= "&" . \basic_parser\to_generic_request__int( "USER_ID", $r->user_id );
    $res .= "&" . to_generic_request__gender_e( "GENDER", $r->gender );
    $res .= "&" . \basic_parser\to_generic_request__string( "LAST_NAME", $r->last_name );
    $res .= "&" . \basic_parser\to_generic_request__string( "FIRST_NAME", $r->first_name );
    $res .= "&" . \basic_parser\to_generic_request__string( "COMPANY_NAME", $r->company_name );
    $res .= "&" . \basic_parser\to_generic_request__string( "EMAIL", $r->email );
    $res .= "&" . \basic_parser\to_generic_request__string( "EMAIL_2", $r->email_2 );
    $res .= "&" . \basic_parser\to_generic_request__string( "PHONE", $r->phone );
    $res .= "&" . \basic_parser\to_generic_request__string( "PHONE_2", $r->phone_2 );
    $res .= "&" . \basic_parser\to_generic_request__string( "TIMEZONE", $r->timezone );

    return $res;
}

// generic

function to_generic_request( $obj )
{
    $handler_map = array(
        // messages
        'user_management_protocol\SetUserInfoRequest'         => 'to_generic_request__SetUserInfoRequest',
        'user_management_protocol\SetUserInfoResponse'         => 'to_generic_request__SetUserInfoResponse',
        'user_management_protocol\GetUserInfoRequest'         => 'to_generic_request__GetUserInfoRequest',
        'user_management_protocol\GetUserInfoResponse'         => 'to_generic_request__GetUserInfoResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_management_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_generic_request( $obj );
}

// namespace_end user_management_protocol


?>
