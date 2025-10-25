#include <bits/stdc++.h>
using namespace std;

int len_longest_substring(string input) {
  set<char> charSet;
  int left = 0;
  int result = 0;

  for (int i = 0; i < input.size(); i++) {
    while (charSet.find(input[i]) != charSet.end()) {
      charSet.erase(input[left]);
      left++;
    }
    charSet.insert(input[i]);
    result = max(result, i - left + 1);
  }
  return result;
}

int main() {

  string input_1 = "bbbbbb";
  cout << len_longest_substring(input_1) << endl;
  return 0;
}
