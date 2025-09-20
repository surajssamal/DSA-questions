#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

void print_vector(vector<int> &vec) {
  for (auto r : vec) {
    cout << r << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr = {
      1, 2, 3, 4, 2, 3, 2, 2, 5,
  };

  print_vector(arr);
  unordered_map<int, int> unir_arr;
  for (auto num : arr) {
    unir_arr[num]++;
  }
  vector<pair<int, int>> pair_arr;
  for (auto r : unir_arr) {
    pair_arr.push_back({r.second, r.first});
  }
  sort(pair_arr.rbegin(), pair_arr.rend());

  int k = 3;
  vector<int> result;
  for (int i = 0; i < k; i++) {
    result.push_back(pair_arr[i].second);
  }
  for (auto r : result) {
    cout << r;
    cout << endl;
  }
  return 0;
}
