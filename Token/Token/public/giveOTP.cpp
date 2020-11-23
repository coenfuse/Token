#include "..\..\Token.h"

std::string Token::giveOTP() {
	std::string new_OTP = get_string(Token::TOKEN_TYPE::OTP);
	while (true) {
		if (OTP_codes.count(new_OTP) == 0) {
			OTP_codes.insert(new_OTP);
			return new_OTP;
		}
		else
			new_OTP = get_string(Token::TOKEN_TYPE::OTP);
	}
}