#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

/*
 *observations
 >there is a road which is represented by a number lines means {1-> }
  >my location is at 0 and my objective is to travel to x
 > i trvel via car and it used 1 liter of gasoline per unit
  >there are n gas station given in a vector {a_1,a_2,...,a_n};
  >and there are no gas stations at 0 point and at x point

  objective is to reach x given that i can only refuel my car at given input
spots output :- give the minimum amount of gas needed for going to x and coming
to 0 back

 * test case
  n=3 x=7
  gas pumps at {1 2 5}

 * output =4
 * explanation:-
  1->2 (1 unit of gas used ) ->refuled here to full
  2->5 (3 unit of gas used ) ->refuled here to full
  5->7 (2 unit of gas used ) ->can't refuled here
  coming back
  {note that we can't refuel at x so}
  7->5 (2 units of gas used) -> 4 units of gas consumed adding of the previous 2
(btw refuled at here again)
  5->2 (3 unit of gas used ) ->refuled here to full
  2->1 (1 unit of gas used ) ->refuled here to full
  1->0 (1 unit of gas used ) ->reached at the desitnation
  total fuel needed is 4 units
 */
int solution(int n, vector<int> inputs, int x) {
  int max_value = inputs[0];
  for (int i = 1; i < n; i++) {
    max_value = max(inputs[i] - inputs[i - 1], max_value);
  }
  int result = max(max_value, (x - inputs[n - 1]) * 2);
  return result;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> inputs(n);
    for (int &x : inputs) {
      cin >> x;
    }
    cout << solution(n, inputs, x) << endl;
  }
}
