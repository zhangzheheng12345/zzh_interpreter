#include "obj_manager.h"
#include <string>
#include <map>

#include <iostream>//only for debug

void obj_sys::add_var(const string& varname,var_ts type,void* begin_value = NULL)//add a new var
{
	obj_box.insert(pair<str,var*>(varname,new var(type))); //do some thing to check error before
	obj_box.set_var(varname,begin_value);
}

var obj_sys::get_var(const string& varname)//get the whole obj
{
	var value;
	if (!obj_box.count(varname))
		return var(Error);
	value.type = obj_box.find(varname)->second->type;//must write like this???
	value.value = obj_box.find(varname)->second->value;
	return value;
}

bool obj_sys::set_var(const string& varname,void* value)
{
	if (!obj_box.count(varname))
		return false;
	obj_box.find(varname)->second->value = value;//set the value
	return true;
}


