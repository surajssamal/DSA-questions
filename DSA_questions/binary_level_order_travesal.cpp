#include "binary_tree.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <csignal>
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
// brute force approach
int layers(TreeNode *node) {
  if (!node) {
    return 0;
  }
  return 1 + max(layers(node->left), layers(node->right));
}

// brute force approach {bad}
vector<vector<int>> levelOrder(TreeNode *node) {
  if (!node) {
    return {};
  }
  int layer_num = layers(node);
  vector<vector<int>> result;
  vector<TreeNode *> node_addr;
  node_addr.push_back(node);
  int counter = 0;
  while (counter < layer_num) {
    vector<int> temp_vec;
    vector<TreeNode *> temp_addr2;
    for (int i = 0; i < node_addr.size(); i++) {
      temp_vec.push_back(node_addr[i]->val);
      temp_addr2.push_back(node_addr[i]->left);
      temp_addr2.push_back(node_addr[i]->right);
    }
    result.push_back(temp_vec);
    node_addr.erase(node_addr.begin(), node_addr.end());
    node_addr = temp_addr2;
    counter += 1;
  }
  return result;
}

// hint approach

void travesal(TreeNode *node, int i, vector<vector<int>> &res) {
  if (!node) {
    return;
  }
  travesal(node->left, i + 1, res);
  travesal(node->right, i + 1, res);
  res[i].push_back(node->val);
}

vector<vector<int>> hint_sol(TreeNode *node) {
  int n = layers(node);
  vector<vector<int>> result(n);
  travesal(node, 0, result);
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
    // vector<vector<int>> sol = solution(root);
    vector<vector<int>> sol = hint_sol(root);
    for (auto x : sol) {
      for (int y : x) {
        cout << y << " ";
      }
      cout << endl;
    }
  }
}

/*
1
7
1 2 3 4 5 6 7
9
1 2 3 4 5 6 7 8 9
5
3 4 1 5 6
*/
