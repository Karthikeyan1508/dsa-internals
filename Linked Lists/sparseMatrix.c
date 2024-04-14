#include<iostream>
using namespace std;

// Node class to represent link list
class Node
{
	public:
	int row;
	int col;
	int data;
	Node *next;
};

// Function to create new node
void create_new_node(Node **p, int row_index,
					int col_index, int x)
{
	Node *temp = *p;
	Node *r;
	
	// If link list is empty then 
	// create first node and assign value.
	if (temp == NULL)
	{
		temp = new Node();
		temp->row = row_index;
		temp->col = col_index;
		temp->data = x;
		temp->next = NULL;
		*p = temp;
	}
	
	// If link list is already created
	// then append newly created node
	else
	{
		while (temp->next != NULL) 
			temp = temp->next;
			
		r = new Node();
		r->row = row_index;
		r->col = col_index;
		r->data = x;
		r->next = NULL;
		temp->next = r;
	}
}

// Function prints contents of linked list
// starting from start
void printList(Node *start)
{
	Node *ptr = start;
	cout << "row_position:";
	while (ptr != NULL)
	{
		cout << ptr->row << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "column_position:";

	ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->col << " ";
		ptr = ptr->next;
	}
	cout << endl;
	cout << "Value:";
	ptr = start;
	
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

// Driver Code
int main()
{ 
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
	
	// Dynamic allocation of 2D array for sparse matrix
    int** sparseMatrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        sparseMatrix[i] = new int[cols];
    }

    cout << "Enter the elements of the sparse matrix:\n";
    for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cin >> sparseMatrix[i][j];
		}
	}
	
	// Creating head/first node of list as NULL
	Node *first = NULL;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			
			// Pass only those values which 
			// are non - zero
			if (sparseMatrix[i][j] != 0)
				create_new_node(&first, i, j, 
								sparseMatrix[i][j]);
		}
	}
	printList(first);
    
    // Deallocating memory for 2D array
    for (int i = 0; i < rows; ++i) {
        delete[] sparseMatrix[i];
    }
    delete[] sparseMatrix;

	return 0;
}
