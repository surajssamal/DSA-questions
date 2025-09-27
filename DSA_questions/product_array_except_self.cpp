#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> product_result(vector<int> &elements) {
  vector<int> result(elements.size(), 0);
  int total_product = 1;
  int is_zero = 0;
  int zero_position = -1;
  for (int i = 0; i < elements.size(); i++) {
    if (elements[i] != 0) {
      total_product *= elements[i];
    } else {
      is_zero += 1;
      zero_position = i;
    }
  };

  if (is_zero >= 2) {
    return result;
  } else if (is_zero == 1) {
    result[zero_position] = total_product;
  } else {
    for (int i = 0; i < elements.size(); i++) {
      result[i] = total_product / elements[i];
    }
  }
  return result;
}
int main() {
  vector<int> elements = {-1, 0, 1, 2, 3};

  vector<int> result = product_result(elements);
  for (auto s : result) {
    cout << s << " ";
  }

  cout << endl;
  return 0;
}
