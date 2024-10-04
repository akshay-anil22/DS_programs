#include <stdio.h>
int f = -1, r = -1;
int n;

void insertFront(int a[], int item)
{
  if ((r + 1) % n == f)
  {
    printf("overflow error");
  }
  else if (f == -1)
  {
    f = 0;
    r = 0;
  }
  else if (f == 0)
  {
    f = n - 1;
  }
  else
  {
    f--;
  }
  a[f] = item;
}

void insertRear(int a[], int item)
{
  if ((r + 1) % n == f)
  {
    printf("overflow error");
  }
  else if (f == -1)
  {
    f = 0;
    r = 0;
  }
  else if (r == n - 1)
  {
    r = 0;
  }
  else
  {
    r++;
  }
  a[r] = item;
}

void dequeueFront(int a[])
{
  if (f == -1)
  {
    printf("underflow error");
  }
  else
  {
    printf("removed element is %d", a[f]);
    if (f == r)
    {
      f = -1;
      r = -1;
    }
    else
    {
      if (f == n - 1)
      {
        f = 0;
      }
      else
      {
        f++;
      }
    }
  }
}

void dequeueRear(int a[])
{
  if (f == -1)
  {
    printf("underflow error");
  }
  else
  {
    printf("removed element is %d", a[r]);
    if (f == r)
    {
      f = -1;
      r = -1;
    }
    else
    {
      if (r == 0)
      {
        r = n - 1;
      }
      else
      {
        r--;
      }
    }
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
      i = (i + 1) % n;
    }
    printf("%d\n", a[i]);
  }
}

void main()
{
  int item;
  printf("enter size of queue");
  scanf("%d", &n);
  int a[n];
  int ch;
  int f1 = 0;
  printf("1. enqueue_from_front \n 2.enqueue_from_rear \n 3.dequeue_from_front \n 4.dequeue_from_rear\n 5.Display \n 6.exit");
  while (f1 == 0)
  {
    printf("\nenter choice\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:

      printf("enter element to be inserted");
      scanf("%d", &item);
      insertFront(a, item);
      break;
    case 2:

      printf("enter element to be inserted");
      scanf("%d", &item);
      insertRear(a, item);
      break;
    case 3:
      dequeueFront(a);
      break;
    case 4:
      dequeueRear(a);
      break;
    case 5:
      display(a);
      break;
    case 6:
      f1 = 1;
      break;
    case 7:
      printf("invalid option");
      break;
    }
  }
}