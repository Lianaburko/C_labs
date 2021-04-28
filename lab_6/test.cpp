#include "main.h"
#include <iostream>
#include <assert.h>

void test(){
//
  tree* test_tree = nullptr;
  List* r = nullptr;
  List* l = nullptr;

  add(&test_tree, 5);
  add(&test_tree, 1);
  add(&test_tree, 2);
  add(&test_tree, 3);
  add(&test_tree, 4);
  add(&test_tree, 6);
  add(&test_tree, 7);
  add(&test_tree, 8);
  add(&test_tree, 9);
  add(&test_tree, 10);

  in_order(test_tree, &r, &l);
  
  List* test_even = nullptr;
  add(&test_even, 2);
  add(&test_even, 4);
  add(&test_even, 6);
  add(&test_even, 8);
  add(&test_even, 10);
  
  List* test_uneven = nullptr;
  add(&test_uneven, 5); 
  add(&test_uneven, 1); 
  add(&test_uneven, 3); 
  add(&test_uneven, 7); 
  add(&test_uneven, 9); 

  assert(compare_lists(l, test_uneven) == true);
  assert(compare_lists(r, test_even) == true);
//
  tree* test1_tree = nullptr;
  add(&test1_tree, 1);
  add(&test1_tree, 3);
  add(&test1_tree, 5);
  add(&test1_tree, 7);
  add(&test1_tree, 9);
  
  List* r1 = nullptr;
  List* l1 = nullptr;
  in_order(test1_tree, &r1, &l1);

  List* test1_even = nullptr;
  List* test1_uneven = nullptr;
  add(&test1_uneven, 1); 
  add(&test1_uneven, 3); 
  add(&test1_uneven, 5); 
  add(&test1_uneven, 7); 
  add(&test1_uneven, 9); 

  assert(compare_lists(l1, test1_uneven) == true);
  assert(compare_lists(r1, test1_even) == true);
//
  tree* test2_tree = nullptr;
  add(&test2_tree, 2);
  add(&test2_tree, 4);
  add(&test2_tree, 6);
  add(&test2_tree, 8);
  add(&test2_tree, 10);
  
  List* r2 = nullptr;
  List* l2 = nullptr;
  in_order(test_tree, &r2, &l2);

  List* test2_even = nullptr;
  List* test2_uneven = nullptr;
  add(&test2_even, 2); 
  add(&test2_even, 4); 
  add(&test2_even, 6); 
  add(&test2_even, 8); 
  add(&test2_even, 10); 

  assert(compare_lists(l2, test2_uneven) == true);
  assert(compare_lists(r2, test2_even) == true);
//
  free(r); free(test_even);
  free(l); free(test_uneven);
  free(r1); free(test1_uneven);
  free(l1); free(test1_uneven);
  free(r2); free(test2_uneven);
  free(l2); free(test2_uneven);

  delete_tree(test_tree);
  delete_tree(test1_tree);
  delete_tree(test2_tree);
}

#undef main 
int main(){
    test();
    return 0;
}