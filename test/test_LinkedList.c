#include "unity.h"
#include "LinkedList.h"

void setUp(){}
void tearDown(){}

/*
void test_createLinkedList_should_return_initialized_LinkedList_object(){
	LinkedList *list;
	
	list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
}

void dumpLinkedList(LinkedList *list){
	Element *elem;
	printf("head:%d , tail:%p\n",list->head,list->tail);
	for(elem = list->head; elem != NULL ; elem = elem->next){
		printf("data:%d , addr:%p\n",elem->data,elem);
	}
	
}

void test_no_test_but_playing_around(){
	LinkedList *list = createLinkedList(); //dynamic add (here)
	//Element arrayElem[3] = {{&arrayElem[1],1},
	//						{&arrayElem[2],2},
	//						{NULL,3}};
	Element arrayElem[3] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = NULL, .data = 3}};
	//LinkedList dlist = {NULL , NULL , 0}; // static add (same as above dynamic add)
	list->head = &arrayElem[0];
	list->length = 3;
	
	dumpLinkedList(list);	
}
*/

void test_element_arrayElement_print_and_value(){
	LinkedList *list = createLinkedList();
	Element arrayElem[4] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = &arrayElem[3], .data = 3},
							{.next = NULL, .data = 4}};
	list->head = &arrayElem[0];
	list->length = 4;
	print();
}



