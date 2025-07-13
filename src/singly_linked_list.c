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
	SinglyNode *new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
	new_node->value = value;
	new_node->next = NULL;

	if (NULL == sll->head && NULL == sll->tail) {
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
	SinglyNode *new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
	new_node->value = value;
	
	if (NULL == sll->head && NULL == sll->tail) {
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
	SinglyNode *new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
	new_node->value = value;
	new_node->next = NULL;

	SinglyNode *curr_node = sll->head;
	for (int i = 0; i < index && NULL != curr_node; i++) {
		curr_node = curr_node->next;
	}

	if (NULL == curr_node) { // Index was last node
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
	return sll->head;
}

SinglyNode* Singly_Get_Tail(SinglyLinkedList *sll){
	return sll->tail;
}

SinglyNode* Singly_Get_Element(SinglyLinkedList *sll, int index){
	if (index > sll->size) return NULL;

	SinglyNode *curr_node = sll->head;
	for (int i = 0; i < index && NULL != curr_node; i++) {
		curr_node = curr_node->next;
	}

	return curr_node;
}

int Singly_Get_IndexOf(SinglyLinkedList *sll, int value){
	int index = 0;
	SinglyNode* curr = sll->head;
	for (curr = sll->head; NULL != curr; curr = curr->next) {
		if (curr->value == value) {
			return index;
		}
		++index;
	}
	return -1;
}

int Singly_Get_LastIndexOf(SinglyLinkedList *sll, int value){
	SinglyNode* curr = sll->head;
	int curr_index = 0;
	int found_index = -1;
	while (NULL != curr) {
		if (curr->value == value) {
			found_index = curr_index;
		}
		++curr_index;
		curr = curr->next;
	}
	return found_index > 0 ? found_index : -1;
}

unsigned int Singly_Get_Size(SinglyLinkedList *sll){
	return sll->size;
}

// Deletion
void Singly_Remove_Head(SinglyLinkedList *sll) {
	if (NULL == sll->head) return;

	SinglyNode* node = sll->head;
	sll->head = sll->head->next;
	node->next = NULL;

	free(node);
	--sll->size;
}

void Singly_Remove_Tail(SinglyLinkedList *sll) {
	if (NULL == sll->tail) return;

	SinglyNode* node = sll->tail;
	SinglyNode* new_tail = sll->head;
	while(NULL != new_tail->next->next) new_tail = new_tail->next;

	new_tail->next = NULL;

	free(node);
	--sll->size;
}

void Singly_Remove_Element(SinglyLinkedList *sll, int index) {

	SinglyNode* curr = sll->head;
	for (int i = 0; i < index-1; i++) {
		curr = curr->next;
	}

	SinglyNode* remove_node = curr->next;
	curr->next = curr->next->next;

	remove_node->next = NULL;
	free(remove_node);
	--sll->size;
}

void Singly_Remove_Value(SinglyLinkedList *sll, int value) {
	SinglyNode* curr = sll->head;
	while (NULL != curr->next && curr->next->value != value) {
		curr = curr->next;
	}
	SinglyNode* re_node = curr->next;
	curr->next = curr->next->next;
	re_node->next = NULL;
	free(re_node);
}

void Singly_Clear_List(SinglyLinkedList *sll) {
	if (NULL == sll) return;

	if (NULL == sll->head && NULL == sll->tail) return;

	SinglyNode* curr = sll->head;
	SinglyNode* node = NULL;
	while(NULL != curr) {
		node = curr;
		curr = curr->next;
		free(node);
	}

	sll->head = NULL;
	sll->tail = NULL;
	sll->size = 0;
}

void Singly_Delete_List(SinglyLinkedList **sll) {
	if (NULL == *sll) return;
	Singly_Clear_List(*sll);
	free(*sll);
	*sll = NULL;
}

// Private function
void _Singly_Reverse_List(SinglyLinkedList* sll, SinglyNode* node) {
	if (NULL == node) {
		return;
	}
	else if (NULL == node->next) {
		Singly_Append(sll, node->value);
		return;
	}
	else {
		_Singly_Reverse_List(sll, node->next);
		Singly_Append(sll, node->value);
		return;
	}
} SinglyLinkedList* Singly_Reverse_List(SinglyLinkedList *sll) {
	SinglyLinkedList *new_sll = Singly_Constructor();
	SinglyNode* curr = sll->head;
	_Singly_Reverse_List(new_sll, curr);
	return new_sll;
}

// Slicing DO NEXT
SinglyLinkedList* Singly_Slice(SinglyLinkedList *sll, int start, int end) {
	SinglyNode* curr = sll->head;
	SinglyNode* start_node;
	for (int i = 0; i < start && NULL != curr; i++) {
		curr = curr->next;
	}

	start_node = curr;

	SinglyNode* end_node;
	curr = sll->head;
	for (int i = 0; i < end && NULL != curr; i++) {
		curr = curr->next;
	}

	end_node = curr;

	SinglyLinkedList* new_sll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));

	new_sll->head = start_node;
	new_sll->tail = end_node;
	curr = new_sll->head;
	int count = 0;
	while (NULL != curr) {
		++count;
		curr = curr->next;
	}
	new_sll->size = count;

	return new_sll;
}

int* Singly_To_Array(SinglyLinkedList *sll) {
	int size = sll->size;
	int* arr = (int*)calloc(size, sizeof(int));

	SinglyNode* curr = sll->head;
	int index = 0;
	while(NULL != curr) {
		arr[index] = curr->value;
		++index;
		curr = curr->next;
	}
	return arr;
}

