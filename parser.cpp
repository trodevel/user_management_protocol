// system includes
#include <map>
#include <memory>

// includes
#include "parser.h"
#include "basic_objects/parser.h"
#include "basic_parser/parser.h"
#include "basic_parser/malformed_request.h"
#include "validator.h"
#include "request_type_parser.h"

namespace user_management_protocol
{

namespace parser
{

using ::basic_parser::parser::get_value_or_throw;
using ::basic_parser::parser::get_value_or_throw_t;

// enums

void get_value_or_throw( gender_e * res, const std::string & key, const generic_request::Request & r )
{
    uint32_t res_i;

    get_value_or_throw( & res_i, key, r );

    * res = static_cast<gender_e>( res_i );
}

// objects

void get_value_or_throw( UserInfo * res, const std::string & prefix, const generic_request::Request & r )
{
    get_value_or_throw( & res->gender, prefix + ".GENDER", r );
    get_value_or_throw( & res->last_name, prefix + ".LAST_NAME", r );
    get_value_or_throw( & res->first_name, prefix + ".FIRST_NAME", r );
    get_value_or_throw( & res->company_name, prefix + ".COMPANY_NAME", r );
    get_value_or_throw( & res->email, prefix + ".EMAIL", r );
    get_value_or_throw( & res->email_2, prefix + ".EMAIL_2", r );
    get_value_or_throw( & res->phone, prefix + ".PHONE", r );
    get_value_or_throw( & res->phone_2, prefix + ".PHONE_2", r );
    get_value_or_throw( & res->timezone, prefix + ".TIMEZONE", r );
}

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r )
{
}

void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r )
{
}

// messages

void get_value_or_throw( SetUserInfoRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->user_info, "USER_INFO", r );
}

void get_value_or_throw( SetUserInfoResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( GetUserInfoRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
}

void get_value_or_throw( GetUserInfoResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

    get_value_or_throw( & res->user_id, "USER_ID", r );
    get_value_or_throw( & res->gender, "GENDER", r );
    get_value_or_throw( & res->last_name, "LAST_NAME", r );
    get_value_or_throw( & res->first_name, "FIRST_NAME", r );
    get_value_or_throw( & res->company_name, "COMPANY_NAME", r );
    get_value_or_throw( & res->email, "EMAIL", r );
    get_value_or_throw( & res->email_2, "EMAIL_2", r );
    get_value_or_throw( & res->phone, "PHONE", r );
    get_value_or_throw( & res->phone_2, "PHONE_2", r );
    get_value_or_throw( & res->timezone, "TIMEZONE", r );
}

// to object

Object * to_SetUserInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<SetUserInfoRequest> res( new SetUserInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_SetUserInfoResponse( const generic_request::Request & r )
{
    std::unique_ptr<SetUserInfoResponse> res( new SetUserInfoResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetUserInfoRequest( const generic_request::Request & r )
{
    std::unique_ptr<GetUserInfoRequest> res( new GetUserInfoRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_GetUserInfoResponse( const generic_request::Request & r )
{
    std::unique_ptr<GetUserInfoResponse> res( new GetUserInfoResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

// to forward message

basic_parser::Object* to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef request_type_e KeyType;

    typedef Object* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & to_##_v }

    static const std::map<KeyType, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( SetUserInfoRequest ),
        HANDLER_MAP_ENTRY( SetUserInfoResponse ),
        HANDLER_MAP_ENTRY( GetUserInfoRequest ),
        HANDLER_MAP_ENTRY( GetUserInfoResponse ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return nullptr;
}

using basic_parser::MalformedRequest;

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return RequestTypeParser::to_request_type( cmd );
}

} // namespace parser

} // namespace user_management_protocol

