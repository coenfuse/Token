# Token
*A random token generator and handler for [Joker.](https://github.com/coenfuse/Joker)*

Token is a simple Token generation system for Joker. It generates 4 types of tokens:
- **Access Token:** A 64bit alphanumeric string that is used to distinguish and verify various 'Clients' that are supposed to be connected to Joker's Server. 
- **Log Token:** A 32bit alphanumeric string that is used to uniquely identify user log data that is later indexed into Joker's database
- **Session Token:** A 10bit alphanumeric string that is used to prove the validity of a session running in Joker's workspace.
- **OTP:** A 4bit numeric string that is generated to verify transactions within Joker.

*To access BAPI headers, a client needs to have a valid Access or Session Token or sometimes a pair of both.*

## How does Token System works in Joker?

### - Why care about Access Token?
As mentioned in the parent documentation, Joker tries to mimic a whole web-application experience within a single program. Maintaining its essential structure, the requirement of Access Token is created into Joker. Access Token represents that 'Developer Token' that the developer receives from the API supplier to use the APIs. ***I might be all wrong here** but I assume it is usually a one-time process.* A developer requests for identity verification and proves he/she isn't a robot and is given a token. The developer than saves the received token into the root directory of his project as a constant (I hope so) and uses it whenever the project needs to make an API call. Simple. This prevents the API supplier, by a significant degree, from experiencing any DDoS attacks.
In Joker it works just like that, although is purely for cosmetic purposes (as of now) but it is there :)

### - Why care about Log Token?
Everytime a user logs into Joker, a small set of data is generated that describes the online activity of the user. This generated data can be very useful to create important analytical reports that could aid in the development of system. To distinguish individual user's log-data from other one the log token is used. The 16bit width of log-token is sufficiently large to uniquely accomodate log-data even across multiple networks.

### - Why care about Session Token?
The usage and importance of Session Token can be better understood with an example:
Suppose a user logs into Joker using his/her credentials that he remembers. The user inputs its credentials and after successful verification, the user is given access to the system. To prevent malicious attack from automated robots BAPI employs a simple key authentication system inside itself. So to get access to BAPI regularly (that a user will once logs into the system because everything is operated via BAPI), one needs to verify its credential at every instance of operation. Since the credential data is located deep inside the data-base, it gets computationally expensive to re-read the file everytime a call to BAPI is made. Thus, to ease off this burden from the system, BAPI verifies the user's credentials once and provides the user with a Session Token. Since session key verification is situated comparatively high up in the system, it is less resource intensive and provides the same security protection.

### - Why care about OTP?
Frankly speaking, you don't have to. It is just a 'One Time Password' that is generated by the system and is supplied to user just to verify a transaction or any critical change in the system.

## How Token System maintains uniqueness?

Token system uses 4 statically declared data-structures of set type from STL. After generating a Token of desired type, token type if it already exists in the appropriate data set or not. If not, then the generated token is unique and is inserted into the data set and also passed to the user. And if a similar token already exists in the data set, simply a new one is generated.
Furthermore, for every session token that is generated and stored in the data-set, once the repsective session ends the attached session token is popped from the data-set. So the system doesn't give a false positive response whenever a new session key is generated.

