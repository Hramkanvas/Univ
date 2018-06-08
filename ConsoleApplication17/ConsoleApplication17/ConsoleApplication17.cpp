// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int vecNum;

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

void insideVectorFilling(BinaryTree *&, std::vector<int> &);

void allProgram(BinaryTree *&);

void firstPart(BinaryTree *&, int &);

void secondPart(BinaryTree *&, int &);

void setABC(BinaryTree *&, int &);

void setHeight_MSL_LOH(BinaryTree *&);

void straightLeftBypass(BinaryTree, std::vector<int> &);

void setTree(BinaryTree &, std::vector<int>);

std::vector<int> readTree(const std::string &);

void writeSLB(const std::string &, std::vector<int> &);

int getMinRight(BinaryTree *&);

void rightRemoval(BinaryTree *&, int);


int main()
{
	auto *tree = new BinaryTree();
	setTree(*tree, readTree("tst.in"));
	allProgram(tree);
	std::vector<int> result;
	straightLeftBypass(*tree, result);
	writeSLB("tst.out", result);
	return 0;
}

void BinaryTree::add(int newKey, BinaryTree *parent)
{
	if (this->key == nullptr)
	{
		this->parentNodePointer = parent;
		this->key = new int(newKey);
	}
	else if (newKey > *this->key)
	{
		if (this->rightArcPointer == nullptr)
		{
			this->rightArcPointer = new BinaryTree();
		}
		this->rightArcPointer->add(newKey, this);
	}
	else if (newKey < *this->key)
	{
		if (this->leftArcPointer == nullptr)
		{
			this->leftArcPointer = new BinaryTree();
		}
		this->leftArcPointer->add(newKey, this);
	}
}

void straightLeftBypass(BinaryTree tree, std::vector<int> &result)
{
	result.push_back(*tree.key);
	if (tree.leftArcPointer != nullptr)
	{
		straightLeftBypass(*tree.leftArcPointer, result);
	}
	if (tree.rightArcPointer != nullptr)
	{
		straightLeftBypass(*tree.rightArcPointer, result);
	}
}

void setTree(BinaryTree &tree, std::vector<int> list)
{
	for (auto &it : list)
	{
		tree.add(it, nullptr);
	}
}

