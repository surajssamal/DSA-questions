#include <bits/stdc++.h>
#include <cctype>
#include <string>
using namespace std;

bool ispalandrome(string &text) {
  string some = "";
  for (char s : text) {
    if (isalnum(s)) {
      some += tolower(s);
    }
  }
  string reverse(some.rbegin(), some.rend());
  return reverse == some;
}
bool pointer_template(char c) {
  return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
};
bool two_pointer_methof(string &text) {
  int l = 0, r = text.size() - 1;
  while (l < r) {
    while (l < r && !pointer_template(text[l])) {
      l++;
    }
    while (l < r && !pointer_template(text[r])) {
      r--;
    }
    if (tolower(text[l]) != tolower(text[r])) {
      return false;
    }
    r--;
    l++;
  }
  return true;
}

int main() {
  string text = "Was it a car or a cat I saw?";
  cout << ispalandrome(text) << endl;
  cout << two_pointer_methof(text) << endl;
  return 0;
}
