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
	bst<int> a;
	assert(a.empty() == 1);

	cout << a.inOrder() << endl;

}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{
	bst<int> a;
	bst<int>b(a);
	assert(a.empty() == 1);
	assert(b.empty() == 1);

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	assert(a.inOrder() == "1, 2, 3, 4");
	bst<int>c(a);
	assert(c.empty() == 0);
	assert(c.inOrder() == "1, 2, 3, 4");

}


// ============================= Test Empty Method =============================
void test_empty()
{
	bst<int> a;
	assert(a.empty() == 1);

	a.insert(1);
	a.insert(10);
	assert(a.empty() == 0);

}


// ============================== Test Get/Insert Method ==============================
void test_get_insert()
{
	bst<int> a;

	a.insert(2);
	a.insert(1);
	a.insert(3);
	a.insert(4);

	assert(a.inOrder() == "1, 2, 3, 4");
	assert(*(a.get(1)) == 1);
	assert(*(a.get(2)) == 2);
	assert(*(a.get(3)) == 3);
	assert(*(a.get(4)) == 4);
	assert(*(a.get(1)) != 3);
	assert((a.get(10)) == NULL); //dont derefrence bc null

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.inOrder() == "3, 4, 7, 8, 9, 10, 12, 13, 14");
	assert(*(b.get(3)) == 3);
	assert(*(b.get(4)) == 4);
	assert(*(b.get(7)) == 7);
	assert(*(b.get(8)) == 8);
	assert(*(b.get(9)) == 9);
	assert(*(b.get(10)) == 10);
	assert(*(b.get(12)) == 12);
	assert(*(b.get(13)) == 13);
	assert(*(b.get(14)) == 14);

	assert(*(b.get(3)) != 4);
	assert((b.get(1)) == NULL); //dont derefrence bc null

}


// ============================= Test Remove Method ============================
void test_remove()
{
	bst<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	assert(a.inOrder() == "1, 2, 3, 4");
	a.remove(1);
	assert(a.inOrder() == "2, 3, 4");
	a.remove(2);
	assert(a.inOrder() == "3, 4");
	a.remove(3);
	assert(a.inOrder() == "4");
	a.remove(4);
	assert(a.inOrder() == "");


}


// ================================ Test Max Method ============================
void test_max()
{
	bst<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	assert(*(a.maximum()) == 4);

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.maximum()) == 14);

}


// ================================ Test Min Method ============================
void test_min()
{
	bst<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	assert(*(a.minimum()) == 1);
	a.remove(1);
	assert(*(a.minimum()) == 2);

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.minimum()) == 3);
}


// ============================= Test Successor Method =========================
void test_successor()
{
	bst<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	assert(*(a.successor(1)) == 2);
	assert(*(a.successor(2)) == 3);
	assert(*(a.successor(3)) == 4);
	assert((a.successor(4)) == NULL);

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.successor(3)) == 4);
	assert(*(b.successor(4)) == 7);
	assert(*(b.successor(7)) == 8);
	assert(*(b.successor(8)) == 9);
	assert(*(b.successor(9)) == 10);
	assert(*(b.successor(10)) == 12);
	assert(*(b.successor(12)) == 13);
	assert(*(b.successor(13)) == 14);

	assert((b.successor(14)) == NULL);
}


// ========================== Test Predecessor Method ==========================
void test_predecessor()
{
	bst<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	assert((a.predecessor(1)) == NULL);
	assert(*(a.predecessor(2)) == 1);
	assert(*(a.predecessor(3)) == 2);
	assert(*(a.predecessor(4)) == 3);

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(*(b.predecessor(4)) == 3);
	assert(*(b.predecessor(7)) == 4);
	assert(*(b.predecessor(8)) == 7);
	assert(*(b.predecessor(9)) == 8);
	assert(*(b.predecessor(10)) == 9);
	assert(*(b.predecessor(12)) == 10);
	assert(*(b.predecessor(13)) == 12);
	assert(*(b.predecessor(14)) == 13);

	assert((b.predecessor(3)) == NULL);
}


// =========================== Test Assignment Operator ========================
void test_assignmentOP()
{
	bst<int> a;
	bst<int>b;

	b = a;
	assert(a.empty() == 1);
	assert(b.empty() == 1);

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	assert(a.empty() == 0);
	assert(a.inOrder() == "1, 2, 3, 4");

	b = a;
	assert(b.empty() == 0);
	assert(b.inOrder() == "1, 2, 3, 4");
}


// ============================ Test In Order Method ===========================
void test_inOrder()
{
	bst<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(2);
	a.insert(4);
	a.insert(5);

	assert(a.inOrder() == "1, 2, 3, 4, 5");

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.inOrder() == "3, 4, 7, 8, 9, 10, 12, 13, 14");
}


// ============================= Test Pre Order Method =========================
void test_preOrder()
{
	bst<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(2);
	a.insert(4);
	a.insert(5);

	assert(a.preOrder() == "3, 1, 2, 4, 5");

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.preOrder() == "10, 7, 4, 3, 8, 9, 13, 12, 14");
}


// ============================ Test Post Order Method =========================
void test_postOrder()
{
	bst<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(2);
	a.insert(4);
	a.insert(5);

	assert(a.postOrder() == "2, 1, 5, 4, 3");

	bst<int> b;

	b.insert(10);
	b.insert(7);
	b.insert(13);
	b.insert(4);
	b.insert(8);
	b.insert(12);
	b.insert(14);
	b.insert(3);
	b.insert(9);

	assert(b.postOrder() == "3, 4, 9, 8, 7, 12, 14, 13, 10");
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
	test_get_insert();
	cout << "Get Test			|Passed|" << endl;
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
