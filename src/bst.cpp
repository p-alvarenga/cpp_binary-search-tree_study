#include "../include/bst.h"

void BST::insertNode(Node* target, int value) 
{
	if (target == nullptr) return; 
		
	if (value <= target->value) 
	{
		if (target->left == nullptr)
		{
			target->left = new Node(++this->cur_id, value, target);
			this->size++; 
		}
		else
			insertNode(target->left, value);
	}
	else 
	{
		if (target->right == nullptr)
		{
			target->right = new Node(++this->cur_id, value, target);
			this->size++;
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
		bool parent_has_left = (n->parent->left == nullptr); 
		
		printf(is_left || parent_has_left ? "%s└── %i" : "%s├── %i", prefix.c_str(), n->value);
		prefix += !is_left && !parent_has_left ? "│   " : "    ";
	
		is_left ? printf(" L\n") : printf(" R\n");
	}
	else printf("%i ROOT\n", n->value);

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

Node** BST::searchNodeById(int id, Node** cur) const
{
	if (*cur == nullptr) return nullptr; 

	if ((*cur)->id == id) 
		return cur;

	Node** left_result = searchNodeById(id, &(*cur)->left); 
	
	if (left_result != nullptr) 
		return left_result; 

	return searchNodeById(id, &(*cur)->right); 
}

Node** BST::findDeepestLeftChild(Node** cur) const 
{
	if (cur == nullptr) return nullptr; // <- is it necessary? 

	if ((*cur)->left == nullptr)
		return cur; 

	return findDeepestLeftChild(&(*cur)->left); 
}

bool BST::deleteNodeById(int id) 
{
	Node** n = this->searchNodeById(id, &this->root);
	if (n == nullptr) return false;
	
	if ((*n)->isEmpty())
	{
		delete *n;
		*n = nullptr; // avoid dangling ptr
		this->size--; 
		return true;	
	}

	if ((*n)->isFull())
	{
		/* NOTE
		 * This solution kinda sucks. Find a 
		 * way to avoid using id_buf. 
		**/

		Node** successor = findDeepestLeftChild(&(*n)->right);	
		int id_buf = (*successor)->id;

		(*n)->value = (*successor)->value;
		(*n)->parent = (*successor)->parent;

		deleteNodeById((*successor)->id);
		
		(*n)->id = id_buf;
		
		this->size--;
		return true; 
	}

	if ((*n)->left != nullptr) // has left node
	{ // dangling ptr here? 
		(*n)->left->parent = (*n)->parent; 
		*n = (*n)->left;
		this->size--; 
		return true; 
	}

	if ((*n)->right != nullptr) // has right node
	{
		(*n)->right->parent = (*n)->parent;
		*n = (*n)->right; 
		this->size--;
		return true; 
	}

	return true; 
}
