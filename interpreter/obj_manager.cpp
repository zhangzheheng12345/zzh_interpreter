#include "obj_manager.h"
#include <string>
#include <map>

#include <iostream>//only for debug

void obj_sys::add_var(const string& varname,var_ts type)//add a new var
{
	switch (type)//different var_types
	{
	case Int:
		obj_box.insert(pair<string, var*>(varname, new var(Int)));
		break;
	case Float:
		obj_box.insert(pair<string,var*>(varname, new var(Float)));
		break;
	case String:
		obj_box.insert(pair<string, var*>(varname, new var(String)));
		break;
	default:
		break;
	}
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


