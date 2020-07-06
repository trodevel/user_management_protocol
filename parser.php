<?php

namespace user_management_protocol;


// includes
require_once __DIR__.'/../basic_objects/parser.php';
require_once __DIR__.'/../basic_parser/parser.php';

// enums

function parse__gender_e( & $csv_arr, & $offset )
{
    $res = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

// objects

function parse__UserInfo( & $csv_arr, & $offset )
{
    $res = new UserInfo;

    $res->gender = parse__gender_e( $csv_arr, $offset );
    $res->last_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->first_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->company_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->email = \basic_parser\parse__string( $csv_arr, $offset );
    $res->email_2 = \basic_parser\parse__string( $csv_arr, $offset );
    $res->phone = \basic_parser\parse__string( $csv_arr, $offset );
    $res->phone_2 = \basic_parser\parse__string( $csv_arr, $offset );
    $res->timezone = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

// base messages

function parse__Request( & $res, & $csv_arr, & $offset )
{

}

function parse__BackwardMessage( & $res, & $csv_arr, & $offset )
{

}

// messages

function parse__SetUserInfoRequest( & $csv_arr )
{
    $res = new SetUserInfoRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->user_info = parse__UserInfo( $csv_arr, $offset );

    return $res;
}

function parse__SetUserInfoResponse( & $csv_arr )
{
    $res = new SetUserInfoResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__GetUserInfoRequest( & $csv_arr )
{
    $res = new GetUserInfoRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );

    return $res;
}

function parse__GetUserInfoResponse( & $csv_arr )
{
    $res = new GetUserInfoResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );

    $res->user_id = \basic_parser\parse__int( $csv_arr, $offset );
    $res->gender = parse__gender_e( $csv_arr, $offset );
    $res->last_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->first_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->company_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->email = \basic_parser\parse__string( $csv_arr, $offset );
    $res->email_2 = \basic_parser\parse__string( $csv_arr, $offset );
    $res->phone = \basic_parser\parse__string( $csv_arr, $offset );
    $res->phone_2 = \basic_parser\parse__string( $csv_arr, $offset );
    $res->timezone = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

// generic

class Parser extends \basic_parser\Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $handler_map = array(
        // messages
        'user_management/SetUserInfoRequest'         => 'parse__SetUserInfoRequest',
        'user_management/SetUserInfoResponse'         => 'parse__SetUserInfoResponse',
        'user_management/GetUserInfoRequest'         => 'parse__GetUserInfoRequest',
        'user_management/GetUserInfoResponse'         => 'parse__GetUserInfoResponse',
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_management_protocol\\' . $handler_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return NULL;
}

}

# namespace_end user_management_protocol


?>
