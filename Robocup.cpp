#include <iostream>
#include <string>
#include <vector>
using namespace std;
class message_manager
{
private:
	
    string messages;                   //消息原始字符串
    string messages_see;
    string messages_hear;
    string time;
    string sender;
    string message;
    vector<string> total;              //经过处理后的消息分段存入vector中
	vector<string> objlnfos;
    
    /* data */
public:
    message_manager(string message);
    ~message_manager();
    void message_print();
};
/*(hear 1022 -30 passto(23,24))(see 1022 ((ball) -20 20 1 -2) ((player hfut1 2) 45 23 0.5 1 22
40 ) ((goal r) 12 20) ((Line r) -30))
*/
message_manager::message_print()
{
    cout << "在" << time <<  "" << sender << << message <<endl;
    cout << "在" << time << "";
    
}

message_manager::message_manager(string original_message)
{
	original_message.replace(original_message.size()-1, 1, " ");
    messages.append(original_message.replace(0, 1, " "));
    messages.replace(messages.find("see")-2, 2, " ");
    messages_hear.append(messages,messages.find("hear"), messages.find("see") - messages.find("hear"));
    messages_see.append(messages, messages.find("see"), messages.size() - messages.find("see"));

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
	
    total.erase(total.begin());              //删除hear
    total.erase(total.begin() + 3);          //删除see
    total.erase(total.begin());              //删除多余的一个time
	vector<string>::iterator itt = total.begin();             //迭代器访问vector
	while (itt != total.end())
	{
		//cout << *itt << "##";  
        switch (itt - total.begin())
        {
        case 0:
            sender.append(*itt);
            break;
        case 1:
            message.append(*itt);
            break;
        case 2:
            time.append(*itt);
            break;
        default:
            objlnfos.push_back(*itt);
            break;
        }
		++itt;
	}

    cout << "time :" << time << "#";
    cout << "sender" << sender << "#";
    cout << "message:" << message << "#";
    itt = objlnfos.begin();
    while (itt != objlnfos.end())
    {
        cout << "*" << *itt << "*";
        ++itt;
    }
    
}

message_manager::~message_manager()
{
}

int main()
{
	string s = "(hear 1022 -30 passto(23,24))(see 1022 ((ball) -20 20 1 -2) ((player hfut1 2) 45 23 0.5 1 2240 ) ((goal r) 12 20) ((Line r) -30))";
    message_manager s1(s);
    
    return 0;
}
