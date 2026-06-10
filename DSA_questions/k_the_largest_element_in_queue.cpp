#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++) {
      pq.push(nums[i]);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }
};

int main() {

  int k = 2;
  vector<int> nums = {2, 3, 1, 1, 5, 5, 4};
  Solution *hello = new Solution();
  cout << hello->findKthLargest(nums, k) << endl;
}
