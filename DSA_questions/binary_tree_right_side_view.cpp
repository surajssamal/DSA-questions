#include "binary_tree.h"
#include "print_array.h"
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

void solution(TreeNode *root, vector<int> &res, int depth) {
  if (!root) {
    return;
  }
  if (depth == res.size()) {
    res.push_back(root->val);
  }
  solution(root->left, res, depth + 1);
  solution(root->right, res, depth + 1);
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
    vector<int> result;
    solution(root, result, 0);
    print_container(result);
  }
}
