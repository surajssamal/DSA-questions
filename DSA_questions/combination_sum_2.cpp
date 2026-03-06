#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void combination(vector<vector<int>> &result, vector<int> &temp, int i,
                 int target, vector<int> inputs) {
  if (target == 0) {
    result.push_back(temp);
    return;
  } else if (target < 0 || i > inputs.size()) {
    return;
  }
  temp.push_back(inputs[i]);
  combination(result, temp, i + 1, target - inputs[i], inputs);
  temp.pop_back();
  while (i < inputs.size() && inputs[i] == inputs[i + 1]) {
    i++;
  }
  combination(result, temp, i + 1, target, inputs);
};

vector<vector<int>> solution(vector<int> inputs, int target) {
  if (inputs.size() <= 0) {
    return {{}};
  }
  sort(inputs.begin(), inputs.end());
  vector<vector<int>> result;
  vector<int> temp;
  combination(result, temp, 0, target, inputs);
  return result;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> inputs(n);
  for (int &x : inputs) {
    cin >> x;
  }
  vector<vector<int>> result = solution(inputs, target);
  for (vector<int> &x : result) {
    for (int &n : x) {
      cout << n << " ";
    }
    cout << endl;
  }
}
