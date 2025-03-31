#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
};

struct Node *nalloc(void) {
    return (struct Node *)malloc(sizeof(struct Node));
}

int main() {
    void date();
    struct Node *node;
    struct Node n1;
    node = &n1;
    printf("Enter Value for Node : ");
    scanf("%d", &node->value);
    printf("You entered With Pointer: %d Direct reference: %d\n", node->value,
           n1.value);
    node = nalloc();
    printf("Enter Value for Node : ");
    scanf("%d", &node->value);
    printf("You entered %d", node->value);
    free(node);
    node = &n1;
    printf("You entered With Pointer: %d Direct reference: %d\n", node->value,
           n1.value);
    date();
    return 0;
}

void date() {
    printf("Enter date in dd/mm/yyyy format : ");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    printf("%d %d %d", day, month, year);
}