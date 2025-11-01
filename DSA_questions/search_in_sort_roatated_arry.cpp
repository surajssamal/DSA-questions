#include <bits/stdc++.h>
#include <vector>
using namespace std;
int BinarySearch(vector<int> &inputs, int target, int left, int right) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (inputs[mid] == target) {
      return mid;
    }
    if (inputs[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
int binary_sort_two_pass(vector<int> &inputs, int target) {

  int left = 0, right = inputs.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    cout << left << " " << mid << " " << right << endl;
    if (inputs[mid] > inputs[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  int pivot = left;
  int result = BinarySearch(inputs, target, 0, pivot - 1);
  if (result != -1) {
    return result;
  }

  return BinarySearch(inputs, target, pivot, inputs.size() - 1);
}

int binary_sort_one_pass(vector<int> &inputs, int target) {
  int left = 0;
  int right = inputs.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (inputs[mid] == target) {
      return mid;
    }
    if (inputs[left] <= inputs[mid]) {
      if (target > inputs[mid] || target < inputs[left]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
      if (target < inputs[mid] || target > inputs[right]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }
  return -1;
}
int main() {
  vector<int> inputs = {5, 8, 12, 1, 2, 3, 4};
  cout << binary_sort_one_pass(inputs, 4) << endl;
  cout << binary_sort_two_pass(inputs, 4) << endl;
  return 0;
}
