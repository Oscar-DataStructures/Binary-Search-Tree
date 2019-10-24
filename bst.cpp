/*
Nicholas Reichert, Oscar Martinez
CS 271
Dr. Lall
Project 5
*/

#include <sstream>
#include <string>
#include <typeinfo>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;



class KeyError
{
	virtual const char* what() const throw()
	{
		return "Error finding key";
	}
};


//============================ New Node Function================================
template <class KeyType>
Node<KeyType>* newNode(KeyType key)
//Preconditions: 	N/A
//Postcondition:	Returns a dynamically allocated keytype Node pointer that updates its key value to be the one in the parameter
{
	Node<KeyType>* node = new Node<KeyType>();		//dynamically allocate Node
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->key = key;															//Sets the node key to the key parameter

	return node;
}


// ================================= Constructor ===============================
template <class KeyType>
bst<KeyType>::bst()
// PreConditions:		N/A
// PostConditions:	Sets the private member root to NULL
{
  this->root = NULL;
}


// ================================ DeConstructor ==============================
template <class KeyType>
bst<KeyType>::~bst()
// PreConditions:		A bst must exist for this to be called one
// PostConditions:	Calls clearNodes which deletes bst
{
	clearNodes();
}


// ================================= Clear Nodes ===============================
template <class KeyType>
void bst<KeyType>::clearNodes()
// PreConditions:		A bst must exist for this to be called one
// PostConditions:	Deallocates memory and destroys existing bst
{

  if (root != NULL)
	{
    vector< Node<KeyType>* > s;
    recPostOrder(root, s);						//used to traverse tree and delete nodes

    for (int i=0; i<s.size(); i++)
		{
      delete s[i];
    }

    this->root = NULL;								//exist condition after the tree has been deleted
  }

	delete root;												//deletes and free the space of the root
}


// =============================== Copy Constructor ============================
template <class KeyType>
bst<KeyType>::bst(const bst<KeyType>& tree)
// PreConditions:		Can only be used for construction
// PostConditions:	Current tree will be a copy of tree
{
  this->root = NULL;
  deepCopy(tree.root);
}


