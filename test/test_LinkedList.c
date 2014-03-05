#include "unity.h"
#include "LinkedList.h"

void setUp(){}
void tearDown(){}

LinkedList *list;
Element *element;

void test_LinkedList_is_created_and_should_be_empty(){
	LinkedList *list = createLinkedList();
	
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	
}
/**
	==============TEST FIXTURE===============
	*****************************************
			elem1	 elem2		elem3
			 ____	  ____		 ____
	head--->|next|-->|next|---->|next|---|
			|____|	 |____|	|-->|____|   |
			|data|	 |data|	|	|data|	 |
			|    |	 |	  |	|	|	 |	 |
			|____|	 |____|	|	|____|	NULL
	tail---------------------	
	*****************************************
**/
	/**	
		======TEST FIXTURE=======================================================
		*************************************************************************
		|1|  |2|  |3|  |4|  |5|		if there is 5 element
		|1|  |2|  |X|  |4|  |5|		remove element 3
		|1|  |2|<-|X|  |4|  |5|		previous element is 2
		|1|  |2|------>|4|  |5|		element 2 -> next = removed element -> next
		*************************************************************************
	**/
void test_LinkedList_remove_middle_element_second_element(){
	LinkedList *list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 111},
							{.next = &arrayElem[2], .data = 222},
							{.next = &arrayElem[3], .data = 333},
							{.next = NULL, .data = 444}};
	
	list->head = &arrayElem[0];
	list->tail = &arrayElem[3];
	list->length = 4;
	//print(); //to test and c the address and data
	element = List_remove(list, &arrayElem[1]);
	//print();
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0],list->head); // list head point to 1st element
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2],list->tail); // list tail pointing to 2nd last element
	TEST_ASSERT_EQUAL(3, list->length); 		 // the length is 3 after deleted element 3
	TEST_ASSERT_EQUAL(222,element->data);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], element); 
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[3].next); 		 //pointer of element 3 pointing to NULL
	
	// list head still at first element
	// list tail still at last element 
	// just the middle changed
	// list length equals 3
	
	}
	
void test_LinkedList_remove_middle_element_third_element(){
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 111},
							{.next = &arrayElem[2], .data = 222},
							{.next = &arrayElem[3], .data = 333},
							{.next = NULL, .data = 444}};
	
	list->head = &arrayElem[0];
	list->tail = &arrayElem[3];
	list->length = 4;
	//print();
	element = List_remove(list, &arrayElem[2]);
	//printf("element nOW %p\n",element);
	
	TEST_ASSERT_NOT_NULL(element);
	TEST_ASSERT_NOT_NULL(list->head); //head have value 
	TEST_ASSERT_NOT_NULL(list->tail); //tail have value
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0],list->head); // list head
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2],list->tail); // list tail
	TEST_ASSERT_EQUAL(3, list->length); 			 // the length of the array should be 3 after REMOVE

	TEST_ASSERT_NULL(arrayElem[3].next);			 // the pointer next of last element should be NULL
	TEST_ASSERT_EQUAL(333,element->data);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2],element); 	 
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next); //pointer of element 1 pointing to element 2
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next); //
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], arrayElem[2].next); //pointer of element 4 pointing to element 5
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[3].next); 		 //pointer of element 5 pointing to NULL
	
	// list head still at first element
	// list tail still at last element 
	// just the middle changed
	// list length equals 3
}


void test_LinkedList_remove_first_element(){
	LinkedList *list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = &arrayElem[3], .data = 3},
							{.next = NULL, .data = 4}};
	
	list->head = &arrayElem[0];
	list->tail = &arrayElem[3];
	list->length = 4;
	//print(); //to test and c the address and data
	element = List_remove(list, &arrayElem[0]);
	//print(); //to test and c the address and data

	TEST_ASSERT_NOT_NULL(list->head); //head have value
	TEST_ASSERT_NOT_NULL(list->tail); //tail have value

	TEST_ASSERT_EQUAL(&arrayElem[1],list->head); // list head point to 2nd element
	TEST_ASSERT_EQUAL(&arrayElem[3],list->tail); // list tail pointing to last element
	TEST_ASSERT_EQUAL(3, list->length); 		 // the length is 3 after deleted element 1

	TEST_ASSERT_NULL(arrayElem[3].next);	 	 // the pointer next of last element should be NULL
	TEST_ASSERT_EQUAL(1,element->data);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], element); 
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next); 
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], arrayElem[2].next); 
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[3].next); 		 //pointer of element 3 pointing to NULL
	
	// list head at next of the first element
	// list tail still at last element 
	// list length equals 3
	
	}

void test_LinkedList_remove_last_element(){
	LinkedList *list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = &arrayElem[3], .data = 3},
							{.next = NULL, .data = 4}};
	
	list->head = &arrayElem[0];
	list->tail = &arrayElem[3];
	list->length = 4;
	//print(); //to test and c the address and data
	element = List_remove(list, &arrayElem[3]);
	//print();
	
	TEST_ASSERT_NOT_NULL(list->head); //head have value
	TEST_ASSERT_NOT_NULL(list->tail); //tail have value

	TEST_ASSERT_EQUAL(&arrayElem[0],list->head); // list head point to 1st element
	TEST_ASSERT_EQUAL(&arrayElem[2],list->tail); // list tail pointing to 2nd last element
	TEST_ASSERT_EQUAL(3, list->length); 		 // the length is 3 after deleted element 3
	
	TEST_ASSERT_NULL(arrayElem[3].next);	 	 // the pointer next of last element should be NULL
	TEST_ASSERT_EQUAL(4,element->data);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], element); 
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next); 
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], arrayElem[2].next); 
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[3].next); 		 //pointer of element 3 pointing to NULL
	
	// list head still at first element
	// list tail at next of the last element
	// list length equals 3
	
	}
void test_LinkedList_remove_with_5_element(){
	LinkedList *list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 123},
							{.next = &arrayElem[2], .data = 234},
							{.next = &arrayElem[3], .data = 345},
							{.next = &arrayElem[4], .data = 456},
							{.next = NULL, .data = 567}};
	
	list->head = &arrayElem[0];
	list->tail = &arrayElem[4];
	list->length = 5;
	//print(); //to test and c the address and data
	element = List_remove(list, &arrayElem[4]);
	//print();
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0],list->head); // list head point to 1st element
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3],list->tail); // list tail pointing to 2nd last element
	TEST_ASSERT_EQUAL(4, list->length); 		 // the length is 4 after deleted element 3
	TEST_ASSERT_EQUAL(567,element->data);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[4], element); 
	TEST_ASSERT_EQUAL_PTR(NULL, arrayElem[4].next); 		 //pointer of element 3 pointing to NULL
	
	// list head still at first element
	// list tail at next of the last element
	// list length equals 4
	
	}
	

