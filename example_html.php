<?php

namespace user_management_protocol;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'html_helper.php';

# objects

function example_UserInfo()
{
    $obj = \user_management_protocol\create_dummy__UserInfo();

    echo "UserInfo : HTML : " . \user_management_protocol\to_html( $obj ) . "<br>\n";
}


# messages

function example_SetUserInfoRequest()
{
    $obj = \user_management_protocol\create_dummy__SetUserInfoRequest();

    echo "SetUserInfoRequest : HTML : " . \user_management_protocol\to_html( $obj ) . "<br>\n";
}

function example_SetUserInfoResponse()
{
    $obj = \user_management_protocol\create_dummy__SetUserInfoResponse();

    echo "SetUserInfoResponse : HTML : " . \user_management_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetUserInfoRequest()
{
    $obj = \user_management_protocol\create_dummy__GetUserInfoRequest();

    echo "GetUserInfoRequest : HTML : " . \user_management_protocol\to_html( $obj ) . "<br>\n";
}

function example_GetUserInfoResponse()
{
    $obj = \user_management_protocol\create_dummy__GetUserInfoResponse();

    echo "GetUserInfoResponse : HTML : " . \user_management_protocol\to_html( $obj ) . "<br>\n";
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

# namespace_end user_management_protocol


?>
