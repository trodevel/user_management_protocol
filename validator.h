#ifndef APG_USER_MANAGEMENT_PROTOCOL__VALIDATOR_H
#define APG_USER_MANAGEMENT_PROTOCOL__VALIDATOR_H

// includes
#include "protocol.h"

namespace user_management_protocol
{

namespace validator
{

// enums
bool validate( const std::string & prefix, const gender_e r );

// objects
bool validate( const std::string & prefix, const UserInfo & r );

// base messages
bool validate( const Request & r );
bool validate( const BackwardMessage & r );

// messages
bool validate( const SetUserInfoRequest & r );
bool validate( const SetUserInfoResponse & r );
bool validate( const GetUserInfoRequest & r );
bool validate( const GetUserInfoResponse & r );

} // namespace validator

} // namespace user_management_protocol

#endif // APG_USER_MANAGEMENT_PROTOCOL__VALIDATOR_H
