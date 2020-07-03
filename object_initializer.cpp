// includes
#include "object_initializer.h"

namespace user_management_protocol
{

// objects

void initialize( UserInfo * res
    , gender_e gender
    , const std::string &  last_name
    , const std::string &  first_name
    , const std::string &  company_name
    , const std::string &  email
    , const std::string &  email_2
    , const std::string &  phone
    , const std::string &  phone_2
    , const std::string &  timezone
 )
{
    res->gender = gender;
    res->last_name = last_name;
    res->first_name = first_name;
    res->company_name = company_name;
    res->email = email;
    res->email_2 = email_2;
    res->phone = phone;
    res->phone_2 = phone_2;
    res->timezone = timezone;
}

// base messages

void initialize( Request * res
 )
{
    // no base class
}

void initialize( BackwardMessage * res
 )
{
    // no base class
}

// messages

void initialize( SetUserInfoRequest * res
    , uint32_t user_id
    , const UserInfo &  user_info
 )
{
    // base class
    initialize( static_cast<Request*>( res ) );

    res->user_id = user_id;
    res->user_info = user_info;
}

void initialize( SetUserInfoResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( GetUserInfoRequest * res
    , uint32_t user_id
 )
{
    // base class
    initialize( static_cast<Request*>( res ) );

    res->user_id = user_id;
}

void initialize( GetUserInfoResponse * res
    , uint32_t user_id
    , const gender_e &  gender
    , const std::string &  last_name
    , const std::string &  first_name
    , const std::string &  company_name
    , const std::string &  email
    , const std::string &  email_2
    , const std::string &  phone
    , const std::string &  phone_2
    , const std::string &  timezone
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

    res->user_id = user_id;
    res->gender = gender;
    res->last_name = last_name;
    res->first_name = first_name;
    res->company_name = company_name;
    res->email = email;
    res->email_2 = email_2;
    res->phone = phone;
    res->phone_2 = phone_2;
    res->timezone = timezone;
}

// messages (constructors)

SetUserInfoRequest * create_SetUserInfoRequest(
    uint32_t user_id
    , const UserInfo &  user_info
 )
{
    auto * res = new SetUserInfoRequest;

    initialize( res, user_id, user_info );

    return res;
}

SetUserInfoResponse * create_SetUserInfoResponse(
 )
{
    auto * res = new SetUserInfoResponse;

    initialize( res );

    return res;
}

GetUserInfoRequest * create_GetUserInfoRequest(
    uint32_t user_id
 )
{
    auto * res = new GetUserInfoRequest;

    initialize( res, user_id );

    return res;
}

GetUserInfoResponse * create_GetUserInfoResponse(
    uint32_t user_id
    , const gender_e &  gender
    , const std::string &  last_name
    , const std::string &  first_name
    , const std::string &  company_name
    , const std::string &  email
    , const std::string &  email_2
    , const std::string &  phone
    , const std::string &  phone_2
    , const std::string &  timezone
 )
{
    auto * res = new GetUserInfoResponse;

    initialize( res, user_id, gender, last_name, first_name, company_name, email, email_2, phone, phone_2, timezone );

    return res;
}

} // namespace user_management_protocol

