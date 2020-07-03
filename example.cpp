#include "protocol.h"
#include "str_helper.h"
#include "csv_helper.h"
#include "dummy_creator.h"
#include "validator.h"

#include <iostream>       // std::cout

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        user_management_protocol::validator::validate( o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

// enums

void example_gender_e()
{
    auto obj = user_management_protocol::dummy::create__gender_e();

    std::cout << "gender_e : STR : " << user_management_protocol::str_helper::to_string( obj ) << std::endl;
}


// objects

void example_UserInfo()
{
    auto obj = user_management_protocol::dummy::create__UserInfo();

    std::cout << "UserInfo : STR : " << user_management_protocol::str_helper::to_string( obj ) << std::endl;
}


// messages

void example_SetUserInfoRequest()
{
    auto & obj = * user_management_protocol::dummy::create__SetUserInfoRequest();

    std::cout << "SetUserInfoRequest : STR : " << user_management_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SetUserInfoRequest : CSV : " << user_management_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SetUserInfoRequest" );

    delete & obj;
}

void example_SetUserInfoResponse()
{
    auto & obj = * user_management_protocol::dummy::create__SetUserInfoResponse();

    std::cout << "SetUserInfoResponse : STR : " << user_management_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "SetUserInfoResponse : CSV : " << user_management_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "SetUserInfoResponse" );

    delete & obj;
}

void example_GetUserInfoRequest()
{
    auto & obj = * user_management_protocol::dummy::create__GetUserInfoRequest();

    std::cout << "GetUserInfoRequest : STR : " << user_management_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetUserInfoRequest : CSV : " << user_management_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetUserInfoRequest" );

    delete & obj;
}

void example_GetUserInfoResponse()
{
    auto & obj = * user_management_protocol::dummy::create__GetUserInfoResponse();

    std::cout << "GetUserInfoResponse : STR : " << user_management_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetUserInfoResponse : CSV : " << user_management_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetUserInfoResponse" );

    delete & obj;
}


int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        std::srand( std::stoi( std::string( argv[1] ) ) );
    }

    // enums

    example_gender_e();

    // objects

    example_UserInfo();

    // messages

    example_SetUserInfoRequest();
    example_SetUserInfoResponse();
    example_GetUserInfoRequest();
    example_GetUserInfoResponse();

    return 0;
}

