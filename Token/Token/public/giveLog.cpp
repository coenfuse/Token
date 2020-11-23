#include "..\..\Token.h"

std::string Token::giveLog() {
	std::string new_string = get_string(Token::TOKEN_TYPE::LOG);
	while (true) {
		if (log_codes.count(new_string) == 0)
			return new_string;
		else
			new_string = get_string(Token::TOKEN_TYPE::LOG);
	}
}