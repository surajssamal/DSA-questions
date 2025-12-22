#include <bits/stdc++.h>
#include <vector>
using namespace std;
void solution() {
  // using ll = long long;
  int n;
  cin >> n;
  vector<int> inputs(n);
  for (int &x : inputs)
    cin >> x;
  // 1 3 4 5 6
  int i = 0, j = 1;
  while (i < j && i < n - 1) {
    if ((inputs[j] % inputs[i]) % 2 == 0) {
      cout << inputs[i] << " " << inputs[j] << endl;
      return;
      break;
    }
    if (j == n - 1 && i < n - 1) {
      i++;
      j = i;
    }
    j++;
  }
  cout << -1 << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solution();
  }
}
