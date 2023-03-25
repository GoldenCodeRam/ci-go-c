#include <stdio.h>
#include <stdlib.h>

struct Node {
  const char *value;
  struct Node *next;
  struct Node *previous;
};

void append(struct Node **head, const char *value);

void insert(struct Node **head, const char *value);
