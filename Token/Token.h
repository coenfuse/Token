#include <string>
#include <set>

// Initializing this container here reduces the size of Token object from 48 to 1.
//static std::set<std::string> session_codes, access_codes, OTP_codes, log_codes;

class Token {
private:
	// Enumerated types of string created by Token class
	const enum class TOKEN_TYPE {
		OTP,SESSION,ACCESS,LOG
	};
	// Containers for each type of string
	std::set<std::string> session_codes, access_codes, OTP_codes, log_codes;
	// Generated a random string of given type.
	std::string get_string(TOKEN_TYPE);
public:
	Token(){}
	~Token(){}

	// Returns a random 64bit alphanumeric string
	std::string giveAccess();
	// Returns a random 10bit alphanumeric string.
	std::string giveSession();
	// Returns a random 4bit numeric string.
	std::string giveOTP();
	// Returns a random 32bit alphanumeric string.
	std::string giveLog();

	// Check if input access code has been generated before.
	bool checkAccess(std::string);
	// Check if input session code has been generated before.
	bool checkSession(std::string);
	// Check if input OTP has been generated before.
	bool checkOTP(std::string);
	// Check if input Log code has been generated before.
	bool checkLog(std::string);

	// Removes the input string from the set (if found)
	void vacate(std::string);
};