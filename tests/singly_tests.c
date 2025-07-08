#include "../include/singly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define INIT_COUNT 3
#define APPENDING_COUNT 3
#define PRENDING_COUNT 5

unsigned char success_count = 0;

void check_elements(SinglyLinkedList* sll, int start);
void print_list(SinglyLinkedList* sll);

int main() {
	printf("Singly Linked List Tests\n\n");

	printf("Create singly list and initialize\n");
	SinglyLinkedList *sll = Singly_Constructor();
	Singly_Initializer(sll);
	if (sll->head == NULL) ++success_count;
	if (sll->tail == NULL) ++success_count;
	if (sll->size == 0) ++success_count;
	printf("%d/%d pass\n\n", success_count, INIT_COUNT);
	success_count = 0;

	// Insertion tests
	// Append
	printf("Append tests\n");
	printf("Appending 1\n");
	Singly_Append(sll, 1);

	printf("Appending 2\n");
	Singly_Append(sll, 2);

	printf("Appending 3\n");
	Singly_Append(sll, 3);
	
	check_elements(sll, 1);
	printf("%d/%d appending successful\n", success_count, APPENDING_COUNT);
	print_list(sll);
	printf("\n");

	// Prepend
	printf("Prepending\n");
	success_count = 0;
	printf("Prepend -1\n");
	Singly_Prepend(sll, -1);

	printf("Prepend -2\n");
	Singly_Prepend(sll, -2);

	check_elements(sll, -2);
	printf("%d/%d prepending successful\n", success_count, PRENDING_COUNT);
	print_list(sll);
	printf("\n");

	// Insert After
	success_count = 0;
	printf("Inserting 0 after -1 (index 1)\n");
	Singly_InsertAfter(sll, 1, 0);

	check_elements(sll, -2);
	printf("%d/%d, inserting successful\n", success_count, 6);
	print_list(sll);
	printf("\n");

	// Getters
	printf("Getters\n");
	SinglyNode* node = NULL;

	printf("Get head\n");
	node = Singly_Get_Head(sll);
	printf("%d\n", node->value);

	printf("Get tail\n");
	node = Singly_Get_Tail(sll);
	printf("%d\n", node->value);

	printf("Get element 0\n");
	node = Singly_Get_Element(sll, 0);
	printf("%d\n", node->value);

	printf("Get element 5\n");
	node = Singly_Get_Element(sll, 5);
	printf("%d\n", node->value);

	printf("Get element 3\n");
	node = Singly_Get_Element(sll, 3);
	printf("%d\n", node->value);

	printf("Get index of 0\n");
	int index = Singly_Get_IndexOf(sll, 0);
	printf("Index is %d\n", index);

	printf("Get last index of 3\n");
	index = Singly_Get_LastIndexOf(sll, 3);
	printf("Index is %d\n", index);
	printf("\n");

	// Deletion
	printf("Deletion Tests\n");
	printf("Removing head\n");
	Singly_Remove_Head(sll);
	assert(sll->head != NULL);
	printf("%d\n", sll->head->value);
	print_list(sll);

	printf("Removing tail\n");
	Singly_Remove_Tail(sll);
	assert(sll->tail != NULL);
	printf("%d\n", sll->tail->value);
	print_list(sll);

	printf("Remove fourth element\n");
	Singly_Remove_Element(sll, 3);
	print_list(sll);

	printf("Remove second element\n");
	Singly_Remove_Element(sll, 1);
	print_list(sll);

	printf("Clear the list\n");
	Singly_Clear_List(sll);

	printf("Delete the list\n");
	Singly_Delete_List(&sll);
	printf("Deleted?\n");
	if (sll == NULL) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	printf("Reverse list\n");
	SinglyLinkedList sll2;
	Singly_Initializer(&sll2);
	Singly_Append(&sll2, 1);
	Singly_Append(&sll2, 2);
	Singly_Append(&sll2, 3);
	Singly_Append(&sll2, 4);
	Singly_Append(&sll2, 5);
	printf("Original list ");
	print_list(&sll2);
	SinglyLinkedList* sll3 = Singly_Reverse_List(&sll2);
	printf("New list ");
	print_list(sll3);

	printf("Create array from list\n");
	int* arr = Singly_To_Array(&sll2);
	assert(arr != NULL);
	int size = sll2.size;
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}

// Functions
void check_elements(SinglyLinkedList* sll, int start) {
	assert(sll->head != NULL);
	SinglyNode *node = sll->head;
	int i = start;
	while (node != NULL) {
		if (node->value == i) ++success_count;
		node = node->next;
		++i;
	}
}

void print_list(SinglyLinkedList* sll) {
	assert(sll != NULL);
	assert(sll->head != NULL);

	SinglyNode* curr = NULL;
	for (curr = sll->head; curr != NULL; curr = curr->next) {
		printf("%d ", curr->value);
	}

	printf("\n");
}
