<?php

namespace user_management_protocol;


// includes
require_once __DIR__.'/../generic_protocol/html_helper.php';
require_once __DIR__.'/../basic_objects/html_helper.php';
require_once __DIR__.'/../basic_parser/html_helper.php';
require_once 'str_helper.php';

// enums

function to_html_header__gender_e( $r )
{
    return array( 'GENDER_E' );
}

function to_html__gender_e( $r )
{
    return to_string__gender_e( $r ) . " (" . $r . ")";
}

// objects

function to_html__UserInfo( & $r )
{
    $header = array( 'GENDER', 'LAST_NAME', 'FIRST_NAME', 'COMPANY_NAME', 'EMAIL', 'EMAIL_2', 'PHONE', 'PHONE_2', 'TIMEZONE' );

    $data = array(
        to_html__gender_e( $r->gender ),
        \basic_parser\to_html__string( $r->last_name ),
        \basic_parser\to_html__string( $r->first_name ),
        \basic_parser\to_html__string( $r->company_name ),
        \basic_parser\to_html__string( $r->email ),
        \basic_parser\to_html__string( $r->email_2 ),
        \basic_parser\to_html__string( $r->phone ),
        \basic_parser\to_html__string( $r->phone_2 ),
        \basic_parser\to_html__string( $r->timezone )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// base messages

function to_html__Request( & $r )
{
    $header = array(  );

    $data = array(        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__BackwardMessage( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// messages

function to_html__SetUserInfoRequest( & $r )
{
    $header = array( 'Request', 'USER_ID', 'USER_INFO' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        to_html__UserInfo( $r->user_info )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__SetUserInfoResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetUserInfoRequest( & $r )
{
    $header = array( 'Request', 'USER_ID' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__int( $r->user_id )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__GetUserInfoResponse( & $r )
{
    $header = array( 'BackwardMessage', 'USER_ID', 'GENDER', 'LAST_NAME', 'FIRST_NAME', 'COMPANY_NAME', 'EMAIL', 'EMAIL_2', 'PHONE', 'PHONE_2', 'TIMEZONE' );

    $data = array(
        to_html__BackwardMessage( $r ),
        \basic_parser\to_html__int( $r->user_id ),
        to_html__gender_e( $r->gender ),
        \basic_parser\to_html__string( $r->last_name ),
        \basic_parser\to_html__string( $r->first_name ),
        \basic_parser\to_html__string( $r->company_name ),
        \basic_parser\to_html__string( $r->email ),
        \basic_parser\to_html__string( $r->email_2 ),
        \basic_parser\to_html__string( $r->phone ),
        \basic_parser\to_html__string( $r->phone_2 ),
        \basic_parser\to_html__string( $r->timezone )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// generic

function to_html( $obj )
{
    $handler_map = array(
        // objects
        'user_management_protocol\UserInfo'         => 'to_html__UserInfo',
        // messages
        'user_management_protocol\SetUserInfoRequest'         => 'to_html__SetUserInfoRequest',
        'user_management_protocol\SetUserInfoResponse'         => 'to_html__SetUserInfoResponse',
        'user_management_protocol\GetUserInfoRequest'         => 'to_html__GetUserInfoRequest',
        'user_management_protocol\GetUserInfoResponse'         => 'to_html__GetUserInfoResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_management_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_html( $obj );
}

# namespace_end user_management_protocol


?>
