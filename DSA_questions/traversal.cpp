#include "binary_tree.h"
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l) : val(x), left(l), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

void preorder_trav(TreeNode *node) {
  if (!node) {
    return;
  }
  preorder_trav(node->left);
  preorder_trav(node->right);
  cout << node->val << " ";
}
void inorder_trav(TreeNode *node) {
  if (!node) {
    return;
  }
  cout << node->val << " ";
  inorder_trav(node->left);
  inorder_trav(node->right);
}
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    vector<int> inputs(n);
    for (int &x : inputs) {
      cin >> x;
    }
    TreeNode *root = make_tree<TreeNode, vector<int>>(inputs, 1, n);
    cout << "in-order traversal " << k << " ";
    inorder_trav(root);
    cout << endl;
    cout << "preorder traversal " << k << " ";
    preorder_trav(root);
    cout << endl;
  }
  return 0;
}
