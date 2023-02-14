/*
**va_list
**为一个保存一个指向参数列表可变部分的指针的变量进行类型定义。这里使用的
**char*,因为作用于它们之上的运算并没有经过调整。
*/
typedef char* va_list;

/*
**va_start
**用于初始化一个va_list变量宏，使它指向堆栈中第1个可变参数。
*/
#define va_start(arg_ptr, arg) arg_ptr = (char*)&arg + sizeof(arg)

/*
**va_arg
**用于返回堆栈中下一个变量值的宏，它同时增加arg_ptr的值，使它指向下一个参数。
*/
#define va_arg(arg_ptr, type) *((type*)arg_ptr)++

/*
**va_end
**在可变参数最后的访问之后调用。在这个环境中，它不需要指向任何任务。
*/
#define va_end(arg_ptr)