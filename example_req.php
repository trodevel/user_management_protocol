<?php

// $Revision: 12222 $ $Date::2019-05-08 #$ $Author: serge $

require_once 'user_management_protocol.php';
require_once 'response_parser.php';

echo "OK\n";

$session_id = "afafaf";

{
    $req = new \user_management_protocol\GetPersonalUserInfoRequest( $session_id, 2074824509 );

    echo "req = " . $req->to_generic_request() . "\n";
}

?>
