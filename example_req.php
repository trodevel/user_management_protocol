<?php

// $Revision: 12293 $ $Date::2019-05-08 #$ $Author: serge $

require_once 'user_management_protocol.php';
require_once 'response_parser.php';

echo "OK\n";

$session_id = "afafaf";

{
    $user_id = 2074824509;

    $user_info = new \user_management_protocol\UserInfo(
        \user_management_protocol\gender_e_MALE,
        "Doe",
        "John",
        "Yoyodine, Inc.",
        "john.doe@yoyodine.com",
        "",
        "+49123456789",
        "",
        "Europe/Berlin"
        );

    $req = new \user_management_protocol\SetUserInfoRequest( $session_id, $user_id, $user_info );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $req = new \user_management_protocol\GetUserInfoRequest( $session_id, 2074824509 );

    echo "req = " . $req->to_generic_request() . "\n";
}
?>
