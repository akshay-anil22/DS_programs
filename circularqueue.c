#include <stdio.h>
int f = -1, r = -1;
int max;

void enqueue(int a[], int item)
{
  if (f == -1 & r == -1)
  {
    f = 0;
    r = 0;
    a[r] = item;
  }
  else if ((r + 1) % max == f)
  {
    printf("overflow error");
  }
  else
  {
    r = (r + 1) % max;
    a[r] = item;
  }
}
void dequeue(int a[])
{
  if (f == -1 && r == -1)
  {
    printf("underflow error");
  }
  else if (f == r)
  {
    printf(" removed element is %d", a[f]);
    f = -1;
    r = -1;
  }
  else
  {
    printf(" removed element is %d", a[f]);
    f = (f + 1) % max;
  }
}

void display(int a[])
{
  int i = f;
  if (f == -1 && r == -1)
  {
    printf("queue is empty");
  }
  else
  {
    while (i != r)
    {
      printf("%d", a[i]);
      i = (i + 1) % max;
    }
    printf("%d\n", a[i]);
  }
}

void main()
{
  int item;
  printf("enter size of queue");
  scanf("%d", &max);
  int ch;
  int a[max];
  int f = 0;
  printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
  while (f == 0)
  {
    printf("enter choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter the element to be inserted : ");
      scanf("%d", &item);
      enqueue(a, item);
      break;
    case 2:
      dequeue(a);
      break;
    case 3:
      display(a);
      break;
    case 4:
      f = 1;
      break;
    default:
      printf("Invalid choice \n");
    }
  }
}