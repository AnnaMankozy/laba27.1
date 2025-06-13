#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct st {
    int info;
    struct st *next;
} STACK;

void push(STACK **s, int item);
int pop(STACK **s);
int peek(STACK *s);
void join_stacks(STACK **s1, STACK **s2);

int main() {
    system("chcp 65001");
    
    STACK *S1 = NULL;
    STACK *S2 = NULL;
    int i, value;

    printf("Введіть 5 елементів для стека S1:\n");
    for (i = 0; i < 5; i+=1) {
        printf("S1, елемент %d: ", i);
        scanf("%d", &value);
        push(&S1, value);
    }

    printf("Введіть 5 елементів для стека S2:\n");
    for (i = 0; i < 5; i+=1) {
        printf("S2, елемент %d: ", i);
        scanf("%d", &value);
        push(&S2, value);
    }

    join_stacks(&S1, &S2);

    printf("Стек S2 після приєднання S1:\n");
    while (S2) {
        printf("%d ", pop(&S2));
    }
    printf("\n");

    return 0;
}

void push(STACK **s, int item) {
    STACK *new_item = (STACK *)malloc(sizeof(STACK));
    if (!new_item) {
        printf("Помилка виділення пам'яті\n");
        exit(1);
    }
    new_item->info = item;
    new_item->next = *s;
    *s = new_item;
}

int pop(STACK **s) {
    if (*s == NULL) {
        printf("Стек порожній!\n");
        return -1;  
    }
    STACK *remove_it = *s;
    int value = remove_it->info;
    *s = remove_it->next;
    free(remove_it);
    return value;
}

int peek(STACK *s) {
    if (s == NULL) {
        printf("Стек порожній!\n");
        return -1;
    }
    return s->info;
}

void join_stacks(STACK **s1, STACK **s2) {
    STACK *temp = NULL;

    while (*s1 != NULL) {
        push(&temp, pop(s1));
    }

    while (temp != NULL) {
        push(s2, pop(&temp));
    }
}
