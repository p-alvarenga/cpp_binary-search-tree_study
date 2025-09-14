#include "../include/bst.h"

void BST::insertNode(Node* target, int value) 
{
	if (target == nullptr) return; 
		
	if (value <= target->value) 
	{
		if (target->left == nullptr)
		{
			this->size++; 
			target->left = new Node(size, value, target);
		}
		else
			insertNode(target->left, value);
	}
	else 
	{
		if (target->right == nullptr)
		{
			this->size++;
			target->right = new Node(size, value, target);
		}
		else 
			insertNode(target->right, value);	
	}
}

void BST::print(Node* n, std::string prefix, bool is_left, int depth) 
{
	if (n == nullptr) return; 

	if (depth != 0) 
	{
		bool parent_has_left = n->parent->left == nullptr; 
		
		printf(is_left || parent_has_left ? "%s└── %i [%i]\n" : "%s├── %i [%i]\n", prefix.c_str(), n->value, n->id);
		prefix += !is_left && !parent_has_left ? "│   " : "    ";
	}
	else printf("%i [%i]\n", n->value, n->id);

	print(n->right, prefix, false, depth + 1);
	print(n->left, prefix, true, depth + 1);
}

void BST::getAllLeaves(std::vector<Node*>* leaves, Node* cur) const 
{
	if (cur == nullptr) return;

	if (cur->isEmpty()) 
		leaves->push_back(cur);

	getAllLeaves(leaves, cur->left);
	getAllLeaves(leaves, cur->right); 
}

void BST::searchNodeById(int id, Node** ptr, Node* cur) const
{
	if (cur == nullptr) return; 

	if (cur->id == id) 
	{
		*ptr = cur; 
		return;
	}

	searchNodeById(id, ptr, cur->left);
	searchNodeById(id, ptr, cur->right);
}
