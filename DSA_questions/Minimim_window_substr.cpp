#include "print_array.h"
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
  vector<int> s_map(26, 0);
  vector<int> t_map(26, 0);
  bool capital = true ? s[0] - 'a' < 0 : false;
  for (auto &c : s) {
    c = tolower(c);
  }
  for (auto &c : t) {
    c = tolower(c);
  }
  for (int i = 0; i < t.size(); i++) {
    t_map[t[i] - 'a'] += 1;
  }
  int matches = 0;
  bool start = false;
  vector<vector<int>> result;
  int left = 0, right = 0;
  while (right < s.size()) {
    if (matches == t.size()) {
      result.push_back({left, right});
      matches = 0;
      s_map[s[left] - 'a']--;
      left += 1;
    }
    // right portion
    int index = s[right] - 'a';
    s_map[index] += 1;
    if (s_map[index] == t_map[index]) {
      matches += 1;
    }

    index = s[left] - 'a';
    s_map[index] -= 1;
    if (s_map[index] == t_map[index]) {
      left += 1;
    }
  }
  return "some";
}

string leet_way(string s, string t) {
  if (t.empty()) {
    return "";
  }
  unordered_map<char, int> s_map;
  unordered_map<char, int> t_map;
  for (auto c : t) {
    t_map[c] += 1;
  }
  int need = t_map.size(), have = 0;
  pair<int, int> result = {-1, -1};
  int min_lenth = INT_MAX;
  int left = 0;
  for (int right = 0; right < s.size(); right++) {
    char index = s[right];
    s_map[index] += 1;
    if (t_map.count(index) && s_map[index] == t_map[index]) {
      have += 1;
    }
    while (have == need) {
      if ((right - left + 1) < min_lenth) {
        result = {left, right};
        min_lenth = right - left + 1;
      }
      index = s[left];
      s_map[index] -= 1;
      if (t_map.count(index) && s_map[index] < t_map[index]) {
        have -= 1;
      }
      left += 1;
    }
  }
  int l = result.first, r = result.second + 1;
  string res = "";
  for (int i = l; i < r; i++) {
    res += s[i];
  }
  return res;
}
int main() {
  string s = "OUZODYXAZV";
  string t = "XYZ";
  // cout << minWindow(s, t) << endl;
  cout << leet_way(s, t) << endl;
  return 0;
}
