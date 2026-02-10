#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;

/*
 *observations
 > given a array of length n
  >have to make sure if a_1+a_2=a_2+a_3=...=a_n-1+a_n;
  >but there is catch the numbers are permuted(that means shuffled )
  >> we have to find the right permuation to satify the given statement

objective :- to return true if the statement satifies otherwise false;

test case:-
  inpts= 2 3 3 3 3
  output = false;

  input=1 1 4 5
  output =false;

  input=1 1 2
  output =true;
  explaination :- 1 2 1
*/
bool solution(int n, vector<ll> inputs) {
  unordered_map<ll, int> records;
  for (int i = 0; i < n; i++) {
    records[inputs[i]] += 1;
  }
  if (records.size() > 2) {
    return 0;
  }
  if (records.size() <= 1) {
    return 1;
  }
  vector<int> check;
  for (auto &p : records) {
    check.push_back(p.second);
  }
  sort(check.begin(), check.end());
  if (n % 2 == 0) {
    return check[0] == n / 2 && check[1] == n / 2;
  } else {
    return (check[0] = n / 2 && check[1] == (n / 2) + 1) ||
           (check[0] = (n / 2) + 1 && check[1] == (n / 2));
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> inputs(n);
    for (ll &x : inputs) {
      cin >> x;
    }
    if (solution(n, inputs)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

// trys
