#include "bst.h"

// ---------------------------------------
// Helper Function for freeing the memory
void exterminate(Node* in){
	if(in){ 
		if(in->get_left()){ exterminate(in->get_left());}
		if(in->get_right()){ exterminate(in->get_right()); }
		delete in;
	}
}

// ---------------------------------------
// Node class
// Default constructor
Node::Node() 
{
	key = 0;
	left = NULL;
	right = NULL;
	parent = NULL;
}
// Constructor
Node::Node(int in) 
{
	key = in;
	left = NULL;
	right = NULL;
	parent = NULL;
}
// Destructor
Node::~Node() { }

// Add parent 
void Node::add_parent(Node* in) 
{
	parent = in;	
}
// Add to left of current node
void Node::add_left(Node* in) 
{
	left = in;
}
// Add to right of current node
void Node::add_right(Node* in) 
{
	right = in;
}

// Get key
int Node::get_key()
{
	return key;
}
// Get parent node
Node* Node::get_parent()
{
	return parent;
}
// Get left node
Node* Node::get_left()
{
	return left;
}
// Get right node
Node* Node::get_right()
{
	return right;
}
// Print the key to ostream to
// Do not change this
void Node::print_info(ostream& to)
{
    to << key << endl;
}
// ---------------------------------------


// ---------------------------------------
// BST class
// Walk the subtree from the given node
void BST::inorder_walk(Node* in, ostream& to)
{
	if (in != NULL){
		inorder_walk(in->get_left(), to);
		in->print_info(to);
		inorder_walk(in->get_right(), to);
	}	
}
// Constructor
BST::BST()
{
	root = NULL;
}
// Destructor
BST::~BST()
{
	exterminate(root);
}

// Insert a node to the subtree
void BST::insert_node(Node* in)
{
	Node* y = NULL;
	Node* x = root;
	while (x!=NULL){
		y = x;
		if (in->get_key() < x->get_key()){ x = x->get_left(); }
		else { x = x->get_right(); }
	}
	in->add_parent(y);
	if (y == NULL)                       { root = in; }
	else if(in->get_key() < y->get_key())  { y->add_left(in); }
	else                                 { y->add_right(in); }
	
}
// Delete a node to the subtree
void BST::delete_node(Node* out)
{ 
	if(out == NULL) { exit(EXIT_FAILURE); }

	Node* prev = NULL;
	//If no left child
	if(out->get_left() == NULL){
		prev = out->get_right();
		//TRANSPLANT
		if (out->get_parent() == NULL){ root = prev; }
		else if(out == out->get_parent()->get_left()){ out->get_parent()->add_left(prev); }
		else{ out->get_parent()->add_right(prev); }

		if (prev != NULL){ prev->add_parent(out->get_parent()); }
	}
	//No right child
	else if(out->get_right() == NULL){
		prev = out->get_left();
		//TRANSPLANT
		if (out->get_parent() == NULL){ root = prev; }
		else if(out == out->get_parent()->get_left()){ out->get_parent()->add_left(prev); }
		else{ out->get_parent()->add_right(prev); }

		if (prev != NULL){ prev->add_parent(out->get_parent()); }
	}
	//2 Children
	else{
		prev = get_min(out->get_right());
		Node* prev_right = prev->get_right();
		if(prev->get_parent() != out){
			//TRANSPLANT
			if (prev->get_parent() == NULL){ root = prev_right; }
			else if(prev == prev->get_parent()->get_left()){ prev->get_parent()->add_left(prev_right); }
			else{ prev->get_parent()->add_right(prev_right); }
	
			if (prev_right != NULL){ prev_right->add_parent(prev->get_parent()); }
		
			prev->add_right(out->get_right());
			prev->get_right()->add_parent(prev);
		}
		
		//TRANSPLANT
		if (out->get_parent() == NULL){	root = prev;	}
		else if(out == out->get_parent()->get_left()){ out->get_parent()->add_left(prev); }
		else{ out->get_parent()->add_right(prev); }

		if (prev != NULL){ prev->add_parent(out->get_parent()); }

		prev->add_left(out->get_left());
		prev->get_left()->add_parent(prev);

	}
	//Free the deleted node from heap
	delete out;
}
// minimum key in the BST
Node* BST::tree_min()
{
	Node* tmp = root;
	while(tmp->get_left() != NULL){
		tmp = tmp->get_left();
	}
	return tmp;
}
// maximum key in the BST
Node* BST::tree_max()
{
	Node* tmp = root;
	while(tmp->get_right() != NULL){
		tmp = tmp->get_right();
	}
	return tmp;
}
// Get the minimum node from the subtree of given node
Node* BST::get_min(Node* in)
{
	while(in->get_left() != NULL){
		in = in->get_left();
	}
	return in;
}
// Get the maximum node from the subtree of given node
Node* BST::get_max(Node* in)
{
	while(in->get_right() != NULL){
		in = in->get_right();
	}
	return in;
}
// Get successor of the given node
Node* BST::get_succ(Node* in)
{
	if(in->get_right() != NULL){ 
		return get_min(in->get_right()); 
	}
	Node* y = in->get_parent();
	while (y!=NULL and in == y->get_right()){ 
		in = y;
		y = y->get_parent();	
	}
	return y;
}
// Get predecessor of the given node
Node* BST::get_pred(Node* in)
{
	if(in->get_left() != NULL){ return get_max(in->get_left()); }
	Node* y = in->get_parent();
	while (y!=NULL and in==y->get_left()){ 
		in = y;
		y = y->get_parent();	
	}
	return y;
}
// Walk the BST from min to max
void BST::walk(ostream& to)
{
	inorder_walk(root, to);
}
// Search the tree for a given key
Node* BST::tree_search(int search_key)
{
	Node* x = root;
	while (x != NULL and search_key != x->get_key()){
		if (search_key < x->get_key()){ x = x->get_left(); }
		else{ x = x->get_right(); }
	}
	return x;
}
// ---------------------------------------
