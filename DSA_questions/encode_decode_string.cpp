#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

void print_arr(vector<string> &words) {
  for (auto s : words) {
    cout << s << " ";
  }
  cout << endl;
}
string encoding(vector<string> &words) {
  string result = "";
  for (auto s : words) {
    result += to_string(s.size()) + '#' + s;
  }
  return result;
}

vector<string> decode(string s) {
  vector<string> res;
  int i = 0;
  while (i < s.size()) {
    int j = i;
    while (s[j] != '#') {
      j++;
    }
    int length = stoi(s.substr(i, j - i));
    i = j + 1;
    j = i + length;
    res.push_back(s.substr(i, length));
    i = j;
  }
  return res;
}
int main() {
  vector<string> message = {"neet", "code", "loves", "you"};
  print_arr(message);
  string encoded_result = encoding(message);
  cout << encoded_result << endl;

  vector<string> decoded_result = decode(encoded_result);
  print_arr(decoded_result);
  return 0;
}
