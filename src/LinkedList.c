#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"
//#include "CException.h"
#include <stdio.h>
LinkedList *list;
Element *tempElem, *prev;

LinkedList *createLinkedList(){
	list = malloc(sizeof(LinkedList));
	list->head = NULL;   //(Element *) 547455;
	list->tail = NULL;   //(Element *) 547455;
	list->length = 0; 
	return list;
}

void print(){
	printf("head:%p , tail:%p\n",list->head,list->tail);
	for(tempElem = list->head; tempElem != NULL ; tempElem = tempElem->next){
		printf("data:%d , addr:%p\n",tempElem->data,tempElem);
	}
}

Element *List_delete(LinkedList *list){
	tempElem = list->head;
	
	while(tempElem !=NULL)
	{
	if(tempElem->data == list->length)
	{
		if(tempElem==list->head){
		list->head = tempElem->next;
		free(tempElem);
		return tempElem ;
		}
		else{
		prev->next = tempElem->next;
		free(tempElem);
		return tempElem;
		}
	}
	else{
	prev = tempElem;
	tempElem = tempElem-> next;
	}
	}
	return 0;
}