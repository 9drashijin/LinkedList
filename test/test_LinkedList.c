#include "unity.h"
#include "LinkedList.h"

void setUp(){}
void tearDown(){}

// TEST to Print the value and array
// void test_element_arrayElement_print_and_value(){
	// LinkedList *list = createLinkedList();
	// Element arrayElem[] = {{.next = &arrayElem[1], .data = 111},
							// {.next = &arrayElem[2], .data = 222},
							// {.next = &arrayElem[3], .data = 333},
							// {.next = &arrayElem[4], .data = 444},
							// {.next = NULL, .data = 555}};
	// list->head = &arrayElem[0];
	//list->tail = &arrayElem[4];
	// list->length = 5;
	// print();
// }
void test_LinkedList_is_created_and_should_be_empty(){
	LinkedList *list = createLinkedList();
	
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	
}
void test_LinkedList_delete_middle_element(){
	LinkedList *list = createLinkedList();
	Element *elem;
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 111},
							{.next = &arrayElem[2], .data = 222},
							{.next = &arrayElem[3], .data = 333},
							{.next = &arrayElem[4], .data = 444},
							{.next = NULL, .data = 555}};
	list->length = 5;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[4];
//	print(); //to test and c the address and data

	//=====================================================
	//BASIC TEST (BEFORE REMOVE) : TESTING ARRAY and DATA
	//=====================================================
	
	TEST_ASSERT_NOT_NULL(list->head); //head have value 
	TEST_ASSERT_NOT_NULL(list->tail); //tail have value
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0],list->head); // list head should be pointing at element 1, array [0]
	TEST_ASSERT_EQUAL_PTR(&arrayElem[4],list->tail); // list tail should be pointing at element 5, array [4]
	TEST_ASSERT_EQUAL(5, list->length); 			 // the length of the array should be 5 BEFORE REMOVE
	
	TEST_ASSERT_NOT_NULL(arrayElem[0].next); 		 // next -> 1, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[1].next); 		 // next -> 2, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[2].next); 		 // next -> 3, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[3].next); 		 // next -> 4, should be NOT NULL
	TEST_ASSERT_NULL(arrayElem[4].next);			 // the pointer next of last element should be NULL
	
	TEST_ASSERT_EQUAL(111, arrayElem[0].data); // element 1, array [0] data should be 111
	TEST_ASSERT_EQUAL(222, arrayElem[1].data); // element 2, array [1] data should be 222
	TEST_ASSERT_EQUAL(333, arrayElem[2].data); // element 3, array [2] data should be 333
	TEST_ASSERT_EQUAL(444, arrayElem[3].data); // element 4, array [3] data should be 444
	TEST_ASSERT_EQUAL(555, arrayElem[4].data); // element 5, array [4] data should be 555
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next); //pointer of element 1 pointing to element 2
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next); //pointer of element 2 pointing to element 3
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], arrayElem[2].next); //pointer of element 3 pointing to element 4
	TEST_ASSERT_EQUAL_PTR(&arrayElem[4], arrayElem[3].next); //pointer of element 4 pointing to element 5
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[4].next); 		 //pointer of element 5 pointing to NULL
	
	//=====================================================
	//START TEST (AFTER REMOVE) : TESTING ARRAY and DATA
	//=====================================================
	
	elem = List_delete(list, &arrayElem[2]); // AFTER remove
	
	TEST_ASSERT_NOT_NULL(elem);
	TEST_ASSERT_NOT_NULL(list->head); //head have value 
	TEST_ASSERT_NOT_NULL(list->tail); //tail have value
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1],list->head); // list head
	TEST_ASSERT_EQUAL_PTR(&arrayElem[4],list->tail); // list tail
	TEST_ASSERT_EQUAL(4, list->length); 			 // the length of the array should be 4 after REMOVE
	
	TEST_ASSERT_NOT_NULL(arrayElem[0].next); 		 // next -> 1, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[1].next); 		 // next -> 2, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[2].next); 		 // next -> 3, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[3].next); 		 // next -> 4, should be NOT NULL
	TEST_ASSERT_NULL(arrayElem[4].next);			 // the pointer next of last element should be NULL
	
	TEST_ASSERT_EQUAL(111, arrayElem[0].data); // element 1, array [0] data should be 111
	TEST_ASSERT_EQUAL(222, arrayElem[1].data); // element 2, array [1] data should be 222
	TEST_ASSERT_EQUAL(444, arrayElem[3].data); // element 4, array [3] data should be 444
	TEST_ASSERT_EQUAL(555, arrayElem[4].data); // element 5, array [4] data should be 555
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next); //pointer of element 1 pointing to element 2
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], arrayElem[2].next); //
	TEST_ASSERT_EQUAL_PTR(&arrayElem[4], arrayElem[3].next); //pointer of element 4 pointing to element 5
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[4].next); 		 //pointer of element 5 pointing to NULL
	
	//TEST_ASSERT_EQUAL_PTR(&arrayElem[2], List_delete(list,elem));									
