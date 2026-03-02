#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * observations
   > given 1 full and two empty vector a,b,c
   >have to fill the b,c vector via this process
   >if c_i is not divisible by d_i then we append the value in c_i else we
append the value in d_i

trick:-
> we sorted it
>lets say we have something like this {1 7 7 2 9 1 4}
>we sort it we get {1,1,2,4,7,7,9}
>trick is if A is dibisible by B that means B is smaller that A right (cause 4/2
is allowed 2/4 is not allowed )
>we we just chose those mumber which are the smallest ones out of all the number
and what else can be smaller then the intial nummber
*/

void solution(int n, vector<int> inputs) {
  vector<int> c;
  vector<int> b;
  sort(inputs.begin(), inputs.end());
  if (inputs[0] == inputs.back()) {
    cout << -1;
  } else {
    int it = 0;
    while (inputs[it] == inputs[0])
      it++;
    cout << it << " " << n - it << endl;
    for (int i = 0; i < it; i++)
      cout << inputs[i] << " ";
    for (int i = it; i < n; i++)
      cout << inputs[i] << " ";
  }
  cout << endl;
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
    solution(n, inputs);
  }
}
