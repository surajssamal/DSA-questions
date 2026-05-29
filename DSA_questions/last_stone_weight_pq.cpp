#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq;
    for (int i = 0; i < stones.size(); i++) {
      pq.push(stones[i]);
    }
    while (pq.size() > 1) {
      int x = pq.top();
      pq.pop();
      int y = pq.top();
      pq.pop();
      if (x != y) {
        pq.push(x - y);
      }
    }
    return pq.empty() ? 0 : pq.top();
  }
};

int main() {
  vector<int> stones = {7, 6, 7, 6, 9};
  Solution *hello = new Solution();
  cout << hello->lastStoneWeight(stones) << endl;
};
