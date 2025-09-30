#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int area_ofwater(vector<int> &arr) {
  int res = 0;
  int r = arr.size() - 1;
  int l = 0;
  while (l < r) {
    if (arr[l] > arr[r]) {
      res = max(res, arr[r] * (r - l));
      r--;
    } else if (arr[l] < arr[r]) {
      res = max(arr[l] * (r - l), res);
      l++;

    } else {
      res = max(arr[l] * (r - l), res);
      l++;
      r--;
    }
  }

  return res;
}

int main() {
  vector<int> arr = {1, 7, 2, 5, 4, 7, 3, 6};
  cout << area_ofwater(arr) << endl;
};
