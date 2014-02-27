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
	

//	print(); //to test and c the address and data
}

