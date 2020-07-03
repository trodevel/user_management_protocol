// includes
#include "validator.h"
#include "basic_objects/validator.h"
#include "basic_parser/validator.h"

namespace user_management_protocol
{

namespace validator
{

using ::basic_parser::validator::validate;
using ::basic_parser::validator::validate_t;

// enums

bool validate( const std::string & prefix, const gender_e r )
{
    validate( prefix, static_cast<unsigned>( r ), true, true, static_cast<unsigned>( gender_e::UNDEF ), true, true, static_cast<unsigned>( gender_e::FEMALE ) );

    return true;
}

// objects

bool validate( const std::string & prefix, const UserInfo & r )
{
    validate( prefix + ".GENDER", r.gender );
    validate( prefix + ".LAST_NAME", r.last_name ); // String
    validate( prefix + ".FIRST_NAME", r.first_name ); // String
    validate( prefix + ".COMPANY_NAME", r.company_name ); // String
    validate( prefix + ".EMAIL", r.email ); // String
    validate( prefix + ".EMAIL_2", r.email_2 ); // String
    validate( prefix + ".PHONE", r.phone ); // String
    validate( prefix + ".PHONE_2", r.phone_2 ); // String
    validate( prefix + ".TIMEZONE", r.timezone ); // String

    return true;
}

// base messages

bool validate( const Request & r )
{

    return true;
}

bool validate( const BackwardMessage & r )
{

    return true;
}

// messages

bool validate( const SetUserInfoRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "USER_INFO", r.user_info );

    return true;
}

bool validate( const SetUserInfoResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const GetUserInfoRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "USER_ID", r.user_id );

    return true;
}

bool validate( const GetUserInfoResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );

    validate( "USER_ID", r.user_id );
    validate( "GENDER", r.gender );
    validate( "LAST_NAME", r.last_name ); // String
    validate( "FIRST_NAME", r.first_name ); // String
    validate( "COMPANY_NAME", r.company_name ); // String
    validate( "EMAIL", r.email ); // String
    validate( "EMAIL_2", r.email_2 ); // String
    validate( "PHONE", r.phone ); // String
    validate( "PHONE_2", r.phone_2 ); // String
    validate( "TIMEZONE", r.timezone ); // String

    return true;
}

} // namespace validator

} // namespace user_management_protocol

