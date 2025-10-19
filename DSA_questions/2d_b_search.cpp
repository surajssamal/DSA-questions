#include "print_array.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int multi_dimension_binary_search(vector<vector<int>> &input, int target) {
  int rows = input.size(), columns = input[0].size();
  int top = 0, bottom = rows - 1;
  while (top <= bottom) {
    int mid = (top + bottom) / 2;
    if (input[mid][0] > target) {
      bottom = mid - 1;
    } else if (input[mid][columns - 1] < target) {
      top = mid + 1;
    } else {
      top = mid;
      break;
    }
  }
  print_container(input[top]);
  if (!(top <= bottom))
    return false;
  int l = 0, r = columns - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (input[top][mid] == target) {
      return true;
    } else if (input[top][mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> input_1 = {
      {1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
  cout << multi_dimension_binary_search(input_1, 122) << endl;
  return 0;
}
