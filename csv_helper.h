#ifndef APG_USER_MANAGEMENT__CSV_HELPER_H
#define APG_USER_MANAGEMENT__CSV_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace user_management_protocol
{

namespace csv_helper
{

// enums
std::ostream & write( std::ostream & os, const gender_e r );

// objects
std::ostream & write( std::ostream & os, const UserInfo & r );

// base messages
std::ostream & write( std::ostream & os, const Request & r );
std::ostream & write( std::ostream & os, const BackwardMessage & r );

// messages
std::ostream & write( std::ostream & os, const SetUserInfoRequest & r );
std::ostream & write( std::ostream & os, const SetUserInfoResponse & r );
std::ostream & write( std::ostream & os, const GetUserInfoRequest & r );
std::ostream & write( std::ostream & os, const GetUserInfoResponse & r );

template<class T>
std::string to_csv( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

// generic
std::ostream & write( std::ostream & os, const basic_parser::Object & r );

} // namespace csv_helper

} // namespace user_management_protocol

#endif // APG_USER_MANAGEMENT__CSV_HELPER_H
