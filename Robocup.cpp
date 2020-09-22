#include <iostream>
#include <string>
#include <vector>
using namespace std;
class message_manager
{
private:
	
    string messages;                   //消息原始字符串
    string time
    string sender;
    string message;
    vector<string> total;              //经过处理后的消息分段存入vector中
	vector<string> objlnfos;
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
	message.replace(message.size()-1, 1, " ");
    messages.append(message.replace(0, 1, " "));
    messages.replace(messages.find("see")-2, 2, " ");
    
    int i = 0;
	while (i < messages.size())                                 //拆分字符串存入vector
    {
        ++i;
        string temp = "";
        while (messages[i] != ' '&&i < messages.size())
        {
            temp.append(messages,i,1);
            ++i;
        }
		total.push_back(temp);
	}
	
	vector<string>::iterator itt = total.begin();             //迭代器访问vector
	while(itt != total.end())
	{
		cout << *itt << "##";  
		++itt;
	}
}

message_manager::~message_manager()
{
}

int main()
{
	string s = "(hear udgawi ugf)(see awhfoiawh)";
    message_manager s1(s);
    
    return 0;
}
