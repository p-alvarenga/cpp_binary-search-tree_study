#include <algorithm>
#include <vector> 
#include <random>

#include "include/bst.h"

int main(void)
{	
	std::vector<int> values; 
	std::random_device rd; 

	BST tree(20); 
	
	for (int i = 0; i <= 20; i++)
		values.push_back(i);

	std::shuffle(values.begin(), values.end(), std::default_random_engine(rd())); 

	for (int i : values)
		tree.insert(i);

	//tree.print(tree.root); 
	
	Node* test = nullptr;

	tree.searchNodeById(40, &test, tree.root);
	
	if (test != nullptr)
		printf("\nn value: %i, n id: %i\n", test->value, test->id);

	return 0; 
}

