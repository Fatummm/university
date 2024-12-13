#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
    int val;
    struct node_t * next;
} Node;

typedef struct forward_list_t {
    size_t size;
    Node * head;
} List;

void DeleteForwardList(List * lst) {
    int size = lst->size;
    for (int i = 0; i != size; ++i) {
        Node * tmp = lst->head;
        if (i + 1 != size) lst->head = lst->head->next;
        else  lst->head = NULL;
        free(tmp);
    }
    printf("Success!\n");
}

void AddNode(List * lst, int val) {
    if (lst->size == 0) {
        lst->head = (Node *) malloc (sizeof(Node));
        lst->head->val = val;
        lst->head->next = NULL;
        ++lst->size;
        return;
    }
    Node * tmp;
    for (int i = 0; i != lst->size; ++i) {
        if (i == 0) tmp = lst->head;
        else tmp = tmp->next;
    }
    
    Node * new = (Node *) malloc (sizeof(Node));
    new->val = val;
    tmp->next = new;
    ++lst->size;
}

void DeleteNodeByIndex(List * lst, int index) {
    Node * tmp = lst->head;
    if (index == 0 && lst->size == 1) {
        DeleteForwardList(lst);
        return;
    }
    for (int i = 1; i < index - 1; ++i) {
        tmp = tmp->next;
    }
    Node * last = tmp;
    tmp = tmp->next;
    last->next = tmp->next;
    free(tmp);
    --lst->size;
}


void print_list(List lst) {
    Node * tmp;
    for (int i = 0; i != lst.size; ++i) {
        if (i == 0) tmp = lst.head;
        else tmp = tmp->next;
        printf("%d ", tmp->val);
    }
    printf("\n");
}

int main() {
    List arr;
    arr.head = NULL;
    arr.size = 0;
    AddNode(&arr, 3);
    AddNode(&arr, 5);
    AddNode(&arr, 100);
    AddNode(&arr, 6);
    AddNode(&arr, 7);
    AddNode(&arr, 5);
    print_list(arr);
    DeleteNodeByIndex(&arr, 1);
    print_list(arr);
    DeleteForwardList(&arr);
    
}