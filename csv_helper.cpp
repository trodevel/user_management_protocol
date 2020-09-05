// system includes
#include <map>
#include <typeindex>

// includes
#include "csv_helper.h"
#include "generic_protocol/csv_helper.h"
#include "basic_objects/csv_helper.h"
#include "basic_parser/csv_helper.h"

namespace user_management_protocol
{

namespace csv_helper
{

using ::basic_parser::csv_helper::write;
using ::basic_parser::csv_helper::write_t;

// enums

std::ostream & write( std::ostream & os, const gender_e r )
{
    write( os, static_cast<unsigned>( r ) );

    return os;
}

// objects

std::ostream & write( std::ostream & os, const UserInfo & r )
{
    write( os, r.gender );
    write( os, r.last_name );
    write( os, r.first_name );
    write( os, r.company_name );
    write( os, r.email );
    write( os, r.email_2 );
    write( os, r.phone );
    write( os, r.phone_2 );
    write( os, r.timezone );

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{
    // no base class

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

// messages

std::ostream & write( std::ostream & os, const SetUserInfoRequest & r )
{
    write( os, std::string( "user_management/SetUserInfoRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );
    write( os, r.user_info );

    return os;
}

std::ostream & write( std::ostream & os, const SetUserInfoResponse & r )
{
    write( os, std::string( "user_management/SetUserInfoResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetUserInfoRequest & r )
{
    write( os, std::string( "user_management/GetUserInfoRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.user_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetUserInfoResponse & r )
{
    write( os, std::string( "user_management/GetUserInfoResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    write( os, r.user_id );
    write( os, r.gender );
    write( os, r.last_name );
    write( os, r.first_name );
    write( os, r.company_name );
    write( os, r.email );
    write( os, r.email_2 );
    write( os, r.phone );
    write( os, r.phone_2 );
    write( os, r.timezone );

    return os;
}

std::ostream & write_SetUserInfoRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SetUserInfoRequest &>( rr );

    return write( os, r );
}

std::ostream & write_SetUserInfoResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const SetUserInfoResponse &>( rr );

    return write( os, r );
}

std::ostream & write_GetUserInfoRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetUserInfoRequest &>( rr );

    return write( os, r );
}

std::ostream & write_GetUserInfoResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const GetUserInfoResponse &>( rr );

    return write( os, r );
}


std::ostream & write( std::ostream & os, const basic_parser::Object & r )
{
    typedef std::ostream & (*PPMF)( std::ostream & os, const basic_parser::Object & );

#define HANDLER_MAP_ENTRY(_v)       { typeid( _v ),        & write_##_v }

    static const std::map<std::type_index, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( SetUserInfoRequest ),
        HANDLER_MAP_ENTRY( SetUserInfoResponse ),
        HANDLER_MAP_ENTRY( GetUserInfoRequest ),
        HANDLER_MAP_ENTRY( GetUserInfoResponse ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( typeid( r ) );

    if( it != funcs.end() )
        return it->second( os, r );

    return ::generic_protocol::csv_helper::write( os, r );
}

} // namespace csv_helper

} // namespace user_management_protocol

