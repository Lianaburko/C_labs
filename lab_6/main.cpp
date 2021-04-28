#include <iostream>
#include "main.h"

struct tree {
    int inf;
    tree* l = nullptr;
    tree* r = nullptr;
};

struct List {
    int num;
    List* next = nullptr;
    List* prev = nullptr;
};

void add(List** top, int n) {
    List* new_list = new List();
    new_list->num = n;
    new_list->prev = nullptr;
    new_list->next = nullptr;
    List* run = *top;

    if (run == nullptr) {
        *top = new_list;    
    }
    else {
        new_list->next = *top;
        run->prev = new_list;
        *top = new_list;
    }
}

void in_order(tree* my_tree, List** r, List** l) {
    if (my_tree == nullptr) {
        return; 
    }
    if (my_tree->inf % 2 == 0) {
        add(&*r, my_tree->inf);
    }
    else {
        add(&*l, my_tree->inf);
    }
    in_order(my_tree->l, r, l);
    in_order(my_tree->r, r, l);
}

void add(tree** my_tree, int value) {
    tree* branch = new tree();
    branch->inf = value;
    branch->l = nullptr;
    branch->r = nullptr;
    tree* root = &**my_tree;

    if (*my_tree == nullptr) {
        *my_tree = branch;
    }
    else {
        while (true) {
            if (root->inf < value) {
                if (root->r == nullptr) {
                    root->r = branch;
                    return;
                }
                root = root->r;
            }
            else {
                if (root->l == nullptr) {
                    root->l = branch;
                    return;
                }
                root = root->l;
            }
        }
}

}

void print(List* top) {
    while (top != nullptr) {
        printf("%d ", top->num);
        top = top->next;
    }
}

bool compare_lists(List* top1, List* top2) {
    bool a = true;
    while (top1 != nullptr || top2 != nullptr) {
        if (top1->num == top2->num) {
            continue;
        }
        else {
            a = false;
        }
        top1 = top1->next;
        top2 = top2->next;
    }
    return a;
}

void delete_tree(tree* node) {
    if (node) {
        delete_tree(node->l);
        delete_tree(node->r);
        free(node);
    }
}

List* delete_head(List* root) {
    struct List* temp;
    temp = root->next;
    temp->prev = NULL;
    free(root);
    return(temp);
}

int main() {
    tree* test_tree = nullptr;
    List* r = nullptr;
    List* l = nullptr;

    add(&test_tree, 2);
    add(&test_tree, 6);
    add(&test_tree, 8);
    add(&test_tree, 10);

    in_order(test_tree, &r, &l);

    print(r);
    printf("\n");

    print(l);
    printf("\n");
    free(r);
    free(l);
    delete_tree(test_tree);

    system("pause");
    return 0;
}