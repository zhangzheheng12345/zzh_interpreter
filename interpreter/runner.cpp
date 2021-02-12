#include "runner.h"

#include <string>
#include <iostream>

using namespace std;

const int alpha_long = 53;
const char alpha[alpha_long] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

const char num[11] = "0123456789";

bool is_alpha(const char a)
{
	for (int t = 0; t < alpha_long; t++)
	{
		if (a == alpha[t])
			return true;
	}
	return false;
}

bool is_num(const char a)
{
	for (int t = 0; t < alpha_long; t++)
	{
		if (a == num[t])
			return true;
	}
	return false;
}

void runner::add_sentence(const string& sen)
{
	sen_to_run = sen;
	objs.add_var("hello_var", Float);
}

void runner::print_var(const string& varname)
{
	cout << varname << ':';
	var getted = obj_get(varname);
	switch (getted.type)
	{
	case Int:
		cout << *(int*)(getted.value) << endl;
		break;
	case Float:
		cout << *(float*)(getted.value) << endl;
		break;
	case String:
		cout << *(string*)(getted.value) << endl;
		break;
	default:
		cout << "strange thing\n";
	}
}

var runner::obj_get(const string& name)
{
	return objs.get_var(name);
}

void runner::first_letter_check()
{
	if (sen_to_run[0] == '.')
	{

	}
	else if (sen_to_run[0] == '_')
	{

	}
	else if (is_alpha(sen_to_run[0]))
	{

	}
	else
	{

	}
}
