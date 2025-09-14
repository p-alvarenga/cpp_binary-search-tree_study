#ifndef NODE__H__
#define NODE__H__

class Node 
{ 
public: 
	Node* right; 
	Node* left; 
	Node* parent; 

	int id; 
	int value;

	Node(int id = 0, int value = 0, Node* parent = nullptr): 
		id(id), 
		value(value),
		right(nullptr), 
		left(nullptr), 
		parent(parent)
	{;}

	inline const bool isEmpty() const;
};

inline const bool Node::isEmpty() const
{
	return (this->right == nullptr && this->left == nullptr);
}

#endif
