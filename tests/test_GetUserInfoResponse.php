<?php

// $Revision: 13367 $ $Date:: 2020-07-06 #$ $Author: serge $

require_once '../protocol.php';
require_once '../parser.php';
require_once '../html_helper.php';

{
    $resp  =
    'user_management/GetUserInfoResponse;123;1;Doe;John;Yoyodine=20Corp.;john.doe@yoyodine.com;=;+491234567890;=;Europe/Berlin;';

    $parsed = \user_management_protocol\Parser::parse( $resp );

    if( $parsed )
    {
        echo "parsed: " . \user_management_protocol\to_html( $parsed ) . "\n";
    }
    else
    {
        echo "ERROR: cannot parse\n";
    }
}

?>
