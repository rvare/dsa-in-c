typedef struct StackNode {
	int value;
	StackNode* next;
} StackNode;

typedef struct Stack {
	StackNode* top;
	int size;
} Stack;

// Constructor and initializer
Stack* Stack_Construct();
void Stack_Initializer(Stack* stack);

// Stack operations
void Push(Stack* stack, int value);
void Pop(Stack* stack, int value);
int Peek(Stack* stack);
int Emtpy(Stack* stack);
int Search(Stack* stack, int value);
