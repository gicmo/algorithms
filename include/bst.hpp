// THE BEER-WARE LICENSE
// adrian.stoewer@rz.ifi.lmu.de wrote this file. As long as you retain this notice
// you can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a beer in return.

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct bst {
    int value;

    bst *parent;
    bst *left;
    bst *right;

    bst(int value, bst *parent=nullptr, bst *left=nullptr, bst * right=nullptr);
};

void bst_print(bst *tree);

void bst_add(bst *&tree, int value, bst *parent=nullptr);

int bst_depth(bst *tree, int depth=0);

void bst_remove(bst* tree, int value);

bool bst_search(bst* tree, int value);

#endif
