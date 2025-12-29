#include "binary_tree.h"
#include <bits/stdc++.h>
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

bool check_tree(TreeNode *node1, TreeNode *node2) {
  if (!node1 && !node2) {
    return 1;
  }
  if (!node1 || !node2) {
    return 0;
  };
  if (node1->val != node2->val) {
    return 0;
  }
  bool left = check_tree(node1->left, node2->left);
  bool right = check_tree(node1->right, node2->right);
  return left && right;
};

int main() {
  int no_case;
  cin >> no_case;
  for (int i = 0; i < no_case; i++) {
    int n;
    cin >> n;
    vector<int> inputs(n);
    for (int &x : inputs) {
      cin >> x;
    }
    vector<int> inputs2(n);
    for (int &x : inputs2) {
      cin >> x;
    }
    TreeNode *node1 = make_tree<TreeNode, vector<int>>(inputs, 1, n);
    TreeNode *node2 = make_tree<TreeNode, vector<int>>(inputs2, 1, n);
    cout << check_tree(node1, node2) << endl;
  }
  return 0;
}
