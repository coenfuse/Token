#include "..\..\Token.h"

bool Token::checkAccess(const std::string& input) {
	if (access_codes.count(input) > 0)
		return true;
	else
		return false;
}

bool Token::checkSession(const std::string& input) {
	if (session_codes.count(input) > 0)
		return true;
	else
		return false;
}

bool Token::checkLog(const std::string& input) {
	if (log_codes.count(input) > 0)
		return true;
	else
		return false;
}

bool Token::checkOTP(const std::string& input) {
	if (OTP_codes.count(input) > 0)
		return true;
	else
		return false;
}