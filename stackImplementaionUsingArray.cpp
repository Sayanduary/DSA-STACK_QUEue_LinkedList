#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
  if (top == MAX - 1)
  {
    printf("Stack overflow\n");
  }
  else
  {
    top++;
    stack[top] = value;
    printf("%d pushed into the stack\n", value);
  }
}

void pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
  }
  else
  {
    printf("%d popped from the stack\n", stack[top]);
    top--;
  }
}

void displayStack()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
  }
  else
  {
    for (int i = top; i >= 0; i--)
    {
      printf("%d ", stack[i]);
    }
    printf("\n");
  }
}

int main()
{
  push(10);
  push(20);
  push(30);
  pop();
  displayStack();
  return 0;
}
