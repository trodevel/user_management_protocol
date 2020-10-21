#ifndef APG_USER_MANAGEMENT_PROTOCOL__ENUMS_H
#define APG_USER_MANAGEMENT_PROTOCOL__ENUMS_H

namespace user_management_protocol
{

enum class request_type_e
{
    UNDEF,
    SetUserInfoRequest,
    SetUserInfoResponse,
    GetUserInfoRequest,
    GetUserInfoResponse,
};

} // namespace user_management_protocol

#endif // APG_USER_MANAGEMENT_PROTOCOL__ENUMS_H
