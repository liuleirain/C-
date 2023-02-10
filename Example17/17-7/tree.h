/*二叉搜索树模块的接口*/
#define TREE_TYPE int /*树值的类型*/
#define TRUE 1
#define FALSE 0

/*TreeNode结构包含了值和两个指向莫个树节点的指针*/
typedef struct TREE_NODE {
  TREE_TYPE value;
  struct TREE_NODE* left;
  struct TREE_NODE* right;
}TreeNode;

/*
** print
** 打印数组中的某个值。
*/
void print(TREE_TYPE value);

/*
** insert
** 向树添加一个新值。参数是需要被添加的值
*/
void insert(TREE_TYPE value);

/*
** find
** 查找一个特定值，这个值作为第1个参数传递给函数
*/
TREE_TYPE* find(TREE_TYPE value);

/*
** compare_tree_type
** 判断值的大小。
*/
int compare_tree_type(TREE_TYPE value, TREE_TYPE value2);

/*
**judge_binary_search_node
**判断该节点附近是否符合二叉搜索树的要求。
*/
int judge_binary_search_node(TreeNode* current, int (*compare)(TREE_TYPE value, TREE_TYPE value2));

/*
**judge_binary_search_tree
**判断该树是否是二叉搜索树。
*/
int judge_binary_search_tree(int(*compare)(TREE_TYPE value, TREE_TYPE value2));

/*
**destroy_tree
**删除树中单个节点
*/
void destroy_tree(TREE_TYPE value);

/*
**pre_order_traverse
**执行树的前序遍历。它的参数是一个回调函数指针，它所指向的函数将在树中处理每个节点时被
**调用，节点的值作为参数传递给这个函数。
*/
void pre_order_traverse(void(*callback)(TREE_TYPE value));

/*
** post_order_traverse
**执行数的后续遍历。它的参数使一个回调函数指针，它所指向的函数将在树中处理每个节点使被
**调用，节点的值作为参数传递给这个函数
*/
void post_order_traverse(void(*callback)(TREE_TYPE value));

/*
** 检查一个链接二叉搜索树的有效性
** 这个助手函数使用从调用方传入的最小值和最大值来检查一个节点的有效性
*/
int check_bst_subtree(TreeNode* node, int min, int max);
int check_bst_tree();