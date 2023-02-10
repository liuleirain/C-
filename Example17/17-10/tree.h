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
**向树添加一个新值。参数使需要被添加的值，它必须原先不存在于树中。
*/
void insert(TREE_TYPE value);

/*
**find
**查找一个特定值，这个值作为第1个参数传递给函数。
*/
TREE_TYPE* find(TREE_TYPE value);

/*
**find_2
**查找一个特定值，这个值作为第1个参数传递给函数。
*/
TreeNode* find_2(TREE_TYPE value);

/*
**find_3
**查找一个特定值的双亲节点，参数值为儿子节点当前的值作为第1个参数传递给函数。
*/
TreeNode* find_3(TREE_TYPE value);

/*
**pre_order_traverse
**执行树的前序遍历。它的参数使一个回调函数指针，它所指向的函数将在树中处理每个节点时被
**调用，节点的值作为参数传递给这个函数。
*/
void pre_order_traverse(void(*callback)(TREE_TYPE value));

/*
**delete_value
**从树中删除一个值，如果需要删除的值并未在树中找到，函数可以终止程序。
*/
void delete_value(TREE_TYPE value);

/*从链接二叉搜索树中删除一个节点*/
void delete(TREE_TYPE value);