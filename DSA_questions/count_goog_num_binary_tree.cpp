#include "binary_tree.h"
#include <algorithm>
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
int dfs(TreeNode *node, int max_num) {
  if (!node) {
    return 0;
  }
  int res = (node->val >= max_num) ? 1 : 0;
  max_num = max(node->val, max_num);
  res += dfs(node->left, max_num);
  res += dfs(node->right, max_num);
  return res;
};
int solution(TreeNode *root) {
  int result = dfs(root, root->val);
  return result;
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
    solution(root);
    cout << n << endl;
  }
}
/*
 * inputs
2
6
2 1 1 3 -1 1 5
5
1 2 0 3 4
*/
