#include <stdio.h>
int top = -1, n;

void push(int A[])
{
  if (top == n - 1)
  {
    printf("Stack overflow");
  }
  else
  {
    int e;
    printf("enter element");
    scanf("%d", &e);
    top = top + 1;
    A[top] = e;
  }
}

void pop(int A[])
{
  if (top == -1)
  {
    printf("Stack underflow");
  }
  else
  {
    printf("Removed element is %d", A[top--]);
  }
}

void isfull(int A[])
{
  if (top == n - 1)
  {
    printf("Stack is full");
  }
  else
  {
    printf("stack is not full");
  }
}

void isempty(int A[])
{
  if (top == -1)
  {
    printf("stack is empty");
  }
  else
  {
    printf("stack is not empty");
  }
}

void peek(int A[])
{
  if (top == -1)
  {
    printf("Stack is empty");
  }
  else
  {
    printf("the peek element is %d", A[top]);
  }
}

void display(int A[])
{
  if (top == -1)
  {
    printf("Stack is empty");
  }
  else
  {
    for (int i = top; i >= 0; i--)
    {
      printf("%d\n", A[i]);
    }
  }
}

void main()
{
  printf("enter size of stack");
  scanf("%d", &n);
  int A[n];
  int f = 0;
  int ch;
  printf("1.Push\n 2.Pop\n 3.IsFull\n 4.IsEmpty\n 5.Peek\n 6.display\n 7.exit\n");
  while (f == 0)
  {
    printf("\nenter choice \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      push(A);
      break;

    case 2:
      pop(A);
      break;

    case 3:
      isfull(A);
      break;

    case 4:
      isempty(A);
      break;

    case 5:
      peek(A);
      break;

    case 6:
      display(A);
      break;

    case 7:
      f = 1;
      break;

    default:
      printf("Invalid option");
      break;
    }
  }
}
