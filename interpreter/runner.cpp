#include "runner.h"

#include <string>
#include <iostream>
#include <sstream>

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

string runner::get_var_name(int index)//pull out funcs here&under
{
	string varname = "";
	for (index; sen_to_run[index] != ':'; index++)//get the varname
		varname += sen_to_run[index];
}

var_ts runner::get_var_type(int index)
{
	string str_var_type = "";
	var_ts vartype;
	void* varvalue;
	for (index; is_alpha(sen_to_run[index]) || sen_to_run[index] == '_'; index++)//get the type
		str_var_type += sen_to_run[index];
	if (!strcmp(str_var_type.c_str(), "int"))//type:str to enum
	{
		vartype = Int;
		varvalue = (void*)new int(get_var_begin_value<int>(index));
	}
	else if (!strcmp(str_var_type.c_str(), "float"))
	{
		vartype = Float;
		varvalue = (void*)new float(get_var_begin_value<float>(index));
	}
	else if (!strcmp(str_var_type.c_str(), "string"))
	{
		vartype = String;
		varvalue = (void*)new string(get_var_begin_value<string>(index));//support string later //str to str?? error or not
	}
	else if (!strcmp(str_var_type.c_str(), "bool"))
	{
		vartype = Bool;
		varvalue = (void*)new bool(get_var_begin_value<bool>(index));
	}
	else if(!strcmp(str_var_type.c_str(),"func"))
	{
		vartype = func;//support func later
	}
	else if(!strcmp(str_var_type.c_str(),"class"))
	{
		vartype = Class;//support class later
	}
	else
	{
		//check classes
		//or output error
		
	}
	var a(vartype);
	a.value = varvalue;
	return a;
}

template<typename Type>
Type runner::get_var_begin_value(int index)
{
	string num;
	if (sen_to_run[index] == ';')
		return NULL;
	if (!is_num(sen_to_run[index+2])
	{
	    index += 3;
	}
	else
	{
		index += 2;
	}
	for (index;!sen_to_run[index] == ';';index++)//use the expression-parse later
	    num += sen_to_run[index];
	stringstream ss(num);
	Type value;
	ss >> value;
	return value;
}

void runner::obj_adding_var()//TODO:maybe need to pull the func of changing str_type to enum_type
{
	int i = 4;
	string varname = get_var_name(i);
	i++;
	var var_a = get_var_type(i);
	vas.vars.add_var(varname, var_a.type,var_a.value);
}

void runner::obj_adding_const()
{
	int i = 6;
	string varname = get_var_name(i);
	i++;
	var var_a = get_var_type(i);
	consts.add_var(varname,var_a.type,var_a.value);
}

void runner::obj_adding_static()
{
	int i = 7;
	string varname = get_var_name(i);
	i++;
	var var_a = get_var_type(i);
	vas.statics.add_var(varname,var_a.type,var_a.value);
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
	var value;
	value = vas.vars.get_var(name);
	if (value == Error)
	{
		value = vas.statics.get_var(name);
		if (value == Error)
		{
			value = consts.get_var(name);
			//if value == error again?? ->...
		}
	}
	return value;
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
		else if (!strcmp(key_word.c_str(),"const"))
		{
			obj_adding_const();
		}
		else if (!strcmp(key_word.c_str(),"static"))
		{
			obj_adding_static();
		}
		else
		{
			//other key words checking
			// or output error
		}
	}
	else
	{

	}
}
