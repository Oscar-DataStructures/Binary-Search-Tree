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


//============================ New Node Function================================
template <class KeyType>
Node<KeyType>* newNode(KeyType key)
//Preconditions:
//Postcondition:

{
	Node<KeyType>* node = new Node<KeyType>();		//dynamically allocate Node
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
  //use postOrder walk for deletion
}


// =============================== Copy Constructor ============================
template <class KeyType>
bst<KeyType>::bst(const bst<KeyType>* tree) //TODO: Come back to this
// PreConditions:
// PostConditions:

{
  deepCopy(tree);
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
    return &(tmp->key);
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
    y->left = z;

	else
    y->right = z;
  //recursiveInsert(this->root, k);
}

/*
// =========================== Recursive Insert Method =========================
template <class KeyType>
Node<KeyType*> bst<KeyType>::recursiveInsert(Node<KeyType*> root, KeyType* k) //added parameter to allow recursion, we could also make new
//private methods that do the recursion and just call them here
// PreConditions:
// PostConditions:  K is inserted into tree
//this can be done easier with recursion(like the walks) or we can use Lall's iterative way

{
  Node<KeyType> *tmp = &root;
  if (tmp == NULL)
    tmp = newNode(k); //new node to be inserted, works with assignment operator if tree empty

  if (k < tmp->key) //go down left side
    tmp->left = recursiveInsert(tmp->left, k);

  else if (k > root->key) //go down right side
    tmp->right = recursiveInsert(tmp->right, k);

  return tmp;
}
*/

// ================================ Remove Method ==============================
template <class KeyType>
void bst<KeyType>::remove(KeyType k) //added parameter to allow recursion, we could also make new
// PreConditions:
// PostConditions:
{
  recursiveRemove(this->root, k);
}


// ============================= Remove Recursive Method =======================
template <class KeyType>
void bst<KeyType>::recursiveRemove(Node<KeyType*> root, KeyType* k) //added parameter to allow recursion, we could also make new
//private methods that do the recursion and just call them here
// PreConditions:
// PostConditions:  Delete first item that has key k
//can also be done recursively, Lalls way we will need transplant funct

{
  /*
  tmp = &root; //this way we dont change the root pointer
  if (tmp == NULL)
    return; //ends the function since there is nothing to remove

  if (k < tmp->key) //go down left side
    tmp->left = recursiveRemove(tmp->left, k);

  else if (k > root->key) //go down right side
    tmp->right = recursiveRemove(tmp->right, k);

  //last possibility is that the root itself is the one that needs to be removed

  */
}


// ============================== Deep Copy Method ==============================
template <class KeyType>
bst<KeyType>& bst<KeyType>::deepCopy(Node<KeyType>* subtreeRoot)
// PreConditions:
// PostConditions:
{
	if(subtreeRoot != NULL) //works from the root so this is okay
  {
		Node<KeyType> *x = newNode(subtreeRoot->key);

		this->insert(x->key);
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
  Node<KeyType>* tmp = root; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->right != NULL)
      {
        tmp = tmp->right;
      }

      return &(tmp->key);
    }
}


// ================================= Min Method ================================
template <class KeyType>
KeyType* bst<KeyType>::minimum() const
// PreConditions: Root cannot be null
// PostConditions:  Return min item

{
	Node<KeyType>* tmp = root; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->left != NULL)
      {
        tmp = tmp->left;
      }

      return &(tmp->key);
    }
}


// ============================= Successor Method ==============================
template <class KeyType>
KeyType* bst<KeyType>::successor(const KeyType& k) const
// PreConditions: Root cannot be null
// PostConditions:  Return successor of k

{
  Node<KeyType>* tmp = root; //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node<KeyType>* y;
    if (tmp->right != NULL)
    {
      tmp = tmp->right; //min of right subtree most immediate successor
      return minimum();
    }

    y = tmp->parent;
    while (y != NULL && tmp == y->right)
    {
      tmp = y;
      y = tmp->parent;
    }

    return &(y->key);
  }
}


// ============================ Predecessor Method =============================
template <class KeyType>
KeyType* bst<KeyType>::predecessor(const KeyType& k) const
// PreConditions: Root cannot be null
// PostConditions:  Return predecessor of k

{
  // Node<KeyType>* tmp = root; //this way we dont change the root pointer
  // if (tmp != NULL)
  // {
  //   Node<KeyType*> y;
  //   if (tmp->left != NULL)
  //   {
  //     tmp = tmp->left; //max of right subtree will be most immediate predecessor
  //     return maximum();
  //   }
	//
  //   y = tmp->left;
  //   while (y != NULL && tmp->left == y)
  //   {
  //     tmp = y;
  //     y = tmp->left; //revisit. Potential to lead off leaves
  //   }
	//
  //   return y;
  // }
}


// ============================= Assignment Operator ===========================
template <class KeyType>
bst<KeyType>& bst<KeyType>::operator=(const bst<KeyType>* tree)
// PreConditions:
// PostConditions:  Make current tree equivalent to tree

{
	deepCopy(tree);
	return this;
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
	vector<KeyType> s;
	recPostOrder(root, s);
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


// ======================== PostOrder Recursive Method =========================
template <class KeyType>
vector<KeyType> bst<KeyType>::recPostOrder(Node<KeyType>* subtreeRoot, vector<KeyType> &s) const
// PreConditions:
// PostConditions:

{
  if(subtreeRoot != NULL) //works from the root so this is okay
  {
    recPostOrder(subtreeRoot->left, s);
    recPostOrder(subtreeRoot->right, s);
    s.push_back(subtreeRoot->key);
  }

	return s;
}
