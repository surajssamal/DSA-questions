#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

int dynamic_solution(vector<int> stocks_price) {
  int minum = stocks_price[0];
  int result = 0;
  for (auto s : stocks_price) {
    result = max(result, s - minum);
    minum = min(minum, s);
  }
  return result;
}

int max_profit(vector<int> stocks_price) {
  int left = 0;
  int right = left + 1;
  int result = 0;
  while (right < stocks_price.size()) {
    if (stocks_price[left] < stocks_price[right]) {
      result = max(stocks_price[right] - stocks_price[left], result);
    } else {
      left = right;
    }
    right++;
  }
  return result;
}

int main() {
  vector<int> stocks_price = {5, 1, 5, 6, 7, 1, 10};
  cout << max_profit(stocks_price) << endl;
  cout << dynamic_solution(stocks_price) << endl;

  return 0;
}
