#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
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
unordered_map<int, int> memo;
int solution(vector<int> inputs, int n) {
  if (memo.find(n) != memo.end()) {
    return memo[n];
  }
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return inputs[n];
  }
  int taking = solution(inputs, n - 2) + inputs[n];
  int not_taking = solution(inputs, n - 1);
  int result = max(taking, not_taking);
  memo[n] = result;
  return result;
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
    cout << solution(inputs, n - 1) << endl;
  }
  return 0;
}
