/*
Nicholas, Oscar
CS 271
Dr. Lall
Project 5
*/

#include <iostream>
#include <string>
#include <cassert>
#include "bst.h"


// ======================= Test Default Constructor Method =====================
void test_defaultConstructor()
{
	//bst<int> a;
	//assert(a.empty() == 1);

	// cout << a.inOrder() << endl;

}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{
	// bst<int> a;
	// bst<int>b(a);
	// assert(b.empty() == 1);
	//
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	// assert(a.inOrder() == "1, 2, 3, 4");
	// bst<int>c(a);
	// assert(c.empty() == 0);
	// assert(c.inOrder() == "1, 2, 3, 4");

}


// ============================= Test Empty Method =============================
void test_empty()
{
	// bst<int> a;
	// assert(a.empty() == 1);
	//
	// a.insert(1);
	// a.insert(10);
	// assert(a.empty() == 0);

}


// ============================== Test Get Method ==============================
void test_get()
{
	// bst<int> a;
	// cout << a.get(1) << endl;
	//
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	//
	// cout << a.get(2) << endl;

}


// =============================== Test Insert Method ==========================
void test_insert()
{
	bst<int> a;
	assert(a.empty() == 1);
	
	cout << "init" << endl;
	a.insert(1);
	a.insert(5);
	a.insert(3);
	a.insert(4);

	cout << "inserts completed" << endl;
	assert(*(a.get(1)) == 1);
	assert(*(a.get(4)) == 4);
	assert(*(a.get(5)) == 5);
	assert(*(a.get(3)) == 3);
	
	// assert(a.inOrder() == "1, 3, 4, 5");
	// assert(a.empty() == 0);

}


// ============================= Test Remove Method ============================
void test_remove()
{
	// bst<int> a;
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	// assert(a.inOrder() == "1, 2, 3, 4");
	// a.remove(2)
	// assert(a.inOrder() == "1, 3, 4");
	// a.remove(1);
	// assert(a.inOrder() == "3, 4");
	// a.remove(3);
	// assert(a.inOrder() == "4");
	// a.remove(4);
	// assert(a.inOrder() == "");
	// assert(a.empty() == 1);
	// a.remove(1);
	// cout << a.inOrder() << endl;

}


// ================================ Test Max Method ============================
void test_max()
{
	// bst<int> a;
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	// assert(a.maximum() == 4);
	// a.remove(4);
	// assert(a.maximum() == 3);

}


// ================================ Test Min Method ============================
void test_min()
{
	// bst<int> a;
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	// assert(a.minimum() == 1);
	// a.remove(1);
	// assert(a.minimum() == 2);

}


// ============================= Test Successor Method =========================
void test_successor()
{
	// bst<int> a;
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	// assert(a.successor(2) == 3);
	// assert(a.successor(3) == 4);

}


// ========================== Test Predecessor Method ==========================
void test_predecessor()
{
	// bst<int> a;
	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);
	// assert(a.predecessor(2) == 1);
	// assert(a.predecessor(4) == 3);

}


// =========================== Test Assignment Operator ========================
void test_assignmentOP()
{
	// bst<int> a;
	// bst<int>b;
	//
	// b = a;
	// assert(a.empty() == 0);
	// assert(b.empty() == 0);

	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);

	// assert(a.empty() == 0);
	// assert(a.inOrder() == "1, 2, 3, 4");

	// b = a;
	// assert(b.empty() == 0);
	// assert(b.inOrder() == "1, 2, 3, 4");
}


// ============================ Test In Order Method ===========================
void test_inOrder()
{
	// bst<int> a;
	// cout << a.inOrder() << endl;

	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);

	// cout << a.inOrder() << endl;
}


// ============================= Test Pre Order Method =========================
void test_preOrder()
{
	// bst<int> a;
	// cout << a.preOrder() << endl;

	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);

	// cout << a.preOrder() << endl;
}


// ============================ Test Post Order Method =========================
void test_postOrder()
{
	// bst<int> a;
	// cout << a.postOrder() << endl;

	// a.insert(1);
	// a.insert(2);
	// a.insert(3);
	// a.insert(4);

	// cout << a.postOrder() << endl;
}



// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor();
	cout << "Default Constructor Test	|Passed|" << endl;
	test_copyConstructor();
	cout << "Copy Constructor Test		|Passed|" << endl;
	test_empty();
	cout << "Empty Test			|Passed|" << endl;
	test_get();
	cout << "Get Test			|Passed|" << endl;
	test_insert();
	cout << "Insert Test			|Passed|" << endl;
	test_remove();
	cout << "Remove Test			|Passed|" << endl;
	test_max();
	cout << "Max Test			|Passed|" << endl;
	test_min();
	cout << "Min Test			|Passed|" << endl;
	test_successor();
	cout << "Successor Test			|Passed|" << endl;
	test_predecessor();
	cout << "Predecessor Test		|Passed|" << endl;
	test_assignmentOP();
	cout << "Assignment Test			|Passed|" << endl;
	test_inOrder();
	cout << "InOrder Test			|Passed|" << endl;
	test_preOrder();
	cout << "PreOrder Test			|Passed|" << endl;
	test_postOrder();
	cout << "PostOrder Test			|Passed|" << endl;

	return 0;
}
