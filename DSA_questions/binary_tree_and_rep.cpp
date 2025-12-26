#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>
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

// void printing_structure(Treenode *node) {}
int getheight(Treenode *node) {
  if (!node) {
    return 0;
  }
  return 1 + max(getheight(node->left), getheight(node->right));
}

void fillCanvas(vector<vector<string>> &canvas, Treenode *node, int row,
                int col, int height) {
  if (!node) {
    return;
  }
  // place node value
  canvas[row][col] = to_string(node->val);
  if (row + 1 >= canvas.size()) {
    return;
  }
  // calculate the spacing for the branches
  int gap = pow(2, (height - row - 2));
  if (node->left) {
    canvas[row + 1][col - gap / 2] = "|";
    for (int i = col - gap / 2 + 1; i < col; i++) {
      canvas[row + 1][i] = "-";
      fillCanvas(canvas, node->left, row + 2, col - gap, height);
    }
  }
  if (node->right) {
    // draw the connector logic
    canvas[row + 1][col + gap / 2] = "|";
    for (int i = col + 1; i < col + gap / 2; i++) {
      canvas[row + 1][i] = "-";
    };
    fillCanvas(canvas, node->right, row + 2, col + gap, height);
  }
};

void print_binary_tree(Treenode *head) {
  int n = getheight(head);
  if (n == 0)
    return;
  int rows = n * 2;
  int cols = pow(2, n) * 3;
  vector<vector<string>> canvas(rows, vector<string>(cols, " "));
  fillCanvas(canvas, head, 0, cols / 2, n);

  // print canvas
  for (const auto &row : canvas) {
    string line = "";
    for (const string &s : row) {
      line += s;
    }
    // trim trailing spaces for cleaners outputs
    line.erase(line.find_last_not_of(' ') + 1);
    if (!line.empty()) {
      cout << line << endl;
    }
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> inputs(n);
  for (int &x : inputs)
    cin >> x;
  Treenode *sol = tree(inputs, 1, n);
  print_binary_tree(sol);

  return 0;
}
