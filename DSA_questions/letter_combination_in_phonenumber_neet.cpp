#include <bits/stdc++.h>
using namespace std;

vector<string> digitToChar = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solution(vector<string> &result, string temp, string digits, int i) {
  if (temp.size() == digits.size()) {
    result.push_back(temp);
    return;
  }
  string chars = digitToChar[digits[i] - '0'];
  for (char &c : chars) {
    solution(result, temp + c, digits, i + 1);
  }
}

vector<string> letter_combination(string n) {
  vector<string> result;
  if (n.empty()) {
    return result;
  }
  solution(result, "", n, 0);
  return result;
}

int main() {
  string input;
  cin >> input;
  vector<string> result = letter_combination(input);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
};
