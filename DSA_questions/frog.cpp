#include "print_array.h"
#include <bits/stdc++.h>
using namespace std;

/*
 *observation
  >  given a frog want to reach N
  >  given an height[] where height of i+1 element is i-1(that means
     height of future stair)
  >  if frog jumps
    - energy loss height[i-1]-height[j-1] where j is the step he reached
    - the frog can jump i+1 and i+2
  output :the optimized minimum jumps required
  input = 10 20 30 10
  explaination :-  10->20=10
                   20->10=10;
                   10+10 =20;
 */

// recurssion apporoach
unordered_map<int, int> memo;
int solution_reccur(vector<int> inputs, int n) {
  if (memo.find(n) != memo.end()) {
    return memo[n];
  }
  if (n <= 0) {
    return 0;
  }
  int left_recur =
      solution_reccur(inputs, n - 1) + abs(inputs[n] - inputs[n - 1]);

  int right_recur = INT_MAX;
  if (n >= 2) {
    right_recur =
        solution_reccur(inputs, n - 2) + abs(inputs[n] - inputs[n - 2]);
  }

  int ans = min(left_recur, right_recur);
  memo[n] = ans;
  return ans;
}
vector<int> solution(vector<int> inputs, int n) {
  vector<int> record(n, 0);
  record[1] = abs(inputs[1] - inputs[0]);
  int prev_record = INT_MAX;
  for (int i = 2; i < n; i++) {
    for (int j = i - 2; j < i; j++) {
      prev_record = min(abs(inputs[i] - inputs[j]) + record[j], prev_record);
    }
    record[i] = prev_record;
    prev_record = INT_MAX;
  }
  return record;
}

int main() {
  int n;
  cin >> n;
  vector<int> inputs(n);
  for (int &x : inputs) {
    cin >> x;
  }
  print_container(inputs);
  vector<int> result = solution(inputs, n);
  print_container(result);
  cout << result[n - 1] << endl;
  cout << solution_reccur(inputs, n - 1) << endl;
  return 0;
}
