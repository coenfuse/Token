#include "..\..\Token.h"
#define OTP 4
#define LOG 32
#define ACCESS 64
#define SESSION 10

void Token::vacate(std::string input) {
	unsigned short length = (unsigned short)input.length();
	switch (length)
	{
		case OTP: {
			if (OTP_codes.count(input) > 0)
				OTP_codes.erase(input);
		}
			break;
		case LOG: {
			if (log_codes.count(input) > 0)
				log_codes.erase(input);
		}
			break;
		case ACCESS: {
			if (access_codes.count(input) > 0)
				access_codes.erase(input);
		}
			break;
		case SESSION: {
			if (session_codes.count(input) > 0)
				session_codes.erase(input);
		}
			break;
		default:
			break;
	}
}