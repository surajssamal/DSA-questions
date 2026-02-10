#include <bits/stdc++.h>
using namespace std;

/*
 *observation
  >given a array we have to sort it
    >if a[i-1]> a[i] < a[i+1]
    >> swap(a[i+1],a[i])
  objective if doing these operations finite time gives a sorted array return
    else 0
 * hint
 * since we're starting from i=1 not i=0 the i=1 will never be sorted that means
 if a[1] = smallest element in the array we can sort it other wise be can't
 (while swaping remember it is basically bubble sort just phased differently and
 insted of starting from 0 starts from 1)
 */

bool solution(int n, vector<int> inputs) {
  if (inputs[0] == 1) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> inputs(n);
    for (int &x : inputs) {
      cin >> x;
    }
    string result = solution(n, inputs) == 1 ? "YES" : "NO";
    cout << result << endl;
  }
}
