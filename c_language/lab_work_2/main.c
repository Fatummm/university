#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point_t {
    int x;
    int y;
} Point;

typedef struct node_t {
    Point val;
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

void AddNode(List * lst, Point val) {
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
    new->next = NULL;
    tmp->next = new;
    ++lst->size;
}

void DeleteByIndex(List * lst, int index) {
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
        printf("%d %d\n", tmp->val.x, tmp->val.y);
    }
}

void SetByIndex(List * lst, int index, Point val) {
    if (index == 0) {
        lst->head->val = val;
        return;
    }
    Node * tmp = lst->head;
    for (int i = 1; i <= index; ++i) {
        tmp = tmp->next;
    }
    tmp->val = val;
}

void SortPoints(List * lst) {
    int mn;
    int index = 0;
    int pos = 0;
    Node * tmp;
    for (int i = 0; i < lst->size - 1; ++i) {
        if (i == 0) tmp = lst->head;
        else tmp = tmp->next;
        mn = tmp->val.x * tmp->val.x + tmp->val.y * tmp->val.y;
        Node * tmp2;
        Point p2 = tmp->val;
        for (int j = i + 1; j < lst->size; ++j) {
            if (j == i + 1) tmp2 = tmp->next;
            else tmp2 = tmp2->next;
            if (mn > tmp2->val.x * tmp2->val.x + tmp2->val.y * tmp2->val.y) {
                pos = j;
                mn = tmp2->val.x * tmp2->val.x + tmp2->val.y * tmp2->val.y;
                p2 = tmp2->val;
                
            }
        }
        Point temp_point = tmp->val;
        tmp->val = p2;
        SetByIndex(lst, pos, temp_point);
    }
}


int main() {
    List lst; lst.head = NULL; lst.size = 0;
    AddNode(&lst, (Point){0, 0});
    AddNode(&lst, (Point){3, 4});
    AddNode(&lst, (Point){1, -1});
    AddNode(&lst, (Point){-2, 2});
    AddNode(&lst, (Point){5, 5});
    AddNode(&lst, (Point){-3, 0});
    AddNode(&lst, (Point){10, -10});
    AddNode(&lst, (Point){6, -2});
    AddNode(&lst, (Point){9, 1});
    AddNode(&lst, (Point){7, -7});
    SortPoints(&lst);
    //SetByIndex(&lst, 1, (Point){100, 100});
    print_list(lst);
    DeleteForwardList(&lst);
}
