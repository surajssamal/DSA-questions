#include "print_array.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> daily_temp(vector<int> &data) {
  vector<int> result(data.size(), 0);
  for (int i = 0; i < data.size(); i++) {
    int counter = 0;
    for (int j = i; j < data.size(); j++) {
      if (data[i] < data[j]) {
        break;
      } else {
        counter += 1;
      }
      counter = (j == data.size() - 1) ? 0 : counter;
    }

    result[i] = counter;
  }
  return result;
}
vector<int> dynamic_approach(vector<int> &data) {
  int n = data.size();
  vector<int> result(n, 0);

  for (int i = n - 2; i >= 0; i--) {
    int j = i + 1;
    while (j < n && data[j] <= data[i]) {
      if (result[j] == 0) {
        j = n;
        break;
      }
      j += result[j];
    }
    if (j < n) {
      result[i] = j - i;
    }
  }
  return result;
};
int main() {
  vector<int> temprature = {30, 38, 30, 36, 35, 40, 28};
  // print_container(daily_temp(temprature));
  print_container(dynamic_approach(temprature));
  return 0;
}
