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
Dictionary<KeyType>::Dictionary() : bst<KeyType>() {}

// =============================== Copy Constructor ============================
template <class KeyType>
Dictionary<KeyType>::Dictionary(const Dictionary<KeyType>& dict) : bst<KeyType>(dict) {}

// ================================= Empty Method ==============================
template <class KeyType>
bool Dictionary<KeyType>::empty() const {
				return bst<KeyType>::empty();
}


// ================================= Get Method ================================
template <class KeyType>
KeyType* Dictionary<KeyType>::get(const KeyType& k) const {
				return bst<KeyType>::get(k);
}


// ================================ Insert Method ==============================
template <class KeyType>
void Dictionary<KeyType>::insert(KeyType k)
// PreConditions:
// PostConditions:
{
				KeyType *exists = get(k);
				if (exists == NULL) {
								bst<KeyType>::insert(k);
				} else {
								throw KeyError();
				}
}


// ================================ Remove Method ==============================
template <class KeyType>
void Dictionary<KeyType>::remove(const KeyType& k) {
				bst<KeyType>::remove(k);
}


