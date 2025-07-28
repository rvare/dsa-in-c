**Table of Contents**

- [Structs](#structs)
	- [Summary of Structs](#summar-of-structs)
	- [Struct Definitions](#struct-definitions)
- [Functions](#functions)
	- [Initializer and Constructor](#initializer-and-constructor)
	- [Insertion Operations](#insertion-operations)
	- [Getters](#getters)
	- [Deletion](#deletion)
	- [Transformation](#transformation)
	- [Slicing](#slicing)
	- [Conversion](#conversion)

- - -

# Structs

## Summary of Structs

`SinglyNode`

| Member | Description |
|:------:|-------------|
| `int value` | Holds the value. |
| `struct SinglyNode *next` | Pointer to next node. |

`SinglyLinkedList`

| Member | Description |
|:------:|-------------|
| `SinglyNode *head` | Pointer of to the head of the list. |
| `SinglyNode *tail` | Pointer of to the tail of the list. |
| `unisgned int size` | How many elements the list currently has. |

## Struct Definitions

The following are the definitions of each struct that is used to create the singly linked list.

```c
typedef struct SinglyNode {
	int value;
	struct SinglyNode *next;
} SinglyNode;
```

```c
typedef struct SinglyLinkedList {
	SinglyNode *head;
	SinglyNode *tail;
	unsigned int size;
} SinglyLinkedList;
```


# Functions


## Initializer and Constructor

`void Singly_Initializer(SinglyLinkedList *sll)`
: Initailzes a `SinglyLinkedList` that has already been allocated or is a variable.

<details>
<summary>Implementation</summary>
```c
void Singly_Initializer(SinglyLinkedList *sll) {
	sll->head = NULL;
	sll->tail = NULL;
	sll->size = 0;
}
```
</details>

`SinglyLinkedList* Singly_Constructor()`
: Calls `malloc()` to allocate a `SinglyLinkedList` struct on the heap.

<details>
<summary>Implementation</summary>
```c
SinglyLinkedList* Singly_Constructor() {
	SinglyLinkedList* sll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	sll->head = NULL;
	sll->tail = NULL;
	sll->size = 0;
	return sll;
}
```
</details>

## Insertion Operations

`void Singly_Append(SinglyLinkedList *sll, int value)`
: Construct and append a `SinglyNode` at the tail of the list.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

`void Singly_Prepend(SinglyLinkedList *sll, int value)`
: Construct and prepend a `SinglyNode` at the head of the list.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

`void Singly_InsertAfter(SinglyLinkedList*sll, int index, int value)`
: Cosntruct and insert a `SinglyNode` *after* `index`.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

## Getters

`SinglyNode* Singly_Get_Head(SinglyLinkedList *sll)`
: Return a pointer to the head of the list.

<details>
<summary>Implementation</summary>
```c
SinglyNode* Singly_Get_Head(SinglyLinkedList *sll){
	return sll->head;
}
```
</details>

`SinglyNode* Singly_Get_Tail(SinglyLinkedList *sll)`
: Return a pointer to the tail of the list.

<details>
<summary>Implementation</summary>
```c
SinglyNode* Singly_Get_Head(SinglyLinkedList *sll){
	return sll->tail;
}
```
</details>

`SinglyNode* Singly_Get_Element(SinglyLinkedList *sll, int index)`
: Return a pointer that is the element at `index` from the head of the list.

<details>
<summary>Implementation</summary>
```c
SinglyNode* Singly_Get_Element(SinglyLinkedList *sll, int index){
	if (index > sll->size) return NULL;

	SinglyNode *curr_node = sll->head;
	for (int i = 0; i < index && NULL != curr_node; i++) {
		curr_node = curr_node->next;
	}

	return curr_node;
}
```
</details>

`int Singly_Get_IndexOf(SinglyLinkedList *sll, int value)`
: Return the index of where the first *appearnce* of `value` is.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

`int Singly_Get_LastIndexOf(SinglyLinkedList *sll, int value)`
: Return the index of where the *last* appearnce of `value` is.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

`unsigned int Singly_Get_Size(SinglyLinkedList *sll)`
: Return the the current size of the list, as in, how many items are in the list.

<details>
<summary>Implementation</summary>
```c
unsigned int Singly_Get_Size(SinglyLinkedList *sll){
	return sll->size;
}
```
</details>

## Deletion

`void Singly_Remove_Element(SinglyLinkedList *sll, int index)`
: Remove the element at `index`.
: This function also calls `free()` to deallocate the node.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

`void Singly_Remove_Value(SinglyLinkedList *sll, int value)`
: Remove the *first occurance* of `value` in the list.
: The function also calls `free()` to deallocate the node.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

`void Singly_Remove_Head(SinglyLinkedList *sll)`
: Remove the head of the list.
: This will move the `head` pointer to the next element in the list.
: The function also calls `free()` to deallocate the node.

<details>
<summary>Implementation</summary>
```c
void Singly_Remove_Head(SinglyLinkedList *sll) {
	if (NULL == sll->head) return;

	SinglyNode* node = sll->head;
	sll->head = sll->head->next;
	node->next = NULL;

	free(node);
	--sll->size;
}
```
</details>

`void Singly_Remove_Tail(SinglyLinkedList *sll)`
: Remove the tail of the list.
: This will move the `tail` pointer to the second to last element of the list.
: The function also calls `free()` to deallocate the node.

<details>
<summary>Implementation</summary>
```c
void Singly_Remove_Tail(SinglyLinkedList *sll) {
	if (NULL == sll->tail) return;

	SinglyNode* node = sll->tail;
	SinglyNode* new_tail = sll->head;
	while(NULL != new_tail->next->next) new_tail = new_tail->next;

	new_tail->next = NULL;

	free(node);
	--sll->size;
}
```
</details>

`void Singly_Clear_List(SinglyLinkedList *sll)`
: Clear the current list.
: This will call `free()` on all nodes of the list, set `head` and `tail` pointers to `NULL`, and `size` to zero.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

`void Singly_Delete_List(SinglyLinkedList **sll)`
: Completely clear list and deallocate it from the heap. Set the pointer to `NULL`.

<details>
<summary>Implementation</summary>
```c
void Singly_Delete_List(SinglyLinkedList **sll) {
	if (NULL == *sll) return;
	Singly_Clear_List(*sll);
	free(*sll);
	*sll = NULL;
}
```
</details>


## Transformation

`SinglyLinkedList* Singly_Reverse_List(SinglyLinkedList *sll)`
: Reverse the linked list pointed by `*sll`.
: This function is a recursive implementation, using the memory stack to reverse the list.

<details>
<summary>Implementation</summary>
```c
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
}

SinglyLinkedList* Singly_Reverse_List(SinglyLinkedList *sll) {
	SinglyLinkedList *new_sll = Singly_Constructor();
	SinglyNode* curr = sll->head;
	_Singly_Reverse_List(new_sll, curr);
	return new_sll;
}
```
</details>

## Slicing

`SinglyLinkedList* Singly_Slice(SinglyLinkedList *sll, int start, int end)`
: Returns a new `SinglyLinkedList` whose `head` and `tail` points to the same nodes in the list pointed by `*sll`.

<details>
<summary>Implementation</summary>
```c
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
```
</details>

## Conversion

`int* Singly_To_Array(SinglyLinkedList *sll)`
: Return an array that contains copies of the values from `*sll`.

<details>
<summary>Implementation</summary>
```c
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

```
</details>
