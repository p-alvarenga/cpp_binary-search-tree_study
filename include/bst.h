#ifndef BST__H__
#define BST__H__

#include <stdbool.h>
#include <string>
#include <vector> 

#include "node.h"

class BST
{
private:
	int cur_id;
	void insertNode(Node* target, int value = 0); 
	Node** findDeepestLeftChild(Node** cur) const; // <-- The node in the right subtree

public: 
	Node* root; 
	size_t size;

	BST(int value): root(new Node(0, value)), size(0) {;}
	inline void insert(int value) { insertNode(this->root, value); }

	void getAllLeaves(std::vector<Node*>* leaves, Node* cur) const;
	Node** searchNodeById(int id, Node** cur) const;
	bool deleteNodeById(int id);
	int geTreetHeight()

	// void deleteNodeByPtr(Node* n) <- Need to verify if "n" is part of tree (it's inside this->root)

	void print(Node* n, std::string prefix, bool is_left = false, int depth = 0); // include depth too
};

/* Todo List 
 * - [x] Search all leaves 
 * - [ ] Delete a given Node  
 * - [ ] ...
 */

#endif
