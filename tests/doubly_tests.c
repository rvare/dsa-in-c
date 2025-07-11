#include "../include/doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_list(DoublyLinkedList* dll);

int main() {
	printf("Doubly linked list tests\n");


	printf("\nConstruction and initalizer tests\n");

	printf("Construct DoublyNode\n");
	DoublyNode* node = DoublyNode_Constructor(0);
	if (NULL != node) {
		printf("value: %d\n", node->value);
		printf("next: %d\n", node->next);
		printf("prev: %d\n", node->prev);
	}

	printf("\nConstruct DoublyLinkedList\n");
	DoublyLinkedList* dll = Doubly_Constructor();
	assert(NULL != dll);
	if (NULL != dll) {
		printf("Constructed\n");
	}
	else {
		printf("Did not construct\n");
	}
	printf("\n");


	printf("Insertion operations\n");

	printf("Appending\n");
	printf("Append 1\n");
	Doubly_Append(dll, 1);
	printf("Append 2\n");
	Doubly_Append(dll, 2);
	printf("Append 3\n");
	Doubly_Append(dll, 3);
	print_list(dll);

	printf("Prepending\n");
	printf("Prepending -1\n");
	Doubly_Prepend(dll, -1);
	printf("Prepending -2\n");
	Doubly_Prepend(dll, -2);
	printf("Prepending -3\n");
	Doubly_Prepend(dll, -3);
	print_list(dll);

	printf("Inserting\n");
	printf("Inserting 0 between -1 and 1\n");
	Doubly_InsertAfter(dll, 2, 0);
	printf("Inserting 4 after last index\n");
	Doubly_InsertAfter(dll, 7, 4);
	print_list(dll);



	printf("Getter operations\n");

	printf("Get head\n");
	node = Doubly_Get_Head(dll);
	printf("node = %d | head = %d\n", node->value, dll->head->value);
	printf("node addr = 0x%x | head addr = 0x%x\n", node, dll->head);
	assert(node == dll->head);

	printf("Get tail\n");
	node = Doubly_Get_Tail(dll);
	printf("node = %d | tail = %d\n", node->value, dll->tail->value);
	printf("node addr = 0x%x | tail addr = 0x%x\n", node, dll->tail);
	assert(node == dll->tail);

	printf("\nGet Element\n");
	node = Doubly_Get_Element(dll, 0);
	printf("Index 0 is %d\n", node->value);
	assert(-3 == node->value);
	node = Doubly_Get_Element(dll, 7);
	printf("Index 7 is %d\n", node->value);
	assert(4 == node->value);
	node = Doubly_Get_Element(dll, 3);
	printf("Index 3 is %d\n", node->value);
	assert(0 == node->value);

	printf("\nGet index of\n");
	int index = Doubly_Get_IndexOf(dll, 0);
	printf("Index of 0 is %d\n", index);
	assert(3 == index);
	index = Doubly_Get_IndexOf(dll, 4);
	printf("Index of 4 is %d\n", index);
	assert(7 == index);
	index = Doubly_Get_IndexOf(dll, -3);
	printf("Index of -3 is %d\n", index);
	assert(0 == index);

	printf("\nGet size\n");
	int size = Doubly_Get_Size(dll);
	printf("Size = %d, should be 8\n", size);
	assert(8 == size);


	printf("\nDeletion operations\n");


	printf("\nTransformation operations\n");


	printf("\nList slicing\n");


	printf("\nTo array conversion\n");


	return EXIT_SUCCESS;
}

void print_list(DoublyLinkedList* dll) {
	assert(NULL != dll);
	DoublyNode* curr = dll->head;
	while (NULL != curr) {
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n\n");
}
