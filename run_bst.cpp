// THE BEER-WARE LICENSE
// adrian.stoewer@rz.ifi.lmu.de wrote this file. As long as you retain this notice
// you can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a beer in return.

#include <iostream>
#include "bst.hpp"

using namespace std;

int main(int argc, char **argv) {

    bst *tree = nullptr;

    cout << "depth:\t" << bst_depth(tree) << endl;
    bst_print(tree);

    cout << "\n-----------------------\n";

    bst_add(tree, 5);
    bst_add(tree, 3);
    bst_add(tree, 2);
    bst_add(tree, 1);
    bst_add(tree, 4);
    bst_add(tree, 7);
    bst_add(tree, 6);
    bst_add(tree, 8);
    bst_add(tree, 9);

    cout << "depth:\t" << bst_depth(tree) << endl;
    bst_print(tree);

    cout << "\n-----------------------\n";

    return 0;

}