#ifndef BST__H__
#define BST__H__

#include <stdbool.h>
#include <string>
#include <vector> 

#include "config.h"
#include "node.h"

class BST
{
private:
	void insertNode(Node* target, int value = 0); 
public: 
	Node* root; 
	int current_id;

	BST(int value): root(new Node(0, value)), current_id(0) {;}
	inline void insert(int value) { insertNode(this->root, value); }

	void getAllLeaves(std::vector<Node*>* leaves, Node* cur) const;

	void print(Node* n, std::string prefix = "", bool is_left = false, int depth = 0); // include depth too
};

/*
 * Todo List 
 * - [x] Search all leaves 
 * - [ ] Delete a given Node  
 * - [ ] ...  
 *
 */

#endif
