#pragma once
#include "obj_manager.h"
#include <string>
using namespace std;
class runner
{
public:
	void add_sentence(const string& sen);
	void print_var(const string& varname);
private:
	var obj_get(const string& name);
	void first_letter_check();
	string sen_to_run;
	obj_sys objs;
};