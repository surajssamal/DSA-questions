#include <algorithm>
#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>
using namespace std;

/*
# observations
  > theofanis has n boxes and each of which has some numbers a_i written on it
  >want to sort the boxes in ascending order
    >howerver the sorting machine works in a strange way it can only reverse any
      subarray of length at most k
    >reversing a subarray means choosing two indices i and j (1<=i<=j<=n)
    input =a_1,a_2,a_3,...,a_n
computations :-
  a_1,a_2,a_(i-1),a_(j),a_(j-1),a_(j-2),....,a_(i),a_(j+1),...,a_(n-1),a(n);
  > and we're not constrained  to choose only one substring we can choose
    multiple substrings

  > and if the output is completedly sorted the anwer will be
true else false number can be reversed
 *
 */
bool solution(int n, int k, vector<int> input) {
  vector<int> temo_inputs(input);
  sort(input.begin(), input.end());
  if (input == temo_inputs) {
    return 1;
  }
  if (n <= 1) {
    return 1;
  }
  if (k <= 1) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int e;
  cin >> e;
  while (e--) {
    int n, k;
    cin >> n >> k;
    vector<int> inputs(n);
    for (int &x : inputs) {
      cin >> x;
    }
    string answer = solution(n, k, inputs) == 1 ? "YES" : "NO";
    cout << answer << endl;
  }
}
