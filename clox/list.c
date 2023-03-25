#include "ddl.h"

void append(struct Node **head, const char *value) {
  struct Node *new_node = create_node(value);

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  struct Node *current_node = *head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }

  current_node->next = new_node;
  new_node->previous = current_node;
  return;
}

void insert(struct Node **head, const char *value) {
  struct Node *new_node = create_node(value);

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  new_node->next = *head;
  (*head)->previous = new_node;
  *head = new_node;
}

uint count(struct Node **head) {
  struct Node *current_node = *head;
  uint count = 0;

  while (current_node != NULL) {
    count++;
    current_node = current_node->next;
  }

  return count;
}

struct Node *find(struct Node **head, const char *value) {
  struct Node *current_node = *head;

  while (current_node != NULL) {
    if (current_node->value == value) {
      return current_node;
    }
    current_node = current_node->next;
  }

  return NULL;
}

void deleteNode(struct Node **head, const char *value) {
  struct Node *current_node = *head;

  if (current_node->value == value) {
    if (current_node->next != NULL) {
      *head = current_node->next;
      (*head)->previous = NULL;
      free(current_node);
    } else {
      *head = NULL;
    }
    return;
  }

  while (current_node != NULL) {
    if (current_node->value == value) {
      if (current_node->next != NULL) {
        current_node->next->previous = current_node->previous;
      }
      if (current_node->previous != NULL) {
        current_node->previous->next = current_node->next;
      }

      free(current_node);
      return;
    }
    current_node = current_node->next;
  }
}

struct Node *create_node(const char *value) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->value = value;
  new_node->next = NULL;
  new_node->previous = NULL;
  return new_node;
}
