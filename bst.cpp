/*
Nicholas, Oscar
CS 271
Dr. Lall
Project 5
*/

#include <sstream>
#include <string>
#include <typeinfo>


using namespace std;


//============================ New Node Function================================
Node* newNode(int value)
//Preconditions:
//Postcondition:

{
	Node* node = new Node();		//dynamically allocate Node
	node->key = value;
	node->left = NULL;
	node->right = NULL;    //New Node with no pointers to any values

	return node;
}


// ================================= Constructor ===============================
template <class KeyType>
bst<KeyType>::bst()
// PreConditions:
// PostConditions:

{
  root = NULL;
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
bst<KeyType>::bst(const bst<KeyType>& tree)
// PreConditions:
// PostConditions:

{
  //use preOrder walk to copy
}


// ================================= Empty Method ==============================
template <class KeyType>
bool bst<KeyType>::empty() const
// PreConditions: Tree must exist
// PostConditions:  Return True if empty, False if not

{
  return (root == NULL); //if root is null then the tree is empty
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* bst<KeyType>::get(const KeyType& k) const
// PreConditions: Tree must exist
// PostConditions:  Return first item that has key k

{
  tmp = root; //this way we dont change the root pointer
  while (tmp != NULL || tmp->key != k)    //iterative solution allows us to search without having node parameter
  {

    if (tmp->key > k)
      tmp = tmp->left;

    else
      tmp = tmp->right;

  }

  return tmp;
}


// ================================ Insert Method ==============================
template <class KeyType>
void bst<KeyType>::insert(Node* root, KeyType *k) //added parameter to allow recursion, we could also make new
//private methods that do the recursion and just call them here
// PreConditions:
// PostConditions:  K is inserted into tree
//this can be done easier with recursion(like the walks) or we can use Lall's iterative way

{
  tmp = root; //this way we dont change the root pointer
  if (tmp == NULL)
    tmp = newNode(k); //new node to be inserted, works with assignment operator if tree empty

  if (k < tmp->key) //go down left side
    tmp->left = insert(tmp->left, k);

  else if (k > root->key) //go down right side
    tmp->right = insert(tmp->right, k);

    //actual insertion can be done with a return but this is void funct
}


// ================================ Remove Method ==============================
template <class KeyType>
void bst<KeyType>::remove(Node* root, const KeyType& k) //added parameter to allow recursion, we could also make new
//private methods that do the recursion and just call them here
// PreConditions:
// PostConditions:  Delete first item that has key k
//can also be done recursively, Lalls way we will need transplant funct

{
  tmp = root; //this way we dont change the root pointer
  if (tmp == NULL)
    return; //ends the function since there is nothing to remove

  if (k < tmp->key) //go down left side
    tmp->left = remove(tmp->left, k);

  else if (k > root->key) //go down right side
    tmp->right = remove(tmp->right, k);

  //last possibility is that the root itself is the one that needs to be removed

}


// ================================== Max Method ===============================
template <class KeyType>
KeyType* bst<KeyType>::maximum() const
// PreConditions: Root cannot be null
// PostConditions:  Return max item

{
  tmp = root; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->right != NULL)
      {
        tmp = tmp->right;
      }

      return tmp;
    }
}


// ================================= Min Method ================================
template <class KeyType>
KeyType* bst<KeyType>::minimum() const
// PreConditions: Root cannot be null
// PostConditions:  Return min item

{
  tmp = root; //this way we dont change the root pointer
  if (tmp != NULL)
    {
      while (tmp->left != NULL)
      {
        tmp = tmp->left;
      }

      return tmp;
    }
}


// ============================= Successor Method ==============================
template <class KeyType>
KeyType* bst<KeyType>::successor(const KeyType& k) const
// PreConditions: Root cannot be null
// PostConditions:  Return successor of k

{
  tmp = root; //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node* y;
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

    return y;
  }
}


// ============================ Predecessor Method =============================
template <class KeyType>
KeyType* bst<KeyType>::predecessor(const KeyType& k) const
// PreConditions: Root cannot be null
// PostConditions:  Return predecessor of k

{
  tmp = root; //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node* y;
    if (tmp->left != NULL)
    {
      tmp = tmp->left; //max of right subtree will be most immediate predecessor
      return maximum();
    }

    y = tmp->left;
    while (y != NULL && tmp->left == y)
    {
      tmp = y;
      y = tmp->left; //revisit. Potential to lead off leaves
    }

    return y;
  }
}


// ============================= Assignment Operator ===========================
template <class KeyType>
bst<KeyType>& bst<KeyType>::operator=(const bst<KeyType>& tree)
// PreConditions:
// PostConditions:  Make current tree equivalent to tree

{

}

// =============================== InOrder Method ==============================
template <class KeyType>
std::string bst<KeyType>::inOrder() const
// PreConditions:
// PostConditions:  r

{
  if(root != NULL) //works from the root so this is okay
  {
    inOrder(root->left);
    cout << root->key << ", "; //convert to string to return, hold string in parameter?
    inOrder(root->right);
  }
}


// ============================== PreOrder Method ==============================
template <class KeyType>
std::string bst<KeyType>::preOrder() const
// PreConditions:
// PostConditions:

{
  if(root != NULL) //works from the root so this is okay
  {
    cout << root->key << ", "; //convert to string to return, hold string in parameter?
    preOrder(root->left);
    preOrder(root->right);
  }
}


// ============================= PostOrder Method ==============================
template <class KeyType>
std::string bst<KeyType>::postOrder() const
// PreConditions:
// PostConditions:

{
  if(root != NULL) //works from the root so this is okay
  {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << ", "; //convert to string to return, hold string in parameter?
  }
}
