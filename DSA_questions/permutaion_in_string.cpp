#include "print_array.h"
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
bool checkInclusion_bruteforce(string s_1, string s_2) {
  sort(s_1.begin(), s_1.end());
  for (int i = 0; i < s_2.size(); i++) {
    for (int j = i; j < s_2.size(); j++) {
      string substr = s_2.substr(i, j - i + 1);
      sort(substr.begin(), substr.end());
      if (substr == s_1) {
        return true;
      }
    }
  }
  return false;
}
bool checkInclusion_myway(string s_1, string s_2) {
  unordered_map<char, int> s_1_map;
  for (auto &s : s_1) {
    s_1_map[s] += 1;
  }
  int need = s_1_map.size();
  for (int i = 0; i < s_2.size(); i++) {
    unordered_map<char, int> s_2_map;
    int cur = 0;
    for (int j = i; j < s_2.size(); j++) {
      s_2_map[s_2[j]] += 1;
      if (s_2_map[s_2[j]] == s_1_map[s_2[j]]) {
        cur++;
      }
      if (s_2_map[s_2[j]] > s_1_map[s_2[j]]) {
        break;
      }
      if (cur == need) {
        return true;
      }
    }
  }
  return false;
}
bool checkInclusion_optimal(string s1, string s2) {
  vector<int> s1_map(26, 0);
  vector<int> s2_map(26, 0);
  for (int i = 0; i < s1.size(); i++) {
    s1_map[s1[i] - 'a'] += 1;
    s2_map[s2[i] - 'a'] += 1;
  }
  int matches = 0;
  for (int i = 0; i < 26; i++) {
    if (s1_map[i] == s2_map[i]) {
      matches += 1;
    }
  }
  int left = 0;
  for (int right = s1.size(); right < s2.size(); right++) {
    if (matches == 26) {
      return true;
    }
    int index = s2[right] - 'a';
    s2_map[index] += 1;
    if (s1_map[index] == s2_map[index]) {
      matches += 1;
    } else if (s1_map[index] + 1 == s2_map[index]) {
      matches -= 1;
    }

    index = s2[left] - 'a';
    s2_map[index] -= 1;
    if (s1_map[index] == s2_map[index]) {
      matches += 1;
    } else if (s1_map[index] - 1 == s2_map[index]) {
      matches -= 1;
    }
    left++;
  }
  return matches == 26;
};

int main() {
  string s_1 = "abc";
  string s_2 = "lbecabee";
  cout << checkInclusion_bruteforce(s_1, s_2) << endl;
  cout << checkInclusion_myway(s_1, s_2) << endl;
  cout << checkInclusion_optimal(s_1, s_2) << endl;
  return 0;
}
