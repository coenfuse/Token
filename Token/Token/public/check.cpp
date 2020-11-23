#include "..\..\Token.h"

bool Token::checkAccess(std::string input) {
	if (access_codes.count(input) > 0)
		return true;
	else
		return false;
}

bool Token::checkSession(std::string input) {
	if (session_codes.count(input) > 0)
		return true;
	else
		return false;
}

bool Token::checkLog(std::string input) {
	if (log_codes.count(input) > 0)
		return true;
	else
		return false;
}

bool Token::checkOTP(std::string input) {
	if (OTP_codes.count(input) > 0)
		return true;
	else
		return false;
}