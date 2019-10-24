/*
Nicholas Reichert, Oscar Martinez
CS 271
Dr. Lall
Project 5
*/

#ifndef _bst_h
#define _bst_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class KeyType>
class Node
{
	public:

		KeyType key; //value held in node

		Node<KeyType>* parent; //parent node
		Node<KeyType>* left; //left child
		Node<KeyType>* right; //right child
};

template <class KeyType>
Node<KeyType>* newNode(KeyType key);



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
		bst<KeyType>& deepCopy(Node<KeyType>* subtreeRoot); // copy method for = operator and copy constructor

		KeyType* maximum() const; // return the maximum item
		KeyType* minimum()const ; // return the minimum item

		KeyType* successor(const KeyType& k) const; // return the successor of k
		KeyType* predecessor(const KeyType& k) const; // return the predecessor of k

		bst<KeyType>& operator=(const bst<KeyType>& tree); // assignment operator

		std::string inOrder() const; // return string of items from an inorder traversal
		std::string preOrder() const; // return string of items from a preorder traversal
		std::string postOrder() const; // return string of items from a postorder traversal

	protected:
		void clearNodes();
		Node<KeyType>* recursiveRemove(Node<KeyType>* root, KeyType k);

		Node<KeyType>* helpMin(Node<KeyType>* subtreeRoot) const;
		KeyType* helpMax(Node<KeyType>* subtreeRoot) const;
		Node<KeyType>* helpGet(KeyType k) const;

		Node<KeyType>* successorNode(const KeyType& k) const;

		vector<KeyType> recInOrder(Node<KeyType>* subtreeRoot, vector<KeyType>& s) const;
		vector<KeyType> recPreOrder(Node<KeyType>* subtreeRoot, vector<KeyType>& s) const;
		vector< Node<KeyType>* > recPostOrder(Node<KeyType>* subtreeRoot, vector< Node<KeyType>* > &s) const;

		Node<KeyType>* root;
};

#include "bst.cpp"

#endif
