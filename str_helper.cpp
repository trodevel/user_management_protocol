// system includes
#include <map>

// includes
#include "str_helper.h"
#include "generic_protocol/str_helper.h"
#include "basic_objects/str_helper.h"
#include "basic_parser/str_helper.h"

namespace user_management_protocol
{

namespace str_helper
{

using ::basic_parser::str_helper::write;
using ::basic_parser::str_helper::write_t;

// enums

#define TUPLE_VAL_STR(_x_)  _x_,#_x_

std::ostream & write( std::ostream & os, const gender_e r )
{
    typedef gender_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( MALE ) },
        { Type:: TUPLE_VAL_STR( FEMALE ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

// objects

std::ostream & write( std::ostream & os, const UserInfo & r )
{
    os << "(";

    os << " gender="; write( os, r.gender );
    os << " last_name="; write( os, r.last_name );
    os << " first_name="; write( os, r.first_name );
    os << " company_name="; write( os, r.company_name );
    os << " email="; write( os, r.email );
    os << " email_2="; write( os, r.email_2 );
    os << " phone="; write( os, r.phone );
    os << " phone_2="; write( os, r.phone_2 );
    os << " timezone="; write( os, r.timezone );

    os << ")";

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{
    os << "(";

    // no base class

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    os << "(";

    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    os << ")";

    return os;
}

// messages

std::ostream & write( std::ostream & os, const SetUserInfoRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " user_info="; write( os, r.user_info );

    return os;
}

std::ostream & write( std::ostream & os, const SetUserInfoResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const GetUserInfoRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " user_id="; write( os, r.user_id );

    return os;
}

std::ostream & write( std::ostream & os, const GetUserInfoResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );

    os << " user_id="; write( os, r.user_id );
    os << " gender="; write( os, r.gender );
    os << " last_name="; write( os, r.last_name );
    os << " first_name="; write( os, r.first_name );
    os << " company_name="; write( os, r.company_name );
    os << " email="; write( os, r.email );
    os << " email_2="; write( os, r.email_2 );
    os << " phone="; write( os, r.phone );
    os << " phone_2="; write( os, r.phone_2 );
    os << " timezone="; write( os, r.timezone );

    return os;
}

} // namespace str_helper

} // namespace user_management_protocol

