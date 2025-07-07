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
	}
	else {
		sll->tail->next = new_node;
		sll->tail = new_node;
	}
}

void Singly_Prepend(SinglyLinkedList *sll, int value){
	assert(sll != NULL);
	SinglyNode *new_node = (SinglyNode*)malloc(sizeof(SinglyNode));
	new_node->value = value;
	
	if (sll->head == NULL && sll->tail == NULL) {
		sll->head = new_node;
		sll->tail = new_node;
	}
	else {
		new_node->next = sll->head;
		sll->head = new_node;
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
		return;
	}

	SinglyNode* next_node = curr_node->next;
	curr_node->next = new_node;
	new_node->next = next_node;
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

SinglyNode Singly_Get_IndexOf(SinglyLinkedList *sll, int value){
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
}

void Singly_Remove_Tail(SinglyLinkedList *sll) {
	assert(sll != NULL);
	if (sll->tail == NULL) return;

	SinglyNode* node = sll->tail;
	SinglyNode* new_tail = sll->head;
	while(new_tail->next->next != NULL) new_tail = new_tail->next;

	new_tail->next = NULL;

	free(node);
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
}

void Singly_Remove_Value(SinglyLinkedList *sll, int value) {
}

void Singly_Clear_List(SinglyLinkedList *sll) {
	if (sll == NULL) return;

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
SinglyLinkedList Singly_Reverse_List(SinglyLinkedList *sll) {
}

// Slicing
SinglyLinkedList Singly_Slice(SinglyLinkedList *sll, int start, int end) {
}

// TODO: Looping
// void Singly_Foreach(SinglyLinkedList *sll, void (*f)(SinglyNode *node));
// void Singly_Forrange(SinglyLinkedList *sll, int start, int end, void (*f)(SinglyNode *node));

// TODO: Make to array operations
// TODO: Iterators operations
