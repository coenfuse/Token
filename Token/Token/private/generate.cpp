#include "..\..\Token.h"
#include <string>
#include <ctime>
#define OTP_length 4
#define SESSION_length 10
#define ACCESS_length 64
#define LOG_length 32
#define RANDOMIZE 9999999

const std::string_view pool = "abcdefghijklmnopqrstuvwxyz0123456789)!@#$%^&*(_+=ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string_view num_pool = "0123456789";

std::string Token::get_string(TOKEN_TYPE type) {

	srand((unsigned int)time(NULL) + rand() % RANDOMIZE);	// Read note at the end of this program.
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

// Note:
// How the srand() is used here?
// The initial approach was with the following syntax:
// srand((unsigned int)time_t(null));
// Techincally it should work find the rand() as the system time provided by
// time_t(null) should be enough for supplying random seeds. Well, it didn't
// happen. Change the line back to: srand((unsigned_int)time_t(null)) and
// you'll see the problem. What's happening there is that the seed is not
// random enough to generate a random string at every calling of the function.
// The execution of the code is so fast here that many random calls happen in
// the same instance of time. Since many calls happen in the same instance of
// time, the randomization core gets fundamentally flawed. To overcome this, the
// end user can call the function with a delay long enough that time_t(null)
// could provide a new seed. Well this is a horrible approach.
// What we can do is to add a system delay call just at the starting of the
// function so that whenver a new call is made. It would never be the same as
// the previous function call (if there was any). This works fine but it pulls
// the handbrake on the performance of this class. Imagine this token class
// implemented in a large banking system that requires to send and OTP to the
// user to complete every transaction. Firstly, if too many users are on the
// server, the individual delays of the function (even if they were in nanosecs)
// could together accumulate to much larger delay that could possibly make the
// network crawl. To avoid this, the following statement is written:
// srand((unsigned int)time_t(null) + rand() % RANDOMIZE)
// RANDOMIZE = 9999999
// The most important part is RANDOMIZE in this statement. To any generated
// seed (rand() % RANDOMIZE) value adds another random value from 0 to 999..
// This works exactly as what the delay methods does, infact in a better way
// and without any delay in the system. Furthermore, using a high value of
// RANDOMIZE is crucial otherwise it suffers from the similar drawback as first
// discussed in this comment.
// Suppose the syntax was this instead:
// srand((unsigned int)time_t(NULL) + rand() % 4)
// Here for any given instance of time_t the possible random seeds are only 4.
// If the system using this syntax is continuously throwing the code on a network,
// a senstive monitor with appropriate small delay could find a pattern in the
// outputs. Thus using high value of RANDOMIZE increases the randomness of the
// output proportionally.