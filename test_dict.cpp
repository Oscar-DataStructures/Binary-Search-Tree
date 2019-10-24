/*
Nicholas, Oscar
CS 271
Dr. Lall
Project 5
*/

#include <iostream>
#include <string>
#include <cassert>
#include "dict.h"

struct KVPair {
	string key;
	string value;
};
ostream& operator<<(ostream& os, const KVPair& dt) {
	return os << dt.key;
}
bool operator< (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key < kv2.key;
}
bool operator> (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key > kv2.key;
}
bool operator!= (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key != kv2.key;
}
bool operator== (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key == kv2.key;
}





// ======================= Test Default Constructor Method =====================
void test_defaultConstructor()
{
	Dictionary<KVPair> dictA;
	assert(dictA.empty() == 1);
}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{
	Dictionary<KVPair> dictA;

	KVPair pair1;
	pair1.key = "apple";
	pair1.value = "yum";
	dictA.insert(pair1);

	KVPair pair2;
	pair2.key = "banana";
	pair2.value = "yummy";
	dictA.insert(pair2);

	Dictionary<KVPair> dictCopy(dictA);

	KVPair getObj;
	getObj.key = "apple";
	assert(dictA.get(getObj)->value == "yum");
	assert(dictCopy.get(getObj)->value == "yum");

	getObj.key = "banana";
	assert(dictA.get(getObj)->value == "yummy");
	assert(dictCopy.get(getObj)->value == "yummy");

	KVPair pairA;
	pairA.key = "onlyA";
	pairA.value = "yeah";
	dictA.insert(pairA);

	getObj.key = "onlyA";
	assert(dictA.get(getObj)->value == "yeah");
	assert(dictCopy.get(getObj) == NULL);

	KVPair pairCopy;
	pairCopy.key = "onlyCopy";
	pairCopy.value = "yeah";
	dictCopy.insert(pairCopy);

	getObj.key = "onlyCopy";
	assert(dictCopy.get(getObj)->value == "yeah");
	assert(dictA.get(getObj) == NULL);
}


// ============================= Test Empty Method =============================
void test_empty()
{
	Dictionary<KVPair> dictA;
	assert(dictA.empty() == 1);

	KVPair pair1;
	pair1.key = "apple";
	pair1.value = "yum";
	dictA.insert(pair1);

	assert(dictA.empty() == 0);
}

// =============================== Test Insert and Get Methods ==========================
void test_insert_and_get()
{
	Dictionary<KVPair> dictA;

	KVPair pair1;
	pair1.key = "apple";
	pair1.value = "yum";
	dictA.insert(pair1);

	KVPair pair2;
	pair2.key = "banana";
	pair2.value = "yummy";
	dictA.insert(pair2);

	KVPair pair3;
	pair3.key = "aardvark";
	pair3.value = "eww";
	dictA.insert(pair3);

	KVPair pair4;
	pair4.key = "garbage";
	pair4.value = "notFood";
	dictA.insert(pair4);

	// Now, test if we can find the values that were just inserted.
	KVPair get1;
	get1.key = "apple";
	assert(dictA.get(get1)->value == "yum");

	KVPair get4;
	get4.key = "garbage";
	assert(dictA.get(get4)->value == "notFood");

	KVPair get3;
	get3.key = "aardvark";
	assert(dictA.get(get3)->value == "eww");

	KVPair get2;
	get2.key = "banana";
	assert(dictA.get(get2)->value == "yummy");

	// Test checking a key that's not in the Dictionary.
	KVPair getInvalid;
	getInvalid.key = "asdfasf";
	assert(dictA.get(getInvalid) == NULL);
}


// ============================= Test Remove Method ============================
void test_remove()
{
	Dictionary<KVPair> dictA;

	KVPair pair1;
	pair1.key = "apple";
	pair1.value = "yum";
	dictA.insert(pair1);

	KVPair pair2;
	pair2.key = "banana";
	pair2.value = "yummy";
	dictA.insert(pair2);

	KVPair pair3;
	pair3.key = "aardvark";
	pair3.value = "eww";
	dictA.insert(pair3);

	KVPair getObj;
	getObj.key = "apple";
	assert(dictA.get(getObj)->value == "yum");
	getObj.key = "banana";
	assert(dictA.get(getObj)->value == "yummy");
	getObj.key = "aardvark";
	assert(dictA.get(getObj)->value == "eww");

	getObj.key = "apple";
	dictA.remove(getObj);

	getObj.key = "apple";
	assert(dictA.get(getObj) == NULL);
	getObj.key = "banana";
	assert(dictA.get(getObj)->value == "yummy");
	getObj.key = "aardvark";
	assert(dictA.get(getObj)->value == "eww");

	getObj.key = "banana";
	dictA.remove(getObj);

	getObj.key = "apple";
	assert(dictA.get(getObj) == NULL);
	getObj.key = "banana";
	assert(dictA.get(getObj) == NULL);
	getObj.key = "aardvark";
	assert(dictA.get(getObj)->value == "eww");

	getObj.key = "aardvark";
	dictA.remove(getObj);

	getObj.key = "apple";
	assert(dictA.get(getObj) == NULL);
	getObj.key = "banana";
	assert(dictA.get(getObj) == NULL);
	getObj.key = "aardvark";
	assert(dictA.get(getObj) == NULL);
}


// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor();
	cout << "Default Constructor Test		|Passed|" << endl;
	test_copyConstructor();
	cout << "Copy Constructor Test			|Passed|" << endl;
	test_empty();
	cout << "Empty Test				|Passed|" << endl;
	test_insert_and_get();
	cout << "Insert and Get Test			|Passed|" << endl;
	test_remove();
	cout << "Remove Test				|Passed|" << endl;

	return 0;
}
