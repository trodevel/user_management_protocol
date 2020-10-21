<?php

namespace user_management_protocol;


// own includes
require_once __DIR__.'/../user_management_protocol/protocol.php';
require_once __DIR__.'/../user_management_protocol/dummy_creator.php';
require_once __DIR__.'/../user_management_protocol/str_helper.php';
require_once __DIR__.'/../user_management_protocol/request_encoder.php';

# objects

function example_UserInfo()
{
    $obj = \user_management_protocol\create_dummy__UserInfo();

    echo "UserInfo : STR : " . \user_management_protocol\to_string( $obj ) . "\n";
}


# messages

function example_SetUserInfoRequest()
{
    $obj = \user_management_protocol\create_dummy__SetUserInfoRequest();

    echo "SetUserInfoRequest : STR : " . \user_management_protocol\to_string( $obj ) . "\n";

    echo "SetUserInfoRequest : REQ : " . \user_management_protocol\to_generic_request( $obj ) . "\n";

}

function example_SetUserInfoResponse()
{
    $obj = \user_management_protocol\create_dummy__SetUserInfoResponse();

    echo "SetUserInfoResponse : STR : " . \user_management_protocol\to_string( $obj ) . "\n";

    echo "SetUserInfoResponse : REQ : " . \user_management_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetUserInfoRequest()
{
    $obj = \user_management_protocol\create_dummy__GetUserInfoRequest();

    echo "GetUserInfoRequest : STR : " . \user_management_protocol\to_string( $obj ) . "\n";

    echo "GetUserInfoRequest : REQ : " . \user_management_protocol\to_generic_request( $obj ) . "\n";

}

function example_GetUserInfoResponse()
{
    $obj = \user_management_protocol\create_dummy__GetUserInfoResponse();

    echo "GetUserInfoResponse : STR : " . \user_management_protocol\to_string( $obj ) . "\n";

    echo "GetUserInfoResponse : REQ : " . \user_management_protocol\to_generic_request( $obj ) . "\n";

}


{
    // objects

    example_UserInfo();

    // messages

    example_SetUserInfoRequest();
    example_SetUserInfoResponse();
    example_GetUserInfoRequest();
    example_GetUserInfoResponse();

}

// namespace_end user_management_protocol


?>