// ================================= Empty Method ==============================
template <class KeyType>
bool bst<KeyType>::empty() const
// PreConditions: 	Must be called on a bst
// PostConditions:  Return True if empty, False if not
{
  return (root == NULL); //if root is null then the tree is empty
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* bst<KeyType>::get(KeyType k) const
// PreConditions: 	Tree must exist and not be empty
// PostConditions:  Return first item in bst that has key k
{
	if (this->helpGet(k) == NULL)
		throw KeyError();

	return &(helpGet(k)->key);
}


// ============================== Help Get Method ==============================
template <class KeyType>
Node<KeyType>* bst<KeyType>::helpGet(KeyType k) const
// PreConditions:		Tree must exist and not be empty
// PostConditions:	Returns the node that has the value k
{
	Node<KeyType> *tmp = root;
	while (tmp != NULL && tmp->key != k)
	{
		if (k < tmp->key)
			tmp = tmp->left;					//Left tree traversal

		else
			tmp = tmp->right;					//Right tree traversal
	}

	if (tmp == NULL)							//Empty Tree
		return NULL;

	else
		return tmp;
}


// ================================ Insert Method ==============================
template <class KeyType>
void bst<KeyType>::insert(KeyType k)
// PreConditions:		N/A
// PostConditions:	Inserts a node containing k into the bst while maintaining the bst property
{
  Node<KeyType> *z = newNode(k);
  Node<KeyType> *x = root;
  Node<KeyType> *y = NULL;
  while (x != NULL)
	{
    y = x;
    if (z->key < x->key)
      x = x->left;							//Left tree traversal
    else
      x = x->right;             //Right tree traversal
  }

  if (y == NULL)								//If no nodes are in tree
    root = z;

	else if (z->key < y->key)
	{
    y->left = z;
		z->parent = y;
	}

	else
	{
    y->right = z;
		z->parent = y;
	}
}


// ================================ Remove Method ==============================
template <class KeyType>
void bst<KeyType>::remove(KeyType k)
// PreConditions:		Tree cannot be empty and key must be in bst
// PostConditions:	Node with value k will be removed and tree restructured
{
  Node<KeyType>* newRoot = recursiveRemove(root, k);
	root = newRoot;							//restructures root
}


// ============================= Remove Recursive Method =======================
template <class KeyType>
Node<KeyType>* bst<KeyType>::recursiveRemove(Node<KeyType>* subtreeRoot, KeyType k)
// PreConditions:		Tree cannot be empty and key must be in bst
// PostConditions:  Return new keytype node pointer subtree with node with value k removed
{
	if (this->helpGet(k) == NULL)
		throw KeyError();

  if (subtreeRoot == NULL)
	{
    return subtreeRoot; 							//ends the function since there is nothing to remove
	}

  if (k < subtreeRoot->key)						//Left tree traversal
	{
		Node<KeyType>* nodeToAttach = recursiveRemove(subtreeRoot->left, k);
    subtreeRoot->left = nodeToAttach;
		nodeToAttach->parent = subtreeRoot;
  }

	else if (k > subtreeRoot->key)			//Right tree traversal
	{
		Node<KeyType>* nodeToAttach = recursiveRemove(subtreeRoot->right, k);
		subtreeRoot->right = nodeToAttach;
		nodeToAttach->parent = subtreeRoot;
	}

	else if (k == subtreeRoot->key)		// for the else portion I looked at https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/ for refrence
	{
		if (subtreeRoot->left == NULL && subtreeRoot->right == NULL) //if root has no children
		{
			delete subtreeRoot;
			return NULL;
		}

		else if(subtreeRoot->left == NULL) 								//if no left child
		{
			Node<KeyType>* tmp = subtreeRoot->right; 				//make the right child root
			delete subtreeRoot;
			return tmp;
		}

		else if(subtreeRoot->right == NULL) 							//if no right child
		{

			Node<KeyType>* tmp = subtreeRoot->left; 				//make the left child root
			delete subtreeRoot;
			return tmp;
		}

		Node<KeyType>* tmp = successorNode(subtreeRoot->key); // get the successor whose value will become new root
		subtreeRoot->key = tmp->key;
		subtreeRoot->right = recursiveRemove(subtreeRoot->right, tmp->key);
	}

	return subtreeRoot;
}


// ============================= Deep Copy Method ==============================
template <class KeyType>
bst<KeyType>& bst<KeyType>::deepCopy(Node<KeyType>* subtreeRoot)
// PreConditions:		N/A
// PostConditions:	Returns a pointer to current bst that is a copy of subtreeRoot
{
	if(subtreeRoot != NULL)
  {
		// This does an pre-order walk through the tree, and inserts items in that order.
		this->insert(subtreeRoot->key);
		deepCopy(subtreeRoot->left);
		deepCopy(subtreeRoot->right);
	}

	return *this;
}


// ================================== Max Method ===============================
template <class KeyType>
KeyType* bst<KeyType>::maximum() const
// PreConditions: 	Root cannot be null
// PostConditions:  Return max item
{
	return helpMax(root);
}


// ============================== Max Helper Method ============================
template <class KeyType>
KeyType* bst<KeyType>::helpMax(Node<KeyType>* subtreeRoot) const
// PreConditions: 	Root cannot be null
// PostConditions:  Return min item
{
	Node<KeyType>* tmp = subtreeRoot; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->right != NULL)		//Right tree traversal
      {
        tmp = tmp->right;
      }

      return &(tmp->key);
    }

  return NULL;
}


// ================================= Min Method ================================
template <class KeyType>
KeyType* bst<KeyType>::minimum() const
// PreConditions: 	Root cannot be null
// PostConditions:  Return min item
{
	Node<KeyType> *result = helpMin(root);
	if (result != NULL)
		return &(result->key);

	else
		return NULL;
}


// ============================== Min Helper Method ============================
template <class KeyType>
Node<KeyType>* bst<KeyType>::helpMin(Node<KeyType>* subtreeRoot) const
// PreConditions: 	Root cannot be null
// PostConditions:  Return min item
{
	Node<KeyType>* tmp = subtreeRoot; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->left != NULL)			//Left tree traversal
      {
        tmp = tmp->left;
      }

      return tmp;
    }

  return NULL;
}


// ============================= Successor Method ==============================
template <class KeyType>
KeyType* bst<KeyType>::successor(const KeyType& k) const
// PreConditions: 	Root cannot be null
// PostConditions:  Return successor of k
{
  Node<KeyType> *result = successorNode(k);

	if (result != NULL)
	{
		return &(result->key);
	}

	else
	{
		return NULL;
	}
}


// =========================== SuccessorNode Method ============================
template <class KeyType>
Node<KeyType>* bst<KeyType>::successorNode(const KeyType& k) const
// PreConditions: 	Root cannot be null
// PostConditions:  Return successor of k
{
	if (this->helpGet(k) == NULL)
		throw KeyError();

  Node<KeyType>* tmp = helpGet(k); 				//this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node<KeyType>* y;
    if (tmp->right != NULL)
    {
      tmp = tmp->right; 									//min of right subtree most immediate successor
      return helpMin(tmp);
    }

    y = tmp->parent;
    while (y != NULL && tmp == y->right)	//traverse until we either hit head or tmp is no longer a right child of y
    {
      tmp = y;
      y = tmp->parent;
    }

    return y;
  }

	return NULL;
}


