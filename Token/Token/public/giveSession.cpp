#include "..\..\Token.h"

std::string Token::giveSession() {
	std::string new_string = get_string(Token::TOKEN_TYPE::SESSION);
	while (true) {
		if (session_codes.count(new_string) == 0)
			return new_string;
		else
			new_string = get_string(Token::TOKEN_TYPE::SESSION);
	}
}