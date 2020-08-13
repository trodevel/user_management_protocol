#ifndef APG_USER_MANAGEMENT__PROTOCOL_H
#define APG_USER_MANAGEMENT__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"
#include "generic_protocol/protocol.h"

// includes for used modules
#include "basic_objects/protocol.h"

namespace user_management_protocol
{

// Enum
enum class gender_e
{
    UNDEF                = 0,
    MALE                 = 1,
    FEMALE               = 2,
};

// Object
struct UserInfo
{
    gender_e             gender    ;
    std::string          last_name ;
    std::string          first_name;
    std::string          company_name;
    std::string          email     ;
    std::string          email_2   ;
    std::string          phone     ;
    std::string          phone_2   ;
    std::string          timezone  ;
};

// Base message
struct Request: public basic_parser::Object
{
};

// Base message
struct BackwardMessage: public generic_protocol::BackwardMessage
{
};

// Message
struct SetUserInfoRequest: public Request
{
    enum
    {
        message_id = 2140375678
    };

    uint32_t             user_id   ;
    UserInfo             user_info ;
};

// Message
struct SetUserInfoResponse: public BackwardMessage
{
    enum
    {
        message_id = 3912424720
    };
};

// Message
struct GetUserInfoRequest: public Request
{
    enum
    {
        message_id = 1519911264
    };

    uint32_t             user_id   ;
};

// Message
struct GetUserInfoResponse: public BackwardMessage
{
    enum
    {
        message_id = 320400376
    };

    uint32_t             user_id   ;
    gender_e             gender    ;
    std::string          last_name ;
    std::string          first_name;
    std::string          company_name;
    std::string          email     ;
    std::string          email_2   ;
    std::string          phone     ;
    std::string          phone_2   ;
    std::string          timezone  ;
};

} // namespace user_management_protocol

#endif // APG_USER_MANAGEMENT__PROTOCOL_H

