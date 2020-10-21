// system includes
#include <map>

// includes
#include "request_type_parser.h"

namespace user_management_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,"user_management_protocol/"+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

request_type_e RequestTypeParser::to_request_type( const std::string & s )
{
    typedef std::string KeyType;
    typedef request_type_e Type;

    typedef std::map< KeyType, Type > Map;
    static const Map m =
    {
        make_inverse_pair( Type:: TUPLE_VAL_STR( SetUserInfoRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( SetUserInfoResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetUserInfoRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetUserInfoResponse ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}
} // namespace user_management_protocol

