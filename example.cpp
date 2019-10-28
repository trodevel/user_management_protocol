#include <iostream>

#include "generic_request/request_parser.h"

#include "user_management_protocol.h"
#include "request_parser.h"
#include "response_gen.h"           // create_closed_job_status
#include "str_helper.h"             // StrHelper::to_string()
#include "csv_response_encoder.h"   // CsvResponseEncoder::to_csv()

void test( const std::string & str )
{
    std::cout << "REQ = " << str << " - ";

    try
    {
        generic_request::Request gr = generic_request::RequestParser::to_request( str );

        auto * r = user_management_protocol::RequestParser::to_forward_message( gr );

        if( r )
        {
            delete r;

            std::cout << "ok\n";
        }
        else
        {
            std::cout << "FAILED - cannot parse\n";
        }
    }
    catch( std::exception & e )
    {
        std::cout << "FAILED - " << e.what() << "\n";
    }
}

void test_SetPersonalUserInfoResponse()
{
    auto s = user_management_protocol::create_SetPersonalUserInfoResponse();

    std::cout << user_management_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetPersonalUserInfoResponse()
{
    auto s = user_management_protocol::create_GetPersonalUserInfoResponse( 123,
            user_management_protocol::gender_e::MALE,
            "Doe", "John", "Yoyodine Corp.", "john.doe@yoyodine.com", "", "+491234567890", "", "Europe/Berlin" );

    std::cout << user_management_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

int main()
{
    test_SetPersonalUserInfoResponse();
    test_GetPersonalUserInfoResponse();

    std::cout << "\n*********************************\n" << std::endl;

    test( "CMD=user_management/GetPersonalUserInfoRequest&SESSION_ID=af&USER_ID=" );
    test( "CMD=user_management/GetPersonalUserInfoRequest&SESSION_ID=af&USER_ID=0" );
    test( "CMD=user_management/GetPersonalUserInfoRequest&SESSION_ID=af&USER_ID=12" );

    return 0;
}
