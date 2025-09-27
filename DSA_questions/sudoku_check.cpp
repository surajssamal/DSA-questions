#include <bits/stdc++.h>
#include <utility>
using namespace std;

bool sudoku_check(char inp[9][9]) {
  map<int, set<char>> rows;
  map<int, set<char>> cols;
  map<pair<int, int>, set<int>> squares;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (inp[i][j] == '.') {
        continue;
      };
      pair<int, int> squarKey = {i / 3, j / 3};
      if (rows[i].count(inp[i][j]) || cols[j].count(inp[i][j]) ||
          squares[squarKey].count(inp[i][j])) {
        return false;
      };
      rows[i].insert(inp[i][j]);
      cols[j].insert(inp[i][j]);
      squares[squarKey].insert(inp[i][j]);
    }
  }
  return true;
};
int main() {

  char inp[9][9] = {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
                    {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
                    {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
                    {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
                    {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                    {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
                    {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  char inp2[9][9] = {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
                     {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
                     {'.', '9', '1', '.', '.', '.', '.', '.', '3'},
                     {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
                     {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
                     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
                     {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << inp[i][j] << "  ";
    }
    cout << endl;
  }
  cout << sudoku_check(inp2) << endl;

  return 0;
}
