typedef struct StackNode {
	int value;
	struct StackNode* next;
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
StackNode* Pop(Stack* stack);
StackNode* Peek(Stack* stack);
int Peek_Value(Stack* stack);
int Emtpy(Stack* stack);
int Search(Stack* stack, int value);
int Get_Size(Stack* stack);
