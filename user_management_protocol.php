<?php

/*

User Management Protocol messages.

Copyright (C) 2019 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 12288 $ $Date::2019-05-28 #$ $Author: serge $

namespace user_management_protocol;

require_once __DIR__.'/../generic_protocol/generic_protocol.php';

class Request extends \generic_protocol\Request
{
    function __construct( $session_id )
    {
        parent::__construct( $session_id );
    }
}

const gender_e_UNDEF   = 0;
const gender_e_MALE    = 1;
const gender_e_FEMALE  = 2;

class UserInfo
{
    public          $gender;            // gender, see gender_e_... constants
    public          $last_name;         // last_name
    public          $first_name;        // first name
    public          $company_name;      // company name
    public          $email;             // email
    public          $email_2;           // email 2
    public          $phone;             // phone
    public          $phone_2;           // phone 2
    public          $timezone;          // timezone

    function __construct( $gender, $last_name, $first_name, $company_name, $email, $email_2, $phone, $phone_2, $timezone )
    {
        $this->gender           = $gender;
        $this->last_name        = $last_name;
        $this->first_name       = $first_name;
        $this->company_name     = $company_name;
        $this->email            = $email;
        $this->email_2          = $email_2;
        $this->phone            = $phone;
        $this->phone_2          = $phone_2;
        $this->timezone         = $timezone;
    }

    public function to_generic_request()
    {
        $res = array(
            "GENDER"        => $this->gender,
            "LAST_NAME:X"   => str2hex( $this->last_name ),
            "FIRST_NAME:X"  => str2hex( $this->first_name ),
            "COMPANY_NAME:X"  => str2hex( $this->company_name ),
            "EMAIL:X"       => str2hex( $this->email ),
            "EMAIL_2:X"     => str2hex( $this->email_2 ),
            "PHONE:X"       => str2hex( $this->phone ),
            "PHONE_2:X"     => str2hex( $this->phone_2 ),
            "TIMEZONE:X"    => str2hex( $this->timezone ) );

        return \generic_protocol\assemble_request( $res );
    }
};

class SetPersonalUserInfoRequest extends Request
{
    public          $user_id;           // user ID
    public          $user_info;         // user_info, see UserInfo
    
    function __construct( $session_id, $user_id, $user_info )
    {
        parent::__construct( $session_id );
        
        $this->user_id          = $user_id;
        $this->user_info        = $user_info;
    }
    
    public function to_generic_request()
    {
        $res = array(
            "CMD"           => "user_management/SetPersonalUserInfoRequest",
            "USER_ID"       => $this->user_id );
        
        return \generic_protocol\assemble_request( $res ) .
            $this->user_info->to_generic_request() .
            parent::to_generic_request();
    }
};

class SetPersonalUserInfoResponse extends \generic_protocol\BackwardMessage
{
};

class GetPersonalUserInfoRequest extends Request
{
    public        $user_id;     // user ID

    function __construct( $session_id, $user_id )
    {
        parent::__construct( $session_id );

        $this->user_id      = $user_id;
    }

    public function to_generic_request()
    {
        $res = array(
                "CMD"           => "user_management/GetPersonalUserInfoRequest",
                "USER_ID"       => $this->user_id );

        return \generic_protocol\assemble_request( $res ) . parent::to_generic_request();
    }
};

class GetPersonalUserInfoResponse extends \generic_protocol\BackwardMessage
{
    public          $user_id;       // user ID
    public          $gender;        // gender, see gender_e_... constants
    public          $last_name;     // family name
    public          $first_name;    // first name
    public          $company_name;  // company name
    public          $email;         // email
    public          $email_2;       // alternative email
    public          $phone;         // phone number
    public          $phone_2;       // alternative phone number
    public          $timezone;      // user's timezone
};

?>
