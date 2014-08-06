// THE BEER-WARE LICENSE
// adrian.stoewer@rz.ifi.lmu.de wrote this file. As long as you retain this notice
// you can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a beer in return.

#include <iostream>
#include "bst.hpp"

using namespace std;

int main(int argc, char **argv) {

    cout << "\n------empty tree-------\n\n";

    bst<int> *tree = nullptr;
    cout << "depth:\t" << bst_depth(tree) << endl;

    cout << "\n------add numbers------\n\n";

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

    cout << "\n---------search---------\n\n";

    cout << "contains 7:  " << bst_search(tree, 7) << endl;
    cout << "contains 8:  " << bst_search(tree, 8) << endl;
    cout << "contains 6:  " << bst_search(tree, 6) << endl;
    cout << "contains 5:  " << bst_search(tree, 5) << endl;
    cout << "contains 1:  " << bst_search(tree, 1) << endl;
    cout << "contains 0:  " << bst_search(tree, 0) << endl;
    cout << "contains 10: " << bst_search(tree, 10) << endl;

    cout << "\n--------remove 5--------\n";

    bst_remove(tree, 5);
    bst_print(tree);
    cout << "contains 0:  " << bst_search(tree, 3) << endl;

    return 0;

}