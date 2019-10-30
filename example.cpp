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

void test_SetUserInfoResponse()
{
    auto s = user_management_protocol::create_SetUserInfoResponse();

    std::cout << user_management_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

void test_GetUserInfoResponse()
{
    auto s = user_management_protocol::create_GetUserInfoResponse( 123,
            user_management_protocol::gender_e::MALE,
            "Doe", "John", "Yoyodine Corp.", "john.doe@yoyodine.com", "", "+491234567890", "", "Europe/Berlin" );

    std::cout << user_management_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

int main()
{
    test_SetUserInfoResponse();
    test_GetUserInfoResponse();

    std::cout << "\n*********************************\n" << std::endl;

    test( "CMD=user_management/SetUserInfoRequest&USER_ID=&GENDER=1&LAST_NAME:X=446f65&FIRST_NAME:X=4a6f686e&COMPANY_NAME:X=596f796f64696e652c20496e632e&EMAIL:X=6a6f686e2e646f6540796f796f64696e652e636f6d&EMAIL_2:X=&PHONE:X=2b3439313233343536373839&PHONE_2:X=&TIMEZONE:X=4575726f70652f4265726c696e&SESSION_ID=afafaf&" );
    test( "CMD=user_management/SetUserInfoRequest&USER_ID=0&GENDER=1&LAST_NAME:X=446f65&FIRST_NAME:X=4a6f686e&COMPANY_NAME:X=596f796f64696e652c20496e632e&EMAIL:X=6a6f686e2e646f6540796f796f64696e652e636f6d&EMAIL_2:X=&PHONE:X=2b3439313233343536373839&PHONE_2:X=&TIMEZONE:X=4575726f70652f4265726c696e&SESSION_ID=afafaf&" );
    test( "CMD=user_management/SetUserInfoRequest&USER_ID=2074824509&GENDER=1&LAST_NAME:X=446f65&FIRST_NAME:X=4a6f686e&COMPANY_NAME:X=596f796f64696e652c20496e632e&EMAIL:X=6a6f686e2e646f6540796f796f64696e652e636f6d&EMAIL_2:X=&PHONE:X=2b3439313233343536373839&PHONE_2:X=&TIMEZONE:X=4575726f70652f4265726c696e&SESSION_ID=afafaf&" );

    test( "CMD=user_management/GetUserInfoRequest&SESSION_ID=af&USER_ID=" );
    test( "CMD=user_management/GetUserInfoRequest&SESSION_ID=af&USER_ID=0" );
    test( "CMD=user_management/GetUserInfoRequest&SESSION_ID=af&USER_ID=12" );

    return 0;
}
