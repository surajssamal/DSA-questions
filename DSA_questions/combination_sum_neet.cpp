#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<vector<int>> result;
void solution(int index, vector<int> input, int target, vector<int> &temp) {
  if (target == 0) {
    result.push_back(temp);
    return;
  } else if (target < 0 || index > input.size()) {
    return;
  }
  temp.push_back(input[index]);
  solution(index, input, target - input[index], temp);
  temp.pop_back();
  solution(index + 1, input, target, temp);
};

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> inputs(n);
  for (int &x : inputs) {
    cin >> x;
  }
  vector<int> temp;
  solution(0, inputs, target, temp);
  for (vector<int> &x : result) {
    for (int &n : x) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}
