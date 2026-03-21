#include <bits/stdc++.h>
#include <string>
using namespace std;

class trie_node {
public:
  trie_node *children[26];
  bool lastelem;
  trie_node() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    lastelem = false;
  }
};

class Prefixtree {
  trie_node *root;

public:
  Prefixtree() { root = new trie_node(); };
  void insert(string word) {
    trie_node *curr = root;
    for (char c : word) {
      int i = c = 'a';
      if (curr->children[i] == nullptr) {
        curr->children[i] = new trie_node();
      }
      curr = curr->children[i];
    }
    curr->lastelem = true;
  };

  bool search(string word) {
    trie_node *curr = root;
    for (char c : word) {
      int i = c = 'a';
      if (curr->children[i] == nullptr) {
        return false;
      }
      curr = curr->children[i];
    }
    return curr->lastelem;
  }

  bool startsWith(string prefix) {
    trie_node *curr = root;
    for (char c : prefix) {
      int i = c = 'a';
      if (curr->children[i] == nullptr) {
        return false;
      }
      curr = curr->children[i];
    }
    return true;
  }
};

int main() {
  Prefixtree something;
  something.insert("hello");
  something.insert("night");
  something.insert("kite");
  cout << something.search("light") << endl;
  cout << something.search("kite") << endl;
  cout << something.startsWith("kit") << endl;
}
