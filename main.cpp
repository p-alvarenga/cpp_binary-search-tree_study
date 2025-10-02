#include <algorithm>
#include <vector> 
#include <random>

#include "include/bst.h"

BST* generateRandomBST(int init_value, int min, int max); 

int main(void)
{	
	BST* tree = generateRandomBST(20, 10, 30); 

	tree->print();
	printf("\n\n");
	
	tree->deleteNodeById(0); // test 
	printf("\n\n");
	tree->print();

	return 0; 
}

BST* generateRandomBST(int init_value, int min, int max) 
{
	BST* bst = new BST(init_value);

	if (min >= max) return nullptr; 

	std::vector<int> values; 
	std::random_device rd; 

	for (int i = min; i <= max; i++)
		values.push_back(i);

	std::shuffle(values.begin(), values.end(), std::default_random_engine(rd())); 

	for (int v : values)
		bst->insert(v);

	return bst;
}
