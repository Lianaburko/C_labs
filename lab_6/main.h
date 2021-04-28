#ifndef MAIN_H
#define MAIN_H

struct tree;
struct List;
void add(List** top, int n);
void add(tree** my_tree, int value);
void in_order(tree* my_tree, List** r, List** l);

void delete_tree(tree* node);
List* delete_head(List* root);
bool compare_lists(List* top1, List* top2);

#endif