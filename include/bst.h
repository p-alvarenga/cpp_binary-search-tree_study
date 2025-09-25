#ifndef BST__H__
#define BST__H__

#include <stdbool.h>
#include <string>
#include <vector> 
#include <algorithm>

#include "node.h"

class BST
{
private:
	int cur_id;

	void insert(Node* target, int value = 0); 
	int height(Node* cur) const; // Prototype !

	Node** findDeepestLeftChild(Node** cur) const; // <-- The node in the right subtree
	
	void print(Node* n, std::string prefix = "", bool is_left = false, int depth = 0) const;
	
public: 
	Node* root; 
	size_t size;

	BST(int value): root(new Node(0, value)), size(0) {}

	void getAllLeaves(std::vector<Node*>* leaves, Node* cur) const;
	Node** searchNodeById(int id, Node** cur) const;
	bool deleteNodeById(int id);

	inline void insert(int value);
	inline int height() const;

	inline void print() const; 
};

void BST::insert(int value) 
{
	insert(this->root, value); 
}

int BST::height() const
{ 
	return height(this->root); 
}

void BST::print() const 
{
	print(this->root);
}


/* Todo List 
 * - [x] Search all leaves 
 * - [x] Delete a given Node  
 * - [ ] ...
 */

#endif
