#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int min_eating_speed(vector<int> &piles, int time) {
  int speed = 1;
  while (true) {
    int total_va = 0;
    for (auto s : piles) {
      total_va += (s + speed - 1) /
                  speed; // the reason for s+speed-1 is to making it round up to
                         // lets say the s/speed= 2.3 its round down would be 2
                         // but additing s and -1 will make it round up to
    }

    if (total_va <= time) {
      return speed;
    }
    speed++;
  }
  return 1;
}

int binary_search_method(vector<int> &piles, int time) {
  int left = 1;
  int right = *max_element(piles.begin(), piles.end());
  int res = right;
  while (left <= right) {
    int mid = (left + right) / 2;
    int total_va = 0;
    for (auto pile : piles) {
      total_va += (pile + mid - 1) / mid;
    }
    if (total_va <= time) {
      res = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
}

int main() {

  vector<int> input = {1, 4, 3, 2};
  cout << binary_search_method(input, 9) << endl;
  return 0;
}
