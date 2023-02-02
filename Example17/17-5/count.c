/*计算链接二叉搜索树的节点数。*/
/*这个helper函数以我们当前处理的树的根作为参数*/
int count_nodes(TreeNode* tree) {
  if (tree == NULL) return 0;
  return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

int number_of_nodes() {
  return count_nodes(tree);
}