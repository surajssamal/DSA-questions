#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void solution() {
  vector<int> alphabets(26);
  vector<int> alphabets_2(26);
  int n;
  cin >> n;
  string input[2];
  for (int i = 0; i < 2; i++) {
    cin >> input[i];
  }
  for (int i = 0; i < n; i++) {
    alphabets[input[1][i] - 'a'] += 1;
  }
  for (int i = 0; i < n; i++) {
    alphabets_2[input[0][i] - 'a'] += 1;
  }
  if (alphabets == alphabets_2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solution();
  }
}
