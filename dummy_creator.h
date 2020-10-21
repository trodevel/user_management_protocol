#ifndef APG_USER_MANAGEMENT_PROTOCOL__DUMMY_CREATOR_H
#define APG_USER_MANAGEMENT_PROTOCOL__DUMMY_CREATOR_H

// includes
#include "protocol.h"

namespace user_management_protocol
{

namespace dummy
{

// enums

gender_e create__gender_e();

// objects

UserInfo create__UserInfo();

// messages

SetUserInfoRequest * create__SetUserInfoRequest();
SetUserInfoResponse * create__SetUserInfoResponse();
GetUserInfoRequest * create__GetUserInfoRequest();
GetUserInfoResponse * create__GetUserInfoResponse();

} // namespace dummy

} // namespace user_management_protocol

#endif // APG_USER_MANAGEMENT_PROTOCOL__DUMMY_CREATOR_H
