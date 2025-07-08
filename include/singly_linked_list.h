typedef struct SinglyNode {
	int value;
	struct SinglyNode *next;
} SinglyNode;

typedef struct SinglyLinkedList {
	SinglyNode *head;
	SinglyNode *tail;
	unsigned int size;
} SinglyLinkedList;

// Initializer
void Singly_Initializer(SinglyLinkedList *sll);

SinglyLinkedList* Singly_Constructor();

// Insertion Operations
void Singly_Append(SinglyLinkedList *sll, int value);
void Singly_Prepend(SinglyLinkedList *sll, int value);
void Singly_InsertAfter(SinglyLinkedList*sll, int index, int value);

// Getters
SinglyNode* Singly_Get_Head(SinglyLinkedList *sll);
SinglyNode* Singly_Get_Tail(SinglyLinkedList *sll);
SinglyNode* Singly_Get_Element(SinglyLinkedList *sll, int index);
int Singly_Get_IndexOf(SinglyLinkedList *sll, int value);
int Singly_Get_LastIndexOf(SinglyLinkedList *sll, int value);
unsigned int Singly_Get_Size(SinglyLinkedList *sll);

// Deletion
void Singly_Remove_Element(SinglyLinkedList *sll, int index);
void Singly_Remove_Value(SinglyLinkedList *sll, int value);
void Singly_Remove_Head(SinglyLinkedList *sll);
void Singly_Remove_Tail(SinglyLinkedList *sll);
void Singly_Clear_List(SinglyLinkedList *sll);
void Singly_Delete_List(SinglyLinkedList **sll);

// Transformation
// SinglyLinkedList Singly_Transform(SinglyLinkedList *sll, void (*f)(SinglyNode *node));
SinglyLinkedList* Singly_Reverse_List(SinglyLinkedList *sll);

// Slicing
SinglyLinkedList* Singly_Slice(SinglyLinkedList *sll, int start, int end);

// TODO: Looping
// void Singly_Foreach(SinglyLinkedList *sll, void (*f)(SinglyNode *node));
// void Singly_Forrange(SinglyLinkedList *sll, int start, int end, void (*f)(SinglyNode *node));

// TODO: Make to array operations
int* Singly_To_Array(SinglyLinkedList *sll);
// TODO: Iterators operations
