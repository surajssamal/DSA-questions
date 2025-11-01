#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
int Findmin(vector<int> &nums) {
  int res = nums[0];
  int l = 0;
  int r = nums.size() - 1;

  while (l <= r) {
    if (nums[l] < nums[r]) {
      res = min(res, nums[l]);
      break;
    }
    int m = l + (r - l) / 2;
    res = min(res, nums[m]);

    if (nums[m] >= nums[l]) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return res;
}
int main() {
  vector<int> nums = {11, 13, 15, 17};
  cout << Findmin(nums) << endl;
  return 0;
}
