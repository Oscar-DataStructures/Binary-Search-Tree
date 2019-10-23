/*
Nicholas Reichert, Oscar Martinez
CS 271
Dr. Lall
Project 5
*/

#include <iostream>
#include <string>
#include "bst.h"

template <class KeyType>
class Dictionary : public bst<KeyType>
{
  public:
    Dictionary(); //constructor
    ~Dictionary(); //deconstructor
    Dictionary(const Dictionary<KeyType>& dict); //copy constructor

    bool empty() const; // return true if empty; false o/w

    KeyType *get(const KeyType& k) const; // return first item with key equal to k

    void insert(KeyType *k); // insert k into the tree, add unique key error
    void remove(const KeyType& k); // delete first item with key equal to k
};

#include "dict.cpp"

class KeyError{};

