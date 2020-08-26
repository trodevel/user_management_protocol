// includes
#include "dummy_creator.h"
#include "generic_protocol/dummy_creator.h"
#include "basic_parser/dummy_creator.h"
#include "basic_objects/dummy_creator.h"
#include "object_initializer.h"

namespace user_management_protocol
{

namespace dummy
{

// enums

gender_e create__gender_e()
{
    static const unsigned SIZE = 3;

    static const gender_e values[SIZE] = { gender_e::UNDEF, gender_e::MALE, gender_e::FEMALE,  };

    auto res = values[ ::basic_parser::dummy::create__uint32() % SIZE ];

    return res;
}

// objects

UserInfo create__UserInfo()
{
    UserInfo res;

    ::user_management_protocol::initialize( & res
        , dummy::create__gender_e()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

// messages

SetUserInfoRequest * create__SetUserInfoRequest()
{
    auto res = new SetUserInfoRequest;

    ::user_management_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__UserInfo()
        );

    return res;
}

SetUserInfoResponse * create__SetUserInfoResponse()
{
    auto res = new SetUserInfoResponse;

    ::user_management_protocol::initialize( res
        );

    return res;
}

GetUserInfoRequest * create__GetUserInfoRequest()
{
    auto res = new GetUserInfoRequest;

    ::user_management_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetUserInfoResponse * create__GetUserInfoResponse()
{
    auto res = new GetUserInfoResponse;

    ::user_management_protocol::initialize( res
        , ::basic_parser::dummy::create__uint32()
        , dummy::create__gender_e()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

} // namespace dummy

} // namespace user_management_protocol

