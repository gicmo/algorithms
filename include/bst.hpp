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
struct bst_node {
    T value;

    bst_node<T> *parent;
    bst_node<T> *left;
    bst_node<T> *right;

};

//prototypes

template<typename T>
bst_node<T> *bst_new(T value, bst_node<T> *parent=nullptr, bst_node<T> *left=nullptr, bst_node<T> *right=nullptr);

template<typename T>
void bst_print(bst_node<T> *tree);

template<typename T>
void bst_add(bst_node<T> *&tree, T value, bst_node<T> *parent=nullptr);

template<typename T>
int  bst_depth(bst_node<T> *tree, int depth=0);

template<typename T>
bool bst_remove(bst_node<T> *&tree, T value);

template<typename T>
bool bst_search(bst_node<T> *tree, T value);


//
template<typename T>
class bst {

public:
    bst() : root(nullptr) { }

    void add(T value) {
        bst_add(root, value);
    }

    void remove(T value) {
        bst_remove(root, value);
    }

    bool search(T value) {
        return bst_search(root, value);
    }

    int depth() {
        return bst_depth(root);
    }

    void print() {
        bst_print(root);
    }
private:
    bst_node<T> *root;
};


//implementation

template<typename T>
bst_node<T> *bst_new(T value, bst_node<T> *parent, bst_node<T> *left, bst_node<T> *right) {
    bst_node<T> *node = new bst_node<T>();

    node->value  = value;
    node->parent = parent;
    node->left   = left;
    node->right  = right;

    return node;
}

template<typename T>
void bst_print(bst_node<T> *tree) {
    int depth_max = bst_depth(tree);

    std::queue<bst_node<T> *> level_curr;
    std::queue<bst_node<T> *> level_next;

    level_curr.push(tree);

    std::string start, gap;
    std::cout << std::endl;

    for (int depth = 1; depth <= depth_max; depth++) {
        start.resize((size_t) (pow(2, depth_max - depth) - 1), ' ');
        gap.resize((size_t) (pow(2, depth_max - depth + 1) - 1), ' ');

        std::cout << start;
        while(!level_curr.empty()) {
            bst_node<T> *node = level_curr.front();
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
        level_next = std::queue<bst_node<T> *>();
    }

    std::cout << std::endl;
}

template<typename T>
void bst_add_node(bst_node<T> *&tree, bst_node<T> *node, bst_node<T> *parent) {
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
void bst_add(bst_node<T> *&tree, T value, bst_node<T> *parent) {
    bst_node<T>* node = bst_new(value);
    bst_add_node(tree, node, parent);
}

template<typename T>
int bst_depth(bst_node<T> *tree, int depth) {
    if (!tree)
        return depth;

    depth++;
    int left  = bst_depth(tree->left, depth);
    int right = bst_depth(tree->right, depth);

    return (left > right) ? left : right;
}


template<typename T>
bool bst_remove(bst_node<T> *&tree, T value) {
    if (!tree)
        return false;
    else if (value < tree->value)
        return bst_remove(tree->left, value);
    else if (value > tree->value)
        return bst_remove(tree->right, value);

    bst_node<T> *tmp = tree;
    if (!tree->left && !tree->right) {
        tree = nullptr;
    } else if (tree->left && !tree->right) {
        tree->left->parent = tree->parent;
        tree = tree->left;
    } else if (!tree->left && tree->right) {
        tree->right->parent = tree->parent;
        tree = tree->right;
    } else {
        bst_node<T> *tmp_right = tree->right;
        tree->left->parent = tree->parent;
        tree = tree->left;
        bst_add_node(tree, tmp_right, tree->parent);
    }
    delete tmp;

    return true;
}


template<typename T>
bool bst_search(bst_node<T> *tree, T value) {
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
