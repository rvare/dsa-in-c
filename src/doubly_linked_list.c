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

// Insertion Operations
void Doubly_Append(DoublyLinkedList *dll, int value){
	DoublyNode *new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (dll->head == NULL && dll->tail == NULL) {
		dll->head = new_node;
		dll->tail = new_node;
		++dll->size;
	}
	else {
		dll->tail->next = new_node;
		dll->tail = new_node;
		++dll->size;
	}
}

void Doubly_Prepend(DoublyLinkedList *dll, int value){
	DoublyNode *new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
	new_node->value = value;
	
	if (dll->head == NULL && dll->tail == NULL) {
		dll->head = new_node;
		dll->tail = new_node;
		++dll->size;
	}
	else {
		new_node->next = dll->head;
		dll->head = new_node;
		++dll->size;
	}
}

void Doubly_InsertAfter(DoublyLinkedList*dll, int index, int value){
	DoublyNode *new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
	new_node->value = value;
	new_node->next = NULL;

	DoublyNode *curr_node = dll->head;
	for (int i=0; i < index && curr_node != NULL; i++) {
		curr_node = curr_node->next;
	}

	if (curr_node == NULL) { // Index was last node
		dll->tail->next = new_node;
		++dll->size;
		return;
	}

	DoublyNode* next_node = curr_node->next;
	curr_node->next = new_node;
	new_node->next = next_node;
	++dll->size;
}

// Getters
DoublyNode* Doubly_Get_Head(DoublyLinkedList *dll){
	return dll->head;
}

DoublyNode* Doubly_Get_Tail(DoublyLinkedList *dll){
	return dll->tail;
}

DoublyNode* Doubly_Get_Element(DoublyLinkedList *dll, int index){
	if (index > dll->size) return NULL;

	DoublyNode *curr_node = dll->head;
	for (int i=0; i < index && curr_node != NULL; i++) {
		curr_node = curr_node->next;
	}

	return curr_node;
}

int Doubly_Get_IndexOf(DoublyLinkedList *dll, int value){
	int index = 0;
	DoublyNode* curr = dll->head;
	for (curr=dll->head; curr!=NULL; curr=curr->next) {
		if (curr->value == value) {
			return index;
		}
		++index;
	}
	return -1;
}

int Doubly_Get_LastIndexOf(DoublyLinkedList *dll, int value){
	DoublyNode* curr = dll->head;
	int curr_index = 0;
	int found_index = -1;
	while (curr != NULL) {
		if (curr->value == value) {
			found_index = curr_index;
		}
		++curr_index;
		curr = curr->next;
	}
	return found_index > 0 ? found_index : -1;
}

unsigned int Doubly_Get_Size(DoublyLinkedList *dll){
	return dll->size;
}

// Deletion
void Doubly_Remove_Head(DoublyLinkedList *dll) {
	if (dll->head == NULL) return;

	DoublyNode* node = dll->head;
	dll->head = dll->head->next;
	node->next = NULL;

	free(node);
	--dll->size;
}

void Doubly_Remove_Tail(DoublyLinkedList *dll) {
	if (dll->tail == NULL) return;

	DoublyNode* node = dll->tail;
	DoublyNode* new_tail = dll->head;
	while(new_tail->next->next != NULL) new_tail = new_tail->next;

	new_tail->next = NULL;

	free(node);
	--dll->size;
}

void Doubly_Remove_Element(DoublyLinkedList *dll, int index) {

	DoublyNode* curr = dll->head;
	for (int i=0; i<index-1; i++) {
		curr = curr->next;
	}

	DoublyNode* remove_node = curr->next;
	curr->next = curr->next->next;

	remove_node->next = NULL;
	free(remove_node);
	--dll->size;
}

void Doubly_Remove_Value(DoublyLinkedList *dll, int value) {
	DoublyNode* curr = dll->head;
	while (curr->next != NULL && curr->next->value != value) {
		curr = curr->next;
	}
	DoublyNode* re_node = curr->next;
	curr->next = curr->next->next;
	re_node->next = NULL;
	free(re_node);
}

void Doubly_Clear_List(DoublyLinkedList *dll) {
	if (dll == NULL) return;

	if (dll->head == NULL && dll->tail == NULL) return;

	DoublyNode* curr = dll->head;
	DoublyNode* node = NULL;
	while(curr != NULL) {
		node = curr;
		curr = curr->next;
		free(node);
	}

	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
}

void Doubly_Delete_List(DoublyLinkedList **dll) {
	if (*dll == NULL) return;
	Doubly_Clear_List(*dll);
	free(*dll);
	*dll = NULL;
}

// Transformation
// DoublyLinkedList Doubly_Transform(DoublyLinkedList *dll, void (*f)(DoublyNode *node));

// Private function
void _Doubly_Reverse_List(DoublyLinkedList* dll, DoublyNode* node) {
	if (node == NULL) {
		return;
	}
	else if (node->next == NULL) {
		Doubly_Append(dll, node->value);
		return;
	}
	else {
		_Doubly_Reverse_List(dll, node->next);
		Doubly_Append(dll, node->value);
		return;
	}
}

DoublyLinkedList* Doubly_Reverse_List(DoublyLinkedList *dll) {
	DoublyLinkedList *new_dll = Doubly_Constructor();
	DoublyNode* curr = dll->head;
	_Doubly_Reverse_List(new_dll, curr);
	return new_dll;
}

// Slicing DO NEXT
DoublyLinkedList* Doubly_Slice(DoublyLinkedList *dll, int start, int end) {
	DoublyNode* curr = dll->head;
	DoublyNode* start_node;
	for (int i=0; i<start && curr!=NULL; i++) {
		curr = curr->next;
	}

	start_node = curr;

	DoublyNode* end_node;
	curr = dll->head;
	for (int i=0; i<end && curr!=NULL; i++) {
		curr = curr->next;
	}

	end_node = curr;

	DoublyLinkedList* new_dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));

	new_dll->head = start_node;
	new_dll->tail = end_node;
	curr = new_dll->head;
	int count = 0;
	while (curr != NULL) {
		++count;
		curr = curr->next;
	}
	new_dll->size = count;

	return new_dll;
}

// TODO: Looping
// void Doubly_Foreach(DoublyLinkedList *dll, void (*f)(DoublyNode *node));
// void Doubly_Forrange(DoublyLinkedList *dll, int start, int end, void (*f)(DoublyNode *node));

int* Doubly_To_Array(DoublyLinkedList *dll) {
	int size = dll->size;
	// int* arr = (int*)malloc(sizeof(int)*size);
	int* arr = (int*)calloc(size, sizeof(int));

	DoublyNode* curr = dll->head;
	int index = 0;
	while(curr != NULL) {
		arr[index] = curr->value;
		++index;
		curr = curr->next;
	}
	return arr;
}

// TODO: Iterators operations
