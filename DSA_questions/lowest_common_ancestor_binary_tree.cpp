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

TreeNode *solution(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (!root) {
    return nullptr;
  }
  if (root->val > p->val && root->val > q->val) {
    return solution(root->left, p, q);
  } else if (root->val < p->val && root->val < q->val) {
    return solution(root->right, p, q);
  } else {
    return root;
  }
}
TreeNode *find_p_q(int a, TreeNode *node) {
  if (!node) {
    return nullptr;
  }
  if (node->val == a) {
    return node;
  }
  if (node->val > a) {
    return find_p_q(a, node->left);
  } else {
    return find_p_q(a, node->right);
  }
};
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int n, p_int, q_int;
    cin >> n >> p_int >> q_int;
    vector<int> input(n);
    for (int &x : input) {
      cin >> x;
    }
    TreeNode *root = make_tree<TreeNode, vector<int>>(input, 1, n);
    TreeNode *p = find_p_q(p_int, root);
    TreeNode *q = find_p_q(q_int, root);
    TreeNode *sol = solution(root, p, q);
    cout << sol->val << endl;
  }
}

/*
 * inputs
9 3 8
5 3 8 1 4 7 9 -1 2
9 3 4
5 3 8 1 4 7 9 -1 2
9 2 4
5 3 8 1 4 7 9 -1 2
*/

//     5
//   3   8
// 1 4   7 9
//   2
