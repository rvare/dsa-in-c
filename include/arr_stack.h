#define RESIZE_TRUE 1
#define RESIZE_FALSE 0

typedef struct ArrStack {
	int *array;
	int *ptr;
	int resizable; // 0 array can't resize; 1 array is resizable
	int capacity; // Size of the array
	int count; // Number of elements in stack
} ArrStack;

// Constructor and initializer
ArrStack* ArrStack_Constructor();
ArrStack* ArrStack_Constructor(int resizable);
void ArrStack_Initializer(ArrStack *arr_stack);
void ArrStack_Initializer(ArrStack *arr_stack, int resizable);

// Stack operations
void ArrStack_Push(ArrStack *stack, int value);
int ArrStack_Pop(ArrStack *stack);
int ArrStack_Peek(ArrStack *stack);

int ArrStack_Empty(ArrStack *stack);
int ArrStack_Search(ArrStack *stack, int value); // Where is value in stack?
int ArrStack_Get_Size(ArrStack *stack);

// Helper functions
void ArrStack_Resize(ArrStack *stack);
