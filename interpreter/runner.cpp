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
	first_letter_check();
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
		cout << "couldn't get this var.undefined it or interpreter bugs.\n";
	}
}

void runner::obj_adding_var()
{
	string varname,str_var_type;
	var_ts vartype;
	int i = 4;
	for (i; sen_to_run[i] != ':'; i++)
		varname += sen_to_run[i];
	i++;
	for (i; is_alpha(sen_to_run[i]) || sen_to_run[i] == '_'; i++)
		str_var_type += sen_to_run[i];
	if (!strcmp(str_var_type.c_str(), "int"))
	{
		vartype = Int;
	}//more types...
	else if (!strcmp(str_var_type.c_str(), "float"))
	{
		vartype = Float;
	}
	else if (!strcmp(str_var_type.c_str(), "string"))
	{
		vartype = String;
	}
	else if (!strcmp(str_var_type.c_str(), "bool"))
	{
		vartype = Bool;
	}
	else
	{

	}
	vas.vars.add_var(varname, vartype);
}

void runner::obj_adding_const()
{

}

void runner::obj_adding_static()
{

}

void runner::obj_adding_global()
{

}

void runner::obj_parce()
{

}

void runner::func_parce()
{

}

void runner::module_parce()
{

}

var runner::obj_get(const string& name)
{
	return vas.vars.get_var(name);
}

void runner::first_letter_check()
{
	if (sen_to_run[0] == '.')
	{
		obj_parce();
	}
	else if (sen_to_run[0] == '_')
	{
		func_parce();
	}
	else if (is_alpha(sen_to_run[0]))
	{
		string key_word = "";
		for (int i = 0; is_alpha(sen_to_run[i])||sen_to_run[i]=='_'; i++)
			key_word += sen_to_run[i];
		if (!strcmp(key_word.c_str(), "var"))
		{
			obj_adding_var();
		}
	}
	else
	{

	}
}
