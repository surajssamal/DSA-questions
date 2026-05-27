#include "print_array.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class trie_node {
public:
  trie_node *children[26];
  int idx;
  int refr;
  trie_node() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    idx = -1, refr = 0;
  }

  void add_words(string &word, int i) {
    trie_node *curr = this;
    curr->refr++;
    for (int i = 0; i < word.size(); i++) {
      int index = word[i] - 'a';
      if (!curr->children[index]) {
        curr->children[index] = new trie_node();
      }
      curr = curr->children[index];
      curr->refr += 1;
    }
    curr->idx = i;
  }
};

class Solution {
public:
  vector<string> result;
  void dfs(vector<vector<char>> &board, vector<string> &words, int r, int c,
           trie_node *node) {

    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
        !node->children[board[r][c] - 'a'] || board[r][c] == '*' || !node) {
      return;
    }
    char temp = board[r][c];
    board[r][c] = '*';
    trie_node *prev = node;
    node = node->children[temp - 'a'];
    if (node->idx != -1) {
      result.push_back(words[node->idx]);
      node->idx = -1;
      node->refr -= 1;
      if (!node->refr) {
        prev->children[temp - 'a'] = nullptr;
        node = nullptr;
        board[r][c] = temp;
        return;
      }
    }

    // backtracking
    dfs(board, words, r + 1, c, node);
    dfs(board, words, r - 1, c, node);
    dfs(board, words, r, c + 1, node);
    dfs(board, words, r, c - 1, node);
    board[r][c] = temp;
  }
  vector<string> find_word(vector<vector<char>> board, vector<string> words) {
    trie_node *root = new trie_node();
    for (int i = 0; i < words.size(); i++) {
      root->add_words(words[i], i);
    }
    int rows = board.size(), cols = board[0].size();
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        dfs(board, words, r, c, root);
      }
    }
    return result;
  }
};

int main() {
  vector<vector<char>> board = {{'a', 'b', 'c', 'd'},
                                {'s', 'a', 'a', 't'},
                                {'a', 'c', 'k', 'e'},
                                {'a', 'c', 'd', 'n'}};
  vector<string> words = {"bat", "cat", "back", "backend", "stack"};
  Solution *hello = new Solution();
  vector<string> result = hello->find_word(board, words);
  print_container(result);
}
