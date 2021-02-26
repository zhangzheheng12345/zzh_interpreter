#pragma once
#include <string>
#include <map>

using namespace std;

enum var_ts//var type's enum
{
	Int,
	Float,
	String,
	Bool,
	func,
	Class,
	Obj,
	Error
};

class var//put a var in here
{
public:
	void* value;//use void* for var<int,float.........>,different type of var in one map
	var_ts type;
	var(var_ts type)
	{
		this->type = type;
		switch (type)
		{
		case Int:
			value = (void*)(new int);
			break;
		case Float:
			value = (void*)(new float);
			break;
		case String:
			value = (void*)(new string);
			break;
		case Bool:
			value = (void*)(new bool);
			break;
		case func:
			value = (void*)(new string);
			break;
		case Class:
			value = (void*)(new string);
			break;
		default:
			break;
		}
	}
	var() {}
};

class obj_sys
{
public:
	void add_var(const string& varname,var_ts type);
	var get_var(const string& varname);
	bool set_var(const string& varname,void* value);
private:
	map<string, var*> obj_box;//var's box
};
