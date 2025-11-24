#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int solution(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  auto n = arr.begin();
  auto l = arr.end() - 1;
  int res = *l - *n;
  if (res >= 10) {
    return -1;
  }
  int mid = 3 / 2;
  return arr[mid];
}

int main() {
  vector<int> array(3);
  for (int i = 0; i < 3; i++) {
    cin >> array[i];
  }
  int res = solution(array);
  if (res == -1) {
    cout << "check again" << endl;
  } else {
    cout << "final " << res << endl;
  }
  return 0;
}
