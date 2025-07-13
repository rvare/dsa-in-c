typedef struct QueueNode {
	int value;
	struct QueueNode *next;
} QueueNode;

typedef struct Queue {
	QueueNode *head;
	QueueNode *tail;
	int size;
} Queue;

// Constructor an initializers
Queue* Queue_Constructor();
void Queue_Initializer(Queue *que);

// Getters
int Queue_Get_Size(Queue *que);
int QueueNode_Get_Value(QueueNode *que_node);

// Operations
void Enqueue(Queue *que, int value);
QueueNode* Dequeue (Queue *que);
QueueNode* Peek(Queue *que);
int Peek_Value(Queue *que);
int Empty(Queue *que);
int Search(Queue *que, int value);
