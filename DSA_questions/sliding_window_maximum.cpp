#include "print_array.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
  int left = 0, right = 0;
  int n = nums.size();
  deque<int> q;
  vector<int> result(n - k + 1);
  while (right < n) {
    while (!q.empty() && nums[q.back()] < nums[right]) {
      q.pop_back();
    }
    q.push_back(right);
    if (left > q.front()) {
      q.pop_front();
    }
    if ((right + 1) >= k) {
      result[left] = nums[q.front()];
      left++;
    }
    right++;
  }
  return result;
}

int main() {
  vector<int> nums = {1, 3, 1, 2, 0, 5};
  int k = 3;
  print_container(maxSlidingWindow(nums, k));
  return 0;
}
