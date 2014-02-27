#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"
//#include "CException.h"
#include <stdio.h>
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


Element *List_delete(LinkedList *list , Element *elem){
	
	if( list->head ==NULL && list->tail ==NULL ) 
		return NULL;
	
	else if	( list->head == list->tail ){
		list->head == NULL;
		list->tail == NULL;
		}
	while(elem !=NULL){
		//for(elem = list->head ; elem!=NULL ; elem = elem->next){
		 if(elem = list->head){ 		 //remove first
			(list->head) = ((list->head)->next);
			(list->tail) = (list->tail);
			(list->tail)->next = NULL;
			(list->length)--;
			//free(elem);
			return elem;
			}
		else if(elem == list->tail){ 	 // remove last
			*(list->tail)--;
			(list->head) = (list->head);
			(list->tail)->next = NULL;
			(list->length)--;
			//free(elem);
			return elem;
			}
		else{							 //remove middle
			Element *previous;			 // *previous pointer are temporary
			previous = elem--;			 // Previous element = current element -1
			previous->next = (elem->next);
			(list->head) = (list->head);
			(list->tail) = (list->tail);
			(list->tail)->next = NULL;
			(list->length)--;
			//free(elem);
			return elem;
		}	
		//}
	}

}
	
