#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

Element *elem;

LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;   //(Element *) 547455;
	list->tail = NULL;   //(Element *) 547455;
	list->length = 0; 
	return list;
}

void print(){ 			// print test
	LinkedList *list;
	printf("head:%p , tail:%p\n",list->head,list->tail);
	for(elem = list->head; elem != NULL ; elem = elem->next){
		printf("data:%d , addr:%p\n",elem->data,elem);
	}
	printf("length: %d\n",list->length);
}

Element *List_remove(LinkedList *list , Element *elem){
	
	if( list->head ==NULL && list->tail ==NULL ) //both NULL ? return NULL
		return NULL;
	
	if	( list->head == list->tail ){ //head equal tail ? YES> both NULL
		list->head == NULL;
		list->tail == NULL;
	}
	
	if(elem == list->head){ 		 //remove first
		(list->head) = ((list->head)->next);
	}
		
	else if(list->tail > list->head){// remove last
		*(list->tail)--;
	}
	else{							 //remove middle
		Element *previous;			 // *previous pointer are temporary
		previous = elem--;			 // Previous element = current element -1
		previous->next = (elem->next);
		elem = previous->next;
	}
	if(list->length > 0){			//is length ? 0 : length-1
		list->length = (list->length) - 1;
	}
	return elem;
}
	
