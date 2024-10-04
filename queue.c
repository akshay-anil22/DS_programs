#include <stdio.h>
int f = -1, r = -1;
int n;

void enqueue(int a[], int item)
{
  if (f == -1 && r == -1 || f > r)
  {
    f = 0;
    r = 0;
    a[r] = item;
  }
  else if (r == n - 1)
  {
    printf("overflow error");
  }
  else
  {
    r = r + 1;
    a[r] = item;
  }
}

void dequeue(int a[])
{
  if (f == -1 && r == -1 || f > r)
  {
    printf("queue underflow");
  }
  else
  {
    printf("the removed element is %d", a[f++]);
  }
}

void full(int a[])
{
  if (r == n - 1)
  {
    printf("queue is full");
  }
  else
  {
    printf("queue is not full");
  }
}

void empty(int a[])
{
  if (f == -1 && r == -1 || f > r)
  {
    printf("queue is empty");
  }
  else
  {
    printf("queue is not empty");
  }
}

void peek(int a[])
{
  if (f == -1 && r == -1 || f > r)
  {
    printf("queue is empty");
  }
  else
  {
    printf("peek element is %d", a[f]);
  }
}

void display(int a[])
{
  if (f == -1 && r == -1 || f > r)
  {
    printf("queue is empty");
  }
  else
  {
    for (int i = f; i <= r; i++)
      printf("%d", a[i]);
  }
}

void main()
{
  int item;
  printf("enter size of queue");
  scanf("%d", &n);
  int a[n];
  int f = 0;
  int ch;
  printf("1.Enqueue\n 2.Dequeue\n 3.Full\n 4.Empty\n 5.Peek\n 6.display\n 7.exit");
  while (f == 0)
  {
    printf("\nenter choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("enter the element to be inserted");
      scanf("%d", &item);
      enqueue(a, item);
      break;

    case 2:
      dequeue(a);
      break;

    case 3:
      full(a);
      break;

    case 4:
      empty(a);
      break;

    case 5:
      peek(a);
      break;

    case 6:
      display(a);
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