// ============================ Predecessor Method =============================
template <class KeyType>
KeyType* bst<KeyType>::predecessor(const KeyType& k) const
// PreConditions: 	Root cannot be null
// PostConditions:  Return predecessor of k
{
	if (this->helpGet(k) == NULL)
		throw KeyError();

  Node<KeyType>* tmp = helpGet(k);		 //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node<KeyType>* y;
    if (tmp->left != NULL)
    {
      tmp = tmp->left; 									//max of right subtree will be most immediate predecessor
      return helpMax(tmp);
    }

    y = tmp->parent;
    while (y != NULL && tmp == y->left) //traverse until we either hit head or tmp is no longer a left child of y
    {

      tmp = y;
      y = tmp->parent;
    }
    return &(y->key);
  }
	return NULL;
}


// ============================= Assignment Operator ===========================
template <class KeyType>
bst<KeyType>& bst<KeyType>::operator=(const bst<KeyType>& tree)
// PreConditions:		N/A
// PostConditions:  Make current tree equivalent to tree
{
	clearNodes();					//first we delete the current tree
	deepCopy(tree.root);

	return *this;
}


// =============================== InOrder Method ==============================
template <class KeyType>
string bst<KeyType>::inOrder() const
// PreConditions:		bst must exist
// PostConditions:	Return a string representation of the inOrder walk of the bst
{
	vector<KeyType> s;
	recInOrder(root, s);
	ostringstream vts;

	if (!s.empty())	// looked at https://www.geeksforgeeks.org/transform-vector-string/ to convert to string
  {
    // Convert all but the last element to avoid a trailing ","
    copy(s.begin(), s.end()-1,
        ostream_iterator<int>(vts, ", "));

    vts << s.back();
  }

	return vts.str();
}


// =========================== InOrder Recursive Method ========================
template <class KeyType>
vector<KeyType> bst<KeyType>::recInOrder(Node<KeyType>* subtreeRoot, vector<KeyType> &s) const
// PreConditions:		bst must exist
// PostConditions:	Return a vector representation of the inOrder walk of the bst
{
  if(subtreeRoot != NULL) //works from the root so this is okay
  {
    recInOrder(subtreeRoot->left, s);
    s.push_back(subtreeRoot->key);
    recInOrder(subtreeRoot->right, s);
	}


	return s;
}


// ============================== PreOrder Method ==============================
template <class KeyType>
string bst<KeyType>::preOrder() const
// PreConditions:		bst must exist
// PostConditions:	Return a string representation of the preOrder walk of the bst
{
	vector<KeyType> s;
	recPreOrder(root, s);
	ostringstream vts;

	if (!s.empty())	// looked at https://www.geeksforgeeks.org/transform-vector-string/ to convert to string
  {
    // Convert all but the last element to avoid a trailing ","
    copy(s.begin(), s.end()-1,
        ostream_iterator<int>(vts, ", "));

    vts << s.back();
  }

	return vts.str();
}


// ========================== PreOrder Recursive Method ========================
template <class KeyType>
vector<KeyType> bst<KeyType>::recPreOrder(Node<KeyType>* subtreeRoot, vector<KeyType> &s) const
// PreConditions:		bst must exist
// PostConditions:	Return a vector representation of the preOrder walk of the bst

{
  if(subtreeRoot != NULL) //works from the root so this is okay
  {
    s.push_back(subtreeRoot->key);
    recPreOrder(subtreeRoot->left, s);
    recPreOrder(subtreeRoot->right, s);
  }

	return s;
}


// ============================= PostOrder Method ==============================
template <class KeyType>
string bst<KeyType>::postOrder() const
// PreConditions:		bst must exist
// PostConditions:	Return a string representation of the postOrder walk of the bst
{
	vector< Node<KeyType>* > s;
	recPostOrder(root, s);
	ostringstream vts;

	if (!s.empty())
  {
    for (int i=0; i<s.size()-1; i++)		//changed implementation so we could use it to destruct
		{
			vts << (s[i])->key << ", ";
    }

    // Now add the last element with no delimiter
    vts << (s.back())->key;
  }

	return vts.str();
}


// ======================== PostOrder Recursive Method =========================
template <class KeyType>
vector< Node<KeyType>* > bst<KeyType>::recPostOrder(Node<KeyType>* subtreeRoot, vector< Node<KeyType>* > &s) const
// PreConditions:		bst must exist
// PostConditions:	Return a vector representation of the postOrder walk of the bst
{
  if(subtreeRoot != NULL) //works from the root so this is okay
  {
    recPostOrder(subtreeRoot->left, s);
    recPostOrder(subtreeRoot->right, s);
    s.push_back(subtreeRoot);
  }

	return s;
}
