#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Treenode {
  int val;
  Treenode *left;
  Treenode *right;
  Treenode() : val(0), left(nullptr), right(nullptr) {}
  Treenode(int x) : val(x), left(nullptr), right(nullptr) {}
  Treenode(int x, Treenode *l) : val(x), left(l), right(nullptr) {}
  Treenode(int x, Treenode *l, Treenode *r) : val(x), left(l), right(r) {}
};
Treenode *tree(vector<int> &inputs, int i, int n) {

  if (i > n) {
    return nullptr;
  }
  Treenode *head = new Treenode(inputs[i - 1]);
  head->left = tree(inputs, 2 * i, n);
  head->right = tree(inputs, 2 * i + 1, n);
  return head;
}
int dfs(Treenode *root, int &k) {
  if (!root) {
    return 0;
  }
  int left = dfs(root->left, k);
  int right = dfs(root->right, k);
  k = max(k, left + right);
  return 1 + max(left, right);
}
int solution(Treenode *node) {
  int res = 0;
  dfs(node, res);
  return res;
};
int main() {
  int n;
  cin >> n;
  vector<int> inputs(n);
  for (int &x : inputs) {
    cin >> x;
  }
  Treenode *node = tree(inputs, 1, n);
  cout << solution(node) << endl;
}
