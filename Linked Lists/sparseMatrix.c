#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int key;
  int row_position;
  int col_postion;
  struct Node *Next;
};

void create_new_node(struct Node** head, int non_zero_element,
          int row_index, int col_index )
{
  struct Node *temp, *r;
  temp = *head;
  if (temp == NULL)
  {
    temp = (struct Node *) malloc (sizeof(struct Node));
    temp->key = non_zero_element;
    temp->row_position = row_index;
    temp->col_postion = col_index;
    temp->Next = NULL;
    *head = temp;

  }
  else
  {
    while (temp->Next != NULL)
      temp = temp->Next;
    r = (struct Node *) malloc (sizeof(struct Node));
    r->key = non_zero_element;
    r->row_position = row_index;
    r->col_postion = col_index;
    r->Next = NULL;
    temp->Next = r;

  }
}

void Print_list(struct Node* head)
{
  struct Node *temp, *r, *s;
  temp = r = s = head;

  printf("row_position: ");
  while(temp != NULL)
  {

    printf("%d ", temp->row_position);
    temp = temp->Next;
  }
  printf("\n");

  printf("col_postion: ");
  while(r != NULL)
  {
    printf("%d ", r->col_postion);
    r = r->Next;
  }
  printf("\n");
  printf("Value: ");
  while(s != NULL)
  {
    printf("%d ", s->key);
    s = s->Next;
  }
  printf("\n");
}

int main()
{
  int sparse_matric[5][4] =
  {
    {0, 0, 3, 0},
    {0, 0, 5, 7},
    {0, 0, 0, 0},
    {0, 2, 6, 0},
    {4, 0, 0, 0}
  };

  struct Node* start = NULL;

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++)
      if (sparse_matric[i][j] != 0)
        create_new_node(&head, sparse_matric[i][j], i, j);

  Print_list(head);

  return 0;
}
