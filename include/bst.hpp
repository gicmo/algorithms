// THE BEER-WARE LICENSE
// adrian.stoewer@rz.ifi.lmu.de wrote this file. As long as you retain this notice
// you can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a beer in return.

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <queue>
#include <cmath>


template<typename T>
struct bst {
    T value;

    bst<T> *parent;
    bst<T> *left;
    bst<T> *right;
};


//prototypes

template<typename T>
bst<T> *bst_new(T value, bst<T> *parent=nullptr, bst<T> *left=nullptr, bst<T> *right=nullptr);

template<typename T>
void bst_print(bst<T> *tree);

template<typename T>
void bst_add(bst<T> *&tree, T value, bst<T> *parent=nullptr);

template<typename T>
int  bst_depth(bst<T> *tree, int depth=0);

template<typename T>
bool bst_remove(bst<T> *&tree, T value);

template<typename T>
bool bst_search(bst<T> *tree, T value);


//implementation

template<typename T>
bst<T> *bst_new(T value, bst<T> *parent, bst<T> *left, bst<T> *right) {
    bst<T> *node = new bst<T>();

    node->value  = value;
    node->parent = parent;
    node->left   = left;
    node->right  = right;

    return node;
}

template<typename T>
void bst_print(bst<T> *tree) {
    int depth_max = bst_depth(tree);

    std::queue<bst<T> *> level_curr;
    std::queue<bst<T> *> level_next;

    level_curr.push(tree);

    std::string start, gap;
    std::cout << std::endl;

    for (int depth = 1; depth <= depth_max; depth++) {
        start.resize((size_t) (pow(2, depth_max - depth) - 1), ' ');
        gap.resize((size_t) (pow(2, depth_max - depth + 1) - 1), ' ');

        std::cout << start;
        while(!level_curr.empty()) {
            bst<T> *node = level_curr.front();
            level_curr.pop();

            if (node) {
                std::cout << node->value << (level_curr.empty() ? "" : gap);

                level_next.push(node->left);
                level_next.push(node->right);
            } else {
                std::cout << '*' << (level_curr.empty() ? "" : gap);

                level_next.push(nullptr);
                level_next.push(nullptr);
            }
        }
        std::cout << std::endl;

        level_curr = level_next;
        level_next = std::queue<bst<T> *>();
    }

    std::cout << std::endl;
}

template<typename T>
void bst_add_node(bst<T> *&tree, bst<T> *node, bst<T> *parent) {
    if (!tree) {
        node->parent = parent;
        tree = node;
    } else if (node->value < tree->value) {
        bst_add_node(tree->left, node, tree);
    } else if (node->value > tree->value) {
        bst_add_node(tree->right, node, tree);
    }
}

template<typename T>
void bst_add(bst<T> *&tree, T value, bst<T> *parent) {
    bst<T>* node = bst_new(value);
    bst_add_node(tree, node, parent);
}

template<typename T>
int bst_depth(bst<T> *tree, int depth) {
    if (!tree)
        return depth;

    depth++;
    int left  = bst_depth(tree->left, depth);
    int right = bst_depth(tree->right, depth);

    return (left > right) ? left : right;
}


template<typename T>
bool bst_remove(bst<T> *&tree, T value) {
    if (!tree)
        return false;
    else if (value < tree->value)
        return bst_remove(tree->left, value);
    else if (value > tree->value)
        return bst_remove(tree->right, value);

    bst<T> *tmp = tree;
    if (!tree->left && !tree->right) {
        tree = nullptr;
    } else if (tree->left && !tree->right) {
        tree->left->parent = tree->parent;
        tree = tree->left;
    } else if (!tree->left && tree->right) {
        tree->right->parent = tree->parent;
        tree = tree->right;
    } else {
        bst<T> *tmp_right = tree->right;
        tree->left->parent = tree->parent;
        tree = tree->left;
        bst_add_node(tree, tmp_right, tree->parent);
    }
    delete tmp;

    return true;
}


template<typename T>
bool bst_search(bst<T> *tree, T value) {
    if (!tree)
        return false;
    else if (value < tree->value)
        return bst_search(tree->left, value);
    else if (value > tree->value)
        return bst_search(tree->right, value);
    else
        return true;
}


#endif
