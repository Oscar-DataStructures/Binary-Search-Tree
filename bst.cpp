/*
Nicholas Reichert, Oscar Martinez
CS 271
Dr. Lall
Project 5
*/

#include <sstream>
#include <string>
#include <typeinfo>


using namespace std;


//============================ New Node Function================================
template <class KeyType>
KeyType* newNode(KeyType* key)
//Preconditions:
//Postcondition:

{
	KeyType* node = new Node<KeyType*>();		//dynamically allocate Node
	node->key = key;
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
  return (&root == NULL); //if root is null then the tree is empty
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* bst<KeyType>::get(const KeyType& k) const
// PreConditions: Tree must exist
// PostConditions:  Return first item that has key k

{
  tmp = &root; //this way we dont change the root pointer
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
void bst<KeyType>::insert(KeyType* k)
// PreConditions:
// PostConditions:

{
  recursiveInsert(this->root, k);
}


// =========================== Recursive Insert Method =========================
template <class KeyType>
Node<KeyType*> bst<KeyType>::recursiveInsert(Node<KeyType*> root, KeyType* k) //added parameter to allow recursion, we could also make new
//private methods that do the recursion and just call them here
// PreConditions:
// PostConditions:  K is inserted into tree
//this can be done easier with recursion(like the walks) or we can use Lall's iterative way

{
  tmp = &root; //this way we dont change the root pointer
  if (tmp == NULL)
    tmp = newNode(k); //new node to be inserted, works with assignment operator if tree empty

  if (k < tmp->key) //go down left side
    tmp->left = recursiveInsert(tmp->left, k);

  else if (k > root->key) //go down right side
    tmp->right = recursiveInsert(tmp->right, k);

  return tmp;
}


// ================================ Remove Method ==============================
template <class KeyType>
void bst<KeyType>::remove(const KeyType& k) //added parameter to allow recursion, we could also make new
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
  tmp = &root; //this way we dont change the root pointer
  if (tmp == NULL)
    return; //ends the function since there is nothing to remove

  if (k < tmp->key) //go down left side
    tmp->left = recursiveRemove(tmp->left, k);

  else if (k > root->key) //go down right side
    tmp->right = recursiveRemove(tmp->right, k);

  //last possibility is that the root itself is the one that needs to be removed

}


// ================================== Max Method ===============================
template <class KeyType>
KeyType* bst<KeyType>::maximum() const
// PreConditions: Root cannot be null
// PostConditions:  Return max item

{
  tmp = &root; //this way we dont change the root pointer
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
  tmp = &root; //this way we dont change the root pointer
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
  tmp = &root; //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node<KeyType*> y;
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
  tmp = &root; //this way we dont change the root pointer
  if (tmp != NULL)
  {
    Node<KeyType*> y;
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
	root = tree->root;

}


// =============================== InOrder Method ==============================
template <class KeyType>
string bst<KeyType>::inOrder() const
// PreConditions:
// PostConditions:

{
	return (recInOrder(root, s));
}


// =========================== InOrder Recursive Method ========================
template <class KeyType>
vector<KeyType*> bst<KeyType>::recInOrder(Node<KeyType*> root, vector<KeyType*> s) const
// PreConditions:
// PostConditions:

{
  if(&root != NULL) //works from the root so this is okay
  {
    recInOrder(root->left, s);
    s.push_back(root->key);
    recInOrder(root->right, s);
  }

	return s;
}


// ============================== PreOrder Method ==============================
template <class KeyType>
string bst<KeyType>::preOrder() const
// PreConditions:
// PostConditions:

{
	return (recPreOrder(root, s));
}


// ========================== PreOrder Recursive Method ========================
template <class KeyType>
vector<KeyType*> bst<KeyType>::recPreOrder(Node<KeyType*> root, vector<KeyType*> s) const
// PreConditions:
// PostConditions:

{
  if(&root != NULL) //works from the root so this is okay
  {
    s.push_back(&root->key);
    recPreOrder(root->left);
    recPreOrder(root->right);
  }

	return s;
}


// ============================= PostOrder Method ==============================
template <class KeyType>
string bst<KeyType>::postOrder() const
// PreConditions:
// PostConditions:

{
	return recPostOrder(root, s);
}


// ======================== PostOrder Recursive Method =========================
template <class KeyType>
vector<KeyType*> bst<KeyType>::recPostOrder(Node<KeyType*> root, vector<KeyType*> s) const
// PreConditions:
// PostConditions:

{
  if(&root != NULL) //works from the root so this is okay
  {
    recPostOrder(root->left);
    recPostOrder(root->right);
    s.push_back(&root->key);
  }

	return s;
}
