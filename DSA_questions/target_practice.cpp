#include "print_array.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

/*
 * observations:-

 * test case:-
    X.........
    ..........
    .......X..
    .....X....
    ......X...
    ..........
    .........X
    ..X.......
    ..........
    .........X
output:- 17
1+3+5+3+1+3+1=17
*/

int score[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1}, {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1}, {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1}, {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
int solution(vector<string> inputs) {
  int sum_value = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (inputs[i][j] == 'X') {
        sum_value += score[i][j];
      }
    }
  }
  return sum_value;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<string> inputs(10);
    for (string &x : inputs) {
      cin >> x;
    }
    cout << solution(inputs) << endl;
  }
}
