#include "..\..\Token.h"

std::string Token::giveLog() {
	std::string new_log = get_string(Token::TOKEN_TYPE::LOG);
	while (true) {
		if (log_codes.count(new_log) == 0) {
			log_codes.insert(new_log);
			return new_log;
		}
		else
			new_log = get_string(Token::TOKEN_TYPE::LOG);
	}
}