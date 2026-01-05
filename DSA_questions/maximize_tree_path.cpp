#include "binary_tree.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
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

int dfs(TreeNode *node, int &k) {
  if (!node) {
    return 0;
  }
  int leftmax = max(dfs(node->left, k), 0);
  int rightmax = max(dfs(node->right, k), 0);
  k = max(leftmax + rightmax + node->val, k);
  return node->val + max(leftmax, rightmax);
}

int solution(TreeNode *node) {
  int k = node->val;
  dfs(node, k);
  return k;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> inputs(k);
    for (int &x : inputs) {
      cin >> x;
    }
    TreeNode *root = make_tree<TreeNode, vector<int>>(inputs, 1, k);
    int sol = solution(root);
    cout << sol << endl;
  }
}

/*
 *inputs

5
3
2 1 3
3
1 2 3
5
4 3 5 2 -1
7
1 2 3 4 5 6 7
8
-15 10 20 -1 -1 15 5 -5
*/