//	print(); //to test and c the address and data
}

void test_LinkedList_delete_first_element(){
	LinkedList *list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = NULL, .data = 3}};
	list->length = 3;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[2];
	///print(); //to test and c the address and data
	
	List_delete(list, &arrayElem[0]);
	
	TEST_ASSERT_NOT_NULL(list->head); //head have value
	TEST_ASSERT_NOT_NULL(list->tail); //tail have value

	TEST_ASSERT_EQUAL(&arrayElem[1],list->head); // list head point to 2nd element
	TEST_ASSERT_EQUAL(&arrayElem[2],list->tail); // list tail pointing to last element
	TEST_ASSERT_EQUAL(2, list->length); 		 // the length is 2 after deleted element 1
	
	TEST_ASSERT_NOT_NULL(arrayElem[0].next); 	 //next -> 1, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[1].next); 	 //next -> 2, should be NOT NULL
	TEST_ASSERT_NULL(arrayElem[2].next);	 	 // the pointer next of last element should be NULL
	
	TEST_ASSERT_EQUAL(1, arrayElem[0].data); //element 1 , array [0] data should be 1
	TEST_ASSERT_EQUAL(2, arrayElem[1].data); //element 2 , array [1] data should be 2
	TEST_ASSERT_EQUAL(3, arrayElem[2].data); //element 3 , array [2] data should be 3
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next); //pointer of element 1 pointing to element 2
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next); //pointer of element 2 pointing to element 3
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[2].next); 		 //pointer of element 3 pointing to NULL

	//print(); //to test and c the address and data
}
void test_LinkedList_delete_last_element(){
	LinkedList *list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = NULL, .data = 3}};
	list->length = 3;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[2];
	//print(); //to test and c the address and data

	List_delete(list, &arrayElem[2]);
	
	TEST_ASSERT_NOT_NULL(list->head); //head have value
	TEST_ASSERT_NOT_NULL(list->tail); //tail have value

	TEST_ASSERT_EQUAL(&arrayElem[1],list->head); // list head point to 2nd element
	TEST_ASSERT_EQUAL(&arrayElem[2],list->tail); // list tail pointing to last element
	TEST_ASSERT_EQUAL(2, list->length); 		 // the length is 2 after deleted element 3
	
	TEST_ASSERT_NOT_NULL(arrayElem[0].next); 	 //next -> 1, should be NOT NULL
	TEST_ASSERT_NOT_NULL(arrayElem[1].next); 	 //next -> 2, should be NOT NULL
	TEST_ASSERT_NULL(arrayElem[2].next);	 	 // the pointer next of last element should be NULL
	
	TEST_ASSERT_EQUAL(1, arrayElem[0].data); //element 1 , array [0] data should be 1
	TEST_ASSERT_EQUAL(2, arrayElem[1].data); //element 2 , array [1] data should be 2
	TEST_ASSERT_EQUAL(3, arrayElem[2].data); //element 3 , array [2] data should be 3
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next); //pointer of element 1 pointing to element 2
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next); //pointer of element 2 pointing to element 3
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[2].next); 		 //pointer of element 3 pointing to NULL
	//print(); //to test and c the address and data
}

