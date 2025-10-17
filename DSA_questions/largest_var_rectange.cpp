#include <bits/stdc++.h>
#include <vector>
using namespace std;

int largest_rect(vector<int> &something) {
  int i = 0, j = 1;
  int max_value = 0;
  int n = something.size();

  while (i < n) {
    while (something[i] <= something[j] && j < n) {
      j++;
    }

    int k = i;
    int back_res = 0;
    while (something[k - 1] > something[i] && k >= 1) {
      back_res += 1;
      k--;
    }
    cout << i << " " << j << " " << back_res
         << " back res :" << (j - (i - back_res))
         << " area : " << something[i] * (j - (i - back_res)) << endl;
    max_value = max(max_value, something[i] * (j - (i - back_res)));
    i++;
    j = i + 1;
  }
  return max_value;
}

int main() {

  vector<int> input_2 = {3, 6, 5, 7, 4, 8, 1, 0};
  vector<int> something = {7, 1, 7, 2, 2, 4};
  cout << endl;
  cout << largest_rect(input_2) << endl;

  return 0;
}
