#include <stdio.h>
#include <stdlib.h>
struct node {
  int something;
  struct node *next;
};

int main(void) {

  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->something = 12;
  head->next = NULL;

  // new attacted noded
  struct node *current = (struct node *)malloc(sizeof(struct node));
  current->something = 19;
  current->next = NULL;
  head->next = current;

  current = (struct node *)malloc(sizeof(struct node));
  current->something = 20;
  current->next = NULL;
  head->next->next = current;

  current = (struct node *)malloc(sizeof(struct node));
  current->something = 21;
  current->next = NULL;
  head->next->next->next = current;

  // printing the values
  int count = 0;
  struct node *ptr = NULL;
  ptr = head;
  while (ptr != NULL) {
    if (ptr == NULL) {
      printf("no values in linked list");
    }
    printf("data=%d next adress=%p current adress =%p\n", ptr->something,
           ptr->next, ptr);
    ptr = ptr->next;
    count += 1;
  }
  return 0;
};
