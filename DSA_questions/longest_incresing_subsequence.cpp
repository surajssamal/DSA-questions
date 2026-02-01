#include "print_array.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> solution(vector<int> inputs, int n) {
  vector<int> record(n, 1);
  int subproblem = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (inputs[j] < inputs[i]) {
        subproblem = max(record[j], subproblem);
      }
      record[i] = 1 + subproblem;
      subproblem = 0;
    }
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
  vector<int> result = solution(inputs, n);
  print_container(result);
}
