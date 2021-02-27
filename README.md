# zzh_interpreter

###a interpreter for a new lang

This lang will be an OO lang, and it will be like C++,Python,JavaScript and many other langs.
This interpreter is programmed by cpp

There may be lots of bugs in it and cannot support error processing well because now it's just at the beginning.

now support:
* int,bool,and float variables (use like "var a:int = 6;" to add a variable called "a",and we put a integer in it(type in the shell))
* var,const,and static variables (Well,these won't work before have "func,while,if" and many other things
* can give a value to the variables while adding them (int & float)(do not support true & false,0 & 1 may work for bool(I'm not sure))
* use: "get varname" to check a variable's value in the shell.For example,type "get var_a" to check var_a's value

will support:
* read codes from files
* if,for,while....
* func,class,user-defined types
* expression like:1+2
* import
* output & input
* better notes
