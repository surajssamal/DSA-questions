#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solution(int a, int b, int c) {
  if (c % 2 == 0) {
    if (a > b) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  } else {
    if (a < b) {
      cout << "Second" << endl;
    } else {
      cout << "First" << endl;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> inputs(n);
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    solution(a, b, c);
  }
}
