#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
class solution_for_prob {
private:
  int rows, cols;
  set<pair<int, int>> check;

public:
  bool solution(vector<vector<char>> &board, string word, int i, int j, int k) {
    if (k == word.length()) {
      return true;
    }
    if (i >= rows || j >= cols || i < 0 || j < 0 || check.count({i, j}) ||
        board[i][j] != word[k]) {
      return false;
    }
    check.insert({i, j});
    bool result = solution(board, word, i + 1, j, k + 1) ||
                  solution(board, word, i - 1, j, k + 1) ||
                  solution(board, word, i, j + 1, k + 1) ||
                  solution(board, word, i, j - 1, k + 1) || check.erase({i, j});

    check.erase({i, j});
    return result;
  }

  bool exist(vector<vector<char>> &board, string word) {
    rows = board.size();
    cols = board.size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (solution(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  };
};
int main() {
  int l;
  cin >> l;
  while (l--) {

    int n;
    string word;
    cin >> n;
    cin >> word;
    vector<vector<char>> board(n, vector<char>(n));
    for (vector<char> &x : board) {
      for (char &i : x) {
        cin >> i;
      }
    };
    solution_for_prob k;
    cout << k.exist(board, word) << endl;
  }
}
