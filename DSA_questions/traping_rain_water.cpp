#include "print_array.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int trap_usingarrys(vector<int> &height) {
  int n = height.size();
  vector<int> right_max(n, 0);
  vector<int> left_max(n, 0);

  left_max[0] = height[0];
  for (int i = 1; i < n; i++) {
    left_max[i] = max(left_max[i - 1], height[i]);
  }

  right_max[n - 1] = height[n - 1];
  for (int i = n - 2; i > -1; i--) {
    right_max[i] = max(right_max[i + 1], height[i]);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res += min(left_max[i], right_max[i]) - height[i];
  }
  return res;
}

int two_pointers(vector<int> &height) {
  int n = height.size();
  int l = 0;
  int r = n - 1;
  int left_max = height[l];
  int right_max = height[n - 1];
  int res = 0;
  while (l < r) {
    if (left_max < right_max) {
      l++;
      left_max = max(left_max, height[l]);
      res += left_max - height[l];
    } else {
      r--;
      right_max = max(right_max, height[r]);
      res += right_max - height[r];
    }
  }
  return res;
}

int main() {
  vector<int> height = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
  cout << trap_usingarrys(height) << endl;
  cout << two_pointers(height) << endl;
  return 0;
}
