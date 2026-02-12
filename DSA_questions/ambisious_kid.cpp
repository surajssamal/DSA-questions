#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> input(n);
  int minimum_val = INT_MAX;
  for (int &x : input) {
    cin >> x;
    minimum_val = min(minimum_val, abs(x));
  }
  cout << abs(minimum_val) << endl;
  return 0;
}
