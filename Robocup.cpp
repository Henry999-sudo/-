#include <iostream>
#include <string>
using namespace std;
class message_manager
{
private:
    string messages;
    string time_hear;
    string time_see;
    string sender;
    string objlnfo;
    /* data */
public:
    message_manager(string message);
    ~message_manager();
};
/*(hear 1022 -30 passto(23,24))(see 1022 ((ball) -20 20 1 -2) ((player hfut1 2) 45 23 0.5 1 22
40 ) ((goal r) 12 20) ((Line r) -30))
*/
message_manager::message_manager(string message)
{
    messages.append(message, 1, message.size()-2);
    cout << messages;
}

message_manager::~message_manager()
{
}

int main()
{
	string s = "(awiudgawiugfiuawhfoiawh)";
    message_manager s1(s);
    
    return 0;
}
