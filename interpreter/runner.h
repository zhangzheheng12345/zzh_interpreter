#pragma once
#include "obj_manager.h"
#include <string>

using namespace std;

class mono_objs
{
public:
	obj_sys vars, statics;
};

class func_box
{
public:
	string name;
	int arg_num;
	var_ts* arg_type_list;
};



class runner
{
public:
	void add_sentence(const string& sen);
	void print_var(const string& varname);
private:
	string get_var_name(int index);
	var_ts get_var_type(int index);
	void obj_adding_var();
	void obj_adding_const();
	void obj_adding_static();
	void obj_adding_global();
	void obj_parce();
	void func_parce();
	void module_parce();
	var obj_get(const string& name);
	void first_letter_check();
	string sen_to_run;
	obj_sys consts;
	mono_objs vas;
};
