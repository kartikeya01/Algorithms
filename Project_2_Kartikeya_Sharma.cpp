// Name: Kartikeya Sharma
// Class: Algorithms 22000
// Professor: Peter Brass
// Homework 2

#include <stdio.h>
#include <stdlib.h>

typedef int object_t;
typedef int key_t;
typedef struct tr_n_t { key_t           key;
                        struct tr_n_t  *left;
                        struct tr_n_t *right;
                        int           height;
} tree_node_t;


//================================================SOLUTION STARTS BELOW================================================

int pass_array_recursively(tree_node_t * tree, int leaf_depth_counter[], int depth) {

    if (tree == nullptr) return 0; // base case
    if (tree->right == nullptr) { // simplified (tree->left==nullptr && tree->right==nullptr)
        leaf_depth_counter[depth] += 1; // if node is leaf, add 1 to its counter in leaf_depth_counter array
    } else { // check whole right sub-tree + check whole left sub-tree + fill array with counter if node is leaf
        pass_array_recursively(tree->right, leaf_depth_counter, depth + 1);
        pass_array_recursively(tree->left, leaf_depth_counter, depth + 1);
    }
    return 0;
}

int depth_distribution(tree_node_t * tree) {

    int leaf_depth_counter[99] { }; // local array of 100 counters
    int total_leaves = 0; // initially there are 0 leaves

    if (tree->height > 99) {
        printf("Depth greater than 99 found");
        exit(0);
    } else {
        pass_array_recursively(tree, leaf_depth_counter, 0); // fill array with leaf count respective to depth position
        for (int i = 0; i < 99; i++) { // now go through array and find total leaves
            if (leaf_depth_counter[i] > 0) { // only add if array index has leaves
                total_leaves += leaf_depth_counter[i]; // add to total_leaves
            }
        }
        printf("\nThere are a total of %u leaves \n\n", total_leaves); // print total leaves

        for (int i = 0; i < 99; i++) { // now to print out table
            if (leaf_depth_counter[i] > 0) { // but for only those depths that have at least one leaf
                printf("%u leaves at depth %u \n", leaf_depth_counter[i], i); // print table
            }
        }
    }
    return 0;
}

