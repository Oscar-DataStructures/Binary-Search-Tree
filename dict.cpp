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



// ================================= Constructor ===============================
template <class KeyType>
Dictionary<KeyType>::Dictionary() : bst<KeyType>()
//Preconditions:  N/A
//Postcondition:  Inherits bst constructor
{

}


// =============================== Copy Constructor ============================
template <class KeyType>
Dictionary<KeyType>::Dictionary(const Dictionary<KeyType>& dict) : bst<KeyType>(dict)
//Preconditions:    N/A
//Postcondition:    Inherits bst copy constructor
{

}


// ================================= Empty Method ==============================
template <class KeyType>
bool Dictionary<KeyType>::empty() const
//Preconditions:  Tree must exist
//Postcondition:  Inherits bst empty method to return whether the dict is empty
{
  return bst<KeyType>::empty();     //bst inheritance
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* Dictionary<KeyType>::get(const KeyType& k) const
//Preconditions:    Tree must exist
//Postcondition:    Inherits bst helpGet method to return key of dict or null if not found
{
  Node<KeyType>* output = bst<KeyType>::helpGet(k);     //bst inheritance
  if (output != NULL)
  {
    return &(output->key);
  }

  else
  {
    return NULL;
  }
}


// ================================ Insert Method ==============================
template <class KeyType>
void Dictionary<KeyType>::insert(KeyType k)
// PreConditions:   N/A
// PostConditions:  Inherits bst insert method to insert into dict value k
{
  Node<KeyType>* exists = bst<KeyType>::helpGet(k);

  if (exists == NULL)
  {
    bst<KeyType>::insert(k);      //bst inheritance
  }

  else
  {
    throw KeyError();             //KeyError caught
  }

}


// ================================ Remove Method ==============================
template <class KeyType>
void Dictionary<KeyType>::remove(const KeyType& k)
//Preconditions:  Tree must exist
//Postcondition:  Inherits remove method from bst to remove value k from dict
{
  bst<KeyType>::remove(k);      //bst inheritance
}
