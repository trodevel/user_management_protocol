<?php

// $Revision: 12288 $ $Date:: 2019-10-30 #$ $Author: serge $

require_once '../user_management_protocol.php';
require_once '../response_parser.php';
require_once '../html_helper.php';

{
    $resp  =
    'user_management/GetPersonalUserInfoResponse;123;1;Doe;John;Yoyodine=20Corp.;john.doe@yoyodine.com;=;+491234567890;=;Europe/Berlin;';

    $parsed = \user_management_protocol\ResponseParser::parse( $resp );

    echo "parsed: " . \user_management_protocol\to_html( $parsed ) . "\n";
}

?>
