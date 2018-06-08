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
	BinaryTree* parentNodePointer = NULL;
	int* key = NULL;
	void add(int newKey, BinaryTree * parent);
};
void BinaryTree::add(int newKey, BinaryTree* parent)
{
	if (this->key == NULL)
	{
		this->parentNodePointer = parent;
		this->key = new int(newKey);
	}
	else if (newKey > *this->key)
	{
		if (this->rightArcPointer == NULL)
		{
			this->rightArcPointer = new BinaryTree();
		}
		this->rightArcPointer->add(newKey, this);
	}
	else if (newKey < *this->key)
	{
		if (this->leftArcPointer == NULL)
		{
			this->leftArcPointer = new BinaryTree();
		}
		this->leftArcPointer->add(newKey, this);
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
		tree.add(it, nullptr);
	}
}
std::vector<int> readTree(std::string source) {
	std::ifstream in(source);
	std::string str;
	std::vector<int> result;
	int num = 0;
	if (in.is_open())
	{
		getline(in, str);
		getline(in, str);
		while (getline(in, str))
		{
			num++;
		}
		result = std::vector<int>(num);
		in.clear();
		in.seekg(0, std::ios::beg);
		auto it = result.begin();
		getline(in, str);
		getline(in, str);
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
int getMinRight(BinaryTree* &tree) {
	if ((*tree).leftArcPointer == NULL) {
		BinaryTree *temp = tree;
		int newKey = *tree->key;
		if ((*tree).rightArcPointer != NULL)
		{
			(*tree).rightArcPointer->parentNodePointer = (*tree).parentNodePointer;

			if ((*tree).parentNodePointer->leftArcPointer == tree)
			{
				(*tree).parentNodePointer->leftArcPointer = (*tree).rightArcPointer;
			}
			else
			{
				(*tree).parentNodePointer->rightArcPointer = (*tree).rightArcPointer;
			}
		}
		else
		{
			if ((*tree).parentNodePointer->leftArcPointer == tree)
			{
				(*tree).parentNodePointer->leftArcPointer = nullptr;
			}
			else
			{
				(*tree).parentNodePointer->rightArcPointer = nullptr;
			}
		}
		delete temp;
		temp = nullptr;
		delete temp;
		return newKey;
	}
	else {
		return getMinRight((*tree).leftArcPointer);
	}
}
void rightRemoval(BinaryTree *&tree,int key)
{
	
	if (*(*tree).key == key)
	{
		BinaryTree *temp = tree;
		if ((*tree).leftArcPointer == NULL && (*tree).rightArcPointer == NULL)
		{
			delete tree;
			tree = nullptr;
			delete tree;
		}
		else if ((*tree).leftArcPointer == NULL)
		{
			(*tree).rightArcPointer->parentNodePointer = (*tree).parentNodePointer;

			if ((*tree).parentNodePointer != nullptr)
			{
				if ((*tree).parentNodePointer->leftArcPointer == tree)
				{
					(*tree).parentNodePointer->leftArcPointer = (*tree).rightArcPointer;
				}
				else
				{
					(*tree).parentNodePointer->rightArcPointer = (*tree).rightArcPointer;
				}
			}
			else
			{
				tree = (*tree).rightArcPointer;
			}
			delete temp;
			temp = nullptr;
			delete temp;
		}
		else if ((*tree).rightArcPointer == NULL)
		{
			(*tree).leftArcPointer->parentNodePointer = (*tree).parentNodePointer;

			if ((*tree).parentNodePointer != nullptr)
			{
				if ((*tree).parentNodePointer->leftArcPointer == tree)
				{
					((*tree).parentNodePointer)->leftArcPointer = (*tree).leftArcPointer;
				}
				else
				{
					(*tree).parentNodePointer->rightArcPointer = (*tree).leftArcPointer;
				}
			}
			else
			{
				tree = (*tree).leftArcPointer;
			}
			delete temp;
			temp = nullptr;
			delete temp;
		}
		else
		{
			*(*tree).key = getMinRight((*tree).rightArcPointer);
		}
	}
	else if (*(*tree).key > key && (*tree).leftArcPointer != NULL)
	{
			rightRemoval((*tree).leftArcPointer, key);
	}
	else if (*(*tree).key < key && (*tree).rightArcPointer != NULL)
	{
		rightRemoval((*tree).rightArcPointer, key);
	}
}

int getKey(std::string str) {
	std::ifstream in(str);
	std::string key;
	getline(in, key);
	int result = std::stoi(key);
	in.close();
	return result;
}
int main()
{
	BinaryTree *tree = new BinaryTree();
	int delKey = getKey("input.txt");
	setTree(*tree, readTree("input.txt" ));
	rightRemoval(tree, delKey);
	std::vector<int> result;
	straightLeftBypass(*tree, result);
	writeSLB("output.txt", result);
	return 0;
}