std::vector<int> readTree(const std::string &source)
{
	std::ifstream in(source);
	std::string str;
	std::vector<int> result;
	vecNum = 0;
	if (in.is_open())
	{
		while (getline(in, str))
		{
			vecNum++;
		}
		result = std::vector<int>(static_cast<const unsigned int>(vecNum));
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

void writeSLB(const std::string &path, std::vector<int> &list)
{
	std::ofstream out(path);
	if (out.is_open())
	{
		for (auto &it : list)
		{
			out << it << std::endl;
		}
	}
	out.close();
}

int getMinRight(BinaryTree *&tree)
{
	if ((*tree).leftArcPointer == nullptr)
	{
		BinaryTree *temp = tree;
		int newKey = *tree->key;
		if ((*tree).rightArcPointer != nullptr)
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
	else
	{
		return getMinRight((*tree).leftArcPointer);
	}
}

void rightRemoval(BinaryTree *&tree, int key)
{
	if (*(*tree).key == key)
	{
		BinaryTree *temp = tree;
		if ((*tree).leftArcPointer == nullptr && (*tree).rightArcPointer == nullptr)
		{
			delete tree;
			tree = nullptr;
			delete tree;
		}
		else if ((*tree).leftArcPointer == nullptr)
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
		else if ((*tree).rightArcPointer == nullptr)
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
	else if (*(*tree).key > key && (*tree).leftArcPointer != nullptr)
	{
		rightRemoval((*tree).leftArcPointer, key);
	}
	else if (*(*tree).key < key && (*tree).rightArcPointer != nullptr)
	{
		rightRemoval((*tree).rightArcPointer, key);
	}
}

void firstPart(BinaryTree *&tree, int &MSLT)
{
	if (tree->rightArcPointer != nullptr)
	{
		firstPart(tree->rightArcPointer, MSLT);
	}
	if (tree->leftArcPointer != nullptr)
	{
		firstPart(tree->leftArcPointer, MSLT);
	}
	setHeight_MSL_LOH(tree);
	if (*(tree->MSL) > MSLT)
	{
		MSLT = *(tree->MSL);
	}
}

void setHeight_MSL_LOH(BinaryTree *&tree)
{
	if (tree->rightArcPointer != nullptr && tree->leftArcPointer != nullptr)
	{
		tree->height =
			new int(*(tree->rightArcPointer->height) > *(tree->leftArcPointer->height) ? (*(tree->rightArcPointer->height) +
				1) : (
					*(tree->leftArcPointer->height) + 1));
		//height is ready
		tree->MSL = new int(*(tree->rightArcPointer->height) + *(tree->leftArcPointer->height) + 2);
		//MSL is ready
		if (*(tree->rightArcPointer->height) == *(tree->leftArcPointer->height))
		{
			tree->leafsOnHeight = new int(*(tree->rightArcPointer->leafsOnHeight) + *(tree->leftArcPointer->leafsOnHeight));
		}
		else
		{
			tree->leafsOnHeight = new int(
				*(tree->rightArcPointer->height) > *(tree->leftArcPointer->height)
				? *(tree->rightArcPointer->leafsOnHeight) : *(tree->leftArcPointer->leafsOnHeight));
		}//leafsOnHeight ready
	}
	else if (tree->rightArcPointer != nullptr)
	{
		tree->height = new int(*(tree->rightArcPointer->height) + 1);
		//height is ready
		tree->MSL = new int(*(tree->rightArcPointer->height) + 1);
		//MSL is ready
		tree->leafsOnHeight = new int(*(tree->rightArcPointer->leafsOnHeight));
		//leafsOnHeight ready
	}
	else if (tree->leftArcPointer != nullptr)
	{
		tree->height = new int(*(tree->leftArcPointer->height) + 1);
		//height is ready
		tree->MSL = new int(*(tree->leftArcPointer->height) + 1);
		//MSL is ready
		tree->leafsOnHeight = new int(*(tree->leftArcPointer->leafsOnHeight));
		//leafsOnHeight ready
	}
	else
	{
		tree->height = new int(0);
		//height is ready
		tree->MSL = new int(0);
		//MSL is ready
		tree->leafsOnHeight = new int(1);
	}
}

void secondPart(BinaryTree *&tree, int &MSLT)
{
	setABC(tree, MSLT);
	if (tree->rightArcPointer != nullptr)
	{
		secondPart(tree->rightArcPointer, MSLT);
	}
	if (tree->leftArcPointer != nullptr)
	{
		secondPart(tree->leftArcPointer, MSLT);
	}
}

void setABC(BinaryTree *&tree, int &MSLT)
{
	if (*(tree->MSL) == MSLT)
	{
		if (tree->rightArcPointer != nullptr && tree->leftArcPointer != nullptr)
		{
			tree->b = new int(*(tree->rightArcPointer->leafsOnHeight) * *(tree->leftArcPointer->leafsOnHeight));
		}
		else if (tree->rightArcPointer != nullptr)
		{
			tree->b = new int(*(tree->rightArcPointer->leafsOnHeight));
		}
		else if (tree->leftArcPointer != nullptr)
		{
			tree->b = new int(*(tree->leftArcPointer->leafsOnHeight));
		}
		else
		{
			tree->b = new int(1);
		}
	}
	else
	{
		tree->b = new int(0);
	}//b completed

	if (tree->parentNodePointer == nullptr)
	{
		tree->a = new int(0);
	}
	if (tree->rightArcPointer != nullptr && tree->leftArcPointer != nullptr)
	{
		if (*(tree->leftArcPointer->height) == *(tree->rightArcPointer->height))
		{
			tree->leftArcPointer->a =
				new int(*(tree->b) + *(tree->leftArcPointer->leafsOnHeight) * *(tree->a) / *(tree->leafsOnHeight));
			(tree->rightArcPointer->a) =
				new int(*(tree->b) + *(tree->rightArcPointer->leafsOnHeight) * *(tree->a) / *(tree->leafsOnHeight));
		}
		else if (*(tree->leftArcPointer->height) > *(tree->rightArcPointer->height))
		{
			(tree->leftArcPointer->a) = new int(*(tree->a) + *(tree->b));
			(tree->rightArcPointer->a) = new int(*(tree->b));
		}
		else
		{
			(tree->rightArcPointer->a) = new int(*(tree->a) + *(tree->b));
			tree->leftArcPointer->a = new int(*(tree->b));
		}
	}
	else if (tree->rightArcPointer != nullptr)
	{
		(tree->rightArcPointer->a) = new int(*(tree->a) + *(tree->b));
	}
	else if (tree->leftArcPointer != nullptr)
	{
		(tree->leftArcPointer->a) = new int(*(tree->a) + *(tree->b));
	}//a completed
	(tree->c) = new int(*(tree->a) + *(tree->b));
	//c completed
}

void allProgram(BinaryTree *&tree)
{
	int MSLT = 0;
	std::vector<int> vector;
	vector.reserve(static_cast<const unsigned int>(vecNum));
	firstPart(tree, MSLT);
	secondPart(tree, MSLT);
	insideVectorFilling(tree, vector);
	if (vector.size() % 2 != 0)
	{
		rightRemoval(tree, vector[vector.size() / 2]);
	}
}

void insideVectorFilling(BinaryTree *&tree, std::vector<int> &vector)
{
	if (tree->leftArcPointer != nullptr)
	{
		insideVectorFilling(tree->leftArcPointer, vector);
	}
	if (*(tree->c) != 0 && *(tree->c) % 2 == 0)
	{
		vector.push_back(*(tree->key));
	}
	if (tree->rightArcPointer != nullptr)
	{
		insideVectorFilling(tree->rightArcPointer, vector);
	}
}