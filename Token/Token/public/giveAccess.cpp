#include "..\..\Token.h"

std::string Token::giveAccess() {
	std::string new_access = get_string(Token::TOKEN_TYPE::ACCESS);
	while (true) {
		if (access_codes.count(new_access) == 0) {
			access_codes.insert(new_access);
			return new_access;			// Returns the code if its unique.
		}
		else
			new_access = get_string(Token::TOKEN_TYPE::ACCESS);
	}
}