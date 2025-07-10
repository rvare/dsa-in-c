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
void Doubly_Initializer(SinglyLinkedList *sll);

DoublyLinkedList* Doubly_Constructor();

// Insertion Operations
void Doubly_Append(DoublyLinkedList *sll, int value);
void Doubly_Prepend(DoublyLinkedList *sll, int value);
void Doubly_InsertAfter(DoublyLinkedList*sll, int index, int value);

// Getters
DoublyNode* Doubly_Get_Head(DoublyLinkedList *sll);
DoublyNode* Singly_Get_Tail(DoublyLinkedList *sll);
DoublyNode* Singly_Get_Element(DoublyLinkedList *sll, int index);
int Doubly_Get_IndexOf(DoublyLinkedList *sll, int value);
int Doubly_Get_LastIndexOf(DoublyLinkedList *sll, int value);
unsigned int Doubly_Get_Size(DoublyLinkedList *sll);

// Deletion
void Doubly_Remove_Element(DoublyLinkedList *sll, int index);
void Doubly_Remove_Value(DoublyLinkedList *sll, int value);
void Doubly_Remove_Head(DoublyLinkedList *sll);
void Doubly_Remove_Tail(DoublyLinkedList *sll);
void Doubly_Clear_List(DoublyLinkedList *sll);
void Doubly_Delete_List(DoublyLinkedList **sll);

// Transformation
// SinglyLinkedList Singly_Transform(SinglyLinkedList *sll, void (*f)(SinglyNode *node));
DoublyLinkedList* Doubly_Reverse_List(DoublyLinkedList *sll);

// Slicing
DoublyLinkedList* Doubly_Slice(DoublyLinkedList *sll, int start, int end);

// TODO: Looping
// void Singly_Foreach(SinglyLinkedList *sll, void (*f)(SinglyNode *node));
// void Singly_Forrange(SinglyLinkedList *sll, int start, int end, void (*f)(SinglyNode *node));

// TODO: Make to array operations
int* Doubly_To_Array(DoublyLinkedList *sll);
// TODO: Iterators operations
