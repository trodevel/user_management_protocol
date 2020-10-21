#ifndef APG_USER_MANAGEMENT_PROTOCOL__OBJECT_INITIALIZER_H
#define APG_USER_MANAGEMENT_PROTOCOL__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

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
 );

// base messages

void initialize( Request * res
 );
void initialize( BackwardMessage * res
 );

// messages

void initialize( SetUserInfoRequest * res
    , uint32_t user_id
    , const UserInfo &  user_info
 );
void initialize( SetUserInfoResponse * res
 );
void initialize( GetUserInfoRequest * res
    , uint32_t user_id
 );
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
 );

// messages (constructors)

SetUserInfoRequest * create_SetUserInfoRequest(
    uint32_t user_id
    , const UserInfo &  user_info
 );
SetUserInfoResponse * create_SetUserInfoResponse(
 );
GetUserInfoRequest * create_GetUserInfoRequest(
    uint32_t user_id
 );
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
 );

} // namespace user_management_protocol

#endif // APG_USER_MANAGEMENT_PROTOCOL__OBJECT_INITIALIZER_H
