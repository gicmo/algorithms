// THE BEER-WARE LICENSE
// adrian.stoewer@rz.ifi.lmu.de wrote this file. As long as you retain this notice
// you can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a beer in return.

#include <iostream>
#include "bst.hpp"

using namespace std;

int main(int argc, char **argv) {

    cout << "\n------empty tree-------\n\n";

    bst<int> tree{};
    cout << "depth:\t" << tree.depth() << endl;

    cout << "\n------add numbers------\n\n";

    tree.add(5);
    tree.add(3);
    tree.add(2);
    tree.add(1);
    tree.add(4);
    tree.add(7);
    tree.add(6);
    tree.add(8);
    tree.add(9);

    cout << "depth:\t" << tree.depth() << endl;
    tree.print();

    cout << "\n---------search---------\n\n";

    cout << boolalpha;
    cout << "contains 8:  " << tree.search(8) << endl;
    cout << "contains 6:  " << tree.search(6) << endl;
    cout << "contains 5:  " << tree.search(5) << endl;
    cout << "contains 1:  " << tree.search(1) << endl;
    cout << "contains 0:  " << tree.search(0) << endl;
    cout << "contains 10: " << tree.search(10) << endl;

    cout << "\n--------remove 5--------\n";

    tree.remove(5);
    tree.print();
    cout << "contains 0:  " << tree.search(3) << endl;

    return 0;

}