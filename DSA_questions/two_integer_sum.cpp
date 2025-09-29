#include "print_array.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> twosum(vector<int> &arr, int &target) {
  int l = 0, r = arr.size() - 1;
  while (l < r) {
    int resdual = arr[l] + arr[r];
    if (resdual == target) {
      return {l + 1, r + 1};
    }
    if (resdual > target) {
      r--;
    }
    if (resdual < target) {
      l++;
    }
  }
  return {};
};
int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  int target = 4;
  print_container(twosum(arr, target));
}
