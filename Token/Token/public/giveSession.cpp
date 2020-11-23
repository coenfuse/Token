#include "..\..\Token.h"

std::string Token::giveSession() {
	std::string new_session = get_string(Token::TOKEN_TYPE::SESSION);
	while (true) {
		if (session_codes.count(new_session) == 0) {
			session_codes.insert(new_session);
			return new_session;
		}
		else
			new_session = get_string(Token::TOKEN_TYPE::SESSION);
	}
}