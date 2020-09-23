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
    vector<string> HEAR;              //经过处理后的消息分段存入vector中
	vector<string> SEE;
    vector<string> objlnfos;          
    
public:
    message_manager(string message);
    ~message_manager();
    void message_print();
};
/*(hear 1022 -30 passto(23,24))(see 1022 ((ball) -20 20 1 -2) ((player hfut1 2) 45 23 0.5 1 22
40 ) ((goal r) 12 20) ((Line r) -30))
*/
void message_manager::message_print()
{
    cout << "在" << time <<  " 周期 hear 从 " << sender << "方向 听到了 " << message << endl;
    
    cout << "在" << time << " 周期 see ";
    vector<string>::iterator itt = SEE.begin()-2;
    while (itt != SEE.end())
    {
        vector<string> container;
        container.push_back(*itt.)

        int index = *itt.find(")");
        while (index < *itt.size())
        {
            string temp;
            while (*itt[index] != ' '&&*itt[index] != '('&&itt[index] != ')'&&index < *itt.size())
            {
                temp.append(*itt[index]);
                index++;
            }
            container.push_back(temp);
            index++;
        }

        if (*itt.find("ball") != -1)
        {
            cout << " Ball 距离我的Direction是 " << container[1] << ", Distance是" << container[2] 
                    << ", Distchng是" << container[3] << ", Dirchng是" << container[4]; 
        }
        if (*itt.find("player") != -1)
        {
            cout << container[0] << "距离我的Direction是 " << container[1] << ", Distance是" 
                    << container[2] << ", Dischng是" << container[3] << "Dirchng是" << container[4]
                            << "它的BodyDir是 " << container[5] << "，HeadDir是 " << container[6];
        }
        if (*itt.find("goal Side") != -1)
        {
            
        }
        if (*itt.find("f ") != -1)
        {

        }
        if (*itt.find("line") != -1)
        {

        }
        ++itt;
    }
    
}

message_manager::message_manager(string original_message)
{
	original_message.replace(original_message.size()-1, 1, " ");
    messages.append(original_message.replace(0, 1, " "));
    messages.replace(messages.find("see")-2, 2, " ");
    messages_hear.append(messages,messages.find("hear"), messages.find("see") - messages.find("hear"));
    messages_see.append(messages, messages.find("see"), messages.size() - messages.find("see"));
    
    int index = 0;
    int flag = 0;
    
	while (index < messages_hear.size())                                 
    {
        string temp = "";
        while (((messages_hear[index] != ' ') && (index < messages_hear.size())) || (flag != 0))
        {
            if (messages_hear[index] == '(')
            {
                ++flag;
            }
            if (messages_hear[index] == ')')
            {
                --flag;
            }

            temp.append(messages_hear,index,1);
            ++index;
        }

        ++index;
        if (temp != "")
        {
            HEAR.push_back(temp);
        }	
	}
	
	index = 0;
	flag = 0;
	while (index < messages_see.size())                                 
    {
        string temp = "";
        while (((messages_see[index] != ' ') && (index < messages_see.size())) || (flag != 0))
        {
            if (messages_see[index] == '(')
            {
                ++flag;
            }
            if (messages_see[index] == ')')
            {
                --flag;
            }

            temp.append(messages_see,index,1);
            ++index;
        }

        ++index;
        if (temp != "")
        {
            SEE.push_back(temp);
        }	
	}
	
	vector<string>::iterator itt = HEAR.begin();             //迭代器访问vector
	while (itt != HEAR.end())
	{
        switch (itt - HEAR.begin()-1)
        {
        case 0:
            time.append(*itt);
            break;
        case 1:
            sender.append(*itt);
            break;
        case 2:
            message.append(*itt);
            break;
        }
		++itt;
	}

    cout << message <<endl;
    cout << time << endl;
    cout << sender << endl;

    itt = SEE.begin()+1;
    while (itt != SEE.end())
    {
        cout << *itt << "#";
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
