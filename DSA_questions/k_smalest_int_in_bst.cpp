#include "binary_tree.h"
#include "print_array.h"
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

vector<int> arr;
void solution(Treenode *node) {
  if (!node) {
    return;
  }
  arr.push_back(node->val);
  solution(node->left);
  solution(node->right);
}
int kthsmallest(Treenode *node, int k) {
  solution(node);
  print_container(arr);
  return arr[k - 1];
}

int main() {
  int k;
  cin >> k;
  while (k-- > 0) {
    int n, m;
    cin >> n >> m;
    vector<int> inputs(n);
    for (int &x : inputs) {
      cin >> x;
    }
    Treenode *root = make_tree<Treenode, vector<int>>(inputs, 1, n);
    int c = kthsmallest(root, m);
    arr.clear();
    cout << c << endl;
  }
}
