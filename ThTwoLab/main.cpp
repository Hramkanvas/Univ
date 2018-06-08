#include <iostream>
#include <vector>
#include <fstream>
#include "BinaryTree.h"

int main()
{
    auto *tree = new BinaryTree();
    setTree(*tree, readTree("input.txt"));
    allProgram(tree);
    std::vector<int> result;
    straightLeftBypass(*tree, result);
    writeSLB("output.txt", result);

    return 0;
}
