#include "../include/singly_linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define APPENDING_COUNT 3
#define PRENDING_COUNT 5

unsigned char success_count = 0;

void check_elements(SinglyLinkedList* sll, int start);
void print_list(SinglyLinkedList* sll);

int main() {
	printf("Singly Linked List Tests\n");

	SinglyLinkedList sll;
	Singly_Initializer(&sll);

	// Insertion tests
	// Append
	printf("Append tests\n");
	printf("Appending 1\n");
	Singly_Append(&sll, 1);

	printf("Appending 2\n");
	Singly_Append(&sll, 2);

	printf("Appending 3\n");
	Singly_Append(&sll, 3);
	
	check_elements(&sll, 1);
	printf("%d out of %d appending successful\n", success_count, APPENDING_COUNT);
	print_list(&sll);

	// Prepend
	success_count = 0;
	printf("Prepend -1\n");
	Singly_Prepend(&sll, -1);

	printf("Prepend -2\n");
	Singly_Prepend(&sll, -2);

	check_elements(&sll, -2);
	printf("%d out of %d prepending successful\n", success_count,PRENDING_COUNT);
	print_list(&sll);

	// Insert After
	success_count = 0;
	printf("Inserting 0 after -1 (index 1)\n");
	Singly_InsertAfter(&sll, 1, 0);

	check_elements(&sll, -2);
	printf("%d out of %d, inserting successful\n", success_count, 6);
	print_list(&sll);

	// Deletion
	printf("Removing head\n");
	Singly_Remove_Head(&sll);
	printf("%d\n", sll.head->value);
	print_list(&sll);

	printf("Removing tail\n");
	Singly_Remove_Tail(&sll);
	printf("%d\n", sll.tail->value);
	print_list(&sll);

	printf("Remove fourth element\n");
	Singly_Remove_Element(&sll, 3);
	print_list(&sll);

	printf("Remove second element\n");
	Singly_Remove_Element(&sll, 1);
	print_list(&sll);

	// printf("Clear the list\n");
	// Singly_Clear_List(&sll);

	// printf("Delete the list\n");
	// Singly_Delete_List(&sll);
	// printf("Deleted?\n");
	// if (sll == NULL) {
	// 	printf("Yes\n");
	// }
	// else {
	// 	printf("No\n");
	// }

	SinglyLinkedList sll2;
	Singly_Initializer(&sll2);
	Singly_Append(&sll2, 1);
	Singly_Append(&sll2, 2);
	Singly_Append(&sll2, 3);
	Singly_Append(&sll2, 4);
	Singly_Append(&sll2, 5);
	printf("Original list\n");
	print_list(&sll2);
	SinglyLinkedList* sll3 = Singly_Reverse_List(&sll2);
	printf("New list\n");
	print_list(sll3);

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
	assert(sll->head != NULL);

	SinglyNode* curr = NULL;
	for (curr = sll->head; curr != NULL; curr = curr->next) {
		printf("%d ", curr->value);
	}

	printf("\n");
}
