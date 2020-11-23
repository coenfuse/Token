#include "..\..\Token.h"
#include <string>
#include <ctime>
#define OTP_length 4
#define SESSION_length 10
#define ACCESS_length 64
#define LOG_length 32

const std::string_view pool = "abcdefghijklmnopqrstuvwxyz0123456789)!@#$%^&*(_+=ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string_view num_pool = "0123456789";

std::string Token::get_string(TOKEN_TYPE type) {
	srand((unsigned int)time(NULL));
	std::string generated_string;

	switch (type)
	{
	case Token::TOKEN_TYPE::OTP: {
		for (int i = 0; i < OTP_length; i++) {
			generated_string += num_pool[rand() % num_pool.length()];
		}
		return generated_string;
	}
		break;
	case Token::TOKEN_TYPE::SESSION: {
		for (int i = 0; i < SESSION_length; i++) {
			generated_string += pool[rand() % pool.length()];
		}
		return generated_string;
	}
		break;
	case Token::TOKEN_TYPE::ACCESS: {
		for (int i = 0; i < ACCESS_length; i++) {
			generated_string += pool[rand() % pool.length()];
		}
		return generated_string;
	}
		break;
	case Token::TOKEN_TYPE::LOG: {
		for (int i = 0; i < LOG_length; i++){
			generated_string += pool[rand() % pool.length()];
		}
		return generated_string;
	}
		break;
	default:
		return "-1";
		break;
	}
}