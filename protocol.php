<?php

namespace user_management_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';
require_once __DIR__.'/../generic_protocol/protocol.php';

// includes for used modules
require_once __DIR__.'/../basic_objects/protocol.php';

// Enum gender_e
const gender_e__UNDEF                = 0;
const gender_e__MALE                 = 1;
const gender_e__FEMALE               = 2;

// Object
class UserInfo
{
    public $gender              ; // type: gender_e
    public $last_name           ; // type: string
    public $first_name          ; // type: string
    public $company_name        ; // type: string
    public $email               ; // type: string
    public $email_2             ; // type: string
    public $phone               ; // type: string
    public $phone_2             ; // type: string
    public $timezone            ; // type: string
};

// Base message
class Request extends \basic_parser\Object
{
    function __construct()
    {
    }
};

// Base message
class BackwardMessage extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }
};

// Message
class SetUserInfoRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2229419794;

    public $user_id             ; // type: uint32_t
    public $user_info           ; // type: UserInfo
};

// Message
class SetUserInfoResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2915926486;
};

// Message
class GetUserInfoRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2716447756;

    public $user_id             ; // type: uint32_t
};

// Message
class GetUserInfoResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 1474803518;

    public $user_id             ; // type: uint32_t
    public $gender              ; // type: gender_e
    public $last_name           ; // type: string
    public $first_name          ; // type: string
    public $company_name        ; // type: string
    public $email               ; // type: string
    public $email_2             ; // type: string
    public $phone               ; // type: string
    public $phone_2             ; // type: string
    public $timezone            ; // type: string
};

// namespace_end user_management_protocol


?>

