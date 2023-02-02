#define TREE_TYPE int

typedef struct TREE_NODE {
  TREE_TYPE value;
  struct TREE_NODE* left;
  struct TREE_NODE* right;
}TreeNode;

void print(TREE_TYPE value);

void insert(TREE_TYPE value);

TREE_TYPE* find(TREE_TYPE value);

TreeNode* find_2(TREE_TYPE value);

void destroy_tree(TREE_TYPE value);

static int pre_order_counter_node_number(TreeNode* current, TREE_TYPE* (*callback)(TREE_TYPE value));

int counter_all_nodes_number(TREE_TYPE* (*callback)(TREE_TYPE value));

void pre_order_traverse(void(*callback)(TREE_TYPE value));

void in_order_traverse(void(*callback)(TREE_TYPE value));

void post_order_traverse(void(*callback)(TREE_TYPE value));