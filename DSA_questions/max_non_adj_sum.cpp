#include "print_array.h"
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*observation
 * given a array of numbers
 * have to find the sum max out of all numbers in array
  - a element cannot add with its adjacent element
  input : 10 20 30 40
  10+30=40
  20+40 =60
  10+40=50
  coutput=60(cause its the max)
*/
int solution(vector<int> inputs, int n, unordered_map<int, int> &memo) {
  if (memo.find(n) != memo.end()) {
    return memo[n];
  }
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return inputs[n];
  }
  int taking = solution(inputs, n - 2, memo) + inputs[n];
  int not_taking = solution(inputs, n - 1, memo);
  int result = max(taking, not_taking);
  memo[n] = result;
  return result;
}
int solution_tabulation(int n, vector<int> inputs) {
  if (n == 0) {
    return inputs[0];
  }
  vector<int> record(n);
  record[0] = inputs[0];
  for (int i = 1; i < n; i++) {
    record[i] = max(record[i - 2] + inputs[i], record[i - 1]);
  }
  return record[n - 1];
}

int main() {
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    vector<int> inputs(n);
    for (int &x : inputs) {
      cin >> x;
    }
    unordered_map<int, int> memo;
    cout << solution(inputs, n, memo) << endl;
    cout << solution_tabulation(n, inputs) << endl;
  }

  return 0;
}
