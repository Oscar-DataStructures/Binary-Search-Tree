/*
Nicholas Reichert, Oscar Martinez
CS 271
Dr. Lall
Project 5
*/

#ifndef _bst_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class KeyType>
class Node
{
	public:

		KeyType key; //value held in node

		Node* parent; //parent node
		Node* left; //left child
		Node* right; //right child

		Node(KeyType key);
		//add private root?
};


template <class KeyType>
class bst
{
	public:
		bst(); //constructor
		~bst(); //deconstructor
		bst(const bst<KeyType>& tree); //copy constructor
		bool empty() const; // return true if empty; false o/w

		KeyType* get(KeyType k) const; // return first item with key equal to k

		void insert(KeyType k); // insert k into the tree
		void remove(KeyType k); // delete first item with key equal to k

		KeyType* maximum() const; // return the maximum item
		KeyType* minimum()const ; // return the minimum item

		KeyType* successor(const KeyType& k) const; // return the successor of k
		KeyType* predecessor(const KeyType& k) const; // return the predecessor of k

		bst<KeyType>& operator=(const bst<KeyType>& tree); // assignment operator

		std::string inOrder() const; // return string of items from an inorder traversal
		std::string preOrder() const; // return string of items from a preorder traversal
		std::string postOrder() const; // return string of items from a postorder traversal

	private:
		Node<KeyType*> recursiveInsert(Node<KeyType*> root, KeyType* k);
		void recursiveRemove(Node<KeyType*> root, KeyType* k);

		vector<KeyType*> recInOrder(Node<KeyType*> root, vector<KeyType*> s) const;
		vector<KeyType*> recPreOrder(Node<KeyType*> root, vector<KeyType*> s) const;
		vector<KeyType*> recPostOrder(Node<KeyType*> root, vector<KeyType*> s) const;

		Node<KeyType> *root;

		vector<KeyType*> s;
};

#include "bst.cpp"

#endif

