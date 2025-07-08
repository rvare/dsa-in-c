#include "../include/singly_linked_list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// Initializer
void Singly_Initializer(SinglyLinkedList *sll) {
	sll->head = NULL;
	sll->tail = NULL;
	sll->size = 0;
}

// Constructor
SinglyLinkedList* Singly_Constructor() {
	SinglyLinkedList* sll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	sll->head = NULL;
	sll->tail = NULL;
	sll->size = 0;
	return sll;
}

// Insertion Operations
void Singly_Append(SinglyLinkedList *sll, int value){
	assert(sll != NULL);
	SinglyNode *new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
	new_node->value = value;
	new_node->next = NULL;

	if (sll->head == NULL && sll->tail == NULL) {
		sll->head = new_node;
		sll->tail = new_node;
		++sll->size;
	}
	else {
		sll->tail->next = new_node;
		sll->tail = new_node;
		++sll->size;
	}
}

void Singly_Prepend(SinglyLinkedList *sll, int value){
	assert(sll != NULL);
	SinglyNode *new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
	new_node->value = value;
	
	if (sll->head == NULL && sll->tail == NULL) {
		sll->head = new_node;
		sll->tail = new_node;
		++sll->size;
	}
	else {
		new_node->next = sll->head;
		sll->head = new_node;
		++sll->size;
	}
}

void Singly_InsertAfter(SinglyLinkedList*sll, int index, int value){
	assert(sll != NULL);
	SinglyNode *new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
	new_node->value = value;
	new_node->next = NULL;

	assert(sll->head != NULL);
	SinglyNode *curr_node = sll->head;
	for (int i=0; i < index && curr_node != NULL; i++) {
		curr_node = curr_node->next;
	}

	if (curr_node == NULL) { // Index was last node
		assert(sll->tail != NULL);
		sll->tail->next = new_node;
		++sll->size;
		return;
	}

	SinglyNode* next_node = curr_node->next;
	curr_node->next = new_node;
	new_node->next = next_node;
	++sll->size;
}

// Getters
SinglyNode* Singly_Get_Head(SinglyLinkedList *sll){
	assert(sll->head != NULL);
	return sll->head;
}

SinglyNode* Singly_Get_Tail(SinglyLinkedList *sll){
	assert(sll->tail != NULL);
	return sll->tail;
}

SinglyNode* Singly_Get_Element(SinglyLinkedList *sll, int index){
	assert(sll != NULL);
	assert(sll->head != NULL);

	SinglyNode *curr_node = sll->head;
	for (int i=0; i <= index && curr_node != NULL; i++) {
		curr_node = curr_node->next;
	}

	return curr_node;
}

int Singly_Get_IndexOf(SinglyLinkedList *sll, int value){
	int index = 0;
	SinglyNode* curr = sll->head;
	for (curr=sll->head; curr!=NULL; curr=curr->next) {
		if (curr->value == value) {
			return index;
		}
		++index;
	}
	return -1;
}

SinglyNode Singly_Get_LastIndexOf(SinglyLinkedList *sll, int value){
}

unsigned int Singly_Get_Size(SinglyLinkedList *sll){
	assert(sll != NULL);
	return sll->size;
}

// Deletion
void Singly_Remove_Head(SinglyLinkedList *sll) {
	assert(sll != NULL);
	if (sll->head == NULL) return;

	SinglyNode* node = sll->head;
	sll->head = sll->head->next;
	node->next = NULL;

	free(node);
	--sll->size;
}

void Singly_Remove_Tail(SinglyLinkedList *sll) {
	assert(sll != NULL);
	if (sll->tail == NULL) return;

	SinglyNode* node = sll->tail;
	SinglyNode* new_tail = sll->head;
	while(new_tail->next->next != NULL) new_tail = new_tail->next;

	new_tail->next = NULL;

	free(node);
	--sll->size;
}

void Singly_Remove_Element(SinglyLinkedList *sll, int index) {
	assert(sll != NULL);

	SinglyNode* curr = sll->head;
	for (int i=0; i<index-1; i++) {
		curr = curr->next;
	}

	SinglyNode* remove_node = curr->next;
	curr->next = curr->next->next;

	remove_node->next = NULL;
	free(remove_node);
	--sll->size;
}

void Singly_Remove_Value(SinglyLinkedList *sll, int value) {
}

void Singly_Clear_List(SinglyLinkedList *sll) {
	if (sll == NULL) return;

	if (sll->head == NULL && sll->tail == NULL) return;

	SinglyNode* curr = sll->head;
	SinglyNode* node = NULL;
	while(curr != NULL) {
		node = curr;
		curr = curr->next;
		free(node);
	}

	sll->size = 0;
}

void Singly_Delete_List(SinglyLinkedList *sll) {
	if (sll == NULL) return;

	Singly_Clear_List(sll);

	free(sll);
}

// Transformation
// SinglyLinkedList Singly_Transform(SinglyLinkedList *sll, void (*f)(SinglyNode *node));

// Private function
void _Singly_Reverse_List(SinglyLinkedList* sll, SinglyNode* node) {
	if (node == NULL) {
		return;
	}
	else if (node->next == NULL) {
		Singly_Append(sll, node->value);
		return;
	}
	else {
		_Singly_Reverse_List(sll, node->next);
		Singly_Append(sll, node->value);
		return;
	}
}

SinglyLinkedList* Singly_Reverse_List(SinglyLinkedList *sll) {
	SinglyLinkedList *new_sll = Singly_Constructor();
	SinglyNode* curr = sll->head;
	_Singly_Reverse_List(new_sll, curr);
	return new_sll;
}

// Slicing
SinglyLinkedList Singly_Slice(SinglyLinkedList *sll, int start, int end) {
}

// TODO: Looping
// void Singly_Foreach(SinglyLinkedList *sll, void (*f)(SinglyNode *node));
// void Singly_Forrange(SinglyLinkedList *sll, int start, int end, void (*f)(SinglyNode *node));

int* Singly_To_Array(SinglyLinkedList *sll) {
	assert(sll != NULL);
	int size = sll->size;
	// int* arr = (int*)malloc(sizeof(int)*size);
	int* arr = (int*)calloc(size, sizeof(int));

	assert(arr != NULL);
	SinglyNode* curr = sll->head;
	int index = 0;
	while(curr != NULL) {
		arr[index] = curr->value;
		++index;
		curr = curr->next;
	}
	return arr;
}

// TODO: Iterators operations
