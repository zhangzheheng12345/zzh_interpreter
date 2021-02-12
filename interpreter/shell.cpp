#include "shell.h"
#include "runner.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int me_length = 3;
string messages[me_length];

runner run_sys;

//get the messages at the begining
bool get_message()
{
	ifstream get_m;
	int index = 0;
	get_m.open("messages.txt");//open file
	if (!get_m)//check:if open the file successfully
		return false;
	while (!get_m.eof())//get all the messages
	{
		getline(get_m, messages[index]);
		index++;
	}
	get_m.close();
	return true;
}


void mono_check(const string& cmd)
{
	string cmd_name,arg;
	int t;
	for (t = 0; t < 3; t++)
	{
		cmd_name += cmd[t];
	}
	t++;
	for (t; t < cmd.length(); t++)
	{
		arg += cmd[t];
	}
	if (strcmp(cmd_name.c_str(), "get"))
	{
		run_sys.print_var(arg);
	}
}

//run the shell
bool shell_run()
{
	runner run;//init runnner
	if(!get_message())//get messages func
		return false;
	string input = "";
	for (int i = 0; i < me_length; i++)
		cout << messages[i] << endl;//output the messsages
	while (strcmp(input.c_str(), "quit"))//check:if the user wants to leave
	{
		cout << ">";
		getline(cin, input);//get input
		mono_check(input);
	}
	return true;
}

