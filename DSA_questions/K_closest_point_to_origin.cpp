#include "print_array.h"
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
  priority_queue<pair<double, vector<int>>> pq;

public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    eucledian_formula(points);
    vector<vector<int>> result;
    for (int i = points.size(); i > k; i--) {
      pq.pop();
    }
    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    return result;
  };

  void eucledian_formula(vector<vector<int>> &inputs) {
    for (vector<int> &k : inputs) {
      double r = k[0] * k[0] + k[1] * k[1];
      pq.push({r, k});
    }
  }
};
int main() {
  int k = 2;
  vector<vector<int>> points = {{0, 2}, {2, 0}, {2, 2}};
  Solution *hello = new Solution();
  vector<vector<int>> result = hello->kClosest(points, k);
  for (vector<int> &k : result) {
    cout << k[0] << " " << k[1] << endl;
  }
  return 0;
}
