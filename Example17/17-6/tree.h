/*二叉搜索树模块的接口*/
#define TREE_TYPE int /*树的值类型*/

/*
**print
**打印节点中的值
*/
void print(TREE_TYPE value);

/*
** insert
** 向树添加一个新值。参数是需要被添加的值，它必须原先并不存在于树中。
*/
void insert(TREE_TYPE value);

/*
** find
** 查找一个特定的值，这个值作为第1个参数传递给函数
*/
TREE_TYPE* find(TREE_TYPE valie);

/*
** pre_order_traverse
** 执行数的前序遍历。它的参数是一个回调函数指针，它所指向的函数将在树中处理每
** 个节点被调用，节点的值作为参数传递给这个函数
*/
void pre_order_traverse(void(*callback)(TREE_TYPE value));

/*
**breadth_first_traversal
**对一个数组形式的二叉搜索树执行层次遍历
*/
void breadth_first_traversal(void(*callback)(TREE_TYPE value));