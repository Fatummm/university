#include "forwarded_list.c"




int main() {
    List lst; lst.head = NULL; lst.size = 0;
    for (int i = 0; i != 10; ++i) {
        AddNode(&lst, rand() % 50);
    }
    print_list(lst);
    DeleteForwardList(&lst);
}