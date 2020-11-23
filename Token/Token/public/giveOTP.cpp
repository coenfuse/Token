#include "..\..\Token.h"

std::string Token::giveOTP() {
	std::string new_string = get_string(Token::TOKEN_TYPE::OTP);
	while (true) {
		if (OTP_codes.count(new_string) == 0)
			return new_string;
		else
			new_string = get_string(Token::TOKEN_TYPE::OTP);
	}
}