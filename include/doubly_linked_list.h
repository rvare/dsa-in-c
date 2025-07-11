typedef struct DoublyNode {
	int value;
	struct DoublyNode *next;
	struct DoublyNode *prev;
} DoublyNode;

typedef struct DoublyLinkedList {
	DoublyNode *head;
	DoublyNode *tail;
	unsigned int size;
} DoublyLinkedList;

// Initializer
void Doubly_Initializer(DoublyLinkedList *dll);
DoublyLinkedList* Doubly_Constructor();
DoublyNode* DoublyNode_Constructor(int value);

// Insertion Operations
void Doubly_Append(DoublyLinkedList *dll, int value);
void Doubly_Prepend(DoublyLinkedList *dll, int value);
void Doubly_InsertAfter(DoublyLinkedList*dll, int index, int value);

// Getters
DoublyNode* Doubly_Get_Head(DoublyLinkedList *dll);
DoublyNode* Doubly_Get_Tail(DoublyLinkedList *dll);
DoublyNode* Doubly_Get_Element(DoublyLinkedList *dll, int index);
int Doubly_Get_IndexOf(DoublyLinkedList *dll, int value);
int Doubly_Get_LastIndexOf(DoublyLinkedList *dll, int value);
unsigned int Doubly_Get_Size(DoublyLinkedList *dll);

// Deletion
void Doubly_Remove_Element(DoublyLinkedList *dll, int index);
void Doubly_Remove_Value(DoublyLinkedList *dll, int value);
void Doubly_Remove_Head(DoublyLinkedList *dll);
void Doubly_Remove_Tail(DoublyLinkedList *dll);
void Doubly_Clear_List(DoublyLinkedList *dll);
void Doubly_Delete_List(DoublyLinkedList **dll);

// Transformation
DoublyLinkedList* Doubly_Reverse_List(DoublyLinkedList *dll);

// Slicing
DoublyLinkedList* Doubly_Slice(DoublyLinkedList *dll, int start, int end);

// To array
int* Doubly_To_Array(DoublyLinkedList *dll);
