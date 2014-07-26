// THE BEER-WARE LICENSE
// adrian.stoewer@rz.ifi.lmu.de wrote this file. As long as you retain this notice
// you can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a beer in return.

#include <iostream>
#include <queue>
#include <cmath>
#include <bst.hpp>

using namespace std;

bst::bst(int value, bst *parent, bst *left, bst *right)
    : value(value), parent(parent), left(left), right(right)
{}

void bst_print(bst *tree) {
    int depth_max = bst_depth(tree);

    queue<bst*> level_curr;
    queue<bst*> level_next;

    level_curr.push(tree);

    string start, gap;

    for (int depth = 1; depth <= depth_max; depth++) {
        start.resize((size_t) (pow(2, depth_max - depth) - 1), ' ');
        gap.resize((size_t) (pow(2, depth_max - depth + 1) - 1), ' ');

        cout << start;
        while(!level_curr.empty()) {
            bst *node = level_curr.front();
            level_curr.pop();

            if (node) {
                cout << node->value << (level_curr.empty() ? "" : gap);

                level_next.push(node->left);
                level_next.push(node->right);
            } else {
                cout << '*' << (level_curr.empty() ? "" : gap);

                level_next.push(nullptr);
                level_next.push(nullptr);
            }
        }
        cout << endl;

        level_curr = level_next;
        level_next = queue<bst*>();
    }
}

void bst_add(bst *&tree, int value) {
    if (!tree)
        tree = new bst(value);
    else if (value < tree->value)
        bst_add(tree->left, value);
    else if (value > tree->value)
        bst_add(tree->right, value);
}

int bst_depth(bst *tree, int depth) {
    if (!tree)
        return depth;

    depth++;
    int left  = bst_depth(tree->left, depth);
    int right = bst_depth(tree->right, depth);

    return (left > right) ? left : right;
}

void bst_remove(bst *tree, int value) {

}

bool bst_search(bst *tree) {
    return false;
}