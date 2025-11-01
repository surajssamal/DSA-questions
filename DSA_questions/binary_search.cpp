#include <bits/stdc++.h>
#include <vector>
using namespace std;

int recurrsion_search(vector<int> &array, int target, int left, int right) {
  if (left > right) {
    return -1;
  }
  int result;
  int mid = (left + right) / 2;
  if (array[mid] == target) {
    return mid;
  } else if (array[mid] > target) {
    result = recurrsion_search(array, target, left, mid - 1);
  } else {
    result = recurrsion_search(array, target, mid + 1, right);
  }
  return result;
}
int iterative_approach(vector<int> &array, int target) {
  int left = 0, right = array.size();

  while (left <= right) {
    int mid = (left + right) / 2;
    if (array[mid] == target) {
      return mid;
    } else if (array[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}
int recurrsion_binary(vector<int> array, int target) {
  return recurrsion_search(array, target, 0, array.size());
}

int main() {
  vector<int> array = {-1, 0, 2, 4, 6, 8};
  cout << recurrsion_binary(array, 2) << endl;
  cout << iterative_approach(array, 3) << endl;
  return 0;
}
