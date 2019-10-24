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



class KeyError: public exception
{
	virtual const char* what() const throw()
	{
		return "Error finding key";
	}
};


//============================ New Node Function================================
template <class KeyType>
Node<KeyType>* newNode(KeyType key)
//Preconditions:
//Postcondition:

{
	Node<KeyType>* node = new Node<KeyType>();		//dynamically allocate Node
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->key = key;

	return node;
}


// ================================= Constructor ===============================
template <class KeyType>
bst<KeyType>::bst()
// PreConditions:
// PostConditions:

{
  this->root = NULL;

}


// ================================ DeConstructor ==============================
template <class KeyType>
bst<KeyType>::~bst()
// PreConditions:
// PostConditions:
{
	clearNodes();
}
template <class KeyType>
void bst<KeyType>::clearNodes() {
  //use postOrder walk for deletion
  if (root != NULL) {
    vector< Node<KeyType>* > s;
    recPostOrder(root, s);

    for (int i=0; i<s.size(); i++) {
      delete s[i];
    }
    this->root = NULL;
  }
}


// =============================== Copy Constructor ============================
template <class KeyType>
bst<KeyType>::bst(const bst<KeyType>& tree)
// PreConditions:
// PostConditions:

{
  this->root = NULL;
  deepCopy(tree.root);
}


// ================================= Empty Method ==============================
template <class KeyType>
bool bst<KeyType>::empty() const
// PreConditions: None
// PostConditions:  Return True if empty, False if not

