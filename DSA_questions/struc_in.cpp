#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

struct nodes {
  int somenum;
  string some_string;
  struct nodes *nxt;
};

int main() {
  // puting data inside a stack
  struct nodes student;
  student.somenum = 22;
  student.some_string = "hemlo";
  student.nxt = NULL;
  cout << student.somenum << endl;

  // using the heap
  struct nodes *student2 = (struct nodes *)malloc(sizeof(struct nodes));
  student2->somenum = 23;
  student2->some_string = "hemlo in heap";
  cout << student2->somenum << endl;
  free(student2);
  return 0;
}
