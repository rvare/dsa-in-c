#include "../include/array_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void print_list(ArrayList *arr_list);

int main() {
	printf("Array List Tests\n\n");


	printf("Construction and Initalization\n");

	ArrayList *arr_list = Arr_Constructor();
	printf("Is arr_list empty?\n");
	if (Arr_IsEmpty(arr_list)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	printf("Size: %d\n", Arr_Get_Size(arr_list));
	printf("Capacity: %d\n", Arr_Get_Capacity(arr_list));


	printf("\nOperations\n");

	printf("Insertion\n");
	printf("Append\n");
	for (int i = 0; i < 5; i++) {
		Arr_Append(arr_list, i);
	}
	print_list(arr_list);
	printf("Inserting more numbers to force resize\n");
	for (int i = 5; i < 14; i++) {
		Arr_Append(arr_list, i);
	}
	
	printf("Set element\n");
	printf("Setting element 0\n");
	Arr_Set_Element(arr_list, 99, 0);
	printf("Setting element 1\n");
	Arr_Set_Element(arr_list, 99, 1);
	print_list(arr_list);
	printf("Setting last element\n");
	Arr_Set_Element(arr_list, 99, arr_list->size);
	print_list(arr_list);


	printf("Get index of 2\n");
	int index = Arr_Get_IndexOf(arr_list, 2);
	printf("2 at %d\n", index);
	printf("Get index of 8\n");
	index = Arr_Get_IndexOf(arr_list, 8);
	printf("8 at %d\n", index);
	printf("Get index of 99\n");
	index = Arr_Get_IndexOf(arr_list, 99);
	printf("99 at %d\n", index);

	printf("Get last index of 7\n");
	index = Arr_Get_LastIndexOf(arr_list, 7);
	printf("7 at %d\n", index);
	printf("Get last index of 99\n");
	index = Arr_Get_LastIndexOf(arr_list, 99);
	printf("99 at %d\n", index);


	printf("\nClear array list\n");
	Arr_Clear_List(arr_list);
	printf("Array list?\n");
	if (Arr_IsEmpty(arr_list)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	printf("\nDelete array list\n");
	Arr_Delete_List(arr_list);
	printf("Deleted?\n");
	if (arr_list) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	printf("\nMaking new list\n");
	ArrayList *arr_list2 = Arr_Constructor();
	for (int i = 0; i < 10; i++) {
		Arr_Append(arr_list2, i);
	}

	printf("\nConverting\n");

	printf("Reverse\n");
	ArrayList *arr_list3 = Arr_Reverse(arr_list2);
	print_list(arr_list3);

	printf("Slice\n");
	ArrayList* arr_list4 = Arr_Slice(arr_list2, 2, 5);
	print_list(arr_list4);


	return EXIT_SUCCESS;
}

void print_list(ArrayList *arr_list) {
	for (int i = 0; i < arr_list->size; i++) {
		printf("%d ", arr_list->array[i]);
	}
	printf("\n");
}
