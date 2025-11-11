#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct bt {
  int p;
  struct bt *left;
  struct bt *right;
};

// a structure of the binary tree
bt *insearting_elements(int &num) {
  bt *node = new bt;
  node->p = num;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void delete_tree(bt *node) {
  if (node == nullptr) {
    return;
  }
  delete_tree(node->left);
  delete_tree(node->right);
  delete node;
}

// printing array
void printing_vector(vector<bt *> &vec) {
  for (auto s : vec) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  vector<int> some = {1, 2, 3, 4, 5, 6, 10, 11};
  bt *root = insearting_elements(some[0]);
  vector<bt *> bt_pointer;
  bt_pointer.push_back(root);
  int counter = 1;
  while (counter < some.size()) {
    int bt_size = bt_pointer.size();
    vector<bt *> bt_pointer_next;
    for (int j = 0; j < bt_size; j++) {
      bt *node = insearting_elements(some[counter]);
      bt *node2 = insearting_elements(some[counter + 1]);
      bt_pointer[j]->left = node;
      bt_pointer[j]->right = node2;
      bt_pointer_next.push_back(node);
      bt_pointer_next.push_back(node2);
      counter += 2;
    }
    printing_vector(bt_pointer);
    bt_pointer.erase(bt_pointer.begin(), bt_pointer.end());
    bt_pointer = bt_pointer_next;
  }
  cout << root->left->p << " " << root->right->p << endl;
  cout << root->left->left->p << " " << root->left->right->p << endl;
  cout << root->right->left->p << " " << root->right->right->p << endl;
  delete_tree(root);
  return 0;
}
