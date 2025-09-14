#include <algorithm>
#include <vector> 
#include <random>

#include "include/bst.h"

int main(void)
{	
	std::vector<int> values; 
	std::random_device rd; 

	BST tree(20); 
	
	for (int i = -5; i <= 5; i++)
		values.push_back(i);

	std::shuffle(values.begin(), values.end(), std::default_random_engine(rd())); 

	for (int i : values)
		tree.insert(i);

	tree.print(tree.root); 

	std::vector<Node*> leaves; 
	tree.getAllLeaves(&leaves, tree.root);
	
	printf("\n");

	for (Node* leaf : leaves) 
	{
		std::printf("Leaf %i : %i\n", leaf->id, leaf->value); 
	}

	printf("\n\n");

	return 0; 
}

