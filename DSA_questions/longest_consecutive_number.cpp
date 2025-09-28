#include "print_array.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// so before we go on i want to explain what the problem is
// given an array lets say [2,20,4,10,3,4,5] in this we can see numbers are
// being incremented not consecutively/(array sequese wise) like 2,3,4,5 which
// are just increment of +1 so the return shoulbe the frequency of these numbers
// this case its 4 another example
//[0,3,2,5,4,6,1,1] the answer is 7 since the frequncy of inncremnt values are :
//- [0,1,2,3,4,5,6]

int brute_force(vector<int> &arr) {
  unordered_set<int> set_arr(arr.begin(), arr.end());
  int res = 0;
  for (auto s : set_arr) {
    int streak = 0, current = s;
    while (set_arr.find(current) != set_arr.end()) {
      current += 1;
      streak += 1;
    }
    res = max(streak, res);
  }
  return res;
}
int sorting_method(vector<int> &arr) {
  if (arr.size() == 0) {
    return 0;
  };
  int res = 0;
  int streak = 0, current = arr[0], i = 0;
  sort(arr.begin(), arr.end());
  while (i < arr.size()) {
    if (arr[i] != current) {
      current = arr[i];
      streak = 0;
    }
    while (arr[i] == current) {
      i++;
    }
    current += 1;
    streak += 1;
    res = max(res, streak);
  }
  return res;
}

int hashset_method(vector<int> &arr) {
  int res = 0;
  unordered_set<int> arr_set(arr.begin(), arr.end());
  for (auto n : arr_set) {
    if (arr_set.find(n - 1) == arr_set.end()) {
      int length = 0;
      while (arr_set.find(n + length) != arr_set.end()) {
        length += 1;
      }
      res = max(res, length);
    }
  }
  return res;
}

int main() {
  vector<int> arr = {2, 20, 4, 10, 3, 4, 6};

  cout << brute_force(arr) << endl;
  cout << sorting_method(arr) << endl;
  cout << hashset_method(arr) << endl;

  return 0;
}