{
  return (root == NULL); //if root is null then the tree is empty
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* bst<KeyType>::get(KeyType k) const
// PreConditions: Root must exist
// PostConditions:  Return first item that has key k
{
	return &(helpGet(k)->key);
}


// ================================= Get Method ================================
template <class KeyType>
Node<KeyType>* bst<KeyType>::helpGet(KeyType k) const
// PreConditions:
// PostConditions:
{
	Node<KeyType> *tmp = root;
	while (tmp != NULL && tmp->key != k)
	{
		if (k < tmp->key)
		{
			tmp = tmp->left;
		}

		else
		{
			tmp = tmp->right;
		}
	}

	if (tmp == NULL)
	{
		return NULL;
	}

	else
	{
		return tmp;
	}
}

// ================================ Insert Method ==============================
template <class KeyType>
void bst<KeyType>::insert(KeyType k)
// PreConditions:
// PostConditions:
{
  Node<KeyType> *z = newNode(k);
  Node<KeyType> *x = root;
  Node<KeyType> *y = NULL;
  while (x != NULL)
	{
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  if (y == NULL)
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
void bst<KeyType>::remove(KeyType k) //added parameter to allow recursion, we could also make new
// PreConditions:
// PostConditions:
{
  Node<KeyType>* newRoot = recursiveRemove(root, k);
	root = newRoot;
}


// ============================= Remove Recursive Method =======================
template <class KeyType>
Node<KeyType>* bst<KeyType>::recursiveRemove(Node<KeyType>* subtreeRoot, KeyType k)
// PreConditions:
// PostConditions:  Delete first item that has key k

{
  if (subtreeRoot == NULL)
	{
    return subtreeRoot; //ends the function since there is nothing to remove
	}

  if (k < subtreeRoot->key)
	{
		Node<KeyType>* nodeToAttach = recursiveRemove(subtreeRoot->left, k);
    subtreeRoot->left = nodeToAttach;
		nodeToAttach->parent = subtreeRoot;
  }

	else if (k > subtreeRoot->key)
	{
		Node<KeyType>* nodeToAttach = recursiveRemove(subtreeRoot->right, k);
		subtreeRoot->right = nodeToAttach;
		nodeToAttach->parent = subtreeRoot;
	}

	else if (k == subtreeRoot->key)
	{
		//this is if we delete the root and have to restructure the tree, 2 cases: root no child or root have child
		// for the else portion I looked at https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/ for refrence
		if (subtreeRoot->left == NULL && subtreeRoot->right == NULL) //if root has no children
		{
			delete subtreeRoot;
			return NULL;
		}

		else if(subtreeRoot->left == NULL) //if no left child
		{
			Node<KeyType>* tmp = subtreeRoot->right; //make the right child root
			delete subtreeRoot;
			return tmp;
		}

		else if(subtreeRoot->right == NULL) //if no right child
		{

			Node<KeyType>* tmp = subtreeRoot->left; //make the left child root
			delete subtreeRoot;
			return tmp;
		}

		Node<KeyType>* tmp = successorNode(subtreeRoot->key); // get the successor whose value will become new root
		subtreeRoot->key = tmp->key;
		subtreeRoot->right = recursiveRemove(subtreeRoot->right, tmp->key);
	}

	return subtreeRoot;
}


// ============================== Deep Copy Method ==============================
template <class KeyType>
bst<KeyType>& bst<KeyType>::deepCopy(Node<KeyType>* subtreeRoot)
// PreConditions:
// PostConditions:
{
	if(subtreeRoot != NULL) //works from the root so this is okay
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
// PreConditions: Root cannot be null
// PostConditions:  Return max item

{
	return helpMax(root);
}


// ============================== Max Helper Method ============================
template <class KeyType>
KeyType* bst<KeyType>::helpMax(Node<KeyType>* subtreeRoot) const
// PreConditions: Root cannot be null
// PostConditions:  Return min item

{
	Node<KeyType>* tmp = subtreeRoot; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->right != NULL)
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
// PreConditions: Root cannot be null
// PostConditions:  Return min item

{
	Node<KeyType> *result = helpMin(root);
	if (result != NULL) {
		return &(result->key);
	} else {
		return NULL;
	}
}


// ============================== Min Helper Method ============================
template <class KeyType>
Node<KeyType>* bst<KeyType>::helpMin(Node<KeyType>* subtreeRoot) const
// PreConditions: Root cannot be null
// PostConditions:  Return min item

{
	Node<KeyType>* tmp = subtreeRoot; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->left != NULL)
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
// PreConditions: Root cannot be null
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
// PreConditions: Root cannot be null
// PostConditions:  Return successor of k

{
  Node<KeyType>* tmp = helpGet(k); //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node<KeyType>* y;
    if (tmp->right != NULL)
    {
      tmp = tmp->right; //min of right subtree most immediate successor
      return helpMin(tmp);
    }

    y = tmp->parent;
    while (y != NULL && tmp == y->right)
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
// PreConditions: Root cannot be null
// PostConditions:  Return predecessor of k

{
  Node<KeyType>* tmp = helpGet(k); //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node<KeyType>* y;
    if (tmp->left != NULL)
    {
      tmp = tmp->left; //max of right subtree will be most immediate predecessor
      return helpMax(tmp);
    }

    y = tmp->parent;
    while (y != NULL && tmp == y->left)
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
// PreConditions:
// PostConditions:  Make current tree equivalent to tree
{
	clearNodes();
	deepCopy(tree.root);
	return *this;
}


// =============================== InOrder Method ==============================
template <class KeyType>
string bst<KeyType>::inOrder() const
// PreConditions:
// PostConditions:

{
	vector<KeyType> s;
	recInOrder(root, s);
	ostringstream vts;

	if (!s.empty())	// looked at https://www.geeksforgeeks.org/transform-vector-string/ to convert to string
  {
    // Convert all but the last element to avoid a trailing ","
    copy(s.begin(), s.end()-1,
        ostream_iterator<int>(vts, ", "));

    // Now add the last element with no delimiter

    vts << s.back();
  }

	return vts.str();
}


// =========================== InOrder Recursive Method ========================
template <class KeyType>
vector<KeyType> bst<KeyType>::recInOrder(Node<KeyType>* subtreeRoot, vector<KeyType> &s) const
// PreConditions:
// PostConditions:

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
// PreConditions:
// PostConditions:

{
	vector<KeyType> s;
	recPreOrder(root, s);
	ostringstream vts;

	if (!s.empty())	// looked at https://www.geeksforgeeks.org/transform-vector-string/ to convert to string
  {
    // Convert all but the last element to avoid a trailing ","
    copy(s.begin(), s.end()-1,
        ostream_iterator<int>(vts, ", "));

    // Now add the last element with no delimiter
    vts << s.back();
  }

	return vts.str();
}


// ========================== PreOrder Recursive Method ========================
template <class KeyType>
vector<KeyType> bst<KeyType>::recPreOrder(Node<KeyType>* subtreeRoot, vector<KeyType> &s) const
// PreConditions:
// PostConditions:

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
// PreConditions:
// PostConditions:

{
	vector< Node<KeyType>* > s;
	recPostOrder(root, s);
	ostringstream vts;

	if (!s.empty())	// looked at https://www.geeksforgeeks.org/transform-vector-string/ to convert to string
  {
    // Convert all but the last element to avoid a trailing ","
    //copy(s.begin(), s.end()-1,
        //ostream_iterator<int>(vts, ", "));
    for (int i=0; i<s.size()-1; i++) {
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
// PreConditions:
// PostConditions:

{
  if(subtreeRoot != NULL) //works from the root so this is okay
  {
    recPostOrder(subtreeRoot->left, s);
    recPostOrder(subtreeRoot->right, s);
    s.push_back(subtreeRoot);
  }

	return s;
}
