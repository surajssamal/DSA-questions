#include <bits/stdc++.h>
#include <vector>
using namespace std;
class TreeNode {
public:
  vector<TreeNode *> children;
  bool word;
  TreeNode() {
    children.assign(26, nullptr);
    word = false;
  }
};

class WordDictionary {
  TreeNode *root;

public:
  WordDictionary() { root = new TreeNode(); };
  void addWord(string word) {
    TreeNode *curr = root;
    for (char c : word) {
      if (curr->children[c - 'a'] == nullptr) {
        curr->children[c - 'a'] = new TreeNode();
      }
      curr = curr->children[c - 'a'];
    }
    curr->word = true;
  };
  bool search(string word) { return dfs(word, 0, root); };

private:
  bool dfs(string word, int i, TreeNode *root) {
    TreeNode *curr = root;
    for (int k = i; k < (int)word.size(); k++) {
      char c = word[k];
      if (c == '.') {
        for (TreeNode *child : curr->children) {
          if (child != nullptr && dfs(word, k + 1, child)) {
            return true;
          }
        }
        return false;
      } else {
        if (curr->children[c - 'a'] == nullptr) {
          return false;
        }
        curr = curr->children[c - 'a'];
      }
    }
    return curr->word;
  };
};

int main() {
  WordDictionary something;
  something.addWord("hello");
  something.addWord("body");
  cout << something.search(".ody") << endl;
  cout << something.search(".od.") << endl;
  cout << something.search("hell.") << endl;
  return 0;
}
