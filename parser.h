#ifndef APG_USER_MANAGEMENT_PROTOCOL__PARSER_H
#define APG_USER_MANAGEMENT_PROTOCOL__PARSER_H

// includes
#include "generic_request/request.h"
#include "enums.h"
#include "protocol.h"

namespace user_management_protocol
{

namespace parser
{

typedef basic_parser::Object    Object;

basic_parser::Object * to_forward_message( const generic_request::Request & r );

request_type_e detect_request_type( const generic_request::Request & r );

// enums

void get_value_or_throw( gender_e * res, const std::string & key, const generic_request::Request & r );

// objects

void get_value_or_throw( UserInfo * res, const std::string & key, const generic_request::Request & r );

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r );
void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r );

// messages

void get_value_or_throw( SetUserInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( SetUserInfoResponse * res, const generic_request::Request & r );
void get_value_or_throw( GetUserInfoRequest * res, const generic_request::Request & r );
void get_value_or_throw( GetUserInfoResponse * res, const generic_request::Request & r );

// to_... functions

Object * to_SetUserInfoRequest( const generic_request::Request & r );
Object * to_SetUserInfoResponse( const generic_request::Request & r );
Object * to_GetUserInfoRequest( const generic_request::Request & r );
Object * to_GetUserInfoResponse( const generic_request::Request & r );

} // namespace parser

} // namespace user_management_protocol

#endif // APG_USER_MANAGEMENT_PROTOCOL__PARSER_H
