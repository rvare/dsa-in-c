typedef struct ArrayList {
	int *array;
	int *ptr; // Pointer used for insertion
	int capacity; // How much memory is actually allocated
	int size; // How many elements are in the array
} ArrayList;

// Constructors and initializers
void Arr_Constructor();
void Arr_Initializer(ArrayList *arr_list);

// Getters
int Arr_Get_Element(ArrayList *arr_list, int index); // Negative indexing allowed
int Arr_Get_Size(ArrayList *arr_list);
int Arr_Get_Capacity(ArrayList *arr_list);

// Operations
// Insertion
void Arr_Append(ArrayList *arr_list, int value);
void Arr_Prepend(ArrayList *arr_list, int value);
void Arr_Insert_After(ArrayList *arr_list, int value, int index);
void Arr_Set_Element(ArrayList *arr_list, int value, int index);
void Arr_Clear_List(ArrayList *arr_list);
void Arr_Delete_List(ArrayList *arr_list);
int Arr_IsEmpty(ArrayList *arr_list);

// Searching
int Arr_Get_IndexOf(ArrayList *arr_list);
int Arr_Get_LastIndexOf(ArrayList *arr_list);

// Removal and Deletion
void Arr_Remove_Head(ArrayList *arr_list);
void Arr_Remove_Tail(ArrayList *arr_list);
void Arr_Remove_Element(ArrayList *arr_list, int index);

// Conversions
ArrayList* Arr_Reverse(ArrayList *arr_list);
ArrayList* Arr_Slice(ArrayList *arr_list, int start, int end);
// TODO: How to convert to lists?

// Helpers
void _Resize_Array(ArrayList *arr_list);
