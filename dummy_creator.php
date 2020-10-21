<?php

namespace user_management_protocol;


// base include
require_once __DIR__.'/../generic_protocol/dummy_creator.php';
// includes
require_once __DIR__.'/../basic_parser/dummy_creator.php';
require_once __DIR__.'/../basic_objects/dummy_creator.php';

// own includes
require_once __DIR__.'/../user_management_protocol/object_initializer.php';

// enums

function create_dummy__gender_e()
{
    $SIZE = 3;

    $values = array( gender_e__UNDEF, gender_e__MALE, gender_e__FEMALE,  );

    $res = $values[ \basic_parser\create_dummy__int32() % $SIZE ];

    return $res;
}

// objects

function create_dummy__UserInfo()
{
    $res = new UserInfo;

    initialize__UserInfo( $res
        , create_dummy__gender_e()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

// messages

function create_dummy__SetUserInfoRequest()
{
    $res = new SetUserInfoRequest;

    initialize__SetUserInfoRequest( $res
        , \basic_parser\create_dummy__int32()
        , create_dummy__UserInfo()
        );
    return $res;
}

function create_dummy__SetUserInfoResponse()
{
    $res = new SetUserInfoResponse;

    initialize__SetUserInfoResponse( $res
        );
    return $res;
}

function create_dummy__GetUserInfoRequest()
{
    $res = new GetUserInfoRequest;

    initialize__GetUserInfoRequest( $res
        , \basic_parser\create_dummy__int32()
        );
    return $res;
}

function create_dummy__GetUserInfoResponse()
{
    $res = new GetUserInfoResponse;

    initialize__GetUserInfoResponse( $res
        , \basic_parser\create_dummy__int32()
        , create_dummy__gender_e()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

// namespace_end user_management_protocol


?>
