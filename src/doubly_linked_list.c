#include "../include/doubly_linked_list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// Initializer
void Doubly_Initializer(DoublyLinkedList *dll) {
	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
}

// Constructor
DoublyLinkedList* Doubly_Constructor() {
	DoublyLinkedList* dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
	return dll;
}

DoublyNode* DoublyNode_Constructor(int value) {
	DoublyNode *new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
}

// Insertion Operations
void Doubly_Append(DoublyLinkedList *dll, int value) {
	DoublyNode *new_node = DoublyNode_Constructor(value);

	if (NULL == dll->head && NULL == dll->tail) {
		dll->head = new_node;
		dll->tail = new_node;
	}
	else {
		dll->tail->next = new_node;
		new_node->prev = dll->tail;
		dll->tail = new_node;
	}
	++dll->size;
}

void Doubly_Prepend(DoublyLinkedList *dll, int value) {
	DoublyNode *new_node = DoublyNode_Constructor(value);

	if (NULL == dll->head && NULL == dll->tail) {
		dll->head = new_node;
		dll->tail = new_node;
	}
	else {
		dll->head->prev = new_node;
		new_node->next = dll->head;
		dll->head = new_node;
	}
	++dll->size;
}

void Doubly_InsertAfter(DoublyLinkedList*dll, int index, int value) {
	DoublyNode *new_node = DoublyNode_Constructor(value);

	DoublyNode *curr_node = dll->head;
	for (int i = 0; i < index && NULL != curr_node; i++) {
		curr_node = curr_node->next;
	}

	if (NULL == curr_node) { // Index was last node
		dll->tail->next = new_node;
		new_node->prev = dll->tail;
		dll->tail = new_node;
		++dll->size;
		return;
	}

	DoublyNode* next_node = curr_node->next;
	curr_node->next = new_node;
	new_node->prev = curr_node;
	new_node->next = next_node;
	next_node->prev = new_node;
	++dll->size;
}

// Getters
DoublyNode* Doubly_Get_Head(DoublyLinkedList *dll) {
	return dll->head;
}

DoublyNode* Doubly_Get_Tail(DoublyLinkedList *dll){
	return dll->tail;
}

unsigned int Doubly_Get_Size(DoublyLinkedList *dll){
	return dll->size;
}

DoublyNode* Doubly_Get_Element(DoublyLinkedList *dll, int index) {
	if (index > dll->size) return NULL;

	DoublyNode *curr_node = dll->head;
	for (int i = 0; i < index && NULL != curr_node; i++) {
		curr_node = curr_node->next;
	}

	return curr_node;
}

int Doubly_Get_IndexOf(DoublyLinkedList *dll, int value) {
	int index = 0;
	DoublyNode* curr = dll->head;
	for (curr = dll->head; NULL != curr; curr = curr->next) {
		if (curr->value == value) {
			return index;
		}
		++index;
	}
	return -1;
}

int Doubly_Get_LastIndexOf(DoublyLinkedList *dll, int value) {
	DoublyNode* curr = dll->tail;
	int curr_index = dll->size-1;
	int found_index = -1;
	while (NULL != curr) {
		if (curr->value == value) {
			found_index = curr_index;
		}
		--curr_index;
		curr = curr->prev;
	}
	return found_index > 0 ? found_index : -1;
}

// Deletion
void Doubly_Remove_Head(DoublyLinkedList *dll) {
	if (NULL == dll->head) return;

	DoublyNode* node = dll->head;
	dll->head = dll->head->next;
	dll->head->prev = NULL;
	node->next = NULL;

	free(node);
	--dll->size;
}

void Doubly_Remove_Tail(DoublyLinkedList *dll) {
	if (NULL == dll->tail) return;

	DoublyNode* node = dll->tail;
	dll->tail = dll->tail->prev;
	dll->tail->next = NULL;

	node->prev = NULL;
	free(node);
	--dll->size;
}

void Doubly_Remove_Element(DoublyLinkedList *dll, int index) {
	assert(NULL != dll);
	assert(NULL != dll->head);
	assert(NULL != dll->tail);
}

void Doubly_Remove_Value(DoublyLinkedList *dll, int value) {
	assert(NULL != dll);
	assert(NULL != dll->head);
	assert(NULL != dll->tail);
}

void Doubly_Clear_List(DoublyLinkedList *dll) {
	if (NULL == dll) return;

	if (NULL == dll->head && NULL == dll->tail) return;

	DoublyNode* curr = dll->head;
	DoublyNode* node = NULL;
	while(NULL != curr) {
		node = curr;
		curr = curr->next;
		free(node);
	}

	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
}

void Doubly_Delete_List(DoublyLinkedList **dll) {
	if (NULL == *dll) return;
	Doubly_Clear_List(*dll);
	free(*dll);
	*dll = NULL;
}

// Transformation
DoublyLinkedList* Doubly_Reverse_List(DoublyLinkedList *dll) {
	DoublyLinkedList *new_dll = Doubly_Constructor();
	DoublyNode* curr = dll->tail;

	while (NULL != curr) {
		Doubly_Append(new_dll, curr->value);
		curr = curr->prev;
	}

	return new_dll;
}

// Slicing
DoublyLinkedList* Doubly_Slice(DoublyLinkedList *dll, int start, int end) {
	DoublyNode* curr = dll->head;
	DoublyNode* start_node;
	for (int i = 0; i < start && NULL != curr; i++) {
		curr = curr->next;
	}

	start_node = curr;

	DoublyNode* end_node;
	curr = dll->head;
	for (int i = 0; i < end && NULL != curr; i++) {
		curr = curr->next;
	}

	end_node = curr;

	DoublyLinkedList* new_dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));

	new_dll->head = start_node;
	new_dll->tail = end_node;
	curr = new_dll->head;
	int count = 0;
	while (NULL != curr) {
		++count;
		curr = curr->next;
	}
	new_dll->size = count;

	return new_dll;
}

int* Doubly_To_Array(DoublyLinkedList *dll) {
	int size = dll->size;
	int* arr = (int*)calloc(size, sizeof(int));

	DoublyNode* curr = dll->head;
	int index = 0;
	while(NULL != curr) {
		arr[index] = curr->value;
		++index;
		curr = curr->next;
	}
	return arr;
}

