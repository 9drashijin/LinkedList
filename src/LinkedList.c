#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"
#include "CException.h"
#include <stdio.h>

LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList *));
	list->head = NULL;   //(Element *) 547455;
	list->tail = NULL;   //(Element *) 547455;
	list->length = NULL; 
	return list;
}