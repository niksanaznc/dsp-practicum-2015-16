#ifndef TREE_H
#define TREE_H

#include <vector>

using namespace std;

class Tree
{
private:
	struct TreeNode
	{
		int data;
		vector<TreeNode*> successors;

		TreeNode(int _data) : data(_data), successors(vector<TreeNode*>()) {}

		void copy(TreeNode const*);
		void insert(int x)
		{
			successors.push_back(new TreeNode(x));
		}
	};

	TreeNode* root;
	
	void erase(TreeNode*&);

public:
	Tree() : root(nullptr) {}
	Tree(int a) : root(new TreeNode(a)) {}
	Tree(Tree const&);
	Tree& operator=(Tree const&);
	~Tree();

	bool member(int) const;
	bool isMember(TreeNode*, int) const;

	void filterOdd();
	void filterOddRec(TreeNode*&);

	void fillTree();
};

#endif
