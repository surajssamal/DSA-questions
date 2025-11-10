#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
int rectange(vector<int> input) {
  int i = 0, j = 0;
  int max_value = 0;
  int n = input.size();
  while (i < n) {
    while (input[i] <= input[j] && j < n) {
      j++;
    }
    int rest_res = 0;
    int k = i;
    while (input[k - 1] > input[i] && k >= 1) {
      rest_res++;
      k--;
    }
    max_value = max(max_value, input[i] * (j - (i - rest_res)));
    i++;
    j = i + 1;
  }
  return max_value;
}
int largestRectangleArea(vector<int> &heights) {
  int maxArea = 0;
  stack<pair<int, int>> stack; // pair: (index, height)

  for (int i = 0; i < heights.size(); i++) {
    int start = i;
    while (!stack.empty() && stack.top().second > heights[i]) {
      pair<int, int> top = stack.top();
      int index = top.first;
      int height = top.second;
      maxArea = max(maxArea, height * (i - index));
      start = index;
      stack.pop();
    }
    stack.push({start, heights[i]});
  }

  while (!stack.empty()) {
    int index = stack.top().first;
    int height = stack.top().second;
    maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
    stack.pop();
  }
  return maxArea;
};
int main() {
  vector<int> input_1 = {7, 1, 7, 2, 2, 4};
  cout << rectange(input_1) << endl;
  cout << largestRectangleArea(input_1) << endl;
  return 0;
}
