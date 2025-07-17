#define RESIZE_TRUE 1
#define RESIZE_FALSE 0

typedef struct ArrStack {
	int *array;
	int resizable; // 0 array can't resize; 1 array is resizable
	int capacity; // Size of the array
	int count; // Number of elements in stack
} ArrStack;

// Constructor and initializer
ArrStack* ArrStack_Constructor();
void ArrStack_Initializer();

// Stack operations
void ArrStack_Push(ArrStack *stack, int value);
int ArrStack_Pop(ArrStack *stack);
int ArrStack_Peek(ArrStack *stack);

int ArrStack_Emtpy(ArrStack *stack);
int ArrStack_Search(ArrStack *stack); // Where is value in stack?
int ArrStack_Get_Size(ArrStack *stack);

// Helper functions
void ArrStack_Resize(ArrStack *stack);
