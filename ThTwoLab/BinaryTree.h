//
// Created by kastu on 21.02.2018.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifndef THTWOLAB_BINARYTREE_H
#define THTWOLAB_BINARYTREE_H


class BinaryTree
{
public:
    BinaryTree *leftArcPointer = nullptr;
    BinaryTree *rightArcPointer = nullptr;
    BinaryTree *parentNodePointer = nullptr;
    int *key = nullptr;
    int *b = nullptr;//number of pairwise different half-ways this node - ways from children
    int *a = nullptr;//number of pairwise different half-ways this node - ways from parent
    int *c = nullptr;//number of pairwise different half-ways this node = a + b
    int *height = nullptr;
    int *leafsOnHeight = nullptr;
    int *MSL = nullptr;

    void add(int, BinaryTree *);
};

void insideVectorFilling(BinaryTree *&, std::vector<int> &, int &);

void allProgram(BinaryTree *&);

void firstPart(BinaryTree *&, int &);

void secondPart(BinaryTree *&, int &, int &);

void thirdPart();

void setABC(BinaryTree *&, int &);

void setHeight_MSL_LOH(BinaryTree *&);

void straightLeftBypass(BinaryTree, std::vector<int> &);

void setTree(BinaryTree &, std::vector<int>);

std::vector<int> readTree(const std::string &);

void writeSLB(const std::string &, std::vector<int> &);

int getMinRight(BinaryTree *&);

void rightRemoval(BinaryTree *&, int);

int getKey(const std::string &);

#endif //THTWOLAB_BINARYTREE_H
