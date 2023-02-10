/*二叉树搜索模块的接口*/
#define TREE_TYPE int 

/*TreeNode结构包含了值和两个指向某个树节点的指针*/
typedef struct TREE_NODE {
  TREE_TYPE value;
  struct TREE_NODE* left;
  struct TREE_NODE* right;
}TreeNode;

/*
**print
**打印数组中的某个值
*/
void print(TREE_TYPE value);

/*
**insert
**向树添加一个新值。参数是需要被添加的值，它必须原先不存在于树中。
*/
void insert(TREE_TYPE value);

/*
**find
**查找一个特定值，这个值作为第1个参数传递给函数
*/
TREE_TYPE* find(TREE_TYPE value);

/*
**find_2
**查找一个特定值，这个值作为第1个参数传递给函数
*/
TreeNode* find_2(TREE_TYPE value);

/*
**destroy_tree
**删除树中单个的节点
*/
void destroy_tree(TREE_TYPE value);

/*
**pre_order_traverse
**执行树的前序遍历。它的参数是一个回调函数指针，它所指向的函数将在树中处理每个节点时被
**调用，节点的值作为参数传递给这个函数。
*/
void pre_order_traverse(void(*callback)(TREE_TYPE value));

/*
**in_order_traverse
**执行树的中序遍历。它的参数是回调函数指针，它所指向的函数将在树中处理每个节点时被
**调用，节点的值作为参数传递给这个函数
*/
void in_order_traverse(void(*callback)(TREE_TYPE value));

/*
**post_order_traverse
**执行树的后序遍历。它的参数时回调函数指针，它所指向的函数将在树中处理每个节点时被
**调用，节点的值作为参数传递给这个函数
*/
void post_order_traverse(void(*callback)(TREE_TYPE value));

/*毁掉整棵树*/
void destroy_tree_2();