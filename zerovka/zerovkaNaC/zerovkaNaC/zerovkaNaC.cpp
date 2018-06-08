// zerovkaNaC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>



class BinaryTree 
{
public:
	BinaryTree* leftArcPointer = NULL;
	BinaryTree* rightArcPointer = NULL;
	int* key = NULL;
	void add(int newKey);
};
void BinaryTree::add(int newKey)
{
	if (this->key == NULL)
	{
		this->key = new int(newKey);
	}
	else if (newKey > *this->key)
	{
		if (this->rightArcPointer == NULL)
		{
			this->rightArcPointer = new BinaryTree();
		}
		this->rightArcPointer->add(newKey);
	}
	else if (newKey < *this->key)
	{
		if (this->leftArcPointer == NULL)
		{
			this->leftArcPointer = new BinaryTree();
		}
		this->leftArcPointer->add(newKey);
	}
}

void straightLeftBypass(BinaryTree tree, std::vector<int> &result)
{
	result.push_back(*tree.key);
	if (tree.leftArcPointer != NULL)
	{
		straightLeftBypass(*tree.leftArcPointer, result);
	}
	if (tree.rightArcPointer != NULL)
	{
		straightLeftBypass(*tree.rightArcPointer, result);
	}
}

void setTree(BinaryTree &tree, std::vector<int> &list)
{
	for (auto& it : list) {
		tree.add(it);
	}
}
std::vector<int> readTree(std::string source) {
	std::ifstream in(source);
	std::string str;
	std::vector<int> result;
	int num = 0;
	if (in.is_open())
	{
		while (getline(in, str))
		{
			num++;
		}
		result = std::vector<int>(num);
		in.clear();
		in.seekg(0, std::ios::beg);
		auto it = result.begin();
		while (getline(in, str))
		{
			*it = std::stoi(str);
			++it;
		}
	}
	in.close();
	return result;
}
void writeSLB(std::string path, std::vector<int> &list)
{
	std::ofstream out(path);
	if (out.is_open())
	{
		for (auto& it : list)
		{
			out << it << std::endl;
		}
	}
	out.close();
}

int main()
{
	BinaryTree tree;
	setTree(tree, readTree("input.txt"));
	std::vector<int> result;
	straightLeftBypass(tree, result);
	writeSLB("output.txt", result);
    return 0;
}