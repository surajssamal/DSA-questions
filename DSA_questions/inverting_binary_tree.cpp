
#include <bits/stdc++.h>
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

;
Treenode *tree(vector<int> &inputs, int i, int n) {

  if (i > n) {
    return nullptr;
  }
  Treenode *head = new Treenode(inputs[i - 1]);
  head->left = tree(inputs, 2 * i, n);
  head->right = tree(inputs, 2 * i + 1, n);
  return head;
}

void solution(Treenode *node) {
  if (!node) {
    return;
  }
  swap(node->left, node->right);
  solution(node->left);
  solution(node->right);
};

int main() {
  int n;
  cin >> n;
  vector<int> inputs(n);
  for (int &x : inputs)
    cin >> x;
  Treenode *sol = tree(inputs, 1, n);
  solution(sol);
  cout << sol->left->left->val << endl;
  return 0;
}
