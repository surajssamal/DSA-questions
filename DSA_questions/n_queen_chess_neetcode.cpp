#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

/*
problem statemet
:- we're give an input int n and which are the square dimensions of a chess
board we have to answer how many queens we can put on the chess board so that
the queens dont eliminate each other i.e there should be no other queens on a
already exisiting queens path
queen paths consists  of horizontal,vertical,diagonal directions

*/
bool isSafe(int r, int c, vector<string> &board) {
  for (int i = r - 1; i >= 0; i--) {
    if (board[i][c] == 'Q')
      return false;
  }
  for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q')
      return false;
  }
  for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
    if (board[i][j] == 'Q')
      return false;
  }
  return true;
}

void backtracking(int r, vector<string> &board,
                  vector<vector<string>> &result) {
  if (r == board.size()) {
    result.push_back(board);
    return;
  }
  for (int c = 0; c < board.size(); c++) {
    if (isSafe(r, c, board)) {
      board[r][c] = 'Q';
      backtracking(r + 1, board, result);
      board[r][c] = '.';
    }
  }
}
vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> result;
  vector<string> board(n, string(n, '.'));
  backtracking(0, board, result);
  return result;
};

int main() {
  int n;
  cin >> n;
  vector<vector<string>> result = solveNQueens(n);
  for (vector<string> &x : result) {
    for (string &n : x) {
      cout << n << endl;
    }
    cout << endl;
  }
}
