#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> something(vector<string> &strs) {
  unordered_map<string, vector<string>> res;
  for (auto s : strs) {
    vector<int> count(26, 0);
    for (auto cha : s) {
      count[cha - 'a']++;
    }
    string key = to_string(count[0]);
    for (int i = 1; i < 26; i++) {
      key += "," + to_string(count[i]);
    }
    res[key].push_back(s);
  }
  vector<vector<string>> result;
  for (auto pairs : res) {
    result.push_back(pairs.second);
  }
  return result;
};

int main() {
  vector<string> arr = {"act", "pots", "tops", "cat", "stop", "hat"};
  // for (auto s : arr) {
  //   cout << s << endl;
  // }
  vector<vector<string>> some = something(arr);
  for (auto p : some) {
    for (auto k : p) {
      cout << k << " ";
    }
    cout << endl;
  }
  return 0;
}
