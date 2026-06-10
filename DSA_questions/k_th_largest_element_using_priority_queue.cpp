#include <bits/stdc++.h>
#include <vector>
using namespace std;

class KthLargest {
private:
  int k;

public:
  priority_queue<int, vector<int>, greater<int>> pq;
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      pq.push(nums[i]);
      if (pq.size() > k) {
        pq.pop();
      }
    }
  };

  int add(int val) {
    pq.push(val);
    if (pq.size() > k) {
      pq.pop();
    }
    return pq.top();
  }
};

int main() {
  int k = 3;
  vector<int> nums = {1, 2, 3, 3};
  KthLargest *hello = new KthLargest(k, nums);
  cout << hello->add(3) << endl;
  cout << hello->add(5) << endl;
  cout << hello->add(6) << endl;
  cout << hello->add(7) << endl;
  cout << hello->add(8) << endl;
}
