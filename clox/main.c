#include "ddl.h"
#include <stdio.h>

int main() {
    struct Node *head = NULL;
    append(&head, "Test1");
    append(&head, "Test2");
    append(&head, "Test4");
    insert(&head, "Test5");

    printf("%s\n", head->value);
    printf("%d\n", count(&head));

    printf("%d\n", find(&head, "Test4") != NULL);
    printf("%d\n", find(&head, "Test999") == NULL);

    printf("%s\n", head->value);
    printf("%d\n", count(&head));
    deleteNode(&head, "Test4");
    printf("%s\n", head->value);
    printf("%d\n", count(&head));
}
