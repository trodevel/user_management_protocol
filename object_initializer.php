<?php

namespace user_management_protocol;


// base include
require_once __DIR__.'/../generic_protocol/object_initializer.php';
// own includes
require_once __DIR__.'/../user_management_protocol/protocol.php';

// objects

function initialize__UserInfo( & $res
    , $gender // gender_e
    , $last_name // string
    , $first_name // string
    , $company_name // string
    , $email // string
    , $email_2 // string
    , $phone // string
    , $phone_2 // string
    , $timezone // string
 )
{
    $res->gender = $gender;
    $res->last_name = $last_name;
    $res->first_name = $first_name;
    $res->company_name = $company_name;
    $res->email = $email;
    $res->email_2 = $email_2;
    $res->phone = $phone;
    $res->phone_2 = $phone_2;
    $res->timezone = $timezone;
}

// base messages

function initialize__Request( & $res
 )
{
    // no base class
}

function initialize__BackwardMessage( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

// messages

function initialize__SetUserInfoRequest( & $res
    , $user_id // uint32_t
    , $user_info // UserInfo
 )
{
    // base class
    initialize__Request( $res );

    $res->user_id = $user_id;
    $res->user_info = $user_info;
}

function initialize__SetUserInfoResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__GetUserInfoRequest( & $res
    , $user_id // uint32_t
 )
{
    // base class
    initialize__Request( $res );

    $res->user_id = $user_id;
}

function initialize__GetUserInfoResponse( & $res
    , $user_id // uint32_t
    , $gender // gender_e
    , $last_name // string
    , $first_name // string
    , $company_name // string
    , $email // string
    , $email_2 // string
    , $phone // string
    , $phone_2 // string
    , $timezone // string
 )
{
    // base class
    initialize__BackwardMessage( $res );

    $res->user_id = $user_id;
    $res->gender = $gender;
    $res->last_name = $last_name;
    $res->first_name = $first_name;
    $res->company_name = $company_name;
    $res->email = $email;
    $res->email_2 = $email_2;
    $res->phone = $phone;
    $res->phone_2 = $phone_2;
    $res->timezone = $timezone;
}

// objects (constructors)

function create__UserInfo(
    $gender // gender_e
    , $last_name // string
    , $first_name // string
    , $company_name // string
    , $email // string
    , $email_2 // string
    , $phone // string
    , $phone_2 // string
    , $timezone // string
 )
{
    $res = new UserInfo;

    initialize__UserInfo( $res, $gender, $last_name, $first_name, $company_name, $email, $email_2, $phone, $phone_2, $timezone );

    return $res;
}

// messages (constructors)

function create__SetUserInfoRequest(
    $user_id // uint32_t
    , $user_info // UserInfo
 )
{
    $res = new SetUserInfoRequest;

    initialize__SetUserInfoRequest( $res, $user_id, $user_info );

    return $res;
}

function create__SetUserInfoResponse(
 )
{
    $res = new SetUserInfoResponse;

    initialize__SetUserInfoResponse( $res );

    return $res;
}

function create__GetUserInfoRequest(
    $user_id // uint32_t
 )
{
    $res = new GetUserInfoRequest;

    initialize__GetUserInfoRequest( $res, $user_id );

    return $res;
}

function create__GetUserInfoResponse(
    $user_id // uint32_t
    , $gender // gender_e
    , $last_name // string
    , $first_name // string
    , $company_name // string
    , $email // string
    , $email_2 // string
    , $phone // string
    , $phone_2 // string
    , $timezone // string
 )
{
    $res = new GetUserInfoResponse;

    initialize__GetUserInfoResponse( $res, $user_id, $gender, $last_name, $first_name, $company_name, $email, $email_2, $phone, $phone_2, $timezone );

    return $res;
}

// namespace_end user_management_protocol


?>
