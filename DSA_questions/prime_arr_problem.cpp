#include <bits/stdc++.h>
using namespace std;

int solution() {
  int n;
  cin >> n;
  vector<long long> inputs(n);
  for (int i = 0; i < n; i++) {
    cin >> inputs[i];
  }

  vector<int> prime_num = {2,  3,  5,  7,  11, 13, 17, 19,
                           23, 29, 31, 37, 41, 43, 47, 53};
  for (int x : prime_num) {
    bool ok = false;
    for (int i : inputs) {
      if (i % x) {
        ok = true;
        break;
      }
    }
    if (ok) {
      return x;
      break;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << solution() << endl;
  }

  return 0;
}
