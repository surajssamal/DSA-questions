#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solution(vector<int> &temp, set<vector<int>> &result, vector<int> &inputs,
              int i) {

  if (i >= inputs.size()) {
    result.insert(temp);
    return;
  }
  temp.push_back(inputs[i]);
  solution(temp, result, inputs, i + 1);
  temp.pop_back();
  solution(temp, result, inputs, i + 1);
}

vector<vector<int>> combination(vector<int> &inputs) {
  vector<int> temp;
  sort(inputs.begin(), inputs.end());
  set<vector<int>> result;
  vector<bool> tick(inputs.size(), false);
  solution(temp, result, inputs, 0);
  return vector<vector<int>>(result.begin(), result.end());
}

int main() {
  int n;
  cin >> n;
  vector<int> inputs(n);
  for (int &x : inputs) {
    cin >> x;
  }
  vector<vector<int>> result = combination(inputs);
  for (vector<int> &x : result) {
    for (int n : x) {
      cout << n << " ";
    }
    cout << endl;
  }
}
