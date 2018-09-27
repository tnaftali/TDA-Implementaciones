#include <stdio.h>
#include <stdlib.h>

#define FALSE  0
#define TRUE  1

typedef struct {
    int info;
} DATA;

typedef struct node {
    DATA data;
    struct node *next;
} NODE;

void init(NODE **top) {/* set top of stack as empty */
    *top = NULL;
}

/* Returns new TOS
 * [In ] Current TOS
 * [In ] Data node to push
 */
NODE *push(NODE *top, DATA data) {
    NODE *tmp = (NODE *) malloc(sizeof(NODE));
    if (tmp == NULL) { // no memory available
        exit(0);
    }
    tmp->data = data;
    tmp->next = top;
    top = tmp;
    return top;
}

/*  Returns new TOS
 * [In] TOS
 * [Out] Data node to pop
 */
NODE *pop(NODE *top, DATA *element) {
    NODE *tmp = top;
    *element = top->data;
    top = top->next;
    free(tmp);
    return top;
}

DATA *top_of_stack(NODE *top) {
    return &top->data;
}

/*
 * Return 1 if empty
 */
int is_empty(NODE *top) {
    return (top == NULL) ? 1 : 0;
}

int main() {
    NODE *top;
    DATA element;
    int size, counter = 0;

    /* stack size is dynamic and specified at runtime */
    printf("Enter stack size:");
    scanf("%d", &size);

    printf("Push elements to stack\n");
    init(&top);
    while (counter < size) {
        element.info = rand();
        printf("push element %d into stack\n", element.info);
        top = push(top, element);
        counter++;
    }
    printf("\nTop Of stack %d\n\n", top_of_stack(top)->info);

    printf("Pop elements from stack\n");
    while (0 == is_empty(top)) {
        top = pop(top, &element);
        printf("pop element %d from stack\n", element.info);
    }

    int empty = is_empty(top);
    if (1 == empty) {
        printf("stack is empty");
    } else {
        printf("stack is not empty");
    }

//    printf("%d", empty);

    return (EXIT_SUCCESS);
}